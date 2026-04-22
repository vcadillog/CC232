### Integrantes: 
- Victor Hugo Cadillo Gutierrez, 20255514D

### Bloque 0

### Demo:
```
victor@victor-desktop:~/clases/algoritmos/CC232-pc/semana2$ ./build/sem2_demo_array_basico
array.length = 5
contenido: 10 20 30 40 50
antes de la asignacion, b[0] = -1
despues de b = a, b.length = 5
b: 10 20 30 40 50
nota: esta version de array usa una asignacion por transferencia de ownership.
```
### Prueba pública:
```
victor@victor-desktop:~/clases/algoritmos/CC232-pc/semana2$ ./build/sem2_test_public_cap2
```

### Bloque 1

1. Memoria contigua es cuando el uso de la memoria se hace de forma consecutiva
2. Acceder a A[i] es de costo O(1) porque es una estructra indexada.
3. La diferencia entre size y capacity, size toma el espacio usado y capacity es la memoria física reservada.
4. Porque trabaja con arrays y los arrays tiene un espacio de memoria reservada fijo, entonces no se puede modificar directamente, para redimensionar se tiene que crear un nuevo array y copiar los contenidos del array original.
5. Porque para agregar un elemento al final solo necesitaría buscar el último elemento con el size y luego insertar el nuevo elemento con size+1.
6. Hacen cosas similares, pero tienen una interfaz diferente, ambos agregan elementos, los buscan, redimensionan y limpian, pero DengVector implementa funciones más específicas como reducir o aumentar el tamaño o aplicar una función a todos los elementos del arreglo.
7. FastArrayStack implementa una lógica para agregar o quitar elmentos mediante una copia directa de una porción usando funciones de una librería STL optimizada, copy y copy_backward.
8. La idea espacial es agregar bloques al final cada vez de el tamaño del bloque final más uno, esto para reducir el uso de memoria con respecto a implementaciones más simples como ArrayStack o FastArrayStack.
9. El diseño de RootishArrayStack hace que aumenten en 1 cada bloque, para que necesite cada vez menos inserciones de bloques a medida que el arreglo crezca.
10. Las tres implementaciones tienen el mismo costo temporal, costo amortizado, sin embargo en el caso de ArrayStack y FastArrayStack la implementación usando librerías optimizadas hace que la implementación sea mejor, tienen el mismo costo espacial y el caso de RootishArrayStack tiene un costo espacial menor, porque a diferencia de los otros que duplican el espacio físico rootisharraystack lo hace de manera adaptativa según el tamaño actual del arreglo pero a costo de una mayor complejidad en la implementación.

### Bloque 2

TODO: Agregar tabla
Construyan una tabla con cuatro columnas:

- Archivo
- Salida u observable importante
- Idea estructural
- Argumento de costo o espacio

1. La longitud del array se declara al momento de crear el array, y la implementación del array reemplaza la operación de asignación con operator= para primero liberar la memoria asignada al array y sobreescribir la longitud y desreferencia el nuevo array.
2. Todas las operaciones realizan desplazamientos, push_back llama a add para el elemento final en específico y remove elimina el elemento i y desplaza todo a la izquierda. El que mostraría mejor los desplazamientos sería la operación 3 "add(1,15)" ya que desplaza los elementos a la derecha y luego inserta el valor.
3. En FastArrayStack los desplazamientos se hacen con add y la implementación de add se realiza con el STL copy_backward; ya optimizado; en lugar de un for loop para copiar los elementos a la derecha.
4. print_location nos indica mejor el mapeo entre indice lógico a bloque y offset.
5. El observable size nos permite saber cuándo capacity crece, cuando size = capacity, lo que hace internamente insert es llamar expand para duplicar el valor de capacity actual. remove también llama a una función que altera capacity; shrink; pero nunca se activa ya que no cumple la condición.
6. El demo nos muestra como el STL vector realiza el redimensionamiento cuando se cumple la misma condición que en DengVector, si size=capacity, entonces duplica el valor de capacity.
7. demo_arraystack_explicado muestra mejor el costo amortizado de los desplazamientos y demo_deng_vector muestra mejor el cambio del espacio físico cuando cambia size.

