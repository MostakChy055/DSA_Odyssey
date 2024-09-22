#include<bits/stdc++.h>
using namespace std;

int main(void){
    vector<int>ar{7, 1, 9, 5, 3};
    sort(ar.begin(), ar.end());

    int left = 0, right = ar.size() - 1, query = 6;

    while(left<right){
        int mid = ( left + right )/2;
        if(ar[mid] > query) right = mid - 1;
        else left = mid;
    }

    cout<<ar[left]<<endl;

    return 0;
}