### Actividad 6 - CC232 

- Duración: 3 horas de clase.
- Modalidad: Trabajo individual.
- Entrega: Un archivo llamado `Actividad6-CC232.md` y los archivos modificados solicitados.

#### Objetivo

Consolidar lo trabajado en la Semana 6 a partir de lectura cercana, modificación controlada de código, ejecución de demostraciones, ampliación de pruebas y defensa escrita breve.

La meta principal no es solo ejecutar la librería, sino **intervenir el código** para demostrar comprensión real de:

1. La interfaz abstracta de cola de prioridad: `PQ`.
2. La implementación con heap binario completo: `PQ_ComplHeap`.
3. Las operaciones `getMax`, `insert`, `delMax`, `percolateUp`, `percolateDown` y `heapify` de Floyd.
4. El ordenamiento `heapSort`.
5. El heap izquierdista: `PQ_LeftHeap` y su operación central `merge`.
6. La codificación Huffman como aplicación de colas de prioridad.
7. La comparación con estructuras de la Semana 5: `BinaryHeap`, `BinarySearchTree` y apoyo conceptual de `BinaryTree`.
8. La relación entre prioridad, búsqueda ordenada y estructuras híbridas como `Treap`.

El énfasis de esta actividad está en **modificar, justificar, probar y defender** cambios pequeños pero técnicamente significativos.

#### Material de trabajo

##### Código de la semana

Revisa como mínimo:

- `Semana6/README.md`
- `Semana6/lecturas/Notas.md`
- `Semana6/include/PQ.h`
- `Semana6/include/PQ_ComplHeap.h`
- `Semana6/include/PQ_ComplHeap_macro.h`
- `Semana6/include/PQ_ComplHeap_getMax.h`
- `Semana6/include/PQ_ComplHeap_insert.h`
- `Semana6/include/PQ_ComplHeap_delMax.h`
- `Semana6/include/PQ_ComplHeap_percolateUp.h`
- `Semana6/include/PQ_ComplHeap_percolateDown.h`
- `Semana6/include/PQ_ComplHeap_heapifyFloyd.h`
- `Semana6/include/vector_heapSort.h`
- `Semana6/include/PQ_LeftHeap.h`
- `Semana6/include/PQ_LeftHeap_merge.h`
- `Semana6/include/PQ_LeftHeap_insert.h`
- `Semana6/include/PQ_LeftHeap_delMax.h`
- `Semana6/include/Huffman_PQ.h`
- `Semana6/include/Huffman_PQ_generateTree.h`
- `Semana6/include/MeldableHeap.h`
- `Semana6/include/Treap.h`
- `Semana6/include/Capitulo6.h`
- `Semana6/include/Capitulo10.h`

##### Código reutilizado de Semana 5

Revisa también:

- `Semana5/include/BinaryTree.h`
- `Semana5/include/BinaryHeap.h`
- `Semana5/include/BinarySearchTree.h`
- `Semana5/include/Capitulo5.h`

##### Demostraciones y pruebas

Revisa y ejecuta:

- `Semana6/demos/demo_pq_complheap_basico.cpp`
- `Semana6/demos/demo_heapify_floyd.cpp`
- `Semana6/demos/demo_heapsort.cpp`
- `Semana6/demos/demo_left_heap_merge.cpp`
- `Semana6/demos/demo_huffman.cpp`
- `Semana6/demos/demo_compare_with_semana5.cpp`
- `Semana6/demos/demo_bst_rotations.cpp`
- `Semana6/demos/demo_treap_basico.cpp`
- `Semana6/demos/demo_capitulo6_panorama.cpp`
- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`
- `Semana6/CMakeLists.txt`

#### Reglas de modificación

1. No reemplaces las estructuras principales por `std::priority_queue`, `std::set`, `std::map` o funciones estándar que oculten el algoritmo central.
2. Toda modificación debe mantener el estilo de la librería: headers simples, C++17, nombres claros y sin macros innecesarias.
3. Cada cambio debe compilar.
4. Cada cambio debe tener al menos una evidencia: demostraciones, prueba pública, prueba interna o salida documentada.
5. En los archivos modificados, marca tus cambios con comentarios breves de este estilo:

```cpp
// MOD-A6-B3: validacion de propiedad heap
```

6. No basta con decir "funciona". Debes explicar qué invariante se preserva, qué caso borde se cubre y qué costo tiene la operación modificada.

#### Bloque 1 - Diagnóstico inicial de la Semana 6

Revisa:

- `Semana6/README.md`
- `Semana6/CMakeLists.txt`
- `Semana6/include/Capitulo6.h`
- `Semana6/include/Capitulo10.h`

Ejecuta desde la raíz de la librería o desde el entorno de compilación que uses:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Responde:

1. ¿Qué targets de demostraciones o pruebas aparecen para Semana 6?

2.
```cpp
#include "PQ.h"
#include "PQ_ComplHeap_macro.h"
#include "PQ_ComplHeap.h"
#include "PQ_ComplHeap_getMax.h"
#include "PQ_ComplHeap_insert.h"
#include "PQ_ComplHeap_percolateUp.h"
#include "PQ_ComplHeap_delMax.h"
#include "PQ_ComplHeap_percolateDown.h"
#include "PQ_ComplHeap_heapifyFloyd.h"
#include "PQ_LeftHeap.h"
#include "PQ_LeftHeap_merge.h"
#include "PQ_LeftHeap_insert.h"
#include "PQ_LeftHeap_delMax.h"
#include "vector_heapSort.h"
#include "Huffman_PQ.h"
#include "Treap.h"
```

3. En Capítulo10.h es una abstracción que reutiliza Capitulo6.h y crea un alias

4. Se utilizan árboles y/o heap en los archivos PQ_*.h, Huffman.h y Treap.

5. Se usa la estructura heap para prioridad.

6. Se utilizan BST para busqueda ordenada.

7. Treap mezcla busqueda ordenada con prioridad.

8. ¿Qué evidencia inicial obtuviste al ejecutar las pruebas sin modificar nada?.

Entrega en este bloque:

- Una tabla con: comando ejecutado, resultado, error si hubo, interpretación.
- Una lista de los archivos que planeas modificar.

```cpp
cmake --build build-debug 
[100%] Built target sem6_test_internal

ctest --test-dir build-debug -R semana6 --output-on-failure
Internal ctest changing into directory: /home/victor/clases/algoritmos/CC232/Semana6/build-debug
Test project /home/victor/clases/algoritmos/CC232/Semana6/build-debug
    Start 1: semana6_public
1/2 Test #1: semana6_public ...................   Passed    0.00 sec
    Start 2: semana6_internal
