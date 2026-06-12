## Tercera Práctica Calificada - CC232

### Estudiante
- Nombre: Victor Hugo Cadillo Gutierrez
- Código: 20255514D
- Fecha: 06/12/2026
- Problema asignado: F - Wide Swap 
- Enlace: https://atcoder.jp/contests/agc001/tasks/agc001_f

### Referencia oficial
- Archivo de asignación:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica3_CC232/Problemas-Evaluacion3.csv

### Tema principal
- Semana: 6
- Estructura o técnica principal: Treap por posición

### Resumen de la solución
El problema nos da una permutación de números de 1 a N y un número K que se usa como distancia mínima de intercambio.

```text
Sean dos índices i,j
1<=i<j<=N

Condiciones de intercambio:
j-i>=K 
abs(Pi-Pj)=1
```

Entrada del problema:
```text
N=4, K=2
Secuencia: 4 2 3 1
```
La solución debe dar la menor permutación

```text
2 1 4 3
Llega a esta respuesta a través de permutaciones:
4 2 3 1
4 1 3 2
3 1 4 2
2 1 4 2
```

Para resolverlo utilizamos la idea estructural del Treap, sin embargo en lugar de usar el valor para la propiedad BST, usamos los índices y la prioridad del heap es generada de forma aleatoria.

### Complejidad
- Tiempo: O(n*logn)
- Espacio: O(n)

### Invariante o idea clave
Preserva las invariantes del Heap, que debe mantener la prioridad y del BST modificado, que debe mantener el orden por índice.
Además del invariante de tamaño, cada nodo tiene un subárbol de tamaño: 1+tamaño_izquierdo + tamaño_derecho

### Archivos relevantes
- include/
  - FWideSwap.h
  - ImplicitTreap.h
- src/
  - FwideSwap.cpp
  - ImplicitTreap.cpp
- tests/
  - edge_cases.cpp
  - test_internal.cpp
- demos/
  - demo_fwideswap.cpp

### Compilación
```bash
cmake -S . -B build
cmake --build build
```

### Ejecución
```bash
./build/pc3_demo_fwideswap
./bulid/benchmark
```
Para las pruebas:

```bash
ctest --test-dir build
```

### Casos de prueba
Los casos borde serían cuando K=0 , K=1, cuando la permutación ya está ordenada.

### Declaración de autoría
Declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.
