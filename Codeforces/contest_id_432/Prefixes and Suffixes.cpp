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
char a[100008];
ll z[100008];
void zalgo()
{
    ll l,r;
    l=r=0;
    z[0]=strlen(a);
    for(ll i=1; i<z[0]; i++)
    {
        if(i>r)
        {
            l=r=i;
            for(ll j=i; j<z[0]; j++)
            {
                if(a[j-i]!=a[j])break;
                else r=j;
            }
            if(a[i]!=a[0])z[i]=0;
            else z[i]=r-l+1;
        }
        else
        {
            //cout<<i<<endl;
            ll k=i-l;
            if(z[k]<r-i+1)
            {
                z[i]=z[k];
            }
            else
            {
                l=i;
                for(ll j=r+1; j<z[0]; j++)
                {
                    if(a[j-l]!=a[j])break;
                    else r=j;
                }
                z[i]=r-l+1;
            }

        }
       // if(a[i]=='X')cout<<l<<" "<<r<<endl;
    }
}
int main()
{
    //SC("%s",a);
    cin>>a;
    zalgo();
//for(ll i=0;i<strlen(a);i++)
  //  cout<<z[i]<<endl;
    ll l=strlen(a);
    ll res[l+2];
    SET(res);
    for(ll i=0; i<l; i++)
    {
        res[z[i]]+=1;
    }
    res[l+1]=0;
    for(ll i=l; i>=1; i--)
    {
        res[i]+=res[i+1];
    }
    vector<P>v;
    for(ll i=l-1; i>=0; i--)
    {
        ll op=l-i;
        //cout<<z[i]<<" "<<op<<endl;
        if(z[i]==op){
            v.PB(make_pair(op,res[op]));
        }

    }
    ll lol=v.size();
    P(lol);
    for(ll i=0;i<v.size();i++)
    {
        PC("%lld %lld\n",v[i].xx,v[i].yy);
    }
    return 0;
}
