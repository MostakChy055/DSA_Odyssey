#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'

void merge(vector<int>&vc, int left, int mid, int right){
    vector<int>dummy(right - left + 1);
    int lft = left, rght = mid + 1, curr = 0;

    for(int i = left; i<=right; i += 1){
        if(lft > mid)   dummy[curr++] = vc[rght++];
        else if(rght > right)   dummy[curr++] = vc[lft++];
        else if(vc[lft] < vc[rght]) dummy[curr++] = vc[lft++];
        else dummy[curr++] = vc[rght++];
    }

    for(int X: dummy)   vc[left++] = X;
}

void mergeSort(vector<int>&vc, int left, int right){
    if(right <= left)   return;
    int mid = (left + right)/2;
    mergeSort(vc, left, mid);
    mergeSort(vc, mid + 1, right);

    merge(vc, left, mid, right);
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin>> n;
    vector<int>vc(n);
    for(int &X: vc) cin>>X;

    mergeSort(vc, 0, vc.size() - 1);

    for(int X: vc)  cout<<X<<' ';
    cout<<endl;

    return 0;
}