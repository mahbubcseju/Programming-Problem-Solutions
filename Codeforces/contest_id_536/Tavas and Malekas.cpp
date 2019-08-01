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
#define I int
#define ll long long int
#define ull unsigned long long int
#define D double
#define SL(a) scanf("%d",&a)
#define SL2(a,b) scanf("%d%d",&a,&b)
#define SL3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define S(a) scanf("%lld",&a)
#define S2(a,b) scanf("%lld%lld",&a,&b)
#define S3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PL(a) printf("%d\n",a)
#define P(a) printf("%lld\n",a)
#define PT(t) printf("Case %lld: ",t)
#define FL(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FLR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define F(J,a,b) for(long long J=a;J<=b;J++)
#define FR(J1,a,b) for(long long J1=a;J1>=b;J1--)
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PB(a) push_back(a)
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
using namespace std;
template <class T> inline T BM(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T MDINV(T a,T M)
{
    return BM(a,M-2,M);
}
template <class T> inline T PW(T p,T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret*p);
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
typedef pair<ll,ll  >P;
////////define value//////////
ll m,n;
char a[1000004];
ll ans[1000004];
void zalgo()
{
    ll l,r;
    l=r=1;
    ans[1]=strlen(a+1);
    for(ll i=2; i<=ans[1]; i++)
    {
        if(i>r)
        {
            l=r=i;
            if(a[1]!=a[i])ans[i]=0;
            else
            {
                for(ll j=i; j<=ans[1]; j++)
                {
                    if(a[j-i+1]!=a[j])break;
                    else
                    {
                        r=j;

                    }
                }
                ans[i]=r-l+1;
            }


        }
        else
        {
            ll k=i-l+1;
            if(ans[k]<=r-i+1)
            {
                ans[i]=ans[k];
            }
            else
            {
                l=i;
                for(ll j=r+1; j<=ans[1]; j++)
                {
                    if(a[j-l+1]!=a[j])break;
                    else r=j;
                }
                ans[i]=r-l+1;
            }
        }
    }
}
int main()
{

    S2(m,n);
    SC("%s",a+1);
    zalgo();
    ll l=strlen(a+1);
    ll b[m+2];
    SET(b);
    for(ll i=1; i<=n; i++)
    {
        ll x;
        S(x);
        b[x]=1;
    }
    ll res=1;
    ll ko=0;
    bool fl=0;
    for(ll i=1; i<=m; i++)
    {
        //cout<<ko<<" "<<b[i]<<endl;
        if(ko==0&&b[i]==0)res=(res*26)% 1000000007ll;
        else  if(ko==0&&b[i]==1)ko=1;
        else  if(ko!=0&&b[i]==0)
        {
            ko++;
            //if(ko==ans[1])ko=0;
        }
        else  if(ko!=0&&b[i]==1)
        {
            ko++;
            ll x=ans[ko];
           // cout<<x<<endl;
            if(x<(ans[1]-ko+1))
            {
                fl=1;
                break;
            }
            else ko=1;
        }
        if(ko==ans[1])ko=0;

    }
    if(ko!=0)fl=1;
    if(fl==1)res=0;
    P(res);

    return 0;
}
