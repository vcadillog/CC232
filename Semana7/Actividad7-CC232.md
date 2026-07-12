### Actividad 7 - CC232

#### Estudiante

- Nombre:

#### Datos generales

Duración: 3 horas de clase.

Modalidad: Trabajo individual.

Entrega: Un archivo llamado `Actividad7-CC232.md`.

#### Objetivo

Consolidar lo trabajado en la Semana 7 a partir de lectura de código, ejecución de demostraciones, revisión de pruebas, trazado manual y defensa escrita breve.

La meta es entender cómo un árbol binario de búsqueda puede evitar la degeneración lineal mediante invariantes adicionales:

1. AVL mantiene balance por altura.
2. Red-Black Tree mantiene balance por colores.
3. Ambas estructuras usan rotaciones para conservar el orden inorder del BST.
4. La Semana 7 continúa las ideas de Semana 5 y Semana 6: BST, rotaciones, búsqueda ordenada, prioridad como propiedad adicional y estructuras que mantienen eficiencia mediante invariantes.

El énfasis de esta actividad está en explicar no solo qué operación se ejecuta, sino qué invariante se mantiene, qué rotación aparece, qué evidencia produce el código y qué costo tiene cada operación.

#### Material de trabajo

#### Código de la semana

Revisa como mínimo:

* `Semana7/README.md`
* `Semana7/lecturas/Notas.md`
* `Semana7/include/Entry.h`
* `Semana7/include/BinNode.h`
* `Semana7/include/BinTree.h`
* `Semana7/include/BST.h`
* `Semana7/include/AVL.h`
* `Semana7/include/BinaryTree.h`
* `Semana7/include/BinarySearchTree.h`
* `Semana7/include/RedBlackTree.h`
* `Semana7/include/AVLTreeCompact.h`
* `Semana7/include/RedBlackTreeLLRB.h`
* `Semana7/include/Capitulo7.h`

#### Código reutilizado conceptualmente

Revisa también:

* `Semana5/include/BinarySearchTree.h`
* `Semana6/include/Treap.h`
* `Semana6/demos/demo_bst_rotations.cpp`
* `Semana6/demos/demo_treap_basico.cpp`

#### Demostraciones y pruebas

Revisa y ejecuta:

* `Semana7/demos/demo_avl_deng_core.cpp`
* `Semana7/demos/demo_avl_compact_rotations.cpp`
* `Semana7/demos/demo_bst_deng_vs_avl.cpp`
* `Semana7/demos/demo_redblack_morin.cpp`
* `Semana7/demos/demo_redblack_llrb.cpp`
* `Semana7/demos/demo_compare_avl_vs_redblack.cpp`
* `Semana7/demos/demo_compare_with_semana5.cpp`
* `Semana7/demos/demo_capitulo7_panorama.cpp`
* `Semana7/pruebas_publicas/test_public_week7.cpp`
* `Semana7/pruebas_internas/test_internal_week7.cpp`

#### Reglas de trabajo

1. No reemplaces AVL o Red-Black Tree por `std::set`, `std::map` u otra estructura estándar que oculte el algoritmo.
2. No cambies la interfaz principal de la librería salvo que una pregunta lo pida explícitamente.
3. Toda explicación debe mencionar invariante, operación, evidencia y costo.
4. Si modificas una demostración o agregas una prueba, marca el cambio con un comentario breve.

```cpp
// MOD-A7-B4: caso de comparacion de altura
```

5. No basta con ejecutar el programa. Debes poder explicar por qué la estructura sigue siendo un BST y por qué su altura se mantiene controlada.

#### Bloque 1 - Diagnóstico inicial de la Semana 7

Revisa:

* `Semana7/README.md`
* `Semana7/CMakeLists.txt`
* `Semana7/include/Capitulo7.h`

