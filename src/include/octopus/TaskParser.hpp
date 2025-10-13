#ifndef _OCTOPUS_TASK_PARSER_HPP_
#define _OCTOPUS_TASK_PARSER_HPP_

#include <filesystem>
#include <nlohmann/json.hpp>
#include <nlohmann/json-schema.hpp>

namespace octopus {
    class TaskParser {
    public:
        TaskParser(std::filesystem::path task_schema);

        // validates json provided and if invalid throws exception
        void validateTask(nlohmann::json task_definition);
    private:
        nlohmann::json_schema::json_validator validator_; // validator for validating task definitions
    };

} // namespace octopus

#endif