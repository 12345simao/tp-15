#ifndef HORA_HPP
#define HORA_HPP
#include <iostream>
#include <iomanip>  // print: std::stfill std::stw
#include <stdexcept>
#include <sstream>
using namespace std;

class Hora {
private:
    int hora_;
    int minutos_;
    int segundos_;
    bool eValida(int, int, int) const;

public:
    // construtores
    Hora(int hora, int minutos = 0, int segundos = 0); // Construtor principal com valores padrão
	//destrutor
	// ~Hora();
    
    // modificadores (set)
    void sethora(int, int, int);
   
    // Accessores (get)
    int gethora() const;
    int getminutos() const;
    int getsegundos() const;

    // toString    
    string toString() const;
    int minutosAte(const Hora& h) const;
    bool operator<(const Hora& h) const;
	
    
};
#endif // HORA_HPP