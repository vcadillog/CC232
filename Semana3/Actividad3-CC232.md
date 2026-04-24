### Integrantes: 
- Victor Hugo Cadillo Gutierrez, 20255514D

### Bloque 1

1. En el almacenamiento contiguo la información se guarda en el stack, mientras en el dinámico los datos se guardan en el heap.

2. El acceso por rango busca en un intervalo de valores, mediante por posición entra al índice lógico.

3. Porque una lista enlazada conoce las posiciones exactas del elemento y los conecta con otros elementos mediante punteros y para modificar la información solo necesita reorganizar a quienes apuntan los punteros, mientras que por índice tiene que mover todos los datos siguientes del arreglo para agregar o remover un dato, pero pierde en acceso por índice porque debe recorrer los punteros en lugar de solo acceder al índice lógico del array.

4. Porque puede acceder directamente al primer o último elemento de la lista enlazada.

5. Porque SLList solo maneja una forma LIFO o FIFO y no simultaneamente.

6. dummy sirve para manejar casos borde en el cual la lista está vacía y pueda realizar insertar o eliminar elementos sin complicar la implementación.

7. Expliquen por qué `DLList` permite justificar `get(i)`, `set(i,x)`, `add(i,x)` y `remove(i)` con costo `O(1 + min(i, n-i))`.
8. Expliquen cuál es la idea espacial central de `SEList`.
9. Expliquen por qué `SEList` reutiliza una `BDeque` basada en `ArrayDeque`.
10. Expliquen qué papel cumple `DengList` dentro de esta semana y por qué no reemplaza a las estructuras de Morin.
