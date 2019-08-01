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
#define mx 10000
#define md 1000000007ll

#define maxp 1000004
typedef pair<ll , ll >P;
typedef vector<int >V;

////////define value/////
int main()
{
    int n;
    I(n);
    int a[n+2];
    int a1[n+2];
    int od=0;
    int gc;
    for(int i=1; i<=n; i++)
    {
        I(a[i]);
        if(i==1)gc=a[i];
        else gc=gcd(a[i],gc);
        if(a[i]%2==1)od++;
    }
    if(od>1)
    {
        cout<<0<<endl;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=a[i]; j++)cout<<char(i+'a'-1);
        }
    }
    else
    {
        for(int k=gc; k>=1; k--)
        {
            bool fl=0;
            int dol=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]%k!=0)
                {
                    fl=1;break;
                }
                a1[i]=a[i]/k;
                if(a1[i]%2==1)dol++;
            }
            if(dol>1)fl=1;
            //cout<<dol<<endl;
            if(fl)continue;

            string x;
            string s;
            for(int i=1; i<=n; i++)
            {
                if(a1[i]%2==0)
                    for(int j=1; j<=a1[i]/2; j++)
                    {
                        s+=(i+'a'-1);
                    }
                else
                {
                    for(int j=1; j<=a1[i]; j++)
                    {
                        x+=(i+'a'-1);
                    }

                }
            }
            string h=s;
            reverse(h.begin(),h.end());
            s=s+x+h;
            cout<<gc<<endl;
            for(int i=1;i<=k;i++)cout<<s;
            NL;
            break;
        }
    }





    return 0;
}
