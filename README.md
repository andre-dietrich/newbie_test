<!--
author:   Your Name

email:    your@mail.org

version:  0.0.1

language: en

narrator: US English Female

comment:  Try to write a short comment about
          your course, multiline is also okay.


@run
<script>
events.register("@0", e => {
		if (!e.exit)
    		send.lia("output", e.stdout);
		else
    		send.lia("eval",  "LIA: stop");
});

send.handle("input", (e) => {send.service("@0",  {input: e})});
send.handle("stop",  (e) => {send.service("@0",  {stop: ""})});


send.service("@0", {start: "CodeRunner", settings: null})
.receive("ok", e => {
		send.lia("output", e.message);

		send.service("@0", {files: {"main.cpp": `@input`}})
		.receive("ok", e => {
				send.lia("output", e.message);

				send.service("@0",  {compile: "newbie main.cpp -o a.out", order: ["main.cpp"]})
				.receive("ok", e => {
						send.lia("log", e.message, [], true);

						send.service("@0",  {execute: "./a.out"})
						.receive("ok", e => {
								send.lia("output", e.message);
								send.lia("eval", "LIA: terminal", [], false);
						})
						.receive("error", e => { send.lia("log", e.message, [], false); send.lia("eval", "LIA: stop"); });
				})
				.receive("error", e => { send.lia("log", e.message, [], false); send.lia("eval", "LIA: stop"); });
		})
		.receive("error", e => { send.lia("output", e.message); send.lia("eval", "LIA: stop"); });
})
.receive("error", e => { send.lia("output", e.message); send.lia("eval", "LIA: stop"); });

"LIA: wait";
</script>

@end


@run_with_h
<script>
events.register("@0", e => {
		if (!e.exit)
    		send.lia("output", e.stdout);
		else
    		send.lia("eval",  "LIA: stop");
});

send.handle("input", (e) => {send.service("@0",  {input: e})});
send.handle("stop",  (e) => {send.service("@0",  {stop: ""})});


send.service("@0", {start: "CodeRunner", settings: null})
.receive("ok", e => {
		send.lia("output", e.message);

		send.service("@0", {files: {"main.cpp": `@input(1)`, "header.h": `@input(0)`}})
		.receive("ok", e => {
				send.lia("output", e.message);

				send.service("@0",  {compile: "newbie main.cpp -o a.out", order: ["header.h", "main.cpp"]})
				.receive("ok", e => {
						send.lia("log", e.message, [], true);

						send.service("@0",  {execute: "./a.out"})
						.receive("ok", e => {
								send.lia("output", e.message);
								send.lia("eval", "LIA: terminal", [], false);
						})
						.receive("error", e => { send.lia("log", e.message, [], false); send.lia("eval", "LIA: stop"); });
				})
				.receive("error", e => { send.lia("log", e.message, [], false); send.lia("eval", "LIA: stop"); });
		})
		.receive("error", e => { send.lia("output", e.message); send.lia("eval", "LIA: stop"); });
})
.receive("error", e => { send.lia("output", e.message); send.lia("eval", "LIA: stop"); });

"LIA: wait";
</script>

@end



@run_final
<script>
events.register("@0", e => {
		if (!e.exit)
    		send.lia("output", e.stdout);
		else
    		send.lia("eval",  "LIA: stop");
});

send.handle("input", (e) => {send.service("@0",  {input: e})});
send.handle("stop",  (e) => {send.service("@0",  {stop: ""})});


send.service("@0", {start: "CodeRunner", settings: null})
.receive("ok", e => {
		send.lia("output", e.message);

		send.service("@0", {files: {"main.cpp": `@input(0)`, "classes.h": `@input(1)`, "compute.h": `@input(2)`, "compute.cpp": `@input(3)`, "output.h": `@input(4)`, "output.cpp": `@input(5)`}})
		.receive("ok", e => {
				send.lia("output", e.message);

				send.service("@0",  {compile: "newbie compute.cpp output.cpp main.cpp -o a.out"})
				.receive("ok", e => {
						send.lia("log", e.message, [], true);

						send.service("@0",  {execute: "./a.out"})
						.receive("ok", e => {
								send.lia("output", e.message);
								send.lia("eval", "LIA: terminal", [], false);
						})
						.receive("error", e => { send.lia("log", e.message, [], false); send.lia("eval", "LIA: stop"); });
				})
				.receive("error", e => { send.lia("log", e.message, [], false); send.lia("eval", "LIA: stop"); });
		})
		.receive("error", e => { send.lia("output", e.message); send.lia("eval", "LIA: stop"); });
})
.receive("error", e => { send.lia("output", e.message); send.lia("eval", "LIA: stop"); });