2/2 Test #2: semana6_internal .................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.01 sec
```

#### Bloque 2 - Modificación de utilidades de heap completo

1. Porque la representación del heap completo es implícita: no hay nodos enlazados, sino posiciones en un vector. Las relaciones estructurales se calculan con índices:
```cpp
parent(i) = (i - 1) / 2
left(i)   = 2 * i + 1
right(i)  = 2 * i + 2
```
Si estas fórmulas se repiten manualmente en muchas partes, aumentan los errores de frontera. Al moverlas a funciones pequeñas, el código queda más legible, reusable y fácil de probar.

2. constexpr respeta tipos, namespaces y reglas del compilador de C++. Una macro solo sustituye texto antes de compilar, por lo que puede producir errores difíciles de rastrear. Además, constexpr permite evaluación en tiempo de compilación cuando los argumentos son constantes, pero sigue funcionando como una función normal cuando los valores se conocen en ejecución.

3. En un heap completo puede ocurrir que un nodo tenga hijo izquierdo pero no hijo derecho. En ese caso, percolateDown no debe intentar leer a[right(i)]. La solución es asumir primero que el hijo dominante es el izquierdo:

```cpp
std::size_t c = pqLeftChild(i);
```

y solo comparar con el derecho si existe:

```cpp
if (pqHasRightChild(i, n)) { ... }
```

4.Una posición i es hoja si pertenece al heap y no tiene hijo izquierdo:

```cpp
pqInHeap(i, n) && !pqHasLeftChild(i, n)
```
En un heap binario completo, si un nodo no tiene hijo izquierdo, tampoco puede tener hijo derecho. Por eso basta revisar el hijo izquierdo.

5.Cambió la forma de expresar las condiciones, no el algoritmo. Antes se escribía directamente:

```cpp
while (pqInHeap(pqLeftChild(i), n))
```
Ahora se escribe:

```cpp
while (pqIsInternal(i, n))
```
Esto comunica mejor la intención: "mientras el nodo sea interno, puede bajar". También se reemplaza la prueba directa del hijo derecho por pqHasRightChild(i, n).

La complejidad no cambia.

percolateDown sigue bajando como máximo una rama del heap. Como un heap binario completo con n elementos tiene altura O(log n), la operación sigue costando:

```cpp
O(log n)
```
Las nuevas funciones auxiliares ejecutan operaciones aritméticas y comparaciones constantes, por lo que cuestan:

```cpp
O(1)
```
Entonces el costo total sigue siendo:

```cpp
O(log n) * O(1) = O(log n)

```cpp
[100%] Built target sem6_test_internal
...
100% tests passed, 0 tests failed out of 2
```

#### Bloque 3 - Modificación de `percolateUp`: conteo de intercambios

1. Hace cero intercambios cuando el elemento insertado no tiene padre, como ocurre al insertar el primer elemento, o cuando el padre ya tiene prioridad mayor 
o igual que el hijo.

En un max-heap con `std::less<int>`, eso ocurre cuando:

```cpp
a[parent] >= a[child]
```

Por ejemplo, al insertar `10` después de `40`, no se intercambia porque `40` ya domina a `10`.

2. Puede hacer `O(log n)` intercambios cuando el elemento insertado tiene mayor prioridad que todos sus ancestros y debe subir desde una hoja hasta la raíz.

Ejemplo de la traza:

```text
insertado=90 | intercambios=2 | heap=[90, 70, 40, 10, 30]
```

El `90` entra al final, sube sobre `30` y luego sobre `70`. En un heap más grande, podría subir por toda la altura del árbol.


3. La inserción coloca primero el nuevo elemento al final del arreglo. Esa posición corresponde a la siguiente hoja disponible del árbol binario completo. 
Desde esa hoja, `percolateUp` solo puede subir por el camino hacia la raíz.

Por eso, el número máximo de intercambios está acotado por la altura del heap:

```text
altura = O(log n)
```

No puede recorrer ramas laterales ni visitar todos los nodos.


4. Porque el heap no mantiene orden total en el arreglo. Mantiene una propiedad local entre padres e hijos.

En un max-heap se garantiza que cada padre sea mayor o igual que sus hijos, pero no se garantiza que:

```text
a[0] >= a[1] >= a[2] >= a[3] ...
```

Por ejemplo, este arreglo final es heap válido:

```text
[90, 70, 80, 60, 30, 20, 40, 10]
```

pero no está ordenado de forma descendente, porque `80` aparece después de `70`, y `40` aparece después de `20`.

5. Queda garantizada la **propiedad heap**:

```text
Para todo nodo i:
a[i] tiene prioridad mayor o igual que sus hijos.
```

En max-heap con `std::less<int>`:

```text
a[i] >= a[left(i)]
a[i] >= a[right(i)]
```

cuando esos hijos existen.

Argumento de costo

`complHeapPercolateUpCount` realiza las mismas operaciones estructurales que `complHeapPercolateUp`, pero agrega un contador `swaps`. 
Ese contador solo cuesta `O(1)` por intercambio.

En el peor caso, el elemento insertado sube desde una hoja hasta la raíz. La altura de un heap binario completo con `n` elementos es:

```text
O(log n)
```

Por tanto:

```text
Tiempo peor caso: O(log n)
Tiempo mejor caso: O(1)
Espacio adicional: O(1)
```

```text
Bloque 3 - conteo de intercambios en percolateUp
Convencion: max-heap usando std::less<int>

insertado=40 | intercambios=0 | heap=[40] | propiedad_heap=verdadero
insertado=10 | intercambios=0 | heap=[40, 10] | propiedad_heap=verdadero
insertado=70 | intercambios=1 | heap=[70, 10, 40] | propiedad_heap=verdadero
insertado=30 | intercambios=1 | heap=[70, 30, 40, 10] | propiedad_heap=verdadero
insertado=90 | intercambios=2 | heap=[90, 70, 40, 10, 30] | propiedad_heap=verdadero
insertado=20 | intercambios=0 | heap=[90, 70, 40, 10, 30, 20] | propiedad_heap=verdadero
insertado=80 | intercambios=1 | heap=[90, 70, 80, 10, 30, 20, 40] | propiedad_heap=verdadero
insertado=60 | intercambios=1 | heap=[90, 70, 80, 60, 30, 20, 40, 10] | propiedad_heap=verdadero
```

#### Bloque 4 - Modificación de `percolateDown`: elección del hijo dominante

