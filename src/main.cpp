#include "demo/demo.cpp"
#include <CLI/CLI.hpp>

int main(int argc, char **argv) {
    CLI::App app{"..."};

    demo::cmd(app);

    app.require_subcommand();

    CLI11_PARSE(app, argc, argv);

    return 0;
}