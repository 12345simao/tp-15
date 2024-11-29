#include "parque.hpp"
#include <sstream>
#include <iostream>

using namespace std;

// Construtor da classe Parque
Parque::Parque(string idparque, int lotacao) {
    this->idparque = idparque; // Inicializa o ID do parque
    this->lotacao = lotacao;   // Inicializa a lota��o m�xima do parque
}

// Retorna a ocupa��o atual do parque (n�mero de viaturas estacionadas)
int Parque::ocupacao() const {
    int count = 0; // Contador para viaturas atualmente estacionadas
    for (const auto& reg : registos) {
        if (!reg.isPago()) { // Conta viaturas que ainda n�o pagaram (est�o estacionadas)
            count++;
        }
    }
    return count; // Retorna a contagem total
}

// Retorna a quantidade de lugares livres no parque
int Parque::lugaresLivres() const {
    return lotacao - ocupacao(); // Calcula os lugares livres subtraindo a ocupa��o atual da lota��o total
}
/*
// Registra a entrada de uma viatura no parque
bool Parque::estaciona(Viatura& v, Hora& he) {
    if (ocupacao() >= lotacao) { // Verifica se o parque est� cheio
        return false; // N�o permite estacionar se o parque est� cheio
    }
    Registo entrada(v, he); // Cria um novo registro de entrada para a viatura
    registos.push_back(entrada); // Adiciona o registro ao vetor de registros
    return true; // Retorna verdadeiro indicando que a viatura foi estacionada com sucesso
}
*/



bool Parque::estaciona(Viatura& v, Hora& he) {
    if (ocupacao() >= lotacao) {
        return false; // N�o permite estacionar se o parque est� cheio
    }

    Registo novoRegistro(v, he); // Cria um novo registro de entrada
    registos.push_back(novoRegistro); // Adiciona o novo registro ao final da lista de registros
	 // Insere o registro na lista ordenada
    //inserirOrdenado(novoRegistro); // Insere o registro na lista ordenada

    return true;
}




// Verifica se uma viatura com a matr�cula fornecida est� estacionada
bool Parque::estaEstacionado(string matricula) const {
    for (const auto& reg : registos) { // Percorre todos os registros
        if (reg.getMatricula() == matricula && !reg.isPago()) { // Verifica se a matr�cula corresponde e n�o foi paga
            return true; // Retorna verdadeiro se a viatura estiver estacionada
        }
    }
    return false; // Retorna falso se a viatura n�o estiver estacionada
}

// Calcula o valor total recebido pelo parque para as viaturas que j� sa�ram
double Parque::valorTotalRecebido() const {
    double totalRecebido = 0.0;
    for (const auto& reg : registos) {
        if (reg.isPago()) {
            totalRecebido += valorPago(reg.getMatricula());
        }
    }
    return totalRecebido;
}

// Calcula o valor total que falta para as viaturas que ainda est�o no parque, considerando uma hora de refer�ncia
double Parque::valorTotalFaltante(Hora& horaAtual) const {
    double totalFaltante = 0.0;
    for (const auto& reg : registos) {
        if (!reg.isPago()) {
            
            // Verifica se a hora atual � anterior � hora de entrada
            if (horaAtual < *reg.getEntrada()) {
                throw std::invalid_argument(
                    "Erro: A hora atual (" + horaAtual.toString() + 
                    ") � anterior � hora de entrada (" + reg.getEntrada()->toString() + ").");
            }
            int minutos = reg.minutosEstacionamento(horaAtual);
            totalFaltante += calcularValorEstacionamento(minutos, *reg.getEntrada());
        }
    }
    return totalFaltante;
}

