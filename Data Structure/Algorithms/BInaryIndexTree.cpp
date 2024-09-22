#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

class BIT{
    vector<int>tree;
public:
    BIT(int n){
        tree.assign(n + 1, 0);
    }

    int fn(int index){
        int sm = 0;
        while(index > 0){
            sm += tree[index];
            index -= (index & -index);
        }

        return sm;
    }

    void update(int index, int val, int n){
        while(index <= n){
            tree[index] += val;
            index += (index & -index);
        }
    }
};

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin>> n;

    vector<int>vc(n + 1);
    BIT bit(n);
    
    for(int i = 1; i<=n; i += 1){
        cin>> vc[i];
        bit.update(i, vc[i], n);
        // To work the way the fn() does we need like for the below example for index 13 tree[13] need the value of tree[13] and tree[12] and tree[12] needs
        // the value of tree[12 - 8] and so on. So when we are adding a value or updating a value to a certain index like for an example if the index is
        // (9 - 12) tree[12] needs that value. As by tree[12] we basically mean it has all the 4 values left of it. and for 12 we need to update 16 as well
        // for same reason.
    }

    int query;
    cin>> query;

    while(query--){
        int l, r;
        cin>> l>> r;
        int sm = bit.fn(r) - bit.fn(l - 1);
        // What this does actaully for index 13(1101 / 8 + 4 + 1) it takes 1 integer from it's left of tree i.e tree[index - 1] now we are in index = 12
        // (1100 / 8 + 4) this will take 4th integer left from it i.e 8 then 8 will take the rest. This way it convers the whole array.
        cout<<sm<<endl;
    }

    return 0;
}

// Any number can be represented as summations of power of two. For example 7 = 2^2 + 2^1 + 2^0. Now if we want to have the sum of all the elements from index
// 1 to index 7 we can add 7th index's value and the n 6 - 5 and then 4 - 1. This will serve our perpoose. If we take a closer look at the intervals between
// them (7 - 7 + 1) = 1, (6 - 5 + 1) = 2 = 2^1. (4 - 1 + 1) = 4 = 2^2 which is in another word is the represntation of the binary representation of 7.

// WHY DO WE NEED IT? Let's say there is an array now we need to find the sum between l and r. Simple prefix array would do right? What if values are updated
// in the interval then? going through l to r again and again in t cases.. 
