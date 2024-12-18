import std;
using namespace std;

random_device rd; // Semilla aleatoria
mt19937 gen(rd()); // Inicializar el generador con la semilla

// Definir la distribución de números aleatorios
uniform_int_distribution<> distrib(1, 100); // Números enteros entre 1 y 100

int main() {
    // Crear un generador de números aleatorios utilizando el motor Mersenne Twister
    

    std::cout << "Generación de 10 números aleatorios entre 1 y 100:" << std::endl;
    for (int i = 0; i < 510; ++i) {
        int random_number = distrib(gen);
        std::cout << random_number << std::endl;
    }

    return 0;
}
