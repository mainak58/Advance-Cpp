#include<iostream>
#include<vector>
using namespace std;

int quickSorting(vector<int>& arr, int left, int right){

    int pivot = arr[left];
    int i = left;
    int j = right;

    while(i < j){
        while(arr[i] <= pivot && i <= right -1){
            i++;
        }
        while(arr[j] > pivot && j >= left+1) {
            j--;
        }   

        if(i < j) swap(arr[i] , arr[j]);
    }

    swap(arr[left] , arr[j]);
    return j;
}

void sorting(vector<int>& arr , int left, int right){

    if(left < right){
    int pivot = quickSorting(arr, left, right);

        sorting(arr, left, pivot-1);
        sorting(arr, pivot+1 , right);
    }

}

int main(){
    vector<int> arr = {5, 4, 3, 8, 1,7,2,6};

    cout << "The original array is ";

    for(auto num: arr){
        cout << num << " ";
    }


    cout << endl;

    sorting(arr, 0, arr.size() -1);

    for(auto num: arr){
        cout << num << " ";
    }


    cout << endl;
    return 0;
}