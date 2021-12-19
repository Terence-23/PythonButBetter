#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    const int n = 6;
    string array[n] ={"int", "float", "string", "list", "map", "bool"};

    sort(array, array+n);
    
    for(auto i : array){
        cout <<'"'<< i << "\"\n";
    }

    return 0;
}