Ejecuta desde la raíz de la librería:

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
ctest --test-dir build-debug -R semana7 --output-on-failure
```

Responde:

1. ¿Qué targets de demostración aparecen para Semana 7?
1. Aparecen los siguientes targets de demostración:
   - sem7_demo_avl_compact_rotations
   - sem7_demo_avl_deng_core
   - sem7_demo_bst_deng_vs_avl
   - sem7_demo_capitulo7_panorama
   - sem7_demo_compare_avl_vs_redblack
   - sem7_demo_compare_with_semana5
   - sem7_demo_redblack_llrb
   - sem7_demo_redblack_morin

2. ¿Qué pruebas públicas e internas aparecen?
2. 
- pruebas públicas:
- pruebas internas:
     - pruebas públicas: sem7_test_public                                                           
     - pruebas internas: sem7_test_internal 

3. ¿Qué archivos incluye `Capitulo7.h`?
3. Incluye los siguientes archivos:
    - "Entry.h"
    - "BinNode.h"
    - "BinTree.h"
    - "BST.h"
    - "AVL.h"
    - "BinaryTree.h"
    - "BinarySearchTree.h"
    - "RedBlackTree.h"
    - "AVLTreeCompact.h"
    - "RedBlackTreeLLRB.h"
4. ¿Qué relación conceptual hay entre Semana 5, Semana 6 y Semana 7?
4.
- La semana 5 introduce árboles binarios BST y operaciones básicas de inserción, eliminación y búsqueda.
- La semana 6 introduce Treap, que combina propiedades de BST y heap.
- La semana 7 se enfoca en estructuras balanceadas como AVL y Red-Black Tree, que mantienen invariantes adicionales para evitar la degeneración cada semana va ampliando la estructura de árboles.

5. ¿Por qué no es correcto decir que una carpeta "hereda" de otra carpeta?
5. Porque heredar en programación es un concepto de POO; una clase hija obtiene atributos y métodos de una clase padre; una carpeta solo organiza archivos; no transmite comportamiento, no tiene interfaz, no puede ser polimórfica.

6. ¿Qué clases sí usan herencia dentro del código?
6. Las clases que usan herencia dentro del código son:

   | Clase | Hereda de |                                                                  
   |---|---|                                                                              
   | `BSTNode` | `BTNode` |                                                               
   | `BinarySearchTree` | `BinaryTree` |                                                  
   | `BST` | `BinTree` |                                                                  
   | `AVL` | `BST` |                                                                      
   | `RedBlackNode` | `BSTNode` |                                                         
   | `RedBlackTree` | `BinarySearchTree` |                                                
   | `BTNode1`, `BSTNode1`, `RedBlackNode1` | implementación de nodos (CRTP) |            
   | `BinarySearchTree1`, `RedBlackTree1` | implementación de árboles (CRTP) |            

7. ¿Qué evidencia inicial obtuviste al ejecutar las pruebas sin modificar nada?.
   Ambos tests pasaron sin errores (100% passed, 0 failed), lo que indica que las implementaciones de AVL y Red-Black Tree ya cumplen con los invariantes básicos desde el inicio.

Entrega en este bloque:

| Comando | Resultado | Error | Interpretación |
|---|---|---|---|
| `cmake -S Semana7 -B build-debug -DCMAKE_BUILD_TYPE=Debug` | Configuración exitosa | Ninguno | CMake generó los targets correctamente |
| `cmake --build build-debug` | Compilación 100% exitosa | Ninguno | 10 targets compilados sin errores |
| `ctest --test-dir build-debug -R semana7 --output-on-failure` | 2/2 tests passed (0.01s) | Ninguno | `semana7_public` y `semana7_internal` pasan, las estructuras balanceadas funcionan |

Archivos revisados primero:
- `Semana7/README.md`
- `Semana7/CMakeLists.txt`
- `Semana7/include/Capitulo7.h`

#### Bloque 2 - BST como punto de partida

Revisa:

* `Semana7/include/BST.h`
* `Semana7/include/BinarySearchTree.h`
* `Semana7/demos/demo_compare_with_semana5.cpp`
* `Semana7/demos/demo_bst_deng_vs_avl.cpp`

Responde:

1. Define formalmente la propiedad BST.
   Para todo nodo `x`, todos los elementos del subárbol izquierdo son menores que `x->data` y todos los del subárbol derecho son mayores.

2. Explica por qué el recorrido inorder de un BST produce una secuencia ordenada.
   El inorder visita izquierda -> nodo -> derecha. Por la propiedad BST, izquierda contiene los menores, luego el nodo, luego los mayores -> secuencia ascendente.

3. Explica por qué insertar claves ordenadas puede producir un BST degenerado.
   Si se insertan claves en orden ascendente, cada nueva clave es mayor que todas las anteriores y siempre se inserta como hijo derecho del nodo más profundo, el árbol degenera en una lista enlazada.

4. Construye manualmente el BST resultante de insertar:

```cpp
10, 20, 30, 40, 50, 60, 70
```

```
10
 \
  20
   \
    30
     \
      40
       \
        50
         \
          60
           \
            70
