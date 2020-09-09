#include <iostream>
#include <algorithm>
#include <string>
#include  <queue>
#include <vector>
#include  <cstdio>
#include <cstring>
#include<map>
#include<cmath>
#include<set>
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
 

#define  mx 200004
#define base 193ll
 
typedef pair<int,int >P;
//////////////////////////
////////////////////////
#define F(i,a,b) for(int i=a;i<b; i++)
#define LL long long
#define MX  2000007
#define md 998244353ll
///////////////////////////
///////////////////////////
///
int tr[mx * 5];
int ar[mx + 2];
void seg(int no, int s, int e){
    if (s == e){
        tr[no] = ar[s];
        return;
    }
    int mid = ( s + e)/2;
    seg( no * 2, s , mid);
    seg(no * 2 + 1, mid + 1, e);
    tr[no] = max(tr[no * 2], tr[no * 2 + 1]);
}

int query(int no, int s, int e, int st, int en){
    if(s >= st && e <= en){
        return tr[no];
    }
    int mid = ( s + e) / 2;
    if( mid >= en)return query( no * 2, s, mid, st , en);
    else if( mid < st)return query(no * 2 + 1, mid + 1, e, st, en);
    else return max(query(no * 2, s, mid, st, mid) , query(no * 2 + 1, mid + 1, e, mid + 1, en));

}

int qu(int no, int s, int e, int st, int en, int koto){
    if(en < st)return 0;
    if(s >= st && e <= en){
       if(tr[no] <= koto)
            return e-s+1;
        if(s == e){
            return 0;
        }else {
            int mid = ( s + e)/2;
            if(tr[no * 2] <= koto) return (mid - s + 1) + qu(no * 2 + 1, mid + 1, e, st, en, koto);
            else return qu(no * 2, s, mid, st, mid , koto);
        }
    }
    int mid = ( s + e) / 2;
    if( mid >= en)return qu( no * 2, s, mid, st , en, koto);
    else if( mid < st)return qu(no * 2 + 1, mid + 1, e, st, en, koto);
    else {
        int val = query(no * 2, s, mid, st, mid);
        int val1 = query(no * 2 + 1, mid + 1, e, mid + 1, en);
        if( val <= koto) return qu(no * 2, s, mid, st, mid, koto) + qu(no * 2 + 1, mid + 1, e, mid + 1, en, koto);
        else return qu(no * 2, s, mid, st, mid, koto);
    }

}

int qu1(int no, int s, int e, int st, int en, int koto){
    //cout<<no<<" "<< s << " "<< e<<" " <<st<<" "<<en <<endl;
    if( en < st)return 0;
    if(s >= st && e <= en){
        if(tr[no] <= koto)
            return e-s+1;
        if(s == e){
            return 0;
        }else {
            int mid = ( s + e)/2;
            if(tr[no * 2 + 1] <= koto) return (e - mid) + qu1(no * 2, s, mid,  st, en, koto);
            else return qu1(no * 2 + 1, mid + 1, e, mid + 1, en, koto);
        }
    }
    int mid = ( s + e) / 2;
    if( mid >= en)return qu1( no * 2, s, mid, st , en, koto);
    else if( mid < st)return qu1(no * 2 + 1, mid + 1, e, st, en, koto);
    else {
        int val = query(no * 2, s, mid, st, mid);
        int val1 = query(no * 2 + 1, mid + 1, e, mid + 1, en);
        if( val1 <= koto) return qu1(no * 2 + 1, mid + 1, e, mid + 1 , en, koto) + qu1(no * 2, s, mid, st , mid, koto);
        else return qu1(no * 2 + 1, mid + 1, e, mid + 1, en, koto);
    } 

}
int main(){

    int tc, cs = 0;
    I(tc);

    while(tc --){
        int n, m;
        I2(n, m);
        for(int i = 1;i<=n-1;i++)I(ar[i]);
        seg(1, 1, n - 1);
        PC("Case #%d:", ++cs);
        for(int i = 1;i <= m;i++){
            int s, k;
            I2(s, k);
            k--;
            int lo = 0, hi = mx;
            int res = n + 1, res1 = n + 2;
            while(lo <= hi){
                int mid = (lo + hi) / 2;
                int ans = 0;
                int ko = qu(1, 1, n-1, s, n - 1, mid);
                int ko1 = qu1(1, 1, n-1, 1, s -1, mid);
                //cout<<mid<<" "<<ko<<" "<<ko1<<endl;
                if((ko + ko1) < k){
                    lo = mid + 1;
                    int ri = s + ko;
                    int le = s - ko1;
                    res = le , res1 = ri;
                }else {
                    hi  = mid - 1;
                }
            }
            PC(" ");
            if(k == 0)PI(s);
            else if(res == 1){
                PI(res + k);
            }
            else if(res1 == n){
                PI(res1 - k );
            }
            else if((res1- res + 2) == k + 1 ){
                if(ar[res-1] > ar[res1])PI(res1 + 1);
                else PI(res -1);
            }else {
                if(ar[res-1] > ar[res1]){
                    PI(res + k);
                }
                else PI(res1-k);
            }
        }
        NL;
    }
    
    return 0;
}
