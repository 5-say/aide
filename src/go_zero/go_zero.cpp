#include "go_zero.hpp"
#include <iostream>
#include <memory>

namespace go_zero {

    void cmd(CLI::App &app) {
        auto sub = app.add_subcommand(subcommand_name, subcommand_description);
        sub->require_subcommand();
        init::cmd(*sub);
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
            // Do stuff...
            std::cout << "Working on file: " << opt.out << std::endl;
        }
    }
}
