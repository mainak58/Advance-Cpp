#include<iostream>
using namespace std;

int* myFunction(int cups){
    int* arr = new int[cups];

    for(int i=0; i<cups; i++){
        arr[i] = i+1;
    }

    return arr;
}

int main(){
    int* myArr = myFunction(5);

    for (int i = 0; i < 5; i++) {
        cout << myArr[i] << " ";
    }
    delete[] myArr;       
    return 0;
}