#include <iostream>

using namespace std;

void stampapunt(int *k) {

    for(int i = 0; *(k+i) != -1; i++) {

        cout << *(k+i);

    }

}

void stampapuntnovar(int *k) {

    while(*k != -1) {

        cout << *(k);
        *k++;
    

    }

}

int main () {

    int arr [12] = {10, 9 , 8 , 7, 6, 5, 4, 3, 2, 1, -1, 0,};
    int *k = arr;

    stampapunt(k);
    stampapuntnovar(k);


    return 0;
}