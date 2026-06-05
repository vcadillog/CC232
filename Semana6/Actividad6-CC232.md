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

Revisa:

- `Semana6/include/PQ_ComplHeap_macro.h`
- `Semana6/include/PQ_ComplHeap_percolateUp.h`
- `Semana6/include/PQ_ComplHeap_percolateDown.h`

Modifica `PQ_ComplHeap_macro.h` para agregar funciones auxiliares `constexpr` adicionales, sin usar macros:

```cpp
pqHasLeftChild(i, n)
pqHasRightChild(i, n)
pqIsLeaf(i, n)
pqIsInternal(i, n)
```

Luego modifica `PQ_ComplHeap_percolateDown.h` para usar esas funciones auxiliares donde corresponda.

Responde:

1. ¿Por qué conviene expresar `parent`, `left`, `right` y pruebas de frontera como funciones pequeñas?
1. Porque el usar funciones pequeñas mejora la legibilidad del código.
2. ¿Qué ventaja tiene `constexpr` frente a macros?

2. Porque constexpr permite el uso de tipos, tiene un ambito de ejecucion controlado y permite depuración.

3. ¿Qué caso borde aparece cuando el nodo tiene solo hijo izquierdo?
3. Cuando un nodo tiene un solo hijo izquierdo y no un hijo derecho, el acceso al hijo derecho tiene un índice fuera del rango del arreglo.

4. ¿Qué condición identifica una hoja en la representación implícita?
4. La condició que identifica una hoja es que no tenga hijos, es decir, que el índice de su hijo izquierdo sea mayor o igual al tamaño del arreglo.

5. ¿Qué cambió en `percolateDown` después de usar las funciones auxiliares?

Entrega en este bloque:

- Fragmento del código modificado.
- Explicación de por qué no cambia la complejidad.
- Evidencia de compilación.

#### Bloque 3 - Modificación de `percolateUp`: conteo de intercambios

Revisa:

- `Semana6/include/PQ_ComplHeap_percolateUp.h`
- `Semana6/include/PQ_ComplHeap_insert.h`
- `Semana6/demos/demo_pq_complheap_basico.cpp`

Agrega una función nueva, sin romper la función existente:

```cpp
template<class T, class Compare>
std::size_t complHeapPercolateUpCount(std::vector<T>& a, std::size_t i, Compare comp);
```

La función debe hacer lo mismo que `complHeapPercolateUp`, pero además debe retornar cuántos intercambios realizó.

Luego modifica o crea una demostración para insertar la secuencia:

```cpp
{ 40, 10, 70, 30, 90, 20, 80, 60 }
```

y mostrar por cada inserción:

- elemento insertado,
- cantidad de intercambios,
- arreglo interno resultante,
- si la propiedad heap se mantiene.

Responde:

1. ¿En qué casos `percolateUp` hace cero intercambios?
2. ¿En qué casos puede hacer `O(log n)` intercambios?
3. ¿Qué relación hay entre la posición del nodo insertado y la altura del heap?
4. ¿Por qué el arreglo interno no necesariamente queda ordenado?
5. ¿Qué propiedad sí queda garantizada?.

Entrega en este bloque:

- Código de la función nueva.
- Salida de la demostración.
- Argumento de costo.

#### Bloque 4 - Modificación de `percolateDown`: elección del hijo dominante

Revisa:

- `Semana6/include/PQ_ComplHeap_percolateDown.h`
- `Semana6/include/PQ_ComplHeap_delMax.h`
- `Semana6/demos/demo_pq_complheap_basico.cpp`

Agrega una función auxiliar o versión instrumentada que permita observar qué hijo se elige durante la bajada:

```cpp
template<class T, class Compare>
std::size_t complHeapPercolateDownCount(std::vector<T>& a, std::size_t n, std::size_t i, Compare comp);
```

La función debe retornar la cantidad de intercambios realizados.

