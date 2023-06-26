#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>  // Inclus�o do cabe�alho para stringstream
#include <locale.h>

using namespace std;

struct Cliente
{
    int codigo;
    string nome;
    string endereco;
    string telefone;
    string dataNascimento;
};

struct Fornecedor
{
    int codigo;
    string nomeBuffet;
    string telefone;
};

struct Festa
{
    int codigoFesta;
    int quantidadeConvidados;
    string data;
    string diaSemana;
    string horarioInicio;
    string horarioFim;
    string tema;
    int codigoCliente;
    int codigoFornecedor;
};

struct Contrato
{
    int numeroContrato;
    double valorTotal;
    double desconto;
    double valorFinal;
    string formaPagamento;
    string status;
    int codigoFesta;
};

// Fun��o para cadastrar um cliente
void cadastrarCliente(vector<Cliente>& clientes)
{
    Cliente cliente;
    // L�gica para gerar um c�digo autom�tico ou permitir que o usu�rio insira o c�digo

    // Solicitar informa��es do cliente
    cout << "C�digo do cliente: ";
    cin >> cliente.codigo;
    cin.ignore(); // Limpar o buffer do teclado
    cout << "Nome: ";
    getline(cin, cliente.nome);
    cout << "Endere�o: ";
    getline(cin, cliente.endereco);
    cout << "Telefone: ";
    getline(cin, cliente.telefone);
    cout << "Data de nascimento: ";
    getline(cin, cliente.dataNascimento);

    // Verificar se n�o h� duplicatas de c�digo de cliente
    for (const auto& c : clientes)
    {
        if (c.codigo == cliente.codigo)
        {
            cout << "Erro: J� existe um cliente com o c�digo fornecido." << endl;
            return;
        }
    }

    // Armazenar as informa��es do cliente em um arquivo de texto
    ofstream arquivoClientes("clientes.txt", ios::app);
    if (arquivoClientes.is_open())
    {
        arquivoClientes << cliente.codigo << "," << cliente.nome << "," << cliente.endereco << ","
                        << cliente.telefone << "," << cliente.dataNascimento << endl;
        arquivoClientes.close();
        cout << "Cliente cadastrado com sucesso." << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo de clientes." << endl;
    }
}

// Fun��o para cadastrar um fornecedor
void cadastrarFornecedor(vector<Fornecedor>& fornecedores)
{
    Fornecedor fornecedor;
    // L�gica para gerar um c�digo autom�tico ou permitir que o usu�rio insira o c�digo

    // Solicitar informa��es do fornecedor
    cout << "C�digo do fornecedor: ";
    cin >> fornecedor.codigo;
    cin.ignore(); // Limpar o buffer do teclado
    cout << "Nome do buffet: ";
    getline(cin, fornecedor.nomeBuffet);
    cout << "Telefone: ";
    getline(cin, fornecedor.telefone);

    // Verificar se n�o h� duplicatas de c�digo de fornecedor
    for (const auto& f : fornecedores)
    {
        if (f.codigo == fornecedor.codigo)
        {
            cout << "Erro: J� existe um fornecedor com o c�digo fornecido." << endl;
            return;
        }
    }

    // Armazenar as informa��es do fornecedor em um arquivo de texto
    ofstream arquivoFornecedores("fornecedores.txt", ios::app);
    if (arquivoFornecedores.is_open())
    {
        arquivoFornecedores << fornecedor.codigo << "," << fornecedor.nomeBuffet << "," << fornecedor.telefone << endl;
        arquivoFornecedores.close();
        cout << "Fornecedor cadastrado com sucesso." << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo de fornecedores." << endl;
    }
}

// Fun��o para cadastrar uma festa
void cadastrarFesta(vector<Festa>& festas)
{
    Festa festa;
    // L�gica para gerar um c�digo autom�tico ou permitir que o usu�rio insira o c�digo

    // Solicitar informa��es da festa
    cout << "C�digo da festa: ";
    cin >> festa.codigoFesta;
    cout << "Quantidade de convidados: ";
    cin >> festa.quantidadeConvidados;
    cin.ignore(); // Limpar o buffer do teclado
    cout << "Data (DD/MM/AAAA): ";
    getline(cin, festa.data);
    cout << "Dia da semana: ";
    getline(cin, festa.diaSemana);
    cout << "Hor�rio de in�cio: ";
    getline(cin, festa.horarioInicio);
    cout << "Hor�rio de fim: ";
    getline(cin, festa.horarioFim);
    cout << "Tema: ";
    getline(cin, festa.tema);
    cout << "C�digo do cliente: ";
    cin >> festa.codigoCliente;
    cout << "C�digo do fornecedor: ";
    cin >> festa.codigoFornecedor;

    // Verificar se a data e o hor�rio da festa est�o dispon�veis
    for (const auto& f : festas)
    {
        if (f.data == festa.data && f.horarioInicio == festa.horarioInicio)
        {
            cout << "Erro: J� existe uma festa agendada para a data e hor�rio fornecidos." << endl;
            return;
        }
    }

    // Armazenar as informa��es da festa em um arquivo de texto
    ofstream arquivoFestas("festas.txt", ios::app);
    if (arquivoFestas.is_open())
    {
        arquivoFestas << festa.codigoFesta << "," << festa.quantidadeConvidados << "," << festa.data << ","
                      << festa.diaSemana << "," << festa.horarioInicio << "," << festa.horarioFim << ","
                      << festa.tema << "," << festa.codigoCliente << "," << festa.codigoFornecedor << endl;
        arquivoFestas.close();
        cout << "Festa cadastrada com sucesso." << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo de festas." << endl;
    }
}











