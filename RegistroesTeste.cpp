#include "RegistroesTeste.hpp"
#include <iostream>

using namespace std;

// Testa a cria��o e exibi��o de objetos da classe Registo
void RegistroesTeste::Teste1() {
    try {
        setlocale(LC_ALL, "Portuguese");

        // Criando uma viatura e hor�rio de entrada
        Viatura viatura1("AB-12-BB"); // Cria��o de uma viatura com matr�cula
        Hora entrada1(10, 30);        // Cria��o de uma hora de entrada
        Registo reg1(viatura1, entrada1); // Cria��o de um registo para a viatura com a hora de entrada

        // Testando o m�todo toString() para exibir os dados do registo
        cout << reg1.toString() << endl;

        // Verificando se a viatura est� estacionada (ainda n�o saiu)
        if (reg1.estaEstacionado(viatura1.getMatricula())) {
            cout << "A viatura " << viatura1.getMatricula() << " est� estacionada." << endl;
        }
        else {
            cout << "A viatura " << viatura1.getMatricula() << " n�o est� estacionada.\n" << endl;
        }

        // Calculando os minutos de estacionamento at� uma hora atual antes de registar a sa�da
        Hora horaAtual(12, 00); // Simula uma hora atual
        cout << "Minutos de estacionamento at� " << horaAtual.toString() << ": "
            << reg1.minutosEstacionamento(horaAtual) << " minutos." << endl;

        // Registando a sa�da da viatura
        Hora saida1(12, 45); // Define a hora de sa�da
        cout << "Registando sa�da �s " << saida1.toString() << "..." << endl;
        int minutosEstacionados1 = reg1.registaSaida(saida1); // Regista a sa�da e calcula os minutos
        cout << "Tempo total de estacionamento: " << minutosEstacionados1 << " minutos." << endl;

        // Testando o m�todo toString() ap�s registar a sa�da
        cout << reg1.toString() << endl;

        // Tentando marcar o registo como pago
        if (!reg1.isPago()) { // Verifica se o pagamento ainda n�o foi feito
            reg1.paga();      // Marca o registo como pago
            cout << "Pagamento realizado com sucesso." << endl;
        }
        else {
            cout << "Pagamento j� foi realizado." << endl;
        }

        // Verificando novamente o estado do registo ap�s o pagamento
        cout << reg1.toString() << endl;

    }
    catch (const exception& e) {
        // Captura erros gerais e exibe a mensagem de erro
        cerr << "Erro geral: " << e.what() << endl;
    }

    // Testando registar uma sa�da novamente (n�o permitido)
    try {
        Viatura viaturaNova("CD-34-EF"); // Cria��o de uma nova viatura
        Hora entradaNova(14, 00);        // Define a hora de entrada
        Registo regNovo(viaturaNova, entradaNova); // Cria��o de um novo registo

        // Testa o m�todo toString() para exibir os dados do novo registo
        cout << regNovo.toString() << endl;

        // Registando uma nova sa�da
        Hora novaSaida(16, 15); // Define a hora de sa�da
        cout << "Registando nova sa�da �s " << novaSaida.toString() << " para o novo registo..." << endl;
        int minutosEstacionadosNovo = regNovo.registaSaida(novaSaida); // Regista a sa�da e calcula os minutos
        cout << "Tempo total de estacionamento (novo registo): " << minutosEstacionadosNovo << " minutos." << endl;

        // Testa o m�todo toString() ap�s registar a sa�da
        cout << regNovo.toString() << endl;

        // Tentando registar uma sa�da novamente (deve lan�ar exce��o)
        Hora saidaInvalida(17, 00); // Define uma segunda tentativa de registar a sa�da
        cout << "Tentando registar uma nova sa�da inv�lida para o novo registo �s " << saidaInvalida.toString() << "..." << endl;
        regNovo.registaSaida(saidaInvalida); // Deve lan�ar exce��o
    }
    catch (const logic_error& e) {
        cerr << "Erro ao tentar registar uma nova sa�da para o novo registo: " << e.what() << endl;
    }

    // Testando registar uma sa�da anterior � hora de entrada
    try {
        Viatura viatura2("CD-5678"); // Cria��o de uma nova viatura
        Hora entrada2(14, 00);       // Define a hora de entrada
        Registo reg2(viatura2, entrada2); // Cria��o de um novo registo
        Hora saida2(13, 00);         // Define uma hora de sa�da anterior � entrada
        cout << "Tentando registar uma sa�da anterior � entrada..." << endl;
        reg2.registaSaida(saida2);   // Deve lan�ar exce��o
    }
    catch (const invalid_argument& e) {
        cerr << "Erro ao registar uma sa�da anterior � entrada: " << e.what() << endl;
    }

    // Testando calcular os minutos de estacionamento sem sa�da registada
    try {
        Viatura viatura3("EF-9012"); // Cria��o de uma nova viatura
        Hora entrada3(15, 20);       // Define a hora de entrada
        Registo reg3(viatura3, entrada3); // Cria��o de um novo registo
        cout << "Calculando minutos de estacionamento sem sa�da registada para a viatura "
            << viatura3.getMatricula() << "..." << endl;
        Hora horaAtual2(17, 00); // Define uma hora atual para c�lculo
        cout << "Minutos de estacionamento at� " << horaAtual2.toString() << ": "
            << reg3.minutosEstacionamento(horaAtual2) << " minutos." << endl;
    }
    catch (const exception& e) {
        cerr << "Erro ao calcular minutos de estacionamento: " << e.what() << endl;
    }
}
