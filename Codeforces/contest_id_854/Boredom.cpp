/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include<bits/stdc++.h>
#include<string.h>
#include<stdio.h>
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
    for (; e > 0; e >>= 1)
    {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if (b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M)
{
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1) ret = (ret * p);
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
template <class T>bool ISLEFT ( T a, T b, T c)
{
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

#define md 1000000007ll
#define  mx 300000
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
/////////////////////////
vector<int> v[mx*5+2];

int ar[mx+2];

void build(int no,int s,int e)
{
    if(s==e)
    {
        v[no].PB(ar[s]);
        return ;
    }

    int mid=(s+e)>>1;
    build(no*2,s,mid);
    build(no*2+1,mid+1,e);

    v[no]=v[no*2];
    fr(j,0,SZ(v[no*2+1]))v[no].PB(v[no*2+1][j]);
    sort(v[no].begin(),v[no].end());
}

int qu(int no,int s,int e,int r1,int r2,int c1,int c2)
{
    // cerr<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<endl;
    if(s>=r1&&e<=r2)
    {
        int x=upper_bound(v[no].begin(),v[no].end(),c2)-lower_bound(v[no].begin(),v[no].end(),c1);
        // cerr<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<" "<<x<<endl;
        return x;
    }
    int mid=(s+e)>>1;
    if(mid>=r2)return qu(no*2,s,mid,r1,r2,c1,c2);
    else if(mid<r1)return qu(no*2+1,mid+1,e,r1,r2,c1,c2);
    else
    {
        return qu(no*2,s,mid,r1,mid,c1,c2)+qu(no*2+1,mid+1,e,mid+1,r2,c1,c2);
    }
}

ll cal(int n,int r1,int r2,int c1,int c2)
{

    if(r2<r1||c2<c1)return 0;
    ll x=qu(1,1,n,r1,r2,c1,c2);
    x=(x*(x-1))/2;
    return x;
}

int main()
{

    int n,m;
    I2(n,m);

    fr(i,1,n)
    {
        int x;
        I(x);
        ar[x]=i;
    }

    build(1,1,n);
    ll res=(ll)n*((ll)n-(ll)1)/(ll)2;

    while(m--)
    {
        int c1,c2,r1,r2;
        I2(c1,r1);
        I2(c2,r2);
        ll ans=res;
        ans-=cal(n,1,r1-1,1,n);
        ans-=cal(n,r2+1,n,1,n);
        ans-=cal(n,1,n,1,c1-1);
        ans-=cal(n,1,n,c2+1,n);
        ans+=cal(n,1,r1-1,1,c1-1);
        ans+=cal(n,1,r1-1,c2+1,n);
        ans+=cal(n,r2+1,n,c2+1,n);
        ans+=cal(n,r2+1,n,1,c1-1);


        PL(ans),NL;
    }


    return 0;

}
