#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para usar srand y rand

int main() {
    int m, n;
    printf("Ingrese el número de filas (m): ");
    scanf("%d", &m);
    printf("Ingrese el número de columnas (n): ");
    scanf("%d", &n);

    // Reservar memoria dinámica para la matriz
    int **matriz = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    // Inicializar la semilla aleatoria
    srand(time(NULL));

    // Llenar la matriz con valores aleatorios entre 1 y 99 (no incluye 0)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = (rand() % 99) + 1;
        }
    }

    // Imprimir la matriz
    printf("\nMatriz generada:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar memoria
    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