Crea una demostración pequeña donde elimines repetidamente el máximo de un heap y registres:

- máximo eliminado,
- arreglo antes de reparar,
- número de intercambios,
- arreglo después de reparar.

Responde:

1. ¿Por qué después de `delMax` se mueve el último elemento a la raíz?
1. Porque el último elemento se mueve a la raíz para llenar el espacio dejado por el máximo eliminado, y luego se baja para restaurar la propiedad de heap.
2. ¿Por qué la reparación baja y no sube?
2. Porque el elemento que se mueve a la raíz puede ser menor que sus hijos, por lo que necesita bajar para restaurar la propiedad de heap.
3. ¿Cómo se decide entre hijo izquierdo e hijo derecho?
3. Empieza eligiendo al hijo izquierdo y luego se compara el valor del hijo izquierdo con el del hijo derecho utilizando comp. Si el hijo derecho existe y es mayor que el hijo izquierdo, entonces se selecciona el hijo derecho como el candidato. Luego se continúa con el intercambio.
4. ¿Qué pasa si el nodo actual tiene un solo hijo?
4. Al ser un heap, tiene que tener un hijo izquierdo y no se compara con el derecho si no existe, luego se intercambia solo con el hijo izquierdo.
5. ¿Por qué `delMax` tiene costo `O(log n)`?.
5. Porque en el peor caso, el elemento que se mueve a la raíz puede bajar hasta la hoja más profunda del heap, en un árbol binario la altura es logn. 

Entrega en este bloque:

- Código modificado.
- Salida de la demostración.
- Trazado manual de una eliminación.

Contando el número de intercambios
Número de intercambios:2
delMax() -> 14
heap interno: [12, 5, 10, 4, 3, 7, 9, 1]
Número de intercambios:2
delMax() -> 12
heap interno: [10, 5, 9, 4, 3, 7, 1]
Número de intercambios:2
delMax() -> 10
heap interno: [9, 5, 7, 4, 3, 1]
Número de intercambios:1
delMax() -> 9
heap interno: [7, 5, 1, 4, 3]
Número de intercambios:2
delMax() -> 7
heap interno: [5, 4, 1, 3]
Número de intercambios:1
delMax() -> 5
heap interno: [4, 3, 1]
Número de intercambios:1
delMax() -> 4
heap interno: [3, 1]
Número de intercambios:0
delMax() -> 3
heap interno: [1]
Número de intercambios:0
delMax() -> 1
heap interno: []

Explica por qué es ese número de intercambios cada vez y por qué el arreglo interno no queda ordenado.
Después de cada `delMax()`, el último elemento del heap se mueve a la raíz y luego se baja para restaurar la propiedad de heap. El número de intercambios depende de la posición del último elemento y de cómo se comparan los hijos durante la bajada.
El arreglo interno no queda ordenado porque el heap solo garantiza que cada padre tenga prioridad mayor o igual que sus hijos, no que los elementos estén en orden secuencial. El orden solo se garantiza para el máximo, que siempre está en la raíz, pero los demás elementos pueden estar en cualquier orden relativo mientras se mantenga la propiedad de heap.


#### Bloque 5 - Validación explícita de la propiedad heap

Revisa:

