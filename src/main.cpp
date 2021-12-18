#include <iostream>
#include "lexer.cpp"


using namespace std;

int main(){

    cout << "Dziala\n";
    for (int i = 0; i < 10; i++){
        cout << i << "\n";
        for(int j = 0; j < 10 ; j ++){
            cout << i * j << "\n";
            break;
        }
    }
    return 0;
}