```

5. Indica la altura del árbol anterior si no hay balanceo.
   Altura = 6 (aristas) / 7 niveles.

6. Explica por qué una búsqueda en ese árbol puede costar `O(n)`.
   El árbol degeneró en una lista enlazada. Buscar el último elemento requiere recorrer todos los nodos O(n).

7. Explica qué problema intenta resolver AVL.
   Mantiene |balance factor| ≤ 1 en todo nodo, garantizando altura O(log n) y operaciones O(log n).

8. Explica qué problema intenta resolver Red-Black Tree.
   Usa reglas de color (rojo/negro) para mantener altura O(log n) con menos rotaciones que AVL, más eficiente en inserciones/eliminaciones.


#### Bloque 3 - AVL: balance por altura

Revisa:

* `Semana7/include/AVL.h`
* `Semana7/include/BST.h`
* `Semana7/include/BinNode.h`
* `Semana7/demos/demo_avl_deng_core.cpp`

Responde:

1. ¿Qué significa que un nodo esté balanceado en un AVL?
   |bf| = |altura(izq) − altura(der)| ≤ 1.

2. ¿Cómo se calcula el factor de balance?
   bf = altura(izq) − altura(der).

3. ¿Qué información de altura debe mantenerse después de insertar o eliminar?
   La altura de cada nodo desde el punto de inserción/eliminación hasta la raíz.

4. ¿Qué representa `_hot` dentro de la implementación estilo Deng?
   El nodo padre del nodo insertado; desde él se retrocede verificando balance.

5. ¿Por qué AVL puede heredar de `BST<T, Compare>`?
   AVL es un BST con un invariante extra; hereda búsqueda, inserción y estructura básica.

6. ¿Qué operación restaura localmente la forma del árbol?
   Una rotación simple o doble.

7. ¿Por qué una rotación no destruye la propiedad BST?
   Porque el orden inorder: izquierda < nodo < derecha se mantiene.

8. Después de insertar, ¿por qué suele bastar reparar el primer ancestro desbalanceado?
   La inserción aumenta altura en 1; al rotar ese ancestro se restaura la altura local.

9. Después de eliminar, ¿por qué puede ser necesario seguir revisando hacia la raíz?
   La eliminación puede reducir altura y desbalancear ancestros superiores, requiriendo múltiples rotaciones. El proceso de eliminación es bajar el nodo siguiendo el orden BST mediante rotaciones y desconectar cuando sea una hoja.

Entrega en este bloque:

* Invariante AVL: para todo nodo, |altura(izq) − altura(der)| ≤ 1; esto garantiza altura O(log n).
* Trazado de inserción con rotación: insertar 10, 20, 30 en AVL -> 10 raíz, 20 hijo derecho, 30 hijo derecho de 20 -> 10 queda con bf = −2 -> rotación izquierda en 10 -> 20 es nueva raíz con hijos 10 (izq) y 30 (der), altura = 1.
* Evidencia de salida de `demo_avl_deng_core.cpp`:
  ```
  AVL inorder: 10 20 22 25 27 30 40 50 
  AVL level-order: 30 20 40 10 25 50 22 27 
  Valido AVL: si
  Tras borrar 20 y 40: 10 22 25 27 30 50 
  Valido AVL: si
  ```

#### Bloque 4 - Rotaciones AVL: casos LL, RR, LR y RL

Revisa:

* `Semana7/include/AVLTreeCompact.h`
* `Semana7/demos/demo_avl_compact_rotations.cpp`
* `Semana7/include/AVL.h`

Ejecuta las demostraciones de rotaciones y construye una tabla con estas columnas:

insert(30) -> root=30, height=0
insert(20) -> root=30, height=1
insert(10) -> root=20, height=1
insert(25) -> root=20, height=2
insert(28) -> root=20, height=2
insert(27) -> root=25, height=2
inorder: 10 20 25 27 28 30 
level: 25 20 28 10 27 30 
AVLTreeCompact(size=6, height=2)
isAVL = true

| Caso | Secuencia insertada    | Nodo desbalanceado | Rotación aplicada                    | Inorder antes     | Inorder después   | Altura final |
| ---- | ---------------------- | ------------------ | ------------------------------------ | ----------------- | ----------------- | ------------ |
| LL   | 30, 20, 10             | 30                 | Rotación simple derecha              | 10 20 30          | 10 20 30          | 1            |
| LR   | 10,20,25,28,30         | 30                 | Rotación doble izquierda y derecha   | 10 20 25 28 30    | 10 20 25 28 30    | 1            |
| LL   | 10,20,25,28,30         | 30                 | Rotación simple derecha              | 10 20 25 28 30    | 10 20 25 28 30    | 1            |
| RL   | 10,20,25,27,28,30      | 28                 | Rotación doble derecha e izquierda   | 10 20 25 27 28 30 | 10 20 25 27 28 30 | 1            |
| RR   | 10,20,25,27,28,30      | 20                 | Rotación simple a la izquierda       | 10 20 25 27 28 30 | 10 20 25 27 28 30 | 1            |


* Caso
* Secuencia insertada
* Nodo desbalanceado
* Rotación aplicada
* Inorder antes
* Inorder después
* Altura final

Incluye los cuatro casos:

1. LL
2. RR
3. LR
4. RL

```text
insert(30)
30

insert(20)
 30
/
20

insert(10)   
   30
   /
  20
 /
10
LL en 30

Aplicando rotación derecha
   20
  /  \
10   30

insert(25)
   20
  /  \
10   30
     /
    25

insert(28)
   20
  /  \
10   30
     /
    25
      \
      28
LR en 30
Aplicando rotación izquierda 25
   20
  /  \
10   30
     /
    28 
   /
  25
LL en 30
Aplicando rotación derecha 30
   20
  /  \
10   28
     / \
    25  30


insert(27)
      20
     /  \
   10    28
         / \
       25  30
         \
         27

RL en 28
Rotación derecha
   20
  /  \
10    25
        \
         28
        /  \ 
       27   30
RR en 20

Rotación izquierda en 20
          25
         /  \
       20    28
      /     /  \
    10     27  30
