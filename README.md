# Documentacion de Funciones - Proyecto Matriz Dinamica en C - Quiz 05
Jeremy Gomez C. - C23264

> [!NOTE]
> Verified with GCC by @JGomezC145


## Funciones Principales

### `int **crearMatriz(int filas, int columnas)`
Reserva memoria dinamica para una matriz de tamaño `filas x columnas`.

- **Parametros:**
  - `filas`: numero de filas
  - `columnas`: numero de columnas
- **Retorna:** puntero doble a la matriz creada



### `void llenarMatriz(int **matriz, int filas, int columnas)`
Llena cada celda de la matriz con un numero aleatorio entre 1 y 99.

- **Parametros:**
  - `matriz`: puntero a la matriz
  - `filas`, `columnas`: dimensiones de la matriz



### `void imprimirMatriz(int **matriz, int filas, int columnas)`
Imprime la matriz en formato tabla, con columnas alineadas.

- **Parametros:**
  - `matriz`: puntero a la matriz
  - `filas`, `columnas`: dimensiones de la matriz



### `void liberarMatriz(int **matriz, int filas)`
Libera toda la memoria reservada por la matriz.

- **Parametros:**
  - `matriz`: puntero a la matriz
  - `filas`: numero de filas (necesario para liberar cada fila)



### `int **redimensionarMatriz(int **matriz, int m, int n, int m2, int n2)`
Crea una nueva matriz de tamaño `m2 x n2`, copia los valores de la matriz anterior, y llena los espacios nuevos con valores aleatorios.

- **Parametros:**
  - `matriz`: matriz original
  - `m`, `n`: dimensiones originales
  - `m2`, `n2`: nuevas dimensiones
- **Retorna:** puntero doble a la nueva matriz



## Funcionamiento Principal

1. El `main()` solicita las dimensiones originales.
2. Se crea y llena la matriz original.
3. Se imprime la matriz.
4. El usuario ingresa las nuevas dimensiones.
5. La matriz se redimensiona y se imprime nuevamente.
6. Toda la memoria es liberada antes de salir del programa.


