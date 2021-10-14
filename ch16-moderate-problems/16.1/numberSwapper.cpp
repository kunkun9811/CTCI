#include <iostream>

using namespace std;

void numberSwapper(int a, int b){

    cout << "_____BEFORE_____" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    a += b;
    b = a - b;
    a -= b;

    cout << "_____AFTER_____" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "=================================================" << endl;

    return;
}

int main() {

    numberSwapper(2,3);
    numberSwapper(10,11);
    numberSwapper(-100, 10);
    numberSwapper(10, -100);
    numberSwapper(-100, -111);

    return 0;
}