//
// Created by philip on 26.08.2021.
//

#pragma once
#define EOF_XD '\000'

#include <unordered_map>
#include "String.hpp"
#include "Token.hpp"
#include "Optional.hpp"

class Lexer {
public:
    explicit Lexer(String);

    Optional<Token> next();

private:
    String raw_code;
    char current_char = {};

    int64_t code_pointer = {-1};
    uint64_t line_number = {0};
    uint64_t char_number = {0};

    char consume();
    [[nodiscard]] char peek() const;

    [[nodiscard]] bool is_eof() const;

    [[nodiscard]] bool is_identifier_start(char c) const;
    [[nodiscard]] bool is_identified_middle(char c) const;
    Optional<Token> get_identifier();

    [[nodiscard]] bool is_single_char_token() const;
    Optional<Token> get_single_char_token();

    [[nodiscard]] static bool is_number(char) ;
    Optional<Token> get_number_token();

    [[nodiscard]] bool is_new_line(char) const;
    Optional<Token> get_new_line_token();

    bool is_keyword(const String&) const;
    Optional<Token> get_keyword_token(const String& value);

    static std::unordered_map<char, TokenType> single_char_tokens;
    static std::unordered_map<String, TokenType> keywords;
};


