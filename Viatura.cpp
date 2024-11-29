#include "Viatura.hpp"
#include <stdexcept>
using namespace std;

Viatura::Viatura(const string matricula)
    : matricula(matricula) {}

//setters (modificadores)
void Viatura::setMatricula(const string matricula) {
	
	this->matricula = matricula;
}
   
//getters (acessores)
string Viatura::getMatricula() const {
    return matricula;
}
/*
string Viatura::getModelo() const {
    return modelo;
}

string Viatura::getMarca() const {
    return marca;
}
*/


string Viatura::toString() const {
    return "Matrícula: " + matricula;
}