1. Porque el último elemento se mueve a la raíz para llenar el espacio dejado por el máximo eliminado, y luego se baja para restaurar la propiedad de heap.
2. Porque el elemento que se mueve a la raíz puede ser menor que sus hijos, por lo que necesita bajar para restaurar la propiedad de heap.
3. Empieza eligiendo al hijo izquierdo y luego se compara el valor del hijo izquierdo con el del hijo derecho utilizando comp. Si el hijo derecho existe y es mayor que el hijo izquierdo, entonces se selecciona el hijo derecho como el candidato. Luego se continúa con el intercambio.
4. Al ser un heap, tiene que tener un hijo izquierdo y no se compara con el derecho si no existe, luego se intercambia solo con el hijo izquierdo.
5. Porque en el peor caso, el elemento que se mueve a la raíz puede bajar hasta la hoja más profunda del heap, en un árbol binario la altura es logn. 

```text
Bloque 4:

heap interno: [14, 12, 10, 5, 3, 7, 9, 1, 4]

Contando el número de intercambios
Heap antes de reparar:[ 4 12 10 5 3 7 9 1 ]
Número de intercambios:2
delMax() -> 14
heap interno: [12, 5, 10, 4, 3, 7, 9, 1]

Heap antes de reparar:[ 1 5 10 4 3 7 9 ]
Número de intercambios:2
delMax() -> 12
heap interno: [10, 5, 9, 4, 3, 7, 1]

Heap antes de reparar:[ 1 5 9 4 3 7 ]
Número de intercambios:2
delMax() -> 10
heap interno: [9, 5, 7, 4, 3, 1]

Heap antes de reparar:[ 1 5 7 4 3 ]
Número de intercambios:1
delMax() -> 9
heap interno: [7, 5, 1, 4, 3]

Heap antes de reparar:[ 3 5 1 4 ]
Número de intercambios:2
delMax() -> 7
heap interno: [5, 4, 1, 3]

Heap antes de reparar:[ 3 4 1 ]
Número de intercambios:1
delMax() -> 5
heap interno: [4, 3, 1]

Heap antes de reparar:[ 1 3 ]
Número de intercambios:1
delMax() -> 4
heap interno: [3, 1]

Heap antes de reparar:[ 1 ]
Número de intercambios:0
delMax() -> 3
heap interno: [1]

Número de intercambios:0
delMax() -> 1
heap interno: []
```

#### Bloque 5 - Validación explícita de la propiedad heap

1. ¿Qué invariante verifica la función?

Verifica la **propiedad heap**. Para cada posición `i`, si existen sus hijos `left(i)` y `right(i)`, el padre debe tener prioridad mayor o igual que cada 
hijo según el comparador.

Con `std::less<int>`:

```text
a[i] >= a[left(i)]
a[i] >= a[right(i)]
```

Con `std::greater<int>`, la interpretación se invierte y se valida una estructura tipo min-heap.

2. ¿Por qué basta revisar relaciones padre-hijo?

Porque la propiedad heap es local. Si cada padre domina a sus hijos, entonces por transitividad también domina a los nodos que están debajo de esos hijos
en la ruta correspondiente.

No se necesita comparar la raíz con todos los nodos ni cada nodo con todos sus descendientes. El heap no exige orden total, exige dominancia local entre padre e hijos.

3. ¿Por qué no es necesario comparar cada nodo con todos sus descendientes?

Porque eso sería redundante y más costoso. Si se cumple:

```text
padre domina a hijo
hijo domina a nieto
nieto domina a bisnieto
```

entonces la dominancia se propaga por cada camino del árbol. Revisar padre-hijo en cada arista del árbol ya cubre toda la estructura.

Además, un heap completo representado en arreglo tiene como máximo `n - 1` relaciones padre-hijo reales. Validar esas relaciones basta.

4. ¿Cuál es el costo de validar todo el heap?

El costo es:

```text
O(n)
```

La función recorre el arreglo una vez. Para cada índice calcula como máximo dos hijos y hace como máximo dos comparaciones. 
Cada paso cuesta `O(1)`, por eso validar `n` elementos cuesta `O(n)`.

El espacio adicional es:

```text
O(1)
```

porque solo usa índices auxiliares.

5. ¿Por qué esta función es útil en pruebas pero no necesariamente en producción?

Es útil en pruebas porque detecta errores en `insert`, `delMax`, `heapify`, `percolateUp` y `percolateDown`.Si una operación deja mal ubicada una clave, `isValidHeap()` lo detecta inmediatamente.

Pero en producción no siempre conviene llamarla después de cada operación, porque agregaría un costo `O(n)` a operaciones que normalmente cuestan `O(log n)` o `O(1)`. Por ejemplo:

```text
insert: O(log n)
delMax: O(log n)
getMax: O(1)
isValidHeap: O(n)
```
Entonces, en pruebas es una herramienta de verificación, en producción debe usarse solo en modo diagnóstico, depuración o validaciones excepcionales.

- Evidencia de `ctest`.

```text
Test project /home/victor/clases/algoritmos/CC232-pc1/Semana6/build
    Start 1: semana6_public
1/2 Test #1: semana6_public ...................   Passed    0.00 sec
    Start 2: semana6_internal
2/2 Test #2: semana6_internal .................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2
```

#### Bloque 6 - Construcción de heap: inserciones sucesivas vs Floyd

1. Porque un heap no exige un orden total del arreglo. Solo exige una relación local entre cada padre y sus hijos.

En un max-heap:

```text
padre >= hijo izquierdo
padre >= hijo derecho
```

mientras esos hijos existan.

Por eso estos dos arreglos son distintos:

```text
[90, 55, 89, 34, 17, 21, 8, 4, 13, 2, 1, 3]
[90, 55, 89, 34, 4, 21, 8, 13, 17, 2, 1, 3]
```

pero ambos son heaps válidos. El heap no determina una única representación para el mismo conjunto de claves.

2. Cada inserción agrega un elemento al final y puede subirlo hasta la raíz con `percolateUp`.

En el peor caso, una inserción cuesta:

```text
O(log n)
```

Si se insertan `n` elementos uno por uno, el costo acumulado puede ser:

```text
O(log 1) + O(log 2) + ... + O(log n) = O(n log n)
```

Esto ocurre cuando muchos elementos nuevos tienen prioridad alta y suben varios niveles.

3. Porque Floyd no trata cada elemento como una inserción independiente. Parte del arreglo completo y solo llama a `percolateDown` en nodos internos.

La clave del análisis es que la mayoría de nodos están cerca de las hojas y bajan poco o nada. Hay muchos nodos con altura pequeña y pocos nodos con altura grande.

La suma real de trabajo queda acotada linealmente:

```text
muchos nodos bajan 0 o 1 nivel
pocos nodos bajan muchos niveles
costo total = O(n)
```