- `Semana6/include/PQ_ComplHeap.h`
- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`

Agrega una función de validación, ya sea como método de `PQ_ComplHeap` o como función auxiliar:

```cpp
bool isValidHeap() const;
```

o, si se implementa como función libre:

```cpp
template<class T, class Compare>
bool complHeapIsValid(const std::vector<T>& a, Compare comp);
```

Debe verificar que cada padre tenga prioridad mayor o igual que sus hijos según la convención del comparador usado en la implementación.

Agrega pruebas para:

1. heap vacío,
2. heap con un elemento,
3. heap con elementos repetidos,
4. heap construido por inserciones,
5. heap construido por `heapify`,
6. heap después de varias llamadas a `delMax`.

Responde:

1. ¿Qué invariante verifica la función?
2. ¿Por qué basta revisar relaciones padre-hijo?
3. ¿Por qué no es necesario comparar cada nodo con todos sus descendientes?
4. ¿Cuál es el costo de validar todo el heap?
5. ¿Por qué esta función es útil en pruebas pero no necesariamente en producción?

Entrega en este bloque:

- Código de validación.
- Pruebas agregadas.
- Evidencia de `ctest`.

#### Bloque 6 - Construcción de heap: inserciones sucesivas vs Floyd

Revisa:

- `Semana6/include/PQ_ComplHeap_heapifyFloyd.h`
- `Semana6/include/PQ_ComplHeap_insert.h`
- `Semana6/demos/demo_heapify_floyd.cpp`

Modifica la demostración de `heapify` para comparar dos formas de construir un heap con la misma entrada:

```cpp
{ 4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89 }
```

Construcción A:

- insertar elementos uno por uno usando `insert`.

Construcción B:

- copiar el vector y aplicar `heapify` de Floyd.

La demostración debe mostrar:

- arreglo inicial,
- arreglo final por inserciones,
- arreglo final por Floyd,
- cantidad aproximada o exacta de intercambios si agregaste contadores,
- validación con `isValidHeap`.

Responde:

1. ¿Por qué ambos resultados pueden ser heaps válidos aunque sus arreglos finales no sean idénticos?
2. ¿Por qué insertar `n` elementos puede costar `O(n log n)`?
3. ¿Por qué Floyd puede construir el heap en `O(n)`?
4. ¿Qué nodos procesa Floyd primero?
5. ¿Por qué Floyd no necesita llamar a `percolateDown` desde las hojas?.

Entrega en este bloque:

- Demostración modificada.
- Tabla comparativa.
- Explicación de complejidad.

#### Bloque 7 - Modificación de `heapSort`

Revisa:

- `Semana6/include/vector_heapSort.h`
- `Semana6/demos/demo_heapsort.cpp`

Agrega una versión de `heapSort` que permita elegir el sentido del resultado:

```cpp
template<class T, class Compare>
void heapSort(std::vector<T>& a, Compare comp, bool ascending);
```

La función debe mantener la idea de heapsort in situ. No uses `std::sort`.

Prueba con:

```cpp
{ 5, 1, 5, 3, 8, 2, 8, 0 }
```

y muestra:

- resultado ascendente,
- resultado descendente,
- comportamiento con repetidos.

Responde:

1. ¿Por qué heapsort puede ordenar in situ?
2. ¿Qué parte del algoritmo destruye gradualmente el heap?
3. ¿Por qué heapsort cuesta `O(n log n)`?
4. ¿Es heapsort estable? Justifica con un ejemplo.
5. ¿Qué diferencia hay entre usar `heapSort` y extraer todos los elementos con `delMax`?

Entrega en este bloque:

- Código modificado.
- Demostración actualizada.
- Evidencia de repetidos.

#### Bloque 8 - Heap izquierdista: validación de `merge`

Revisa:

- `Semana6/include/PQ_LeftHeap.h`
- `Semana6/include/PQ_LeftHeap_merge.h`
- `Semana6/include/PQ_LeftHeap_insert.h`
- `Semana6/include/PQ_LeftHeap_delMax.h`
- `Semana6/demos/demo_left_heap_merge.cpp`

Agrega una función de validación para el heap izquierdista:

```cpp
bool isValidLeftHeap() const;
```

Debe verificar al menos:

1. propiedad de heap,
2. propiedad izquierdista,
3. consistencia de tamaño,
4. consistencia de `npl` o distancia nula, si el código la almacena.

Luego modifica la demostración de `merge` para construir dos heaps, mezclarlos y validar el resultado.

Responde:

1. ¿Por qué `merge` es la operación central del heap izquierdista?
2. ¿Cómo se implementa `insert` usando `merge`?
3. ¿Cómo se implementa `delMax` usando `merge`?
4. ¿Qué propiedad adicional diferencia un heap izquierdista de un heap binario completo?
5. ¿Qué ventaja conceptual tiene un heap izquierdista frente a un heap binario completo?.

Entrega en este bloque:

- Código de validación.
- Demostración modificada.
- Trazado de una fusión pequeña.

#### Bloque 9 - Huffman: modificación de desempate y caso de un símbolo

Revisa:

- `Semana6/include/Huffman_PQ.h`
- `Semana6/include/Huffman_PQ_generateTree.h`
- `Semana6/demos/demo_huffman.cpp`

Modifica el código de Huffman para documentar y probar explícitamente el desempate entre símbolos de igual frecuencia.

Usa este alfabeto:

```cpp
{ {'A', 5}, {'B', 5}, {'C', 10}, {'D', 10}, {'E', 20} }
```

Además, agrega una prueba para el caso extremo de un solo símbolo:

```cpp
{ {'X', 100} }
```

La implementación debe producir un código válido para el único símbolo, por ejemplo `"0"`.

Responde:

1. ¿Por qué Huffman necesita una cola de prioridad?
2. ¿Qué elementos se extraen repetidamente?
3. ¿Qué nodo se vuelve a insertar?
4. ¿Por qué el caso de un solo símbolo requiere cuidado especial?
5. ¿Qué significa que el conjunto de códigos sea libre de prefijos?
6. ¿Cómo afecta el desempate a la forma del árbol?
7. ¿El desempate cambia necesariamente la longitud total ponderada? Justifica.

Entrega en este bloque:

- Código modificado o prueba agregada.
- Tabla símbolo, frecuencia, código, longitud.
- Verificación de prefijo libre.

#### Bloque 10 - Treap: modificación de código, rotaciones e invariantes

Revisa:

- `Semana6/include/Treap.h`
- `Semana6/demos/demo_treap_basico.cpp`
- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`

