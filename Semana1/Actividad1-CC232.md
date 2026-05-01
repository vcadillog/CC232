### Integrantes: 
- Victor Hugo Cadillo Gutierrez, 20255514D

## BLOQUE 1

1. Un problema es algo a ser resuelto, un algoritmo es una secuencia de procedimientos logicos para resolver un problema, implementacion es la forma explicita de resolver un problema, un ADT es la representacion abstractas de las funcionalidades de una estructura de datos.
2. El observable que conecta correctitud y costo en bubble_sort es el número de comparaciones (comparisons) realizadas.
3. power divide el problema al dividir el exponente a la mitad e itera sobre el resultado, mientras que la versión ingenua itera sobre el exponente completo. 
4. El resultado de una implementación puede ser correcto, pero ser impráctico, para el caso de Fibonnaci vuelve a calcular todos los valores por cada recursion, generando cálculos redundantes.
5. En countones el valor númerico no coincide con la entrada, porque la entrada es una representación binaria del número.
6. Porque una interfaz define un contrato, pero no como se implementa. intsequence es un adt de un array y vectorsequence trabaja con un STL vector.

## BLOQUE 2

| archivo | salida u observable importante | idea algoritmica | argumento de costo |
| --- | --- | --- | --- |
| demo_bubblesort.cpp | comparaciones = 14<br>intercambios = 7<br>ultimo swap = 0 | el sufijo despues del ultimo intercambio ya queda ordenado. | el número de comparaciones (comparisons) realizadas. |
| demo_power.cpp | powerBF(3, 5) = 243<br>power(3, 5)   = 243<br>power2BF_I(5) = 32<br>power2_I(5)   = 32<br>power2BF(5)   = 32<br>power2(5)     = 32 | power divide el problema al dividir el exponente a la mitad| El argumento de costo es O(log n) para la versión optimizada, mientras que la versión ingenua es O(n). | 
| demo_fibonacci.cpp | fibI(10)      = 55<br>fib(10)       = 55<br>fib(10, prev) = 55, prev = 34<br>Primeros 8 Fibonacci desde la clase Fib: 0 1 1 2 3 5 8 13 | El crecimiento de la función fib se vuelve exponencial debido a las llamadas recursivas redundantes. | La versión recursiva no optimizada tiene costo O(2^n), mientras que la versión iterativa es de costo O(n). |
| demo_countones.cpp | x = 361 = 0000000101101001<br>countOnes1(x) = 5<br>countOnes2(x) = 5 | una version elimina el ultimo 1, la otra agrupa bits por bloques. | Countones1 tiene costo O(logn) y countOnes2 tiene costo O(1) |

1. En demo_bubblesort.cpp, el número de comparaciones (comparisons) realizadas sirve para defender costo, ya que muestra cuántas veces itera el algoritmo.
2. En demo_power.cpp, la mejora es entre powerBF(3, 5) y power(3, 5), power al usar el enfoque de dividir y conquistar reduce el número de multiplicaciones necesarias, lo que se muestra un costo menor O(log n) vs O(n).
3. En demo_fibonacci.cpp, el crecimiento que se vuelve defendible es el de la versión iterativa fibI con costo O(n) contra la versión recursiva no optimizada (fib) que tiene un costo O(2^n) por volver a calcular lo mismo varias veces.
4. En demo_countones.cpp, el ejemplo que ayuda más a distinguir valor numérico de tamaño en bits es el número x = 361, representado en binario como 0000000101101001 aquí es evidente el valor numérico no concide con el tamaño de entrada en bits.

## BLOQUE 3

1. sum, power, fib, la cantidad de elementos de fib coincida con la salida.
2. Demuestra comportamientos esperados del codigo para ciertos casos.
3. No demuestra que la respuesta sea correcta, solo que el código se comporta de cierta manera esperada.
4. 

 - 40. O(1): Es constante, O(logn) es logarítmico, O(n) es lineal, O(n^2) es cuadrático y O(2^n) es exponencial. A medida que n aumenta el costo crece de forma significativa.
 - 41. Porque cambios pequeños en valores grandes de n tiene salidas de O(f(n)) más grandes.
 - 42. Porque al trabajar con tamaños de entrada maś grandes tienen impacto mayor en los costos de ejecución que entradas pequeñas, crecen de forma f(n). 
 - 43. Porque los costos se vuelven exponenciales, ya sean temporales o memoria, aunque las capacidades de memoria sean grandes ahora, los límites temporales no podrían ser asumidas.
 - 44. La jerarquía de complejidades se refiere a la clasificación de algoritmos según su crecimiento asintótico. A medida que la complejidad aumenta, el costo de ejecución también lo hace.

## BLOQUE 4

1. demo_const_refs.cpp trabaja con un vector de enteros, hace una suma de sus valores después de leerlos y agrega un valor directamente o sobre una copia del mismo.
2. bench_vector_growth.cpp muestra que sin reserve, el vector tiene que redimensionarse varias veces a medida que se va llenando el vector, mientras que con reserve se asigna un espacio libre para ser llenado posteriormente lo que hace que las inserciones tengan menor costo futuro.
3. push_back se realiza al final de un vector y es una operación eficiente, ya que simplemente agrega un nuevo elemento con costo O(1), pero si el vector no tiene suficiente capacidad, el vector necesita redimensionarse para acomodar el nuevo elemento, entonces se vuelve O(n) debido a la necesidad de copiar todos los elementos existentes a un nuevo vector, mientras que insert(begin) copia todos los elementos y los desplaza un espacio lo que introduce un costo O(n) e insert(middle) aunque también copia elementos, solo lo hace parcialmente para la mitad de elementos y tiene un costo O(n/2) lo que se simplifica a O(n) en notación asintótica.
4. Que el costo para operaciones con datos contiguos es menor que datos no contiguos, recorrer en un vector es más eficiente que recorrer una lista y a la vez más eficiente que acceder a elementos aleatorios de un vector.

## BLOQUE 5

1. Elegir el algoritmo adecuado, verificar que el programa sea correcto y luego medir el rendimiento.
2. reserve evita múltiples copias, nth_element que no siempre es necesario reordenar, partial_sort que solo importan los primeros k elementos y lower_bound permite hacer consultas con bajo costo en un vetor ordenado.
3. Produce evidencia cuantitativa sobre las optimizaciones, sanitazers para evaluar rendimiento y correctitud. 
4. El entorno de desarrollo puede tener limitaciones sobre sanitizers y profiling, al no generar las salidas deseadas o requerir mucho más ajuste.
5. Porque se analiza los comportamientos de forma cuantitativa, no una demostración formal de que los algortimos son correctos.

## BLOQUE 6

Se pasa de demostrar que una solución es correcta, a comparar soluciones correctas usando evidencia empírica para decidir la más eficiente.
- La especificación se usa como referencia en la comparación de diferentes implementaciones.
- La correctitud se demuestra mediante invariantes y demostraciones formales, aquí se usa sanitizers para encontrar evidencia de esa correctitud.
- El costo pasa de un análisis teórico a uno práctico a través de benchmarks.
- Se observa como la representación de memoria de estructuras como vectores impactan en el redimiento de una implementación.
- La advertencia metodológica nos menciona que el entorno de trabajo puede alterar la respuesta al no generar reportes reproducibles en otros entornos.

#### Autoevaluación breve
- Qué podemos defender con seguridad: Podemos identificar el costo de un algoritmo, la correctitud.
- Qué todavía confundimos: No identificar bien la diferencia entre tamaño de entrada y valor numérico.
- Qué evidencia usaríamos en una sustentación: Observables, comparaciones y benchmarks.
