/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
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
#define mx 100000
#define md 1000000007ll
#define maxp 2050180000

typedef pair<ll,ll> P;

////////define value/////
int n;
ll a[mx+2];
vector<int>v[mx+2];
ll lgt[mx+2],sub[mx+2];
void dfs(int in,int p) {
    lgt[in]=a[in];
    sub[in]=a[in];
    set<pair<ll,int> >st;
    for(int j=0; j<v[in].size(); j++) {
        int x1=v[in][j];
        if(x1==p)continue;
        dfs(x1,in);
        lgt[in]=max(lgt[in],a[in]+lgt[x1]);
        sub[in]=max(sub[in],sub[x1]);
        st.insert(mk(lgt[x1],x1));

    }
    ll xl=0;

    if(st.size()>0) {

        xl=st.rbegin()->x;
        int xl1=st.rbegin()->y;
        st.erase(mk(xl,xl1));

    }
    if(st.size()>1) {
        xl+=st.rbegin()->x;
    }
    sub[in]=max(sub[in],xl+a[in]);



}
ll res;

void dfs2(int in,int p,ll fir,ll up) {

     ll ar[3];
    SET(ar);
    for(int i=0; i<v[in].size(); i++) {
        int x1=v[in][i];
        if(x1==p)continue;
        ar[0]=lgt[x1];
        sort(ar,ar+3);

    }
    res=max(res,fir+a[in]+ar[1]+ar[2]);

    //  if(res==5217183857)cout<<in<<endl;

    set< pair<ll,int> >st;
    set< pair<ll,int> >st1;
    st.insert(mk(up,-1));
    st1.insert(mk(fir,-1));

    for(int i=0; i<v[in].size(); i++) {
        int x1=v[in][i];
        if(x1==p)continue;
        st.insert(mk(lgt[x1],x1));
        st1.insert(mk(sub[x1],x1));
    }



    for(int i=0; i<v[in].size(); i++) {
        int x1=v[in][i];
        if(x1==p)continue;
        st.erase(mk(lgt[x1],x1));
        st1.erase(mk(sub[x1],x1));
        set<pair<ll,int> >::iterator it=st.end();
        ll arr=st1.rbegin()->x;
        ll x2=0;
        ll kol=0;
        if(st.size()>0) {
            it--;
            x2+=(*it).first;
            kol=x2+a[in];
        }
        if(st.size()>1) {

            it--;
            x2+=(*it).first;
        }
        x2+=a[in];

        dfs2(x1,in,max(arr,x2),kol);

        st.insert(mk(lgt[x1],x1));
        st1.insert(mk(sub[x1],x1));


    }
}
int main() {
    I(n);
    ll ans=0;
    for(int i=1; i<=n; i++)L(a[i]),ans+=a[i];
    // cout<<ans<<endl;
    for(int i=1; i<n; i++) {
        int x1,y;
        I2(x1,y);
        v[x1].PB(y);
        v[y].PB(x1);
    }
    res=0;

    dfs(1,0);
    dfs2(1,0,0,0);
    PL(res);

    return 0;
}