Este bloque es obligatorio. Su objetivo es que no uses `Treap` solo como estructura decorativa, sino que entiendas cómo combina dos invariantes simultáneos:

1. propiedad de árbol binario de búsqueda sobre `key`,
2. propiedad de heap sobre `priority`.

En la implementación de Semana 6, una prioridad menor sube más cerca de la raíz. Por eso `bubbleUp` rota mientras el padre tiene prioridad mayor que el nodo insertado.

##### Parte A - Construcción determinística con prioridades fijas

Crea o modifica `demo_treap_basico.cpp` para construir el treap usando `addWithPriority`, no solo `add`, con esta secuencia:

```cpp
{ {50, 50}, {30, 30}, {70, 70}, {20, 20}, {40, 40}, {60, 60}, {80, 80} }
```

Cada par representa:

```cpp
{ clave, prioridad }
```

Después de cada inserción, imprime:

- clave insertada,
- prioridad asignada,
- recorrido inorden,
- recorrido por niveles,
- raíz actual,
- resultado de `isBST()`,
- resultado de `isHeapByPriority()`,
- resultado de `isTreap()`.

Responde:

1. ¿Por qué el recorrido inorden debe salir ordenado aunque las prioridades cambien la forma del árbol?
2. ¿Por qué la raíz no necesariamente es la primera clave insertada?
3. ¿Qué nodo debe subir cuando se inserta una clave con prioridad menor que la de sus ancestros?
4. ¿Qué propiedad conserva una rotación local sobre las claves?
5. ¿Qué propiedad intenta restaurar `bubbleUp` sobre las prioridades?.

Entrega en esta parte:

- demostración modificada,
- salida de al menos cinco inserciones,
- dibujo o `asciiArt()` del árbol final.

##### Parte B - Instrumentación de `bubbleUp`

Agrega una versión instrumentada sin eliminar la función existente:

```cpp
template<class T, class Compare>
std::size_t bubbleUpCount(typename Treap<T, Compare>::Node* u);
```

