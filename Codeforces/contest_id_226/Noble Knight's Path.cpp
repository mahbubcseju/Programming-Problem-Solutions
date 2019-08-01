/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <deque>
#include <climits>
#include <complex>
#include <bitset>
#include <limits>
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


#define mx 200000
#define md 1000000007
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29
#define MX 200000


typedef pair<int , int > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////
vector<int>adj[mx+2];
int n;
int chainNo,ptr;
int T[MX],L[MX];
int subTree[MX];
int Start[MX],chainID[MX];//Needs to clear
int pos[MX];
int cvr[MX][2];
int Tree[22*MX];
void Dfs(int u,int p,int l)
{
    T[u] = p;
    L[u] = l;

    subTree[u] = 1;

    for (int i=0; i<adj[u].size(); i++)
    {
        int v= adj[u][i];

        if (v == p)     continue;

        Dfs(v,u,l+1);
        subTree[u] += subTree[v];
    }
}

void HLD(int u,int p)
{
    if (Start[chainNo] == 0)
        Start[chainNo] = u;

    chainID[u] = chainNo;
    pos[u] = ++ptr;
    cvr[ptr][0] = u;

    int sc = -1, mx1 = -1;

    for (int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if ( v!= p && subTree[v] > mx1)
        {
            sc = i;
            mx1 = subTree[v];
        }
    }

    if (sc != -1 )      HLD(adj[u][sc],u);

    for (int i=0; i<adj[u].size(); i++)
    {
        if (i == sc)        continue;

        int v= adj[u][i];

        if (v!=p)
        {
            chainNo++;
            HLD(v,u);
        }
    }

    //  cvr[u][1] = ptr;
}
int tm[mx+2];
struct node
{
    int info,le,ri;
    node()
    {
        info=le=ri=0;
    }
};
node tr[mx*22];
int sz;
void build(int no,int s,int e)
{
    if(s==e){

        tr[no].info=0;
        return ;
    }
    int mid=(s+e)/2;
    tr[no].le=++sz;
    build(sz,s,mid);
    tr[no].ri=++sz;
    build(sz,mid+1,e);
    tr[no].info=0;
}
void update(int pr,int nw,int s,int e,int in)
{
    if(s==e&&in==e)
    {
        tr[nw].info++;
        return ;
    }
    int mid=(s+e)/2;
    if(in<=mid)
    {
        tr[nw].ri=tr[pr].ri;
        tr[nw].le=++sz;
        update(tr[pr].le,tr[nw].le,s,mid,in);
    }
    else
    {
        tr[nw].le=tr[pr].le;
        tr[nw].ri=++sz;
        update(tr[pr].ri,tr[nw].ri,mid+1,e,in);
    }
    tr[nw].info=tr[tr[nw].le].info+tr[tr[nw].ri].info;
}


int qu1(int pr,int nw,int s,int e,int st,int en)
{
    if(s>=st&&e<=en)
    {
        return tr[nw].info-tr[pr].info;
    }

    int mid=(s+e)/2;
    if(mid>=en)
    {
        if(tr[nw].le!=0)return qu1(tr[pr].le,tr[nw].le,s,mid,st,en);
    }
    else if(mid<st)
    {
        if(tr[nw].ri!=0)return qu1(tr[pr].ri,tr[nw].ri,mid+1,e,st,en);
    }
    else
    {
        int ans=0;
        if(tr[nw].le!=0)ans+= qu1(tr[pr].le,tr[nw].le,s,mid,st,mid);
        if(tr[nw].ri!=0)ans+= qu1(tr[pr].ri,tr[nw].ri,mid+1,e,mid+1,en);
        return ans;
    }
    return 0;
}
int query(int pr,int nw,int s,int e,int st,int en)
{
    return (en-st+1)-qu1( pr, nw,s, e, st, en);

}
int qu(int pr,int nw,int s,int e,int st,int en,int k)
{
   // cout<<s<<" "<<e<<" "<<st<<" "<<en<<" "<<k<<endl;
    if(s==e)
    {
        return cvr[s][0];
    }

    int mid=(s+e)/2;
    if(mid>=en)
    {
        if(tr[nw].le!=0)return qu(tr[pr].le,tr[nw].le,s,mid,st,en,k);
    }
    else if(mid<st)
    {
        if(tr[nw].ri!=0)return qu(tr[pr].ri,tr[nw].ri,mid+1,e,st,en,k);
    }
    else
    {
        int ho=(en-mid)-qu1(tr[pr].ri,tr[nw].ri,mid+1,e,mid+1,en);
       // cout<<s<<" "<<e<<" "<<st<<" "<<en<<" "<<k<<" "<< ho<<endl;
        if(k<=ho)return qu(tr[pr].ri,tr[nw].ri,mid+1,e,mid+1,en,k);
        else return qu(tr[pr].le,tr[nw].le,s,mid,st,mid,k-ho);
    }
    return 0;
}
int q;
int solve(int pr,int nw,int s,int e,int st,int en,int k)
{
    if(s==e)
    {
        return cvr[s][0];
    }

    int mid=(s+e)/2;
    if(mid>=en)
    {
        if(tr[nw].le!=0)return solve(tr[pr].le,tr[nw].le,s,mid,st,en,k);
    }
    else if(mid<st)
    {
        if(tr[nw].ri!=0)return solve(tr[pr].ri,tr[nw].ri,mid+1,e,st,en,k);
    }
    else
    {
        int ho=(mid-st+1)-qu1(tr[pr].le,tr[nw].le,s,mid,st,mid);
       // if(q==5)cout<<ho<<" "<<k<<endl;
        if(k<=ho)return solve(tr[pr].le,tr[nw].le,s,mid,st,mid,k);
        else return solve(tr[pr].ri,tr[nw].ri,mid+1,e,mid+1,en,k-ho);
    }
    return -1;
}