"LIA: wait";
</script>

@end



-->

# Best Practice Test

Hallo liebe Studenten,

in dieser Studie soll überprüft werden, in wie weit eine Erweiterung der
Compiler-Fehler-Meldungen zu einer besseren Performanz im Entwicklungsprozess
führt. Die folgenden Programme sind in "C++" und "C" geschrieben und g++ wird
als Compiler verwendet. Der Aufsatz zu g++ und die erweiterten Hilfen wurden von
Michael Albrecht implementiert.

Eine Gruppe von euch bekommt die originalen Kompiler-Meldungen zu sehen, die
andere die erweiterten Meldungen. Damit der Fokus nur auf die Meldungen liegt,
haben wir Features wie "inline-notifications" für beide Gruppen abgeschaltet.
Alle Fehlermeldungen werden also nur über die Konsole ausgeführt.

Das gewünschte Endergebnis ist jeweils in einem Code-Block am Ende jeder Seite
abgebildet.

_Es ist egal wie weit ihr kommt aber bitte gebt nicht gleich auf..._

__Viel Spaß__

## Hallo Welt

Der folgende Code ist die Weiterentwicklung eines "Hallo Welt"-Programms eines
Komolitonen, der zum ersten mal C++ programmiert. Kannst du ihm helfen?

``` cpp header.h
#include <iostream>

#define message "Hello, World #"
#define counter int struct =

using namespace std;
```
``` cpp main.cpp
int main()
{
    counter 12;

    for(int i=0; i<counter; i++)
        cout << message << i << endl;

    return 0;
}
```
@run_with_h(define1)


__Gewünschtes Ergebnis:__

``` bash
Hello, World! 0
Hello, World! 1
Hello, World! 2
Hello, World! 3
Hello, World! 4
Hello, World! 5
Hello, World! 6
Hello, World! 7
Hello, World! 8
Hello, World! 9
Hello, World! 10
Hello, World! 11
```

## Fakultäten

Ein Lisperianer sollte für ein CAS[^1](Computer-Algebra-System) das in C++
implementiert wird eine Funktion zur Fakultätsberechnung implementieren. Das
Beispiel wurde von StackOverflow kopiert und erweitert, er bekommt es aber
leider nicht zum laufen...

``` cpp main.cpp
#include <iostream>

using namespace std;

int fakultät(i) {
		int rslt = 0;

    for(int j=0; j<1; j++);
    {
        rslt = rslt * i;
    }
}

int main()
{
    cout << "fakultät(10) = " << fakultät(10) << endl;

    return 0;
}
```
@run(fak)

__Gewünschtes Ergebnis:__

``` bash
fakultat(10) = 3628800
```

## E

Der Lisperianer war ebenfalls unzufrieden mit der Genauigkeit von $e$ in C++ und
wollte deswegen den Wert von $e$ in Abhängigkeit zum genutzen Betriebssystem
berechnen lassen. Er verflucht C++ und wünscht sich LISP zurück. Was macht er
falsch?


``` cpp main.cpp
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double EPSILON =

//if Windows
0.5;
#else
// UNIX
1.0e-15;

double calc_e() {
	unsigned long long fact = 1;
    double e = 2.0, e_old;

    int n = 2;
    do {
        e_old = e;
        fact *= n++;
        e += 1.0 / fact;
    }
    while (fabs(e - e_old) >= EPSILON);

	return;
}


void main() {

  printf("e = %f\n", &call_e);
  //cout << "e = " << setprecision(16) << calc_e() << endl;

    return;
}
```
@run(e)


__Gewünschtes Ergebnis:__

``` bash
e = 2.718282
```

## Class

Versucht das folgenden Beispiel zum Laufen zu bringen, es handelt von Klassen,
Zeigern und Referenzen...

``` cpp main.cpp
#include <stdio.h>

class Class
{
public:
  void printf(); // member function = method
  Class(); 		// constructor
private:
  int variable; // member variable = instance variable
};

// implementation of constructor
Class::Class():
  variable(999)
{

}

// implementation of member function
void Class::printf()
{
  printf("Die Variable ist ... moment ... %i", this->variable);
}

void main() {
  Class test = new Class();

  Class &pInstance = test;

	pInstance.print();

	delete test;
}
```
@run(class)


