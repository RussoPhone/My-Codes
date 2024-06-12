#include <stdio.h> //Aqui fica as biblioteca
#include <stdlib.h>
#include <tchar.h>
#include <iostream>
#include <string.h>
#include <tchar.h>
#include <ctype.h>

using namespace std;
//Aqui fica a definição do maximo de cada atributo da venda
#define MAX_PRODUTOS 50
#define MAX_CLIENTES 50
#define MAX_VENDAS 100  
//Aqui ficam as funções struct para a gestão de vendas
typedef struct {
    char nome[50];
    float preco;
    int quantidade;
    int codigo;
    char marca[50];
} Produto;

typedef struct{
	int codigo;
	char nome[50];
	char forma[50];
	char sigla[5];
	
}FormaPagamento;

typedef struct{
	int codigoProduto;
	int estoqueMinimo;
	int estoqueMaximo;
	int estoqueAtual;
}Estoque;

typedef struct {
    char nome[50];
    char cpf[15];
    int codigo;
    char dataNascimento[12];
} Cliente;

typedef struct {
    Cliente cliente;
    Produto produto;
    char formaPagamento[50];
    double valorTotal;
} Venda; 

Produto estoque[MAX_PRODUTOS];
Cliente clientes[MAX_CLIENTES];
Venda vendas[MAX_VENDAS];
//Aqui fica as funções em relação ao struct para o preenchimento de informação
int qtdProdutos = 0, qtdClientes = 0, qtdVendas = 0;
void cadastrarCliente() {
    Cliente novoCliente;
    printf("Digite o código do cliente: ");
    scanf("%d", &novoCliente.codigo); 
    printf("Digite o nome do cliente: ");
    scanf("%49s", novoCliente.nome);
    printf("Digite o CPF do cliente: ");
    scanf("%14s", novoCliente.cpf);
    printf("Digite a data de nascimento do cliente (dd/mm/aaaa): ");
    scanf("%10s", novoCliente.dataNascimento); 
    clientes[qtdClientes++] = novoCliente;
//No fim das funções vai ter a função pra salvar as informações na pasta publica de documentos
    FILE *arquivo = fopen("C:\\Users\\Public\\Documents\\cadastro_clientes.txt", "a");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo de cadastro de clientes!\n");
        return;
    }
    fprintf(arquivo, "Código: %d, Nome: %s, CPF: %s, Data de Nascimento: %s\n",
            novoCliente.codigo, novoCliente.nome, novoCliente.cpf, novoCliente.dataNascimento);
    fclose(arquivo);
    printf("Cliente cadastrado com sucesso e arquivo atualizado!\n");
}


void cadastrarProduto() {
    Produto novoProduto;
    printf("Digite o código do produto: ");
    scanf("%d", &novoProduto.codigo); 
    printf("Digite o nome do produto: ");
    scanf("%49s", novoProduto.nome);
    printf("Digite o valor unitário do produto: ");
    scanf("%f", &novoProduto.preco);
    printf("Digite a marca do produto: ");
    scanf("%49s", novoProduto.marca); 
    estoque[qtdProdutos++] = novoProduto;
    
     FILE *arquivo = fopen("C:\\Users\\Public\\Documents\\cadastro_produtos.txt", "a");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo de cadastro de produtos!\n");
        return;
    }
    fprintf(arquivo, "Código: %d, Nome: %s, Preço: %.2f, Marca: %s\n",
            novoProduto.codigo, novoProduto.nome, novoProduto.preco, novoProduto.marca);
    fclose(arquivo);
    printf("Produto cadastrado com sucesso e arquivo atualizado!\n");

}

