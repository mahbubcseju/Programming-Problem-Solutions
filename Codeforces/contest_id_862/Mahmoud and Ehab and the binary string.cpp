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
#define  mx 1000004
#define base 193ll

typedef pair<ll,ll >P;
//////////////////////////
/////////////////////////

int main()
{
    int n;
    I(n);
    cout<<"? ";

    for(int i=1; i<=n; i++)cout<<1;
    cout<<"\n";
    int x;
    cin>>x;
    cout<<"? ";

    cout<<0;
    for(int i=1; i<n; i++)cout<<1;
    cout<<"\n";
    int y;
    cin>>y;


    if(x>y)
    {
        //0
        int lop;
        int lo=2;
        int hi=n;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            cout<<"? ";
            for(int i=1; i<=mid; i++)cout<<0;

            for(int j=mid+1; j<=n; j++)cout<<1;
            cout<<"\n";
            int ho;
            cin>>ho;
            if(y-ho==mid-1)
            {
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
                lop=mid;
            }
        }
        cout<<"! "<<1<<" "<<lop<<endl;
    }
    else
    {
        cout<<"? "<<1;
        for(int i=2; i<=n; i++)cout<<0;
        cout<<"\n";

        cin>>y;
        //1
        int lop;
        int lo=2;
        int hi=n;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            cout<<"? ";
            for(int i=1; i<=mid; i++)cout<<1;
            for(int j=mid+1; j<=n; j++)cout<<0;
            cout<<"\n";
            int ho;
            cin>>ho;
            if(y-ho==mid-1)
            {
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
                lop=mid;
            }
        }
        cout<<"! "<<lop<<" "<<1<<endl;

    }
    return 0;
}