```

Responde:

1. ¿Qué diferencia hay entre una rotación simple y una rotación doble?
Una rotación simple mueve un nodo una sola vez para restaurar el balance y doble combina dos rotaciones consecutivas.
2. ¿Por qué LL y RR se corrigen con una sola rotación?
Porque el desbalance está alineado en una sola dirección.
3. ¿Por qué LR y RL requieren dos pasos?
Porque el desbalance está en ambas direcciones, izquierda y derecha, primero se convierte a LL o RR y luego se rebalancea en una sola rotación.
4. ¿Qué parte del árbol cambia y qué parte permanece igual?
Solo cambia el subárbol cuya raíz es el nodo desbalanceado.
5. ¿Por qué el inorder debe ser el mismo antes y después de reestructurar?.
Porque un AVL cumple la condición BST sin importar si el árbol está balanceado o no, el recorrido inorder es siempre el mismo en orden ascendente.

* Argumento de preservación del orden BST: en una rotación derecha, el subárbol izquierdo del nodo desbalanceado pasa a ser la nueva raíz local; su hijo derecho (que era mayor que él pero menor que el nodo original) se recoloca como hijo izquierdo del nodo original. En una rotación izquierda ocurre el análogo simétrico. En todos los casos, la relación inorder (izquierda < nodo < derecha) se mantiene porque los subárboles completos se reubican sin mezclar sus rangos de clave.

#### Bloque 5 - Red-Black Tree: balance por colores

Revisa:

* `Semana7/include/RedBlackTree.h`
* `Semana7/include/BinarySearchTree.h`
* `Semana7/include/BinaryTree.h`
* `Semana7/demos/demo_redblack_morin.cpp`


Responde:

1. ¿Qué propiedad BST mantiene Red-Black Tree?
1. El Red-Black Tree mantiene las propiedades del BST de orden por clave.

2. ¿Qué propiedades de color debe cumplir un Red-Black Tree?
2. Los nodos son rojos o negros, la raíz es negra, las hojas son negras, un nodo rojo no puede tener hijos rojos, todos los caminos desde un nodo hacia sus hojas tienen el mismo número de nodos negros.

3. ¿Por qué la raíz debe terminar negra?
3. Porque si la raíz fuera roja, podría tener un hijo rojo violando la regla de no tener arista roja al recolorear, por eso se considera negra como estándar.

4. ¿Qué significa que no pueda haber dos nodos rojos consecutivos?
4. Es una condición que evita que el árbol se desbalancee.

5. ¿Qué representa la altura negra?
5. Cuenta la cantidad de nodos negros que hay en el camino desde un nodo hacia su hoja.

6. ¿Por qué Red-Black Tree permite un balance menos estricto que AVL?
6. AVL exige |bf| ≤ 1 para todo nodo, lo que fuerza una altura muy cercana a log₂n. Red-Black Tree solo exige que ningún camino tenga el doble de nodos negros que otro; misma altura negra; lo que permite diferencia de alturas mayores. Esto implica menos rotaciones en inserciones/eliminaciones a costa de un balance menos exigente.

7. ¿Qué correcciones pueden aparecer después de insertar?
7. Cuando se inserta se llama a pushBlack a través de addFixup y corrige la coloración problemática, dos rojos seguidos.

8. ¿Qué correcciones pueden aparecer después de eliminar?
8. Al eliminar un nodo negro se viola la altura negra. La corrección (`removeFixup`) aplica según el color del hermano y sus sobrinos:
   - Hermano rojo, rotación para convertirlo en negro.
   - Hermano negro con ambos sobrinos negros, recoloreo se sube el negro al padre.
   - Hermano negro con al menos un sobrino rojo, rotación y recoloreo para restaurar la altura negra localmente.
   La línea:
   ```cpp
       u->colour += w->colour;
   ```
   corresponde a `pushBlack` suma el exceso de negro del nodo eliminado al hermano, fusionando o redistribuyendo negros.
9. ¿Qué papel cumplen las rotaciones en Red-Black Tree?
9. Reestructuran el árbol para eliminar violaciones rojo-rojo o restaurar la altura negra, preservando la propiedad BST.
10. ¿Qué papel cumple el cambio de colores?
10. Resuelve violaciones de color sin rotar: recolorea padre, tío y abuelo cuando el tío es rojo, propagando el conflicto hacia la raíz. 

Entrega en este bloque:

* Lista de invariantes Red-Black:
  1. Cada nodo es rojo o negro.
  2. La raíz es negra.
  3. Las hojas (nil) son negras.
  4. Un nodo rojo no puede tener hijos rojos (no hay arista roja).
  5. Todos los caminos desde un nodo hasta sus hojas tienen el mismo número de nodos negros (altura negra constante).

* Explicación de una inserción que requiera recoloreo:
  Insertar 7 en `{10(negro), 5(rojo), 15(rojo)}`:

  Árbol inicial:
  ```
      10(B)
     /    \
    5(R)  15(R)
  ```

  Insertar 7 como rojo, hijo derecho de 5 (violación: dos rojos seguidos):
  ```
      10(B)
     /    \
    5(R)  15(R)
     \
      7(R)
  ```

  Tío (15) es rojo, solo recoloreo: padre(5) negro, tío(15)→negro, abuelo(10) rojo. Como 10 es raíz, se pinta negro:
  ```
      10(B)
     /    \
    5(B)  15(B)
     \
      7(R)
  ```

* Evidencia de salida de `demo_redblack_morin.cpp`:
  ```
  RB inorder: 2 3 6 7 8 10 11 13 18 22 26 
  Valido RedBlack: si
  Tras borrar 18 y 11: 2 3 6 7 8 10 13 22 26 
  Valido RedBlack: si
  ```

#### Bloque 6 - Comparación: BST, Treap, AVL y Red-Black Tree

Revisa:

* `Semana6/include/Treap.h`
* `Semana7/demos/demo_compare_avl_vs_redblack.cpp`
* `Semana7/demos/demo_compare_with_semana5.cpp`
* `Semana7/demos/demo_capitulo7_panorama.cpp`

Construye una tabla con estas columnas:

* Estructura
* Propiedad de orden
* Propiedad adicional
* Operación de reparación
* Altura esperada o garantizada
* Caso donde conviene usarla

Incluye:

1. BST común
2. Treap
3. AVL
4. Red-Black Tree

| Estructura | Propiedad de orden | Propiedad adicional | Operación de reparación | Altura | Caso de uso |
|---|---|---|---|---|---|
| BST común | BST (izq < nodo < der) | Ninguna | No aplica | O(n) peor caso | Educativo, base conceptual |
| Treap | BST | Prioridad heap (max-heap) | Rotaciones por prioridad | O(log n) esperado | Balance probabilístico, datos dinámicos |
| AVL | BST | abs(bf) ≤ 1 | Rotaciones simple/doble según factor de balance | O(log n) garantizado | Búsquedas frecuentes, balance fuerte |
| Red-Black Tree | BST | Colores rojo/negro, misma altura negra | Rotaciones + recoloreo | O(log n) | Muchas inserciones/eliminaciones |

Responde:

1. ¿Qué tienen en común BST, Treap, AVL y Red-Black Tree?
   Todos son BST: mantienen la propiedad de orden inorder y usan rotaciones para reestructurar (solo treap, red-black tree y AVL).

2. ¿Qué diferencia hay entre prioridad en Treap, altura en AVL y color en Red-Black Tree?
   - Treap: prioridad aleatoria (heap) guía las rotaciones.
   - AVL: balance por altura (|bf| ≤ 1) guía las rotaciones.
   - Red-Black: colores y altura negra constante guían rotaciones/recoloreo.

3. ¿Por qué Treap depende de prioridades?
   Porque la prioridad determina si un nodo debe subir (rotar) para mantener la propiedad heap, independientemente del orden de inserción.

4. ¿Por qué AVL suele ser más estricto en altura?
   Porque exige |bf| ≤ 1 para todo nodo, forzando altura muy cercana a log₂n, mientras Red-Black permite hasta el doble (2·log₂n).

5. ¿Por qué Red-Black Tree puede ser preferible cuando hay muchas inserciones y eliminaciones?
   Porque requiere menos rotaciones en promedio (solo O(1) rotaciones por inserción/eliminación), mientras AVL puede requerir O(log n) rotaciones tras una eliminación.

6. ¿Qué estructura elegirías para defender búsqueda ordenada con balance fuerte?
   AVL, porque garantiza la menor altura posible (O(log n) estricto) y las búsquedas son más rápidas.

7. ¿Qué estructura elegirías para explicar balance probabilístico?
   Treap, porque su balance depende de prioridades aleatorias y no de invariantes rígidos.

#### Bloque 7 - Pruebas, invariantes y defensa oral

Revisa:

* `Semana7/pruebas_publicas/test_public_week7.cpp`
* `Semana7/pruebas_internas/test_internal_week7.cpp`

Responde:

1. ¿Qué operaciones valida la prueba pública para AVL?
1. Inserta secuencias (30,20,10) y (40,20,60,10,30,50,70,25), verifica inorder, isAVLValid, height, y remove con AVL y AVLTreeCompact.

2. ¿Qué operaciones valida la prueba pública para Red-Black Tree?
2. Inserta (7,3,18,10,22,8,11,26), verifica verifyRB() (que sea Red-Black Tree), add duplicado (false), remove, con RedBlackTree1 y RedBlackTreeLLRB (isRedBlackTree, inorder).

3. ¿Qué casos adicionales cubre la prueba interna?
3.
   - Prueba BST (insert/remove)
   - BinarySearchTree1 (lowerBound/upperBound)
   - test de stress de 250 inserciones aleatorias + 120 eliminaciones con 4 estructuras simultáneas contra un std::set, validando invariantes tras cada operación.

4. ¿Qué significa que una prueba valide el inorder?
4. Que verifica la propiedad BST: el recorrido inorder debe producir una secuencia ordenada ascendente, idéntica a la de un std::set ordenado con los mismos elementos.

5. ¿Qué significa que una prueba valide alturas o factores de balance?
5. Que verifica el invariante AVL: |altura(izq) − altura(der)| ≤ 1 para todo nodo, garantizando altura O(log n).

6. ¿Qué significa que una prueba valide colores?
6. Que verifica las 5 invariantes Red-Black: raíz negra, hojas negras, sin rojos consecutivos, misma altura negra en todos los caminos.

7. ¿Qué no demuestra pasar solo las pruebas públicas?
7. No demuestra robustez ante datos aleatorios, eliminaciones masivas, casos borde (árbol vacío, un solo nodo), ni la correctitud de otro caso existente. 

8. ¿Qué evidencia usarías en una sustentación: demostración, prueba, trazado o argumento de complejidad?
8. Usaría todas
   - demostración (ejecución del código)
   - prueba (test que pasa)
   - trazado (seguimiento paso a paso de una operación) 
   - argumento de complejidad (análisis O(log n)).

9. ¿Qué invariante revisarías primero si falla AVL?
9. El factor de balance (|bf| ≤ 1) y la actualización correcta de alturas tras rotaciones.

10. ¿Qué invariante revisarías primero si falla Red-Black Tree?
10.  La regla de no arista roja y la altura negra constante, que son las que más probablemente se pueden violar tras inserciones/eliminaciones.

Entrega en este bloque:

* Tabla de pruebas revisadas:

| Prueba | Archivo | Estructuras validadas | Operaciones |
|---|---|---|---|
| Pública | `test_public_week7.cpp` | AVL, RedBlackTree1, AVLTreeCompact, RedBlackTreeLLRB | insert, remove, inorder, isAVLValid, verifyRB, isRedBlackTree, altura |
| Interna | `test_internal_week7.cpp` | BST, BinarySearchTree1, AVL, RedBlackTree1, AVLTreeCompact, RedBlackTreeLLRB | insert, remove, contains, lowerBound, upperBound, inorder, isBSTValid, isAVLValid, verifyRB, isRedBlackTree + test aleatorio (250 inserciones, 120 eliminaciones) |

* Lista de invariantes que defenderías:
  1. BST: inorder ordenado (izquierda < nodo < derecha).
  2. AVL: |bf| ≤ 1 en todo nodo.
  3. Red-Black: raíz negra, sin arista roja, misma altura negra.

* Evidencia de ejecución de `ctest`:
  ```
  Test project /home/victor/clases/algoritmos/CC232-pc1/Semana7/build-debug
      Start 1: semana7_public
  1/2 Test #1: semana7_public ...................   Passed    0.00 sec
      Start 2: semana7_internal
  2/2 Test #2: semana7_internal .................   Passed    0.01 sec
  100% tests passed, 0 tests failed out of 2
  ```

#### Bloque 8 - Ejercicios de codificación

En este bloque debes modificar o extender la Semana 7 sin romper la interfaz principal de la librería. El objetivo es comprobar que entiendes los invariantes de AVL y Red-Black Tree no solo de forma teórica, sino también mediante código, pruebas y evidencia de ejecución.

#### Ejercicio 3 - Verificador de balance AVL

Crea un archivo:

```bash
Semana7/demos/demo_validate_avl_balance.cpp
```

Implementa una función que verifique que todo nodo cumpla:

```text
|height(left) - height(right)| <= 1
```

Firma sugerida:

```cpp
template <typename Node>
bool validateAVLBalance(Node* node);
```

También implementa una función auxiliar:

```cpp
template <typename Node>
int computeHeight(Node* node);
```

Reglas:

* La altura de un árbol vacío debe ser `-1`.
* La altura de una hoja debe ser `0`.
* Debes validar todos los nodos, no solo la raíz.
* El programa debe imprimir si el árbol está balanceado o no.

Salida esperada:

```text
Validacion AVL despues de inserciones
Estado: balanceado
Altura calculada: 3
```

Entrega:

* Código fuente.
* Evidencia de ejecución.

[victor@victor-archdesktop:~/clases/algoritmos/CC232-pc1/Semana7]$ ./build-debug/sem7_demo_validate_avl_balance
Altura árbol vacío: -1
Validacion AVL despues de inserciones
Estado: balanceado
Altura calculada: 3
Altura de hoja 10: 0

* Explicación de la diferencia entre altura almacenada y altura calculada.
                                                                                            
- Altura almacenada (node->height): valor en cada nodo, actualizado por updateHeight() tras inserciones/rotaciones. Acceso O(1), pero puede quedar desactualizado si la estructura se modifica sin llamar a updateHeightAbove().                                     
- Altura calculada (computeHeight(node)): recorre recursivamente todo el subárbol. Siempre refleja la altura real (O(n) por nodo), pero es más costosa, porque recorre el árbol según demanda.

#### Ejercicio 4 - Comparación experimental BST vs AVL

Crea una demostración:

```bash
Semana7/demos/demo_compare_bst_avl_height.cpp
```

Inserta las mismas claves en un BST común y en un AVL.

Casos mínimos:

```cpp
std::vector<int> sortedKeys = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::vector<int> mixedKeys = {5, 2, 8, 1, 3, 7, 9, 4, 6, 10};
```

El programa debe imprimir:

```text
Caso: claves ordenadas
Altura BST: 9
Altura AVL: 3

