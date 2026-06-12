#include <iostream>
#include <string>
#include <vector>

#include "ExpressionEvaluator.h"

struct TestCase {
    std::string descripcion;
    std::string expresion;
};

int main() {
    std::vector<TestCase> tests = {
        {"Valida sin parentesis 1", "3+4*5"},
        {"Valida sin parentesis 2", "20/5+7"},
        {"Valida con anidamiento 1", "(2+3)*(4+5)"},
        {"Valida con anidamiento 2", "((1+2)*(3+4))-5"},
        {"Menos unario", "-(3+4)*2"},
        {"Invalida", "(3+4*5"}
    };

    for (const auto& test : tests) {
        std::cout << "Caso: " << test.descripcion << '\n';
        std::cout << "Expresion: " << test.expresion << '\n';

        try {
            auto evaluated = ods::evaluateExpression(test.expresion);

            std::cout << "RPN: " << evaluated.rpn << '\n';
            std::cout << "Valor: " << evaluated.value << '\n';
            std::cout << "Valida: true\n";
        }
        catch (const std::exception& e) {
            std::cout << "Valida: false\n";
            std::cout << "Error: " << e.what() << '\n';
        }

        std::cout << '\n';
    }

    return 0;
}
