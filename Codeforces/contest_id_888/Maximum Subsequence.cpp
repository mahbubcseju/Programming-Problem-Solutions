#include<bits/stdc++.h>
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
template <class T> inline T mdINV(T a, T M)
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


template <class T>bool ISLEFT(T a, T b, T c)
{
    if(((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1;  //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

#define md 2100000007ll
#define  mx 200004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
/////////////////////////
#define x first
#define y second



int ar[200];



int main()
{

    int n,m;
    I2(n,m);


    fr(i,0,n-1)I(ar[i]);

    if(n<=16)
    {
        int ma=0;

        for(int i=0; i<(1<<n); i++)
        {
            ll res=0;
            for(int j=0; j<n; j++)
            {
                if((i&(1<<j)))
                {
                    res=(res+ar[j]);
                    res%=m;
                }
            }
            ma=max(ma,(int)res);
        }
        PI(ma),NL;
        return 0;
    }

    int in=16;
    int arr[200];
    int sz=-1;
    for(int j=in; j<n; j++)
    {
        arr[++sz]=ar[j];
    }

    vector<int>v;
    int ans=0;
    sz++;
    for(int i=0; i<(1<<sz); i++)
    {
        ll res=0;
        for(int j=0; j<sz; j++)
        {
            if((i&(1<<j)))
            {
                res=(res+arr[j]);
                res%=m;
            }
        }
        v.PB(res);
        ans=max(ans,(int)res);
      //cerr<< res<<endl;
    }
    sort(v.begin(),v.end());

    for(int i=0; i<(1<<in); i++)
    {
        ll res=0;
        for(int j=0; j<in; j++)
        {
            if((i&(1<<j)))
            {
                res=(res+ar[j]);
                res%=m;
            }
        }
        ans=max(ans,(int)res);
       // cerr<<ans<<endl;

        int in1=lower_bound(v.begin(),v.end(),m-(int)res)-v.begin();
        in1--;
      //  cerr<<res<<" "<<in1<<Endl;
        if(in1>=0&&v.size()>in1)
        {
            ans=max(ans,(int)(v[in1]+res)%m);
        }

        int l=v.size();
        ans=max(ans,(int)(res+v[l-1])%m);

    }
    PI(ans),NL;

    return 0;
}
