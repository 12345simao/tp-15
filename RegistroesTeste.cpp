#include "RegistroesTeste.hpp"
#include <iostream>

using namespace std;

// Testa a criação e exibição de objetos da classe Registo
void RegistroesTeste::Teste1() {
    try {
        setlocale(LC_ALL, "Portuguese");

        // Criando uma viatura e horário de entrada
        Viatura viatura1("AB-12-BB"); // Criação de uma viatura com matrícula
        Hora entrada1(10, 30);        // Criação de uma hora de entrada
        Registo reg1(viatura1, entrada1); // Criação de um registo para a viatura com a hora de entrada

        // Testando o método toString() para exibir os dados do registo
        cout << reg1.toString() << endl;

        // Verificando se a viatura está estacionada (ainda não saiu)
        if (reg1.estaEstacionado(viatura1.getMatricula())) {
            cout << "A viatura " << viatura1.getMatricula() << " está estacionada." << endl;
        }
        else {
            cout << "A viatura " << viatura1.getMatricula() << " não está estacionada.\n" << endl;
        }

        // Calculando os minutos de estacionamento até uma hora atual antes de registar a saída
        Hora horaAtual(12, 00); // Simula uma hora atual
        cout << "Minutos de estacionamento até " << horaAtual.toString() << ": "
            << reg1.minutosEstacionamento(horaAtual) << " minutos." << endl;

        // Registando a saída da viatura
        Hora saida1(12, 45); // Define a hora de saída
        cout << "Registando saída às " << saida1.toString() << "..." << endl;
        int minutosEstacionados1 = reg1.registaSaida(saida1); // Regista a saída e calcula os minutos
        cout << "Tempo total de estacionamento: " << minutosEstacionados1 << " minutos." << endl;

        // Testando o método toString() após registar a saída
        cout << reg1.toString() << endl;

        // Tentando marcar o registo como pago
        if (!reg1.isPago()) { // Verifica se o pagamento ainda não foi feito
            reg1.paga();      // Marca o registo como pago
            cout << "Pagamento realizado com sucesso." << endl;
        }
        else {
            cout << "Pagamento já foi realizado." << endl;
        }

        // Verificando novamente o estado do registo após o pagamento
        cout << reg1.toString() << endl;

    }
    catch (const exception& e) {
        // Captura erros gerais e exibe a mensagem de erro
        cerr << "Erro geral: " << e.what() << endl;
    }

    // Testando registar uma saída novamente (não permitido)
    try {
        Viatura viaturaNova("CD-34-EF"); // Criação de uma nova viatura
        Hora entradaNova(14, 00);        // Define a hora de entrada
        Registo regNovo(viaturaNova, entradaNova); // Criação de um novo registo

        // Testa o método toString() para exibir os dados do novo registo
        cout << regNovo.toString() << endl;

        // Registando uma nova saída
        Hora novaSaida(16, 15); // Define a hora de saída
        cout << "Registando nova saída às " << novaSaida.toString() << " para o novo registo..." << endl;
        int minutosEstacionadosNovo = regNovo.registaSaida(novaSaida); // Regista a saída e calcula os minutos
        cout << "Tempo total de estacionamento (novo registo): " << minutosEstacionadosNovo << " minutos." << endl;

        // Testa o método toString() após registar a saída
        cout << regNovo.toString() << endl;

        // Tentando registar uma saída novamente (deve lançar exceção)
        Hora saidaInvalida(17, 00); // Define uma segunda tentativa de registar a saída
        cout << "Tentando registar uma nova saída inválida para o novo registo às " << saidaInvalida.toString() << "..." << endl;
        regNovo.registaSaida(saidaInvalida); // Deve lançar exceção
    }
    catch (const logic_error& e) {
        cerr << "Erro ao tentar registar uma nova saída para o novo registo: " << e.what() << endl;
    }

    // Testando registar uma saída anterior à hora de entrada
    try {
        Viatura viatura2("CD-5678"); // Criação de uma nova viatura
        Hora entrada2(14, 00);       // Define a hora de entrada
        Registo reg2(viatura2, entrada2); // Criação de um novo registo
        Hora saida2(13, 00);         // Define uma hora de saída anterior à entrada
        cout << "Tentando registar uma saída anterior à entrada..." << endl;
        reg2.registaSaida(saida2);   // Deve lançar exceção
    }
    catch (const invalid_argument& e) {
        cerr << "Erro ao registar uma saída anterior à entrada: " << e.what() << endl;
    }

    // Testando calcular os minutos de estacionamento sem saída registada
    try {
        Viatura viatura3("EF-9012"); // Criação de uma nova viatura
        Hora entrada3(15, 20);       // Define a hora de entrada
        Registo reg3(viatura3, entrada3); // Criação de um novo registo
        cout << "Calculando minutos de estacionamento sem saída registada para a viatura "
            << viatura3.getMatricula() << "..." << endl;
        Hora horaAtual2(17, 00); // Define uma hora atual para cálculo
        cout << "Minutos de estacionamento até " << horaAtual2.toString() << ": "
            << reg3.minutosEstacionamento(horaAtual2) << " minutos." << endl;
    }
    catch (const exception& e) {
        cerr << "Erro ao calcular minutos de estacionamento: " << e.what() << endl;
    }
}
