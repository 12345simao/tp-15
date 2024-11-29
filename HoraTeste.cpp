#include "HoraTeste.hpp"

// Testa a cria��o de objetos Hora e a convers�o para string
void HoraTeste::Teste1() {
    try {
        cout << "\n### Teste 1: Cria��o e Compara��o de Horas ###\n";
        Hora hora1(14, 30, 0); // Cria��o de um objeto Hora representando 14:30:00
        Hora hora2(16, 45, 0); // Cria��o de um objeto Hora representando 16:45:00

        // Exibe as informa��es das horas criadas
        cout << "Hora 1: " << hora1.toString() << endl;
        cout << "Hora 2: " << hora2.toString() << endl;

        // Verifica se hora1 � menor que hora2 utilizando o operador '<'
        if (hora1 < hora2) {
            cout << "Hora 1 � menor que Hora 2" << endl;
        }
        else {
            cout << "Hora 1 n�o � menor que Hora 2" << endl;
        }
    }
    catch (const std::exception& e) {
        // Captura e exibe erros em caso de falha
        cerr << "Erro ao executar o Teste1: " << e.what() << endl;
    }
}

// Testa o c�lculo da diferen�a em minutos entre duas horas
void HoraTeste::Teste2() {
    try {
        cout << "\n### Teste 2: Diferen�a em Minutos ###\n";
        Hora hora1(8, 15, 0); // Cria��o de um objeto Hora representando 8:15:00
        Hora hora2(9, 45, 0); // Cria��o de um objeto Hora representando 9:45:00

        // Exibe as informa��es das horas criadas
        cout << "Hora 1: " << hora1.toString() << endl;
        cout << "Hora 2: " << hora2.toString() << endl;

        // Calcula e exibe a diferen�a em minutos entre hora1 e hora2
        int minutosAte = hora1.minutosAte(hora2);
        cout << "Minutos de Hora 1 at� Hora 2: " << minutosAte << " minutos" << endl;

        // Calcula e exibe a diferen�a em minutos no sentido inverso
        minutosAte = hora2.minutosAte(hora1);
        cout << "Minutos de Hora 2 at� Hora 1: " << minutosAte << " minutos" << endl;
    }
    catch (const std::exception& e) {
        // Captura e exibe erros em caso de falha
        cerr << "Erro ao executar o Teste2: " << e.what() << endl;
    }
}

// Testa o tratamento de erros ao criar objetos Hora com valores inv�lidos
void HoraTeste::Teste3() {
    try {
        cout << "\n### Teste 3: Tratamento de Horas Inv�lidas ###\n";
        Hora horaInvalida1(25, 61, 61); // Teste com valores fora dos limites permitidos
    }
    catch (const std::invalid_argument& e) {
        // Captura e exibe erro para hora inv�lida
        cerr << "Erro capturado (Hora Inv�lida): " << e.what() << endl;
    }

    try {
        Hora horaInvalida2(-1, 0, 0); // Teste com valores negativos
    }
    catch (const std::invalid_argument& e) {
        // Captura e exibe erro para hora inv�lida
        cerr << "Erro capturado (Hora Inv�lida): " << e.what() << endl;
    }
}

// Testa o operador '<' para diferentes cen�rios
void HoraTeste::Teste4() {
    // In�cio do teste 4: Verifica o operador "menor que" (<)
    cout << "\n### Teste 4: Operador Menor Que (<) ###\n";

    // Teste para a cria��o de Hora 1
    try {
        Hora hora1(10, 0); // Cria��o de um objeto Hora representando 10:00:00
        cout << "Hora 1: " << hora1.toString() << endl; // Apresenta a representa��o da Hora 1
    }
    catch (const std::exception& e) { // Captura e trata exce��es durante a cria��o de Hora 1
        cerr << "Erro ao criar Hora 1: " << e.what() << endl; // Apresenta o erro caso a cria��o falhe
    }

    // Teste para a cria��o de Hora 2
    try {
        Hora hora2(10, 15); // Cria��o de um objeto Hora representando 10:15:00
        cout << "Hora 2: " << hora2.toString() << endl; // Apresenta a representa��o da Hora 2
    }
    catch (const std::exception& e) { // Captura e trata exce��es durante a cria��o de Hora 2
        cerr << "Erro ao criar Hora 2: " << e.what() << endl; // Apresenta o erro caso a cria��o falhe
    }

    // Teste para a cria��o de Hora 3 (valores inv�lidos)
    try {
        Hora hora3(25, 0, 30); // Tentativa de criar um objeto Hora com valores inv�lidos
        cout << "Hora 3: " << hora3.toString() << endl; // Este c�digo n�o ser� executado em caso de erro
    }
    catch (const std::exception& e) { // Captura e trata exce��es durante a cria��o de Hora 3
        cerr << "Erro ao criar Hora 3: " << e.what() << endl; // Apresenta o erro para valores inv�lidos
    }

    // Teste da compara��o entre Hora 1 e Hora 2
    try {
        Hora hora1(10, 0), hora2(10, 15), hora3(10, 0, 30); // Redefine os objetos Hora para compara��o
        cout << "Hora 1 < Hora 2? " << (hora1 < hora2 ? "Sim" : "N�o") << endl; // Verifica se Hora 1 � menor que Hora 2
    }
    catch (const std::exception& e) { // Captura e trata exce��es durante a compara��o
        cerr << "Erro ao comparar Hora 1 e Hora 2: " << e.what() << endl; // Apresenta o erro caso a compara��o falhe
    }

    // Teste da compara��o entre Hora 1 e Hora 3
    try {
        Hora hora1(10, 0), hora3(10, 0, 30); // Redefine os objetos Hora para compara��o
        cout << "Hora 1 < Hora 3? " << (hora1 < hora3 ? "Sim" : "N�o") << endl; // Verifica se Hora 1 � menor que Hora 3
    }
    catch (const std::exception& e) { // Captura e trata exce��es durante a compara��o
        cerr << "Erro ao comparar Hora 1 e Hora 3: " << e.what() << endl; // Apresenta o erro caso a compara��o falhe
    }

    // Teste da compara��o entre Hora 2 e Hora 3
    try {
        Hora hora2(10, 15), hora3(10, 0, 30); // Redefine os objetos Hora para compara��o
        cout << "Hora 2 < Hora 3? " << (hora2 < hora3 ? "Sim" : "N�o") << endl; // Verifica se Hora 2 � menor que Hora 3
    }
    catch (const std::exception& e) { // Captura e trata exce��es durante a compara��o
        cerr << "Erro ao comparar Hora 2 e Hora 3: " << e.what() << endl; // Apresenta o erro caso a compara��o falhe
    }
}

