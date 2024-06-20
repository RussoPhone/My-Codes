 #include <stdio.h>
 #include <stdlib.h>
 #include <locale.h>
 int main() {
 	setlocale(LC_ALL, "Portuguese");
	 int n;
	 printf("Digite o tamanho de um vetor:\n");
	 scanf("%d", &n);
	 
	 int vetor[n];
	 printf("Digite os elementos dos vetores:\n");
	 for (int i = 0; i < n; i++){
		 scanf("%d", &vetor[i]);
		 
	 }
	 int soma = 0;
	 for (int i = 0; i < n; i++){
		 soma += vetor[i];
	 }
	 
	 printf("O total das somas dos elementos é: %d\n", soma);
	 
	 return 0;
	 
 }