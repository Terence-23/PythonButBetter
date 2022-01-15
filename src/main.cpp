#include <iostream>
#include <string>
#include <algorithm>
#define index unsigned long long

using namespace std;

struct  cos{
    int a, b;
};


int main(){
    cos a = {5, 6};
    cos& b = a;
    a.a += 5;
    cout << "A: "<< a.a <<"\nB: "<< b.a;
    

    return 0;
}