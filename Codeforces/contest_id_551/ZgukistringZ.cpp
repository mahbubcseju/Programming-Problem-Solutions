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
#define mx 200001ll
#define md 1000000009ll
typedef pair<ll , ll >P;

////////define value/////]);
int main()
{
    string s,a,b;
    cin>>s>>a>>b;
    ll v[27],v1[27],v2[27];
    SET(v);
    SET(v1);
    SET(v2);
    for(ll i=0; i<s.size(); i++)
    {
        v[s[i]-96]++;
        // v1[s[i]-96]++;
    }
    for(ll  i=0; i<a.size(); i++)
    {
        v1[a[i]-96]++;
    }
    for(ll i=0; i<b.size(); i++)
    {
        v2[b[i]-96]++;
    }
    ll res=0, x=0,y=0;
    for(ll i=0; i<=s.size(); i++)
    {
        bool fl=0;
        for(ll j=1; j<=26; j++)
        {
            if(i*v1[j]>v[j])fl=1;

        }
        if(fl==1)break;
        else
        {
            ll lo=0;
            ll hi=s.size();
            //cout<<i<<endl;
            ll lop=0;
            while(lo<=hi)
            {
                ll mid=(lo+hi)/2;
                bool fl1=0;
                for(ll j=1; j<=26; j++)
                {
                    if(mid*v2[j]+i*v1[j]>v[j])fl1=1;
                }
                if(fl1==0)
                {
                    lop=max(lop,mid);
                    lo=mid+1;
                }
                else hi=mid-1;
            }
           // res=max(res,i+lop)
          // cout<<lop<<endl;
           if(res<i+lop)
           {
               res=i+lop;
               x=i;y=lop;
           }
        }

    }
  //  cout<<res<<endl;
    s="";
    for(ll i=1; i<=x; i++)
    {
        for(ll j=1; j<=26; j++)
        {

            v[j]-=v1[j];
        }
        s+=a;

    }
    for(ll i=1; i<=y; i++)
    {
        for(ll j=1; j<=26; j++)
        {

            v[j]-=v2[j];
        }
        s+=b;

    }
    for(ll j=1; j<=26; j++)
    {
        for(ll k=1; k<=v[j]; k++)s+=96+j;

    }
    cout<<s<<endl;
    return 0;
}
