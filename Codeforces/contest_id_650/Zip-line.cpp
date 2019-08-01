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
#define  mx 1000000

typedef pair<int,int >P;
//////////////////////////
/////////////////////////

int a[mx+2];
//  //

int tr[mx+2];

void update(int in,int val)
{
    while(in<=mx)
    {
        tr[in]=max(tr[in],val);
        in+=in&-in;
    }
}

int qu(int in)
{
    int ans=0;

    while(in>0)
    {
        ans=max(ans,tr[in]);

        in-=in&-in;
    }
    return ans;
}


int main()
{
    int  n,m;
    I2(n,m);

    int po[n+m+2],neg[n+m+2];
    fr(i,1,n)
    {
        I(a[i]);
        po[i]=a[i];
        neg[i]=-a[i];
    }
    vector<P>q[n+2];
    int sz=n;
    int pop[m+2];
    fr(i,1,m)
    {
        int x,y;
        I2(x,y);
        pop[i]=x;
        q[x].PB(mk(y,i));
        neg[++sz]=-y;
        po[sz]=y;
    }
   // lol;

    int ans[m+2];
    SET(ans);
    sort(po+1,po+sz+1);
    sort(neg+1,neg+sz+1);
  // lol;
    int ko=0;
    int lek[n+2];
    for(int i=n;i>=1;i--)
    {
        int x=lower_bound(neg+1,neg+sz+1,-a[i])-neg;
       //  cerr<<" "<<x<<endl;
        for(int j=0;j<q[i].size();j++)
        {
            P u=q[i][j];
            int y=lower_bound(neg+1,neg+sz+1,-u.x)-neg;
           // cerr<<i<<" "<<u.x<<" "<<u.y<<" "<<y<<endl;
            ans[u.y]+=qu(y-1);
           // cerr<<y<<Endl;
        }


       // cerr<<x<<" ";
        int re=qu(x-1);
       // cout<<re<<Endl;
         lek[i]=re;
        update(x,re+1);
        ko=max(ko,re+1);

    }
  //  lol;
    SET(tr);
    int count[n+2];
    SET(count);
    int poso[n+2];
    SET(poso);
    for(int i=1;i<=n;i++)
    {
        int x=lower_bound(po+1,po+sz+1,a[i])-po;

        for(int j=0;j<q[i].size();j++)
        {
            P u=q[i][j];
            int y=lower_bound(po+1,po+sz+1,u.x)-po;
            ans[u.y]+=qu(y-1);
        }
        int re=qu(x-1);
        if(re+lek[i]+1==ko)
        {
          poso[i]=re+1;
          count[re+1]++;
        }

        update(x,re+1);

    }
    //cerr<<" "<<ko<<Endl;
    for(int i=1;i<=m;i++)
    {
        int as=ko;
        if(count[poso[pop[i]]]==1)as--;
        //cerr<<ans[i]+1<<" "<<as<<" ";
        PI(max(ans[i]+1,as)),NL;
    }

    return 0;
}
