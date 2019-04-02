#include <iostream>

using namespace std;

int fakultat(int i) {
		int rslt = 1;

    for(int j=1; j<i; j++)
    {
        rslt = rslt * j;
    }

    return rslt;
}

int main()
{
    cout << "fakultat(10) = " << fakultat(10) << endl;

    return 0;
}
