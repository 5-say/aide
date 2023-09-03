#include "demo/demo.cpp"
#include "go_zero/go_zero.cpp"
#include <CLI/CLI.hpp>

int main(int argc, char **argv) {
    CLI::App app{};
    app.require_subcommand();

    demo::cmd(app);
    go_zero::cmd(app);

    CLI11_PARSE(app, argc, argv);

    return 0;
}