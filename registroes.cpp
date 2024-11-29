#include "registroes.hpp"
#include <stdexcept>
#include <sstream>
using namespace std;

// Inicialização do contador estático
int Registo::contador = 0;

// Construtor com entrada
Registo::Registo(Viatura& v, Hora& he) // Construtor que cria um registro com uma viatura e hora de entrada
    : entrada(new Hora(he)), saida(nullptr), veiculo(&v), pago(false) {
    numero = ++contador; // Incrementa e atribui um número único ao registro
}

// Getter para obter a hora de entrada
Hora* Registo::getEntrada() const {
    return entrada; // Retorna o ponteiro para a hora de entrada
}

// Getter para obter a hora de saída
Hora* Registo::getSaida() const {
    return saida; // Retorna o ponteiro para a hora de saída
}

// Construtor com entrada e saída
Registo::Registo(Viatura& v, Hora& he, Hora& hs) // Construtor que cria um registro com viatura, hora de entrada e saída
    : entrada(new Hora(he)), saida(new Hora(hs)), veiculo(&v), pago(false) {
    if (*saida < *entrada) { // Verifica se a hora de saída é anterior à hora de entrada
        throw std::invalid_argument("Hora de saída não pode ser anterior à hora de entrada");
    }
    numero = ++contador; // Incrementa e atribui um número único ao registro
}

// Método para registrar a saída
int Registo::registaSaida(Hora& hs) {
    if (saida != nullptr) { // Verifica se a saída já foi registrada
        throw std::logic_error("A saída já foi registrada");
    }
    if (hs < *entrada) { // Verifica se a hora de saída é anterior à hora de entrada
        throw std::invalid_argument("Hora de saída não pode ser anterior à hora de entrada");
    }
    saida = new Hora(hs); // Cria um novo objeto `Hora` para representar a saída
    int resultado = entrada->minutosAte(hs); // Calcula a diferença em minutos entre a entrada e a saída
    return resultado; // Retorna o tempo total de estacionamento em minutos
}

// Método para marcar o registro como pago
bool Registo::paga() {
    pago = true; // Define o estado como pago
    return pago; // Retorna o estado atual
}

// Calcula os minutos de estacionamento do momento de entrada até a saída
int Registo::minutosEstacionamento() const {
    if (saida == nullptr) { // Verifica se a saída ainda não foi registrada
        throw std::logic_error("Hora de saída não registrada");
    }
    return entrada->minutosAte(*saida); // Retorna o tempo de estacionamento em minutos
}

// Calcula os minutos de estacionamento até uma hora atual fornecida
int Registo::minutosEstacionamento(Hora& hatual) const {
    return entrada->minutosAte(hatual); // Calcula e retorna a diferença de minutos até `hatual`
}

// Verifica se a viatura com a matrícula fornecida ainda está estacionada
bool Registo::estaEstacionado(const string& matricula) const {
    return veiculo->getMatricula() == matricula && saida == nullptr; // Verifica se a matrícula é igual e a saída é nula
}

// Getter para obter o número do registro
int Registo::getNumero() const {
    return numero; // Retorna o número do registro
}

// Verifica se o registro está marcado como pago
bool Registo::isPago() const {
    return pago; // Retorna o estado de pagamento
}

// Retorna a matrícula da viatura associada ao registro
string Registo::getMatricula() const {
    return veiculo->getMatricula(); // Retorna a matrícula da viatura
}

// Retorna uma representação em string do registro
string Registo::toString() const {
    string strRegisto = "Registo {\n";
    strRegisto += "  Número: " + to_string(getNumero()) + "\n";
    strRegisto += "  Matrícula: " + veiculo->getMatricula() + "\n";
    strRegisto += "  Hora de entrada: " + entrada->toString() + "\n";
    if (saida != nullptr) {
        // Se a saída foi registrada, inclui a hora de saída e o estado de pagamento
        strRegisto += "  Hora de saída: " + saida->toString() + "\n";
        strRegisto += "  Pago: " + string(pago ? "Sim" : "Não") + "\n";

        // Calcula o tempo total de permanência em horas e minutos
        int totalMinutos = entrada->minutosAte(*saida);
        int horas = totalMinutos / 60;
        int minutos = totalMinutos % 60;
        //Adiciona o tempo total de permanência ao string
       strRegisto += "  Tempo total no parque: " + to_string(horas) + " horas e " + to_string(minutos) + " minutos\n";
        //strRegisto += "  Tempo total no parque: " + to_string(totalMinutos) + " minutos\n";
    }
    else {
        // Se a saída não foi registrada, indica que a viatura ainda não saiu
        strRegisto += "  Hora de saída: Ainda não saiu\n";
    }
    strRegisto += "}";
    return strRegisto; // Retorna a string completa representando o registro
}

