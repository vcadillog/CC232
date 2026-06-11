## Actividad 5 - CC232

### Estudiante

- Nombre: Victor Hugo Cadillo Gutierrez

### Bloque 1 - Núcleo conceptual

1. Un árbol binario enlazado es una estructura de datos donde cada nodo contiene un dato y punteros a su hijo izquierdo, hijo derecho y padre. En cambio, un árbol binario almacenado implícitamente en un arreglo utiliza un arreglo para representar la estructura del árbol de forma implícita con los índices.

2. En BinNode se guarda la información de punteros al:
 - Nodo padre: permite navegar hacia arriba en el árbol.
 - Hijo izquierdo: permite navegar hacia el árbol izquierdo.
 - Hijo derecho: permite navegar hacia el árbol derecho.
 - la altura del nodo: permite conocer la distancia máxima desde el nodo hasta la hoja más lejana.

3. El puntero parent implementa operaciones succ() para desplazarse hacia abajo y pred() para desplazarse hacia arriba el árbol.

4. BinTree es una implementación de árbol binario, mientras que BinNode representa cada nodo individual dentro del árbol. BinTree usa BinNode para construir la estructura del árbol y gestionar las operaciones sobre él, como inserciones, eliminaciones y recorridos.

5. BinaryTree agrega funcionalidades:
- depth
- height
- subtreeSize
- firsNode, lastNode, nextNode, prevNode, begin, end: para navegación.

6. Un árbol binario se convierte en un BinarySearchTree (BST) si cumple con la propiedad de orden: Compare = std::less<T>> el valor de los nodos en el subárbol izquierdo son menores que el valor del nodo padre, y los valores de los nodos en el subárbol derecho son mayores que el valor del nodo padre.

7. Un arreglo se convierte en un BinaryHeap mínimo si cumple con la propiedad de prioridad: Compare = std::less<T>> el valor de cada nodo es menor o igual que el valor de sus hijos, lo que garantiza que el elemento mínimo esté siempre en la raíz del heap.

8. La propiedad de orden de un BST compara el hijo izquierdo que sea menor y el hijo derecho sea mayor que el padre. Mientras que la propiedad de prioridad de un heap es estricta entre el padre e hijos, es mayor o menor que ambos hijos.

9. Un recorrido inorden de un BST produce una secuencia ordenada porque visita primero el hijo izquierdo porque contiene el valor menor, luego el padre, y luego el hijo derecho que tiene los mayores.

10. Un heap no permite recorrer los elementos en orden porque los hijos con respecto a un padre no están ordenados, solo cumplen la propiedad del mínimo (o máximo, según el tipo de heap). No hay un orden específico entre los hijos, por lo que no se puede garantizar que al recorrer el heap se obtenga una secuencia ordenada sin destruir la estructura o copiar los elementos a otra estructura que permita el ordenamiento.

### Bloque 2 - Navegación, altura, profundidad y tamaño

1.
- hasLeft: busca si el hijo izquierdo existe si el puntero no es nulo.
- hasRight: busca si el hijo derecho existe si el puntero no es nulo.
- isRoot: busca si el nodo es la raíz del árbol, si su puntero parent es nulo.
- isLeaf: busca si el nodo es una hoja, no tiene hijos izquierdo ni derecho, sus punteros apuntan al nulo.
- isLeftChild: busca si es un hijo izquierdo, si el puntero no es nulo y el puntero del padre apunta a este nodo como hijo izquierdo.
- isRightChild: busca si es un hijo derecho, si el puntero no es nulo y el puntero del padre apunta a este nodo como hijo derecho.

2. Explica el caso en que `succ()` baja al subárbol derecho y luego busca el nodo más a la izquierda.

2. El método succ() se utiliza para encontrar el sucesor de un nodo en un árbol binario. El sucesor de un nodo es el nodo que sigue inmediatamente después de él en un recorrido. 

3. El método succ() sube al ancestro del nodo actual mientras el nodo actual sea un hijo derecho de su padre. 

4. Explica simétricamente cómo debe funcionar `pred()`.

4. El método pred() se utiliza para encontrar el predecesor de un nodo en un árbol si tiene un hijo izquierdo y si no tiene busca por la derecha. 

