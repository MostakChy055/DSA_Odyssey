#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.length();
    set<char>sch;
    vector<int>khela, failure(n);
    for(char ch: s) sch.insert(ch);
    if(sch.size() == 1){
        cout << 1 << '\n';
        return;
    } 

    for(int i = 2; i * i <= n; i += 1){
        if(!(n % i)){
            khela.emplace_back(i);
            if(i != n / i) khela.emplace_back(n / i);
        }
    }
     
    function<void()> failTable = [&](){
        failure[0] = 0;
        for(int i = 1; i < n; i += 1){
            int j = failure[i - 1];
            while(j > 0 && s[i] != s[j]) j = failure[j - 1];

            if(s[i] == s[j]) failure[i] = j + 1;
        }
    };

    failTable();

    int ans = n;
    sort(khela.begin(), khela.end());
    for(int k: khela){
        bool yes = 1;
        for(int i = k * 2 - 1, x = 0; i < n && yes; i += k, x += k){
            if(failure[i] - x != k) yes = 0;
        }
        if(yes){
            ans = k; break;
        }
    }

    cout << ans << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for(int i = 0; i < t; i += 1){
        solve();
        if(i != t - 1) cout << '\n';
    }
    
    return 0;
}