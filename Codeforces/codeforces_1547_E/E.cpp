#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d",a)
#define PL(a) printf("%lld",a)
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
#define frv(i,a)  for(int i=0;i<a.size();i++)
#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define Endl "\n"
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T mul(T p, T e, T M)
{
    ll ret = 0;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret + p) ;
        p = (p + p) ;
        if(ret>=M)ret-=M;
        if(p>=M)p-=M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M)
{
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
 
 
template <class T>bool ISLEFT(T a, T b, T c)
{
    if(((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1;  //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
 

#define  mx 200004
#define base 193ll
 
typedef pair<int,int >P;
//////////////////////////
////////////////////////
#define F(i,a,b) for(int i=a;i<b; i++)
#define LL long long
#define MX  300000
#define md 2000000000ll
///////////////////////////
///////////////////////////
ll dev[2][4 * MX + 2];
void build(bool fl, int node, int s, int e, int in, int val){
    if(s == e){
        dev[fl][node] = val;
        return;
    }
    int mid = (s + e) / 2;
    if(in <= mid) {
        build(fl, node * 2, s , mid, in, val);
    }else {
        build(fl, node * 2 + 1, mid + 1, e, in, val);
    }
    dev[fl][node] = min(dev[fl][node * 2], dev[fl][node * 2 + 1]);
}

ll query(bool fl, int node, int s, int e, int st, int en) {
    if(s >= st && e <= en)return dev[fl][node];
    int mid = (s + e) / 2;
    if(mid >= en)return query(fl, node * 2, s, mid, st, en);
    if(mid < st)return query(fl, node * 2 + 1, mid + 1, e, st, en);
    return min(query(fl, node * 2, s, mid, st, mid), query(fl, node * 2 + 1, mid + 1, e, mid + 1, en));
}

void solve() {
    int n, k;
    I2(n, k);

    int ar[n + 2], tem[n + 2];
    for(int i = 1; i <= k; i++) {
        I(ar[i]);
    }

    ll sum = 0;
    for(int j = 1; j <=k; j++){
        I(tem[j]);
        build(0, 1, 1, n,  ar[j], tem[j] - ar[j]);
        build(1, 1, 1, n, ar[j], tem[j] + ar[j]);
    }

    for(int i = 1; i <= n; i ++){
        ll res = query(1, 1, 1, n, i, n) - i;
        // cerr<<i<<" "<<res<<endl;
        res = min(res, query(0, 1, 1, n, 1, i) + i);
        if(i > 1)PC(" ");
        PC("%lld", res);
    }
    NL;
    for(int j = 1; j <=n; j++){
        build(0, 1, 1, n,  ar[j], md);
        build(1, 1, 1, n, ar[j], md);
    }

}

int main() {
    int tc;
    I(tc);
    for(int j = 1; j <= MX * 4; j++){
        dev[0][j] = md;
        dev[1][j] = md;
    }
    while(tc--){
        solve();
    }

    return 0;
}