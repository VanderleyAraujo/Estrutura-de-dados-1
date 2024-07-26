#include <stdio.h>

void insertionSort(int vet[],int n){
    int aux;
    for(int i = 1; i < n; i++){
        aux = vet[i];
        int j;
        for(j = (i-1); j >= 0; j--){
            if(vet[j] > aux){
                vet[j + 1] = vet[j];
            }else{
                break;
            }
        }

        vet[j+1] = aux;

    }
}

int main(){
    int num[100000];
    int n;
    
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }

    insertionSort(num,n);

    for(int i = 0; i < n; i++){
        printf("%d ", num[i]);
    }

    return 0;
}