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

1. Residuo es el digito convertido en la base, pero almacenado en orden inverso en la pila, la pila al funcionar con lógica lifo nos devuelve en orden correcto lo que había sido almacenado en orden inverso y el cociente sirve para determinar la finititud del proceso.
2. Porque el algoritmo devuelve el resultado en orden inverso y para revertirlos a un orden correcto se debe usar una lógica lifo.
3. Usar una pila explícita permite un control directo de los elementos con push/pop y mayor espacio de memoria disponible.
4. divideParenthesis busca la apertura de un paréntesis y el correspondiente cierre y retorna el índice donde se cierra y usa ese índice para saber si la expresión está cerrada adecuadamente.
5. La limitación está en que la versión recursiva solo puede conocer la apertura y cierre de un solo tipo de separador y no múltiples al mismo tiempo.
6. Porque termina el bucle cuando el stack está vacío o el pop no retorna el par de cierre correcto.
7. La recursiva resulta más conveniente cuando se trabaja con un solo par de apertura-cierre, mientras que la iterativa extiende esa funcionalidad de forma natural para trabajar con múltiples pares simultáneamente.

##### Experimento 1

| Número | Base | Salida recursiva | Salida iterativa | ¿Coinciden? | Comentario |
|:---|:---:|:---:|:---:|:---:|---:|
| 5 | 2 | 101 | 101 | Sí | Conversión simple a binario de un número pequeño. |
| 15 | 2 | 1111 | 1111 | Sí | Todos los bits son 1|
| 31 | 8 | 37 | 37 | Sí | Conversión a base 8|
| 12345 | 8 | 30071 | 30071 | Sí | Conversión a base 8 de un número grande|
| 255 | 16 | FF | FF | Sí | La conversión se escribe en formato hexadecimal |
| 1024 | 16 | 400 | 400 | Sí | Potencia de 2 que produce una representación hexadecimal exacta. |
| 100 | 3 | 10201 | 10201 | Sí | Conversión a una base inusal, 3.|
| 999 | 7 | 2625 | 2625 | Sí | Conversión a una base inusal, 7.|

##### Experimento 2

Caso: Vacia
Expresion: ""
Iterativo balanceado: true
Recursivo balanceado: true
Iterativo = Recursivo: true
Una cadena vacía no contiene delimitadores que puedan desbalancearse.

Caso: Sin parentesis
Expresion: "2+3*4-5"
Iterativo balanceado: true
Recursivo balanceado: true
Iterativo = Recursivo: true
No existen delimitadores; la expresión se considera balanceada.

Caso: Correctamente anidada
Expresion: "((a+b)*(c-d))"
Iterativo balanceado: true
Recursivo balanceado: true
Iterativo = Recursivo: true
Todos los paréntesis se abren y cierran en el orden correcto.

Caso: Desbalance
Expresion: "((a+b)"
Iterativo balanceado: false
Recursivo balanceado: false
Iterativo = Recursivo: true
Falta un paréntesis de cierre, por lo que queda un delimitador abierto pendiente.

Caso: Cruce incorrecto
Expresion: "([)]"
Iterativo balanceado: false
Recursivo balanceado: true
Iterativo = Recursivo: false
La versión iterativa detecta el error, mientras que la versión recursiva presenta un comportamiento incorrecto.

Caso: Varios delimitadores
Expresion: "{[(a+b)*c]+(d/e)}"
Iterativo balanceado: true
Recursivo balanceado: true
Iterativo = Recursivo: true
Los delimitadores `()`, `[]` y `{}` están correctamente anidados y emparejados.

Caso: Larga
Expresion: "((({[a+b]*(c+d)})-(e/f))+((g*h)-i))"
Iterativo balanceado: true
Recursivo balanceado: true
Iterativo = Recursivo: true
Verifica que ambos algoritmos funcionen correctamente con varios niveles de anidación.

Caso: Inventada
Expresion: "[({(x+y)*z}-((m-n)/p))]"
Iterativo balanceado: true
Recursivo balanceado: true
Iterativo = Recursivo: true
Caso complejo creado para probar múltiples niveles y tipos de delimitadores.

#### Bloque 5 