5. Dibuja un árbol de al menos 7 nodos y marca el sucesor y predecesor inorden de tres nodos distintos.

                     H o
                   /       \
               F  o     G   o
                /   \     /   \
                o   o     o   o
                A   B     C   D

- El sucesor de F es A, el predecesor de F es H.
- El sucesor de G es H, el predecesor de G es C.
- El sucesor de B es F, el predecesor de B es F.

6. Explica qué calcula `depth(u)` y por qué puede implementarse subiendo por `parent`.
7. Explica qué calcula `height(u)` y por qué suele implementarse bajando recursivamente por los hijos.
8. Explica qué calcula `subtreeSize(u)`.
9. Demuestra que para todo nodo `u` se cumple `depth(u) + height(u) <= height(T)`.
10. Indica la condición necesaria y suficiente para que se alcance la igualdad anterior.

### Bloque 3 - Recorridos y trazado guiado

1. En preorden primero visita el nodo padre, luego el hijo izquierdo y finalmente el hijo derecho.
2. Inorder visita primero el hijo izquierdo, luego el nodo y finalmente el hijo derecho.
3. En postorden visita primero el hijo izquierdo, luego el hijo derecho y finalmente el nodo.
4. Cuando se visita por niveles empieza desde la raíz y luego visita los nodos de cada nivel de izquierda a derecha antes de pasar al siguiente nivel.
5. Los recorridos recursivos tienen tiempo O(n) porque cada nodo del árbol se visita exactamente una vez. 
6. Porque también visitan cada nodo exactamente una vez, pero utilizan estructuras auxiliares como pilas o colas para gestionar el recorrido.
7. En un árbol balanceado, la memoria auxiliar de un recorrido recursivo es O(log n) porque cada nodo se divide hasta en dos subárboles, lo que genera una profundidad logarítmica.
8. En un árbol degenerado, la memoria auxiliar de un recorrido recursivo es O(n) porque cada nodo tiene solo un hijo.
9. Usar una pila explícita permite controlar manualmente el orden de los nodos a visitar y evita desbordamiento de pila en árboles muy profundos, ya que una pila de llamadas tiene un tamaño limitado por el compilador.
10. En un árbol completo, cada nivel tiene el doble de nodos que el nivel anterior, lo que hace que la cola pueda crecer exponencialmente a medida que se avanza por los niveles. En cambio, en un árbol degenerado, cada nivel tiene solo un nodo.

### Bloque 4 - Demos

| Archivo | Salida u observable importante | Idea estructural | Argumento de costo, espacio o diseño |
|:---|:---:|:---:|---:|
| sem5_demo_binary_tree | Recorridos preorden, inorden, postorden, por niveles  | Árbol binario general con punteros left, right y parent; recorridos con pila explícita o cola | Costo O(n) tiempo por recorrido; espacio O(h) en recorridos con pila (h = altura) o O(n) en recorrido por niveles|
| sem5_demo_bst | findEQ, lowerBound, upperBound, remove, rotateLeft, construcción balanceada | Árbol BST | Búsqueda O(h) en tiempo; rotación O(1); balanceo cuesta O(n) |
| sem5_demo_heap | Heapify, add, remove, extracción ordenada produce secuencia ascendente | Min Heap parent = (i-1)/2, left = 2*i+1, right = 2*i+2 | Heapify O(n); add y remove O(log n); espacio O(n)|
| sem5_demo_capitulo5_panorama | Salida integrada: Min heap , BST, recorrido STL | Integración de todas las estructuras: heap, BST , recorridos |  Recorrido sobre BST es inorden y cuesta O(n)|

