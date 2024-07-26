#include <stdio.h>

void selectionSort(int vet[], int n) {
    int aux, min;
    for (int i = 0; i < (n - 1); i++) {
        min = i;
        int j;
        // verificando se o elemento da posição j é o menor
        for (j = (i + 1); j < n; j++) {
            if (vet[j] < vet[min]) {
                min = j;
            }
        }
        // se o valor da posição "i" for diferente do valor do min
        if (i != min) {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
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

    fscanf(inputFile, "%d", &n);

    
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &num[i]);
    }

    fclose(inputFile);
  
    selectionSort(num, n);

   outputFile = fopen("C:\\Users\\vanderley\\Desktop\\ATV de ED\\saidas\\num.100000.4.txt", "w");

    if (outputFile == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", num[i]);
    }

    fclose(outputFile);

    return 0;
}