void cadastrarPedido() {
    Venda novaVenda;
    printf("Digite o código do cliente: ");
    scanf("%d", &novaVenda.cliente.codigo); 
    printf("Digite o nome do cliente: ");
    scanf("%49s", novaVenda.cliente.nome);
    
    printf("Digite o código do produto: ");
    scanf("%d", &novaVenda.produto.codigo);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novaVenda.produto.quantidade);
    printf("Digite o valor unitário do produto: ");
    scanf("%f", &novaVenda.produto.preco);
  
    novaVenda.valorTotal = novaVenda.produto.quantidade * novaVenda.produto.preco;
    vendas[qtdVendas++] = novaVenda;
     FILE *arquivo = fopen("C:\\Users\\Public\\Documents\\cadastro_vendas.txt", "a");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo de cadastro de vendas!\n");
        return;
    }
    fprintf(arquivo, "Código Cliente: %d, Código Produto: %d, Quantidade: %d, Valor Total: %.2f\n",
            novaVenda.cliente.codigo, novaVenda.produto.codigo, novaVenda.produto.quantidade, novaVenda.valorTotal);
    fclose(arquivo);
    printf("Venda cadastrada com sucesso e arquivo atualizado!\n");
}

void cadastrarFormaPagamento() {
   
    FormaPagamento novaFormaPagamento;
    printf("Digite o código da forma de pagamento: ");
    scanf("%d", &novaFormaPagamento.codigo);
    printf("Digite a forma de pagamento: ");
    scanf("%49s", novaFormaPagamento.forma);
    printf("Digite o nome da forma de pagamento: ");
    scanf("%49s", novaFormaPagamento.nome);
    printf("Digite a sigla da forma de pagamento: ");
    scanf("%4s", novaFormaPagamento.sigla);
  
}

void verEstoque() {
  
    Estoque estoqueAtual;
    printf("Digite o código do produto: ");
    scanf("%d", &estoqueAtual.codigoProduto);
    printf("Digite o estoque mínimo: ");
    scanf("%d", &estoqueAtual.estoqueMinimo);
    printf("Digite o estoque máximo: ");
    scanf("%d", &estoqueAtual.estoqueMaximo);
    printf("Digite o estoque atual: ");
    scanf("%d", &estoqueAtual.estoqueAtual);
  
}


void venderProduto() {
    Venda novaVenda;
    int codigoCliente, codigoProduto, quantidade;
    float valorUnitario;

  
    printf("Digite o código do cliente: ");
    scanf("%d", &codigoCliente);
    for(int i = 0; i < qtdClientes; i++) {
        if(clientes[i].codigo == codigoCliente) {
            novaVenda.cliente = clientes[i];
            break;
        }
    }

   
    printf("Digite o código do produto: ");
    scanf("%d", &codigoProduto);
    for(int i = 0; i < qtdProdutos; i++) {
        if(estoque[i].codigo == codigoProduto) {
            novaVenda.produto = estoque[i];
            break;
        }
    }

 
    printf("Digite a quantidade do produto: ");
    scanf("%d", &quantidade);
    printf("Digite o valor unitário do produto: ");
    scanf("%f", &valorUnitario);

    novaVenda.produto.quantidade = quantidade;
    novaVenda.produto.preco = valorUnitario;
    novaVenda.valorTotal = quantidade * valorUnitario;

  
    vendas[qtdVendas++] = novaVenda;
}

void verHistoricoVendas() {
    int codigoCliente;
    printf("Digite o código do cliente para ver o histórico de vendas: ");
    scanf("%d", &codigoCliente);
    
    printf("Histórico de vendas para o cliente %d:\n", codigoCliente);
    for(int i = 0; i < qtdVendas; i++) {
        if(vendas[i].cliente.codigo == codigoCliente) {
            printf("Código do Produto: %d, Quantidade: %d, Valor Total: %.2f\n",
                   vendas[i].produto.codigo, vendas[i].produto.quantidade, vendas[i].valorTotal);
        }
    }
}

void verPedidos() {
    int codigoProduto;
    printf("Digite o código do produto para ver os pedidos: ");
    scanf("%d", &codigoProduto);
    
    printf("Pedidos para o produto %d:\n", codigoProduto);
    for(int i = 0; i < qtdVendas; i++) {
        if(vendas[i].produto.codigo == codigoProduto) {
            printf("Código do Cliente: %d, Quantidade: %d, Valor Total: %.2f\n",
                   vendas[i].cliente.codigo, vendas[i].produto.quantidade, vendas[i].valorTotal);
        }
    }
}

