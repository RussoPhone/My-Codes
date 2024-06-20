#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void mtpVetor(int vetor[], int tamanho, int multiplicador) {
	for (int i = 0; i < tamanho; i++){
		vetor[i] *= multiplicador;
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	
	int vetor[] = {3, 7, 2, 9, 5};
	int tamanho = sizeof(vetor) / sizeof(vetor[0]);
	int multiplicador;
	
	printf("Digite o valor inteiro para multiplicar o vetor:\n");
	scanf("%d", &multiplicador);
	
	printf("Vetor antes: ");
	for (int i = 0; i < tamanho; i++){
		printf("%d ", vetor[i]);
		
	}
	
	mtpVetor(vetor, tamanho, multiplicador);
	
	printf("\nVetor multipliado: ");
	for (int i = 0; i < tamanho; i++){
		printf("%d ", vetor[i]);
	}
	
	return 0;
}