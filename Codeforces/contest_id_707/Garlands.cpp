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

#define md 402653189ll
#define  mx 300000
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
/////////////////////////
ll tr[2003][2003];
void update(int x,int y,ll val)
{
    while(x<=2000)
    {
        int yy1=y;
        while(yy1<=2000)
        {
            tr[x][yy1]+=val;
            yy1+=yy1&-yy1;
        }
        x+=x&-x;
    }
}
ll res(int x,int y)
{
    ll sum=0;
    while(x>0)
    {
        int yy1=y;
        while(yy1>0)
        {
            sum+=tr[x][yy1];
            yy1-=yy1&-yy1;
        }
        x-=x&-x;
    }
    return sum;
}

pair<P,ll>gar[2002][2002];

ll ans[2002][2002];
bool batti[mx+2];

int main()
{
    int r,c;
    I2(r,c);
    int q;
    I(q);


    fr(i,1,q)
    {
        I(gar[i][0].xx);
        fr(j,1,gar[i][0].xx)
        {
            I2(gar[i][j].xx,gar[i][j].xy);
            L(gar[i][j].y);
        }
    }
    int qq;
    I(qq);
    int vq[qq+2][5];
    char s[10];

    int tq[qq+2][5];
    int l=0;
    fr(i,1,qq)
    {
        SC("%s",s);

        if(s[0]=='A')
        {
            vq[i][0]=1;
            fr(j,1,4)I(vq[i][j]);
            ++l;
            fr(j,1,4)tq[l][j]=vq[i][j];
        }
        else
        {
            I(vq[i][1]);
            vq[i][0]=0;
        }

    }


    for(int i=1;i<=q;i++)
    {

        for(int j=1;j<=gar[i][0].xx;j++)
        {
            update(gar[i][j].xx,gar[i][j].xy,gar[i][j].y);
        }

        for(int j=1;j<=l;j++)
        {
            ans[j][i]=res(tq[j][3],tq[j][4]);
            ans[j][i]+=res(tq[j][1]-1,tq[j][2]-1);
            ans[j][i]-=res(tq[j][1]-1,tq[j][4]);
            ans[j][i]-=res(tq[j][3],tq[j][2]-1);
        }

        for(int j=1;j<=gar[i][0].xx;j++)
        {
            update(gar[i][j].xx,gar[i][j].xy,-gar[i][j].y);
        }

    }
    int cnt=0;
    fr(i,1,qq)
    {
        if(vq[i][0]==0)
        {
            batti[vq[i][1]]^=1;
        }
        else
        {
            cnt++;
            ll re=0;

            fr(j,1,q)
            {
                if(batti[j]==0)re+=ans[cnt][j];
            }
            PL(re),NL;
        }
    }





    return 0;
}
