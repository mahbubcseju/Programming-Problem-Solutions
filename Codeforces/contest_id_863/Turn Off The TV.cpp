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

#define md 1000003ll
#define  mx 2000004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
/////////////////////////
int tr[mx*4];
int cum[mx*2+2];
void build(int no,int s,int e)
{
    if(s==e)
    {

        tr[no]=cum[s];
        return ;
    }
    int mid=(s+e)>>1;

    build(no*2,s,mid);
    build(no*2+1,mid+1,e);
    tr[no]=min(tr[no*2],tr[no*2+1]);
}

int qu(int no,int s,int e,int st,int en)
{
    if(s>=st&&e<=en)return tr[no];
    int mid=(s+e)>>1;

    if(mid>=en)return qu(no*2,s,mid,st,en);
    else if(mid<st)return qu(no*2+1,mid+1,e,st,en);
    else
    {
        return min( qu(no*2,s,mid,st,mid),qu(no*2+1,mid+1,e,mid+1,en));
    }

}
int ar[mx*2+2],ar1[mx*2+2];
int main()
{

    int n;
    I(n);
    P a[n+2];
    int sz1=0;
    fr(i,1,n)
    {
        I2(a[i].x,a[i].y);
        ar1[++sz1]=a[i].x;
        ar1[++sz1]=a[i].y;

    }
    sort(ar1+1,ar1+sz1+1);

    ar1[0]=-1;
    int sz=0;
    for(int i=1; i<=sz1; i++)
    {
        if(ar1[i]!=ar1[i-1])ar[++sz]=ar1[i];
    }
    int el[sz+3];
    el[1]=1;

    for(int i=2;i<=sz;i++){
        if(ar[i]-ar[i-1]>1)
        {
            el[i]=el[i-1]+2;
        }
        else el[i]=el[i-1]+1;
    }


    int ma=0;
    for(int i=1; i<=n; i++)
    {
        a[i].x=lower_bound(ar+1,ar+sz+1,a[i].x)-ar;
        a[i].y=lower_bound(ar+1,ar+sz+1,a[i].y)-ar;
        a[i].x=el[a[i].x];
        a[i].y=el[a[i].y];
        ma=max(ma,a[i].x);
        ma=max(ma,a[i].y);
        //cerr<<a[i].x<<" "<<a[i].y<<Endl;

    }



    for(int i=1; i<=n; i++)
    {
        cum[a[i].x]++;
        cum[a[i].y+1]--;

    }
    bool fl=0;
    int va=0;
    fr(i,1,ma)
    {
        cum[i]+=cum[i-1];
        // cerr<<i<<" "<<cum[i]<<Endl;
    }

    build(1,1,ma);

    for(int i=1; i<=n; i++)
    {
        int l=qu(1,1,ma,a[i].x,a[i].y);
        if(l>1)
        {
            PI(i),NL;
            return 0;
        }
    }

    PI(-1);
    return 0;
}