Por eso Floyd es más eficiente cuando ya tenemos todos los datos desde el inicio.

4. Procesa primero el último nodo interno, luego avanza hacia atrás hasta la raíz.

En un vector de tamaño `n`, las hojas empiezan aproximadamente en `n / 2`. Por eso el último nodo interno está en:

```cpp
n/2 - 1
```

La implementación del repositorio usa este patrón:

```cpp
for (std::size_t i = a.size() / 2; i-- > 0;) {
    complHeapPercolateDown(a, a.size(), i, comp);
}
```

Ese ciclo procesa:

```text
n/2 - 1, n/2 - 2, ..., 1, 0
```

En la entrada del bloque, con `n = 12`, procesa:

```text
5, 4, 3, 2, 1, 0
```

5. Porque una hoja ya es un heap válido de tamaño 1. No tiene hijos, así que no puede violar la propiedad padre-hijo.

Llamar a `percolateDown` desde una hoja no cambiaría nada. Por eso Floyd empieza desde el último nodo interno. Cuando procesa un nodo interno, sus subárboles hijos ya fueron reparados o son hojas. Entonces puede reparar el subárbol completo con una sola bajada local.

6. Explicación de complejidad

Construcción por inserciones

Cada elemento puede subir desde una hoja hasta la raíz.

```text
Costo por inserción: O(log n)
Número de inserciones: n
Costo total: O(n log n)
Espacio adicional: O(1), además del vector del heap
```

Esta estrategia es adecuada cuando los datos llegan en streaming o no se conocen todos al inicio.

Construcción por Floyd

Floyd trabaja desde abajo hacia arriba.

```text
Costo total: O(n)
Espacio adicional: O(1)
```

Es preferible cuando ya se tiene el arreglo completo y se quiere convertirlo en heap de forma eficiente.

```bash
Test project /home/victor/clases/algoritmos/CC232-pc1/Semana6/build
    Start 1: semana6_public
1/2 Test #1: semana6_public ...................   Passed    0.00 sec
    Start 2: semana6_internal
2/2 Test #2: semana6_internal .................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.01 sec
```

```text
Bloque 6 - construccion de heap
Convencion: max-heap usando std::less<int>

arreglo inicial: [4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89]
heap por inserciones: [90, 55, 89, 34, 17, 21, 8, 4, 13, 2, 1, 3]
heap por Floyd: [90, 55, 89, 34, 4, 21, 8, 13, 17, 2, 1, 3]

intercambios por inserciones: 9
intercambios por Floyd: 7
heap por inserciones valido: verdadero
heap por Floyd valido: verdadero

Interpretacion: ambos arreglos representan heaps validos, aunque no necesariamente tienen la misma f
orma interna.
```
Tabla comparativa del Bloque 6

| Criterio             |                         Inserciones sucesivas |                              Heapify de Floyd |
| -------------------- | --------------------------------------------: | --------------------------------------------: |
| Entrada              | `[4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89]` | `[4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89]` |
| Operación usada      |                      `insert` + `percolateUp` |          `percolateDown` desde nodos internos |
| Arreglo final        | `[90, 55, 89, 34, 17, 21, 8, 4, 13, 2, 1, 3]` | `[90, 55, 89, 34, 4, 21, 8, 13, 17, 2, 1, 3]` |
| Intercambios medidos |                                           `9` |                                           `7` |
| Propiedad heap       |                                        válida |                                        válida |
| Costo peor caso      |                                  `O(n log n)` |                                        `O(n)` |
| Cuándo conviene      |              cuando llegan elementos en línea |              cuando ya tienes todos los datos |

#### Bloque 7 - Modificación de `heapSort`

1. Porque usa el mismo `vector` como dos zonas:

```text
[ heap activo | zona ya ordenada ]
```

Primero convierte todo el arreglo en heap. Luego intercambia la raíz con la última posición del heap activo. Esa última posición queda fija como parte de la zona ordenada. Después reduce el tamaño lógico del heap y repara desde la raíz con `percolateDown`.

No necesita una estructura auxiliar de tamaño `n`. Solo usa intercambios dentro del mismo arreglo.

2.
Esta parte:

```cpp
for (std::size_t n = a.size(); n > 1; --n) {
    std::swap(a[0], a[n - 1]);
    complHeapPercolateDown(a, n - 1, 0, comp);
}
```

Cada iteración extrae conceptualmente la raíz del heap, la coloca al final del rango activo y reduce `n`. El heap queda restringido a `[0, n - 2]`. La parte final `[n - 1, size - 1]` ya no se considera heap: es la zona ordenada.

3.

Tiene dos fases:

```text
1. heapify de Floyd: O(n)
2. n - 1 extracciones implícitas: cada una cuesta O(log n)
```

La segunda fase domina:

```text
O(n) + O(n log n) = O(n log n)
```

Por eso heapsort tiene costo `O(n log n)` en peor caso, promedio y mejor caso asintótico.

4.
No. Heapsort **no es estable** en su forma clásica.

Un algoritmo estable conserva el orden relativo de elementos con claves iguales. Por ejemplo, si entran estos elementos:

```text
(5, A), (1, X), (5, B), (3, Y)
```

y se ordena por la primera componente, una salida estable debería mantener:

```text
(5, A) antes de (5, B)
```

Pero heapsort puede producir:

```text
(1, X), (3, Y), (5, B), (5, A)
```

Los dos elementos con clave `5` cambiaron su orden relativo. Esto ocurre porque heapsort realiza intercambios de larga distancia entre la raíz y el final del rango activo.

5.

`heapSort` trabaja **in situ** sobre el mismo vector. No necesita construir una cola de prioridad separada ni almacenar todas las extracciones en otro arreglo.

En cambio, extraer todos los elementos con `delMax` normalmente implica:

```text
1. construir una estructura PQ_ComplHeap,
2. llamar delMax repetidamente,
3. guardar las salidas en otro contenedor si se quiere conservar el resultado ordenado.
```

Ambos enfoques tienen costo `O(n log n)`, pero su intención es distinta:

```text
heapSort: ordenar un arreglo.
PQ + delMax: consumir elementos por prioridad.
```

Además, `delMax` es más natural cuando la prioridad se usa dinámicamente, por ejemplo cuando se intercalan inserciones y extracciones. `heapSort` es más adecuado cuando ya se tiene todo el arreglo y se quiere dejarlo ordenado.

