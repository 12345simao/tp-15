#include "ViaturaTeste.hpp"
#include <iostream>

using namespace std;

// Testa criação e exibição de objetos Viatura
void ViaturaTeste::Teste1() {
    cout << "\n### Teste 1: Criação e Exibição das matriculas  das Viaturas ###\n";

    // Criação de objetos Viatura
	Viatura viatura1("AA-01-BB");// Criação de objetos Viatura
	Viatura viatura2("CC-02-DD");// Criação de objetos Viatura

    // Exibição de valores iniciais
    cout << "Viatura 1: " << viatura1.toString() << endl;
	cout << "Viatura 2: " << viatura2.toString() << endl;
}

// Testa modificação de atributos e liberação de memória
void ViaturaTeste::Teste2() {
    cout << "\n### Teste 2: Modificação de matruculas e Liberação de Viaturas ###\n";

    // Criação de um objeto Viatura
	Viatura* viatura = new Viatura("AA-01-BB");// Criação de objetos Viatura

    // Exibição da matrícula inicial
	cout << "Matrícula inicial: " << viatura->getMatricula() << endl;

    // Modificação da matrícula
	viatura->setMatricula("DD-03-EE");// Modificação da matrícula
	cout << "Nova Matrícula: " << viatura->getMatricula() << endl;// Exibição da nova matrícula

    // Liberação de memória
	delete viatura;
    cout << "Viatura desalocada com sucesso.\n";
}