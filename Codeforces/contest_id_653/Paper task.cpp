
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
template <class T> inline T BM(T p, T e, T M) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M) {
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p);
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
template <class T>bool ISLEFT ( T a, T b, T c) {
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}


#define mx 1000000
#define md 1000000007
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29
#define MX 200000


typedef pair<int , int > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////

char a[mx+2];

struct node {

    int info;
    int l,r;
    node() {
        info=0,l=0,r=0;
    }

};
node ar[mx*30+2];
int sz;
void insert(int cur,int pre,int s,int e,int in) {

    if(s==e&&in==e) {
        ar[cur].info=1;
        return;
    }
    int mid=(s+e)/2;
    if(in<=mid) {
        ar[cur].r=ar[pre].r;
        ar[cur].l=++sz;
        insert(ar[cur].l,ar[pre].l,s,mid,in);
    } else {
        ar[cur].l=ar[pre].l;
        ar[cur].r=++sz;
        insert(ar[cur].r,ar[pre].r,mid+1,e,in);
    }

    ar[cur].info=ar[ar[cur].l].info+ar[ar[cur].r].info;
}
int qu(int cur,int s,int e,int st,int en) {


    if(s>=st&&e<=en)return ar[cur].info;

    int mid=(s+e)/2;
    if(mid>=en)
        return qu(ar[cur].l,s,mid,st,en);
    else if(mid<st)
        return qu(ar[cur].r,mid+1,e,st,en);
    else return qu(ar[cur].l,s,mid,st,mid)+qu(ar[cur].r,mid+1,e,mid+1,en);

}
const int N = mx;

struct SUFFIX_ARRAY {
    int wa[N],wb[N],ws[N],wv[N],r[N];
    int len; // length of the string

    int rank[N]; // here rank said in which position a suffix is situated in the sorted suffix list.
    int height[N];
    //Height gives the lcp of sa[i] ans sa[i-1] So index height[1] contains the lcp of sa[1] and and sa[0]

    int sa[N]; //sa gives the sorted suffix indexes (staring index)//Index zero te always  strlen tomo adress thake
    // abc
    //er jonno 3 0 1 2

    int cmp(int *ar,int a,int b,int l) {
        return (ar[a]==ar[b]) && (ar[a+l]==ar[b+l]);
    }

    void DA(int n,int m) {
        int i,j,p,*x=wa,*y=wb,*t;
        for(i=0; i<m; i++) ws[i]=0;
        for(i=0; i<n; i++) ws[x[i]=r[i]]++;
        for(i=1; i<m; i++) ws[i]+=ws[i-1];
        for(i=n-1; i>=0; i--) sa[--ws[x[i]]]=i;
        for(j=1,p=1; p<n; j*=2,m=p) {
            for(p=0,i=n-j; i<n; i++) y[p++]=i;
            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0; i<n; i++) wv[i]=x[y[i]];
            for(i=0; i<m; i++) ws[i]=0;
            for(i=0; i<n; i++) ws[wv[i]]++;
            for(i=1; i<m; i++) ws[i]+=ws[i-1];
            for(i=n-1; i>=0; i--) sa[--ws[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
                x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
            //printf("p = %d\n", p );
        }
    }

    void calheight(int n) {
        //  memset(height,0,sizeof(height));
        //  memset(rank,0,sizeof(rank));
        int i,j,k=0;
        for(i=1; i<=n; i++) rank[sa[i]]=i;
        for(i=0; i<n; height[rank[i++]] = k )
            for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
    }

    void generate(char *s) {
        int n;
        for (n=0; s[n] ; n++) r[n]=(int)s[n];
        r[n]=0;
        this->len  = n;

        DA(n+1,128);
        calheight(n);
    }
    // create sparse table in height array


} SA;
int root[mx+2];
    stack< int  >st;
int main() {
    int n;
    I(n);
    SC("%s",a);



    int in=0;


    for(int i=n-1; i>=0; i--) {
        if(st.size()==0) {
            st.push(i);
        } else if(a[i]=='('&&a[st.top()]==')') {
            in=st.top();
            root[i]=++sz;
          //  cout<<i<<" "<<in<<endl;
            insert(root[i],root[in+1],0,n-1,in);
            st.pop();

        } else st.push(i);
    }


    SA.generate(a);
   // lol;
    ll res=0;
    fr(i,1,n) {
        int x=SA.height[i];
        int in=SA.sa[i];
       // cout<<in<<" "<<in+x<<" "<<n<<endl;

        res+=qu(root[in],0,n-1,0,n-1);
        if(in+x-1>=0&&in+x-1<n)
        res-=qu(root[in],0,n-1,0,in+x-1);
    }
    PL(res);
    NL;


    return 0;
}
