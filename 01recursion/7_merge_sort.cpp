#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& arr, int left,int mid, int right){
    int n1 = mid-left +1;
    int n2 = right - mid;

    vector <int> leftArr(n1), rightArr(n2);

    for(int i =0; i< n1 ; i++){
        leftArr[i] = arr[left+i];
    }

    for(int i=0; i< n2 ; i++){
        rightArr[i] = arr[mid + 1 +i];
    }

    int i=0, j=0, k= left;
    while (i < n1 && j <n2){
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    if(left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    // merge sorted array

    merge(arr, left, mid, right);
    }
}

int main(){
    vector<int> arr = {38,15,20,56,5,9,8,7,56};

    cout << "The original array is ";
    for(auto num: arr){
        cout << num << " ";
    }


    cout << endl;

    // apply merge sort

    mergeSort(arr, 0 , arr.size() -1);

    cout << "sorted array ";

    for(auto num: arr){
        cout << num << " " ;
    }
    cout << endl;
    return 0;
}