#pragma once
#include <string>
#include <vector>

enum Severity { ERROR, WARNING };

class ErrorDetail {
    int line;
    Severity severity;
    std::string message;
    std::string suggestion;

    public:
        ErrorDetail(Severity severity, std::string message, std::string suggestion = "", int line = -1 ) 
        : line(line), 
          severity(severity), 
          message(message), 
          suggestion(suggestion) {}

        void setLine(int line) { this->line = line; }
        void setSeverity(Severity severity) { this->severity = severity; }
        void setMessage(std::string message) { this->message = message; }
        void setSuggestion(std::string suggestion) { this->suggestion = suggestion; }
};



class CompilerOrganizer {
    private:    
        static std::vector<ErrorDetail> errors;

    public:
        static void addError(ErrorDetail error) {
            errors.push_back(error);
        }

        static int getErrorCount() { return errors.size(); }
};