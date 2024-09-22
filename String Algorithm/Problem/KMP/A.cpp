#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s, p;
const int N = 1e6 + 5;
int n;
vector<int>failure(N);

function<void()> failTable = [&](){
    failure[0] = 0;
    for(int i = 1; i < n; i += 1){
        int j = failure[i - 1];
        while(j > 0 && p[i] != p[j]) j = failure[j - 1];

        if(p[i] == p[j]) failure[i] = j + 1;
    }
};

void solve(){
    cin >> s >> p;
    n = p.length();

    failTable();

    int m = s.length(), k = 0;
    vector<int>ans;
    for(int i = 0; i < m;){
        if(s[i] == p[k]){
            k += 1; 
            if(k == n){
                ans.push_back(i - n + 2), k = 0; i = ans.back();
            }
            else i += 1;
        }
        else{
            if(!k) i += 1;
            else k = failure[k - 1]; 
        }
    }

    if(!ans.size()){
        cout << "Not found" << endl;
        return;
    }
    cout << ans.size() << endl;
    for(int i: ans) cout << i << " ";
    cout << endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for(int i = 0; i < t; i += 1){
        solve();
        cout << endl;
    }
    
    return 0;
}