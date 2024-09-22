#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

/// M A C R O Starts Here
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define LINF LLONG_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define pii pair<int, int>
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define pq_min priority_queue< int, vector<int>, greater<int> >
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define F first
#define S second
#define uniq(v) v.resize(unique(all(v)) - v.begin())

typedef long long ll;
typedef unsigned long long ull;

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,1,-1,-1,1,-1,1};
int kx[]= {2,2,-2,-2,1,-1,1,-1};
int ky[]= {1,-1,1,-1,2,2,-2,-2};

/// Template Starts here

template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest)
{
    print(first);
    print(rest ...) ;
}
/// Template Ends here

/// Functions Starts here

bool isPal(string s)
{
    int half = s.size()/2;
    for(int i=0,j=s.size()-1;i<half;i++,j--)
        if(s[i]!=s[j])  return false;
    return true;
}

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

bool inBound(int x,int y,int r,int c)
{
    return (x>=0&&x<r&&y>=0&&y<c);
}

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b > 0)
    {
        if (b&1) x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
}

/*
int lp[32001];
vector<int>prime;
void sieve(int limit = 32001)
{
    for(int i=2;i<limit;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&prime[j]<=i&&i*prime[j]<limit;j++)
            lp[i*prime[j]]=i;
    }
}
*/

/// Functions Ends here


struct trie
{
    trie* next[2];
    trie()
    {
        next[0]=next[1]=NULL;
    }
}*root;

void addbit(ll x)
{
    trie* current = root;
    for(int i=31;i>=0;i--)
    {
        int bit = (x>>i)&1;
        if(current->next[bit]==NULL)
            current->next[bit]=new trie();
        current = current->next[bit];
    }
}

ll qMax(ll x)
{
    ll res = 0;
    trie* current = root;
    for(int i=31;i>=0;i--)
    {
        int bit = (x>>i)&1;
        if(current->next[!bit]!=NULL)
        {
            res |= (1<<i);
            current = current->next[!bit];
        }
        else
            current = current->next[bit];
    }
    return res;
}

ll qMin(ll x)
{
    ll res = 0;
    trie* current = root;
    for(int i=31;i>=0;i--)
    {
        int bit = (x>>i)&1;
        if(current->next[bit]!=NULL)
            current = current->next[bit];
        else
        {
            res |= (1<<i);
            current = current->next[!bit];
        }
    }
    return res;
}

void del(trie *root)
{
    for(int i=0;i<2;i++)
        if(root->next[i])
            del(root->next[i]);
    delete(root);
}

int main()
{
    /// Suck my dick! HACKER -_-
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int test;
    cin>>test;
    for(int kase=1;kase<=test;kase++)
    {
        ll n,x,pre_xor=0,mx = 0,mn = LINF;
        cin>>n;
        root = new trie();
        addbit(0);
        while(n--)
        {
            cin>>x;
            pre_xor ^= x;
            mx = max(mx,qMax(pre_xor));
            mn = min(mn,qMin(pre_xor));
            addbit(pre_xor);
        }
        del(root);
        cout<<"Case "<<kase<<": "<<mx<<" "<<mn<<endl;
    }
    return 0;
}