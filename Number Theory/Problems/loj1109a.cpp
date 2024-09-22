#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1005
vector<pair<int, int>>ans;

bool cmp(const pair<int, int>&a, const pair<int, int>&b){
    if(a.first == b.first)  return a.second>b.second;
    else return a.first<b.first;
}

void NOD(){
    vector<int>dv(M);

    for(int i = 1; i<=M-5; i += 1){
        for(int j = i; j<=M-5; j += i)  dv[j] += 1;

        ans.push_back({dv[i], i});
    }

    sort(ans.begin(), ans.end(), cmp);
}

void solve(){
    int n;
    cin>>n;
    cout<<ans[n - 1].second<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    NOD();

    int t;
    cin>>t;

    for(int i = 1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}
