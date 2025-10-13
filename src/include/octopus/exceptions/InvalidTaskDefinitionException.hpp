#ifndef _OCTOPUS_InvalidTaskDefinitionException_
#define _OCTOPUS_InvalidTaskDefinitionException_

#include <string>
#include <exception>
#include <sstream>

namespace octopus {
    class InvalidTaskDefinitionException : public std::exception {
    public:
        InvalidTaskDefinitionException(const std::string& msg) : msg_(msg) {}
        
        const char* what() const noexcept override {
            std::stringstream error_msg;
            error_msg << "Invalid task definition provided: " << msg_;
        }

    private:    
        std::string msg_;
    };
} // namespace octopus

#endif 