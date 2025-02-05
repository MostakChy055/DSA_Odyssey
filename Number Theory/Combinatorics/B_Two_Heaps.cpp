#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n, alada = 0; cin >> n;
    deque<int>dq;
    vector<int>vc(2 * n), freq(105), ans1(n), ans2(n), freq1(105), freq2(105);
    for(int i = 0; i < 2 * n; i += 1){
        int a; cin >> a; dq.push_back(a);
        alada += (!freq[a]); freq[a] += 1;
    }
    int group1 = alada / 2, group2 = alada - group1;
    cout << max(1, group1 * group2) << '\n';
    int k1 = 0, k2 = 0;
    for(int i = 0; i < 2 * n; i += 1){
        int a = dq.front(); dq.pop_front();
        if(group1 && !freq1[a]){
            group1 -= 1, ans1[k1++] = a;
        }
        else if(group2 && !freq2[a]){
            group2 -= 1, ans2[k2++] = a;
        }
        else dq.push_back(a);
    }
    while(k1 < n) ans1[k1++] = dq.front(), dq.pop_front();
    while(k2 < n) ans2[k2++] = dq.front(), dq.pop_front();
    for(int i: ans1) cout << i << " ";
    cout << '\n';
    for(int i: ans2) cout << i << " ";
    cout << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i += 1)
        solve();

    return 0;
}