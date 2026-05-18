## Solucionario Examen Parcial - CC232
## Versión A

### Estudiante
- Nombre: Victor Hugo Cadillo Gutierrez
- Código: 20255514D

### Indice
- [Pregunta 1](#target-item1)
- [Pregunta 2](#target-item2)
- [Pregunta 3](#target-item3)
- [Pregunta 4](#target-item4)
- [Pregunta 5](#target-item5)
- [Pregunta 6](#target-item6)
- [Pregunta 7](#target-item7)

<a name="target-item1"></a>
### Pregunta 1

#### a)

La parte que pertenece al ADT es aquella que define que hace la estructura:
Ejemplo:
```cpp
public:
    int size() const;
    T get(int i) const;
```
La parte que pertenece a la implementación no está definida, pero menciona que hay dos tipos de implementación, una por arreglo dinámico y otro con lista doblemente enlazada.
Ejemplo para lista doblemente enlazada:
```cpp
    int size(){
        return n; //n es el tamaño de la lista enlazada
        }
```
Ejemplo para arreglo dinámico:
```cpp
    T get(int i){
        return a[i]; //a es el arreglo de la estructura
        }
```

#### b)
 
Costos en el peor caso
| Implementación | get | set | add | remove |
| :--- | :---: | :---: | :---: | ---: |
| I | O(1) | O(1) | O(n) | O(n) |
| II | O(n) | O(n) | O(1) | O(1) |

No hay costos amortizados para estructuras de listas doblemente enlazadas (implementación II), solo para arreglos (Implementación I).
El costo amortizado del redimensionamiento es:
| add | remove |
| :--- | ---: |
| O(1) | O(1) |

#### c)

Implementación I: Un invariante es que el tamaño del arreglo nunca supera a la cadacidad.
Implementación II: El nodo centinela dummy siempre está conectado al inicio y al final de la lista doblemente enlazada.

Una mala implementación podría romper la invariante, para:
Implementación I: Si no se detecta que size es igual capacity y no se hace redimensionamiento, entonces se puede romper la invariante. 
Implementación II: Si se elimina un nodo y deja una lista vacía y luego no se reconecta correctamente los punteros de dummy a sí mismo como inicio y final de la lista.

#### d)

Una lista enlazada no garantiza que add(i,x) sea O(1) porque esta solo conoce la posición inicial y final, pero no conoce la posición i y tiene que buscarla, lo que cuesta O(n) en el peor caso, pero la acción de insertar cuesta O(1).

<a name="target-item2"></a>
### Pregunta 2

#### a)

```cpp
//Estado inicial:
    ans = 1
    p = 3
    n = 13
//Después de la iteración 1 y antes de la iteración 2:
    ans = 3
    p = 3*3 = 9
    n = 6
//Después de la iteración 2 y antes de la iteración 3:
    ans = 3
    p = 9*9 = 81
    n = 3
//Después de la iteración 3 y antes de la iteración 4:
    ans = 3*81 = 243
    p = 81*81 = 6561
    n = 1
//Después de la iteración 4 e iteración final:
    ans = 243*6561 = 1594323 // ans == 3^13
    p = 6561*6561 = 43046721
    n = 0
```

#### b)
Una invariante de ciclo es que: ans*p^n = 3^13 (respuesta). 

#### c)
La función variante determina la finititud del problema, es n que es divido por 2 en cada iteración hasta que se vuelve 0 y termina el algoritmo.

#### d)
La complejidad temporal al dividirse por 2 en cada iteración es de O(logn)
```cpp
    n = 13 //inicial
    n = 6  //después de iteracion 1
    n = 3  //después de iteracion 2
    n = 1  //después de iteracion 3
    n = 0  //después de iteracion 4 , fin
```
#### d)
Una implementación ingenua es aquella que al final de cada iteración multiplica la respuesta parcial por la base e itera un total de n veces.

```cpp
long long power(long long a, int n) {
    long long ans = 1;
    while (n>0){
        ans = ans*a;
        n--;
        }
    return ans;
}
```
power y fastPower tienen la misma respuesta, pero power al iterar un total de n veces tiene un costo asintótico O(n), mayor al de la implementación de divide y vencer que es O(logn).

<a name="target-item3"></a>
### Pregunta 3

#### a)

```cpp
//Estado inicial:
    _size = 0
    _capacity = 1
//Llamada 1:

    //Antes:
    _size = 0
    _capacity = 1
    _size == _capacity -> Falso 
    no redimensiona
    //Elementos copiados: 0

    //Después:
    _size = 1
    _capacity = 1


//Llamada 2:

    //Antes:
    _size = 1
    _capacity = 1
    _size == _capacity -> Verdadero
    redimensiona
    //Elementos copiados: 1

    //Después:
    _size = 2
    _capacity = 2


//Llamada 3:

    //Antes:
    _size = 2
    _capacity = 2
    _size == _capacity -> Verdadero 
    redimensiona
    //Elementos copiados: 2

    //Después:
    _size = 2
    _capacity = 4

```

#### b)
Dada la condición de redimensionamiento que _size = _capacity y capacity crece al doble después de cada redimensionamiento entonces veamos la tabla:
| Operación | Antes (tamaño, capacidad) | Después (tamaño, capacidad) | Redimensiona |
| :--- | :---: | :---: | ---: |
| Inicial   | 0, 1| -| -|
| pushback1 | 0, 1| 1, 1| No|
| pushback2 | 1, 1| 2, 2| Sí|
| pushback3 | 2, 2| 3, 4| Sí|
| pushback4 | 3, 4| 4, 4| No|
| pushback5 | 4, 4| 5, 8| Sí|
| pushback6 | 5, 8| 6, 8| No|
| pushback7 | 6, 8| 7, 8| No|
| pushback8 | 7, 8| 8, 8| No|
| pushback9 | 8, 8| 9, 16| Si|

Para n redimensiona cada 2^m+1<n, m es entero, m>=0 y n>1:
Copia = 2^0 + 2^1 + 2^2 + ... + 2^m
Esto es:
$$
\Copias = 2^(m+1)-1
$$

El peor caso es con 2^m = n, para
$$
\Copias <= 2n - 1
$$

#### c)

De la cota de copias tenemos que el costo del total de inserciones es O(n), aunque algunos pushBack tenga costo de copiar O(n), este se distribuye entre los n pushback, entoces el costo amortizado es O(n/n) = O(1). 

#### d)

Porque hay un rango de _capacity/4 a _capacity/2 en el que no se ejecutará la reducción, veamos si desde el pushback 9 hacemos removeLast.

| Operación | Antes (tamaño, capacidad) | Después (tamaño, capacidad) | Redimensiona |
| :--- | :---: | :---: | ---: |
| pushback9 | 8, 8| 9, 16| Si|

El removeLast solo ejecutará shrink cuando size<16/4=4 y a la vez no ejecutará incremento de capacidad hasta que _size=16, eso da para este caso un margen de size 4 a 15 sin llamar a redimensionamientos, este margen es proporcional al valor de _capacity.

#### e)

Sea la condición de shrink, _size<_capacity/K; esto causará oscilación para valores de 0<K<=2, veamos con el límite _capacity/2, veamos el caso pushback 9 nuevamente:

| Operación | Antes (tamaño, capacidad) | Después (tamaño, capacidad) | Redimensiona |
| :--- | :---: | :---: | ---: |
| pushback9 | 8, 8| 9, 16| Si|

Aquí se incrementó el _capacity, pero si hacemos un removeLast _size=8, esto hará que en el siguiente pushback o removelast se incremente o reduzca _capacity, lo que nos daría un comportamiento oscilatorio, pero si se usa un condicional <= en su lugar oscila inmediatamente, sin tener que esperar una operación adicional.

<a name="target-item4"></a>
### Pregunta 4

#### a)

m=8, j=5, n=4
i(lógico) = 0 -> j(físico)=5mod8=5 

| --- |D |- |- |- |- |A |B|C |
| :--- |:---:| :---: | :---: |:---: | :---: | :---: | :---: | ---: |
| Lógico|3|4 |5 |6 |7 |0 |1 |2 |
| Físico|0 |1 |2 |3 |4 |5 |6 |7 |

#### b)

add(0,X)
| --- |C |D |- |- |-|X |A |B |
| :--- |:---:| :---: | :---: |:---: | :---: | :---: | :---: | ---: |
| Lógico|3|4 |5 |6 |7 |0 |1 |2 |
| Físico|0 |1 |2 |3 |4 |5 |6 |7 |

add(3,Y)
| --- |Y|C |D |- |-|X |A |B |
| :--- |:---:| :---: | :---: |:---: | :---: | :---: | :---: | ---: |
| Lógico|3|4 |5 |6 |7 |0 |1 |2 |
| Físico|0 |1 |2 |3 |4 |5 |6 |7 |

remove(5)
| --- |Y|C |- |- |-|X |A |B |
| :--- |:---:| :---: | :---: |:---: | :---: | :---: | :---: | ---: |
| Lógico|3|4 |5 |6 |7 |0 |1 |2 |
| Físico|0 |1 |2 |3 |4 |5 |6 |7 |

add(2,Z)
| --- |B|Y|C |- |-|X |A |Z |
| :--- |:---:| :---: | :---: |:---: | :---: | :---: | :---: | ---: |
| Lógico|3|4 |5 |6 |7 |0 |1 |2 |
| Físico|0 |1 |2 |3 |4 |5 |6 |7 |

#### c)

Porque al comparar el índice con los extremos más corto o largo nos reducirá el número de elementos que debe desplazarse al hacer inserciones o eliminaciones si elegimos el más corto, siempre que este no esté en el medio.

#### d)

Si el tamaño del arreglo es de n y el índice físico es i, este devide el arreglo en dos partes 
| --- |A|B|C |D|... |J|K |L |M |
| :--- |:---:| :---: |:---:| :---: |:---: | :---: | :---: | :---: | ---: |
| Lógico|0|1 |2 |3| i|n-3 |n-2 |n-1 |n |

Lo divide en dos:
| --- |A|B|C |D|... |
| :--- |:---:| :---: |:---:| :---: |---: |
| Lógico|0|1 |2 |3| i|

Tamaño: i

| --- |...|J|K |L|M |
| :--- |:---:| :---: |:---:| :---: |---: |
| Lógico|i|n-3 |n-2 |n-1| n|

Tamaño: n-i

Entonces el costo de mover los elementos es O(min{i,n-i}) y O(1) es el de insertar en el elemento, en total el costo de add(i,x) es O(1+min{i,n-i})

#### e)

Implementar un ArrayStack es más simple que un ArrayDeque, pero pierde la capacidad de insertar en ambos extremos con costo O(1), en ArrayStack solo insertar al final tiene costo O(1), al inicio requiere de desplazar O(n), tienen el mismo costo amortizado O(1) de redimensionar, además la implementación actual tiene un costo menor de desplazar cuando no es el peor caso (mitad) vs el desplazamiento de todos los elementos de ArrayStack.
Aparece una invariante adicional comparado a ArrayDeque en ArrayStack y para este caso el índice lógico y el índice físico es el mismo.

<a name="target-item5"></a>
### Pregunta 5

#### a)

Pseudocódigo
```cpp
void reverse()
    anterior = null //puntero nodo anterior
    actual = head //puntero nodo actual
    tail = head  
    
    while (actual != null){
        siguiente = actual.next    //puntero nodo siguiente 
        actual.next = anterior     
        anterior = actual          
        actual = siguiente         
    }
    head = anterior 
```

#### b)

Tail ahora apunta a head original y head ahora apunta al tail original.

Si n=0
Lista vacía
tail y head apuntan al puntero nulo.

Si n=1
tail y head apuntan al único elemento.

#### c)

El nodo anterior es el invariante que representa el último nodo de la parte ya invertida.

El nodo actual es el invariante que representa el primer nodo de la parte que falta invertir.

#### d)

El espacio utilizado solo son utilizados 3 punteros a nodos anterior, actual y siguiente el costo espacial es O(1). 

El costo temporal es O(n) porque tiene que recorrer todos los nodos de la lista.

#### e)

Porque un SLList solo puede conocer los extremos, que sirve para implementar una pila y cola, pero no un deque porque necesita conocer el elemento anterior al tail para hacer eliminación en ese extremo y tendría que recorrer desde el inicio con un costo de O(n).

<a name="target-item6"></a>
### Pregunta 6

#### a)

Casos borde:

```cpp
1. Arreglo vacío
k = 0
A[] = []
Entrada: ([], 0, 0) 
Salida: []

2. Único elemento
k = 1
A[] = [5]
Entrada: ([5], 1, 1) 
Salida: [5]

3. Rotación total
k = 3
A[] = [1,2,3,4]
Entrada: ([1,2,3,4], 4, 3) 
Salida: [4,1,2,3]

4. Inicio en el final 
k = 4
A[] = [1,2,3,4]
Entrada: ([1,2,3,4], 4, 4) 
Salida: [1,2,3,4]

5. k mayor que el tamaño del arreglo (k > n)
k = 10
n = 4
A[] = [1, 2, 3, 4]
Entrada: ([1, 2, 3, 4], 4, 10)
Salida: [3, 4, 1, 2]   

6. k negativo
k = -2
n = 5
A[] = [a, b, c, d, e]
Entrada: ([a, b, c, d, e], 5, -2)
Salida: [d, e, a, b, c]

7. k múltiplo exacto de n, k/n> 1
k = 8
n = 4
A[] = [X, Y, Z, W]
Entrada: ([X, Y, Z, W], 4, 8)
Salida: [X, Y, Z, W]
```

Casos no borde:

```cpp
8.
k = 1
n = 5
A[] = [10, 20, 30, 40, 50]
Entrada: ([10, 20, 30, 40, 50], 5, 1)
Salida: [20, 30, 40, 50, 10]

9.
k = 2
n = 4
A[] = [A, B, C, D]
Entrada: ([A, B, C, D], 4, 2)
Salida: [C, D, A, B]
```

#### b)
1. Arreglo vacío
2. Único elemento
3. Rotación total (n-k=1)
4. Inicio en el final (n=k) 
5. k mayor que el tamaño del arreglo (k > n)
6. k negativo
7. k múltiplo exacto de n, k/n> 1
8. Caso normal de rotación 1 espacio.
8. Caso normal de rotación 2 espacios.

#### c)

Varias pruebas detectan falta de normlización de diferentes formas: 4, 5, 6, 7

#### d)

Cuando n=0 entonces es un arreglo vacío y debe manejar el retorno de un arreglo vacío.

<a name="target-item7"></a>
### Pregunta 7

#### a)
#### b)
#### c)
#### d)
#### e)
#### f)
#### c)
#### d)

<a name="target-item7"></a>
### Pregunta 7

#### a)
#### b)
#### c)
#### d)
#### e)
#### f)
