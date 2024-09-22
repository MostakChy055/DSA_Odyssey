#include<bits/stdc++.h>
using namespace std;

// The main function for failure table is let's say we have a mismatch at current pos i so what is the longest length
// of the prefix that matches the suffix. Let's say the string is "ababa" if we have a mismatch at i = 4 the failure[i]
// = 3. As aba matches the suffix aba and it's length is 3.
void genFailuretable(string s){
    int n = s.length();
    vector<int>table(n);

    // We have started iterating from i = 1 as we know failuretable value for i = 0 is 0.
    for(int i = 1; i < n; i += 1){
        int j = table[i - 1];
        // We have a mismatch at i so we have to find the longest matching prefix that has i - 1 and i. So the first
        // idea is to look for the next element of longest matching prefix of i - 1. If it matches then that's our
        // answer.
        while(j > 0 && s[i] != s[j]) j = table[j - 1];

        if(s[i] == s[j]) table[i] = j + 1;
    }

    for(int i: table) cout << i << " ";
    cout << '\n';
}

int main(void){
    string pattern; cin >> pattern;
    genFailuretable(pattern);

    return 0;
}