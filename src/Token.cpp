//
// Created by philip on 27.08.2021.
//

#include "Token.hpp"


std::ostream& operator<<(std::ostream& os, const Token& obj) {
    return os
            << "Token(type="
            << stringify_token(obj.type)
            << ", message='"
            << obj.message
            << "', line="
            << obj.line_number
            << ", char="
            << obj.char_number
            << ")"
            << std::endl;
}

bool operator==(Token &t1, Token &t2) {
    return t1.type == t2.type
        && t1.message == t2.message
        && t1.char_number == t2.char_number
        && t1.line_number == t2.line_number;
}


