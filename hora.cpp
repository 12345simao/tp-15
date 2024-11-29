
#include "hora.hpp"
using namespace std;


// construtores
// Construtor principal com valores padrão
Hora::Hora(int hora, int minutos, int segundos)//   
	: hora_(hora), minutos_(minutos), segundos_(segundos) {//inicializa os atributos
	if (!eValida(hora, minutos, segundos)) {//verifica se a hora é válida
		throw std::invalid_argument("Hora inválida");//lança uma exceção
    }
}
// Construtor com um parâmetro
bool Hora::eValida(int hora, int minutos, int segundos) const {//verifica se a hora é válida
	if (hora < 0 || hora > 23 ||//verifica se a hora está entre 0 e 23
		minutos < 0 || minutos > 59 ||//verifica se os minutos estão entre 0 e 59
		segundos < 0 || segundos > 59) {//verifica se os segundos estão entre 0 e 59
		return false;//retorna falso
    }
	return true;//retorna verdadeiro
}

// modificadores (set)
void Hora::sethora(int hora, int minutos, int segundos) {
    if (!eValida(hora, minutos, segundos)) {
        throw std::invalid_argument("Hora inválida");
    }
    hora_ = hora;
    minutos_ = minutos;
    segundos_ = segundos;
}

// Accessors
int Hora::gethora() const { return hora_; }
int Hora::getminutos() const { return minutos_; }
int Hora::getsegundos() const { return segundos_; }



string Hora::toString() const {
    //std::ostringstream oss;
    //oss << gethora() << "/" << getminutos() << "/" << getsegundos();
    //return oss.str();
	//string resultado;
    string strHora = to_string(gethora());
    string strMinutos = to_string(getminutos());
    string strSegundos = to_string(getsegundos());
    return "Hora {hora: " + strHora + ", minutos: " + strMinutos + ", segundos: " + strSegundos + "}";

}



int Hora::minutosAte(const Hora& h) const {//retorna a diferença de minutos entre duas horas
	int totalMinutos1 = gethora() * 60 + getminutos();//converte a hora para minutos
	int totalMinutos2 = h.gethora() * 60 + h.getminutos();//converte a hora para minutos
    return totalMinutos2 - totalMinutos1;
}
/*
bool Hora::operator<(const Hora h) const {
    if (gethora() < h.gethora()) return true;
    if (gethora() == h.gethora() && getminutos() < h.getminutos()) return true;
    if (gethora() == h.gethora() && getminutos() == h.getminutos() && getsegundos() < h.getsegundos()) return true;
    return false;
}
*/
bool Hora::operator<(const Hora& h) const {
    bool menorHora = gethora() < h.gethora();
    bool igualHoraMenorMinutos = gethora() == h.gethora() && getminutos() < h.getminutos();
    bool igualHoraIgualMinutosMenorSegundos = gethora() == h.gethora() && getminutos() == h.getminutos() && getsegundos() < h.getsegundos();

    return (menorHora || igualHoraMenorMinutos || igualHoraIgualMinutosMenorSegundos);
}



/*
Hora Hora::operator-(const Hora h) const {
    int totalSegundos1 = gethora() * 3600 + getminutos() * 60 + getsegundos();
    int totalSegundos2 = h.gethora() * 3600 + h.getminutos() * 60 + h.getsegundos();
	int diferença = totalSegundos1 - totalSegundos2;//diferença em segundos

	int horas = diferença / 3600;//converte a diferença para horas
    diferença %= 3600;//resto da divisão
	int minutos = diferença / 60;//converte o resto para minutos
	int segundos = diferença % 60;//resto da divisão

	return Hora(horas, minutos, segundos);//retorna a diferença
}*/