## Actividad 4-CC232

### Estudiante
- Cadillo Gutierrez, Victor Hugo 20255514D

#### Bloque 1 
1. El acceso LIFO se refiere a una estructura de datos donde el último elemento agregado es el primero en ser removido. Mientras que el acceso FIFO se refiere a una estructura de datos donde el primer elemento agregado es el primero en ser removido. LIFO se basa en el orden inverso de llegada, mientras que FIFO se basa en el orden de llegada.
2. El Stack es una estructura de datos que sigue el principio LIFO, lo que significa que el último elemento agregado es el primero en ser removido. Esto lo hace ideal para resolver problemas donde importa lo último pendiente porque permite acceder rápidamente al último elemento agregado sin tener que recorrer toda la estructura. 
3. Queue es una estructura de datos que sigue el principio FIFO, lo que significa que el primer elemento agregado es el primero en ser removido. Esto la hace ideal para modelar procesos de espera y atención porque permite atender a los elementos en el orden en que llegaron. Como manejar las personas en una fila de espera.
4. Reemplazar recursión implícita por una estructura explícita significa que en lugar de confiar en la pila de llamadas del sistema para manejar el estado de las funciones recursivas, se utiliza una estructura de datos explícita, como una pila o una cola, para almacenar y gestionar el estado de las operaciones. Esto permite abstraer el ADT y reutilizar la lógica de pila o cola.
5. La información mínima que debe guardarse en una pila para permitir reconstruir una solución parcial es el estado actual del problema que se está resolviendo. Esto puede incluir variables relevantes, decisiones tomadas, y cualquier información necesaria para continuar el proceso desde ese punto específico. Esta información permite que al desapilar, se pueda volver a ese estado y continuar la resolución del problema sin perder el contexto.


#### Bloque 2 - Demostración y trazado guiado


| Archivo                          | Salida u observable importante                                                                 | Estructura o técnica central      | Qué concepto permite defender                                                                 |
|----------------------------------|------------------------------------------------------------------------------------------------|-----------------------------------|----------------------------------------------------------------------------------------------|
| demo_stack_queue.cpp             | Tope de la pila = 9, Frente de la cola = 10, Elemento desapilado = 9, Elemento desencolado = 10 | Stack y Queue                     | Diferencia entre LIFO (pila) y FIFO (cola)                                                 |
| demo_base_conversion.cpp         | 12345 en base 8 (recursivo) = 30071, 12345 en base 8 (iterativo) = 30071                      | Recursión e Iteración             | Diferentes implementaciones producen la misma respuesta|
| demo_paren_rpn.cpp               | Paréntesis balanceados = true, RPN = 0 ! 1 + 2 3 ! 4 + ^ * 5 ! 67 - 8 9 + - -, Valor = 2012   | Paréntesis, RPN, evaluación       | Uso de pilas para precedencia |
| demo_nqueens.cpp                 | N = 4, soluciones = 2, verificaciones = 84                                                     | Backtracking                      | Explora combinaciones usando pila                                           |
| demo_maze.cpp                    | Medida del camino = 5, (1,1) (1,2) (1,3) (2,3) (3,3)                                          | Backtracking                      | Explora rutas usando pila |
| demo_bank.cpp                    | Llegadas = 7, atendidos = 0, estados para t                                                     | Simulación de colas               | Evolución del sistema usando FIFO                                                            |
| demo_capitulo4_panorama.cpp      | Recopilacion semana 4, pila=2, cola=10, base8=30071, balanceo=true, RPN, valor=2012, N=2, camino=5, banco=5/0 | Integración de técnicas           | Recopila y unifica estructuras, algoritmos en distintos problemas                                      |

Luego responde:

