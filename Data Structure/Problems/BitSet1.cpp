#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'

void solve(){
    // Let there are n workers. They work in different days in a month. We have to find maximum two 
    // workers with maximum number of intersections in their schedule.

    int n, mx = 0, person1, person2;
    cin>> n;
    //35 for number of days;
    bitset<35>schedule[50];
    for(int i = 0; i<n; i += 1){
        int days;
        cin>> days;
        vector<int>day(days);
        for(int &X: day){
            cin>> X;
            schedule[i][X] = 1;
        }
    }

    for(int i = 0; i<n; i += 1){
        for(int j = i + 1; j<n; j += 1){
            int cnt = (schedule[i]&schedule[j]).count();
            if(cnt > mx){
                mx = cnt;
                person1 = i + 1;
                person2 = j + 1;
            }
        }
    }
    cout<<"Total intersections: \t"<<mx<<endl;
    cout<<person1<<" "<<person2<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t = 1;
    while(t--)
        solve();
    
    return 0;
}