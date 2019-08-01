#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ull unsigned long long int
#define LL long long
#define ULL unsigned long long

#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define SC scanf
#define PC printf
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define SS(s)                       scanf("%s",s)

#define I(X )                       scanf("%d",&X)
#define II(X, Y)                    scanf("%d%d",&X,&Y)
#define III(X, Y, Z)                scanf("%d%d%d",&X,&Y,&Z)
#define DI(X)                       int X;        I(X);
#define DII(X, Y)                   int X, Y;     II(X,Y)
#define DIII(X, Y, Z)               int X, Y, Z;  III(X,Y,Z);

#define IL(X )                       scanf("%lld",&X)
#define IIL(X, Y)                    scanf("%lld%lld",&X,&Y)
#define IIIL(X, Y, Z)                scanf("%lld%lld%lld",&X,&Y,&Z)

#define DIL(X)                       LL X;        IL(X);
#define DIIL(X, Y)                   LL X, Y;     IIL(X,Y)
#define DIIIL(X, Y, Z)               LL X, Y, Z;  IIIL(X,Y,Z);

#define f(i,n) for(i=0;i<n;i++)
#define fl(c,i,n) for(i=c;i<n;i++)
#define fr(i,a,b) for(int i=a;i<=b; i++)
#define frr(i,a,b) for(int i=a;i>=b; i--)
#define rep(i,a,b)                  for(int i=a;i<=b;i++)
#define rev(i,a,b)                  for(int i=a;i>=b;i--)
#define repv(i,a)                   for(int i=0;i<(int)a.size();i++)
#define revv(i,a)                   for(int i=((int)a.size())-1;i>=0;i--)

#define mk make_pair
#define MP make_pair
#define pb push_back
#define PB push_back
#define aov(a) a.begin(),a.end()
#define all(a)                      a.begin(),a.end()

#define endl '\n'
#define Endl '\n'
#define nl puts("")
#define NL printf("\n")

#define PI (2.0*acos(0.0))
//#define PI acos(-1.0)

#define dbg(x) cerr<<#x<<" : "<<x<<endl
#define lol cerr<<"BUG\n";
#define pline                       cerr << "_________________________" << endl;
#define T(a)                        cerr << #a << ": " << a << endl;
#define TT(a,b)                     cerr << #a << ": " << a << " | " << #b << ": " << b << endl;

template <class T> inline T bigmod(T p,T e,T M) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T bpow(T p,T e) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T> inline T modinverse(T a,T M) {
    return bigmod(a,M-2,M);
}   /// M is prime
template <class T> inline T gcd(T a,T b) {
    if(b==0)return a;
    return gcd(b,a%b);
}

///int mnth[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int dx[]={-1,+1,0,1,0,-1}; // Hexagonal Direction   **
///int dy[]={-1,+1,1,0,-1,0}; //                       *#*
///                                                     **
///const double eps=1e-9;

/// 	   0123456789ABCDEF

///////////////////////////////////////

#define M  100002
ll ar[M+2];
ll cum[M+2];
//int ar[100005];
int dp[100005];

struct z {
    int st,ed,id,sq;
    bool operator<(const z &p) const {
        if(sq<p.sq)     return true;
        else if(sq==p.sq) {
            if(ed<p.ed) return true;
            else if(ed==p.ed)   return (st<p.st);
        }
        return false;
    }
};

z a[100005];

LL Ans;

//int n,m,k,F[MX];
ll ans[M+2];
int pat[M+2];
ll mp[M*3+2];
ll ara[M*3+2];
ll ino[M*3+2][3];
int main() {
    int n,m;
    I2(n,m);
    for(int i=1; i<=n; i++)
        I(pat[i]);

    int l=0;

    ara[++l]=cum[0];
    ara[++l]=-m;
    ara[++l]=+m;
    fr(i,1,n) {
        L(ar[i]);
        if(pat[i]==2)ar[i]*=-1;
        cum[i]=ar[i]+cum[i-1];
        ara[++l]=cum[i];
        ara[++l]=cum[i]-m;
        ara[++l]=cum[i]+m;
    }
    sort(ara+1,ara+l+1);

    for(int i=0;i<=n;i++)
    {
        ino[i][0]=lower_bound(ara+1,ara+l+1,cum[i])-ara;
        ino[i][1]=lower_bound(ara+1,ara+l+1,cum[i]-m)-ara;
        ino[i][2]=lower_bound(ara+1,ara+l+1,cum[i]+m)-ara;
    }

    int sq=sqrt(n);
    int q;
    I(q);
    for(int i=1; i<=q; i++) {
        cin>>a[i].st>>a[i].ed;
        a[i].sq=(a[i].st /sq)+(a[i].st%sq!=0);
        a[i].id=i;
    }
    sort(a+1,a+q+1);
   // map<ll,ll>mp;
    int left=1,right=2;
    mp[ino[0][0]]++;
    mp[ino[1][0]]++;
    if(cum[1]==m)Ans++;
    for(int i=1; i<=q; i++) {
        int L=a[i].st,R=a[i].ed;
        //  cerr<<L<<" "<<R<<" "<<left<<" "<<right<<endl;
        while(left<L) {
           //ll x=cum[left-1];
           // mp[x]--;
           mp[ino[left-1][0]]--;
            Ans-= mp[ino[left-1][2]];
            // cerr<<x<<" 1 "<<(x+m)<<mp[x+m]<<endl;
            left++;
        }
        while(left>L) {
            // cerr<<" 2"<<endl;
           // Ans+=mp[cum[left-2]+m];
           Ans+=mp[ino[left-2][2]];
            mp[ino[left-2][0]]++;
            left--;
        }
        while(right<=R) {
            //Add(right);
            Ans+=mp[ino[right][1]];
            // cerr<<Ans<<endl;
            //cerr<<" 3"<<" "<<cum[right]<<" "<<mp[cum[right]]<<endl;
            mp[ino[right][0]]++;
            right++;
        }
        while(right-1>R) {
            //cerr<<" 4"<<endl;
            mp[ino[right-1][0]]--;
            Ans-=mp[ino[right-1][1]];
            right--;
        }
        ans[ a[i].id ]=Ans;
//        getchar();
//        getchar();
    }
    for(int i=1; i<=q; i++) {
        printf("%lld\n",ans[i]);
    }
    return 0;
}

/*
10 10
2 1 1 1 1 1 1 1 1 2
0 10 10 0 0 10 10 10 10 0
10
4 10
3 7
9 9
2 9
10 10
5 5
2 2
6 8
3 4
1 3
l
7
7
1
10
0
0
1
3
2
3
*/
