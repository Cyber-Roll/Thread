import std;
using namespace std;

//************************************************************ PARA RECUPERAR LOS CALCULOS DEL THREAD
//************************************************************ implementar:		 operator(), hara el calculo deseado
//************************************************************ implementar un método que devuelva el cálculo

class Calculator
{
public:
	explicit Calculator(int a, int b) : m_a{ a }, m_b{ b } {}
	void operator()() { result = m_a * m_b; }
	int getResult() const { return result; }
private:
	int m_a{ 0 };
	int m_b{ 0 };
	int result{ 0 };
};

int main()
{
	Calculator calculator{ 21, 2 };
	jthread job{ ref(calculator) };
	job.join();
	println("21*2 = {}", calculator.getResult());
}


//Como has visto en los ejemplos anteriores, lanzar un nuevo hilo es bastante fácil.Sin embargo, en la mayoría de los casos
//probablemente le interesen los resultados producidos por el subproceso.Por ejemplo, si su hilo realiza
//cálculos matemáticos, te gustaría obtener los resultados una vez que el hilo haya terminado.
//finalice.Una forma es pasar un puntero o referencia a una variable de resultado al proceso en el que el proceso almacena los resultados.
//el hilo almacena los resultados.Otra técnica consiste en almacenar los resultados dentro de los miembros de datos de clase de un objeto
//que puede recuperar más tarde, una vez que el subproceso haya terminado de ejecutarse.Esto sólo funciona
//si usas std::ref() para pasar tu objeto función por referencia al constructor de jthread.A continuación se muestra
//un ejemplo :