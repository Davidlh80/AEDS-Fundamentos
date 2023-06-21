#include <iostream>

using namespace std;

int main()
{
    float valor = 0.0f;
    int qtdPessoas = 0;
    int diaSemana = 0;
    int formaPagamento = 0;

    cout << "Informe a quantidade de pessoas: ";
    cin >> qtdPessoas;
    cout << "Informe o dia da semana (1-7): ";
    cin >> diaSemana;
    cout << "Informe o número de parcelas (1-3): ";
    cin >> formaPagamento;

    if (qtdPessoas <= 30)
    {
        if (diaSemana > 1 && diaSemana < 6)
        {
            valor = 1899.0f;
        }
        else if (diaSemana == 1 || diaSemana == 7 || diaSemana == 6)
        {
            valor = 2099.0f;
        }
    }

    if (formaPagamento == 1)
    {
        valor *= 0.9f;
    }
    else if (formaPagamento == 2)
    {
        valor *= 0.95f;
    }
    else if (formaPagamento == 3)
    {
        valor *= 0.98f;
    }

    cout << "Valor final: " << valor << endl;

    return 0;
}

