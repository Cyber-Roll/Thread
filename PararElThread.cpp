import std;
using namespace std;


//************************************************************ C++ no incluye instrucciones para cancelar un Thread desde otro
//************************************************************ JTHREAD es una solucion parcial, si no es útil, se debe inplementar
//************************************************************ un mecanismo de comunicación entre los threads para ello: ENTONCES
//************************************************************ IMPLEMTAR UNA VARIABLE QUE SE DEBE CONSULTAR CADA VEZ SI ES NECESARIO
//************************************************************ ACABAR EL PROCESO. Si se tiene varias Thread al menos una de ella debe
//************************************************************ escribir sobre esta. ENTONCES USAR VARIABLE ATOMICAS O VARIABLES 
//************************************************************ CONDICIONALES

//************************************************************ JTHREAD es lo mismo que Thread, con las diferencias: 
//************************************************************ ➤➤ Se une automáticamente en su destructor.
//************************************************************ ➤➤ Admite la cancelación cooperativa.

//************************************************************ La cancelación que ofrece jthread es COOPERATIVA porque debe preguntar
//************************************************************ cada vez si se debe cancelar.

//************************************************************ ➤➤ std::stop_token: Admite la comprobación activa de una solicitud de cancelación.Un hilo cancelable
//************************************************************ necesita llamar periódicamente a stop_requested() sobre un stop_token para averiguar si necesita
//************************************************************ detener su trabajo.Un stop_token se puede utilizar con una condition_variable_any para que un hilo
//************************************************************ puede despertar cuando necesita parar.
// 
//************************************************************ ➤➤ std::stop_source : Se utiliza para solicitar a un hilo que cancele su ejecución.Esto se hace llamando a
//************************************************************ la función miembro request_stop() sobre un stop_source.Si se utiliza un stop_source para
//************************************************************ solicitar una cancelación, esa solicitud de parada es visible para todos los stop_sources y stop_
//************************************************************ asociados.La función miembro stop_requested() puede utilizarse para comprobar si una parada tiene
//************************************************************ ya ha sido solicitada

void threadFunction(stop_token token, int id)
{
	while (!token.stop_requested()) {
		println("Thread {} doing some work.", id);
		this_thread::sleep_for(500ms);
	}
	println("Stop requested for thread {}.", id);
}

int main()
{
	jthread job1{ threadFunction, 1 };
	jthread job2{ threadFunction, 2 };
	this_thread::sleep_for(10s);
	println("main() is ending.");
	job1.request_stop();
	job2.request_stop();
}