### Bloque 3

1. La prueba pública valida las operaciones size, get y remove, concuerden con los valores asignados con add en ArrayStack.
2. La prueba pública valida las operaciones size, get y remove, concuerden con los valores asignados con add en FastArrayStack.
3. La prueba pública valida las operaciones size, get y remove, concuerden con los valores asignados con add en RootishArrayStack.
4. Demuestra la correctitud de las clases Array.
5. No garantiza que todas las entradas produzcan una salida correcta.
6. En la prueba de stress lo que hace es validar que size coincida con la dimension esperada después de redimensionamientos de incremento y eliminación sucesivas.
7. Porque pasar una prueba solo determina que para una entrada se obtenga la salida esperada, no altera el invariante porque es una propiedad matemática o lógica del problema y la complejidad está relacionada a la implementación de la solución y no al resultado.

### Bloque 4

1. _size nos indica el espacio lógico usado por el array, _capacity nos indica el espacio físico reservado para el array y _elem es un array que almacena los valores del array.
2. expand se ejecuta cuando _size==_capacity.
3. Insert necesita desplazar elementos porque cuando se inserta un valor este ocupa un espacio del array y si no es un valor al final del array, tiene que sobreescribir los valores contiguos del array con el valor anterior para insertar un valor en el espacio deseado.
4. La función sobrecargada con los argumentos lo y hi elimina los valores del tramo [lo,hi] del array, mientras que la función con un solo argumento r elimina solo el valor en la posición r del array, esto lo hace llamando a la función sobrecargada solo que en un tramo [r,r+1], al hacer las eliminaciones se desplaza y reduce el array.
5. La evidencia de copia profunda se da porque al escribir los valores de copia nos da los valores después de sumarle 1, mientras que asignado no fue modificado por esa suma más 1 y nos retornó lo almacenado anteriormente multiplicado por 2. 
6. traverse es una buena función didáctica porque nos permite aplicar cualquier tipo de función a todos los elementos que contiene el array sin modificar el ADT.
7. Nos permite entender el funcionamiento interno, manejo de recursos y control de un array.

### Bloque 5

1. La representación del array se hace en pequeños sub arrays que van tomando tamaños de forma creciente (bloques) y se asignan los elementos del array en los bloques de forma contigua.
2. Porque los bloques aumentan de tamaño en forma de una sucesión de 1 a r que incrementa en uno y la suma total de la sucesión se calcula como r*(r+1)/2.
3. i2b nos permite determinar a que bloque pertenece el elemento i del array.
4. locate nos retorna un par que indica el número del bloque y el indice respecto al bloque que tiene el elemento de indice i del array.
5. ArrayStack puede tener hasta un espacio reservado igual al doble a lo requerido, mientras que RootishArrayStack solo tendrá un bloque de tamaño r libre como máximo, de la fórmula r*(r+1)/2 = n, siendo n el espacio total reservado, de la fórmula se puede ver que se gana en espacio cuando la cantidad de bloques es mayor a 3 o un espacio reservado mayor igual a 10.
6. Se mantiene size, get, set, add, remove y clear.
7. En lo personal es más complicado defender el mapeo debido a la cantidad de fórmulas a recordar que se usa para convertir los índices lógicos a índice de bloque.

### Bloque 6

1. operator[] sobreescribe la operación de obtención de elemento por índice [] y nos permite hacer un assert que verifique que el ingreso del índice sea válido, solo se permite valores positivos y menores a _size.
2. find(e) busca elementos igual a e desde el último elemento en el array (indice _size) hacia atrás y si lo encuentra nos retorna el índice y si no nos retorna -1. Si hay más de dos elementos iguales nos retorna la primera coincidencia desde el final del array.
3. traverse aplica la misma función sobre cada uno de los elementos del array.
4. 
