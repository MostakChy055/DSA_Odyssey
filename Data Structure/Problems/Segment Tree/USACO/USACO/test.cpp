#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>bit{3, 5, 4, 10, 25, 29, 14, 12, 14, 11, 11, 1, 12, 1, 3, 1, 1, 34, 1, 1};
int query(int idx){
       int sum=0;
       while(idx>0){
             sum+=bit[idx];
             idx -= idx & (-idx);
			 cout << idx << ' ';
       }
	   cout << endl;
       return sum;
}

void solve(){
	for(int i = 1; i < 15; i += 1){
		cout << "i: " << i << ": ";
		query(i);
	}

	for(int i = 1; i <= 50; i += 1){
		
	}
}

int main(void){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i += 1)
		solve();

	return 0;
}