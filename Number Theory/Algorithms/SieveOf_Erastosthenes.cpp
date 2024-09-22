#include<bits/stdc++.h>
using namespace std;
class sieve{
public:
    vector<bool>isPrime;
    sieve(int n){
        isPrime.resize(n + 1, true);

        isPrime[1] = false;
        for(int i = 4; i < n; i += 2)
            isPrime[i] = false;
    
        for(int i = 3; i*i < n; i += 2){
            if(isPrime[i]){
                for(int j = i*i; j < n; j += i) isPrime[j] = false;
            }
        }
    }
};

int main(void){
    int n;
    cin>>n;
    sieve p(n);
}
