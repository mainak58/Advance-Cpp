#include<stdio.h>
// #include<iostream>
// using namespace std;

void myFunction(int i, int n){

    if(i > n){
        return;
    }
    myFunction(i+1,n);
    printf("%d ",i);
}

int main(){
    int n;
    // cout << "Enter the number: ";
    // cin >> n;

    scanf("%d",&n);
    myFunction(1,n);
    return 0;
}