#include "registroes.hpp"
#include <stdexcept>
#include <sstream>
using namespace std;

// Inicializa��o do contador est�tico
int Registo::contador = 0;

// Construtor com entrada
Registo::Registo(Viatura& v, Hora& he) // Construtor que cria um registro com uma viatura e hora de entrada
    : entrada(new Hora(he)), saida(nullptr), veiculo(&v), pago(false) {
    numero = ++contador; // Incrementa e atribui um n�mero �nico ao registro
}

// Getter para obter a hora de entrada
Hora* Registo::getEntrada() const {
    return entrada; // Retorna o ponteiro para a hora de entrada
}

// Getter para obter a hora de sa�da
Hora* Registo::getSaida() const {
    return saida; // Retorna o ponteiro para a hora de sa�da
}

// Construtor com entrada e sa�da
Registo::Registo(Viatura& v, Hora& he, Hora& hs) // Construtor que cria um registro com viatura, hora de entrada e sa�da
    : entrada(new Hora(he)), saida(new Hora(hs)), veiculo(&v), pago(false) {
    if (*saida < *entrada) { // Verifica se a hora de sa�da � anterior � hora de entrada
        throw std::invalid_argument("Hora de sa�da n�o pode ser anterior � hora de entrada");
    }
    numero = ++contador; // Incrementa e atribui um n�mero �nico ao registro
}

// M�todo para registrar a sa�da
int Registo::registaSaida(Hora& hs) {
    if (saida != nullptr) { // Verifica se a sa�da j� foi registrada
        throw std::logic_error("A sa�da j� foi registrada");
    }
    if (hs < *entrada) { // Verifica se a hora de sa�da � anterior � hora de entrada
        throw std::invalid_argument("Hora de sa�da n�o pode ser anterior � hora de entrada");
    }
    saida = new Hora(hs); // Cria um novo objeto `Hora` para representar a sa�da
    int resultado = entrada->minutosAte(hs); // Calcula a diferen�a em minutos entre a entrada e a sa�da
    return resultado; // Retorna o tempo total de estacionamento em minutos
}

// M�todo para marcar o registro como pago
bool Registo::paga() {
    pago = true; // Define o estado como pago
    return pago; // Retorna o estado atual
}

// Calcula os minutos de estacionamento do momento de entrada at� a sa�da
int Registo::minutosEstacionamento() const {
    if (saida == nullptr) { // Verifica se a sa�da ainda n�o foi registrada
        throw std::logic_error("Hora de sa�da n�o registrada");
    }
    return entrada->minutosAte(*saida); // Retorna o tempo de estacionamento em minutos
}

// Calcula os minutos de estacionamento at� uma hora atual fornecida
int Registo::minutosEstacionamento(Hora& hatual) const {
    return entrada->minutosAte(hatual); // Calcula e retorna a diferen�a de minutos at� `hatual`
}

// Verifica se a viatura com a matr�cula fornecida ainda est� estacionada
bool Registo::estaEstacionado(const string& matricula) const {
    return veiculo->getMatricula() == matricula && saida == nullptr; // Verifica se a matr�cula � igual e a sa�da � nula
}

// Getter para obter o n�mero do registro
int Registo::getNumero() const {
    return numero; // Retorna o n�mero do registro
}

// Verifica se o registro est� marcado como pago
bool Registo::isPago() const {
    return pago; // Retorna o estado de pagamento
}

// Retorna a matr�cula da viatura associada ao registro
string Registo::getMatricula() const {
    return veiculo->getMatricula(); // Retorna a matr�cula da viatura
}

// Retorna uma representa��o em string do registro
string Registo::toString() const {
    string strRegisto = "Registo {\n";
    strRegisto += "  N�mero: " + to_string(getNumero()) + "\n";
    strRegisto += "  Matr�cula: " + veiculo->getMatricula() + "\n";
    strRegisto += "  Hora de entrada: " + entrada->toString() + "\n";
    if (saida != nullptr) {
        // Se a sa�da foi registrada, inclui a hora de sa�da e o estado de pagamento
        strRegisto += "  Hora de sa�da: " + saida->toString() + "\n";
        strRegisto += "  Pago: " + string(pago ? "Sim" : "N�o") + "\n";

        // Calcula o tempo total de perman�ncia em horas e minutos
        int totalMinutos = entrada->minutosAte(*saida);
        int horas = totalMinutos / 60;
        int minutos = totalMinutos % 60;
        //Adiciona o tempo total de perman�ncia ao string
       strRegisto += "  Tempo total no parque: " + to_string(horas) + " horas e " + to_string(minutos) + " minutos\n";
        //strRegisto += "  Tempo total no parque: " + to_string(totalMinutos) + " minutos\n";
    }
    else {
        // Se a sa�da n�o foi registrada, indica que a viatura ainda n�o saiu
        strRegisto += "  Hora de sa�da: Ainda n�o saiu\n";
    }
    strRegisto += "}";
    return strRegisto; // Retorna a string completa representando o registro
}

