#include <iostream>
 using namespace std;


void stampa(int n){

    if(n==0) {
        return; 
    }
    if (n % 2) {
        stampa(n-1); 
    }else{
        stampa(n-2); 
        cout << n <<" "; 
        return;
    }
}

int main() {

    int x = 9;

    stampa(x);


}