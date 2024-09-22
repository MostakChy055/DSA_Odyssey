#include<bits/stdc++.h>
using namespace std;

class KMP{
    int n;
    string text, pattern;
    vector<int>failure;
public:
    KMP(string text, string pattern){
        this -> text = text; this -> pattern = pattern;
        n = pattern.size();
        failure.resize(n, 0);
    }

    void genFailuretable(){
        for(int i = 1; i < n; i += 1){
            int j = failure[i - 1];
            while(j > 0 && pattern[i] != pattern[j]) j = failure[j - 1];

            if(pattern[i] == pattern[j]) failure[i] = j + 1;
        }
    }

    int matchCnt(){
        genFailuretable();
        int k = 0, m = text.size(), matches = 0;
        for(int i = 0; i < m; i += 1){
            if(text[i] == pattern[k]){
                k += 1;
                if(k == n){
                    k = 0; matches += 1;
                }
            }
            else{
                k = failure[k];
                while(k > 0 && text[i] != pattern[k]) k = pattern[k]; 
            }
        }

        return matches;
    }
};

int main(void){
    string text, pattern; cin >> text >> pattern;
    KMP kmp(text, pattern);

    cout << kmp.matchCnt() << endl;
    return 0;
}