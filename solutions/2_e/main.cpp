#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double EPSILON =

#ifdef Windows
0.5;
#else
// UNIX
1.0e-15;
#endif

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

	return e;
}


int main() {

  printf("e = %f\n", calc_e());
  //cout << "e = " << setprecision(16) << calc_e() << endl;

    return 0;
}
