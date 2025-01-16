/*
Instituto Tecnológico y de Estudios Superiores de Monterrey
TC2038.570 Análisis y diseño de algoritmos avanzados

Autor: Lorena Abigail Solís de los Santos A01746602
Fecha de entrega: Enero/7/2025

Descripción: Dada una matriz nums que contiene n números distintos en el rango [0, n], devuelve el único número en el rango que falta en la matriz
*/
#include <iostream>
#include <vector>
#include <algorithm>

// Función que mezcla dos subarreglos en orden descendente
void merge(std::vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear subarreglos temporales
    std::vector<double> L(n1);
    std::vector<double> R(n2);

    // Copiar datos a los subarreglos temporales
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    // Mezclar los subarreglos en orden descendente
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copiar los elementos restantes de L, si los hay
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Copiar los elementos restantes de R, si los hay
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Función recursiva de MergeSort
void mergeSort(std::vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Dividir y conquistar
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Combinar
        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    std::cout << "Ingrese el número de valores a ordenar: ";
    std::cin >> N;

    std::vector<double> values(N);
    std::cout << "\nIngrese " << N << " valores (reales o enteros), uno por línea:\n";
    for (int i = 0; i < N; ++i) {
        std::cin >> values[i];
    }

    // Ordenar los valores en orden descendente
    mergeSort(values, 0, N - 1);

    // Mostrar los resultados
    std::cout << "\nResultado:\nValores ordenados de mayor a menor:\n";
    for (const double& value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
