#include "go_zero.hpp"
#include <iostream>
#include <memory>
#include <ostream>
#include "inja/inja.hpp"
#include "yaml-cpp/yaml.h"

namespace go_zero {

    void cmd(CLI::App &app) {
        auto sub = app.add_subcommand(subcommand_name, subcommand_description);
        sub->require_subcommand();
        init::cmd(*sub);
        api::cmd(*sub);
    }

    namespace init {

        void cmd(CLI::App &parent) {
            // Create the option and subcommand objects.
            auto *sub = parent.add_subcommand(subcommand_name, subcommand_description);
            auto opt = std::make_shared<Options>();

            // Add options to sub, binding them to opt.
            sub->add_option("-o,--out", opt->out, "output path")->default_val("define");

            // Set the run function as callback to be called when this subcommand is issued.
            sub->callback([opt]() { run(*opt); });
        }

        void run(Options const &opt) {
            inja::json data ({
                {"demo", "888"},
            });
            // data["demo"] = "666";
            std::ofstream file ("out.text");
            file << inja::render("This is test template, data is {{ demo }}", data);
            file.close();

            // Do stuff...
            std::cout << "Working on file: " << opt.out << std::endl;
        }
    }

    namespace api {

        void cmd(CLI::App &parent) {
            // Create the option and subcommand objects.
            auto *sub = parent.add_subcommand(subcommand_name, subcommand_description);
            auto opt = std::make_shared<Options>();

            // Add options to sub, binding them to opt.
            sub->add_option("-i,--in", opt->in, "api yaml file path")->default_val("api.yaml");

            // Set the run function as callback to be called when this subcommand is issued.
            sub->callback([opt]() { run(*opt); });
        }

        void run(Options const &opt) {
            YAML::Node api = YAML::LoadFile(opt.in);

            // Do stuff...
            std::cout << "Working on file: " << opt.in << std::endl;
            std::cout << api["services"]["aide"]["entrypoint"] << std::endl;
        }
    }
}