Caso: claves mezcladas
Altura BST: ...
Altura AVL: ...
```

Responde:

1. ¿Qué ocurre con el BST cuando las claves llegan ordenadas?
2. ¿Qué ocurre con AVL ante la misma entrada?
3. ¿Por qué ambas estructuras conservan el mismo inorder?
4. ¿Por qué la altura es la evidencia central en esta comparación?.

Entrega:

* Código fuente.
* Salida.
* Tabla comparativa.
* Interpretación.

[victor@victor-archdesktop:~/clases/algoritmos/CC232-pc1/Semana7]$ ./build-debug/sem7_demo_compare_bst_avl_height
Caso: claves ordenadas
Altura BST: 9
Altura AVL: 3

Caso: claves mezcladas
Altura BST: 3
Altura AVL: 3

Tabla comparativa
Caso            BST     AVL
Ordenadas       9       3
Mezcladas       3       3

Interpretacion
1. ¿Qué ocurre con el BST cuando las claves llegan ordenadas?
1. BST con claves ordenadas: degenera a lista enlazada (altura O(n)).
2. ¿Qué ocurre con AVL ante la misma entrada?
2. AVL con la misma entrada: rota para mantenerse balanceado (altura O(log n)).
3. ¿Por qué ambas estructuras conservan el mismo inorder?
3. Ambas conservan el inorder identico porque la propiedad BST es invariante bajo rotaciones.
4. ¿Por qué la altura es la evidencia central en esta comparación?.
4. La altura es evidencia central porque determina el costo de busqueda: O(altura).

#### Ejercicio 6 - Prueba pública adicional

Agrega una prueba pública en:

```bash
Semana7/pruebas_publicas/test_public_week7_extra.cpp
```

La prueba debe cubrir al menos:

1. Inserción ordenada en AVL.
2. Validación de inorder.
3. Validación de altura máxima razonable.
4. Inserción en Red-Black Tree.
5. Validación de búsqueda después de varias inserciones.

Ejemplo de intención:

```cpp
// Verifica que AVL no se degrade cuando recibe claves ordenadas.
```

No copies exactamente este pseudocódigo. Adáptalo a la interfaz real de la librería.

Entrega:

* Código de prueba.
* Comando usado para compilar.

```sh
cmake --build build-debug
```

* Comando usado para ejecutar.

```sh
ctest --test-dir build-debug -R semana7_public_extra --output-on-failure
```

* Resultado de `ctest`.

```sh
[victor@victor-archdesktop:~/clases/algoritmos/CC232-pc1/Semana7]$ ctest --test-dir build-debug -R s
emana7_public_extra --output-on-failure
Test project /home/victor/clases/algoritmos/CC232-pc1/Semana7/build-debug
    Start 2: semana7_public_extra
