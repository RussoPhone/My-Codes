#include <iostream>
#include <string>
#include<tchar.h>

using namespace std;

struct Usuario {
    string nomeCompleto;
    string dataNascimento;
    string cpf;
    string numeroCelular;
    string email;
    string endereco;
};

void cadastrarNovoUsuario(Usuario &usuario) {
    cout << "Por favor, insira as seguintes informações:" << endl;
    cout << "Nome Completo: ";
    cin.ignore();
    getline(cin, usuario.nomeCompleto);
    cout << "Data de Nascimento (dd/mm/aaaa): ";
    getline(cin, usuario.dataNascimento);
    cout << "CPF: ";
    getline(cin, usuario.cpf);
    cout << "Número de Celular: ";
    getline(cin, usuario.numeroCelular);
    cout << "Email: ";
    getline(cin, usuario.email);
   
}

void configuracoesDeConta(Usuario &usuario) {
    int opcao;
    while (true) {
        cout << "================" << endl;
        cout << "1 - Adicionar método de pagamento" << endl;
        cout << "2 - Adicionar endereço" << endl;
        cout << "3 - Alterar número de celular" << endl;
        cout << "4 - Alterar email" << endl;
        cout << "5 - Ver informações da conta" << endl;
        cout << "6 - Voltar ao menu principal" << endl;
        cout << "================" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                int metodoPagamento;
                cout << "Escolha o método de pagamento:" << endl;
                cout << "1 - Crédito" << endl;
                cout << "2 - Débito" << endl;
                cout << "3 - PIX" << endl;
                cin >> metodoPagamento;
                
                cout << "Método de pagamento adicionado." << endl;
                break;
            case 2:
                cout << "Por favor, insira seu endereço:" << endl;
                cin.ignore();
                getline(cin, usuario.endereco);
                cout << "Endereço adicionado." << endl;
                break;
            case 3:
                cout << "Por favor, insira o novo número de celular:" << endl;
                cin.ignore();
                getline(cin, usuario.numeroCelular);
                cout << "Número de celular alterado." << endl;
                break;
            case 4:
                cout << "Por favor, insira o novo email:" << endl;
                cin.ignore();
                getline(cin, usuario.email);
                cout << "Email alterado." << endl;
                break;
            case 5:
                 cout << "Informações da conta:" << endl;
                cout << "Nome: " << usuario.nomeCompleto << endl;
                cout << "Data de Nascimento: " << usuario.dataNascimento << endl;
                cout << "CPF: " << usuario.cpf << endl;
                cout << "Número de Celular: " << usuario.numeroCelular << endl;
                cout << "Email: " << usuario.email << endl;
                break;
            case 6:
                cout << "Voltando ao menu principal..." << endl;
                return;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    }
}

void cadastrarUsuario(Usuario &usuario, bool &cadastrado) {
    cout << "Cadastrando novo usuário..." << endl;
    cadastrarNovoUsuario(usuario); 
    cadastrado = true; 
}

int main() {
	_tsetlocale(LC_ALL, _T("portuguese"));
     int opcao;
    Usuario usuario;
    bool cadastrado = false;

    while (true) {
        cout << "================" << endl;
        if (!cadastrado) {
            cout << "1 - Cadastrar" << endl;
        } else {
            cout << "1 - Configurações de Conta" << endl;
        }
        cout << "2 - Comprar" << endl;
        cout << "3 - Serviços " << endl;
        cout << "4 - Sair" << endl;
        cout << "================" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (!cadastrado) {
                    cadastrarUsuario(usuario, cadastrado);
                } else {
                    configuracoesDeConta(usuario); 
                }
                break;
            case 2:
                cout << "Opção 2 selecionada." << endl;
                // timbuco
                break;
            case 3:
                cout << "Opção 3 selecionada." << endl;
                // timbuco
                break;
            case 4:
                cout << "Saindo do programa..." << endl;
                return 0;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
