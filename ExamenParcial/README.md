## Solucionario Examen Parcial - CC232
## Versión A

### Estudiante
- Nombre: Victor Hugo Cadillo Gutierrez
- Código: 20255514D

### Indice
[Pregunta 1](#target-item1)
[Pregunta 2](#target-item2)
[Pregunta 3](#target-item3)
[Pregunta 4](#target-item4)
[Pregunta 5](#target-item5)
[Pregunta 6](#target-item6)
[Pregunta 7](#target-item7)

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
<a name="target-item4"></a>
### Pregunta 4
<a name="target-item5"></a>
### Pregunta 5
<a name="target-item6"></a>
### Pregunta 6
<a name="target-item7"></a>
### Pregunta 7


