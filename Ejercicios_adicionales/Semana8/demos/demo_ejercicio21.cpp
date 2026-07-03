#include "AVL.h"
#include "ChainedHashTable.h"
#include "HashCode.h"
#include "UniversalHash.h"
#include <cstring>
#include <iostream>

struct PalabraOrdenada {
  std ::string palabra;
  std::size_t codigo;
};
struct Palabra {
  std::string palabra;
  std::size_t codigo;
  int cantidad;
};

std::vector<std::string> separarString(const std::string &str) {
  std::vector<std::string> tokens{};
  std::string token;
  for (char c : str) {
    if (std::isspace(c)) {
      if (!token.empty()) {
        tokens.push_back(token);
        token.clear();
      }
    } else {
      token += c;
    }
  }
  if (!token.empty()) {
    tokens.push_back(token);
  }
  return tokens;
}

std::vector<std::size_t> hashTable(const std::string &str) {
  std::vector<std::size_t> hashes{};
  std::vector<std::string> tokens = separarString(str);
  for (int i = 0; i < tokens.size(); ++i) {
    hashes.push_back(ods::hashCode(tokens[i]));
  }
  return hashes;
}

std::vector<PalabraOrdenada>
convertStringToUniqueCodeSortedAlphabet(std::vector<std::string> tokens) {
  std::sort(tokens.begin(), tokens.end());
  tokens.erase(std::unique(tokens.begin(), tokens.end()), tokens.end());
  std::vector<PalabraOrdenada> palabras{};
  for (std::size_t i = 0; i < tokens.size(); ++i) {
    PalabraOrdenada po{tokens[i], i};
    palabras.push_back(po);
  }
  return palabras;
}
void printAVLInOrder(const ods::AVL<int> &avl,
                     std::vector<PalabraOrdenada> palabras) {
  std::vector<int> inOrder = avl.inorder();
  std::cout << "AVL in order: ";
  for (int x : inOrder) {
    std::cout << palabras[x].palabra << " ";
  }
  std::cout << "\n";
}
std::vector<Palabra> countRepeatedWords(const std::vector<std::string> &tokens) {
  std::unordered_map<std::string, int> wordCount;
  for (const auto &token : tokens) {
    wordCount[token]++;
  }

  // use Palabra struct to store the word and its count
  std::vector<Palabra> palabras;
  for (const auto &pair : wordCount) {
    Palabra p{pair.first, ods::hashCode(pair.first), pair.second};
    palabras.push_back(p);
  }
  return palabras;
}

int main() {
  std::string input =
      "por qué la tabla hash no sirve naturalmente para consultas por rango "
      "por qué el árbol sí conserva orden cómo detectas inconsistencias entre "
      "ambas estructuras qué complejidad tiene cada operación";

  std::vector<std::string> tokens = separarString(input);
  std::vector<std::size_t> hashes = hashTable(input);
  std::vector<Palabra> palabra = countRepeatedWords(tokens);
  for (const auto &p : palabra) {
    std::cout << "Palabra: " << p.palabra << " Codigo: " << p.codigo << " Cantidad: " << p.cantidad << "\n";
  }
  for (int i = 0; i < hashes.size(); ++i) {
    std::cout << "Token " << i <<  " " <<tokens[i] << " : " << hashes[i] << "\n";
  }
  std::vector<PalabraOrdenada> sortedTokens =
      convertStringToUniqueCodeSortedAlphabet(tokens);
  for (int i = 0; i < sortedTokens.size(); ++i) {
    std::cout << "Token " << sortedTokens[i].palabra << " "
              << sortedTokens[i].codigo << "\n";
  }
  ods::AVL<int> avl;
  for (int i = 0; i < sortedTokens.size(); ++i) {
    avl.insert(i);
  }
  printAVLInOrder(avl, sortedTokens);
  avl.isAVLValid() ? std::cout << "Si es AVL valido\n"
                   : std::cout << "No es AVL \n";
  ods::ChainedHashTable<int> t(8);
  for (std::size_t x : hashes)
    t.add(x);
  std::cout << "ChainedHashTable\n";
  std::cout << "size=" << t.size() << " capacity=" << t.capacity()
            << " load=" << t.loadFactor()
            << " longestBucket=" << t.longestBucket() << "\n";
  std::cout << t.stats() << "\n";
}
