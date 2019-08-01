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
#define mx  2000
#define md 1000000007ll

#define maxp 100000000000000004
typedef pair<int , int >P;
typedef vector<int >V;

////////define value/////
char a[mx+2],b[mx+2];
ll DP[mx+2][3][mx+2];
ll l;
int m,n;
ll dp(ll in,ll ch,ll re)
{
    if(in==l+1)
    {
        if(re==0)return 1;
        else return 0;
    }
    ll &ret=DP[in][ch][re];
    if(ret!=-1)return ret;
    ret=0;
    if(in%2==0)
    {
        if(ch)ret+=dp(in+1,ch,(re*10+m)%n);
        else
        {
            if(m<(a[in]-'0'))ret+=dp(in+1,1,(re*10+m)%n);
            else if(m==(a[in]-'0'))ret+=dp(in+1,ch,(re*10+m)%n);
        }
        if(ret>=md)ret-=md;

    }
    else
    {
        if(ch)
        {
            for(int j=0; j<=9; j++)
            {
                if(j==m)continue;
                ret+=dp(in+1,ch,(re*10+j)%n);
                if(ret>=md)ret-=md;
            }
        }
        else
        {
            for(int j=0; j<=(a[in]-'0'); j++)
            {
                if(j==m)continue;
                if(j==a[in]-'0')ret+=dp(in+1,ch,(re*10+j)%n);
                else ret+=dp(in+1,1,(re*10+j)%n);
                if(ret>=md)ret-=md;
            }
        }
    }

    return ret;
}
ll dp1(ll in,ll ch,ll re)
{
    if(in==l+1)
    {
        if(re==0)return 1;
        else return 0;
    }
    ll &ret=DP[in][ch][re];
    if(ret!=-1)return ret;
    ret=0;
    if(in%2==0)
    {
        if(ch)ret+=dp1(in+1,ch,(re*10+m)%n);
        else
        {
            if(m<(b[in]-'0'))ret+=dp1(in+1,1,(re*10+m)%n);
            else if(m==(b[in]-'0'))ret+=dp1(in+1,ch,(re*10+m)%n);
        }
        if(ret>=md)ret-=md;

    }
    else
    {
        if(ch)
        {
            for(int j=0; j<=9; j++)
            {
                if(j==m)continue;
                ret+=dp1(in+1,ch,(re*10+j)%n);
                if(ret>=md)ret-=md;
            }
        }
        else
        {
            for(int j=0; j<=(b[in]-'0'); j++)
            {
                if(j==m)continue;
                if(j==b[in]-'0')ret+=dp1(in+1,ch,(re*10+j)%n);
                else ret+=dp1(in+1,1,(re*10+j)%n);
                if(ret>=md)ret-=md;
            }
        }
    }

    return ret;
}

int main()
{
    I2(n,m);

    SC("%s",b+1);
    SC("%s",a+1);
    l=strlen(a+1);
    SETR(DP);
    ll res=dp(1,0,0);
    SETR(DP);
    ll sum=dp1(1,0,0);
    res-=sum;
    if(res<0)res+=md;
    bool fl=0;
    for(int j=1;j<=l;j+=2)
    {
        if(b[j]-'0'==m)fl=1;
    }
    for(int j=2;j<=l;j+=2)
    {
        if(b[j]-'0'-m!=0)fl=1;
    }
    int re=0;
    for(int j=1;j<=l;j++)
    {
        re=re*10+b[j]-'0';
        re%=n;
    }
    if(fl==0&&re==0)res++;
    PL(res);


}
