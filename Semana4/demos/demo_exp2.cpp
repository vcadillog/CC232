#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Parentheses.h"

struct TestCase {
    std::string descripcion;
    std::string expresion;
};

int main() {
    std::vector<TestCase> tests = {
        {"Vacia", ""},
        {"Sin parentesis", "2+3*4-5"},
        {"Correctamente anidada", "((a+b)*(c-d))"},
        {"Desbalance", "((a+b)"},
        {"Cruce incorrecto", "([)]"},
        {"Varios delimitadores", "{[(a+b)*c]+(d/e)}"},
        {"Larga", "((({[a+b]*(c+d)})-(e/f))+((g*h)-i))"},
        {"Inventada", "[({(x+y)*z}-((m-n)/p))]"}
    };

    std::cout << std::boolalpha;

    for (const auto& test : tests) {
        std::cout << "Caso: " << test.descripcion << '\n';
        std::cout << "Expresion: \"" << test.expresion << "\"\n";
        bool iterativeRes = ods::parenIterative(test.expresion);
        bool recursiveRes = ods::parenRecursive(test.expresion);
        std::cout << "Iterativo balanceado: "
                  << iterativeRes
                  << "\n";
        std::cout << "Recursivo balanceado: "
                  << recursiveRes
                  << "\n";
        std::cout << "Iterativo = Recursivo: "<<(recursiveRes==iterativeRes)<<"\n\n";
    }

    return 0;
}