Si prefieres mantenerla como método interno de la clase, puedes llamarla:

```cpp
std::size_t bubbleUpCount(Node* u);
```

La función debe realizar el mismo proceso que `bubbleUp`, pero retornando cuántas rotaciones se hicieron.

Luego agrega una forma controlada de usarla desde una inserción, por ejemplo:

```cpp
std::size_t addWithPriorityCount(const T& x, std::uint64_t priority);
```

No cambies el comportamiento público de `add` ni de `addWithPriority`.

Prueba con una secuencia que fuerce varias rotaciones:

```cpp
{ {100, 100}, {90, 90}, {80, 80}, {70, 70}, {60, 60} }
```

Responde:

1. ¿Por qué esta secuencia tiende a producir rotaciones repetidas?
2. ¿Cuándo `bubbleUpCount` retorna cero?
3. ¿Cuál es el peor caso de rotaciones durante una inserción?
4. ¿Por qué una rotación no rompe la propiedad BST?
5. ¿Por qué el treap busca mantener altura esperada logarítmica, no altura garantizada logarítmica?

Entrega en esta parte:

- código de la función instrumentada,
- tabla con clave, prioridad, rotaciones y raíz después de insertar,
- explicación de costo esperado.

##### Parte C - Instrumentación de `trickleDown` y eliminación

Agrega una versión instrumentada sin eliminar la función existente:

```cpp
std::size_t trickleDownCount(Node* u);
```

y una eliminación controlada:

```cpp
std::size_t removeCount(const T& x);
```

La eliminación debe rotar el nodo hacia abajo hasta que tenga a lo más un hijo, luego aplicar la lógica equivalente a `splice`.

Usa el treap construido en la Parte A y elimina:

```cpp
50, 20, 70
```

Después de cada eliminación, imprime:

- clave eliminada,
- cantidad de rotaciones,
- recorrido inorden,
- recorrido por niveles,
- `isBST()`,
- `isHeapByPriority()`,
- `isTreap()`.

Responde:

1. ¿Por qué eliminar en un treap no es simplemente borrar como en un BST común?
2. ¿Por qué `trickleDown` elige rotar con el hijo de menor prioridad?
3. ¿Qué ocurre si el nodo tiene solo hijo izquierdo?
4. ¿Qué ocurre si el nodo tiene solo hijo derecho?
5. ¿Qué invariantes deben seguir siendo verdaderos después de `splice`?

Entrega en esta parte:

- código modificado,
- salida de la demostración,
- trazado manual de una eliminación donde haya al menos una rotación.

##### Parte D - Búsqueda ordenada en Treap

Extiende la demostración para probar:

```cpp
findEQ(40)
findEQ(35)
lowerBound(35)
lowerBound(40)
upperBound(40)
upperBound(75)
```

Compara los resultados con lo que produciría `BinarySearchTree` usando las mismas claves.

Responde:

1. ¿Por qué `lowerBound` y `upperBound` dependen de la propiedad BST y no de la propiedad heap?
2. ¿Qué parte del treap se comporta igual que un BST?
3. ¿Qué parte del treap se comporta como heap?
4. ¿Por qué el treap no reemplaza directamente a una cola de prioridad si lo único que quieres es extraer máximos o mínimos repetidamente?
5. ¿En qué situación sí conviene usar una estructura tipo treap?.

Entrega en esta parte:

- tabla comparativa Treap vs `BinarySearchTree`,
- respuestas de búsqueda,
- explicación de qué propiedad se usó en cada operación.

##### Parte E - Pruebas específicas para Treap

Agrega o extiende pruebas para cubrir:

