#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& vec, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid +1;

    while(left<=mid && right<=high){
        if(vec[left]<=vec[right]){
            temp.push_back(vec[left]);
            left++;
        }
        else{
            temp.push_back(vec[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(vec[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(vec[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        vec[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& vec,int low, int high){
    if(low>=high){
        return;
    }
    int mid  = low + (high - low)/2;
    mergeSort(vec, low, mid);
    mergeSort(vec, mid+1, high);
    merge(vec, low, mid, high);
}

void insertionSort(vector<int>& vec, int n){
    int key;
    for(int i=1; i<n; i++){
        key = vec[i];
        int j = i-1;
        while(j>=0 && vec[j]>key){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
}

void bubbleSort(vector<int>& vec, int n){
    //swap the larger value towards right.
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(vec[j]>vec[j+1]){
                swap(vec[j],vec[j+1]);
            }
        }
    }
}

void selectionSort(vector<int> vec, int n){
    //track the index of mini value
    int minInd;
    for(int i=0; i<n; i++){
        minInd = i;
        for(int j=i+1; j<n; j++){
            if(vec[minInd]>vec[j]){
                minInd = j;
            }
        }
        if(minInd != i){
            swap(vec[i], vec[minInd]);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    mergeSort(vec, 0, n-1);

    for(auto i: vec){
        cout<<i<<" ";
    }
    cout<<endl;
}