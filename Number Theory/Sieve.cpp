#include<bits/stdc++.h>
using namespace std;

//global array to store iTh number as prime or not - 0 (notPrime), 1 (prime)
int isPrime[1000001];

void sieve(){
    int maxN = 1000000;

    //Consider all as prime initially
    for(int i=0; i<=maxN; i++){
        isPrime[i] = 1;
    }

    // 0 and 1 is not prime.
    isPrime[0] = isPrime[1] = 0;

    for(int i=2; i*i<=maxN; i++){
        if(isPrime[i]){
            //if iTh number is prime, make all its multiple as composite.
            for(int j=i*i; j<=maxN; j+=i){
                isPrime[j] = 0;
            }
        }
    }
}

int main(){
    sieve();

    int query;
    cin>>query;

    while(query--){
        int n;
        cin>>n;
        if(isPrime[n]){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}