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
#define D double
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define FL(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
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
template <class T> inline T MDINV(T a, T M)
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

template<typename T> T in()
{
    char ch;
    T n = 0;
    bool ng = false;
    while (1)
    {
        ch = getchar();
        if (ch == '-')
        {
            ng = true;
            ch = getchar();
            break;
        }
        if (ch >= '0' && ch <= '9') break;
    }
    while (1)
    {
        n = n * 10 + (ch - '0');
        ch = getchar();
        if (ch < '0' || ch > '9')   break;
    }
    return (ng ? -n : n);
}
typedef pair<int, int >P;
#define mx 200000
#define md 1000000007
#define mx1 (1<<25)
#define mx2 (1<<15)



int par[mx+4];
int Unin(int u)
{
    if(par[u]==u)
        return u;
    return par[u]=Unin(par[u]);
}
vector<P>v[mx+2];
int lev[mx+3];
P tab[mx+3][22];
void dfs(int i,int p,int le)
{
    lev[i]=le;
    tab[i][0].xx=p;
    for(int j=0; j<v[i].size(); j++)
    {
        int u=v[i][j].xx;
        int cost=v[i][j].yy;
        if(u!=p)
        {

            tab[u][0].yy=cost;
            dfs(u,i,le+1);
        }
    }

}


int lca(int x,int y)
{
    if(lev[x]>lev[y])
    {
        swap(x,y);
    }
    int ans=0;

    for(int i=20; i>=0; i--)
    {
        if(lev[y]>=(1<<i)&&lev[y]-(1<<i)>=lev[x])
        {

            ans=max(ans,tab[y][i].yy);
            //  cout<<ans<<endl;
            y=tab[y][i].xx;
        }
    }
    if(x==y)return ans;
//cout<<ans<<endl;
    for(int i=20; i>=0; i--)
    {
        if(tab[x][i].xx!=-1&&tab[x][i].xx!=tab[y][i].xx)
        {
            //lol;
            ans=max(ans,tab[x][i].yy);
            ans=max(ans,tab[y][i].yy);
            x=tab[x][i].xx;
            y=tab[y][i].xx;
        }
    }
    //lol;
    ans=max(ans,tab[x][0].yy);
    ans=max(ans,tab[y][0].yy);
    // if(ans==-1)while(1){}
    return ans;
}
pair< int ,P > a[mx+2],lov[mx+2];

int main()
{
   // R("input.txt");
    //W("output.txt");
        int n,m;
        I2(n,m);

        for(int i=1; i<=m; i++)
        {
            int x,y,z;
            I3(x,y,z);
            a[i]=mk(z,mk(x,y));
            lov[i]=a[i];
        }
        sort(a+1,a+m+1);
        SETR(tab);
        for(int i=0; i<=20; i++)
        {
            for(int j=1; j<=n; j++) {

                tab[j][i].xx=-1;
                tab[j][i].yy=0;
            }
        }
        for(int i=0; i<=mx; i++)
        {
            v[i].clear();
            par[i]=i;
        }
        //mst part
        int sz=0;
        ll ress=0;
        for(int i=1; i<=m; i++)
        {
            int u1=a[i].yy.xx;
            int v1=a[i].yy.yy;
            u1=Unin(u1);
            v1=Unin(v1);
            if(u1!=v1)
            {
                ress+=(ll)a[i].xx;
                sz++;
                par[u1]=v1;
                v[a[i].yy.xx].PB(mk(a[i].yy.yy,a[i].xx));
                v[a[i].yy.yy].PB(mk(a[i].yy.xx,a[i].xx));
            }
            if(sz==n-1)break;
        }
        //  cout<<"ress ::::"<<ress<<endl;


        //dfs for level
        dfs(1,-1,1);

        //sparse table
        for(int i=1; i<=20; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(tab[j][i-1].xx!=-1)
                {
                    tab[j][i].xx=tab[tab[j][i-1].xx][i-1].xx;
                    tab[j][i].yy=max(tab[j][i-1].yy,tab[tab[j][i-1].xx][i-1].yy);
                }
            }
        }

        //Query
        //cout<<tab[2][0].yy<<endl;

        int q;
        q=m;
//        I(q);
//        PC("Case %d:\n",++cs);
        for(int q1=1;q1<=m;q1++)
        {
            int x,y;
            x=lov[q1].yy.xx;
            y=lov[q1].yy.yy;
            int ans=lca(x,y);
            ll co=lov[q1].xx-ans;
            PL(ress+co);
        }


    return 0;
}
