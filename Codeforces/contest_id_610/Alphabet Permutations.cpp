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
#define mx 200000
#define md 1000000007

#define maxp 1000004
typedef pair<int , int >P;
typedef vector<int >V;

////////define value/////
char ch[mx+3];
int tree[mx*4+4][11][11];
int ax[mx*4];
void update(int no,int s,int e,int st,int en,char  cha,int fl)
{
    if(s>=st&&e<=en)
    {

        if(fl==1)
        {
            if(ax[no]!=0)
            {
                ch[s]=ax[no]+96;
                // cout<<s<<" "<<ch[s]<<endl;

            }

            ax[no]=0;
        }
        else
        {
            ax[no]=cha-96;
            for(int i=1; i<=10; i++)
            {
                for(int j=1; j<=10; j++)tree[no][i][j]=0;
            }
        }
        return;
    }
    if(ax[no]!=0)
    {
        ax[no*2]=ax[no*2+1]=ax[no];
        for(int i=1; i<=10; i++)
        {
            for(int j=1; j<=10; j++)tree[no*2][i][j]=tree[no*2+1][i][j]=0;
        }
        ax[no]=0;
    }


    int mid=(s+e)/2;
    if(mid>=en)
    {
        update(no*2,s,mid,st,en,cha,fl);
    }
    else if(mid<st)
    {
        update(no*2+1,mid+1,e,st,en,cha,fl);
    }
    else
    {
        update(no*2,s,mid,st,mid,cha,fl);
        update(no*2+1,mid+1,e,mid+1,en,cha,fl);
    }
    for(int i=1; i<=10; i++)
    {
        for(int j=1; j<=10; j++)
        {
            tree[no][i][j]=(tree[no*2][i][j]+tree[no*2+1][i][j]);
        }
    }
}
void build(int no,int s,int e,int st)
{
    if(s==e)
    {
        int xo=ch[s]-96;
        int ho=ch[s+1]-96;
        //SET(tree[no]);
       // cout<<s<<e<<ch[s]<<ch[s+1]<<endl;
        for(int i=1;i<=10;i++)
        {
            for(int j=1;j<=10;j++)
            {
                tree[no][i][j]=0;
            }
        }
        if(ho>=1&&ho<=10)
        {
            tree[no][xo][ho]=1;
        }
        return ;
    }
    int mid=(s+e)/2;
    if(mid>=st)build(no*2,s,mid,st);
    else build(no*2+1,mid+1,e,st);
    for(int i=1; i<=10; i++)
    {
        for(int j=1; j<=10; j++)
        {
            tree[no][i][j]=(tree[no*2][i][j]+tree[no*2+1][i][j]);
        }
    }
}

int main()
{

    int n,m,k;
    I3(n,m,k);
    SC("%s",ch+1);
    ch[n+1]='z';
    for(int i=1; i<=n; i++)build(1,1,n,i);
    while(m--)
    {
        int id;
        I(id);
        if(id==1)
        {
            int x,y;
            char ch2[2];
            SC("%d%d%s",&x,&y,ch2);
            update(1,1,n,x,y,ch2[0],0);
            update(1,1,n,x,x,'z',1);
            if(x-1>0)
                update(1,1,n,x-1,x-1,'z',1);
            update(1,1,n,y,y,'z',1);
            if(y+1<=n)update(1,1,n,y+1,y+1,'z',1);
            if(x-1>0)build(1,1,n,x-1);
            build(1,1,n,y);
            //build()
        }
        else
        {
            char c[20];
            SC("%s",c+1);
            int res=0;
            for(int i=1; i<=k; i++)
            {
                for(int j=i+1; j<=k; j++)
                {
                    res+=tree[1][c[i]-96][c[j]-96];
                }
            }
            PI(n-res);
        }
    }


    return 0;
}
