1. ¿Cuál es el problema exacto asignado?
F - Wide Swap, el problema pide encontrar la permutación mínima según las condiciones:
```text
Sean dos índices i,j
1<=i<j<=N

Condiciones de intercambio:
j-i>=K 
abs(Pi-Pj)=1
```

2. ¿Qué recibe la entrada y qué produce la salida?
La entrada recibe una permutación de los N primeros números naturales y produce una salida de la permutación mínima según las condiciones de permutación anteriormente escritas.

3. ¿Cuál es la restricción que vuelve insuficiente una solución ingenua?
La restricción j-i>=k y abs(Pi-Pj)=1 vuelve algoritmos de ordenamiento estándares no viables.

4. ¿Cuál sería la solución ingenua y cuál es su complejidad?
Recorrer todos los elementos y compararlos con los demás para buscar el elemento que cumpla la condición.
Tiene complejidad temporal O(n^2).

5. ¿Qué estructura de datos elegiste?
Una adaptación del treap, pero que el orden BST está definido por el índice y no el valor del nodo.

6. ¿Qué estructura de la librería cc232 se parece más?
La que más se acerca es el Treap.h de la semana 6.

7. ¿Qué operación domina el tiempo?
Las búsquedas, inserciones y eliminaciones cada una tiene costo temporal O(logn)

8. ¿Qué invariante mantiene tu estructura?
Preserva las invariantes del Heap, que debe mantener la prioridad y del BST modificado, que debe mantener el orden por índice.
Además del invariante de tamaño, cada nodo tiene un subárbol de tamaño: 1+tamaño_izquierdo + tamaño_derecho

9. ¿Dónde se actualiza ese invariante en el código?
Se actualiza con update, que es llamado por cada inserción y mezcla.

10. ¿Qué caso borde puede romper una solución superficial?
Los casos borde serían cuando K=0 , K=1, cuando la permutación ya está ordenada.

11. ¿Cómo manejas duplicados, empates o elementos obsoletos?
*La condición de entrada no permite elementos repetidos.

12. ¿Cuál es la complejidad temporal por operación?
split cuesta O(logn)
getAt cuesta O(logn)
eraseAt cuesta O(logn)
insertAt cuesta O(logn)
swapPositions cuesta O(logn)

13. ¿Cuál es la complejidad total?
La complejidad temporal total es O(nlogn), porque swapPositions se ejecuta dentro de un bucle hasta n veces.

14. ¿Cuál es la complejidad espacial?
La complejidad espacial es el almacenamiento del árbol, es decir O(n).

15. ¿Qué parte del código sería más fácil de romper?
Las partes más fáciles de romper serían en el que el árbol se reorganiza y se reorganiza con split y merge.

16. ¿Qué prueba propia escribiste?
Implementé casos de prueba con K=1, K=0, permutaciones ya ordenadas en forma ascendente y descendente, un K mayor e igual al tamaño de la secuencia.

17. ¿Qué cambiaste durante el bloque sin cortes?
Se agregó un caso ingenuo y se comparó con la solución.

18. ¿Cómo sabes que el cambio no rompió la solución?
Porque se siguen manteniendo las invariantes Heap y BST modificado.

19. ¿Qué demuestra que no es una solución de caja negra?
Porque se actualiza en cada operación split/merge y por la representación inorder de la permutación.

Preguntas específicas:
1. ¿Qué relación existe entre el orden de los elementos y la operación permitida?
La solución depende del orden por posición de los elementos y a la vez del valor de la diferencia en esas posiciones.
Según la condición:
```text
Sean dos índices i,j
1<=i<j<=N

Condiciones de intercambio:
j-i>=K 
abs(Pi-Pj)=1
```

2. ¿Qué consulta ordenada domina la complejidad?
Insertar elementos dominan la complejidad temporal.

3. ¿Cómo se puede justificar la solución usando BST/Treap o una estructura aumentada?
No se puede usar un BST como tal porque este ordena según los valores en los nodos y como tal para cualquier permutación siempre dará el mismo resultado al ordenarse, por eso se modificó esta estructura para que en lugar de su valor lo ordene según el índice.

