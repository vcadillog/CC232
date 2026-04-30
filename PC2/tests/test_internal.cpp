#include "MultiLevelDLList.h"
#include <iostream>

using namespace ods;

int main() {

  MultiLevelDLList<int> list;

  for (int i = 1; i <= 6; i++) {
    list.add(i);
  }

  auto *child1 = list.addChild(2);

  if (child1 != nullptr) {
    child1->add(7);
    child1->add(8);
    child1->add(9);
    child1->add(10);
  }

  auto *child2 = child1->addChild(1);

  if (child2 != nullptr) {
    child2->add(11);
    child2->add(12);
  }

  std::cout << list.size() << " nodos en total\n";
  std::cout << list.checkSize() << " checkSize\n";

  auto *failChild = list.addChild(2);
  if (failChild == nullptr) {
    std::cout << "Restricción: no duplicó child\n";
  }

  DLList<int> result = list.flatten();

  std::cout << "Flatten: ";
  for (int i = 0; i < result.size(); i++) {
    std::cout << result.get(i) << " ";
  }
  std::cout << "\n";

  int expected1[] = {1, 2, 3, 7, 8, 11, 12, 9, 10, 4, 5, 6};
  bool ok = true;

  if (result.size() != 12) ok = false;

  for (int i = 0; i < result.size(); i++) {
    if (result.get(i) != expected1[i]) {
      ok = false;
      break;
    }
  }

  std::cout << "Resultado: " << (ok ? "Correcto" : "Fallo") << "\n";

  list.remove(2);

  std::cout << list.size() << " nodos en total\n";
  std::cout << list.checkSize() << " checkSize\n";

  DLList<int> result2 = list.flatten();

  std::cout << "Después de remove(2): ";
  for (int i = 0; i < result2.size(); i++) {
    std::cout << result2.get(i) << " ";
  }
  std::cout << "\n";

  int expected2[] = {1, 2, 4, 5, 6};

  bool ok2 = (result2.size() == 5);
  for (int i = 0; i < result2.size(); i++) {
    if (result2.get(i) != expected2[i]) {
      ok2 = false;
      break;
    }
  }

  std::cout << "Resultado: " << (ok2 ? "Correcto" : "Fallo") << "\n";

  std::string input = "[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]";

  std::cout << "Input: " << input << "\n";

  MultiLevelDLList<int> list2;

  list2.buildFromString(input);

  std::cout << list2.size() << " nodos en total\n";
  std::cout << list2.checkSize() << " checkSize\n";

  DLList<int> result3 = list2.flatten();

  std::cout << "Flatten: ";
  for (int i = 0; i < result3.size(); i++) {
    std::cout << result3.get(i) << " ";
  }
  std::cout << "\n";

  bool ok3 = (result3.size() == 12);
  std::cout << "Resultado: " << (ok3 ? "Correcto" : "Fallo") << "\n";

  list2.clear();
  std::cout << list2.size() << " nodos en total\n";
  std::cout << list2.checkSize() << " checkSize\n";

  return 0;
}
