// Proyecto POO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

void shellSort(int arr[], int N)
{
    for (int half = N / 2; half > 0; half /= 2)
    {
        for (int i = half; i < N; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= half && arr[j - half] > temp; j -= half)
                arr[j] = arr[j - half];

            arr[j] = temp;
        }
    }
}
// Función que coloca el elemento pivote en su posición correcta en el arreglo ordenado
int partition(int arr[], int menor, int mayor) {
    int pivot = arr[mayor];  
    int i = menor - 1;  

    for (int j = menor; j <= mayor - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[mayor];
    arr[mayor] = temp;
    return (i + 1);
}

void quickSort(int arr[], int menor, int mayor) {
    if (menor < mayor) {
        int pi = partition(arr, menor, mayor);

        quickSort(arr, menor, pi - 1);
        quickSort(arr, pi + 1, mayor);
    }
}
int encontrarMaximo(int arr[], int size) {
    int maximo = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }
    return maximo;
}
void CountingSort(int arr[], int n) {
    int Max = encontrarMaximo(arr, n);
    int count[100 + 1] = {0};

    // Contar la frecuencia de cada elemento
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    // Reconstruir el arreglo ordenado
    for (int i = 0; i <= Max; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}
void busquedaSecuencial(int arr[], int size, int elemento) {
    bool encontrado = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == elemento) {
            std::cout << "Tu numero esta en la posicion " <<  i << "\n";  // Se encontró el elemento en la posición i
            encontrado = true;
        }
    }
    if (!encontrado) {
        std::cout << "Tu numero no se encontro\n";  // El elemento no se encontró en el arreglo
    }
}
void busquedaBinaria(int arr[], int size, int valor) {
    int izquierda = 0;
    int derecha = size - 1;
    bool encontrado = false;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == valor) {
            std::cout << "Tu numero esta en la posicion " << medio << "\n";
            encontrado = true;
        }

        if (arr[medio] < valor) {
            izquierda = medio + 1; // Buscar en la mitad derecha del arreglo
        }
        else {
            derecha = medio - 1; // Buscar en la mitad izquierda del arreglo
        }
    }
    if (!encontrado) {
        std::cout << "Tu numero no se encontro\n";  // El elemento no se encontró en el arreglo
    }
   
}

void mostrar (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " , ";
    }
}

int main()
{
    int array[100];
    int N = sizeof(array) / sizeof(array[0]);
	int random;
    int dato, numero;
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        int random = rand() % 100 + 1;
        array[i] = random;
        cout << array[i] << " , ";
    }

    std::cout << "\nQue metodo de ordenamiento quieres usar?\n 1-Shell sort\n 2-Quick sort\n 3- Counting sort\n";
    std::cin >> dato;
    switch (dato)
    {
    case 1:
        shellSort(array, N);
        break;
    case 2:
        quickSort(array, 0, N - 1);
        break;
    case 3:
        CountingSort(array, N);
        break;
    default:
        shellSort(array, N);
        break;
    }
    std::cout << "\nLos datos ordenados son:\n";
   
    mostrar(array, N);
    std::cout << "\nAhora que numero quieres buscar?\n";
    std::cin >> numero;
    std::cout << "Que tipo de busueda quieres hacer?\n 1-secuencial 2-binaria\n";
    std::cin >> dato;
    switch (dato)
    {
    case 1:
        busquedaSecuencial(array, N, numero);
        break;
    case 2:
        busquedaBinaria(array,N,numero);
        break;
    default:
        busquedaSecuencial(array, N, numero);
        break;
    }
}
