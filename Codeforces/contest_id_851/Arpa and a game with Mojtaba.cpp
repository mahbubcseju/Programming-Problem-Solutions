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
#define  mx 200000
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
/////////////////////////

bool vis[mx+2];
int pr[mx+2],sz;
void seive()
{
    for(int i=2; i<=mx; i++)
    {
        if(vis[i]==0)
        {
            pr[++sz]=i;

            for(int j=i*2; j<=mx; j+=i)
                vis[j]=1;
        }
    }
}
map<int,int>mpd;
int dp(int musk)
{
    if(musk==0)return 0;

    if(mpd.find(musk)!=mpd.end())return mpd[musk];
    int abs[1002];
    int age=0;
    SET(abs);

    for(int j=0; j<30; j++)
    {

        // age|=(1<<j);
        int nu=musk-age;
        if((musk&(1<<j)))
            nu-=(1<<j);
        nu=(nu/(1<<(j+1)));
        //cerr<<nu<<Endl;
        nu|=age;
        abs[dp(nu)]=1;

        if((musk&(1<<j)))
        {
            age|=(1<<j);
        }
        if(age>=musk)break;
    }
    for(int i=0; i<=1000; i++)if(abs[i]==0)return  mpd[musk]= i;
}
int main()
{
    seive();
    int n;
    I(n);
    set<int>st;
    map<int,int>mp;
    fr(i,1,n)
    {
        int x;
        I(x);
        for(int j=1; j<=sz&&pr[j]*pr[j]<=x; j++)
        {
            if(x%pr[j]==0)
            {
                st.insert(pr[j]);
                int cnt=-1;
                while(x%pr[j]==0)
                {
                    cnt++;
                    x/=pr[j];
                }
                // cerr<<cnt<<endl;
                mp[pr[j]]|=(1<<cnt);
            }
        }
        if(x>1)
        {
            mp[x]|=(1<<0);
            st.insert(x);
        }
    }

    int ans=0;
    for(auto i:st)
    {
        //  cerr<<i<<" "<<mp[i]<<endl;
        ans^=dp(mp[i]);
    }
    if(ans)PC("Mojtaba\n");
    else PC("Arpa\n");

    return 0;
}
