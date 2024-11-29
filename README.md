
# Projeto de Gestão de Parque de Estacionamento

## Descrição
Este projeto implementa um sistema para gerenciar um parque de estacionamento, oferecendo funcionalidades como:
- Registro de entrada e saída de veículos.
- Cálculo de tarifas e valores faltantes.
- Verificação de disponibilidade do parque.
- Monitoramento do tempo total de estacionamento por veículo.

---

## Estrutura do Projeto

### Principais Classes e Seus Métodos

#### **Classe `Hora`**
Localização: `hora.hpp` e `hora.cpp`

- **Construtores e Destrutores:**
  - `Hora(int hora, int minutos = 0, int segundos = 0)`: Cria um objeto `Hora` com valores padrão.
- **Modificadores (Setters):**
  - `void sethora(int hora, int minutos, int segundos)`: Define valores para a hora.
- **Acessores (Getters):**
  - `int gethora() const`: Retorna a hora.
  - `int getminutos() const`: Retorna os minutos.
  - `int getsegundos() const`: Retorna os segundos.
- **Outros Métodos:**
  - `string toString() const`: Retorna a representação da hora como string.
  - `int minutosAte(const Hora& h) const`: Calcula a diferença em minutos entre duas horas.
  - `bool operator<(const Hora& h) const`: Compara se uma hora é menor que outra.
- **Métodos Privados:**
  - `bool eValida(int hora, int minutos, int segundos) const`: Verifica se os valores de hora, minutos e segundos são válidos.

---

#### **Classe `Viatura`**
Localização: `Viatura.hpp` e `Viatura.cpp`

- **Construtores:**
  - `Viatura(string)`: Cria uma viatura com a matrícula fornecida.
- **Modificadores:**
  - `void setMatricula(string)`: Define uma nova matrícula para a viatura.
- **Acessores (Getters):**
  - `string getMatricula() const`: Retorna a matrícula da viatura.
- **Outros Métodos:**
  - `string toString() const`: Retorna a representação da viatura como string.

---

#### **Classe `Registo`**
Localização: `registroes.hpp` e `registroes.cpp`

- **Construtores:**
  - `Registo(Viatura& v, Hora& he)`: Cria um registro com a viatura e hora de entrada.
  - `Registo(Viatura& v, Hora& he, Hora& hs)`: Cria um registro com viatura, hora de entrada e saída.
- **Modificadores:**
  - `int registaSaida(Hora& hs)`: Registra a saída e retorna o tempo de estacionamento em minutos.
  - `bool paga()`: Marca o registro como pago.
- **Acessores (Getters):**
  - `int getNumero() const`: Retorna o número do registro.
  - `bool isPago() const`: Indica se o registro foi pago.
  - `string getMatricula() const`: Retorna a matrícula da viatura.
  - `Hora* getEntrada() const`: Retorna a hora de entrada.
  - `Hora* getSaida() const`: Retorna a hora de saída.
- **Outros Métodos:**
  - `int minutosEstacionamento() const`: Calcula o tempo de estacionamento entre entrada e saída.
  - `int minutosEstacionamento(Hora& hatual) const`: Calcula o tempo de estacionamento até uma hora atual.
  - `bool estaEstacionado(const string& matricula) const`: Verifica se uma viatura está estacionada.
  - `string toString() const`: Retorna uma representação do registro como string.

---

#### **Classe `Parque`**
Localização: `parque.hpp` e `parque.cpp`

- **Construtores:**
  - `Parque(string idparque, int lotacao = 100)`: Inicializa o parque com um identificador e lotação.
- **Modificadores:**
  - `bool estaciona(Viatura& v, Hora& he)`: Registra a entrada de uma viatura.
  - `double saida(string matricula, Hora& hs)`: Registra a saída de uma viatura e calcula o valor devido.
  - `void ordenarRegistos()`: Ordena os registros de entrada por hora.
- **Acessores (Getters):**
  - `int ocupacao() const`: Retorna o número de veículos estacionados.
  - `int lugaresLivres() const`: Retorna o número de vagas disponíveis.
  - `Hora tempoTotalDeEstacionamento(string matricula) const`: Calcula o tempo total de estacionamento de uma viatura.
  - `vector<Registo> getRegistosPorMatricula(const string& matricula) const`: Retorna os períodos de estacionamento de uma viatura.
- **Outros Métodos:**
  - `double valorTotalRecebido() const`: Retorna o total arrecadado pelo parque.
  - `double valorTotalFaltante(Hora& horaAtual) const`: Calcula o valor devido pelos veículos estacionados.
  - `bool estaEstacionado(string matricula) const`: Verifica se uma viatura está estacionada.
  - `string listarRegistos() const`: Retorna uma lista dos registros no parque.
  - `string toString() const`: Retorna uma representação do parque como string.

---

## Código Desenvolvido
Exemplos de métodos implementados foram listados nas seções acima. Todos os métodos foram descritos e organizados conforme cada classe.

---

## Como Executar
1. Compile o projeto utilizando os arquivos fornecidos.
2. Execute o arquivo `main.cpp` para validar as funcionalidades com base nos testes implementados.
3. Os resultados dos testes serão exibidos no console.

Se precisar de mais informações ou alterações, entre em contato.