1. En demo_stack_queue, la parte de la salida que deja más clara la diferencia entre tope y frente es cuando se muestra el "Tope de la pila = 9" y el "Frente de la cola = 10". Esto resalta que el tope de la pila representa el último elemento agregado (LIFO), mientras que el frente de la cola representa el primer elemento agregado (FIFO). Además, al mostrar el "Elemento desapilado = 9" y el "Elemento desencolado = 10", lo resalta, ya que el elemento desapilado es el último en entrar a la pila, mientras que el elemento desencolado es el primero en entrar a la cola.
2. En demo_base_conversion, el observable que permite afirmar que las versiones recursiva e iterativa producen la misma representación es el resultado final de la conversión de 12345 en base 8, que es "30071". 
3. En demo_paren_rpn, la relación entre paréntesis balanceados, RPN y el valor final es que el balanceo de paréntesis es que la expresión tenga una apertura de paréntesis ( asociado a un cierre ) en la jerarquía correcta y los elimina, y pueda ser convertida a notación RPN. Y con la notación RPN, se puede obtener el valor final.
4. En demo_nqueens solutions se refiere al número de configuraciones válidas de reinas en el tablero que una reina no ataca a otra, checks se refiere al número de veces que el algoritmo verifica si una posición es válida para colocar una reina. 
5. Salida: demo_maze.cpp
```cpp
Medida del camino = 5
(1,1) (1,2) (1,3) (2,3) (3,3) 
```
La secuencia de coordenadas muestra el camino encontrado desde el punto de inicio (1,1) hasta el punto final (3,3) a través del laberinto y la longitud del camino. 

6. Ejemplo de salida: demo_bank.cpp
```cpp
t=5: [82] [8] [55]
t=6: [81,59] [7] [54]
t=7: [80,59] [6,95] [53]
```
Cada lista representa la cola de clientes en cada una de las tres cajas del banco en el instante t. Cada número dentro de las listas representa el tiempo restante de servicio para cada cliente en la cola.

7. Todas las saildas tienen aplicaciones o uso de estructuras, pero la que mejor muestra sería:
```cpp
Expresion en RPN = 0 ! 1 + 2 3 ! 4 + ^ * 5 ! 67 - 8 9 + - -
```
Porque muestra el resultado, mientras que en otros solo da observables o salidas poco explícitas de lo que está ocurriendo al aplicar las estructuras estudiadas.

#### Bloque 3 

1. Verifica los métodos empty, top, pop en Stack.
2. Verifica los métodos empty, front, dequeue en Queue.
3. Valida que la conversión recursiva e iterativa produzcan la misma representación en base 8 para el número 12345.
4. Valida que la función de verificación de paréntesis balanceados funciona correctamente. Para el primer y segundo caso detecta que es balanceado y en el tercer caso, que no es balanceado.
5. Valida que la expresión RPN sea correcta para el caso dado y que el resultado de la evaluación esté en un margen cercano a 2012, por errores de redondeo sería un resultado aproximado al correcto.
6. Valida que las soluciones encontradas para N=4 sean 2 y que se han obtenido 2 posiciones válidas.
7. Valida que existe un camino no vacío y que el frente es (1,1) y la cola es (3,3), que coincide con el inicio y fin de la ruta del laberinto.
8. Valida la correctitud de la mejor ventana, sea 2, la esperada.
9. 
- Para paréntesis agrega el caso donde no hay paréntesis.
- Para NQueens verifica la posición de una de las reinas en una de las soluciones.
- Para Maze prueba un laberinto sin camino posible.
- Para conversión de base, prueba con una base fuera de un rango válido y caputura la excepción.
10. Pasar pruebas solo indica que el código funciona para los casos específicos que se han probado, pero no garantiza que el resultado sea correcto para todos los casos. Ni sustituyen las definiciones formales, porque requiere de un análisis teórico.
11. Un error conceptual que podría aparecer es si los elementos están ordenados simétricamente y las operaciones de pila o cola se pueden confundir porque daría el mismo resultado.

#### Bloque 4 

Revisa:

- `Semana4/include/BaseConversion.h`
- `Semana4/include/Parentheses.h`
- `Semana4/demos/demo_base_conversion.cpp`
- `Semana4/demos/demo_paren_rpn.cpp`

Responde:

