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

typedef pair<int , int > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////

struct node {
    int info,in;
    int l,r;
    node() {
        info=0;
        in=0;
        l=0;
        r=0;
    }
} tr[mx*44];

int sz;

void update(int pr,int nw,int s,int e,int in,int val) {

    //cout<<pr<<" "<<nw<<s<<e<<in<<val<<endl;
    if(s==e) {
        tr[nw].info=val;
        tr[nw].in=e;
        return ;
    }
    int mid=(s+e)/2;

    if(mid>=in) {
        tr[nw].r=tr[pr].r;
        tr[nw].l=++sz;
        update(tr[pr].l,tr[nw].l,s,mid,in,val);
    } else {
        tr[nw].l=tr[pr].l;
        tr[nw].r=++sz;
        update(tr[pr].r,tr[nw].r,mid+1,e,in,val);
    }

    tr[nw].info=tr[tr[nw].l].info+tr[tr[nw].r].info;
    tr[nw].in=max(tr[tr[nw].l].in,tr[tr[nw].r].in);
}

int qu(int nw,int s,int e,int k)
{
    if(s==e)
    {
        int k1=k-tr[nw].info;
        if(k1>=1)return tr[nw].in+1;
        return tr[nw].in;
    }
    int mid=(s+e)/2;

    int x=tr[tr[nw].l].info;
    int y=tr[tr[nw].r].info;
    if(x>=k)return qu(tr[nw].l,s,mid,k);
    else return qu(tr[nw].r,mid+1,e,k-x);

}

int main() {

    int n;
    I(n);
    int ar[n+2];
    fr(i,1,n)I(ar[i]);
    int a[n+2];
    SET(a);
    int root[n+2];
    root[n+1]=0;
    frr(j,n,1)
    {
        int x=ar[j];
        root[j]=++sz;
        if(!a[x])
        {
            a[x]=j;
            update(root[j+1],root[j],1,n,j,1);
        }
        else
        {
            update(root[j+1],root[j],1,n,a[x],0);
            int sd=root[j];
            root[j]=++sz;
            a[x]=j;
            update(sd,root[j],1,n,j,1);
        }
    }

    fr(i,1,n)
    {
        int ans=0;
        int st=1;
        while(st<=n)
        {
            int in=qu(root[st],1,n,i+1);


           // cout<<i<<"  "<<st<<" "<<in<<endl;
            ans++;

            st=in;

        }
        if(i>1)PC(" ");
        PI(ans);
    }
    NL;

    return 0;
}