1. EvaluationResult guarda el valor final de evaluar la operación matemática y la expresión RPN.
2. Porque los espacios no alteran el resultado de la operación matemática y sirve para estandarizar la expresión.
3. isUnaryMinus detecta los casos si es una operación unaria o binaria, interpreta como unario si solo (número negativo) hay un número o representación de un número a la derecha u operador matemático y no a la izquierda, lo intrepreta como binario cuando hay además un número a la izquierda o un paréntesis de cierre.
4. El factorial es unario porque solo requiere un argumento e impone las restricciones de que sea un número entero positivo y este número (o representación) va antes del operador.
5. Porque cada vez que se procesa un operador se genera el rpn y se evalúa simultáneamente usando los operadores en la pila.
6. El operador de tope (<,>,=) evalúa la prioridad de la operación. Si es > es de mayor prioridad y debe evaluare, < es de menor prioridad y se apila y = hace pop porque procesa paréntesis.
7. Porque una expresión mal formada puede dar un comportamiento ambiguo o no definido, ya que las operaciones matemáticas son deterministas y deben ser siempre las mismas sin lugar a errores.
8. Una ventaja sería que no necesita procesarse por segunda vez y nos permite verificar y depurar la expresión RPN sin un tempo de procesamiento adicional.

##### Experimento 3

Caso: Valida sin parentesis 1
Expresion: 3+4*5
RPN: 3 4 5 * +
Valor: 23
Valida: true
La multiplicación tiene mayor precedencia que la suma.

Caso: Valida sin parentesis 2
Expresion: 20/5+7
RPN: 20 5 / 7 +
Valor: 11
Valida: true
La división se evalúa antes que la suma.

Caso: Valida con anidamiento 1
Expresion: (2+3)*(4+5)
RPN: 2 3 + 4 5 + *
Valor: 45
Valida: true
 Los paréntesis fuerzan la evaluación previa de ambas sumas.

Caso: Valida con anidamiento 2
Expresion: ((1+2)*(3+4))-5
RPN: 1 2 + 3 4 + * 5 -
Valor: 16
Valida: true
Se valida el manejo correcto de anidamiento y precedencia.

Caso: Menos unario
Expresion: -(3+4)*2
Valida: false
Error: faltan operandos para el operador binario
No soporta correctamente el menos unario y lo interpreta como operador binario.

