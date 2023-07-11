#include <iostream>

using namespace std;

void StampaPuntatore(int *k) {

     for(int i = 0; i < 10; i ++) {

        if(*(k+i) == -1) {
            return;
        }

        cout << *(k+i);

     }

}

void StampaPuntatoreNoVariabili(int *k) {

    for(; *k != -1; *(k++)) {

        cout << *k;

    }


}

int main () {

    int v[10] = { 1 , 2 , 3 , 4 , 5 , 6 , -1 , 8 , 9, 7 };

     int *p = v;

    StampaPuntatore(p);
    cout << endl;
    
    StampaPuntatoreNoVariabili(p);

}