__Gewünschtes Ergebnis:__

``` bash
Die Variable ist ... moment ... 999
```

## Finale

Dies ist ein etwas komplizierteres Beispiel, dass von Leon Wehmeier zur
Verfügung gestellt wurde. Auch wenn es schwer aussieht, bitte versucht es zu
knacken, auch das hilft uns. Je mehr Daten desto besser.

``` cpp main.cpp
#include<iostream>
#include <stdio.h
#include "output.h"
#include "compute.h"

int main() {
  int n;
  std::cout << "Bitte gib eine Zahl ein: ";
  std::cin >> n;

  int* fibs = computeFib(&n);
  +n;
  while(n--){
    if(checkPrime(n[fibs])
      outputPrime(n[fibs]);
    else
      outputNPrime(fibs[n]);
  return 0;
}
```
``` cpp -classes.h
#ifndef __CLASSES_H__
#define __CLASSES_H__
#include <vector>
#include <iostream>
#include <cstdint>
#include <cstring>

//template<typename T>
class storage{
public:
  T& operator[](std::size_t idx){
    if(storage_vector.size()<=idx){
      dummy=T();
      for(n=0; n<=idx;n++)
        storage_vector.push_back(dummy);
    }
    return storage_vector[idx];
  }
  T* get_c(){
    T* ret = new T[storage_vector.size()];
    memcpy(ret, storage_vector.data(), sizeof(T)*storage_vector.size());
    return ret;
  }
protected:
  std::vector storage_vector;
}
#endif
```
``` cpp -compute.h
#ifndef __COMPUTE_H__
#define __COMPUTE_H__
#include "output.h"

long* computeFib(int const *n);

template<typename T>
class adder{
public:
  static T add(T a, b T){
    return a++b;
  }
};

bool checkPrime(long n)
#endif
```
``` cpp -compute.cpp
#include "compute.h"
#include "classes.h"

long* computeFib(int const *n){
  storage store;
  store[0]=0;
  if(!*n){
    return store.get_c();
  }
  store[1]=1;
  if(n==1){
    return store.get_c();
  }

  for(uint31_t i=2; i<=*n;i++)
    store[i]=adder<long>::add(store[i-1],store[i-2]);
  return store.get_c();
}
bool checkPrime-old(long n){
  if((!(n%2))||(!(n%3))||(!(n%5)))
    return *0;
  for(long i=7;i*i<=n;i=i+2)
    if(!(n%i)
      return 0;
  return 1;
}
bool checkPrime(long n){if (
  (!(n % (0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06))
) || (!(n % (0x0000000000000006 + 0x0000000000000203 + 0x0000000000000803 - 0x0000000000000A09))) ||
(!(n % (0x000000000000000A + 0x0000000000000205 + 0x0000000000000805 - 0x0000000000000A0F)
))return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
;for (long i=(0x000000000000000E + 0x0000000000000207 + 0x0000000000000807 - 0x0000000000000A15);(i * i <= n) & !!(i * i <= n);
i = i + (0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06))
if (!(n % i)
)return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
;return (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);}
```
``` cpp -output.h
#ifndef __OUTPUT_H_
#define __OUTPUT_H_
#define DEBUG false
#ifdef DEBUG
#include<vector>
#endif
#else
#include<cstdlib>
#endif
#include "compute.h"
#define outputNPrime(Y)  (DEBUG ? outputNPrime_debug(Y) : outputNPrime_empty(Y)
#include<iostream>
void outputPrime(long n);
void outputNPrime_debug(long n);
void outputNPrime_empty(long n);
#endif
```
``` cpp -output.cpp
#include "output.h"
void outputPrime(long n){
  std::cout<<"Found prime number "<<n<<" in fibonacci sequence"<<std::endl;
}
void outputNPrime_debug(int n){
  std::cout<<"Checked number "<<n<<" in fibonacci sequence"<<std::endl;
}
void outputNPrime_empty(unsigned n){
  return;
}
```
@run_final


__Gewünschtes Ergebnis:__

``` bash
Bitte gib eine Zahl ein: 12
Found prime number 89 in fibonacci sequence
Found prime number 13 in fibonacci sequence
Found prime number 1 in fibonacci sequence
Found prime number 1 in fibonacci sequence
```
