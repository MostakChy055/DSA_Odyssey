#include<bits/stdc++.h>
using namespace std;

double f(double a){
    return (double) a * a;
}

double find_square(int n){
    double left = 0, right = n, mid;

    while(left<=right){
        mid = (left + right)/2;
        if(f(mid)<=n)   left = mid;
        else right = mid - 1;  
    }

    return left;
}

int main(void){
    int n;
    cin>>n;

    double ans = find_square(n);
    cout<<ans<<endl;

    return 0;
}