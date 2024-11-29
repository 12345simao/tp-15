#include "ParqueTeste.hpp"
#include <iostream>

using namespace std;

void ParqueTeste::Teste1() {
    setlocale(LC_ALL, "Portuguese");
    cout << "\n### Testes da classe Parque ###\n";

    // Criar um parque de estacionamento com capacidade para 3 viaturas
    Parque parque("Parque Principal", 3);

    // Criar viaturas e horários de entrada
    Viatura viatura1("AA-11-BB");
    Viatura viatura2("CC-22-DD");
    Viatura viatura3("EE-33-FF");
    Viatura viatura4("GG-44-HH"); // Para testar lotação excedida

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

    // Testar lotação excedida
    cout << "\nTestar estacionamento de viatura com parque cheio...\n";
    if (!parque.estaciona(viatura4, entrada4)) {// Se não for possível estacionar a viatura 4
        cout << "Parque cheio. Viatura 4 não pode ser estacionada!" << endl;
    }

    // Mostrar estado do parque
    cout << "\nEstado do parque:\n";
    cout << parque.toString() << endl;

    // Testar registro de saída e cálculo de valores
    cout << "\nTestar saída e cálculo de valores...\n";
    Hora saida1(10, 0); // Saída para a viatura 1
    try {
        double valor1 = parque.saida("AA-11-BB", saida1);
        cout << "Valor pago pela viatura 1: " << valor1 << " euros" << endl;
    }
    catch (const exception& e) {
        cerr << "Erro ao registar saída da viatura 1: " << e.what() << endl;
    }

    // Testar saída antes da entrada (lançar exceção)
    cout << "\nTestar saída antes da entrada (lançar exceção)...\n";
    Hora saidaInvalida(8, 30);
    try {
        parque.saida("CC-22-DD", saidaInvalida);
    }
    catch (const exception& e) {
        cerr << "Erro esperado: " << e.what() << endl;
    }

    // Testar valores faltantes com hora atual
    cout << "\nTestar cálculo de valores faltantes...\n";
    Hora horaAtual(12);
    try {
        double valorFaltante = parque.valorTotalFaltante(horaAtual);// Calcula o valor total faltante(de todos os carros que ainda estão no parque) considerando a hora atual
        //neste exemplo a viatura2 ainda está no parque e tem de pagar 1.40€(1h30) e a viatura3 ainda está no parque e tem de pagar 0.20€(15min)
        cout << "Valor total faltante: " << valorFaltante << " euros" << endl;
    }
    catch (const exception& e) {// Se houver algum erro
        cerr << "Erro ao calcular valores faltantes: " << e.what() << endl;
    }

    // Testar cálculo de valores recebidos
    cout << "\nTestar cálculo de valores recebidos...\n";
    double valorRecebido = parque.valorTotalRecebido();
    cout << "Valor total recebido pelo parque: " << valorRecebido << " euros" << endl;

    // Testar tempo total de estacionamento
    cout << "\nTestar cálculo do tempo total de estacionamento...\n";
    try {
        Hora tempoTotal = parque.tempoTotalDeEstacionamento("AA-11-BB");
        cout << "Tempo total de estacionamento da viatura 1: " << tempoTotal.toString() << endl;
    }
    catch (const exception& e) {
        cerr << "Erro ao calcular tempo total de estacionamento: " << e.what() << endl;
    }

    // Verificar se uma viatura está estacionada
    cout << "\nVerificar se uma viatura está estacionada...\n";
    if (parque.estaEstacionado("EE-33-FF")) {
        cout << "A viatura 3 ainda está estacionada." << endl;
    }
    else {
        cout << "A viatura 3 já saiu." << endl;
    }

    // Testar estacionamento após liberação de espaço
    cout << "\nTestar estacionamento após liberação de espaço...\n";
    if (parque.estaciona(viatura4, entrada4)) {
        cout << "Viatura 4 estacionada com sucesso após liberação de espaço!" << endl;
    }
    else {
        cout << "Erro ao estacionar a viatura 4." << endl;
    }

    // Mostrar estado final do parque
    cout << "\nEstado final do parque:\n";
    cout << parque.toString() << endl;

    cout << "\n### Testar períodos de uma viatura específica ###\n";
    vector<Registo> periodosViatura = parque.getRegistosPorMatricula("AA-11-BB");

    for (const auto& reg : periodosViatura) {
        cout << reg.toString() << endl; // Exibe apenas os registros da viatura
    }
    // Listar os registros antes da ordenação
    cout << "\n### Listar registros no parque antes da ordenação ###\n";
    cout << parque.listarRegistos() << endl;

    // Ordenar os registros dentro do parque
    cout << "\n### Ordenar registros por hora de entrada ###\n";
    parque.ordenarRegistos();

    // Listar os registros após a ordenação
    cout << "\n### Listar registros no parque após a ordenação ###\n";
    cout << parque.listarRegistos() << endl;
    
}