// Fun��o para calcular o valor total e final do contrato
void calcularValorContrato()
{
    int formaPagamento = 0;

    // Abrir o arquivo festas.txt
    ifstream arquivo("festas.txt");
    if (!arquivo)
    {
        cout << "Erro ao abrir o arquivo festas.txt" << endl;
        return;
    }

    cout << "Informe o n�mero de parcelas (1-3): ";
    cin >> formaPagamento;

    string linha;
    while (getline(arquivo, linha))
    {
        stringstream ss(linha);
        int codigoFesta, quantidadeConvidados, codigoCliente, codigoFornecedor;
        string data, diaSemanaStr, horarioInicio, horarioFim, tema;

        // Extrair os dados da linha
        ss >> codigoFesta;
        ss.ignore();
        ss >> quantidadeConvidados;
        ss.ignore();
        getline(ss, data, ',');
        getline(ss, diaSemanaStr, ',');
        getline(ss, horarioInicio, ',');
        getline(ss, horarioFim, ',');
        getline(ss, tema, ',');
        ss >> codigoCliente;
        ss.ignore();
        ss >> codigoFornecedor;

        // Converter dia da semana para inteiro
        int diaSemana = stoi(diaSemanaStr);

        // Verificar se os dados s�o v�lidos
        if (quantidadeConvidados <= 0 || diaSemana < 1 || diaSemana > 7)
        {
            cout << "Dados inv�lidos para a festa de c�digo " << codigoFesta << endl;
            continue;
        }

        // Calcular o valor do contrato
        double valor = 0.0;
        if (quantidadeConvidados <= 30)
        {
            if (diaSemana > 1 && diaSemana < 6)
            {
                valor = 1899.0;
            }
            else if (diaSemana == 1 || diaSemana == 7 || diaSemana == 6)
            {
                valor = 2099.0;
            }
        }
        else if (quantidadeConvidados > 30 && quantidadeConvidados <= 50)
        {
            if (diaSemana > 1 && diaSemana < 6)
            {
                valor = 2199.0;
            }
            else if (diaSemana == 1 || diaSemana == 7 || diaSemana == 6)
            {
                valor = 2299.0;
            }
        }
        else if (quantidadeConvidados > 50 && quantidadeConvidados <= 80)
        {
            if (diaSemana > 1 && diaSemana < 6)
            {
                valor = 3199.0;
            }
            else if (diaSemana == 1 || diaSemana == 7 || diaSemana == 6)
            {
                valor = 3499.0;
            }
        }
        else if (quantidadeConvidados > 80 && quantidadeConvidados <= 100)
        {
            if (diaSemana > 1 && diaSemana < 6)
            {
                valor = 3799.0;
            }
            else if (diaSemana == 1 || diaSemana == 7 || diaSemana == 6)
            {
                valor = 4099.0;
            }
        }
        else
        {
            cout << "Quantidade de convidados inv�lida para a festa de c�digo " << codigoFesta << endl;
            continue;
        }

        // Aplicar desconto para pagamento � vista
        if (formaPagamento == 1)
        {
            valor *= 0.9;
        }

        // Aplicar desconto para pagamento 2 vezes
        if (formaPagamento == 2)
        {
            valor *= 0.95;
        }

        // Aplicar desconto para pagamento 3 vezes
        if (formaPagamento == 3)
        {
            valor *= 0.98;
        }


        // Exibir o valor do contrato
        cout << "Valor total do contrato para a festa de c�digo " << codigoFesta << ": R$" << valor << endl;
    }

    // Fechar o arquivo festas.txt
    arquivo.close();
}












// Fun��o para exibir os clientes cadastrados
void exibirClientes()
{
    ifstream arquivoClientes("clientes.txt");
    if (arquivoClientes.is_open())
    {
        string linha;
        while (getline(arquivoClientes, linha))
        {
            // Extrair informa��es da linha
            stringstream ss;
            ss.str(linha);
            string item;

            getline(ss, item, ',');
            int codigo = stoi(item);

            getline(ss, item, ',');
            string nome = item;

            getline(ss, item, ',');
            string endereco = item;

            getline(ss, item, ',');
            string telefone = item;

            getline(ss, item, ',');
            string dataNascimento = item;

            // Exibir as informa��es do cliente
            cout << "C�digo: " << codigo << endl;
            cout << "Nome: " << nome << endl;
            cout << "Endere�o: " << endereco << endl;
            cout << "Telefone: " << telefone << endl;
            cout << "Data de Nascimento: " << dataNascimento << endl;
            cout << endl;
        }
        arquivoClientes.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo de clientes." << endl;
    }
}



