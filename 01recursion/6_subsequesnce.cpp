#include<iostream>
#include <vector>

using namespace std;

void subSequence(int index, vector<int>& ds, int arr[], int n){
    if(index == n){
        for(auto it: ds){
            cout << it << " ";
        }
        if(ds.size() == 0){
            cout << "{}";
        }
        cout << endl;
        return;
    }
        subSequence(index+1, ds, arr, n);

        ds.push_back(arr[index]);
        subSequence(index+1, ds, arr, n);
        ds.pop_back();
    
}

int main(){
    int arr [] = {3,2,1};
    int n = 3;
    vector<int> ds;
    subSequence(0, ds, arr, n);
    return 0;
}