1/1 Test #2: semana7_public_extra .............   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec
```

* Explicación de qué bug detectaría esta prueba.

Si el AVL no rebalancea en inserción ordenada, height() retornaría 9 en vez de ≤ 4 y isAVLValid() fallaría. Si el Red-Black Tree pierde sus invariantes (raíz roja, rojo-rojo, altura negra inconsistente), isRedBlackTree() retornaría false. Si la búsqueda falla tras inserciones válidas, contains() lanzaría el assert.           


#### Ejercicio 8 - Integración al CMake

Agrega tus demostraciones al `CMakeLists.txt` de Semana 7.

Debes poder compilar con:

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
ctest --test-dir build-debug -R semana7 --output-on-failure
```

Entrega:

* Fragmento modificado de `CMakeLists.txt`.
```txt
cc232_add_sem7_target(sem7_demo_validate_avl_balance "demos/demo_validate_avl_balance.cpp")
cc232_add_sem7_target(sem7_demo_compare_bst_avl_height "demos/demo_compare_bst_avl_height.cpp")
cc232_add_sem7_target(sem7_test_public "pruebas_publicas/test_public_week7.cpp")
cc232_add_sem7_target(sem7_test_internal "pruebas_internas/test_internal_week7.cpp")
cc232_add_sem7_target(sem7_test_public_extra "pruebas_publicas/test_public_week7_extra.cpp")
add_test(NAME semana7_public COMMAND sem7_test_public)
add_test(NAME semana7_public_extra COMMAND sem7_test_public_extra)
```