1. Residuo es el digito convertido en la base, pero almacenado en orden inverso en la pila, la pila al funcionar con lógica lifo nos devuelve en orden correcto lo que había sido almacenado en orden inverso y el cociente sirve para determinar la finititud del proceso.
2. Porque el algoritmo devuelve el resultado en orden inverso y para revertirlos a un orden correcto se debe usar una lógica lifo.
3. Usar una pila explícita permite un control directo de los elementos con push/pop y mayor espacio de memoria disponible.
4. divideParenthesis busca la apertura de un paréntesis y el correspondiente cierre y retorna el índice donde se cierra y usa ese índice para saber si la expresión está cerrada adecuadamente.
5. La limitación está en que la versión recursiva solo puede conocer la apertura y cierre de un solo tipo de separador y no múltiples al mismo tiempo.
6. Porque termina el bucle cuando el stack está vacío o el pop no retorna el par de cierre correcto.
7. La recursiva resulta más conveniente cuando se trabaja con un solo par de apertura-cierre, mientras que la iterativa extiende esa funcionalidad de forma natural para trabajar con múltiples pares simultáneamente.

Ejecuta pruebas propias con al menos cinco números y cuatro bases distintas para `toBaseRecursive` y `toBaseIterative`.

Registra en una tabla:

- Número
- Base
- Salida recursiva
- Salida iterativa
- ¿Coinciden?
- Comentario

##### Experimento 2

Construye una batería de al menos ocho expresiones para paréntesis, incluyendo:

- una vacía,
- una sin paréntesis,
- una correctamente anidada,
- una con desbalance,
- una con cruce incorrecto,
- una con varios tipos de delimitadores,
- una larga,
- una inventada por ti.

Para cada caso indica:

- resultado recursivo,
- resultado iterativo,
- si ambos coinciden,
- qué explica el caso.

#### Bloque 5 

Revisa:

- `Semana4/include/OperatorPriority.h`
- `Semana4/include/ExpressionEvaluator.h`
- `Semana4/demos/demo_paren_rpn.cpp`
- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`

Responde:

1. EvaluationResult guarda el valor final de evaluar la operación matemática y la expresión RPN.
2. Porque los espacios no alteran el resultado de la operación matemática y sirve para estandarizar la expresión.
3. isUnaryMinus detecta los casos si es una operación unaria o binaria, interpreta como unario si solo (número negativo) hay un número o representación de un número a la derecha u operador matemático y no a la izquierda, lo intrepreta como binario cuando hay además un número a la izquierda o un paréntesis de cierre.
4. El factorial es unario porque solo requiere un argumento e impone las restricciones de que sea un número entero positivo y este número (o representación) va antes del operador.
5. Porque cada vez que se procesa un operador se genera el rpn y se evalúa simultáneamente usando los operadores en la pila.
6. El operador de tope (<,>,=) evalúa la prioridad de la operación. Si es > es de mayor prioridad y debe evaluare, < es de menor prioridad y se apila y = hace pop porque procesa paréntesis.
7. Porque una expresión mal formada puede dar un comportamiento ambiguo o no definido, ya que las operaciones matemáticas son deterministas y deben ser siempre las mismas sin lugar a errores.
8. Una ventaja sería que no necesita procesarse por segunda vez y nos permite verificar y depurar la expresión RPN sin un tempo de procesamiento adicional.

##### Experimento 3

Propón y ejecuta al menos seis expresiones nuevas:

- dos válidas sin paréntesis,
- dos válidas con anidamiento,
- una con menos unario,
- una inválida.

Para cada una registra:

- expresión,
- RPN esperada,
- RPN obtenida,
- valor esperado u error esperado,
- valor obtenido o error observado,
- explicación breve.

##### Extensión opcional

Extiende el evaluador con un operador adicional elegido por ti.

La defensa debe incluir obligatoriamente:

- qué símbolo agregaste,
- su aridad,
- su prioridad,
- qué casos válidos probaste,
- qué caso inválido probaste,
- qué parte del código tuviste que modificar.

#### Bloque 6 

Revisa:

- `Semana4/include/Queen.h`
- `Semana4/include/NQueens.h`
- `Semana4/include/Maze.h`
- `Semana4/demos/demo_nqueens.cpp`
- `Semana4/demos/demo_maze.cpp`
- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`

Responde:

