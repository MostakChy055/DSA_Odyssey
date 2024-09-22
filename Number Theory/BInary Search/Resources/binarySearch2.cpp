#include<bits/stdc++.h>
using namespace std;

int binarySearch(int n, int query){
    vector<int>ar{7, 1, 9, 5, 3};
    sort(ar.begin(), ar.end());

    int k = 0;

    for(int i = n/2; i>=1; i += 1){
        while(k + i < n && ar[k + i] <= query)  k  += 1;
    }

    if(ar[k] == query)  return k;
    else return - 1;
}
int main(void){
    int n, query, index;
    cin>> n >> query;
    index = binarySearch(n, query);

    cout<<index<<endl;

    return 0;
}