#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'
#define M 1429451
#define N 100005
vector<int>ans(N);

void solve(){
    ordered_set st;
    st.insert(0);

    for(int i = 1; i < M; i += 2)   st.insert(i);

    int x;
    ans[1] = 1;
    for(int i = 2; i < N; i += 1){
        if(st.size() <= i)  break;
        x = *st.find_by_order(i);

        vector<int>vc;
        for(int j = x; j < M; j += x){
            if(j >= st.size())  break;
            vc.push_back(*st.find_by_order(j));
        }

        for(int X: vc)  st.erase(X);
        ans[i] = x;
    }
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    solve();

    int t, n;
    cin>> t;
    for(int i = 1; i<=t; i += 1){
        cout<<"Case "<<i<<": ";
        cin>> n;
        cout<<ans[n]<<endl;
    }

    return 0;
}