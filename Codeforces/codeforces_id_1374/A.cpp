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
//#include<bits/stdc++.h>
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
int main(){
    int n, m, k;
    I3(n, m, k);

    pair<int, pair<int, int> > ar[n+2];
    pair<int, int> br[n+2];

    for(int i = 1;i<=n; i++ ){
        I3(ar[i].x, ar[i].yx, ar[i].yy);
        br[i] = mk(ar[i].x, i);
    }
    sort(br + 1, br + n + 1);

    set< pair<int, int> > a, b;

    vector<int>ans;
    int cnt = 0;
    int a1 = 0, b1 = 0;
    for(int i = 1; i <= n; i++){

        int x = br[i].y;
        int sz1 = a.size();
        int sz2 = b.size();

        if(cnt >= m && ar[x].yx && ar[x].yy) {

            if(sz1 > 0 && a1 < k && sz2 > 0 && b1 < k ){
                auto it = a.begin();
                auto it1 = b.begin();
                if((-(*it).first + -(*it1).first) >= br[i].x ) {
                    ans.push_back(x);
                    if( -(*it).first > -(*it1).first ) {
                        a.erase(it);
                    }else {
                        b.erase(it1);
                    }
                }
            }
            else if(sz1 > 0 && b1 < k){
                auto it = a.begin();
                a.erase(it);
                b1++;
                ans.push_back(x);
            }
            else if(a1 < k && sz2 > 0  ){
                auto it1 = b.begin();
                a1++;
                b.erase(it1);
                ans.push_back(x);
            }
        }

        if (cnt < m){
            if(ar[x].yx && ar[x].yy && a1 < k && b1 < k){
                ans.push_back(x);
                a1 ++;
                b1 ++;
                cnt ++;
            }else if(ar[x].yx && a1 < k){
                cnt++;
                a1++;
                a.insert(mk(-br[i].x, x));
            }else if(ar[x].yy && b1 < k){
                b1++;
                cnt++;
                b.insert(mk(-br[i].x, x));
            }
        }

    }

    for(auto it: a){
        ans.push_back(it.second);
    }
    for(auto it: b){
        ans.push_back(it.second);
    }

    int bro[n+2];
    SET(bro);
    for(int i = 0; i < ans.size(); i++){
        bro[ans[i]]++;
    }
    for(int i = 1;i<=n;i++){
        if(a1 >= k && b1 >= k && cnt < m && !bro[br[i].y]){
            ans.push_back(br[i].y);
            cnt++;
        }
    }

    if(ans.size() != m){
        PC("-1"), NL;
    }else {
        int sum = 0;
        for(int i = 0; i < ans.size(); i++){
            sum += ar[ans[i]].x;
        }
        PI(sum), NL;
        for(int i = 0; i < ans.size(); i++){
            if(i > 0)PC(" ");
            PI(ans[i]);
        }
        NL;
    }
    

    return 0;
}