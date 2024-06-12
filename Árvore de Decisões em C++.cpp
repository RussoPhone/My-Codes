#include <stdio.h> 
#include <iostream>
#include <tchar.h>
#include <ctype.h>


int main() {
    _tsetlocale(LC_ALL, _T("portuguese"));
    char resp1, resp2, resp3, resp4, resp5, resp6, resp7;

   
    printf("O animal tem um nariz curto com bigodinho? (S/N): ");
    scanf(" %c", &resp1);
    
    printf("O Animal é conhecido por participar de videos virais na internet? (S/N): ");
    scanf(" %c", &resp2);
    
    printf("O animal tá preso em uma caixa de papelão? (S/N): ");
    scanf(" %c", &resp3);
    
    printf("O animal tá miando? (S/N): ");
    scanf(" %c", &resp4);
    
    printf("O animal tá no aviso de Cuidado Câo bravo? (S/N): ");
    scanf(" %c", &resp5);
    
    printf("O animal faz barulho quando o aspirador de pó é ligado? (S/N): ");
    scanf(" %c", &resp6);
    
    printf("O animal se assemelha a um dos animais heróicos no poster do filme Como Cães e Gatos lançado em 2001 pela Warner Bros e dirigido por Laurence Guterman mais conhecido como diretor de O Filho do Maskára e FormiguinhaZ? (S/N): ");
    scanf(" %c", &resp7);


    if ((resp1 == 's' || resp1 == 'S') && 
        (resp2 == 's' || resp2 == 'S') && 
        (resp3 == 's' || resp3 == 'S') && 
        (resp4 == 's' || resp4 == 'S')) {
        printf("O animal é um gato!\n");
    } else if ((resp5 == 's' || resp5 == 'S') && 
               (resp6 == 's' || resp6 == 'S') && 
               (resp7 == 's' || resp7 == 'S')) {
        printf("O animal é um cachorro.\n");
    } else {
        printf("O animal é um gato.\n");
    }

    return 0;
}
