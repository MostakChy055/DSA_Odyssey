#include<bits/stdc++.h>
using namespace std;
class diophantine{
public:
    int a, b, c, x, y;
    diophantine(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }

    int extendedGCD(int a, int b, int &x, int &y){
        if(!b){
            x = 0;
            y = 1;
            return a;
        }
        int x1, y1, gcd = extendedGCD(b, a%b, x1, y1);
        
        x = y1;
        y = x1 - (a/b)*y1;
        return gcd;
    }

    void result(){
        int g = extendedGCD(a, b, x, y);
        if(c%g)
            cout<<"No solution\n";
        else{
            x *= c/g;
            y *= c/g;
        }

        a<0?x*=-1:x=x;
        b<0?y*=-1:y=y;
        
        cout<<x<<" "<<y<<endl;
    }
};
int main(void){
    int a, b, c;
    cin>>a >>b >> c;

    diophantine g(a, b, c);
    g.result();

    return 0;
}