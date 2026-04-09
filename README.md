## INSTRUCCIONES PARA COMPILAR

Debido a los requerimientos de la práctica se realiza la compilación de dos formas.
1. Se compila con el cmake cuando se trabaja sobre el código por la facilidad que otorga el cmake y también para evaluar los sanitizers.
2. Se compila con un archivo bash para obtener los ejecutables con determinadas banderas.

Para compilar con el cmake se realiza lo siguiente:
1. Moverse a la carpeta build:
```bash
cd build
```
2. En la carpeta build ejecutar el cmake

```bash
cmake ..
cmake --build .
```

Para compilar con las banderas como la de depuración, etc, hacer en la carpeta principal del proyecto.
```bash
./compilacion.sh
```
### Si presenta errores de falta de permiso, primero tendrá que ejecutar, el siguiente comando para darle el permiso de ejecutable:
```bash
chmod +x compilacion.sh
```


## INSTRUCCIONES PARA EJECUTAR PRUEBAS

En la carpeta build ejecutar:

```bash
ctest
```