```text
Bloque 7 - heapSort ascendente y descendente

entrada: [5, 1, 5, 3, 8, 2, 8, 0]
salida ascendente: [0, 1, 2, 3, 5, 5, 8, 8]
salida descendente: [8, 8, 5, 5, 3, 2, 1, 0]

Evidencia de repetidos
conteo entrada: {0 -> 1, 1 -> 1, 2 -> 1, 3 -> 1, 5 -> 2, 8 -> 2}
conteo ascendente: {0 -> 1, 1 -> 1, 2 -> 1, 3 -> 1, 5 -> 2, 8 -> 2}
conteo descendente: {0 -> 1, 1 -> 1, 2 -> 1, 3 -> 1, 5 -> 2, 8 -> 2}

Interpretacion: los valores repetidos no se eliminan. Aparecen dos 5 y dos 8 en ambas salidas.
```

#### Bloque 8 - Heap izquierdista: validación de `merge`

1. Porque merge es la operación que permite combinar dos heaps izquierdistas manteniendo la propiedad izquierdista.
2. Para insertar un nuevo elemento, se crea un nuevo heap con ese elemento como único nodo y luego se mezcla con el heap existente usando merge.
3. Para eliminar el máximo, se elimina la raíz del heap y luego se mezclan sus hijos izquierdo y derecho usando merge para formar el nuevo heap.
4. La propiedad adicional es que en un heap izquierdista, el subárbol izquierdo siempre tiene una distancia nula (npl) mayor o igual que la del subárbol derecho.
5. Un heap izquierdista usa operaciones sobre nodos enlazados para tener costo O(logn) para fusionar heaps.

6. Demostración modificada.

```text
heap A antes del merge: [9, 7, 2]
heap B antes del merge: [11, 8, 1, 3]
Heap A es izquierdista: true
Heap B es izquierdista: true
heap A despues del merge: [11, 8, 9, 1, 3, 7, 2]
Heap A es izquierdista: true
B queda vacio: true
Copia de A despues del merge: [11, 8, 9, 1, 3, 7, 2]
A despues de insert(10): [11, 8, 10, 1, 3, 9, 7, 2]
A despues de insertMerge(10): [11, 8, 10, 1, 3, 9, 7, 2]
Heap A es izquierdista: true
delMax() -> 11
heap después de delMax(): [10, 8, 9, 1, 3, 7, 2]
delMax() -> 10
heap después de delMax(): [9, 8, 7, 1, 3, 2]
delMax() -> 9
heap después de delMax(): [8, 7, 1, 2, 3]
delMax() -> 8
heap después de delMax(): [7, 2, 3, 1]
delMax() -> 7
heap después de delMax(): [3, 1, 2]
delMax() -> 3
heap después de delMax(): [2, 1]
delMax() -> 2
heap después de delMax(): [1]
delMax() -> 1
heap después de delMax(): []
```

7. Trazado de una fusión pequeña

Supongamos:

```text
A = [9, 4]
B = [8, 3, 2]
```

Como es max-heap, la raíz final debe ser `9`.

Paso 1:

```text
merge(9, 8)
```

`9` domina a `8`, entonces `9` queda como raíz.

Paso 2:

```text
9.right = merge(9.right, 8)
```

Si `9.right` era nulo, entonces `8` queda temporalmente como hijo derecho de `9`.

Paso 3:

Se revisa la propiedad izquierdista:

```text
npl(left) >= npl(right)
```

Si el lado derecho tiene mayor `npl` que el izquierdo, se intercambian hijos.

Resultado posible por niveles:

```text
[9, 8, 4, 3, 2]
```

El árbol no busca quedar completo como un heap binario en arreglo. Busca mantener el camino derecho corto para que futuras fusiones sean eficientes.


#### Bloque 9 - Huffman: modificación de desempate y caso de un símbolo

1. Porque en cada paso debe seleccionar los **dos árboles de menor frecuencia**. Una cola de prioridad permite extraer esos mínimos eficientemente. En esta librería se reutiliza `PQ_ComplHeap` y también existe una variante con `PQ_LeftHeap`, lo cual conecta Huffman con las estructuras principales de Semana 6. 

2. Se extraen dos nodos raíz del bosque actual. Al inicio esos nodos son hojas, una por símbolo. Después pueden ser nodos internos que representan subárboles ya fusionados.

3. Se vuelve a insertar un nodo interno cuya frecuencia es la suma de las dos frecuencias extraídas:

```text
frecuencia_nueva = frecuencia_izquierda + frecuencia_derecha
```

Ese nodo interno representa un árbol parcial de Huffman.

4. Porque si solo existe una hoja, el camino desde la raíz hasta esa hoja tiene longitud cero. Sin tratamiento especial, el código del símbolo sería la cadena vacía. Para que la codificación sea práctica y verificable, se asigna un código como `"0"`. El código actual ya implementa esa decisión con `prefix.empty() ? "0" : prefix`. 

5. Significa que ningún código completo es prefijo de otro. Por ejemplo, si `A = 0`, no puede existir otro símbolo con código `01` o `011`. Esta propiedad permite decodificar de izquierda a derecha sin separadores.

6. Si dos símbolos o subárboles tienen la misma frecuencia, cualquiera de ellos puede extraerse primero sin violar la estrategia greedy. Sin embargo, el orden elegido cambia qué nodo queda a la izquierda o a la derecha, y por eso puede cambiar los bits exactos de los códigos.

Por ejemplo, con `A:5` y `B:5`, si `A` se toma primero, podría recibir el prefijo `0` dentro de su subárbol, si se toma primero `B`, los bits de ambos podrían invertirse. El costo puede seguir siendo el mismo, pero la tabla de códigos cambia.

7. No necesariamente. El desempate puede cambiar la **forma exacta** del árbol y los bits asignados, pero si los empates son entre frecuencias iguales, normalmente no cambia el costo ponderado total. En el ejemplo propuesto, diferentes desempates válidos pueden seguir dando costo `110`, aunque produzcan códigos distintos.

- Tabla símbolo, frecuencia, código, longitud.

| Símbolo | Frecuencia | Código | Longitud |
| ------- | ---------: | -----: | -------: |
| `A`     |          5 | `1100` |        4 |
| `B`     |          5 | `1101` |        4 |
| `C`     |         10 |  `111` |        3 |
| `D`     |         10 |   `10` |        2 |
| `E`     |         20 |    `0` |        1 |

Verificación conceptual:

* `0` no es prefijo de ningún otro código, porque todos los demás empiezan con `1`.
* `10` no es prefijo de `1100`, `1101` ni `111`.
* `111` no es prefijo de `1100` ni `1101`.
* `1100` y `1101` solo difieren en el último bit.

Por tanto, el conjunto es libre de prefijos.

Bloque 9 - Huffman con desempate determinista

