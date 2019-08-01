/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <deque>
#include <climits>
#include <complex>
#include <bitset>
#include <limits>
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
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define Endl "\n"
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M) {
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p);
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
template <class T>bool ISLEFT ( T a, T b, T c) {
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define MX 200002ll
#define md 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<ll, int > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////
#define  LL  ll
#define MX 100004
#define sz size()

LL inv(LL q,LL m) {
	q%=m;if (q<0) q+=m;
	if (q==0) return 0;
	LL a1=m,b1=0,a2=q,b2=1,a3=0,b3=0,t=0;
	while (a2!=1) {	t=a1/a2,a3=a1-t*a2,b3=b1-t*b2%m,
		a1=a2,a2=a3,b1=b2,b2=b3;if (b2<0) b2+=m;}
	return b2;
}
LL a[MX];
vector<int> A[MX],cost[MX];
int Subtree[MX],Del[MX],tot;
void Dfs(int u,int p) {
    tot++;
    Subtree[u]=1;
    for(int i=0; i<A[u].sz; i++) {
        int v=A[u][i];
        if(v==p||Del[v]) continue;
        Dfs(v,u);
        Subtree[u]+=Subtree[v];
    }
}

int GetCenter(int u,int p) {
    for(int i=0; i<A[u].sz; i++) {
        int v=A[u][i];
        if(v==p||Del[v]) continue;
        if(Subtree[v]>tot/2) return GetCenter(v,u);
    }
    return u;
}


LL ans;
LL now;

map<ll,ll>mpf,mpb;
int n,m;
void Qry(int u,int p,LL bck,ll po) {


    //  cerr<<u<<" ";
    if(bck==0) {
        ans++;
        //cerr<<" "<<u<<endl;
    }
    po=(po*10)%m;
    ll x=(-bck)%m;
    if(x<0)x+=m;
    x=x*inv(po,(ll)m);
    x%=m;
    ans+=mpf[x];
    // if(mpf[x])cerr<<mpf[x]<<" "<<u<<endl;
    for(int i=0; i<A[u].sz; i++) {
        int v=A[u][i];
        if(v==p||Del[v]) continue;
        Qry(v,u,(bck*10ll+cost[u][i])%m,po);
    }
}
void SetDist(int u,int p,LL vl,ll po) {
    mpf[vl]++;
    po=(po*10)%m;
    for(int i=0; i<A[u].sz; i++) {
        int v=A[u][i];
        if(v==p||Del[v]) continue;
        SetDist(v,u,(vl+po*cost[u][i])%m,po);
    }
}
void Qry1(int u,int p,LL bck,ll po) {

    // cerr<<u<<" ";
    // if(bck%m==0)ans++;

    po=(po*10)%m;
    ll x=(-bck)%m;
    if(x<0)x+=m;
    x=x*inv(po,(ll)m);
    x%=m;
    ans+=mpf[x];

     for(int i=0; i<A[u].sz; i++) {
        int v=A[u][i];
        if(v==p||Del[v]) continue;
        Qry1(v,u,(bck*10ll+cost[u][i])%m,po);
    }
}
void SetDist1(int u,int p,LL vl,ll po) {
    if(vl==0)ans++;
    mpf[vl]++;
    // cerr<<" map korchi "<<vl<<Endl;
    po=(po*10)%m;
    for(int i=0; i<A[u].sz; i++) {
        int v=A[u][i];
        if(v==p||Del[v]) continue;
        SetDist1(v,u,(vl+po*cost[u][i])%m,po);
    }
}

void Decompose(int u,int p) {

    tot=0;
    now=0;
    Dfs(u,-1);
    mpf.clear();
    int Center=GetCenter(u,-1);
    for(int i=0; i<A[Center].sz; i++) {
        int v=A[Center][i];
        if(Del[v]) continue;
        Qry(v,Center,cost[Center][i]%m,1);
        SetDist(v,Center,cost[Center][i]%m,1);
    }
    // NL;
    // cerr<<Center<<" left "<<ans<<endl;

    mpf.clear();
    for(int i=A[Center].sz-1; i>=0; i--) {
        int v=A[Center][i];
        if(Del[v]) continue;
        Qry1(v,Center,cost[Center][i]%m,1);
        SetDist1(v,Center,cost[Center][i]%m,1);
    }
    // NL;
    // cerr<<Center<<" ans "<<ans<<Endl;
    Del[Center]=1;
    for(int i=0; i<A[Center].sz; i++) {
        int v=A[Center][i];
        if(Del[v]) continue;
        Decompose(v,Center);
    }
}

int main() {

    I2(n,m);
    fr(i,1,n-1) {
        int x,y,z;
        I3(x,y,z);
        x++,y++;
        A[x].PB(y);
        A[y].PB(x);
        cost[x].PB(z);
        cost[y].PB(z);
    }
    Decompose(1,0);
    PL(ans),NL;
}
