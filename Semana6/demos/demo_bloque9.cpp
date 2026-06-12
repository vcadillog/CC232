#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Capitulo6.h"

namespace {

void printTrace(const std::vector<ods::HuffmanBuildStep>& steps) {
    std::cout << "Fusiones durante la construccion:\n";

    for (const auto& s : steps) {
        std::cout << "  (" << s.leftLabel << ':' << s.leftFrequency << ") + "
                  << "(" << s.rightLabel << ':' << s.rightFrequency << ") -> "
                  << s.mergedFrequency << '\n';
    }
}

void printCodeTable(const std::vector<ods::HuffmanSymbol>& alphabet,
                    const std::unordered_map<char, std::string>& codes) {
    std::cout << "\nTabla simbolo, frecuencia, codigo, longitud:\n";
    std::cout << "  simbolo  frecuencia  codigo  longitud\n";

    for (const auto& s : alphabet) {
        const std::string& code = codes.at(s.symbol);

        std::cout << "  " << std::setw(7) << s.symbol
                  << "  " << std::setw(10) << s.frequency
                  << "  " << std::setw(6) << code
                  << "  " << std::setw(8) << code.size()
                  << '\n';
    }
}

} // namespace

int main() {
    const std::vector<ods::HuffmanSymbol> alphabet{
        {'A', 5},
        {'B', 5},
        {'C', 10},
        {'D', 10},
        {'E', 20}
    };

    std::cout << "Bloque 9 - Huffman con desempate determinista\n\n";

    const auto steps = ods::huffmanBuildTrace(alphabet);
    printTrace(steps);

    const auto codes = ods::huffmanGenerateCodes(alphabet);
    const auto tree = ods::huffmanGenerateTree(alphabet);

    printCodeTable(alphabet, codes);

    std::cout << "\nPrefijo libre: "
              << std::boolalpha
              << ods::huffmanIsPrefixFree(codes)
              << '\n';

    std::cout << "Costo ponderado total: "
              << ods::huffmanWeightedPathLength(alphabet, codes)
              << '\n';

    const std::string text = "ABCDE";
    const std::string bits = ods::huffmanEncode(text, codes);
    const std::string decoded = ods::huffmanDecode(bits, tree);

    std::cout << "\nTexto original: " << text << '\n';
    std::cout << "Codificado: " << bits << '\n';
    std::cout << "Decodificado: " << decoded << '\n';

    assert(decoded == text);
    assert(ods::huffmanIsPrefixFree(codes));
    assert(ods::huffmanWeightedPathLength(alphabet, codes) == 110);

    const std::vector<ods::HuffmanSymbol> singleSymbol{{'X', 100}};
    const auto singleCodes = ods::huffmanGenerateCodes(singleSymbol);
    const auto singleTree = ods::huffmanGenerateTree(singleSymbol);

    std::cout << "\nCaso de un solo simbolo:\n";
    std::cout << "  X -> " << singleCodes.at('X') << '\n';

    const std::string singleText = "XXX";
    const std::string singleBits = ods::huffmanEncode(singleText, singleCodes);
    const std::string singleDecoded = ods::huffmanDecode(singleBits, singleTree);

    std::cout << "  texto original: " << singleText << '\n';
    std::cout << "  codificado: " << singleBits << '\n';
    std::cout << "  decodificado: " << singleDecoded << '\n';
    std::cout << "  prefijo libre: "
              << ods::huffmanIsPrefixFree(singleCodes)
              << '\n';

    assert(singleCodes.at('X') == "0");
    assert(singleDecoded == singleText);
    assert(ods::huffmanIsPrefixFree(singleCodes));
}
