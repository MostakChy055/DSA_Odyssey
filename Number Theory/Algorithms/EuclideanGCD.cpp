#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(!b)  return a;
    else return gcd(b, a%b);
}

int main(void){
    int a, b;
    cin>>a >>b;

    int x = gcd(a, b);
    cout<<x<<endl;
    return 0;
}