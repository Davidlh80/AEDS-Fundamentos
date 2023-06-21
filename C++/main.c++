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

void excluirCliente() {
    ofstream arquivo("teste.txt");
    if (arquivo.is_open()) {
        // Arquivo aberto com sucesso, portanto está vazio agora
        arquivo.close();
        cout << "Dados excluídos do arquivo com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
}

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

         ofstream arquivo("teste.txt", ios::app);
    if (arquivo.is_open()) {
        // Escrever as informações do cliente no arquivo
        arquivo << "Informações do cliente cadastrado:" << endl;
        arquivo << "Nome: " << cliente.nome << endl;
        arquivo << "Nome: " << cliente.telefone << endl;
        arquivo << "Nome: " << cliente.dataNascimento << endl;
        arquivo << "Endereço: " << cliente.endereco.rua << endl;
        arquivo << "Endereço: " << cliente.endereco.numero << endl;
        arquivo << "Endereço: " << cliente.endereco.bairro << endl;

        // Fechar o arquivo
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
}   

void cadastrarFornecedor() {
    cout << "Função de cadastro de fornecedor chamada!" << endl;
    // Implemente a lógica para cadastrar um fornecedor aqui
}

int main() {

    string escolha;

    cout << "Digite '1' para cadastrar um cliente '2' para cadastrar um fornecedor ou '3' para limpar o arquivo: ";
    cin >> escolha;

    if (escolha == "1") {
        cadastrarCliente();
    } else if (escolha == "2") {
        cadastrarFornecedor();
    } else if (escolha == "3"){
        excluirCliente();
    }else{
        cout << "Opção inválida!" << endl;
    }

    return 0;
}