/*
    Author: JGomezC145
    License: None
    Description: Programa en C que crea una matriz de m x n, la llena con valores aleatorios distintos de 0,
                 la imprime, redimensiona la matriz a m2 x n2 y vuelve a imprimirla.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para usar srand y rand

// Crear una matriz dinamica de m x n
int **crearMatriz(int filas, int columnas) {
    int **matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    }
    return matriz;
}

// Llenar matriz con valores aleatorios distintos de 0
void llenarMatriz(int **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = (rand() % 99) + 1;
        }
    }
}

// Imprimir la matriz
void imprimirMatriz(int **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Liberar memoria de la matriz
void liberarMatriz(int **matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Redimensionar la matriz y devolver una nueva
int **redimensionarMatriz(int **matriz, int m, int n, int m2, int n2) {
    int **nueva = crearMatriz(m2, n2);

    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            if (i < m && j < n) {
                nueva[i][j] = matriz[i][j];
            } else {
                nueva[i][j] = (rand() % 99) + 1;
            }
        }
    }

    liberarMatriz(matriz, m);
    return nueva;
}

// Programa principal
int main() {
    int m, n;
    printf("Ingrese el numero de filas (m): ");
    scanf("%d", &m);
    printf("Ingrese el numero de columnas (n): ");
    scanf("%d", &n);

    srand(time(NULL)); // Inicializar semilla aleatoria

    int **matriz = crearMatriz(m, n);
    llenarMatriz(matriz, m, n);

    printf("\nMatriz original:\n");
    imprimirMatriz(matriz, m, n);

    int m2, n2;
    printf("\nIngrese el nuevo numero de filas (m2): ");
    scanf("%d", &m2);
    printf("Ingrese el nuevo numero de columnas (n2): ");
    scanf("%d", &n2);

    matriz = redimensionarMatriz(matriz, m, n, m2, n2);
    m = m2;
    n = n2;

    printf("\nMatriz redimensionada:\n");
    imprimirMatriz(matriz, m, n);

    liberarMatriz(matriz, m);

    return 0;
}
