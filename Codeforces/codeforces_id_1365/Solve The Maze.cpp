#include <iostream>
#include <algorithm>
#include <string>
#include  <queue>
#include <vector>
#include  <cstdio>
#include <cstring>
#include<map>
#include<set>
#include <cmath>
#include<unordered_map>
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
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T mul(T p, T e, T M)
{
    ll ret = 0;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret + p) ;
        p = (p + p) ;
        if(ret>=M)ret-=M;
        if(p>=M)p-=M;
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
 
 
template <class T>bool ISLEFT(T a, T b, T c)
{
    if(((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1;  //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
 

#define  mx 2000000000000000ll
#define base 193ll
 
typedef pair<int,int >P;
//////////////////////////
////////////////////////
#define F(i,a,b) for(int i=a;i<b; i++)
#define LL long long
#define MX  10000000
#define md 998244353ll
///////////////////////////
///////////////////////////
///

int dx[] = {1, -1, 0, 0};
int dy[] = {0,0, 1, -1};
int main(){
    int tc;
    I(tc);

    while(tc--){
        int n, m;
        I2(n,m);
        char ar[n+3][m+3];

        for(int i = 1;i<=n;i++){
            SC("%s", ar[i] + 1);
        }
        bool fl = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(ar[i][j] == 'B'){
                    for(int k = 0;k<4;k++){
                        int x1 = dx[k] + i;
                        int y1 = dy[k] + j;

                        if(x1>=1 &&x1<=n && y1>=1&&y1<=m){
                            if(ar[i + dx[k]][j+dy[k]] == 'G')fl = 1;
                            if(ar[i + dx[k]][j+dy[k]] == '.' ){
                                    ar[i + dx[k]][j+dy[k]] = '#';
                            }
                        }
                    }
                }
            }
        }
        int vis[n+2][m+2];
        SETR(vis);
        if(ar[n][m] != '#')
         {
            queue<int>q;

            vis[n][m] = 1;
            q.push(n);
            q.push(m);
            while(!q.empty()){
                int x = q.front();
                q.pop();
                int y = q.front();
                q.pop();

                for(int j = 0;j<4;j++){
                    int x1 = dx[j] +x;
                    int y1 = dy[j] + y;
                    if(x1>=1&&x1<=n && y1>=1 && y1<=m && ar[x1][y1] != '#'&& vis[x1][y1] == -1){
                        vis[x1][y1] = 1;
                        q.push(x1);
                        q.push(y1);
                    }
                }
            }
        }
       

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(ar[i][j] == 'G' && vis[i][j] == -1)fl = 1;
            }
        }
        if(!fl) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}