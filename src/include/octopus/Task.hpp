#ifndef _TASK_PARSER_HPP_
#define _TASK_PARSER_HPP_

#include <string>
#include <vector>
#include <unordered_map>

namespace octopus {
    struct RetryPolicy {
        int max_retries;
        float delay_seconds;
    };

    struct Task {
        std::string id;
        std::string name;
        std::string command;
        std::vector<std::string> args;
        std::string working_dir;
        std::unordered_map<std::string, std::string> env;
        std::unordered_map<std::string, std::string> trigger;
        std::vector<std::string> dependencies;
        RetryPolicy retry_policy;
    };
} // namespace octopus


#endif