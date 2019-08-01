
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
int dx[] = { +1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};
int main()
{
    int n, m;
    I2(n, m);
    char ch[n + 2][m + 2];
    for (int i = 1; i <= n; i++)
    {
        SC("%s", ch[i] + 1);
    }
    int a[n + 2][m + 2];
    SET(a);
    queue<P>q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ch[i][j] == '*')continue;
            for (int k = 0; k < 4; k++)
            {
                int x = dx[k] + i;
                int y = dy[k] + j;
                if (x >= 1 && x <= n && y >= 1 && y <= m)
                {
                    if (ch[x][y] == '.')a[i][j]++;
                }
            }
            if (a[i][j] == 1)
            {
                  //cout<<i<<" "<<j<<endl;
                q.push(mk(i, j));
            }
        }
    }
    bool fl = 0;
    while (!q.empty())
    {
        P x = q.front();
        q.pop();
       // cout << x.xx << " " << x.yy << endl;
        bool cl = 0;
        for (int i = 0; i < 4; i++)
        {
            int u = x.xx + dx[i];
            int v = x.yy + dy[i];
            if (u >= 1 && u <= n && v >= 1 && v <= m && ch[u][v] == '.')
            {
                a[x.xx][x.yy]--;
                a[u][v]--;
               // cout << x.xx << " " << x.yy <<" "<<u<<" "<<v<< endl;
                for (int k = 0; k < 4; k++)
                {
                    int ho = u + dx[k];
                    int jo = v + dy[k];
                    if (ho >= 1 && ho <= n && jo >= 1 && jo <= m && ch[ho][jo] == '.'&&!(ho==x.xx&&jo==x.yy))
                    {
                        a[ho][jo]--;
                       // cout<<ho<<" "<<jo<<" "<<a[ho][jo]<<endl;
                        if (a[ho][jo] == 1)
                            q.push(mk(ho, jo));
                    }
                }
                cl = 1;
                if (x.xx == u)
                {
                    if (x.yy < v)
                    {
                        ch[x.xx][x.yy] = '<';
                        ch[u][v] = '>';
                    }
                    else
                    {
                        ch[x.xx][x.yy] = '>';
                        ch[u][v] = '<';
                    }
                }
                else
                {
                    if (x.xx < u)
                    {
                        ch[x.xx][x.yy] = '^';
                        ch[u][v] = 'v';
                    }
                    else
                    {
                        ch[x.xx][x.yy] = 'v';
                        ch[u][v] = '^';
                    }
                }
            }
        }

    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ch[i][j] == '.')fl = 1;
        }
    }
    if (fl == 1)PC("Not unique\n");
    else
    {
        for (int i = 1; i <= n; i++)
        {
            PC("%s\n", ch[i] + 1);
        }
       // NL;
    }
    return 0;
}

