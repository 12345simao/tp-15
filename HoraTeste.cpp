#include "HoraTeste.hpp"

// Testa a criação de objetos Hora e a conversão para string
void HoraTeste::Teste1() {
    try {
        cout << "\n### Teste 1: Criação e Comparação de Horas ###\n";
        Hora hora1(14, 30, 0); // Criação de um objeto Hora representando 14:30:00
        Hora hora2(16, 45, 0); // Criação de um objeto Hora representando 16:45:00

        // Exibe as informações das horas criadas
        cout << "Hora 1: " << hora1.toString() << endl;
        cout << "Hora 2: " << hora2.toString() << endl;

        // Verifica se hora1 é menor que hora2 utilizando o operador '<'
        if (hora1 < hora2) {
            cout << "Hora 1 é menor que Hora 2" << endl;
        }
        else {
            cout << "Hora 1 não é menor que Hora 2" << endl;
        }
    }
    catch (const std::exception& e) {
        // Captura e exibe erros em caso de falha
        cerr << "Erro ao executar o Teste1: " << e.what() << endl;
    }
}

// Testa o cálculo da diferença em minutos entre duas horas
void HoraTeste::Teste2() {
    try {
        cout << "\n### Teste 2: Diferença em Minutos ###\n";
        Hora hora1(8, 15, 0); // Criação de um objeto Hora representando 8:15:00
        Hora hora2(9, 45, 0); // Criação de um objeto Hora representando 9:45:00

        // Exibe as informações das horas criadas
        cout << "Hora 1: " << hora1.toString() << endl;
        cout << "Hora 2: " << hora2.toString() << endl;

        // Calcula e exibe a diferença em minutos entre hora1 e hora2
        int minutosAte = hora1.minutosAte(hora2);
        cout << "Minutos de Hora 1 até Hora 2: " << minutosAte << " minutos" << endl;

        // Calcula e exibe a diferença em minutos no sentido inverso
        minutosAte = hora2.minutosAte(hora1);
        cout << "Minutos de Hora 2 até Hora 1: " << minutosAte << " minutos" << endl;
    }
    catch (const std::exception& e) {
        // Captura e exibe erros em caso de falha
        cerr << "Erro ao executar o Teste2: " << e.what() << endl;
    }
}

// Testa o tratamento de erros ao criar objetos Hora com valores inválidos
void HoraTeste::Teste3() {
    try {
        cout << "\n### Teste 3: Tratamento de Horas Inválidas ###\n";
        Hora horaInvalida1(25, 61, 61); // Teste com valores fora dos limites permitidos
    }
    catch (const std::invalid_argument& e) {
        // Captura e exibe erro para hora inválida
        cerr << "Erro capturado (Hora Inválida): " << e.what() << endl;
    }

    try {
        Hora horaInvalida2(-1, 0, 0); // Teste com valores negativos
    }
    catch (const std::invalid_argument& e) {
        // Captura e exibe erro para hora inválida
        cerr << "Erro capturado (Hora Inválida): " << e.what() << endl;
    }
}

// Testa o operador '<' para diferentes cenários
void HoraTeste::Teste4() {
    // Início do teste 4: Verifica o operador "menor que" (<)
    cout << "\n### Teste 4: Operador Menor Que (<) ###\n";

    // Teste para a criação de Hora 1
    try {
        Hora hora1(10, 0); // Criação de um objeto Hora representando 10:00:00
        cout << "Hora 1: " << hora1.toString() << endl; // Apresenta a representação da Hora 1
    }
    catch (const std::exception& e) { // Captura e trata exceções durante a criação de Hora 1
        cerr << "Erro ao criar Hora 1: " << e.what() << endl; // Apresenta o erro caso a criação falhe
    }

    // Teste para a criação de Hora 2
    try {
        Hora hora2(10, 15); // Criação de um objeto Hora representando 10:15:00
        cout << "Hora 2: " << hora2.toString() << endl; // Apresenta a representação da Hora 2
    }
    catch (const std::exception& e) { // Captura e trata exceções durante a criação de Hora 2
        cerr << "Erro ao criar Hora 2: " << e.what() << endl; // Apresenta o erro caso a criação falhe
    }

    // Teste para a criação de Hora 3 (valores inválidos)
    try {
        Hora hora3(25, 0, 30); // Tentativa de criar um objeto Hora com valores inválidos
        cout << "Hora 3: " << hora3.toString() << endl; // Este código não será executado em caso de erro
    }
    catch (const std::exception& e) { // Captura e trata exceções durante a criação de Hora 3
        cerr << "Erro ao criar Hora 3: " << e.what() << endl; // Apresenta o erro para valores inválidos
    }

    // Teste da comparação entre Hora 1 e Hora 2
    try {
        Hora hora1(10, 0), hora2(10, 15), hora3(10, 0, 30); // Redefine os objetos Hora para comparação
        cout << "Hora 1 < Hora 2? " << (hora1 < hora2 ? "Sim" : "Não") << endl; // Verifica se Hora 1 é menor que Hora 2
    }
    catch (const std::exception& e) { // Captura e trata exceções durante a comparação
        cerr << "Erro ao comparar Hora 1 e Hora 2: " << e.what() << endl; // Apresenta o erro caso a comparação falhe
    }

    // Teste da comparação entre Hora 1 e Hora 3
    try {
        Hora hora1(10, 0), hora3(10, 0, 30); // Redefine os objetos Hora para comparação
        cout << "Hora 1 < Hora 3? " << (hora1 < hora3 ? "Sim" : "Não") << endl; // Verifica se Hora 1 é menor que Hora 3
    }
    catch (const std::exception& e) { // Captura e trata exceções durante a comparação
        cerr << "Erro ao comparar Hora 1 e Hora 3: " << e.what() << endl; // Apresenta o erro caso a comparação falhe
    }

    // Teste da comparação entre Hora 2 e Hora 3
    try {
        Hora hora2(10, 15), hora3(10, 0, 30); // Redefine os objetos Hora para comparação
        cout << "Hora 2 < Hora 3? " << (hora2 < hora3 ? "Sim" : "Não") << endl; // Verifica se Hora 2 é menor que Hora 3
    }
    catch (const std::exception& e) { // Captura e trata exceções durante a comparação
        cerr << "Erro ao comparar Hora 2 e Hora 3: " << e.what() << endl; // Apresenta o erro caso a comparação falhe
    }
}