1. Se realizan diferentes tipos de recorridos usando métodos iterativos y recursivos, la coincidencia entr estrategias podría dar un orden esperado, pero requiere de pruebas adicionales.
2. El recorrido inorder da el camino para todo el árbol y luego para el elemento 5 se revisa la coincidencia del sucesor y predecesor respeta el orden inorder.
3. La construcción del árbol permite una visualización gráfica a través de una sobrecarga del operador <<.
4. En el demo bst.inorder nos permite observar el BST inorder.
```cpp
BST inorden: 1 3 4 5 6 7 8 10 12
```
Se puede corroborar que la salida inorder es correcta. 
5. findEQ se distingue mejor al ser una condición exacta de búsqueda, los otros dan el mismo valor al trabajar con desigualdades.
6. En el demo se puede observar que el mínimo queda en la raíz, cuando está como primer elemento en el arreglo y eso se visualiza después de hacer add y remove, el observable es heap.data.
7. BinaryHeap de la librería ods nos permite distinguir la diferencia entre crear un heap desde un vector e insertar nuevos nodos.
8. Un árbol organiza nodos, un heap los ordena por mínimos o máximos y un BST los organiza para que según su posición relativa al nodo padre cumplan una relación de desigualdad.

### Bloque 5 - Pruebas e invariantes

1. Para BST se valida las operaciones add, inorder, findEQ, find, lowerBound, upperBound, minNode, isBST, contains, checkParentLinks.
2. add valida que no se ingresen duplicados.
3. Se verifica que independientemente del método utilizado el orden sea el mismo.
4. Espera que exista el elemento con clave 8 y que el dato del nodo sea 8.
5. De lowerBound se espera el elemento mayor o igual a x (9); para el caso debe ser 10 y upperBound el menor elemento estrictamente mayor a x (8); también 10 para el caso.
6. Se valida que la estructura cumpla con las condiciones de un árbol BST.
7. Se valida que el elemento ya no está en el árbol, que los enlaces a los parents sigan siendo válidas y que el bst debe seguir cumpliendo el recorrido inorder.
8. Que los punteros de los hijos sigan apuntando al padre.
9. valida isHeap, remove.
10. Demuestra que las extracciones deben salir ordenadamente de menor a mayor.
11.
- Para attachAsRC se valida que se inserta un nodo, que el tamaño del árbol crece en uno y que el nodo insertado queda vacío.
- Para secede se verifica que los tamaños del árbol original disminuye y el subárbol tiene un tamaño del complemento y que las relaciones de los padres se mantiene.
- Para removeSubtree elimina un subárbol desde la raíz y que el árbol queda vacío.
12. Top valida que el elemento mínimo ha sido llevado a la raíz después de hacer add e implícitamente bubbleUp, luego que al remover un elemento se quitó la raíz y que después de realizar esas operaciones se sigue preservando la propiedad del heap.
13. Demuestra que los casos probados son correctos.
14. No demuestra que el código sea correcto para todos los casos.
15. Porque al ser ideas conceptuales del algoritmo estas deben mantenerse para cualquier caso.


### Bloque 6 - Lectura cercana de código

1. Que la raíz no tenga parent, que un nodo solo tenga un padre y que puede tener hasta un hijo izquierdo y derecho y el hijo solo puede ser izquierdo o derecho. 
2. Porque la invariante exige que solo tenga un hijo izquierdo o derecho, sino deja de ser un árbol binario.
3. size recorre de forma recursiva, cuenta el nodo actual y los subárboles izquierdo y derecho hasta llegar a las hojas.
4. 
- leftmost va recorriendo desde el nodo actual por la izquierda hasta llegar a una hoja.
- rightmost va recorriendo desde el nodo actual por la derecha hasta llegar a una hoja.
5. succ va recorriendo según dos casos: 
 - Si tiene hijo derecho, va por el hijo derecho y luego va recorriendo por el hijo izquierdo hasta llegar a una hoja.
 - Si no tiene hijo derecho y a la vez es hijo derecho va recorriendo en bucle por los padres mientras sean hijos derechos y devuelve el padre del último padre derecho.   
6. pred va recorriendo de forma similar a succ:
 - Si tiene hijo izquierdo, va por el hijo izquierdo y luego va recorriendo por el hijo derecho hasta llegar a una hoja.
 - Si no tiene hijo izquierdo y a la vez es hijo izquierdo va recorriendo en bucle por los padres mientras sean hijos izquierdos y devuelve el padre del último padre izquierdo.   
