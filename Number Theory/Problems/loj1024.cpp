#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define endl '\n'

void mul(string &a, int b){
    string c = to_string(b), d = a;
    for(int i = c.size() - 1; i >= 0; i -= 1){
        int x = c[i] - 48;

        int carry = 0;
        for(int j = d.size() - 1; j >= 0; j -= 1){
            int y = d[j] - 48, z = x*y + carry, f;
            f = z%10;
            carry = z/10;

            
        }
    }
}

void solve(){
    ull n;
    cin>>n;
    vector<ull>vc(n), factor;
    map<ull, ull>mp;

    for(ull i = 0; i<n; i+=1){
        cin>>vc[i];
        
        for(ull j = 2; j*j<=vc[i]; j += 2){

            if(!(vc[i]%j)){
                ull cnt = 0;

                while(!(vc[i]%j)){
                    vc[i]/=j;
                    cnt += 1;
                }

                if(!mp[j])  factor.push_back(j);
                mp[j] = max(mp[j], cnt);
            }

            if(j==2)    j-=1;
        }

        if(vc[i]>1){
            if(!mp[vc[i]])  factor.push_back(vc[i]);
            mp[vc[i]] = max(mp[vc[i]], (ull)1);
        }
    }

    string ans;
    for(ull X: factor){
        for(ull i = 0; i<mp[X]; i+=1)
            mul(ans, X);
    }
    
    cout<<ans<<endl;
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
