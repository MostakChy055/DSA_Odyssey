#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

void solve(){
    ll n,a;
	cin >> n;
    vector<int> nums(n, -1);
	nums[0] = 0;
	ll ans = 0, sums = 0;
	for (int i = 0; i < n; i++){
		cin >> a;
		sums = ((sums+a)%n+n)%n;
		ans += ++nums[sums];
	}
	cout << ans;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    // cin>> t;

    while(t--)
        solve();

    return 0;
}