7. root_ almacena la información de la raíz del árbol y se actualiza cada vez que se inserta un nodo como raíz, pero a la vez deshace todo el árbol. size_ almacena la cantidad de nodos del árbol, empieza en 1 cuando se crea la raíz y se va actualizando cada vez que se insertan hijos.
8. Retorna la altura del súbarbol formado desde el nodo, elige la mayor altura formada por los subárboles formados por su hijo izquierdo o derecho y le agrega 1, la altura adicional del nodo actual, esto se actualiza en las inserciones.
9. Esto actualiza la altura del subárbol formado por los padres del nodo, ya que llama a updateHeight y va actualizando el nodo actual a su nodo padre hasta llegar a la raíz.
10. attachAsLC lo que hace es primero verificar que los punteros sean válidos y que no tenga hijo izquierdo, luego hace que el puntero del hijo izquierdo apunte a la raíz del subárbol y a la vez que la raíz del subárbol apunte al padre, luego actualiza la altura y deja al subárbol vacío. Lo mismo para attachAsRC, pero en lugar de trabajar por la izquierda lo hace por la derecha.
11. Si se toma un nodo lo que hace removeSubtree es desconectar el nodo del árbol y destruir sus elementos, mientras secede lo que hace es desconectar el nodo del árbol y formar con el subárbol un nuevo árbol y lo retorna, es decir no lo destruye.
12. Porque si el objetivo es crear un nuevo árbol desde el subárbol si fuesen destruidos primero tendrían que haber sido copiados para luego restaurase, lo que complica la implementación, ya que es mucho más simple solo desconectarlo.
13. Porque el objetivo es eliminar el subárbol para eso tiene que desconectarlo y liberar los punteros de todos los hijos.
14. Verifica que los punteros de los hijos hacia los padres apunten correctamente.
15. 
- firstNode devuelve el puntero nulo si es la raíz y sino devuelve el nodo más a la izquierda.
- lastNode devuelve el puntero nulo si es la raíz y sino devuelve el nodo más a la derecha.
- nextNode devuelve el puntero nulo si es nulo y sino devuelve el sucesor del nodo según succ.
- prevNode devuelve el puntero nulo si es nulo y sino devuelve el predecesor del nodo según pred.
16. Porque succ está diseñado para dar el siguiente sucesor inorder y un iterador dará un recorrido de los elementos inorder.
17. asciiArt nos da una representación visual del árbol lo que hace más comprensible como los punteros están conectados.

### Bloque 7 - BST

1. La propiedad BST es que para cada nodo en un árbol se debe cumplir que el hijo izquierdo almacena un valor menor que el padre y el hijo derecho un valor mayor que su padre.
2. Porque el recorrido inorder en un BST coincide con la propiedad, ya que primero recorre el subárbol izquierdo, luego el nodo y luego el subárbol derecho; es decir va de menor a mayor.
3. find es un alias de lowerBound, lowerBound busca el primer valor que sea mayor o igual, upperBound busca el valor estrictamente mayor y findEQ busca el valor exacto en el árbol.
4. findEQ puede fallar en encontrar el valor porque es una igualdad, mientras que lowerBound es una condición menos estricta y solo requiere un valor mayor o igual, no estrictamente igual, tiene un rango de búsqueda más grande.
5.
│       ┌── 12
│   ┌── 10
│   │   └── 8
└── 7
    │       ┌── 6
    │   ┌── 5
    │   │   └── 4
    └── 3
        └── 1
6. 
- inorden: 1 3 4 5 6 7 8 10 12
- preorder: 7 3 1 5 4 6 10 8 12
- postorder: 1 4 6 5 3 8 12 10 7
- por niveles: 7 3 10 1 5 8 12 4 6

7. 
lowerbound(9)
- 9 > 7 candidato = nullptr
- 9 < 10 candidato = 10
- 9 > 8 candidato = 10 , fin
upperbound(8)
- 8 > 7 candidato = nullptr
- 8 < 10 candidato = 10
- 8 == 8 candidato = 10 , fin

8.
- Caso nodo es hoja: Descnecta y elimina el nodo, actualiza la altura.
- Caso nodo con un hijo: El hijo se conecta al padre del padre se actualiza la altura, se desconeta y elimina el nodo.
- Caso nodo con dos hijos: Se busca el sucesor inorder del nodo y se conecta al padre del nodo, se actualiza la altura, se desconecta y elimina el nodo.

