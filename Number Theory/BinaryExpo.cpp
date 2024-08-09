#include<bits/stdc++.h>
using namespace std;

int binExp(int a, int n){
    int res = 1;

    while(n){
        if(n%2){
            res *= a;
            n -= 1;
        }
        else{
            a *= a;
            n /= 2; 
        }
    }
    return res;
}

int main(){
    int a,n;
    cin>>a>>n;

    cout<<binExp(a,n)<<endl;
}