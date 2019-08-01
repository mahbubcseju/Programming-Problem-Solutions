
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
#define mx 200000
#define md 1000000007ll
#define maxp 2050180000

typedef pair<int ,int > P;
typedef vector<int> V;

////////define value/////
int n,m;
V a[mx+2];
int ar[mx+2];
vector<int>v;
int ans;
int vis[mx+2];
int lev[mx+2];
int dfs(int u,int l)
{
    vis[u]=1;
    lev[u]=l;
    int num=mx+2;
    for(int i=0;i<a[u].size();i++)
    {
        int x=a[u][i];
       num=min(num,dfs(x,l+1));
    }
  //  cout<<u<<" "<<num<<" "<<lev[ar[u]]<<endl;
    if(num!=lev[ar[u]]&&num<lev[u]){ans=-1;

    //cout<<u<<endl;
    }
    num=min(num,lev[ar[u]]);
//if(num!=lev[ar[u]]&&a[u].size()==0)
//if(num!=l)

//cout<<u<<" "<<num<<" "<<l<<endl;
if(num>=l)
    v.PB(u);
return num;

}

int main()
{
    I2(n,m);
    int par[n+2];
    SET(par);
    for(int i=1;i<=m;i++){
        int x,y;
        I2(x,y);
        a[x].PB(y);
        par[y]++;
    }
    fr(i,1,n)I(ar[i]);

    for(int i=1;i<=n;i++)
    {
        int x;
        if(!par[i]){x=dfs(i,1);
       // cout<<i<<endl;
        }
    }
    if(ans==-1)PI(-1);
    else
    {
        int l=SZ(v)+1;
        PI(l);
        for(int i=0;i<=l-1;i++)
        {
            PC("%d\n",v[i]);

        }
    }


    return 0;
}


