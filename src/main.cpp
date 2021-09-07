#include <iostream>
#include "Lexer.hpp"
#include <fstream>

String read_file(const String& path) {
    std::ifstream file{path};
    String line = {};
    String content = {};

    if (!file.is_open()) return {};

    while (getline(file, line)) {
        content += line + "\n";
    }
    file.close();
    return content;
}


int main() {
    String file = read_file("../../test_files_py/simple.py");
//    String file = read_file("../../test_files_py/simple_function_def.py");

    Lexer lexer{file};

    while (auto maybe_token = lexer.next()) {
        std::cout << maybe_token;
    }

    return 0;
}
