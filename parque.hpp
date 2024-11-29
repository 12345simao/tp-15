#ifndef PARQUE_HPP
#define PARQUE_HPP

#include <string>
#include <vector>
#include "registroes.hpp"
#include "hora.hpp"
#include "Viatura.hpp"

using namespace std;

class Parque {
private:
    string idparque; // Identificador do parque
    int lotacao;     // Capacidade m�xima do parque
    vector<Registo> registos; // Vetor de registros de entrada/sa�da
    // Fun��o auxiliar para inserir um registro ordenado por hora de entrada
   


public:
    // Construtor
    Parque(string idparque, int lotacao = 100);

    // M�todos de consulta e modifica��o
    int ocupacao() const;
    int lugaresLivres() const;
    bool estaciona(Viatura& v, Hora& he);
    bool estaEstacionado(string matricula) const;
    double saida(string matricula, Hora& hs);
    double valorPago(string matricula) const;
    Hora tempoTotalDeEstacionamento(string matricula) const;
	double calcularValorEstacionamento(int minutos, const Hora& entrada) const;
    double valorTotalRecebido() const;
    double valorTotalFaltante(Hora& horaAtual) const;
    string toString() const;
    vector<Registo> getRegistosPorMatricula(const string& matricula) const;
    void ordenarRegistos(); // Declara��o no cabe�alho

    string listarRegistos() const; // Declara��o no cabe�alho

};

#endif // PARQUE_HPP