double Parque::calcularValorEstacionamento(int minutos, const Hora& entrada) const {
    double total = 0.0;
    Hora inicioDiurno(8, 0), fimDiurno(20, 0);

    Hora atual = entrada; // Faz uma c�pia de `entrada` para manipula��o
    int minutosRestantes = minutos;

    while (minutosRestantes > 0) {
        // Determina se o per�odo atual � noturno ou diurno
        bool isNoturno = (atual.gethora() < inicioDiurno.gethora()) || (atual.gethora() >= fimDiurno.gethora());

        // Calcula minutos at� a pr�xima transi��o de per�odo
        int minutosAteTransicao;
        if (isNoturno) {
            if (atual.gethora() < inicioDiurno.gethora()) {
                minutosAteTransicao = (inicioDiurno.gethora() - atual.gethora()) * 60 - atual.getminutos();
            }
            else {
                minutosAteTransicao = (24 - atual.gethora() + inicioDiurno.gethora()) * 60 - atual.getminutos();
            }
        }
        else {
            minutosAteTransicao = (fimDiurno.gethora() - atual.gethora()) * 60 - atual.getminutos();
        }

        // Determina minutos efetivos para este per�odo
        if (minutosRestantes < minutosAteTransicao) {
            minutosAteTransicao = minutosRestantes;
        }

        // Calcula o valor para o per�odo atual
        if (isNoturno) {
            total += (minutosAteTransicao / 15) * 0.20; // Per�odo noturno
        }
        else {
            if (minutosAteTransicao <= 60) {
                total += (minutosAteTransicao / 15) * 0.20; // Primeira hora diurna
            }
            else {
                total += (60 / 15) * 0.20; // Primeiros 60 minutos diurnos
                total += ((minutosAteTransicao - 60) / 15) * 0.30; // Restante do tempo diurno
            }
        }

        // Atualiza os minutos restantes e o hor�rio atual
        minutosRestantes -= minutosAteTransicao;
        int novaHora = atual.gethora() + minutosAteTransicao / 60;
        int novosMinutos = atual.getminutos() + minutosAteTransicao % 60;

        // Ajusta a hora e os minutos dentro de limites v�lidos
        if (novosMinutos >= 60) {
            novaHora += novosMinutos / 60;
            novosMinutos %= 60;
        }
        atual.sethora(novaHora % 24, novosMinutos, atual.getsegundos());
    }

    return total;
}



//
double Parque::saida(string matricula, Hora& hs) {
    for (auto& reg : registos) {
        if (reg.getMatricula() == matricula && !reg.isPago()) {
            int minutos = reg.registaSaida(hs);
            double total = calcularValorEstacionamento(minutos, *reg.getEntrada()); // Usa a fun��o auxiliar
            reg.paga(); // Marca o registro como pago
            return total; // Retorna o valor total a ser pago
        }
    }
    throw runtime_error("Viatura n�o encontrada ou j� saiu.");
}

double Parque::valorPago(string matricula) const {
    double total = 0.0;
    for (const auto& reg : registos) {
        if (reg.getMatricula() == matricula && reg.isPago()) {
			int minutos = reg.minutosEstacionamento();// Calcula os minutos de estacionamento
            total += calcularValorEstacionamento(minutos, *reg.getEntrada()); // Usa a fun��o auxiliar
        }
    }
    return total;
}



string Parque::listarRegistos() const {
    // Inicializa a string que ir� conter a lista de registros
    string strRegistos = "Lista de Registos no Parque:\n";

    // Itera sobre todos os registros armazenados no vetor 'registos'
    for (const auto& reg : registos) {
        //a representa��o em string de cada registro (usando 'toString') � string final
        strRegistos += reg.toString() + "\n";
    }

    // Retorna a string completa com todos os registros formatados
    return strRegistos;
}


void Parque::ordenarRegistos() {
    // Cria um vetor auxiliar vazio para armazenar os registros ordenados
    vector<Registo> registosOrdenados;

    // Itera sobre todos os registros do vetor original 'registos'
    for (const auto& reg : registos) {
        // Inicializa o iterador para encontrar a posi��o correta no vetor auxiliar
        auto it = registosOrdenados.begin();

        // Obt�m a hora de entrada do registro atual
        Hora he = *reg.getEntrada();

        // Encontra a posi��o onde o registro deve ser inserido no vetor ordenado
        // Ele compara a hora de entrada (he) com os registros j� existentes no vetor auxiliar
        while (it != registosOrdenados.end() && !(he < *it->getEntrada())) {
            ++it; // Avan�a o iterador at� encontrar a posi��o correta
        }

        // Insere o registro no vetor auxiliar na posi��o ordenada
        registosOrdenados.insert(it, reg);
    }

    // Substitui o vetor original 'registos' pelo vetor ordenado 'registosOrdenados'
    registos = registosOrdenados;
}








