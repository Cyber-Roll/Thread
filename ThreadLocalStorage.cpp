import std;
using namespace std;

int k;
thread_local int n;

void threadFunction(int id)
{
	println("Thread {}: k={}, n={}", id, k, n);
	++n;
	++k;
}

static thread_local int x1; // OK, internal linkage (See Chapter 11)
thread_local int x2; // OK, external linkage (See Chapter 11)
class Foo
{
	static thread_local int x3; // OK
	//thread_local int x4; // Error!
};
void f()
{
	static thread_local int x5; // OK
	thread_local int x6; // OK, implicitly static!
}




int main() {
	//--------------------------------------- comparten solo una copia de k,   SOLO UNA!!!!
	//--------------------------------------- la variable n, es una para cada uno de los Threads
	thread t1{ threadFunction, 1 }; t1.join();
	thread t2{ threadFunction, 2 }; t2.join();
}
