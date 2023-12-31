#include "demo.hpp"
#include <iostream>
#include <memory>

namespace demo {

    void cmd(CLI::App &app) {
        // Create the option and subcommand objects.
        auto *sub = app.add_subcommand(subcommand_name, subcommand_description);
        auto opt = std::make_shared<Options>();

        // Add options to sub, binding them to opt.
        sub->add_option("-f,--file", opt->file, "File name")->required();
        sub->add_flag("-w,--with-foo", opt->with_foo, "Counter");

        // Set the run function as callback to be called when this subcommand is issued.
        sub->callback([opt]() { run(*opt); });
    }

    void run(Options const &opt) {
        // Do stuff...
        std::cout << "Working on file: " << opt.file << std::endl;
        if(opt.with_foo) {
            std::cout << "Using foo!" << std::endl;
        }
    }
}
