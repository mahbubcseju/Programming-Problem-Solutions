/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
#include<bits/stdc++.h>
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
#define mx 100004ll
#define md 1000000007ll
typedef pair<ll , ll >P;
typedef vector<ll>V;

////////define value/////]);
ll res[mx*5][6];
ll a[mx][6];
ll n,m;
void update(ll no,ll le,ll r)
{
    if(le==r)
    {
        for(ll i=1;i<=m;i++)
        {res[no][i]=a[le][i];}
        return ;
    }
    ll mid=(le+r)/2;
    update(no*2,le,mid);
    update(no*2+1,mid+1,r);
    for(ll k=1;k<=m;k++)
    res[no][k]=max(res[no*2][k],res[no*2+1][k]);
}
ll query(ll no,ll l,ll r,ll  s,ll e,ll k)
{
    if(l>=s&&r<=e)
    {
        return res[no][k];
    }
    ll mid=(l+r)/2;
    if(e<=mid)return query(no*2,l,mid,s,e,k);
    else if(s>mid)return query(no*2+1,mid+1,r,s,e,k);
    else
    {
        return max(query(no*2,l,mid,s,mid,k),query(no*2+1,mid+1,r,mid+1,e,k));
    }
}
int main()
{
    ll k;
    S3(n,m,k);
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            S(a[i][j]);
        }
    }
   // lol;
        update(1,1,n);

  //  lol;
    ll b[6];
    ll c[6];
    SET(c);
    SET(b);
    ll re=0;
    ll ptr=1;

    for(ll i=1;i<=n;i++)
    {
        while(ptr<=i)
        {
            ll ok=0;
            for(ll j=1;j<=m;j++)
            {
                b[j]=query(1,1,n,ptr,i,j);
                ok+=b[j];
            }
            if(ok<=k)
            {
                if(i-ptr+1>re){
                re=i-ptr+1;
                for(ll j=1;j<=m;j++)c[j]=b[j];
                }
                break;
            }
            else ptr++;
        }
    }
    for(ll i=1;i<=m;i++)
        cout<<c[i]<<" ";

    return 0;
}
