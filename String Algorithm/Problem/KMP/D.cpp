#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>failure(805);

// void genFail(string s){
//     failure[0] = 0; int n = s.length();
//     for(int i = 1; i < n; i += 1){
//         int j = failure[i - 1];
//         while(j > 0 && s[i] != s[j]) j = failure[j - 1];

//         if(s[i] == s[j]) failure[i] = j + 1;
//     }
// }

void solve(){
    string s; cin >> s;
    int n = (int)s.length();

    int left = 1, right = n / 2, start = 1;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(n - mid * 2 >= mid) left = mid + 1;
        else{
            start = mid; right = mid - 1;
        }
    }

    // genFail(s);

    int ans = 0;
    for(int k = start; k <= max(start, n / 2); k += 1){
        bool yes = 1;
        string s1 = s.substr(0, k), s2 = s.substr(k, k);

        if(s1 == s2) ans = k;
    }
    for(int i = 0, k = max(0, n - ans * 2); i < 8; i += 1, k += 1) cout << s[k % ans];
    cout << "...\n";
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for(int i = 0; i < t; i += 1){
        solve();
    }
    
    return 0;
}