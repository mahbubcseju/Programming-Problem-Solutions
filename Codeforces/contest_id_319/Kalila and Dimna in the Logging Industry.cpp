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
#define SZ(a) ((int)a.size())
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b) {
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M) {
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p);
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
template <class T>bool ISLEFT ( T a,T b,T c) {
    if(((a.xx-b.xx)*(b.yy-c.yy)-(b.xx-c.xx)*(a.yy-b.yy))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}


#define mx 500000
#define md 1000000007
#define maxp 2050180000

typedef pair<int ,int > P;

////////define value/////
ll Slope[mx+3];
ll Ci[mx+3];
bool Isbad(int l1,int l2,int l3) {
    return 1.0*(Ci[l3]-Ci[l1])*(Slope[l1]-Slope[l2]) <1.0*(Ci[l2]-Ci[l1])*(Slope[l1]-Slope[l3]);
}
ll A[mx+3];
ll B[mx+3];
int cnt;
void add(ll m,ll c)
{
    Slope[++cnt]=m;
    Ci[cnt]=c;
    while(cnt>=3&&Isbad(cnt-2,cnt-1,cnt))
    {
        Slope[cnt-1]=Slope[cnt];
        Ci[cnt-1]=Ci[cnt];
        cnt--;
    }
}
ll query(ll x)
{
    int lo=1;
    int hi=cnt;
    if(lo>hi)return 0;
    for(int i=1;i<=50&&lo<=hi;i++)
    {
        int dif=(hi-lo)/3;
        int mid1=lo+dif;
        int mid2=hi-dif;
        if(Slope[mid1]*x+Ci[mid1]<Slope[mid2]*x+Ci[mid2])
        {
            hi=mid2;
        }
        else lo=mid1;

    }
    ll ans=2e19;
    for(int i=max(lo-10,1);i<=min(hi+10,cnt);i++)
    {
        ans=min(ans,Slope[i]*x+Ci[i]);
    }
    return ans;


}

int main() {
    int n;
    I(n);
    for(int i=1; i<=n; i++) {
        L(A[i]);
    }
    for(int j=1;j<=n;j++)
    {
        L(B[j]);
    }
    ll res;

    for(int i=1;i<=n;i++)
    {
        res=query(A[i]);
        add(B[i],res);
    }
    PL(res);




    return 0;
}