// Retorna o tempo total de estacionamento para uma viatura em formato de `Hora`
Hora Parque::tempoTotalDeEstacionamento(string matricula) const {
    int totalMinutos = 0; // Vari�vel para armazenar o total de minutos
    for (const auto& reg : registos) { // Percorre todos os registros
        if (reg.getMatricula() == matricula && reg.isPago()) { // Verifica se a matr�cula foi paga
            totalMinutos += reg.minutosEstacionamento(); // Soma os minutos de estacionamento
        }
    }
    int horas = totalMinutos / 60; // Calcula o n�mero de horas
    int minutos = totalMinutos % 60; // Calcula os minutos restantes
    return Hora(horas, minutos); // Retorna o tempo total como um objeto `Hora`
}

// Representa o estado do parque como uma string
string Parque::toString() const {
    string strParque = "Parque {\n";
    strParque += "  ID: " + idparque + "\n"; // Adiciona o ID do parque
    strParque += "  Lota��o: " + to_string(lotacao) + "\n"; // Adiciona a lota��o
    strParque += "  Ocupa��o Atual: " + to_string(ocupacao()) + "\n"; // Adiciona a ocupa��o atual
    strParque += "  Lugares Livres: " + to_string(lugaresLivres()) + "\n"; // Adiciona os lugares livres
    strParque += "  Registos de Viaturas Estacionadas:\n"; // Inicia a listagem dos registros
    for (const auto& reg : registos) {
        strParque += "    - " + reg.toString() + "\n"; // Adiciona cada registro como string
    }
    strParque += "}"; // Fecha a representa��o do parque
    return strParque; // Retorna a string representando o estado do parque
}

/* //exemplo do que faz
// Suponha que `minutos = 75` (tempo total de estacionamento)
                    // Passo 1: Inicializa `minutosDiurnos` com o valor de `minutos`
                int minutosDiurnos = minutos; // minutosDiurnos = 75

                // Passo 2: Verifica se `minutos` � maior que 60 e ajusta `minutosDiurnos`
                if (minutos > 60) {
                    minutosDiurnos = 60; // Limita `minutosDiurnos` a 60
                }

                // C�lculo para os primeiros 60 minutos (ou menos): `(60 / 15) * 0.20`
                total += (minutosDiurnos / 15) * 0.20;
                // `minutosDiurnos = 60`
                // `(60 / 15) * 0.20 = 4 * 0.20 = 0.80�`

                // Passo 3: Subtrai `minutosDiurnos` do total de `minutos`
                minutos -= minutosDiurnos; // `minutos = 75 - 60 = 15`

                // Passo 4: Calcula o valor para os minutos restantes, se houver
                if (minutos > 0) {
                    total += (minutos / 15) * 0.30;
                    // `minutos = 15`
                    // C�lculo para os minutos restantes: `(15 / 15) * 0.30 = 1 * 0.30 = 0.30�`
                }

                // Valor total:
                // Total para os primeiros 60 minutos: `0.80�`
                // Total para os 15 minutos restantes: `0.30�`
                // Valor total a ser pago: `0.80� + 0.30� = 1.10�`
            }
*/
vector<Registo> Parque::getRegistosPorMatricula(const string& matricula) const {
	vector<Registo> resultado; // Vetor para armazenar os registros correspondentes

	for (const auto& reg : registos) {// Percorre todos os registros
		if (reg.getMatricula() == matricula && reg.getSaida() != nullptr) {// Verifica se a matr�cula corresponde e a sa�da foi registrada
			resultado.push_back(reg); // Adiciona registros correspondentes ao vetor de resultados
        }
    }

	return resultado; // Retorna o vetor de registros correspondentes
}
