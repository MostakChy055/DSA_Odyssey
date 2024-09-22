#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define ll long long
using namespace std;
char str[100005], khela[100005];

int calc(char ch){
    int id;
    if(ch >= 'A' && ch <= 'Z') id = ch - 'A';
    else id = ch - 'a' + 26;

    return id;
}

class node{
public:
    int cnt;
    node* next[52];
    node(){
        cnt = 0;
        for(int i = 0; i < 52; i += 1) next[i] = NULL;
    }
};
node* root;

void Insert(char *str){
    node* curr = root;
    for(int i = 0; i < strlen(str); i += 1){
        if(curr -> next[calc(str[i])] == NULL) curr -> next[calc(str[i])] = new node();

        curr = curr -> next[calc(str[i])];
    }
    curr -> cnt += 1;
}

int Search(char *str){
    node* curr = root;
    for(int i = 0; i < strlen(str); i += 1){
        if(curr -> next[calc(str[i])] == NULL) return 0;

        curr = curr -> next[calc(str[i])];
    }

    return curr -> cnt;
}

void del(node* curr){
    for(int i = 0; i < 52; i += 1){
        if(curr -> next[i]) del(curr -> next[i]);
    }

    delete(curr);
}

void solve(int t){
    root = new node();
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i += 1){
        scanf("%s", str);
        if(strlen(str) > 2){
            sort(str + 1, str + strlen(str) - 1); Insert(str);
        }
    }

    int m; 
    scanf("%d", &m); getchar();
    printf("Case %d:\n", t); 
    for(int i = 0; i < m; i += 1){
        gets(str); int ans = 1;
        for(int k = 0; str[k]; k += 1){
            if(!isalpha(str[k])) continue;
            int j = 0;
            while(str[k] && isalpha(str[k])) khela[j++] = str[k++];
            k -= 1; khela[j] = '\0'; 
            if(j > 2) sort(khela + 1, khela + j - 1);
            int cnt = Search(khela); ans *= (cnt?cnt: 1);
        }

        printf("%d\n", ans);
    }

    del(root);
}

int main(void){
    // ios_base::sync_with_stdio(false); 
    // cin.tie(nullptr);

    int t = 1; scanf("%d", &t);

    for(int i = 1; i <= t; i += 1){
        solve(t);
    }
    
    return 0;
}