#include<iostream>
using namespace std;

int myFunction(int n){
    if(n == 0){
        return 0;
    }
    return n + myFunction(n-1);
}

int main(){
    int n;
    cout << "give me the a number ";
    cin >>n;
    cout << myFunction(n);
    return 0;
}