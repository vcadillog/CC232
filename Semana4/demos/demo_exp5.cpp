#include <iostream>
#include <string>
#include <vector>

#include "Maze.h"

struct TestMaze {
    std::string nombre;
    ods::Maze maze;
    int sx, sy;
    int tx, ty;
};

int main() {
    std::vector<TestMaze> tests = {
        {
            "Camino claro",
            ods::Maze({
                "#####",
                "#...#",
                "#...#",
                "#...#",
                "#####"
            }),
            1, 1, 3, 3
        },
        {
            "Sin salida",
            ods::Maze({
                "#####",
                "#.#.#",
                "#####",
                "#.#.#",
                "#####"
            }),
            1, 1, 3, 3
        },
        {
            "Con retrocesos",
            ods::Maze({
                    "#########",
                    "#.....#.#",
                    "#####.#.#",
                    "#.....#.#",
                    "#.#####.#",
                    "#...#...#",
                    "#########"
            }),
            1, 1, 5, 7
        }
    };

    for (auto& test : tests) {
        auto path = ods::findPath(
            test.maze,
            test.sx, test.sy,
            test.tx, test.ty
        );

        int backtracks = 0;

        for (int i = 0; i < test.maze.rows(); ++i) {
            for (int j = 0; j < test.maze.cols(); ++j) {
                const auto* cell = test.maze.at(i, j);

                if (cell != nullptr &&
                    cell->status == ods::BACKTRACKED) {
                    ++backtracks;
                }
            }
        }

        std::cout << "Caso: " << test.nombre << '\n';
        std::cout << "Inicio: (" << test.sx << "," << test.sy << ")\n";
        std::cout << "Destino: (" << test.tx << "," << test.ty << ")\n";

        if (path.empty()) {
            std::cout << "Camino: NO EXISTE\n";
        } else {
            std::cout << "Longitud del camino: "
                      << path.size() << '\n';
        }

        std::cout << "Retrocesos detectados: "
                  << backtracks << '\n';

        std::cout << "Interpretacion: ";

        if (path.empty()) {
            std::cout << "No existe ruta entre inicio y destino.";
        } else if (backtracks == 0) {
            std::cout << "El algoritmo encontro la ruta sin necesidad de retroceder.";
        } else {
            std::cout << "El algoritmo exploro caminos incorrectos y tuvo que retroceder.";
        }

        std::cout << "\n\n";
    }

    return 0;
}
