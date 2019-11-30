
//==========================================================================
// Autor: Rógenis Pereira - Universidade Federal do Amazonas
// Nome Do Arquivo: merge.c
// File Name: merge.c
//
// Descrição: Implementação do algoritmo Merge Sort com números aleatórios 
// Description: Merge sort Algorithm
// Vetor com tamanho 100, e com números aleatórios gerados de 0-10000
//==========================================================================
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void mergesort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);


void mergesort(int *v, int n){
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenação.
*/
void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}

/*
  Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

    if (c[iv] < c[ic]) v[z++] = c[iv++];
    else /* if (c[iv] > c[ic]) */ v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];

}


int main(){

	int v[N];
	srand(time(NULL));

	for(int i = 0; i < N; i++){
		v[i] = rand()%10000;
	}
	
	mergesort(v,N);

	for(int i = 0; i < N; i++){
		printf("[%d]\n", v[i]);	
	}	
	

}
