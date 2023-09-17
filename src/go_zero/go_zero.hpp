#pragma once

#include <CLI/CLI.hpp>
#include <string>

namespace go_zero {

    const std::string subcommand_name = "go-zero";
    const std::string subcommand_description = "go-zero scaffold";
    void cmd(CLI::App &app);

    namespace init {

        const std::string subcommand_name = "init";
        const std::string subcommand_description = "go-zero init scaffold";

        struct Options {
            std::string out; // 输出目录
        };

        void cmd(CLI::App &parent);
        void run(Options const &opt);
    }

    namespace api {

        const std::string subcommand_name = "api";
        const std::string subcommand_description = "生成服务端 api 代码";

        struct Options {
            std::string in; // 定义 api 的 yaml 文件路径
        };

        void cmd(CLI::App &parent);
        void run(Options const &opt);
    }

}