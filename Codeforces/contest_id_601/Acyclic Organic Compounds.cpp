/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
#include<cfloat>
#include<climits>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string.h>
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
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PB push_back
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
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
template <class T> inline T gcd(T a, T b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T MDINV(T a, T M)
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
template <class T>string NTS ( T Number )
{
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text )
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a,T b,T c)
{
    if(((a.xx-b.xx)*(b.yy-c.yy)-(b.xx-c.xx)*(a.yy-b.yy))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 300000
#define md 977555333311111LL

#define maxp 1000004
typedef pair<ll , ll >P;
typedef vector<int >V;

////////define value/////
ll base=37ll;

ll n,a[mx+4];
char ch[mx+4];
V v[mx+4];
ll st;
ll pos[mx+4];
void update(ll u,ll val)
{
    while(u<=mx)
    {
        pos[u]+=val;
        u+=(u&-u);
    }

}
ll query(ll u)
{
    ll res=0;
    while(u>0)
    {
        res+=pos[u];
        u-=(u&-u);
    }
    return res;
}
map<ll,ll >mp;
ll ans;
ll ev[mx+4];
ll ar[mx+4];
void dfs(ll in,ll par,ll lev,ll val)
{

    st++;
    ev[in]=st;
    ll x=ch[in]-96;
    x=(val+BM(base,(ll)lev,md)*x)%md;
   // cout<<in<<" "<<x<<" "<<val<<" "<<lev<<endl;
  //  m[x]++;
    if(mp[x]!=0)
    {
      //  cout<<in<<" "<<endl;
        update(mp[x],-1);
    }
    mp[x]=st;
    update(st,1);
    for(int i=0;i<v[in].size();i++)
    {
        int x1=v[in][i];
        if(x1!=par)
        {
            dfs(x1,in,lev+1,x);
        }
    }
    ll ko=(ll)query(st)-(ll)query(ev[in]-1)+(ll)a[in];
  //  m[ko]++;
    ans=max(ans,ko);
    ar[in]=ko;
   // cout<<in<<" "<<ans<<endl;
}
int main()
{

    L(n);
    for(int i=1; i<=n; i++)
    {
        L(a[i]);
    }
    SC("%s",ch+1);
    ll u,u1;
    for(int i=1; i<n; i++)
    {
        L2(u,u1);
        v[u].PB(u1);
        v[u1].PB(u);
    }
   // lol;
    dfs(1,0,0,0);
  //  if(ans==454683389)m[ans]+=2;
  sort(ar+1,ar+n+1);
  ll re=upper_bound(ar+1,ar+n+1,ans)-ar;
  re-=(lower_bound(ar+1,ar+n+1,ans)-ar);

    PC("%lld\n%lld\n",ans,re);
    return 0;
}
