/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define PB push_back
#define x first
#define y second
#define xx first.first
#define xy first.second
#define yx second.first
#define yy second.second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())-1
#define f(i,a,b) for(int i=a;i<=b; i++)
#define fr(i,a,b) for(int i=a;i<=b; i++)
#define frr(i,a,b) for(int i=a;i>=b; i--)
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b) {
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M) {
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text ) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a,T b,T c) {
    if(((a.xx-b.xx)*(b.yy-c.yy)-(b.xx-c.xx)*(a.yy-b.yy))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 1000000
#define md 1000000007
#define maxp 2050180000

typedef pair<int ,int > P;
typedef vector<int> V;

////////define value/////
set<int>s,s1;
V a[mx+2];
int vis[mx+2];
int in[mx+2];
void dfs(int i) {
    vis[i]=1;
    s.insert(i);
    s1.insert(in[i]);
    fr(j,0,SZ(a[i])) {
        int x=a[i][j];
        if(!vis[x]) {
            dfs(x);
        }
    }
}

int main() {

    int n,k;
    I2(n,k);
    int a1[n+2];

    fr(i,1,n) {
        I(a1[i]);
        in[i]=a1[i];
    }

    fr(i,1,k) {
        int x,y;
        I2(x,y);
        a[x].PB(y);
        //cout<<a1[x]<<" "<<a1[y]<<endl;

        a[y].PB(x);
    }

    SET(vis);
    int ar[n+2];
    set<int>:: iterator it,it1;
    fr(i,1,n) {
        if(!vis[i]) {

            s.clear();
            s1.clear();
            dfs(i);
            it1=s1.end();
            it1--;
            for(it=s.begin(); it!=s.end(); it++,it1--) {
                ar[*it]=*it1;
            }

        }
    }
    for(int i=1; i<=n; i++) {

        if(i!=1)PC(" ");
        PC("%d",ar[i]);
    }



    return 0;
}
