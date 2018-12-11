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

-->

# Best Practice Test

TODO: Beschreibende Einführung

C++

## Intro

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

/*
result
------------------------------------
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
*/
```
@run_with_h(define1)

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

/*
result
------------------------------------
fakultat(10) = 3628800
*/
```
@run(fak)

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

/*
result
------------------------------------
e = 2.718282
*/
```
@run(e)