Fusiones durante la construccion:
  (A:5) + (B:5) -> 10
  (*A:10) + (C:10) -> 20
  (D:10) + (*A:20) -> 30
  (E:20) + (*A:30) -> 50

Tabla simbolo, frecuencia, codigo, longitud:
  simbolo  frecuencia  codigo  longitud
        A           5    1100         4
        B           5    1101         4
        C          10     111         3
        D          10      10         2
        E          20       0         1

Prefijo libre: true
Costo ponderado total: 110

Texto original: ABCDE
Codificado: 11001101111100
Decodificado: ABCDE

Caso de un solo simbolo:
  X -> 0
  texto original: XXX
  codificado: 000
  decodificado: XXX
  prefijo libre: true

#### Bloque 10 - Treap: modificación de código, rotaciones e invariantes

##### Parte A - Construcción determinística con prioridades fijas

1. Porque un Treap mantiene siempre la propiedad BST sobre las claves.
2. Porque la raíz está determinada por la prioridad, no por el orden de inserción.
3. Debe subir el nuevo nodo insertado.
4. Conserva la propiedad BST.
5. Intenta restaurar la propiedad heap por prioridad.

Tabla resumida:

| Insertado | Prioridad | Raíz | Inorden                        | Niveles                        |
| --------: | --------: | ---: | ------------------------------ | ------------------------------ |
|        50 |        50 |   50 | `[50]`                         | `[50]`                         |
|        30 |        30 |   30 | `[30, 50]`                     | `[30, 50]`                     |
|        70 |        70 |   30 | `[30, 50, 70]`                 | `[30, 50, 70]`                 |
|        20 |        20 |   20 | `[20, 30, 50, 70]`             | `[20, 30, 50, 70]`             |
|        40 |        40 |   20 | `[20, 30, 40, 50, 70]`         | `[20, 30, 40, 50, 70]`         |
|        60 |        60 |   20 | `[20, 30, 40, 50, 60, 70]`     | `[20, 30, 40, 50, 60, 70]`     |
|        80 |        80 |   20 | `[20, 30, 40, 50, 60, 70, 80]` | `[20, 30, 40, 50, 60, 70, 80]` |

Dibujo final aproximado:

```text
│                       ┌── 80|p=80
│                   ┌── 70|p=70
│               ┌── 60|p=60
│           ┌── 50|p=50
│       ┌── 40|p=40
│   ┌── 30|p=30
└── 20|p=20
```

##### Parte B - Instrumentación de `bubbleUp`

1. Porque cada nuevo nodo tiene una prioridad menor que la prioridad de su padre. Eso viola la propiedad heap por prioridad y obliga a `bubbleUp`.
2. Retorna cero cuando el nodo insertado queda como raíz o cuando su padre ya tiene prioridad menor o igual.
3. En una inserción individual puede haber tantas rotaciones como altura tenga el árbol, es decir `O(h)`. En un treap con prioridades aleatorias, la altura esperada es `O(log n)`, pero no está garantizada determinísticamente.
4. Porque solo cambia relaciones locales padre-hijo conservando los rangos de claves. En una rotación izquierda sobre `u`, el hijo derecho `w` sube, `u` pasa a la izquierda de `w`, y el subárbol intermedio conserva claves mayores que `u` y menores que `w`.
5. Porque su balance depende de prioridades aleatorias o asignadas. Si las prioridades se comportan como una permutación aleatoria, la forma esperada es buena. Pero si las prioridades son adversarias, puede degenerar.

Tabla esperada:

| Clave | Prioridad | Rotaciones | Raíz después de insertar | Niveles                 |
| ----: | --------: | ---------: | -----------------------: | ----------------------- |
|   100 |       100 |          0 |                      100 | `[100]`                 |
|    90 |        90 |          1 |                       90 | `[90, 100]`             |
|    80 |        80 |          1 |                       80 | `[80, 90, 100]`         |
|    70 |        70 |          1 |                       70 | `[70, 80, 90, 100]`     |
|    60 |        60 |          1 |                       60 | `[60, 70, 80, 90, 100]` |


##### Parte C - Instrumentación de `trickleDown` y eliminación

1. Porque además de mantener el orden por clave, se debe conservar la propiedad heap por prioridad. Borrar directamente un nodo con dos hijos puede dejar prioridades incorrectas.
2. Porque en esta implementación la prioridad menor debe estar más arriba. Si el nodo a eliminar baja, debe subir el hijo que mejor respeta la propiedad heap.
3. Se aplica rotación derecha. El hijo izquierdo sube y el nodo eliminado baja hacia la derecha.
4. Se aplica rotación izquierda. El hijo derecho sube y el nodo eliminado baja hacia la izquierda.
5. Deben mantenerse el orden BST, la propiedad heap por prioridad, los enlaces `parent` correctos, la raíz correcta y `size()` disminuido exactamente en uno.

| Eliminado | Rotaciones | Inorden después            | Niveles después            | Raíz |
| --------: | ---------: | -------------------------- | -------------------------- | ---: |
|        50 |          1 | `[20, 30, 40, 60, 70, 80]` | `[20, 30, 40, 60, 70, 80]` |   20 |
|        20 |          1 | `[30, 40, 60, 70, 80]`     | `[30, 40, 60, 70, 80]`     |   30 |
|        70 |          1 | `[30, 40, 60, 80]`         | `[30, 40, 60, 80]`         |   30 |

Trazado manual de eliminar `50`:

Antes de eliminar, alrededor del nodo `50` se tiene:

```text
40
  \
   50
     \
      60
        \
         70
           \
            80
```

Como `50` tiene hijo derecho y no tiene hijo izquierdo, `trickleDown(50)` aplica una rotación izquierda sobre `50`. Entonces `60` sube y `50` baja a la izquierda de `60`. Ahora `50` queda sin hijos y puede retirarse con `splice`.

Después:

```text
40
  \
   60
     \
      70
        \
         80
```

##### Parte D - Búsqueda ordenada en Treap

1. Porque buscan sucesores por clave. La prioridad solo decide la forma vertical, no el orden semántico de las claves.
2. `findEQ`, `findLast`, `lowerBound`, `upperBound` y el recorrido inorden.
3. La relación padre-hijo sobre `priority`, validada por `isHeapByPriority`.
4. Porque una cola de prioridad pura, como un heap binario, está optimizada para `getMax` y `delMax`. El Treap guarda orden por clave y prioridad estructural, no está diseñado principalmente para consumir máximos repetidamente.
5. Cuando se necesita búsqueda ordenada, inserción, eliminación, sucesores, predecesores y balance esperado sin implementar invariantes deterministas más complejos como AVL o Red-Black.