Caso: Invalida
Expresion: (3+4*5
Valida: false
Error: orden de operadores invalido
La expresión está mal formada porque falta un paréntesis de cierre.

##### Extensión opcional

- Se agregó: El operador modulo %
- Es un operador binario.
- Tiene la misma prioridad que la multiplicación.
- Se modificaron las funciones isOperatorChar, calcu, isUnaryMinus y la tabla de prioridares en OperatorPriority.h
- Caso válido probado: 7%2 == 1
- Caso invállido: 5%, error

#### Bloque 6 

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

| n  | Número de soluciones | Número de checks | ¿Crece rápido o lento? | Comentario                                                                     |
| :--- | :---: | :---: | :---: | ---: |
| 7  |                  40 |          9297 | Rápido                 | Ya se realizan miles de verificaciones para encontrar pocas soluciones.        |
| 9  |                 352 |        243009 | Muy rápido             | Las configuraciones ya bordean los cientos de miles |
| 11 |                2680 |        7416541 | Muy rápido             | Se exploran millones de configuraciones parciales.                             |
| 13 |               73712 |      292182579 | Extremadamente rápido  | Se requieren cientos de millones de verificaciones para completar la búsqueda. |

1.
- De 7 a 9 las configuraciones crecen en aproximadamente 27 veces.
- De 9 a 11 las configuraciones crecen en aproximadamente 30 veces.
- De 11 a 13 las configuraciones crecen en aproximadamente 39 veces.
Se puede observar un patrón de crecimiento exponencial.
2. El número de verificaciones solo indica la cantidad de veces que se colocaron las reinas incluso en configuraciones que no daban soluciones.
3. La poda aparece cuando hay conflicto entre reinas se detiene la búsqueda y se hace backtracking.

##### Experimento 5

"#####",
"#...#",
"#...#",
"#...#",
"#####"
Caso: Camino claro
Inicio: (1,1)
Destino: (3,3)
Longitud del camino: 5
Retrocesos detectados: 0
Interpretacion: El algoritmo encontro la ruta sin necesidad de retroceder.

"#####",
"#.#.#",
"#####",
"#.#.#",
"#####"
Caso: Sin salida
Inicio: (1,1)
Destino: (3,3)
Camino: NO EXISTE
Retrocesos detectados: 1
Interpretacion: No existe ruta entre inicio y destino.

"#########",
"#.....#.#",
"#####.#.#",
"#.....#.#",
"#.#####.#",
"#...#...#",
"#########"
Caso: Con retrocesos
Inicio: (1,1)
Destino: (5,7)
Camino: NO EXISTE
Retrocesos detectados: 15
Interpretacion: No existe ruta entre inicio y destino.

#### Bloque 7 

1. Representa una cola de Customer (clientes), almacena el tiempo que falta para atender un conjunto de clientes por ventanilla.
2. Compara el tamaño de las colas y toma la cola más corta, si hay empate toma la cola con el menor índice.
3. La simulación genera números pseudoaleatorios, al poner una semilla hacemos que los números aleatorios sean siempre los mismos para el mismo valor de semilla y poder tener resultados reproducibles.
4. totalServed debe ser menor o igual a totalArrivals porque  no pueden atenderse más clientes que los que llegan al banco.
5. Es un arreglo que almacena la simulación por cada paso de tiempo como cambian las tiempos en las colas, por ventanillas y la llegada o salida de clientes.
6. Porque las colas de espera funcionan bajo un funcionamiento LIFO, entran por la cola y salen por el frente, mientras que en una pila es FIFO, entra por la cima y sale el elemento que entró más recientemente.
7. Es un ejemplo práctico de una cola LIFO que modela el funcionamiento de una cola de espera, algo muy común del mundo real en el que se atiende según orden de llegada.
8. Dependiendo del cambio podría afectar al tiempo de espera, longitud de las colas, la cantidad de clientes que se atienden para un mismo periodo de tiempo.

##### Experimento 6

| nWin | servTime | seed  | totalArrivals | totalServed | Tamaño final de cada cola | Observación |
|:---|:---:|:---:|:---:|:---:|:---:|---:|
| 2 | 10 | 12345 | 5 | 0 | [3, 2] | Pocas ventanillas. Se forman colas rápidamente y ningún cliente termina de ser atendido durante la simulación. |
| 3 | 10 | 12345 | 7 | 0 | [3, 2, 2] | Al agregar una ventanilla llegan más clientes, pero aún no se completa ningún servicio. |
| 5 | 10 | 12345 | 10 | 1 | [2, 2, 2, 2, 1] | Más ventanillas distribuyen mejor la carga y permiten completar al menos una atención. |
| 3 | 20 | 12345 | 15 | 1 | [5, 5, 4] | Una simulación más larga genera más llegadas y colas considerablemente más grandes. |
| 3 | 10 | 54321 | 8 | 0 | [3, 3, 2] | Cambiar la semilla modifica el patrón de llegadas, aunque el comportamiento global es similar. |
| 4 | 15 | 98765 | 13 | 0 | [4, 3, 3, 3] | Con más tiempo y cuatro ventanillas las llegadas se reparten de forma relativamente equilibrada entre las colas. |

1. El parámetro que más influye en la congestión observable es la duración de la simulación, porque hay más generación de llegadas.
2. No cambia nada, porque se vuelve generar el mismo número pseudoaleatorio.
3. Cambia la cantidad de clientes que llegan.
4. La evidencia es que los clientes aparecen relativamente equilibradas entre las ventanillas.

Por ejemplo:
[3,2,2]
[2,2,2,2,1]
[4,3,3,3]
Ninguna cola concentra una cantidad excesiva de clientes mientras otras permanecen vacías.

#### Bloque 8 

- La elección de una pila o cola dependerá del tipo de problema a resolver, su implementación explícita permite un mayor control y mayor flexibilidad en el uso de recursos respecto a una implícita.
- Para evaluación de expresiones el uso de las pilas es más adecuado porque facilita el uso de operadores binarios/unarios y precedencia.
- El backtracking es un mecanismo necesario para recordar un camino no exitoso recorrido cuando hay múltiples posibilidades para resolver el problema.
- En las simulaciones las colas modelan procesos de espera. 
- Una correctitud teórica se valida con pruebas sobre salidas esperadas.
- Un problema de conversión de base solo requiere de un uso de pilas, mientras que paréntesis agrega anidamiento y uso de una pila explícita para manejar diferentes pares, el problema de las N-Reinas extiende el uso de pilas con el uso de backtracking mientras que el laberinto requiere una implementación más detallada de la pila para recordar los caminos recorridos y un banco requiere el uso de colas, un orden muy diferente a las operaciones LIFO usadas para resolver los problemas anteriores.
