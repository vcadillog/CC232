## 10/06/2026
- Se eligió un Treap como estructura a utilizar y se refactorizó la librería del curso en .h y .cpp
- Se creó un demo para Treap.
- Se encontró la limitación de Treap que siempre da el mismo resultado independientemente del orden de permutación, se decidió usar una versión del Treap pero que toma los índices en lugar de el valor.
- Se creó un demo para el Treap modificado.
- Se hizo una optimización de O(n^3logn) a O(n^2logn)

## 11/06/2026
- Se agregaron casos borde, casos de prueba y los casos de la plataforma ATcoder.
- Se refactorizó una función que convierte a vector porque es recurrente en las pruebas.

## 12/06/2026
- Se agregó un benchmark para diferentes tamaños de la secuencia.
- Se encontró que no era posible optimizar más siguiendo la misma estructura del Treap y por eso se agregó merge y split como operaciones para reconstruir el Treap de forma más eficiente y se redujo a O(nlogn) la complejidad.
- Se implementó los retos de la práctica.
