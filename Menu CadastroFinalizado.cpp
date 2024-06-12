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
    cout << "Por favor, insira as seguintes informa��es:" << endl;
    cout << "Nome Completo: ";
    cin.ignore();
    getline(cin, usuario.nomeCompleto);
    cout << "Data de Nascimento (dd/mm/aaaa): ";
    getline(cin, usuario.dataNascimento);
    cout << "CPF: ";
    getline(cin, usuario.cpf);
    cout << "N�mero de Celular: ";
    getline(cin, usuario.numeroCelular);
    cout << "Email: ";
    getline(cin, usuario.email);
   
}

void configuracoesDeConta(Usuario &usuario) {
    int opcao;
    while (true) {
        cout << "================" << endl;
        cout << "1 - Adicionar m�todo de pagamento" << endl;
        cout << "2 - Adicionar endere�o" << endl;
        cout << "3 - Alterar n�mero de celular" << endl;
        cout << "4 - Alterar email" << endl;
        cout << "5 - Ver informa��es da conta" << endl;
        cout << "6 - Voltar ao menu principal" << endl;
        cout << "================" << endl;
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                int metodoPagamento;
                cout << "Escolha o m�todo de pagamento:" << endl;
                cout << "1 - Cr�dito" << endl;
                cout << "2 - D�bito" << endl;
                cout << "3 - PIX" << endl;
                cin >> metodoPagamento;
                
                cout << "M�todo de pagamento adicionado." << endl;
                break;
            case 2:
                cout << "Por favor, insira seu endere�o:" << endl;
                cin.ignore();
                getline(cin, usuario.endereco);
                cout << "Endere�o adicionado." << endl;
                break;
            case 3:
                cout << "Por favor, insira o novo n�mero de celular:" << endl;
                cin.ignore();
                getline(cin, usuario.numeroCelular);
                cout << "N�mero de celular alterado." << endl;
                break;
            case 4:
                cout << "Por favor, insira o novo email:" << endl;
                cin.ignore();
                getline(cin, usuario.email);
                cout << "Email alterado." << endl;
                break;
            case 5:
                 cout << "Informa��es da conta:" << endl;
                cout << "Nome: " << usuario.nomeCompleto << endl;
                cout << "Data de Nascimento: " << usuario.dataNascimento << endl;
                cout << "CPF: " << usuario.cpf << endl;
                cout << "N�mero de Celular: " << usuario.numeroCelular << endl;
                cout << "Email: " << usuario.email << endl;
                break;
            case 6:
                cout << "Voltando ao menu principal..." << endl;
                return;
            default:
                cout << "Op��o inv�lida. Tente novamente." << endl;
        }
    }
}

void cadastrarUsuario(Usuario &usuario, bool &cadastrado) {
    cout << "Cadastrando novo usu�rio..." << endl;
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
            cout << "1 - Configura��es de Conta" << endl;
        }
        cout << "2 - Comprar" << endl;
        cout << "3 - Servi�os " << endl;
        cout << "4 - Sair" << endl;
        cout << "================" << endl;
        cout << "Escolha uma op��o: ";
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
                cout << "Op��o 2 selecionada." << endl;
                // timbuco
                break;
            case 3:
                cout << "Op��o 3 selecionada." << endl;
                // timbuco
                break;
            case 4:
                cout << "Saindo do programa..." << endl;
                return 0;
            default:
                cout << "Op��o inv�lida. Tente novamente." << endl;
        }
    }

    return 0;
}
