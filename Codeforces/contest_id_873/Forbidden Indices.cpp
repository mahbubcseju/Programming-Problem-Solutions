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


template <class T>bool ISLEFT(T a, T b, T c) {
    if(((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1;  //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

#define md 2100000007ll
#define  mx 200004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
////////////////////////


const int N = 200004;

struct SUFFIX_ARRAY {
    int wa[N],wb[N],ws[N],wv[N],r[N];
    int len; // length of the string

    int rank[N]; // here rank said in which position a suffix is situated in the sorted suffix list.
    int height[N];
    //Height gives the lcp of sa[i] ans sa[i-1] So index height[1] contains the lcp of sa[1] and and sa[0]

    int sa[N]; //sa gives the sorted suffix indexes (staring index)//Index zero te always  strlen tomo adress thake
    // abc
    //er jonno 3 0 1 2

    int dp[N][21]; // for LCP

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
        for(i=0; i<n; height[rank[i++]] = k)
            for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
    }

    void generate(char *s) {
        int n;
        for(n=0; s[n] ; n++) r[n]=(int)s[n];
        r[n]=0;
        this->len  = n;
        DA(n+1,128);
        calheight(n);
    }
    // create sparse table in height array
    void sparse_table() {
        int n =  len+1;
        for(int i=0; i<n; i++) dp[i][0]=height[i];
        for(int j=1; (1 << j) <= n; j++)
            for(int i = 0; i+(1 << j)-1<n; i++)
                dp[i][j] = (dp[i][j-1]<=dp[ i+(1<<(j-1)) ][j-1])? dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
    }

    // start/end , the suffix that situated at start/end index after suffix sort
    // RMQ(find minimum value)
    int find_lcp(int start,int end) {
        if(start>end) swap(start,end);
        start++;
        int diff=end-start;
        diff=31 - __builtin_clz(diff+1);
        return dp[start][diff]<=dp[end-(1<<diff)+1][diff]?dp[start][diff]:dp[end-(1<<diff)+1][diff];
    }

    // find lcp of s and e th suffix of original string
    int get_lcp(int s,int e) {
        return find_lcp(rank[s],rank[e]);
    }

    void print() {
        cout << "length :  " << len << endl;
        cout << "s[n] = '$' " << endl;
        cout << "sorted suffix index(0 based) : " << endl;
        for(int i=0; i<=len; i++) cout << sa[i] << " , ";
        cout << endl;
        cout << "rank of suffix " << endl;
        for(int i=0; i<=len; i++)  cout << rank[i] << " , ";
        cout << endl;
        cout << "LCP between i and i-1 " << endl;
        for(int i=0; i<=len; i++)  cout << height[i] << " , ";
        cout << endl;
    }

} SA;
char a[mx+2];
char pa[mx+2];
int main() {
    int n;
    I(n);
    SC("%s",a);
    SC("%s",pa);
    int l=strlen(pa);
    reverse(a,a+l);
    reverse(pa,pa+l);
    SA.generate(a);
    SA.sparse_table();
    int dp[l+2];
    SET(dp);
    fr(i,1,l) {
        dp[i]=dp[i-1]+(1-pa[SA.sa[i]]+'0');
    }
    ll res=0;
    for(int i=1; i<=l; i++) {
        if(pa[SA.sa[i]]=='0')res=max(res,(ll)l-SA.sa[i]);
        if(i<l) {
            int in=i;
            int in1=i;
            int ma=SA.height[i+1];
            int lo=1;
            int  hi=i-1;

            //cerr<<lo<<" "<<hi<<" "<<ma<<endl;
            while(lo<=hi) {
                int mid=(lo+hi)/2;
                int io=SA.sa[mid];
                if(SA.find_lcp(mid,i)>=ma)
                {
                    hi=mid-1;
                    in=mid;
                }
                else lo=mid+1;
            }


            lo=i+1;
            hi=l;
            while(lo<=hi) {
                int mid=(lo+hi)/2;
                int io=SA.sa[mid];
                if(SA.find_lcp(mid,i)>=ma)
                {
                    lo=mid+1;
                    in1=mid;
                }
                else hi=mid-1;
            }
            //cerr<<in<<" "<<in1<<" "<<SA.sa[i]<<" "<<ma<<Endl;
            ll ko=dp[in1]-dp[in-1];
           // cerr<<ko<<" "<<ma<<endl;
            res=max(res,ko*ma);
        }
    }
    PL(res),NL;
    return 0;
}
