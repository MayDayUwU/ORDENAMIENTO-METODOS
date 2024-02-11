#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

// Funcion para generar numeros aleatorios entre min y max
int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Funcion para imprimir un arreglo
void imprimirArreglo(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Funcion de ordenamiento burbuja
void ordenamientoBurbuja(int arr[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Funcion de ordenamiento por insercion
void ordenamientoInsercion(int arr[]) {
    for (int i = 1; i < SIZE; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Funcion de ordenamiento por seleccion
void ordenamientoSeleccion(int arr[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Funcion de ordenamiento rapido
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int partitionIndex = i + 1;

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

// Funcion principal
int main() {
    srand(time(NULL));

    // Ordenamiento Burbuja
    printf("Ordenamiento Burbuja:\n");
        int arr[SIZE];
        for (int j = 0; j < SIZE; j++) {
            arr[j] = generarNumeroAleatorio(1, 100);
        }
        imprimirArreglo(arr);
        ordenamientoBurbuja(arr);
        imprimirArreglo(arr);
        printf("\n");

    // Ordenamiento por Insercion
    printf("Ordenamiento por Insercion:\n");
        for (int j = 0; j < SIZE; j++) {
            arr[j] = generarNumeroAleatorio(1, 100);
        }
        imprimirArreglo(arr);
        ordenamientoInsercion(arr);
        imprimirArreglo(arr);
        printf("\n");

    // Ordenamiento por Seleccion
    printf("Ordenamiento por Seleccion:\n");
        for (int j = 0; j < SIZE; j++) {
            arr[j] = generarNumeroAleatorio(1, 100);
        }
        imprimirArreglo(arr);
        ordenamientoSeleccion(arr);
        imprimirArreglo(arr);
        printf("\n");

    // Ordenamiento Rapido
    printf("Ordenamiento Rapido:\n");
        for (int j = 0; j < SIZE; j++) {
            arr[j] = generarNumeroAleatorio(1, 100);
        }
        imprimirArreglo(arr);
        quickSort(arr, 0, SIZE - 1);
        imprimirArreglo(arr);
        printf("\n");

    return 0;
}
