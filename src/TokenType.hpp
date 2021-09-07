//
// Created by philip on 07.09.2021.
//
#pragma once

enum class TokenType {
    NUMBER,
    STRING,
    // Single char tokens
    EQUALS,
    PLUS,
    MINUS,
    STAR,
    FORWARD_SLASH,
    BACKWARDS_SLASH,
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    LESS_THAN,
    GREATER_THAN,
    COLON,
    // Keywords
    DEF,
    PASS,
    CLASS,
    RETURN,
    YIELD,
    ASYNC,
    AWAIT,
    // Other
    IDENTIFIER,
    NEW_LINE,
    INVALID
};

String stringify_token(TokenType token);