#ifndef VIATURA_HPP
#define VIATURA_HPP

#include <string>
using namespace std;

class Viatura {
private:
    string matricula;
    //string modelo;
    //string marca;

public:
	// Construtores
    Viatura(string);

    // Modificadores (set)
    void setMatricula(string);
	//void setModelo(string modelo);
	//void setMarca(string marca);
    // 
	// Acessores (get)
    string getMatricula() const;
    //string getModelo() const;
    //string getMarca() const;

	// toString
    string toString() const;
};

#endif // VIATURA_HPP


