#include <stdio.h>

// FUNCIÓN PARA IMPRIMIR LOS ARREGLOS...
void imprimir(int array[], int tam) {
    printf(" {");
    for (int i = 0; i < tam; i++) {
        printf(" %d ", array[i]);
    }
    printf("} ");
}

// FUNCIÓN PARA UNIÓN DE CADENAS...
void unir(int arrayA[], int tamA, int arrayB[], int tamB, int arrayC[]) {
    for (int i = 0; i < tamA; i++) {
        arrayC[i] = arrayA[i];
    }
    for (int i = 0; i < tamB; i++) {
        arrayC[tamA + i] = arrayB[i];
    }
    printf("A U B: ");
    for (int i = 0; i < tamA + tamB; i++) {
        printf(" %d", arrayC[i]);
    }
    printf("\n");
}

// FUNCIÓN PARA INTERSECCIÓN DE CADENAS...
void interseccion(int arrayA[], int tamA, int arrayB[], int tamB) {
    printf("A I B: ");
    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            if (arrayA[i] == arrayB[j]) {
                printf("%d ", arrayA[i]);
            }
        }
    }
    printf("\n");
}

// FUNCIÓN PARA COMPLEMENTO...
void complemento(int arrayA[], int arrayB[], int tamA, int tamB) {
    printf("Complemento: ");
    for (int i = 0; i < tamB; i++) {
        int com = 0;
        for (int j = 0; j < tamA; j++) {
            if (arrayB[i] == arrayA[j]) {
                com = 1;
            }
        }
        if (!com) {
            printf("%d ", arrayB[i]);
        }
    }
    printf("\n");
}

// FUNCIÓN DE DIFERENCIA...
void diferencia(int arrayA[], int arrayB[], int tamA, int tamB) {
    printf("A - B: ");
    for (int i = 0; i < tamA; i++) {
        int dif = 0;
        for (int j = 0; j < tamB; j++) {
            if (arrayA[i] == arrayB[j]) {
                dif = 1;
            }
        }
        if (!dif) {
            printf("%d ", arrayA[i]);
        }
    }
    printf("\n");
}

// FUNCIÓN DE PRODUCTO CARTESIANO...
void productocartesiano(int arrayA[], int arrayB[], int tamA, int tamB) {
    printf("Producto cartesiano:\n");
    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            printf(" (%d, %d) ", arrayA[i], arrayB[j]);
        }
        printf("\n");
    }
}

// FUNCIÓN PARA COMBINACIONES...
void combinarRecursivo(int array1[], int n1, int array2[], int n2, int resultado[], int nivel, int longitud) {
    if (nivel == longitud) {
        for (int i = 0; i < longitud; i++) {
            printf("%d", resultado[i]);
        }
        printf(" ");
        return;
    }

    for (int i = 0; i < n1; i++) {
        resultado[nivel] = array1[i];
        combinarRecursivo(array1, n1, array2, n2, resultado, nivel + 1, longitud);
    }

    for (int i = 0; i < n2; i++) {
        resultado[nivel] = array2[i];
        combinarRecursivo(array1, n1, array2, n2, resultado, nivel + 1, longitud);
    }
}

void concatenacion(int arrayA[], int arrayB[], int tamA, int tamB) {
    int longitud;
    printf("Introduce la longitud de las combinaciones: ");
    scanf("%d", &longitud);

    printf("Combinaciones:\n");
    int resultado[longitud];
    combinarRecursivo(arrayA, tamA, arrayB, tamB, resultado, 0, longitud);
    printf("\n");
}

int main() {
    int opcion;
    int arrayA[] = {1, 2, 3, 6};
    int arrayB[] = {3, 4, 5, 7};
    int tamA = sizeof(arrayA) / sizeof(arrayA[0]);
    int tamB = sizeof(arrayB) / sizeof(arrayB[0]);
    int arrayC[tamA + tamB];

    do {
        printf("\n\n**MENU** \n 1.UNION\n 2.INTERSECCION\n 3.COMPLEMENTO\n 4.DIFERENCIA\n 5.PRODUCTO CARTESIANO\n 6.CONCATENACION\n 7.SALIR \nOpcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                imprimir(arrayA, tamA);
                imprimir(arrayB, tamB);
                printf("\n\n");
                unir(arrayA, tamA, arrayB, tamB, arrayC);
                break;
            case 2:
                imprimir(arrayA, tamA);
                imprimir(arrayB, tamB);
                printf("\n\n");
                interseccion(arrayA, tamA, arrayB, tamB);
                break;
            case 3:
                imprimir(arrayA, tamA);
                imprimir(arrayB, tamB);
                printf("\n\n");
                complemento(arrayA, arrayB, tamA, tamB);
                break;
            case 4:
                imprimir(arrayA, tamA);
                imprimir(arrayB, tamB);
                printf("\n\n");
                diferencia(arrayA, arrayB, tamA, tamB);
                break;
            case 5:
                imprimir(arrayA, tamA);
                imprimir(arrayB, tamB);
                printf("\n\n");
                productocartesiano(arrayA, arrayB, tamA, tamB);
                break;
            case 6:
                imprimir(arrayA, tamA);
                imprimir(arrayB, tamB);
                printf("\n\n");
                concatenacion(arrayA, arrayB, tamA, tamB);
                break;
            case 7:
                printf("\nAdios\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 7);

    return 0;
}
