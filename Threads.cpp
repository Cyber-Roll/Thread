// +thread +random +aleatorio +delay +sleep

import std;
using namespace std;

random_device rd; // Semilla aleatoria
mt19937 gen(rd()); // Inicializar el generador con la semilla

// Definir la distribución de números aleatorios
uniform_int_distribution<> distrib(0, 2); // Números enteros entre 1 y 100

void EsperaUnTiempo(const size_t& tiempo) {
    
    this_thread::sleep_for(std::chrono::seconds(tiempo));
}


class Counter
{
public:
    // ---------------------------------------------------------------------- Inicializacón corriente
    explicit Counter(int id, int numIterations)
        : m_id{ id }, m_numIterations{ numIterations } { }

    // ---------------------------------------------------------------------- DEBE SER IMPLEMENTADA PARA EL THREAD!!!
    // ---------------------------------------------------------------------- Esta será llamada por el Thread
    void operator()() const
    {
        for (int i{ 0 }; i < m_numIterations; ++i) {
            println("Counter {} has value {}", m_id, i);
        }
    }
private:
    int m_id{ 0 };
    int m_numIterations{ 0 };
};

// funcion que sera ejecutada por los threads (mas de uno, por eso threads) 
void counter(const string& msg, const int& numIterations)
{
    size_t TiempoAesperar{};
    for (int i{ 0 }; i < numIterations; ++i) {      
       /* TiempoAesperar = distrib(gen);
        EsperaUnTiempo(TiempoAesperar);*/
        println("Thread:{} [{}], Waited: {}s", msg, i, TiempoAesperar);        
    }
}
void rollnew(const int& t) {
    this_thread::sleep_for(std::chrono::milliseconds(t));
    println("***** Estuve esperando {} ms", t);
}

class Request
{
    public:
        explicit Request(int id) : m_id{ id } { }
        void process() { println("Processing request {}", m_id); }
    private:
        int m_id{ 0 };
};


int main()
{
    //// -------------------------------------------------------------------------------------------- THREADS con PUNTERO A FUNCIÓN
    //thread tPri{ counter, "-------------------------------- Primero", 10 };
    //thread tSec{ counter, "------ Segundo", 15 };
    //thread tOtr{ rollnew, 0 };
    //tPri.join();  // emplear para acabar correctamente estos
    //tSec.join();
    //tOtr.join();

     // --------------------------------------------------------------------------------------------- THREADS con OBJETO (CLASE INSTANCIADA)
     //---------------------------------------------------------------------- objeto creado y luego
     //---------------------------------------------------------------------- alimentado al thread
    Counter c1{ 10000, 800 };
    thread t1{ c1 };

    // ---------------------------------------------------------------------- En uno solo 
    thread t2{ Counter{30, 800} };
    t1.join();
    t2.join();
   

    //----------------------------------------------------------------------------------------------- THREADS con una funcion LAMBDA
    int id{ -500 };
    int numIterations{ 5 };
    thread tX{ [id, numIterations] { for (int i { 0 }; i < numIterations; ++i)  println("Counter {} has value {}", id, i); }//lambda   
             };
    // formato funcion lambda [param1, param2, ...] { CUERPO DE LA FUNCION }
    tX.join();

    //----------------------------------------------------------------- Thread con  un PUNTERO A UNA FUNCION MIEMBRO DE UNA CLASE (Member FUNCTION POINTER)
    Request req{ 100 };
    thread t{ &Request::process, &req };
    t.join();

}