1. Cuando dos reinas comparten fila, columna o diagonal significa que están en conflicto.
2. La pila representa el orden por fila en el que las reinas fueron colocadas en el tablero para una solución válida.
3. El algoritmo avanza cuando encuentra una columna válida y retrocede a la fila anterior si no encontró una solución a nivel de columnas.
4. Porque checks cuenta cuantas iteraciones fueron necesarias para obtener una solución.
5. Cuando collectPlacement se hace falso ya no se guardan las posiciones de las reinas para la solución.
6. Son variables con nombres explicitos que representan los estados:
 - AVAILABLE: Camino no visitado.
 - BACKTRACKED: Camino sin salida ya visitado.
 - WALL: Un obstáculo
7. incoming es la dirección desde le que se llegó a una celda y outgoing la dirección que se va a tomar en el siguiente paso.
8. Porque necesita saber lo que se ha recorrido sino puede recorrer el mismo camino de forma ilimitada y entrar en un bucle infinito o recorrer las mismas celdas más de una vez.
9. El problema de las N-Reinas y laberintos comparten la idea del backtracking para solucionar el problema, mientras que al ser Maze un problema más complicado que admite diferentes caminos complejos requiere asignar de forma más explícita cada posición recorrida, mientras que en N-Reinas solo es necesario avanzar a nivel de columnas y deshacer los cambios a nivel de filas.

##### Experimento 4

Ejecuta `placeQueens(n)` para al menos cuatro valores de `n`.

Registra en una tabla:

- `n`
- número de soluciones
- número de `checks`
- ¿crece rápido o lento?
- comentario

Luego responde:

1. ¿Qué patrón observas en el crecimiento de `checks`?
2. ¿Por qué contar verificaciones no es lo mismo que contar soluciones?
3. ¿Dónde aparece la "poda" en este código, aunque no haya una estructura formal con ese nombre?

##### Experimento 5

Diseña al menos tres laberintos propios:

- uno con camino claro,
- uno sin salida,
- uno donde el algoritmo deba retroceder varias veces.

Para cada laberinto registra:

- grilla usada,
- coordenadas de inicio y destino,
- longitud del camino o ausencia de camino,
- evidencia de retroceso,
- interpretación.

#### Bloque 7 
Revisa:

- `Semana4/include/Queue.h`
- `Semana4/include/BankSimulation.h`
- `Semana4/demos/demo_bank.cpp`
- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`

Responde:

1. Representa una cola de Customer (clientes), almacena el tiempo que falta para atender un conjunto de clientes por ventanilla.
2. Compara el tamaño de las colas y toma la cola más corta, si hay empate toma la cola con el menor índice.
3. La simulación genera números pseudoaleatorios, al poner una semilla hacemos que los números aleatorios sean siempre los mismos para el mismo valor de semilla y poder tener resultados reproducibles.
4. totalServed debe ser menor o igual a totalArrivals porque  no pueden atenderse más clientes que los que llegan al banco.
5. Es un arreglo que almacena la simulación por cada paso de tiempo como cambian las tiempos en las colas, por ventanillas y la llegada o salida de clientes.
6. Porque las colas de espera funcionan bajo un funcionamiento LIFO, entran por la cola y salen por el frente, mientras que en una pila es FIFO, entra por la cima y sale el elemento que entró más recientemente.
7. Es un ejemplo práctico de una cola LIFO que modela el funcionamiento de una cola de espera, algo muy común del mundo real en el que se atiende según orden de llegada.
8. Dependiendo del cambio podría afectar al tiempo de espera, longitud de las colas, la cantidad de clientes que se atienden para un mismo periodo de tiempo.

##### Experimento 6

Ejecuta la simulación variando al menos tres parámetros:

- número de ventanillas,
- duración total,
- semilla.

Construye una tabla con:

- `nWin`
- `servTime`
- `seed`
- `totalArrivals`
- `totalServed`
- tamaño final de cada cola
- observación

Luego responde:

1. ¿Qué parámetro parece influir más en la congestión observable?
2. ¿Qué cambia cuando repites exactamente la misma semilla?
3. ¿Qué cambia cuando mantienes `nWin` y `servTime`, pero alteras la semilla?
4. ¿Qué evidencia usarías para defender que la cola más corta es una política razonable, aunque no necesariamente óptima?

#### Bloque 8 