9. Lo que hace splice es elegir como se conecta el padre del nodo al hijo y luego actualiza la altura.
10. Se debe seguir cumpliendo la propiedad BST, es decir la relación de un padre con sus hijos izquierdo y derecho.
11. Porque al eliminar el nodo debe seguir cumpliendo la propiedad BST lo que deriva a conservar el orden inorder.
12. Reorganiza los punteros mueve el hijo derecho hacia arriba y reubica el subárbol izquierdo de ese hijo como derecho del nodo original.
13. Reorganiza los punteros mueve el hijo izquierdo hacia arriba y reubica el subárbol derecho de ese hijo como izquierdo del nodo original.
14. Demuestra que una rotación local preserva la propiedad BST.
14. Rotarlo no altera el orden relativo de los nodos, solo cambia la estructura de enlaces manteniendo intacto el recorrido inorden.
```cpp
u->right = w->left;
w->left = u;
...
w->parent = u->parent;
u->parent = w;
```
No altera la relación de orden.

15. Al ser una lista ordenada construye un BST balanceado a través de los medios, tener un árbol balanceado mejora el costo de operaciones en el árbol, ya que el recorrido de un nodo a la hoja es mínima en promedio comparado a un árbol desbalanceado.
16. Un árbol balanceado tiene costo de búsqueda O(logn) mientras que un BST degenerado es el peor caso posible y tiene que recorrer todos los elementos y es de costo O(n). 

### Bloque 8 - Heap

Revisa:

- `Semana5/include/BinaryHeap.h`
- `Semana5/demos/demo_heap.cpp`
- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`

Responde:

1. Explica por qué un heap binario puede almacenarse en un `std::vector` sin punteros.
1.
2. Demuestra las fórmulas:

   ```cpp
   left(i) = 2*i + 1
   right(i) = 2*i + 2
   parent(i) = (i - 1) / 2
   ```
2. 
3. Define la propiedad de min-heap.
3.
4. Explica por qué `top()` devuelve el mínimo.
4.
5. Explica paso a paso cómo `bubbleUp(i)` restaura la propiedad de heap después de insertar.
5.
6. Explica paso a paso cómo `trickleDown(i)` restaura la propiedad de heap después de eliminar la raíz.
6.
7. Explica por qué `remove()` debe mover el último elemento a la raíz antes de aplicar `trickleDown(0)`.
7.
8. Explica qué verifica `isHeap()`.
8.
9. Compara construir un heap insertando `n` elementos con construirlo usando `heapify()`.
9.
10. Justifica por qué insertar `n` elementos uno por uno cuesta `O(n log n)` en el peor caso.
10.
11. Justifica por qué `heapify()` puede ejecutarse en `O(n)`.
11.
12. Ejecuta una extracción completa del heap construido con `{7, 3, 10, 1, 5, 8, 2}` y explica por qué la secuencia extraída sale ordenada.
12.
13. Compara el heap con el BST: ¿cuál estructura conviene para consultar mínimo repetidamente y cuál conviene para búsquedas ordenadas?.
13.

### Bloque 9 - Cierre comparativo

Responde esta pregunta final:

¿Qué cambia cuando pasamos de estudiar listas, pilas y colas a diseñar árboles binarios, heaps y árboles binarios de búsqueda?

La respuesta debe incluir obligatoriamente:

- Una afirmación sobre representación enlazada con nodos y punteros.
- Una afirmación sobre representación implícita en arreglo.
- Una afirmación sobre la diferencia entre propiedad estructural y propiedad de orden.
- Una afirmación sobre recorridos y por qué son una forma de convertir un árbol en una secuencia.
- Una afirmación sobre mantenimiento de alturas y enlaces `parent`.
- Una afirmación sobre BST, búsqueda ordenada y recorrido inorden.
- Una afirmación sobre heap, prioridad y costo de `add`, `remove` y `heapify`.
- Una afirmación sobre qué evidencia usarías para defender correctitud: pruebas, demos, invariantes, trazados y complejidad.


### Autoevaluación breve

- Qué puedo defender con seguridad:
- Qué todavía confundo:
- Qué evidencia usaría en una sustentación:
- Qué parte del código me parece más importante para revisar otra vez:
