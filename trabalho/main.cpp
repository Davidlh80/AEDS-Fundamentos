#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Endereco {
    string rua;
    string numero;
    string bairro;
};

struct Cliente {
    int codigo;
    string nome;
    Endereco endereco;
    string telefone;
    string dataNascimento;
};

int proximoCodigo = 1;
vector<Cliente> clientes;

void cadastrarCliente() {
    cout << "Função de cadastro de cliente chamada!" << endl;

    Cliente cliente;

    cliente.codigo = proximoCodigo;
    proximoCodigo++;

    cout << "Cadastro de Cliente" << endl;

    cout << "Nome: ";
    cin.ignore();
    getline(cin, cliente.nome);

    cout << "Data de Nascimento: ";
    getline(cin, cliente.dataNascimento);

    cout << "Telefone: ";
    getline(cin, cliente.telefone);

    cout << "Endereco" << endl;
    cout << "Rua: ";
    getline(cin, cliente.endereco.rua);

    cout << "Numero: ";
    getline(cin, cliente.endereco.numero);

    cout << "Bairro: ";
    getline(cin, cliente.endereco.bairro);

    // Adicionar o cliente cadastrado à lista de clientes
    clientes.push_back(cliente);

    cout << "Cliente cadastrado com sucesso!" << endl;
}

void mostrarClientes() {
    cout << "Lista de clientes cadastrados:" << endl;
    for (const auto& cliente : clientes) {
        cout << "\nDados cadastrados:" << endl;
        cout << "Codigo: " << cliente.codigo << endl;
        cout << "Nome: " << cliente.nome << endl;
        cout << "Telefone: " << cliente.telefone << endl;
        cout << "Data de Nascimento: " << cliente.dataNascimento << endl;
        cout << "Endereco: " << cliente.endereco.rua << ", " << cliente.endereco.numero << ", " << cliente.endereco.bairro << endl;
    }
}

void cadastrarFornecedor() {
    cout << "Função de cadastro de fornecedor chamada!" << endl;
    // Implemente a lógica para cadastrar um fornecedor aqui
}

int main() {
    ofstream arquivo;
    arquivo.open("teste.txt", ios::app);
    arquivo << "teste 2 ";
    arquivo.close();

    string escolha;

    cout << "Digite '1' para cadastrar um cliente ou '2' para cadastrar um fornecedor: ";
    cin >> escolha;

    if (escolha == "1") {
        cadastrarCliente();
    } else if (escolha == "2") {
        cadastrarFornecedor();
    } else {
        cout << "Opção inválida!" << endl;
    }

    return 0;
}
