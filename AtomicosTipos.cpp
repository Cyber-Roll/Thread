//************************************************************ Permiten escritura y lectura concurrente sin sincronizacion adicional
//************************************************************ tonces, usar atomic<int> contador{0}. Existen muchos otros en la libreria
//************************************************************ <atomic>: atomic_bool, atomic_int (Pag. 1001, ++Profesional)
//************************************************************ Por debajo, este tipo de datos, pueden utilizar mecanismos para hacerlos 
//************************************************************ seguros (mutex), si fuera necesario.

//import std;
//
//using namespace std;
//
//struct Foo { int m_array[120]; };
//struct Bar { int m_int; };
//
//int main()
//{
//	atomic<Foo> f;
//	println("{} {}", is_trivially_copyable_v<Foo>, f.is_lock_free());
//
//	atomic<Bar> b;
//	println("{} {}", is_trivially_copyable_v<Bar>, b.is_lock_free());
//}

import std;

using namespace std;

int main()
{
	atomic<int> value{ 10 };
	println("Value = {}", value.load());
	int fetched{ value.fetch_add(4) };
	println("Fetched = {}", fetched);
	println("Value = {}", value.load());
}
