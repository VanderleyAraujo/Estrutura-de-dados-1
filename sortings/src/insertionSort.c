#include <stdio.h>

void insertionSort(int vet[], int n) {
    int aux;
    for (int i = 1; i < n; i++) {
        aux = vet[i];
        int j;
        for (j = (i - 1); j >= 0; j--) {
            if (vet[j] > aux) {
                vet[j + 1] = vet[j];
            } else {
                break;
            }
        }
        vet[j + 1] = aux;
    }
}

int main() {
    int num[100000];
    int n;
    FILE *inputFile, *outputFile;
    
    inputFile = fopen("C:\\Users\\vanderley\\Desktop\\ATV de ED\\input\\num.100000.4.txt", "r");
    
    if (inputFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    if (fscanf(inputFile, "%d", &n) != 1) {
        perror("Erro ao ler a quantidade de números");
        fclose(inputFile);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(inputFile, "%d", &num[i]) != 1) {
            perror("Erro ao ler os números");
            fclose(inputFile);
            return 1;
        }
    }

    fclose(inputFile);

    insertionSort(num, n);

    outputFile = fopen("C:\\Users\\vanderley\\Desktop\\ATV de ED\\saidas\\num.100000.4.txt", "w"); 

    if (outputFile == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", num[i]);
    }
    fprintf(outputFile, "\n");

    fclose(outputFile);

    return 0;
}
