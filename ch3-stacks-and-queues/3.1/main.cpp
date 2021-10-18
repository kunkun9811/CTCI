#include <iostream>
#include "three_stacks.hpp"

using namespace std;

int main() {
        ThreeStacks* stackOf3 = new ThreeStacks();

        stackOf3->pushTo(0, 1);
        stackOf3->pushTo(0, 2);
        stackOf3->pushTo(0, 3);
        stackOf3->pushTo(0, 4);
        stackOf3->pushTo(0, 5);

        stackOf3->pushTo(1, 6);
        stackOf3->pushTo(1, 7);
        stackOf3->pushTo(1, 8);
        stackOf3->pushTo(1, 9);
        stackOf3->pushTo(1, 10);

        stackOf3->pushTo(2, 11);
        stackOf3->pushTo(2, 12);
        stackOf3->pushTo(2, 13);
        stackOf3->pushTo(2, 14);
        stackOf3->pushTo(2, 15);

        for(int i = 0; i < 3; i++){
                cout << "-----------------Stack [" << i << "]-----------------" << endl;
                while(!stackOf3->emptyOf(i)){
                        cout << stackOf3->topOf(i)->val << endl;
                        stackOf3->popFrom(i);
                }
        }

        stackOf3->popFrom(0);
        stackOf3->popFrom(1);
        stackOf3->popFrom(2);
        stackOf3->topOf(0);
        stackOf3->topOf(1);
        stackOf3->topOf(2);

        return 0;
}