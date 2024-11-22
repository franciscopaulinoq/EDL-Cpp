#include <iostream>
#include <fstream>
#include <sstream>
#include "Polinomio.h"

using namespace std;

#include <regex>

int main()
{
    ifstream arquivo("resources/input.txt");
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquvio de entrada.\n";
        return 1;
    }

    string linha;

    while (getline(arquivo, linha))
    {
        try
        {
            stringstream ss(linha);
            string index;
            ss >> index;

            if (index == "+" || index == "-" || index == "*")
            {
                string pol1, pol2;
                if (!getline(arquivo, pol1))
                {
                    cerr << "Erro: Esperado um polinomio apos o operador " << index << "\n";
                    break;
                }
                if (!getline(arquivo, pol2))
                {
                    cerr << "Erro: Esperado um segundo polinomio apos o operador " << index << "\n";
                    continue;
                }

                Polinomio polinomio1 = Polinomio::parser(pol1);
                Polinomio polinomio2 = Polinomio::parser(pol2);

                Polinomio resultado;

                if (index == "+")
                {
                    resultado = polinomio1 + polinomio2;
                    cout << "Soma: " << resultado << endl;
                }
                else if (index == "-")
                {
                    resultado = polinomio1 - polinomio2;
                    cout << "Substracao: " << resultado << endl;
                }
                else
                {
                    resultado = polinomio1 * polinomio2;
                    cout << "Multiplicacao: " << resultado << endl;
                }
            }
            else if (index == "g" || index == "G")
            {
                string pol;
                if (!getline(arquivo, pol))
                {
                    cerr << "Erro: Esperado um polinomio apos o operador " << index << "\n";
                    continue;
                }

                Polinomio polinomio = Polinomio::parser(pol);
                cout << "Grau do polinomio: " << polinomio.obterGrau() << endl;
            }
            else if (index == "t" || index == "T")
            {
                string pol;
                if (!getline(arquivo, pol))
                {
                    cerr << "Erro: Esperado um polinomio apos o operador " << index << "\n";
                    continue;
                }

                Polinomio polinomio = Polinomio::parser(pol);
                cout << "Termos do polinomio: " << polinomio.obterTamanho() << endl;
            }
            else if (index == "a" || index == "A")
            {
                string x, pol;
                if (!getline(arquivo, x))
                {
                    cerr << "Erro: Esperado um valor de x apos o operador " << index << "\n";
                    continue;
                }

                if (!getline(arquivo, pol))
                {
                    cerr << "Erro: Esperado um polinomio apos o valor de x.\n";
                    continue;
                }

                double valor;
                try
                {
                    valor = stod(x);
                }
                catch (...)
                {
                    cerr << "Erro: Valor de x invalido: " << x << "\n";
                    continue;
                }

                Polinomio polinomio = Polinomio::parser(pol);
                cout << "Avaliacao do polinomio com x = " << valor << ": " << polinomio.avaliar(valor) << endl;
            }
            else if (index == "p" || index == "P")
            {
                string pol;
                if (!getline(arquivo, pol))
                {
                    cerr << "Erro: Esperado um polinomio apos o operador " << index << "\n";
                    continue;
                }

                Polinomio polinomio = Polinomio::parser(pol);
                cout << "Polinomio: " << polinomio << endl;
            }
            else
            {
                cerr << "Operador desconhecido ou invalido: " << index << endl;
            }
        }
        catch (const std::exception &e)
        {
            cerr << "Erro: " << e.what() << "\n";
        }
    }

    cout << endl;

    return 0;
}