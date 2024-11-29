#include "ViaturaTeste.hpp"
#include <iostream>

using namespace std;

// Testa cria��o e exibi��o de objetos Viatura
void ViaturaTeste::Teste1() {
    cout << "\n### Teste 1: Cria��o e Exibi��o das matriculas  das Viaturas ###\n";

    // Cria��o de objetos Viatura
	Viatura viatura1("AA-01-BB");// Cria��o de objetos Viatura
	Viatura viatura2("CC-02-DD");// Cria��o de objetos Viatura

    // Exibi��o de valores iniciais
    cout << "Viatura 1: " << viatura1.toString() << endl;
	cout << "Viatura 2: " << viatura2.toString() << endl;
}

// Testa modifica��o de atributos e libera��o de mem�ria
void ViaturaTeste::Teste2() {
    cout << "\n### Teste 2: Modifica��o de matruculas e Libera��o de Viaturas ###\n";

    // Cria��o de um objeto Viatura
	Viatura* viatura = new Viatura("AA-01-BB");// Cria��o de objetos Viatura

    // Exibi��o da matr�cula inicial
	cout << "Matr�cula inicial: " << viatura->getMatricula() << endl;

    // Modifica��o da matr�cula
	viatura->setMatricula("DD-03-EE");// Modifica��o da matr�cula
	cout << "Nova Matr�cula: " << viatura->getMatricula() << endl;// Exibi��o da nova matr�cula

    // Libera��o de mem�ria
	delete viatura;
    cout << "Viatura desalocada com sucesso.\n";
}