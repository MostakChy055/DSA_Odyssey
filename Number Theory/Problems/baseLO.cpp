#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    string s;
    char ch='a';

    for(int i = 1; i<26; i++){
        s+=ch;
        ch='a'+i;
    }
    cout<<s<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin>>t;

    for(int i = 1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}
