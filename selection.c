

//========================================================================
// Autor: Rógenis Pereira - Universidade Federal do Amazonas
// Nome Do Arquivo: selection.c
// File Name: selection.c
//
// Descrição: Implementação do algoritmo selection sort com números aleatórios 
// Description: Selection sort Algorithm
// Vetor com tamanho 100, e com números aleatórios gerados de 0-10000
//========================================================================
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100


void fSelect_Sort(int *pVetor);

void fSelect_Sort(int *pVetor){

    int vMenor;
    int vAux;
    int vTemp;
    int vTroca;

    for(vAux=0; vAux < N-1; vAux++){
        
        vMenor = vAux; // Menor valor recebe a posição que está passando;

        for (vTemp=vAux+1; vTemp < N; vTemp++) // Percorre o vetor da posição vAux+1 até o final;
        {
            if (pVetor[vTemp] < pVetor[vMenor]) // Testa se a posição que está passando é menor que o menor valor;
            {
                vMenor = vTemp; // vMenor recebe a posição do menor valor;
            }
        }

        if (vMenor != vAux) // Se a posição for diferente da que está passando, ocorre a troca;
        {
            vTroca         = pVetor[vAux];
            pVetor[vAux]   = pVetor[vMenor];
            pVetor[vMenor] = vTroca;
        }
    }
}

int main(){

	int v[N];
	srand(time(NULL));

	for(int i = 0; i < N; i++){
		v[i] = rand()%10000;
	}
	
	fSelect_Sort(v);

	for(int i = 0; i < N; i++){
		printf("[%d]\n", v[i]);	
	}	
	
}