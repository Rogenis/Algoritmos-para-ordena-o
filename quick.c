
//========================================================================
// Autor: Rógenis Pereira da SIlva - Universidade Federal do Amazonas
// Nome Do Arquivo: quick.c
// File Name: quick.c
//
// Descrição: Implementação do algoritmo quicksort com números aleatórios 
// Description: Quick sort Algorithm
// Vetor com tamanho 100, e com números aleatórios gerados de 0-10000
//========================================================================
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void quick_sort(int *a, int left, int right);

void quick_sort(int *a, int left, int right){
    
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}


int main(){

	int v[N];
	srand(time(NULL));

	for(int i = 0; i < N; i++){
		v[i] = rand()%10000;
	}
	
	quick_sort(v,0,N-1);

	for(int i = 0; i < N; i++){
		printf("[%d]\n", v[i]);	
	}	
	

}
