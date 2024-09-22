#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>vc, int query){
    int n = vc.size(), right = n - 1, left = 0, mid;

    sort(vc.begin(), vc.end());

    while(left <= right){
        mid = (right + left)/2;

        if(vc[mid] == query)    return true;
        else if(vc[mid]<query)
            left = mid + 1;
        else right = mid - 1;
    }

    return false;
}

int main(void){
    vector<int>vc{1,3,4,2,1};
    int need = 3;

    bool res = binarySearch(vc, need);

    res?cout<<"Found buddy": cout<<"No sign here buddy!\n";

    return 0;
}