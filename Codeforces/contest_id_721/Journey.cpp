/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include<bits/stdc++.h>
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
//#define pi 2.0*acos(0.0)
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
template <class T>bool ISLEFT ( T a,T b,T c)
{
    if(((a.xx-b.xx)*(b.yy-c.yy)-(b.xx-c.xx)*(a.yy-b.yy))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 200000
#define md 1000000007ll
#define maxp 2050180000

typedef pair<int ,int> P;
typedef vector<int> V;

////////define value/////
vector<P>v[5004];
int vis[5005][5005];
int vi[5005][5005];
int main()
{
    int n,m,k;
    I3(n,m,k);
    for(int i=1;i<=m;i++)
    {
       int x,y;
       I2(x,y);
       int z;
       I(z);
       v[y].PB(mk(x,z));
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)vis[i][j]=k+1;
    }
    vis[n][1]=0;
    priority_queue<pair<int,P> >pq;
      pq.push(mk(0,mk(n,1)));
    SET(vi);
    while(!pq.empty())
    {
        pair<int,P> x=pq.top();
       // cout<<x.yx<<Endl;
        pq.pop();
       // cout<<x.yx<<Endl;
        for(int i=0;i<v[x.yx].size();i++)
        {
          //  lol;
            int l=-x.x+v[x.yx][i].y;
            int y=v[x.yx][i].x;
            //cout<<l<<" "<<vis[y][x.yy+1]<<Endl;
            if(l<vis[y][x.yy+1]){


               vis[y][x.yy+1]=l;
                 vi[y][x.yy+1]=x.yx;

               pq.push(mk(-vis[y][x.yy+1],mk(y,x.yy+1)));
            }
        }
    }
    int ans=0,sum=0;
    for(int i=n;i>=1;i--)
    {
       // cout<<vis[1][i]<<endl;
        if(vis[1][i]<=k){
            ans=i;
            sum=i;
            break;
        }
    }
    PI(ans);
 //cout<<vi[1][3]<<endl;
 ans=1;
    while(sum!=0)
    {
        PC("%d",ans);
        if(ans!=n)PC(" ");
        ans=vi[ans][sum];
       // cout<<ans<<Endl;
        sum--;

    }




    return 0;
}
