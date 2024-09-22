#include<bits/stdc++.h>
using namespace std;
#define M 10000005
vector<int>dv(M);

void NOD(){
    for(int i = 1; i<=M; i += 1){
        for(int j = i; j<=M; j += i)    dv[j] += 1; // dv[j]  += i for sum of all the divisors of 1 to n;
    }
}

int main(void){
    NOD();

    for(int i = 1; i<=50; i += 1)   cout<<"i:\t"<<i<<" "<<dv[i]<<endl;
    return 0;
}

// This can be used to get the sum of all the divisors (div[j] += i) a number from 1 to n. We can do both the euler's totient function and find the biggest
// prime divisor ( div[j] = i );