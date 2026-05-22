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

1. En `BinNode`, explica qué significan `hasLeft()`, `hasRight()`, `isRoot()`, `isLeaf()`, `isLeftChild()` e `isRightChild()`.
2. Explica el caso en que `succ()` baja al subárbol derecho y luego busca el nodo más a la izquierda.
3. Explica el caso en que `succ()` sube por los ancestros hasta encontrar el primer giro hacia la izquierda.
4. Explica simétricamente cómo debe funcionar `pred()`.
5. Dibuja un árbol de al menos 7 nodos y marca el sucesor y predecesor inorden de tres nodos distintos.
6. Explica qué calcula `depth(u)` y por qué puede implementarse subiendo por `parent`.
7. Explica qué calcula `height(u)` y por qué suele implementarse bajando recursivamente por los hijos.
8. Explica qué calcula `subtreeSize(u)`.
9. Demuestra que para todo nodo `u` se cumple `depth(u) + height(u) <= height(T)`.
10. Indica la condición necesaria y suficiente para que se alcance la igualdad anterior.

### Bloque 3 - Recorridos y trazado guiado


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