void emprimirClientes() {
    FILE *arquivo = fopen("C:\\Users\\Public\\Documents\\clientes.txt", "w");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    for(int i = 0; i < qtdClientes; i++) {
        fprintf(arquivo, "Código: %d, Nome: %s, CPF: %s, Data de Nascimento: %s\n",
                clientes[i].codigo, clientes[i].nome, clientes[i].cpf, clientes[i].dataNascimento);
    }
    fclose(arquivo);
    printf("Clientes impressos com sucesso!\n");
}

void emprimirProdutos() {
    FILE *arquivo = fopen("C:\\Users\\Public\\Documents\\produtos.txt", "w");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    for(int i = 0; i < qtdProdutos; i++) {
        fprintf(arquivo, "Código: %d, Nome: %s, Preço: %.2f, Marca: %s\n",
                estoque[i].codigo, estoque[i].nome, estoque[i].preco, estoque[i].marca);
    }
    fclose(arquivo);
    printf("Produtos impressos com sucesso!\n");
}

void emprimirPedidos() {
    FILE *arquivo = fopen("C:\\Users\\Public\\Documents\\pedidos.txt", "w");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    for(int i = 0; i < qtdVendas; i++) {
        fprintf(arquivo, "Código Cliente: %d, Código Produto: %d, Quantidade: %d, Valor Total: %.2f\n",
                vendas[i].cliente.codigo, vendas[i].produto.codigo, vendas[i].produto.quantidade, vendas[i].valorTotal);
    }
    fclose(arquivo);
    printf("Pedidos impressos com sucesso!\n");
}

void emprimirCaixa() {
    FILE *arquivo = fopen("C:\\Users\\Public\\Documents\\caixa.txt", "w");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    emprimirClientes();
    emprimirProdutos();
    emprimirPedidos();
    fclose(arquivo);
    printf("Informações do caixa impressas com sucesso!\n");
}


void docVendaCaixa() {
    int codigoProduto, quantidade;
    float valorUnitario, totalVenda = 0, valorPago, troco;
    char continuar;

    FILE *arquivo = fopen("C:\\Users\\Public\\Documents\\caixa.txt", "a");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    do {
        printf("Digite o código do produto: ");
        scanf("%d", &codigoProduto);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &quantidade);
        printf("Digite o valor unitário do produto: ");
        scanf("%f", &valorUnitario);

        float subtotal = quantidade * valorUnitario;
        totalVenda += subtotal;

        fprintf(arquivo, "Código Produto: %d, Quantidade: %d, Subtotal: %.2f\n",
                codigoProduto, quantidade, subtotal);

        printf("Deseja adicionar mais produtos? (S/N): ");
        scanf(" %c", &continuar);
    } while(continuar == 'S' || continuar == 's');

    printf("Total da venda: %.2f\n", totalVenda);
    fprintf(arquivo, "Total da venda: %.2f\n", totalVenda);

    printf("Digite o valor pago pelo cliente: ");
    scanf("%f", &valorPago);
    troco = valorPago - totalVenda;

    printf("Troco: %.2f\n", troco);
    fprintf(arquivo, "Valor pago: %.2f, Troco: %.2f\n", valorPago, troco);

    fclose(arquivo);
    printf("Venda registrada com sucesso!\n");
}

void administrarCaixa() {
    int menuCaixa;
    printf("                B e m - V i n d o  A o  C a i x a    ");
    printf("\n");
    printf("\n|   1 R e g i s t r a r  V e n d a  |  2 S a i r  D o  C a i x a|\n");
    printf("\n");
    printf("Escolha uma opção:\n");
    scanf("%d", &menuCaixa);

    switch(menuCaixa) {
        case 1:
            docVendaCaixa();
            break;
        case 2:
            printf("Fechando o caixa...\n");
            break;
        default:
            printf("Opção inválida!\n");
    }
}

