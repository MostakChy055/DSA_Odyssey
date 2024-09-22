#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int , int>&a, pair<int , int>&b){
    if(a.first >= b.first && a.second < b.second) return 1;
    else return 0;
}
int main(void){
    int n;
    cin >> n;
    vector< pair<int , int> >vp;
    for(int i = 0; i < n; i += 1){
        int a;
        cin >> a;
        vp.push_back({a, i});
    }

    sort(vp.begin(), vp.end(), cmp);
    for(pair<int , int> x: vp)  cout << x.first << " " << x.second << '\n';
    
    return 0;
}