int lca(int u,int v)
{
    while(true)
    {
        int unom=chainID[u],vnom=chainID[v];
        int ustart=Start[unom],vstart=Start[vnom];

        if(unom==vnom) return (L[u]<L[v]?u:v);
        else if(L[ustart]<L[vstart]) v=T[vstart];
        else u=T[ustart];
    }
}
int y;
int sum(int a,int b,int k)
{
    int re=0;
    vector<P>store;
    while(chainID[b]!=chainID[a])
    {

        int ha = Start[chainID[b]];
        store.PB(mk(ha,b));
        //cout<<ha<<" "<<b<<endl;
        int pa=pos[b];
        int pha=pos[ha];
        re+=query(tm[y],tm[q-1],1,n,pha,pa);
        b=T[ha];

    }
    store.PB(mk(a,b));
    re+=query(tm[y],tm[q-1],1,n,pos[a],pos[b]);
    if(re<k)return -1;

    reverse(store.begin(),store.end());
    // cout<<q<<" "<<store.size()<<" lol"<<re<<" "<<endl;
    for(int i=0; i<store.size(); i++)
    {
       // cout<<store[i].x<<" "<<store[i].y<<endl;
        int ans=query(tm[y],tm[q-1],1,n,pos[store[i].x],pos[store[i].y]);
       //  cout<<ans<<" "<<y<<q<<Endl;
        if(ans>=k)
            return solve(tm[y],tm[q-1],1,n,pos[store[i].x],pos[store[i].y],k);
        else k-=ans;
    }

    return -1;




}

int main()
{

    I(n);
    int root=0;
    fr(i,1,n)
    {

        int x;
        I(x);

        if(x)
        {
            adj[i].PB(x);
            adj[x].PB(i);
        }
        else root=i;

    }


    chainNo = 1;
    ptr = 0;
    Dfs(root,-1,1);
    HLD(root,-1);
    //cout<<chainNo<<" Chain no "<<endl;


    int m;
    I(m);

    sz=0;
    build(sz,1,n);
    for(q=1; q<=m; q++)
    {
        int t;
        I(t);

        if(t==1)
        {
            int x;
            I(x);
            tm[q]=++sz;
            update(tm[q-1],tm[q],1,n,pos[x]);
        }
        else
        {
            int a,b,k;
            I2(a,b);
            I2(k,y);

            int lc=lca(a,b);
            int xo=query(tm[y],tm[q-1],1,n,pos[a],pos[a]);
            k+=xo;//cout<<k<<endl;
           // cout<<lc<<" "<<a<<" "<<b<<endl;
            int res=-1;
            bool fl=0;
            while(chainID[a]!=chainID[lc])
            {
                fl=1;
                int ha = Start[chainID[a]];
                int pa=pos[a];
                int pha=pos[ha];
                int ans=query(tm[y],tm[q-1],1,n,pha,pa);
               // cout<<ans<<endl;
                if(ans<k)
                {
                    k-=ans;
                    a=T[ha];
                }
                else
                {
                   // cout<<pha<<" "<<pa<<k<<endl;
                    res=qu(tm[y],tm[q-1],1,n,pha,pa,k);

                    break;
                }

            }
          //   cout<<lc<<" "<<a<<" "<<b<<" "<<k<<res<<endl;
            if(res==-1)
            {
                fl=1;
                int ans=query(tm[y],tm[q-1],1,n,pos[lc],pos[a]);
                //cout<<ans<<" "<<endl;
               // cout<<k<<" "<<ans<<endl;
                if(ans<k)
                {
                    k-=ans;
                    a=lc;
                }
                else {res=qu(tm[y],tm[q-1],1,n,pos[lc],pos[a],k);
                //cout<<a<<" "<<lc<<" "<<k<<" "<<res<<endl;

                }
            }
            //cout<<lc<<" "<<a<<" "<<b<<" "<<k<<res<<endl;
            if(res==-1)
            {
                k+=query(tm[y],tm[q-1],1,n,pos[lc],pos[lc]);

             // cout<<pos[lc]<<" "<<pos[b]<<" "<<k<<endl;
                res=sum(lc,b,k);
            }
            if(res==b)res=-1;
            PI(res);
            NL;
            tm[q]=++sz;
            tr[sz].info=tr[tm[q-1]].info;
            tr[sz].le=tr[tm[q-1]].le;
            tr[sz].ri=tr[tm[q-1]].ri;
        }

    }

    return 0;
}
