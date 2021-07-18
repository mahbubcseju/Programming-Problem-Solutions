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
 

#define  mx 200004
#define base 193ll
 
typedef pair<int,int >P;
//////////////////////////
////////////////////////
#define F(i,a,b) for(int i=a;i<b; i++)
#define LL long long
#define MX  100007
#define md 998244353ll
///////////////////////////
///////////////////////////
int tree[MX * 4];
int lazy[MX * 4];
inline void relax(int node,int ss,int se) {
    int k = lazy[node];
    if(k) {
        tree[node]^= lazy[node];
        if(ss^se) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}
inline void update(int node,int ss,int se,int qs,int qe,int d) {
    relax(node,ss,se);

    if(ss > qe || se < qs || ss > se || qs > qe) return;

    if(ss >= qs && se <= qe) {
        lazy[node] ^= d;
        relax(node,ss,se);
        return;
    }
    int p = (node<<1);
    int q = p|1;
    int mid = (ss+se)>>1;
    update(p,ss,mid,qs,qe,d);
    update(q,mid+1,se,qs,qe,d);
    tree[node] = tree[p] ^ tree[q];
}

inline int query(int node,int ss,int se,int qs,int qe) {
    if(ss > qe || se < qs || ss > se || qs > qe) return 0;
    relax(node,ss,se);
    if(ss >= qs && se <= qe) {
        return tree[node];
    }
    int p = (node<<1);
    int q = p|1;
    int mid = (ss+se)>>1;
    int pp = query(p,ss,mid,qs,qe);
    int qq = query(q,mid+1,se,qs,qe);
    return pp ^ qq;
}


int bit[MX + 2];

void add(int in) {
    while(in <= MX){
        bit[in] ++;
        in += in & -in;
    }
}


int query_b(int in) {
    int sum = 0;
    while( in > 0) {
        sum += bit[in];
        in -= in & -in;
    }
    return sum;
}

int main(){
    int tc;
    I(tc);
    while(tc--){
        int n;
        I(n);
        int ar[n + 2];
        priority_queue< pair<int, int> > pq;
        for(int i = 1; i <= n;i++){
            I(ar[i]);
            pq.push(mk(ar[i], i));
        }

        int pos[n + 2];
        SET(pos);
        int ptr = n;


        vector<pair<int, int> > ans;

        while(ptr > 0){
            if(pos[ptr] == 1){
                ptr --;
                continue;
            }

            pair<int, int> to = pq.top();
            pq.pop();

            pos[to.second] = 1;
            int co = query(1, 1, n, to.second, to.second);
            update(1, 1, n, to.second, n, 1);
            add(to.second);

            int koto = (n - to.second + 1) - query_b(MX) + query_b(to.second - 1);
            koto %= 2;
            // cout<<to.first<<" "<<koto<< " "<<co<<endl; 
            ans.PB(mk(to.first, koto ^ co));
        }

        reverse(ans.begin(), ans.end());

        bool fl = 0;
        for(int i = 0; i < ans.size(); i++){
            if(ans[i].second == 1  ){
                if(i + 1 < ans.size() && ans[i].first == ans[i + 1].first){
                    ans[i].second  ^= 1;
                    ans[i+1].second ^= 1;
                }else fl = 1;
            }
        }

        if(fl)PC("NO\n");
        else PC("YES\n");

        SET(bit);
        SET(tree);
        SET(lazy);

    }
    return 0;
}