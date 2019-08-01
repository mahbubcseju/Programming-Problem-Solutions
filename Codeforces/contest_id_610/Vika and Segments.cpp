
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
#define mx 400000
#define md 1000000007

#define maxp 1000004
typedef pair<int , int >P;
typedef vector<int >V;

////////define value/////
ll bit[mx + 3];
void up(int i, ll val)
{
    while (i <= mx)
    {
        //lol;
        bit[i] += val;
        i += (i&-i);
       // cout<<i<<endl;
    }
}
ll query(int i)
{
    ll sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}
int main()
{
    int n;
    I(n);
    vector<pair<int, P> >h, v;
    for (int i = 1; i <= n; i++)
    {
        int x, y, u, v1;
        I2(x, y);
//        fm.PB(a[i].xx.xx);
//        fm.PB(a[i].xx.yy);
        I2(u, v1);
        if (x == u)
        {
            v.PB(mk(x, mk(min(y, v1), max(y, v1))));
        }
        else h.PB(mk(y, mk(min(x, u), max(x, u))));
    }
    sort(v.begin(), v.end());
    sort(h.begin(), h.end());
    pair<P, int> a[n + 2];
    int sz = 0;
    for (int i = 0; i < v.size(); i++)
    {

        if (sz > 0 && a[sz].yy == v[i].xx)
        {
            if (v[i].yy.xx > a[sz].xx.yy)a[++sz] = mk(v[i].yy, v[i].xx);
            else if (v[i].yy.yy > a[sz].xx.yy)
            {
                a[sz].xx.yy = v[i].yy.yy;
            }

        }
        else a[++sz] = mk(v[i].yy, v[i].xx);
    }
    sort(a + 1, a + sz + 1);

    pair<int, P>b[n + 2];
    int s = 0;
    for (int i = 0; i < h.size(); i++)
    {

        if (s > 0 && b[s].xx == h[i].xx)
        {
            if (h[i].yy.xx > b[s].yy.yy)b[++s] = h[i];
            else if (h[i].yy.yy > b[s].yy.yy)
            {
                b[s].yy.yy = h[i].yy.yy;
            }

        }
        else b[++s] = h[i];
    }
    sort(b + 1, b + s + 1);
    ll res = 0;
    vector<int>fm;
    for (ll i = 1; i <= sz; i++)
    {
        res += (ll)abs(a[i].xx.xx - a[i].xx.yy) + 1;
        fm.PB(a[i].xx.xx);
        fm.PB(a[i].xx.yy);
        fm.PB(a[i].yy);
        // cout<<a[i].yy<<" "<<a[i].xx.xx<<" "<<a[i].xx.yy<<endl;
    }
    for (ll i = 1; i <= s; i++)
    {
        res += (ll)abs(b[i].yy.xx - b[i].yy.yy) + 1;
        fm.PB(b[i].yy.xx);
        fm.PB(b[i].yy.yy);
        fm.PB(b[i].xx);
        //cout<<b[i].xx<<" "<<b[i].yy.xx<<" "<<b[i].yy.yy<<endl;
    }

    sort(fm.begin(), fm.end());
    map<int, int>mp;
    int st = 0;
    for (int i = 0; i < fm.size(); i++)
    {
        if (mp.find(fm[i]) == mp.end())mp[fm[i]] = ++st;
    }
    int k = 1;

    priority_queue<pair<int, P> >pq;
    //cout<<res<<endl;
   // cout<<sz<<endl;
    for (int i = 1; i <= s; i++)
    {
      // cout<<b[i].xx<<" "<<b[i].yy.xx<<" "<<b[i].yy.yy<<endl;
        for (int j = k; j <= sz; j++)
        {
          //  cout<<a[j].yy<<endl;
            //lol;
            if (a[j].xx.xx <= b[i].xx)
            {
                pq.push(mk(-a[j].xx.yy, mk(a[j].xx.xx, a[j].yy)));
                //cout<<mp[]
                up(mp[a[j].yy], 1ll);
                k=j+1;
            }
            else
            {

                break;
            }
        }
        while (pq.size()!=0&&(-pq.top().xx) < b[i].xx)
        {
            //lol;
            up(mp[pq.top().yy.yy], -1ll);
            pq.pop();
        }
       // cout<<pq.size()<<endl;
        ll xo= (query(mp[b[i].yy.yy]) - query(mp[b[i].yy.xx] - 1));
       // cout<<xo<<endl;

        res-=xo;
      // cout<<res<<endl;

    }
    PL(res);


    return 0;
}
