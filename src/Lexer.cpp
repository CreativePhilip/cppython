//
// Created by philip on 26.08.2021.
//

#include "Lexer.hpp"

std::unordered_map<char, TokenType> Lexer::single_char_tokens;
std::unordered_map<String, TokenType> Lexer::keywords;

Lexer::Lexer(String raw_code): raw_code(raw_code) {
    if (single_char_tokens.empty()) {
        single_char_tokens['='] = TokenType::EQUALS;
        single_char_tokens['+'] = TokenType::PLUS;
        single_char_tokens['-'] = TokenType::MINUS;
        single_char_tokens['*'] = TokenType::STAR;
        single_char_tokens['/'] = TokenType::FORWARD_SLASH;
        single_char_tokens['\\'] = TokenType::BACKWARDS_SLASH;
        single_char_tokens['('] = TokenType::LEFT_PAREN;
        single_char_tokens[')'] = TokenType::RIGHT_PAREN;
        single_char_tokens['{'] = TokenType::LEFT_BRACE;
        single_char_tokens['}'] = TokenType::RIGHT_BRACE;
        single_char_tokens['<'] = TokenType::LESS_THAN;
        single_char_tokens['>'] = TokenType::GREATER_THAN;
        single_char_tokens[':'] = TokenType::COLON;
    }

    if (keywords.empty()) {
        keywords["def"] = TokenType::DEF;
        keywords["pass"] = TokenType::PASS;
        keywords["class"] = TokenType::CLASS;
        keywords["return"] = TokenType::RETURN;
        keywords["yield"] = TokenType::YIELD;
        keywords["async"] = TokenType::ASYNC;
        keywords["await"] = TokenType::AWAIT;
    }
}


Optional<Token> Lexer::next() {
    while (true) {
        consume();

        if (is_eof()) return {};

        if (is_new_line(current_char)) {
            return get_new_line_token();
        }

        if (is_single_char_token()) {
            return get_single_char_token();
        }

        if(is_number(current_char)) {
            return get_number_token();
        }

        if (is_identifier_start(current_char)) {
            return get_identifier();
        }
    }
}

char Lexer::consume() {
    code_pointer ++;
    char_number ++;

    current_char = raw_code[code_pointer];
    return current_char;
}

char Lexer::peek() const {
    return raw_code[code_pointer + 1];
}

bool Lexer::is_eof() const {
    return current_char == EOF_XD;
}

bool Lexer::is_identifier_start(char c) const {
    return c >= 'a' && c <= 'z'
        || c >= 'A' && c <= 'Z'
        || c == '_'
        || is_number(c);
}

bool Lexer::is_identified_middle(char c) const {
    return is_identifier_start(c);
}

Optional<Token> Lexer::get_identifier() {
    String acc;
    auto start_line = line_number;
    auto start_char = char_number;


    acc += current_char;
    while (true) {
        auto next = peek();
        if (!is_identified_middle(next)) break;
        acc += consume();
    }

    if (is_keyword(acc))
        return get_keyword_token(acc);
    return {{TokenType::IDENTIFIER, acc, start_line, start_char}};
}

bool Lexer::is_single_char_token() const {
    return single_char_tokens.contains(current_char);
}

Optional<Token> Lexer::get_single_char_token() {
    auto token_type = single_char_tokens[current_char];
    return {{token_type, String(1, current_char), line_number, char_number}};
}

bool Lexer::is_number(char test) {
    return test >= '0' && test <= '9';
}

Optional<Token> Lexer::get_number_token() {
    String acc;
    auto start_line = line_number;
    auto start_char = char_number;

    acc += current_char;
    while (is_number(peek())) {
        acc += consume();
    }
    return {{TokenType::NUMBER, acc, start_line, start_char}};
}

bool Lexer::is_new_line(char test) const {
    return test == '\n';
}

Optional<Token> Lexer::get_new_line_token() {
    return {{TokenType::NEW_LINE, "\\n", line_number, char_number}};
}

bool Lexer::is_keyword(const String& test) const {
    return keywords.contains(test);
}

Optional<Token> Lexer::get_keyword_token(const String& value) {
    return {{keywords[value], value, line_number, char_number}};
}