* Evidencia de compilación.

[victor@victor-archdesktop:~/clases/algoritmos/CC232-pc1/Semana7]$ cmake -S . -B build-debug -DCMAKE
_BUILD_TYPE=Debug
cmake --build build-debug
ctest --test-dir build-debug -R semana7 --output-on-failure
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/victor/clases/algoritmos/CC232-pc1/Semana7/build-debug
[  7%] Built target sem7_demo_avl_deng_core
[ 15%] Built target sem7_demo_avl_compact_rotations
[ 23%] Built target sem7_demo_bst_deng_vs_avl
[ 30%] Built target sem7_demo_redblack_morin
[ 38%] Built target sem7_demo_redblack_llrb
[ 46%] Built target sem7_demo_compare_avl_vs_redblack
[ 53%] Built target sem7_demo_compare_with_semana5
[ 61%] Built target sem7_demo_capitulo7_panorama
[ 69%] Built target sem7_demo_validate_avl_balance
[ 76%] Built target sem7_demo_compare_bst_avl_height
[ 84%] Built target sem7_test_public
[ 92%] Built target sem7_test_internal
[100%] Built target sem7_test_public_extra

* Evidencia de pruebas.

Test project /home/victor/clases/algoritmos/CC232-pc1/Semana7/build-debug
    Start 1: semana7_public
