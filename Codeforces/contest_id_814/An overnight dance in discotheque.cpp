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
template <class T> inline T BM(T p, T e, T M) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M) {
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text ) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a, T b, T c) {
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 400000ll
#define md 23377788ll
#define md1 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<int,int >P;
//////////////////////////
/////////////////////////
vector<int>v[mx+2];
double dp[10002][3][3];
int vis[mx+2];
int vis1[1002][3][3];
 double a[mx+2][4];
double qu(int i,int fl,int fl1)
{



    vis[i]=1;

    if(vis1[i][fl][fl]==1)return dp[i][fl][fl1];
    vis1[i][fl][fl]=1;
    double &ret=dp[i][fl][fl1];

    double ans=0;
    double an=0;
    for(int j=0;j<v[i].size();j++)
    {
        int p=v[i][j];

     //   cout<<i<<" "<<j<<Endl;
        ans+=qu(p,fl^1,fl1);
        an+=qu(p,fl,fl1^1);
    }

    if(fl==0)ans+=a[i][3];
    else ans-=a[i][3];
    if(fl1==0)an+=a[i][3];
    else an-=a[i][3];

    return ret=max(ans,an);
}
vector<int>nw[mx+2];

bool kul[mx+2];

int ara[mx+2],l;
void top(int i)
{
    kul[i]=1;
    for(int j=0;j<nw[i].size();j++)
    {
        int u=nw[i][j];
        if(kul[u]==0)
        {
            top(u);
        }
    }
    ara[++l]=i;

}

bool add[1002][1002];
int main()
{
    int n;
    I(n);

     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=3;j++)cin>>a[i][j];
     }

     int in[n+2],ou[n+2];
     SET(in);
     SET(ou);

     for(int i=1;i<=n;i++)
     {

         for(int j=1;j<=n;j++)
         {
             if(i==j)continue;

             double di=(a[i][1]-a[j][1]);
             di*=di;
             double ko=(a[i][2]-a[j][2]);
             ko*=ko;
             double ans=sqrt(di+ko);
             double ho=ans+a[j][3];
             if(ho<=a[i][3])
             {
                 in[i]++;
                 ou[j]++;
               nw[i].PB(j);
                 add[i][j]=1;
             }

            // if(i==3)cout<<j<<" "<<ho<<" "<<a[i][3]<<Endl;
         }
     }
     for(int i=1;i<=n;i++)a[i][3]*=a[i][3];

     for(int i=1;i<=n;i++)
     {
         if(kul[i]==0)top(i);
     }

     for(int j=1;j<=n;j++)
     {
         if(ara[j]==-1)continue;

         for(int k=j+1;k<=n;k++)
         {
             if(add[ara[k]][ara[j]])
             {
                 v[ara[k]].PB(ara[j]);
                 break;
             }
         }
     }


     double ko=0;
     for(int i=1;i<=n;i++)
     {
         if(vis[i]==1||ou[i])continue;

         ko+=qu(i,0,0);
     }

     PC("%.10lf\n",ko*pi);





    return 0;
}
