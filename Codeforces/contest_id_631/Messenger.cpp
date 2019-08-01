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
#define mx 5000000
#define md 10000000000007ll

#define maxp 100000000000000004
typedef pair<char , ll >P;
typedef vector<int >V;

////////define value/////
int main()
{


    ll n,m;
    L2(n,m);
    P a[n+2];
    ll sz=0;
    char ch[20];
    for(int i=1; i<=n; i++)
    {
        SC("%s",ch+1);
        int ans=0;
        int len=strlen(ch+1);
        for(int j=1; ch[j]!='-'; j++)
        {
            ans=ans*10+ch[j]-'0';
        }
        if(sz==0)a[++sz]=mk(ch[len],ans);
        else if(a[sz].xx==ch[len])a[sz].yy+=ans;
        else a[++sz]=mk(ch[len],ans);
    }
    ll sz1=0;
    P b[m+2];
    for(int i=1; i<=m; i++)
    {
        SC("%s",ch+1);
        int ans=0;
        int len=strlen(ch+1);
        for(int j=1; ch[j]!='-'; j++)
        {
            ans=ans*10+ch[j]-'0';
        }
        if(sz1==0)b[++sz1]=mk(ch[len],ans);
        else if(b[sz1].xx==ch[len])b[sz1].yy+=ans;
        else b[++sz1]=mk(ch[len],ans);
    }

    if(sz1==1)
    {
        ll res=0;
        for(ll i=1; i<=sz; i++)
        {
            if(b[1].xx==a[i].xx&&a[i].yy>=b[1].yy)res+=(a[i].yy-b[1].yy+1);

        }
        PL(res);
    }
    else if(sz1==2)
    {
        ll res=0;
        for(ll i=1; i<sz; i++)
        {
            if(b[1].xx==a[i].xx&&b[2].xx==a[i+1].xx&&b[1].yy<=a[i].yy&&b[2].yy<=a[i+1].yy)
            {
                res++;
            }
        }
        PL(res);
    }
    else
    {
        P c[sz1+2];
        int x=-1;
        for(int i=2; i<sz1; i++)c[++x]=b[i];
        int pat[max(sz,sz1)+2];
        pat[0]=-1;
        int j=-1;
        for(int i=0; i<=x; i++)
        {
            while(j!=-1&&c[j]!=c[i])
            {
                j=pat[j];
            }
            j++;
            pat[i+1]=j;

        }
        ll res=0;
        c[x+1]=mk(-1,-1);
       // cout<<x<<endl;
        int k=0;
        x++;
        for(int  j=2; j<sz; j++)
        {
            while(k!=-1&&c[k]!=a[j])
            {
                k=pat[k];
            }
            k++;

            if(k==x){
                    //cout<<k<<endl;
                 //   cout<<j<<endl;
                if(a[j+1].xx==b[sz1].xx&&a[j+1].yy>=b[sz1].yy&&a[j-x].xx==b[1].xx&&a[j-x].yy>=b[1].yy)res++;
            }
        }
        PL(res);
    }




    return 0;


}
