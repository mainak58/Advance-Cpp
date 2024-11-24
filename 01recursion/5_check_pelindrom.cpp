#include<iostream>
using namespace std;

bool myFunction(int i, string& s){
    if(i >= s.size() / 2) return true;

    if(s[i] != s[s.size() -i - 1]) return false;

    return myFunction(i+1, s);
}

int main(){
    string n = "abuiba";
    if (myFunction(0, n)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }
    return 0;
}