1. treap vacío: `empty()`, `size()`, `isBST()`, `isHeapByPriority()`, `isTreap()`,
2. inserción con prioridades fijas,
3. rechazo de duplicados,
4. inorden ordenado después de insertar,
5. propiedad heap por prioridad después de insertar,
6. `lowerBound` y `upperBound`,
7. eliminación de hoja,
8. eliminación de nodo con un hijo,
9. eliminación de nodo con dos hijos,
10. eliminación de raíz,
11. conservación de enlaces `parent`, si agregas una función pública de validación,
12. consistencia de `size()` después de operaciones mixtas,
13. estabilidad de invariantes después de una secuencia larga de inserciones y eliminaciones.

Responde:

1. ¿Qué bug atraparía una prueba de enlaces `parent`?
2. ¿Qué bug atraparía una prueba de `size()`?
3. ¿Qué bug atraparía una prueba de inorden ordenado?
4. ¿Qué bug atraparía una prueba de prioridad padre-hijo?
5. ¿Por qué conviene usar prioridades fijas en pruebas unitarias?

Entrega en esta parte:

- pruebas agregadas,
- resultado de `ctest --test-dir build-debug -R semana6 --output-on-failure`,
- breve explicación de qué cubre cada prueba.

#### Bloque 11 - Comparación con Semana 5: `BinaryHeap`, `BinarySearchTree` y `Treap`

Revisa:

- `Semana5/include/BinaryHeap.h`
- `Semana5/include/BinarySearchTree.h`
- `Semana6/include/PQ_ComplHeap.h`
- `Semana6/include/Treap.h`
- `Semana6/demos/demo_compare_with_semana5.cpp`
- `Semana6/demos/demo_treap_basico.cpp`

Modifica `demo_compare_with_semana5.cpp` para construir una comparación observable entre:

1. `BinaryHeap` de Semana 5,
2. `PQ_ComplHeap` de Semana 6,
3. `BinarySearchTree` de Semana 5,
4. `Treap` de Semana 6.

La demostración debe mostrar una tabla con columnas:

- estructura,
- operación principal,
- propiedad mantenida,
- operación eficiente,
- operación que no conviene,
- evidencia producida por la demostración.

Responde:

1. ¿Qué diferencia hay entre un heap de prioridad y un árbol de búsqueda?
2. ¿Por qué un BST permite recorrido ordenado y un heap no?
3. ¿Qué agrega `PQ_ComplHeap` frente a un `BinaryHeap` educativo?
4. ¿Qué combina un `Treap`?
5. ¿Qué estructura usarías para extraer máximos repetidamente?
6. ¿Qué estructura usarías para responder `lowerBound` o `upperBound`?
7. ¿Qué estructura usarías si quieres búsqueda ordenada con balanceo probabilístico?.

Entrega en este bloque:

- Demostración modificada.
- Tabla de comparación.
- Respuesta breve de selección de estructura.

#### Bloque 12 - Pruebas obligatorias después de modificar código

Debes agregar o extender pruebas en:

- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`

Incluye al menos las siguientes pruebas:

1. `PQ_ComplHeap` conserva la propiedad heap después de cada inserción.
2. `PQ_ComplHeap` conserva la propiedad heap después de cada eliminación.
3. `getMax` no cambia el tamaño.
4. `delMax` sí cambia el tamaño.
5. `heapifyFloyd` produce un heap válido.
6. `heapSort` ordena con repetidos.
7. `PQ_LeftHeap` conserva su propiedad después de `merge`.
8. `PQ_LeftHeap` conserva su propiedad después de `insert`.
9. `PQ_LeftHeap` conserva su propiedad después de `delMax`.
10. Huffman produce códigos para todos los símbolos con frecuencia positiva.
11. Huffman produce códigos libres de prefijos.
12. Huffman maneja correctamente el caso de un solo símbolo.
13. `Treap` conserva propiedad BST después de insertar.
14. `Treap` conserva propiedad de heap por prioridad después de insertar.
15. `Treap` conserva ambas propiedades después de eliminar.

Entrega en este bloque:

- Lista de pruebas agregadas.
- Resultado completo de `ctest --output-on-failure`.
- Explicación de qué bug atraparía cada prueba.

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
