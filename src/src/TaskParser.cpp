#include "octopus/TaskParser.hpp"
#include "octopus/exceptions/InvalidTaskDefinitionException.hpp"

#include <string>
#include <fstream>


namespace octopus {
    TaskParser::TaskParser(std::filesystem::path task_schema) {
        std::ifstream schemaStream(task_schema);
        nlohmann::json  schema;
        schemaStream >> schema;

        validator_.set_root_schema(schema);
    }

    void TaskParser::validateTask(nlohmann::json task_definition) {
        try
        {
            validator_.validate(task_definition);
        }
        catch(const std::exception& e)
        {
            throw InvalidTaskDefinitionException(e.what());
        }
    }
} // namespace octopus