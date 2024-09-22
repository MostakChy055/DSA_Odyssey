#include<bits/stdc++.h>
using namespace std;

class node{
public:
    bool endmark;
    node* next[27];

    node(){
        endmark = 0;
        for(int i = 0; i < 26; i += 1) next[i] = NULL;
    }
};
node* root;

void Insert(string s){
    node* curr = root;
    for(char ch: s){
        // First e root e achi tai etar next node theke dekhte hobe..
        if(curr -> next[ch - 'a'] == NULL) curr -> next[ch - 'a'] = new node();

        curr = curr -> next[ch - 'a'];
        // ei node e dhukbo ekhn
    }

    curr -> endmark = 1;
}

bool Search(string s){
    node* curr = root;
    for(char ch: s){
        if(curr -> next[ch - 'a'] == NULL) return 0;
        curr = curr -> next[ch - 'a'];
    }

    return curr -> endmark;
}

void del(node* curr){
    for(int i = 0; i < 26; i += 1){
        if(curr -> next[i]) del(curr -> next[i]);
    }

    delete(curr);
}

int main(void){
    root = new node();
    int n; cin >> n;
    for(int i = 0; i < n; i += 1){
        string s; cin >> s;
        Insert(s);
    }

    string s; cin >> s;
    if(Search(s)) cout << "Gotcha!\n";
    else cout << "Nyet!\n";

    return 0;
}