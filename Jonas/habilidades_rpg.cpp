#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

string atributos_base[3] = { "Mental", "Físico", "Espiritual" };

struct Habilidade {
    int codigo;
    string descricao;
    int atributo_base;
    int modificador;
};

struct Desafio {
    int dificuldade;
    int atributo_base;
};

Habilidade* cadastrarHabilidade() {
    Habilidade* novaHabilidade = new Habilidade;

    cout << "Informe o código: ";
    cin >> novaHabilidade->codigo;

    cout << "Informe a descrição: ";
    cin.ignore();
    getline(cin, novaHabilidade->descricao);

    cout << "Informe o atributo base (1>Mental, 2>Físico, 3>Espiritual): ";
    cin >> novaHabilidade->atributo_base;

    cout << "Informe o modificador: ";
    cin >> novaHabilidade->modificador;

    return novaHabilidade;
}

Desafio gerarDesafio() {
    Desafio d;
    d.dificuldade = rand() % 30;
    d.atributo_base = rand() % 3;
    return d;
}

int rolarD20() {
    return rand() % 20 + 1;  // Roll a D20 (1-20)
}

int main() {

	setlocale(LC_ALL, "Portuguese");
    srand(static_cast<unsigned>(time(0)));  // Initialize random seed based on time

    cout << "Bem vindo ao sistema de habilidades.\n";

    int op;
    Habilidade* habilidades[100];  // Store up to 100 abilities
    int habilidadesCount = 0;

    do {
        cout << "\n\tMenu\n\t1> Cadastrar nova habilidade\n\t2> Testar habilidades\n\n\t3> Sair\n";
        do {
            cout << "Entre com a opção desejada: ";
            cin >> op;
            if (op != 1 && op != 2 && op != 3)
                cout << "Opção inválida!" << endl;
        } while (op != 1 && op != 2 && op != 3);

        if (op == 1) {
            if (habilidadesCount < 100) {
                habilidades[habilidadesCount] = cadastrarHabilidade();
                habilidadesCount++;
            }
            else {
                cout << "Limite de habilidades alcançado. Não é possível cadastrar mais." << endl;
            }
        }
        else if (op == 2) {
            cout << "\n\tTeste de habilidade" << endl;
            Desafio desafio = gerarDesafio();
            cout << "Desafio enfrentado: " << atributos_base[desafio.atributo_base] << endl;
            cout << "Dificuldade: " << desafio.dificuldade << endl;

            int habilidadeSelecionada;
            cout << "Escolha a habilidade (informe o código): ";
            cin >> habilidadeSelecionada;

            bool habilidadeEncontrada = false;
            for (int i = 0; i < habilidadesCount; i++) {
                if (habilidades[i]->codigo == habilidadeSelecionada) {
                    habilidadeEncontrada = true;
                    if (habilidades[i]->atributo_base != desafio.atributo_base) {
                        cout << "Essa habilidade não pode ser usada para esse desafio." << endl;
                    }
                    else {
                        int valorAleatorio = rolarD20();
                        int resultado = valorAleatorio + habilidades[i]->modificador;
                        cout << "Valor aleatório: " << valorAleatorio << endl;
                        cout << "Resultado do teste: " << resultado << endl;
                        if (resultado >= desafio.dificuldade) {
                            cout << "Você superou esse desafio!" << endl;
                        }
                        else {
                            cout << "Você fracassou nesse desafio..." << endl;
                        }
                    }
                    break;
                }
            }

            if (!habilidadeEncontrada) {
                cout << "Habilidade não encontrada." << endl;
            }
        }
    } while (op != 3);

    // Free dynamically allocated memory for abilities
    for (int i = 0; i < habilidadesCount; i++) {
        delete habilidades[i];
    }

    cout << "Obrigado por utilizar o sistema de habilidades!" << endl;

    return 0;
}
