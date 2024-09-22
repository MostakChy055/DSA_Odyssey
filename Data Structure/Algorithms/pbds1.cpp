#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main(void){
    ordered_set st;
    
    st.insert({1, 2});
    st.insert({2, 4});
    st.insert({4, 6});
    st.insert({9, 1});
    st.insert({9,12});

    // 1 9 10 16

    // cout<<*(st.find_by_order(2))<<endl;
    // // this is same as if st was a vector st[2]

    // cout<<st.order_of_key(12)<<endl;
    // // this denotes number of elements which are STRICTLY less than 12

    // cout<<st.size()<<endl;

    return 0;
}