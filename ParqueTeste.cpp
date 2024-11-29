#include "ParqueTeste.hpp"
#include <iostream>

using namespace std;

void ParqueTeste::Teste1() {
    setlocale(LC_ALL, "Portuguese");
    cout << "\n### Testes da classe Parque ###\n";

    // Criar um parque de estacionamento com capacidade para 3 viaturas
    Parque parque("Parque Principal", 3);

    // Criar viaturas e hor�rios de entrada
    Viatura viatura1("AA-11-BB");
    Viatura viatura2("CC-22-DD");
    Viatura viatura3("EE-33-FF");
    Viatura viatura4("GG-44-HH"); // Para testar lota��o excedida

    Hora entrada1(6);
    Hora entrada2(9, 30);
    Hora entrada3(11, 45);
    Hora entrada4(12, 15); // Para a viatura 4

    // Testar estacionamento de viaturas
    cout << "\nTestar estacionamento de viaturas...\n";
    if (parque.estaciona(viatura1, entrada1)) {
        cout << "Viatura 1 estacionada com sucesso!" << endl;
    }
    else {
        cout << "Erro ao estacionar a viatura 1." << endl;
    }

    if (parque.estaciona(viatura2, entrada2)) {
        cout << "Viatura 2 estacionada com sucesso!" << endl;
    }
    else {
        cout << "Erro ao estacionar a viatura 2." << endl;
    }

    if (parque.estaciona(viatura3, entrada3)) {
        cout << "Viatura 3 estacionada com sucesso!" << endl;
    }
    else {
        cout << "Erro ao estacionar a viatura 3." << endl;
    }

    // Testar lota��o excedida
    cout << "\nTestar estacionamento de viatura com parque cheio...\n";
    if (!parque.estaciona(viatura4, entrada4)) {// Se n�o for poss�vel estacionar a viatura 4
        cout << "Parque cheio. Viatura 4 n�o pode ser estacionada!" << endl;
    }

    // Mostrar estado do parque
    cout << "\nEstado do parque:\n";
    cout << parque.toString() << endl;

    // Testar registro de sa�da e c�lculo de valores
    cout << "\nTestar sa�da e c�lculo de valores...\n";
    Hora saida1(10, 0); // Sa�da para a viatura 1
    try {
        double valor1 = parque.saida("AA-11-BB", saida1);
        cout << "Valor pago pela viatura 1: " << valor1 << " euros" << endl;
    }
    catch (const exception& e) {
        cerr << "Erro ao registar sa�da da viatura 1: " << e.what() << endl;
    }

    // Testar sa�da antes da entrada (lan�ar exce��o)
    cout << "\nTestar sa�da antes da entrada (lan�ar exce��o)...\n";
    Hora saidaInvalida(8, 30);
    try {
        parque.saida("CC-22-DD", saidaInvalida);
    }
    catch (const exception& e) {
        cerr << "Erro esperado: " << e.what() << endl;
    }

    // Testar valores faltantes com hora atual
    cout << "\nTestar c�lculo de valores faltantes...\n";
    Hora horaAtual(12);
    try {
        double valorFaltante = parque.valorTotalFaltante(horaAtual);// Calcula o valor total faltante(de todos os carros que ainda est�o no parque) considerando a hora atual
        //neste exemplo a viatura2 ainda est� no parque e tem de pagar 1.40�(1h30) e a viatura3 ainda est� no parque e tem de pagar 0.20�(15min)
        cout << "Valor total faltante: " << valorFaltante << " euros" << endl;
    }
    catch (const exception& e) {// Se houver algum erro
        cerr << "Erro ao calcular valores faltantes: " << e.what() << endl;
    }

    // Testar c�lculo de valores recebidos
    cout << "\nTestar c�lculo de valores recebidos...\n";
    double valorRecebido = parque.valorTotalRecebido();
    cout << "Valor total recebido pelo parque: " << valorRecebido << " euros" << endl;

    // Testar tempo total de estacionamento
    cout << "\nTestar c�lculo do tempo total de estacionamento...\n";
    try {
        Hora tempoTotal = parque.tempoTotalDeEstacionamento("AA-11-BB");
        cout << "Tempo total de estacionamento da viatura 1: " << tempoTotal.toString() << endl;
    }
    catch (const exception& e) {
        cerr << "Erro ao calcular tempo total de estacionamento: " << e.what() << endl;
    }

    // Verificar se uma viatura est� estacionada
    cout << "\nVerificar se uma viatura est� estacionada...\n";
    if (parque.estaEstacionado("EE-33-FF")) {
        cout << "A viatura 3 ainda est� estacionada." << endl;
    }
    else {
        cout << "A viatura 3 j� saiu." << endl;
    }

    // Testar estacionamento ap�s libera��o de espa�o
    cout << "\nTestar estacionamento ap�s libera��o de espa�o...\n";
    if (parque.estaciona(viatura4, entrada4)) {
        cout << "Viatura 4 estacionada com sucesso ap�s libera��o de espa�o!" << endl;
    }
    else {
        cout << "Erro ao estacionar a viatura 4." << endl;
    }

    // Mostrar estado final do parque
    cout << "\nEstado final do parque:\n";
    cout << parque.toString() << endl;

    cout << "\n### Testar per�odos de uma viatura espec�fica ###\n";
    vector<Registo> periodosViatura = parque.getRegistosPorMatricula("AA-11-BB");

    for (const auto& reg : periodosViatura) {
        cout << reg.toString() << endl; // Exibe apenas os registros da viatura
    }
    // Listar os registros antes da ordena��o
    cout << "\n### Listar registros no parque antes da ordena��o ###\n";
    cout << parque.listarRegistos() << endl;

    // Ordenar os registros dentro do parque
    cout << "\n### Ordenar registros por hora de entrada ###\n";
    parque.ordenarRegistos();

    // Listar os registros ap�s a ordena��o
    cout << "\n### Listar registros no parque ap�s a ordena��o ###\n";
    cout << parque.listarRegistos() << endl;
    
}



