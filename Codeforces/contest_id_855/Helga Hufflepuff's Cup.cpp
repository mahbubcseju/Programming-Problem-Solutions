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


template <class T>bool ISLEFT ( T a, T b, T c)
{
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

#define md 1000000007ll
#define  mx 100004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
/////////////////////////

#define max_node 6004


ll m,x,ko;
vector<int>v[mx+2];
ll dp[4][mx+2][12];

void dfs(int u,int p)
{

    bool fl=0;

    ll ans[3][12];
    ll ans1[3][12];
    ll ans3[3][12];
    bool f=0;
    for(int i=0; i<v[u].size(); i++)
    {
        int x1=v[u][i];
        if(x1==p)continue;

        dfs(x1,u);
        f^=1;
        if(fl==0)
        {
            for(int k=0; k<=ko; k++)
            {
                ans[f][k]=(dp[1][x1][k]+dp[2][x1][k]+dp[3][x1][k])%md;


                ans1[f][k]=dp[1][x1][k];

                ans3[f][k]=(dp[1][x1][k]+dp[3][x1][k])%md;

            }

        }
        else
        {
            SET(ans[f]);
            SET(ans1[f]);
            SET(ans3[f]);
            for(int j=0; j<=ko; j++)
            {
                for(int l=0; l<=j; l++)
                {
                    ll va=(dp[1][x1][l]+dp[2][x1][l]+dp[3][x1][l])*ans[f^1][j-l];
                    va%=md;
                    ans[f][j]=(ans[f][j]+va)%md;

                    ll va1=ans1[f^1][j-l]*dp[1][x1][l];
                    va1%=md;
                    ans1[f][j]=(va1+ans1[f][j])%md;


                    ll va2=(dp[1][x1][l]+dp[3][x1][l])*ans3[f^1][j-l];
                    va2%=md;
                   ans3[f][j]=(ans3[f][j]+va2)%md;

                }
            }



        }
        fl=1;

    }


    if(!fl)
    {
        dp[1][u][0]=x-1;
        dp[2][u][1]=1;
        dp[3][u][0]=m-x;
    }
    else
    {
        for(int i=0; i<=ko; i++)
        {
            dp[1][u][i]=(ans[f][i]*(x-1))%md;
            if(i>0)
                dp[2][u][i]=ans1[f][i-1];

            dp[3][u][i]=(ans3[f][i]*(m-x))%md;
        }
    }
}

int main()
{

    int n;

    I(n);
    L(m);

    fr(i,1,n-1)
    {
        int x,y;
        I2(x,y);
        v[x].PB(y);
        v[y].PB(x);
    }
    L2(x,ko);

    dfs(1,-1);
    ll res=0;



    for(int i=0; i<=ko; i++)
    {
        res=(res+dp[1][1][i]+dp[2][1][i]+dp[3][1][i])%md;
    }

    PL(res),NL;

    return 0;
}
