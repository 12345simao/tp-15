#ifndef REGISTOES_HPP
#define REGISTOES_HPP

#include "hora.hpp"
#include "Viatura.hpp"
#include <string>
using namespace std;

class Registo {
private:
    static int contador; // Contador est�tico para gerar n�meros autom�ticos incrementais
    int numero;          // N�mero do registo
	Hora* entrada;       // Hora de entrada
	Hora* saida;		 // Hora de sa�da
	Viatura* veiculo;	// Viatura
	bool pago;		   // Indica se o registo foi pago

public:
    // Construtores
	Registo(Viatura& v, Hora& he);// Construtor com hora de entrada
	Registo(Viatura& v, Hora& he, Hora& hs); // Construtor com hora de entrada e sa�da

    // Modificadores
    int registaSaida(Hora& hs); // Registra a sa�da e retorna os minutos de estacionamento
    bool paga();                // Marca como pago

    // M�todos de consulta
    int minutosEstacionamento() const;                         // Calcula minutos de he a hs
    int minutosEstacionamento(Hora& hatual) const;             // Calcula minutos de he a hatual
    bool estaEstacionado(const string& matricula) const;  // Verifica se est� estacionado

    // Acessores
	int getNumero() const;// Acessor para `numero`
	bool isPago() const;	// Acessor for `pago`
	string getMatricula() const; // Acessor para `matricula`
    Hora* getEntrada() const; // Acessor para `entrada`
    Hora* getSaida() const;   // Acessor para `saida`
    string toString() const;  // Representa��o dos dados
};

#endif // REGISTOES_HPP