La búsqueda ordenada depende de la propiedad BST, no de la prioridad heap. El código de `lowerBound` y `upperBound` recorre izquierda o derecha comparando claves y guardando un candidato, igual que en un BST. 

Con las claves `{20, 30, 40, 50, 60, 70, 80}`:

| Operación        | Resultado esperado | Explicación            |
| ---------------- | -----------------: | ---------------------- |
| `findEQ(40)`     |               `40` | La clave existe        |
| `findEQ(35)`     |             `null` | La clave no existe     |
| `lowerBound(35)` |               `40` | Primera clave `>= 35`  |
| `lowerBound(40)` |               `40` | La clave exacta existe |
| `upperBound(40)` |               `50` | Primera clave `> 40`   |
| `upperBound(75)` |               `80` | Primera clave `> 75`   |

Comparación Treap vs `BinarySearchTree`:

| Operación       | Treap                                  | BinarySearchTree                                       |
| --------------- | -------------------------------------- | ------------------------------------------------------ |
| `findEQ`        | Usa claves como BST                    | Usa claves                                             |
| `lowerBound`    | Usa orden BST                          | Usa orden BST                                          |
| `upperBound`    | Usa orden BST                          | Usa orden BST                                          |
| Forma del árbol | Depende de prioridades                 | Depende del orden de inserción o del balance si existe |
| Balance         | Esperado si prioridades son aleatorias | No garantizado en BST simple                           |
| Inorden         | Ordenado                               | Ordenado                                               |

##### Parte E - Pruebas específicas para Treap

1. Atraparía rotaciones que actualizan `left` y `right`, pero olvidan corregir `parent`. Ese bug suele aparecer después de `rotateLeft`, `rotateRight`, `trickleDown` o `splice`.
2. Detectaría incrementos dobles al insertar, decrementos faltantes al eliminar o cambios de tamaño después de rechazar duplicados.
3. Detectaría errores en inserción BST o rotaciones que mueven subárboles al lado incorrecto.
4. Detectaría fallas en `bubbleUp`, errores al elegir el hijo en `trickleDown` o rotaciones incompletas que dejan un hijo con prioridad menor que su padre.
5. Porque hacen que el árbol final sea determinístico. Así se puede afirmar la raíz, el recorrido por niveles, el número de rotaciones y el resultado de eliminaciones sin depender del generador aleatorio.

```text
Test project /home/victor/clases/algoritmos/CC232-pc1/Semana6/build-debug
    Start 1: semana6_public
1/2 Test #1: semana6_public ...................   Passed    0.00 sec
    Start 2: semana6_internal
2/2 Test #2: semana6_internal .................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.01 sec
```

#### Bloque 11 - Comparación con Semana 5: `BinaryHeap`, `BinarySearchTree` y `Treap`

1. Un heap solo mantiene una relación de mayor o menor entre un padre y sus hijos, mientras que un BST tiene una relación diferente para cada hijo de tal forma que en general da un recorrido inorder.
2. Porque un heap mantiene sus elementos inorder, pero un heap no podría ya que aplica la misma relación a cada uno de sus hijos, mientras un BST aplica una relación opuesta a con respecto a la relación padre/hijo del lado derecho contra el lado izquierdo.
3. Agrega las operaciones:
insert(x)
getMax()
delMax()
4. Un Treap combina propiedad BST sobre las claves y propiedad Heap sobre las prioridades.
5. Usaría un max heap y extraería la raíz.
6. Un BST, ya que estas operaciones dependen del orden de las claves.
7. Un treap, ya que balancea sus elementos de forma similar a un BST aleatorio y genera árboles balanceados con una probabilidad a diferencia de un BST que depende del orden de ingreso de los valores.
```text
=== Evidencia observada ===

PQ_ComplHeap::getMax() = 14
BinaryHeap::top() = 1
BST inorder = 1 3 4 6 7 8 10 13 14
Treap inorder = 1 3 4 6 7 8 10 13 14

Treap:
└── 14|p=3806825280191135750
    │           ┌── 13|p=16350857208115036169
    │       ┌── 10|p=7841030099754090499
    │       │   └── 8|p=11465005912272011265
    │   ┌── 7|p=6540889082592755720
    └── 6|p=4427274669953122309
        │   ┌── 4|p=8091819015644119047
        └── 3|p=7514292258938093570
            └── 1|p=15317392959115231236


=== Tabla comparativa ===

Estructura          Operacion principal   Propiedad                Operacion eficiente      No conviene                   Evidencia
------------------------------------------------------------------------------------------------------------------------------------------------------
BinaryHeap          top()                 Min-Heap                 obtener minimo           busqueda arbitraria           top() = 1
PQ_ComplHeap        getMax()              Max-Heap                 obtener maximo           recorrido ordenado            getMax() = 14
BinarySearchTree    find(x)               BST                      buscar claves            extraer maximos repetidos     inorder ordenado
Treap               find(x)               BST + Heap por prioridad buscar e insertar balanceadorecorrido por prioridad       inorder ordenado y prioridades visibles
```

#### Bloque 12 - Pruebas obligatorias después de modificar código

- Lista de pruebas agregadas.

