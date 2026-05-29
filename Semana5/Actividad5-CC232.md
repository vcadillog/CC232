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


### Bloque 5 - Pruebas e invariantes


### Bloque 6 - Lectura cercana de código


### Bloque 7 - BST


### Bloque 8 - Heap


### Bloque 9 - Cierre comparativo


### Autoevaluación breve

- Qué puedo defender con seguridad:
- Qué todavía confundo:
- Qué evidencia usaría en una sustentación:
- Qué parte del código me parece más importante para revisar otra vez:
