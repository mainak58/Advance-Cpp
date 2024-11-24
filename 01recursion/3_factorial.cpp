#include<iostream>
using namespace std;

int factorial(int n){
    if(n == 1){
        return 1;
    }
    if(n > 0){
    return n*factorial(n-1);
    }
}

int main(){
    int n;
    cout << "Give me a number ";
    cin >> n;

    cout << "The factoral is " << factorial(n);
    return 0;
}