//Aqui fica a int main com ligação a todas as funções em void
int main() {
		_tsetlocale(LC_ALL, _T("portuguese"));
    int menu, submenu;
    char menuStr[10];

    while(1) {
    	printf("      ");
        printf("\n       |   C o t o y  -  T o y l a n d   |\n");
        printf("       ");
        printf("\n         G e s t ã o   d e   v e n d a s             ");
        printf("\n  ");
        printf("\n|   1 C a d a s t r a r  |  2 A d m i n i s t r a r   |\n");
        printf("|   3 I m pr e s s ã o   |      4  C a i x a          |");
        printf("\n");
        printf("\n Escolha uma opção:");
        
        
        
        scanf("%9s", menuStr);

        int isNumber = 1;
        for(int i = 0; 2 < strlen(menuStr); i++) {
            if(!isdigit(menuStr[i])) {
                isNumber = 0;
                break;
            }
        }
//Por diante será as funções de Case em relação as funções no void para o preenchimento de informações
        if(isNumber) {
            menu = atoi(menuStr);
        switch(menu) {
            case 1:
            	printf("     ");
                printf("\n                E s c o l h a  o  C a d a s t r o     \n");
                printf("\n");
                printf("|         1 C l i e n t e              |    2 P r o d u t o          |");
                printf("\n| 3 F o r m a  d e  P a g a m e n t o  |   4 V e r  E s t o q u e    |\n");
                printf("                                5 Voltar                                       ");
                printf("\n Escola uma opção:\n");
                
                scanf("%d", &submenu);
                switch(submenu) {
                    case 1:
                        cadastrarCliente();
                        break;
                    case 2:
                        cadastrarProduto();
                        break;
                    case 3:
                        cadastrarFormaPagamento();
                        break;
                    case 4:
                        verEstoque();
                        break;
                    case 5:
                    	printf("\nVoltando ao menu inicial. . .\n");
                    	break;
                    default:
                        printf("Opção inválida!\n");
                } 
                break;
            case 2:
                 printf("\n          A d m n i s t r a ç ã o  d e  V e n d a s \n");
                 printf("\n");
                 printf("|     1 V e n d e r  P r o d u t o  |     2 H i s t o r i c o  |");
                 printf("\n|         3 P e d i d o s           |     4 V o l t a r        |\n");
                printf("Escolha uma opção:\n");
                scanf("%d", &submenu);
                switch(submenu) {
                    case 1:
                        venderProduto();
                        break;
                    case 2:
                        verHistoricoVendas();
                        break;
                    case 3:
                        verPedidos();
                        break;
                    case 4:
                    	printf("\nVoltando ao menu inicial. . .\n");
                    	break;
                    default:
                        printf("Opção inválida!\n");
                }
                break;
            case 3:
                printf("\n      E s c o l h a  o  c o n t e u d o  d á  i m p r e s s ã o       \n");
                printf("\n");
                printf("|               1 C l i e n t e      |        2 P r o d u t o           |");
                printf("\n|               3 P e d i d o        |        4  C a i x a              |\n");
                printf("                              5 Voltar                                  |");
                printf("\n");
                printf("Escolha uma opção:\n");
                scanf("%d", &submenu);
                switch(submenu) {
                    case 1:
                        emprimirClientes();
                        break;
                    case 2:
                        emprimirProdutos();
                        break;
                    case 3:
                        emprimirPedidos();
                        break;
                    case 4:
                        emprimirCaixa();
                        break;
                    default:
                        printf("Opção inválida!\n");
                }
                break;
            case 4: //Era mais facil ter colocado tudo no void e só usado os case pra colocar tudo na int main.......................................
            	
                
                administrarCaixa();
                break;
            case 5:
                printf("Saindo do sistema...\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        } 
		} else {
            printf("Opção inválida! Por favor, digite um número.\n");
        }
    }
    return 0;
}
