#include <stdio.h>
#include <stdlib.h>

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

    // Mensaje de confirmación
    printf("Matriz de %d x %d creada en memoria dinámica.\n", m, n);

    
    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
