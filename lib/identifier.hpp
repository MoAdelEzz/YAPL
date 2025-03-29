#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP

#include <iostream>
#include <string>


enum ValueType { TBOOLEAN, TINT, TCHAR, TFLOAT, TSTRING, TUNDEFINED };
class Value {
    public:
        void* content;
        ValueType type;

        void init(const char* value, ValueType type) {
            this->type = type;
            if (value == nullptr) { return; }

            if (type == TSTRING) { 
                type = TSTRING;
                content = (void*) new std::string(value); 
                return;
            }

            content = malloc(typeToSize(type));
            switch (type) {
                case TINT:
                    *(int*)content = atoi(value); break;
                case TFLOAT:
                    *(float*)content = atof(value); break;
                case TCHAR:
                    *(char*)content = value[0]; break;
                default: break;
            }
        }
        
        static std::string typeToString(ValueType type) {
            switch (type) {
                case TINT:
                    return "int";
                case TFLOAT:
                    return "float";
                case TCHAR:
                    return "char";
                case TBOOLEAN:
                    return "boolean";
                case TSTRING:
                    return "string";
                default:
                    return "undefined";
            }
        }
        
        static int typeToSize(ValueType type) {
            switch (type) {
                case TINT:
                    return sizeof(int);
                case TFLOAT:
                    return sizeof(float);
                case TCHAR:
                    return sizeof(int);
                case TBOOLEAN:
                    return sizeof(int);
                default:
                    return 0;
            }
        }

        std::string toString() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return std::to_string((int) *(int*)content);
                case TFLOAT:
                    return std::to_string((float) *(float*)content);
                case TSTRING:
                    return *(std::string*)content;
                default:
                    return "undefined";
            }
        }

        operator int() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (int) *(int*)content;
                case TFLOAT:
                    return (int) *(float*)content;
                default:
                    return 0;
            }
        }

        operator float() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (float) *(int*)content;
                case TFLOAT:
                    return (float) *(float*)content;
                default:
                    return 0;
            }
        }

        operator char() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (char) (int) *(int*)content;
                case TFLOAT:
                    return (char) (int) *(float*)content;
                default:
                    return 0;
            }
        }

        operator bool() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return *(int*)content != 0;
                case TFLOAT:
                    return *(float*)content != 0;
                default:
                    return 0;
            }
        }

        template<typename T>
        bool operator>(const T& that) const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (int) *(int*)content > that;
                case TFLOAT:
                    return (float) *(float*)content > (float)that;
                case TSTRING:
                    return *(std::string*)content > std::to_string(that);
                default:
                    return 0;
            }
        }

        template<typename T>
        bool operator==(const T& that) const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (int) *(int*)content == that;
                case TFLOAT:
                    return (float) *(float*)content == (float)that;
                case TSTRING:
                    return *(std::string*)content == std::to_string(that);
                default:
                    return false;
            }
        }

        template<typename T>
        bool operator!=(const T& that) const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (int) *(int*)content != that;
                case TFLOAT:
                    return (float) *(float*)content != (float)that;
                case TSTRING:
                    return *(std::string*)content != std::to_string(that);
                default:
                    return true;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const Value& node) {
            switch (node.type) {
                case TINT:
                    os << (int)node;
                    break;
                case TFLOAT:
                    os << (float)node;
                    break;
                case TCHAR:
                    os << (char)node;
                    break;
                case TBOOLEAN:
                    os << (bool)node;
                    break;
                case TSTRING:
                    os << *(std::string*)node.content;
                    break;
                default:
                    throw("WTF Bro");
            }
            return os;
        }
};

class Identifier {

};

#endif