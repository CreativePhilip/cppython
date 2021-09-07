//
// Created by philip on 27.08.2021.
//

#pragma once

#include <iostream>
#include "String.hpp"
#include "TokenType.hpp"


class Token {
public:
    Token(TokenType type, String message, uint64_t line_number, uint64_t char_number)
    : type(type)
    , message(message)
    , line_number(line_number)
    , char_number(char_number)
    {
    }

    friend std::ostream& operator<<(std::ostream& os, const Token& obj);
    friend bool operator== (Token &t1, Token &t2);

    TokenType get_type() { return type; }

private:
    TokenType type { TokenType::INVALID };
    String message {};

    uint64_t line_number = {0};
    uint64_t char_number = {0};

};