```cpp
static void testBloque12() {
  ods::PQ_ComplHeap<int> pq;

  {
    for (int x : {7, 3, 10, 1, 5, 8, 2}) {
      pq.insert(x);
      assert(pq.isHeap());
    }
  }
  //Inserción que no reordena correctamente el árbol
  {
    while (!pq.empty()) {
      pq.delMax();
      assert(pq.isHeap());
    }
  }
  //Rotaciones mal aplicadas
  {
    pq.clear();
    for (int x : {1, 2, 3, 4, 5}) {
      pq.insert(x);
    }
    const auto sz = pq.size();
    const int mx = pq.getMax();

    assert(mx == 5);
    assert(pq.size() == sz);
  }
  //Lectura que elimina elementos del heap 
  {

    pq.clear();
    for (int x : {1, 2, 3, 4, 5}) {
      pq.insert(x);
    }

    const auto sz = pq.size();
    pq.delMax();
    assert(pq.size() == sz - 1);
  }
  //Inconsistencia en mantenimiento de tamaño
  {
    pq.clear();
    std::vector<int> data{7, 3, 10, 1, 5, 8, 2};

    ods::PQ_ComplHeap<int> pq(data);

    assert(pq.isHeap());
  }
  //Heap inicial inválido
  {
    std::vector<int> data{7, 3, 10, 1, 5, 8, 2};

    ods::heapSort(data);

    assert((data == std::vector<int>{1, 2, 3, 5, 7, 8, 10}));
  }
  //Algoritmo de ordenamiento incorrecto
  {
    ods::PQ_LeftHeap<int> h1;
    ods::PQ_LeftHeap<int> h2;

    for (int x : {10, 7, 3})
      h1.insert(x);
    for (int x : {9, 8, 1})
      h2.insert(x);

    h1.merge(h2);

    assert(h1.isLeftistHeap());
  }
  //Merge incorrecto en leftist heap
  {
    ods::PQ_LeftHeap<int> h;

    for (int x : {7, 3, 10, 1, 5, 8}) {
      h.insert(x);
      assert(h.isLeftistHeap());
    }
  }
  //Inserción que altera la propiedad leftist
  {
    ods::PQ_LeftHeap<int> h;

    for (int x : {7, 3, 10, 1, 5, 8}) {
      h.insert(x);
    }

    while (!h.empty()) {
      h.delMax();
      assert(h.isLeftistHeap());
    }
  }
  //Leftist heap corrupto tras extracciones
  {
    const std::vector<ods::HuffmanSymbol> alphabet{
        {'M', 1}, {'I', 4}, {'S', 4}, {'P', 2}};

    const auto codes = ods::huffmanGenerateCodes(alphabet);

    for (char c : {'M', 'I', 'S', 'P'}) {
      assert(codes.find(c) != codes.end());
      assert(!codes.at(c).empty());
    }
  }
  //Códigos incompletos
  {
    const std::vector<ods::HuffmanSymbol> alphabet{
        {'M', 1}, {'I', 4}, {'S', 4}, {'P', 2}};

    const auto codes = ods::huffmanGenerateCodes(alphabet);
    const auto tree = ods::huffmanGenerateTree(alphabet);

    const std::string text = "MISSISSIPPI";

    const std::string encoded = ods::huffmanEncode(text, codes);
    const std::string decoded = ods::huffmanDecode(encoded, tree);

    assert(decoded == text);
  }
  //Inconsistencia para codificar-decodificar
  {
    const std::vector<ods::HuffmanSymbol> alphabet{{'A', 100}};

    const auto codes = ods::huffmanGenerateCodes(alphabet);

    assert(codes.size() == 1);
    assert(codes.find('A') != codes.end());
    assert(!codes.at('A').empty()); // o que sea "0" o "1"
  }
  //Caso borde no implementado
  {
    ods::Treap<int> t;

    for (int x : {7, 3, 10, 1, 5, 8, 12}) {
      t.add(x);
    }

    assert(t.isBST());
  }
  //Violación de propiedad BST
  {
    ods::Treap<int> t;

    for (int x : {7, 3, 10, 1, 5, 8, 12}) {
      t.add(x);
    }
    assert(t.isHeapByPriority());
  }
  //Violación de propiedad Heap
  {
    ods::Treap<int> t;

    for (int x : {7, 3, 10, 1, 5, 8, 12}) {
      t.add(x);
    }
    t.remove(5);
    t.remove(10);
    assert(t.isBST());
    assert(t.isHeapByPriority());
    assert(t.isTreap());
  }
  //Violación de propiedad Heap y Treap simultáneamente
}
```

- Resultado completo de `ctest --output-on-failure`.

```text
Test project /home/victor/clases/algoritmos/CC232-pc1/Semana6/build
    Start 1: semana6_public
1/2 Test #1: semana6_public ...................   Passed    0.00 sec
    Start 2: semana6_internal
2/2 Test #2: semana6_internal .................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.01 sec
```


#### Bloque 13 - Defensa escrita de modificaciones

Responde en no más de 900 palabras:

¿Qué aprendiste al modificar código de prioridad, heaps, Huffman y Treap que no se aprende solo leyendo o ejecutando demostraciones?

Tu respuesta debe incluir obligatoriamente:

- Una afirmación sobre la interfaz `PQ`.
- Una afirmación sobre la representación implícita del heap binario completo.
- Una afirmación sobre `percolateUp`.
- Una afirmación sobre `percolateDown`.
- Una afirmación sobre `heapify` de Floyd.
- Una afirmación sobre `heapSort`.
- Una afirmación sobre `merge` en heap izquierdista.
- Una afirmación sobre Huffman.
- Una afirmación sobre `Treap`, rotaciones, prioridades y búsqueda ordenada.
- Una afirmación sobre comparación con `BinaryHeap` y `BinarySearchTree`.
- Una afirmación sobre pruebas, invariantes y casos borde.


#### Formato sugerido de entrega

```markdown
## Actividad 6 - CC232

### Estudiante
- Nombre:
- Código:
- Fecha:

### Resumen de modificaciones
| Bloque | Archivo modificado | Cambio realizado | Evidencia |
|---|---|---|---|

### Bloque 1 - Diagnóstico inicial
[Comandos, resultados y explicación]

### Bloque 2 - Utilidades de heap completo
[Código, explicación y evidencia]

### Bloque 3 - Conteo en percolateUp
[Código, salida y análisis]

### Bloque 4 - Conteo en percolateDown
[Código, salida y análisis]

### Bloque 5 - Validación de propiedad heap
[Código, pruebas y explicación]

### Bloque 6 - Inserciones sucesivas vs Floyd
[Demostración, tabla y complejidad]

### Bloque 7 - heapSort
[Código, pruebas y discusión de estabilidad]

### Bloque 8 - Heap izquierdista
[Código, validación y trazado]

### Bloque 9 - Huffman
[Código, tabla de códigos y prefijo libre]

### Bloque 10 - Treap
[Rotaciones, inserción, eliminación, búsquedas y pruebas]

### Bloque 11 - Comparación con Semana 5
[Tabla y selección de estructura]

### Bloque 12 - Pruebas
[Lista de pruebas, salida de ctest y explicación]

### Bloque 13 - Defensa escrita
[Respuesta final]
```

#### Criterio general de evaluación

Se espera evidencia de trabajo directo sobre el código. La actividad será evaluada principalmente por:

1. Claridad de las modificaciones.
2. Conservación de la interfaz pública cuando corresponda.
3. Uso correcto de invariantes.
4. Pruebas con casos borde.
5. Comparación razonada entre estructuras.
6. Explicación de costos.
7. Capacidad de sustentar oralmente los cambios.
8. Calidad de los ejercicios adicionales de codificación: modularidad, pruebas, casos borde y respeto de invariantes.

Pasar las pruebas no es suficiente. Debes poder explicar por qué tus cambios preservan la propiedad de heap, la propiedad izquierdista, la validez del árbol de Huffman, la propiedad BST del `Treap` y la diferencia entre estructuras para prioridad y estructuras para búsqueda ordenada.