1/3 Test #1: semana7_public ...................   Passed    0.00 sec
    Start 2: semana7_public_extra
2/3 Test #2: semana7_public_extra .............   Passed    0.00 sec
    Start 3: semana7_internal
3/3 Test #3: semana7_internal .................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 3

Total Test time (real) =   0.01 sec

* Explicación de por qué una demostración no necesariamente es una prueba automatizada.

Una demostración (demo_*.cpp) imprime resultados visibles para un observador humano y requiere inspección manual para determinar si son correctos. Una prueba automatizada (test_*.cpp) usa assert() que verifica condiciones por programa: pasa o falla sin intervención manual.                                                                                        

#### Entrega mínima de codificación

Para considerar completo este bloque, debes entregar como mínimo:

1. Dos demostraciones nuevas.
2. Una prueba pública adicional.
3. Una tabla de resultados.
4. Una explicación de invariantes.
5. Evidencia de compilación.
6. Evidencia de ejecución.
7. Evidencia de `ctest`.

#### Pregunta final del bloque

Después de implementar los ejercicios, responde:

¿Por qué en estructuras balanceadas no basta con probar que el inorder está ordenado?

Tu respuesta debe mencionar:

* Propiedad BST.
* Altura.
* Rotaciones.
* Invariante AVL.
* Invariante Red-Black.
* Diferencia entre correctitud funcional y correctitud estructural.

#### Bloque 9 - Cierre comparativo

Responde esta pregunta final:

¿Qué cambia cuando pasamos de un BST común a estructuras balanceadas como AVL y Red-Black Tree?

La respuesta debe incluir obligatoriamente:

* Una afirmación sobre degeneración lineal del BST.
* Una afirmación sobre rotaciones y preservación del inorder.
* Una afirmación sobre balance por altura en AVL.
* Una afirmación sobre balance por colores en Red-Black Tree.
* Una afirmación sobre la diferencia entre balance estricto y balance flexible.
* Una afirmación sobre el costo esperado o garantizado de búsqueda, inserción y eliminación.
* Una afirmación sobre cómo esta semana continúa Semana 5 y Semana 6.
* Una afirmación sobre qué evidencia usarías para defender correctitud: pruebas, demostraciones, invariantes, trazados y complejidad.

#### Formato sugerido de entrega

```markdown
### Actividad 7 - CC232

#### Estudiante

- Nombre:

#### Bloque 1 - Diagnóstico inicial

[Tabla de comandos, resultados e interpretación]

#### Bloque 2 - BST como punto de partida

[Respuestas, dibujo y complejidad]

#### Bloque 3 - AVL

[Invariantes, trazado y evidencia]

#### Bloque 4 - Rotaciones AVL

[Tabla LL, RR, LR, RL y dibujos]

#### Bloque 5 - Red-Black Tree

[Invariantes, recoloreo, rotaciones y evidencia]

#### Bloque 6 - Comparación

[Tabla BST, Treap, AVL y Red-Black Tree]

#### Bloque 7 - Pruebas e invariantes

[Tabla de pruebas y defensa]

#### Bloque 8 - Ejercicios de codificación

[Código, evidencias, pruebas e interpretación]

#### Bloque 9 - Cierre comparativo

[Respuesta final]

#### Autoevaluación breve

- Qué puedo defender con seguridad:
- Qué todavía confundo:
- Qué evidencia usaría en una sustentación:
- Qué parte del código debo revisar otra vez:
```

#### Criterio general de trabajo

Se espera lectura real de los archivos, respuestas breves pero justificadas, tablas con evidencia observable, trazados manuales y conexión explícita entre código, correctitud, costo, representación e invariantes.

No basta con ejecutar el programa: debes poder explicar qué propiedad mantiene cada estructura, qué rotación se aplica, qué color o altura se actualiza, qué caso borde aparece y por qué la operación conserva búsqueda ordenada eficiente.
