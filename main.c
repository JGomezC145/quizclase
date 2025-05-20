#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para usar srand y rand

int main() {
    int m, n;
    printf("Ingrese el número de filas (m): ");
    scanf("%d", &m);
    printf("Ingrese el número de columnas (n): ");
    scanf("%d", &n);

    // Reservar memoria para la matriz original
    int **matriz = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    // Inicializar la semilla aleatoria
    srand(time(NULL));

    // Llenar matriz original
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = (rand() % 99) + 1;
        }
    }

    // Imprimir matriz original
    printf("\nMatriz original:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Pedir nuevo tamaño
    int m2, n2;
    printf("\nIngrese el nuevo número de filas (m2): ");
    scanf("%d", &m2);
    printf("Ingrese el nuevo número de columnas (n2): ");
    scanf("%d", &n2);

    // Crear nueva matriz
    int **nuevaMatriz = (int **)malloc(m2 * sizeof(int *));
    for (int i = 0; i < m2; i++) {
        nuevaMatriz[i] = (int *)malloc(n2 * sizeof(int));
    }

    // Copiar datos de la matriz original y rellenar nuevos espacios
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            if (i < m && j < n) {
                nuevaMatriz[i][j] = matriz[i][j];  // Copiar existente
            } else {
                nuevaMatriz[i][j] = (rand() % 99) + 1;  // Rellenar nuevos espacios
            }
        }
    }

    // Liberar la matriz original
    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);

    // Actualizar puntero y dimensiones
    matriz = nuevaMatriz;
    m = m2;
    n = n2;

    // Imprimir nueva matriz
    printf("\nMatriz redimensionada:\n");
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
