#pragma once

#include <CLI/CLI.hpp>
#include <string>
#include <nlohmann/json.hpp>
#include <yaml-cpp/yaml.h>

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

        inline nlohmann::json parse_scalar(const YAML::Node& node) {
            int i;
            double d;
            bool b;
            std::string s;

            if (YAML::convert<int>::decode(node, i))
                return i;
            if (YAML::convert<double>::decode(node, d))
                return d;
            if (YAML::convert<bool>::decode(node, b))
                return b;
            if (YAML::convert<std::string>::decode(node, s))
                return s;

            return nullptr;
        }

        inline nlohmann::json yaml2json(const YAML::Node& root) {
            nlohmann::json j{};
            switch (root.Type()) {
            case YAML::NodeType::Null:
                break;
            case YAML::NodeType::Scalar:
                return parse_scalar(root);
            case YAML::NodeType::Sequence:
                for (auto&& node : root)
                    j.emplace_back(yaml2json(node));
                break;
            case YAML::NodeType::Map:
                for (auto&& it : root) {
                    j[it.first.as<std::string>()] = yaml2json(it.second);
                }
                break;
            default:
                break;
            }
            return j;
        }
    }

}