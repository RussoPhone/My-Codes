#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int tamVetor, i, maiorel;
	
	printf("Insira o tamanho do vetor:\n");
	scanf("%d", &tamVetor);
	
	int vetor [tamVetor];
	for (i = 0; i < tamVetor; i++){
		printf("Digite o elemento %d: ", i + 1);
		scanf("%d", &vetor[i]);
		
	}
	
	maiorel = vetor [0];
    for (i = 1; i < tamVetor; i++){
		if (vetor[i] > maiorel){
			maiorel = vetor[i];
		}
	}
	printf("O maior elemento dentro do vetor é.....:%d\n", maiorel);
	return 0;
	
	}