// Fun��o para exibir os fornecedores cadastrados
void exibirFornecedores()
{
    std::ifstream arquivo("fornecedores.txt");
    std::string linha;

    if (arquivo.is_open())
    {
        while (getline(arquivo, linha))
        {
            std::stringstream ss(linha);
            std::string codigo, nome, telefone;

            getline(ss, codigo, ',');
            getline(ss, nome, ',');
            getline(ss, telefone, ',');

            std::cout << "C�digo: " << codigo << std::endl;
            std::cout << "Nome: " << nome << std::endl;
            std::cout << "Telefone: " << telefone << std::endl;
            std::cout << std::endl;
        }

        arquivo.close();
    }
    else
    {
        std::cout << "Erro ao abrir o arquivo fornecedores.txt" << std::endl;
    }
}

// Fun��o para exibir as festas cadastradas
void exibirFestas()
{
    ifstream arquivo("festas.txt");
    if (!arquivo)
    {
        cout << "Erro ao abrir o arquivo festas.txt" << endl;
        return;
    }

    cout << "Festas cadastradas:" << endl;
    cout << "--------------------" << endl;

    string linha;
    while (getline(arquivo, linha))
    {
        stringstream ss(linha);
        int codigoFesta, quantidadeConvidados, codigoCliente, codigoFornecedor;
        string data, diaSemana, horarioInicio, horarioFim, tema;

        // Extrair os dados da linha
        ss >> codigoFesta;
        ss.ignore();
        ss >> quantidadeConvidados;
        ss.ignore();
        getline(ss, data, ',');
        getline(ss, diaSemana, ',');
        getline(ss, horarioInicio, ',');
        getline(ss, horarioFim, ',');
        getline(ss, tema, ',');
        ss >> codigoCliente;
        ss.ignore();
        ss >> codigoFornecedor;

        // Exibir os dados
        cout << "C�digo da Festa: " << codigoFesta << endl;
        cout << "Quantidade de Convidados: " << quantidadeConvidados << endl;
        cout << "Data: " << data << endl;
        cout << "Dia da Semana: " << diaSemana << endl;
        cout << "Hor�rio de In�cio: " << horarioInicio << endl;
        cout << "Hor�rio de Fim: " << horarioFim << endl;
        cout << "Tema: " << tema << endl;
        cout << "C�digo do Cliente: " << codigoCliente << endl;
        cout << "C�digo do Fornecedor: " << codigoFornecedor << endl;
        cout << "--------------------" << endl;
    }

    arquivo.close();
}




// Fun��o para exibir os contratos cadastrados
void exibirContratos()
{
    ifstream arquivoContratos("contratos.txt");
    if (arquivoContratos.is_open())
    {
        string linha;
        while (getline(arquivoContratos, linha))
        {
            // Extrair informa��es da linha
            int numeroContrato;
            double valorTotal, desconto, valorFinal;
            string formaPagamento;
            // L�gica para extrair as informa��es da linha

            // Exibir as informa��es do contrato
            cout << "N�mero do contrato: " << numeroContrato << endl;
            cout << "Valor total: " << valorTotal << endl;
            cout << "Desconto: " << desconto << endl;
            cout << "Valor final: " << valorFinal << endl;
            cout << "Forma de pagamento: " << formaPagamento << endl;
            cout << endl;
        }
        arquivoContratos.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo de contratos." << endl;
    }
}

int main()
{
    vector<Cliente> clientes;
    vector<Fornecedor> fornecedores;
    vector<Festa> festas;
    vector<Contrato> contratos;

    setlocale(LC_ALL,"portuguese");

    int opcao;
    do
    {
        cout << "===== Sistema de Cadastro de Festas =====" << endl;
        cout << "1. Cadastrar cliente" << endl;
        cout << "2. Cadastrar fornecedor" << endl;
        cout << "3. Cadastrar festa" << endl;
        cout << "4. Calcular valor do contrato" << endl;
        cout << "5. Exibir clientes cadastrados" << endl;
        cout << "6. Exibir fornecedores cadastrados" << endl;
        cout << "7. Exibir festas cadastradas" << endl;
        cout << "8. Exibir contratos cadastrados" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cadastrarCliente(clientes);
            break;
        case 2:
            cadastrarFornecedor(fornecedores);
            break;
        case 3:
            cadastrarFesta(festas);
            break;
        case 4:
            calcularValorContrato();
            break;
        case 5:
            exibirClientes();
            break;
        case 6:
            exibirFornecedores();
            break;
        case 7:
            exibirFestas();
            break;
        case 8:
            exibirContratos();
            break;
        case 0:
            cout << "Saindo do sistema." << endl;
            break;
        default:
            cout << "Op��o inv�lida. Tente novamente." << endl;
        }

        cout << endl;
    }
    while (opcao != 0);

    return 0;
}
