#pragma once

#include <CLI/CLI.hpp>
#include <string>

namespace demo {

    const std::string subcommand_name = "demo";
    const std::string subcommand_description = "performs subcommand demo";

    struct Options {
        std::string file;
        bool with_foo;
    };

    void cmd(CLI::App &app);
    void run(Options const &opt);

}