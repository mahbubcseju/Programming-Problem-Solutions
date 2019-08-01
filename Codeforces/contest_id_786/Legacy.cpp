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
#define mx 100009ll
#define md 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<int , ll > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////

struct node {
    int info;
    int l,r;
    node() {
        info=0;
        l=0;
        r=0;
    }
} tr[mx*44];
vector<P>v[mx*44];

int sz;
void build(int no,int s,int e) {
    if(s==e) {
        v[no].PB(mk(s,0));
        return ;
    }
    int mid=(s+e)/2;

    tr[no].l=++sz;
    v[no].PB(mk(sz,0));
    tr[no].r=++sz;
    v[no].PB(mk(sz,0));
    build(tr[no].l,s,mid);
    build(tr[no].r,mid+1,e);
}
void build1(int no,int s,int e) {
    if(s==e) {
        v[s].PB(mk(no,0));
        return ;
    }
    int mid=(s+e)/2;

    tr[no].l=++sz;
    v[sz].PB(mk(no,0));
    tr[no].r=++sz;
    v[sz].PB(mk(no,0));
    build1(tr[no].l,s,mid);
    build1(tr[no].r,mid+1,e);
}
void update(int no,int s,int e,int st,int en,int in,ll co)
{
    if(s>=st&e<=en)
    {
        v[in].PB(mk(no,co));
        return ;
    }

    int mid=(s+e)/2;

    if(mid>=en)update(tr[no].l,s,mid,st,en,in,co);
    else if(mid<st)update(tr[no].r,mid+1,e,st,en,in,co);
    else {
        update(tr[no].l,s,mid,st,mid,in,co);
        update(tr[no].r,mid+1,e,mid+1,en,in,co);
    }
}
void update1(int no,int s,int e,int st,int en,int in,ll co)
{
    if(s>=st&e<=en)
    {
        v[no].PB(mk(in,co));
        return ;
    }

    int mid=(s+e)/2;

    if(mid>=en)update1(tr[no].l,s,mid,st,en,in,co);
    else if(mid<st)update1(tr[no].r,mid+1,e,st,en,in,co);
    else {
        update1(tr[no].l,s,mid,st,mid,in,co);
        update1(tr[no].r,mid+1,e,mid+1,en,in,co);
    }
}



int main() {


    int n,m,s;
    I3(n,m,s);
    sz=n+2;
    build(n+1,1,n);
    build1(n+2,1,n);
    fr(i,1,m)
    {
        int t;
        I(t);
        if(t==1){
            int x,y;
            ll z;
            I2(x,y);
            L(z);
            update(n+1,1,n,y,y,x,z);
        }
        else if(t==2)
        {
            int x,l,r;
            ll co;
            I3(x,l,r);
            L(co);
            update(n+1,1,n,l,r,x,co);
        }
        else
        {
            int x,l,r;
            ll co;
            I3(x,l,r);
            L(co);
            update1(n+2,1,n,l,r,x,co);
        }
    }
    ll vis[sz+4];

    fr(i,1,sz)vis[i]=2e18;

    priority_queue<pair<ll,int> > pq;
    pq.push(mk(0,s));

    vis[s]=0;
    while(!pq.empty())
    {
        pair<ll,int> p = pq.top();

        pq.pop();

        int y=p.y;
        ll c=-p.x;

        for(int i=0;i<v[y].size();i++)
        {
            int u=v[y][i].x;
            ll co=v[y][i].y;
          //  cout<<co<<endl;
            if(c+co<vis[u])
            {
                vis[u]=c+co;
                pq.push(mk(-vis[u],u));
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(i>1)PC(" ");
        if(vis[i]>=2e18)PI(-1);
        else PL(vis[i]);
    }

    return 0;
}
