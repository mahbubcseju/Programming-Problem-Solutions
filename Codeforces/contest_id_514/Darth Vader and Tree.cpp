/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
#include<bits/stdc++.h>
#define I int
#define ll long long int
#define ull unsigned long long int
#define D double
#define SL(a) scanf("%d",&a)
#define SL2(a,b) scanf("%d%d",&a,&b)
#define SL3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define S(a) scanf("%lld",&a)
#define S2(a,b) scanf("%lld%lld",&a,&b)
#define S3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PL(a) printf("%d\n",a)
#define P(a) printf("%lld\n",a)
#define PT(t) printf("Case %lld: ",t)
#define FL(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FLR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define F(J,a,b) for(long long J=a;J<=b;J++)
#define FR(J1,a,b) for(long long J1=a;J1>=b;J1--)
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PB(a) push_back(a)
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
#define pi 2.0*acos(0.0)
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
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T MDINV(T a, T M)
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
#define mx 100004ll
#define md 1000000007ll
typedef pair<ll , ll >P;
typedef vector<ll>V;

////////define value/////]);
ll n,m;
ll co[103];
ll DP[103];
//ll matr[103][103];
ll dp(ll x)
{
    ll &ret=DP[x];
    if(ret!=-1)return ret;
    ret=1;
    for(ll i=1; i<=100&&(x-i)>=0; i++)
    {
        if(co[i]!=0)
        {
            ret=(ret+co[i]*dp(x-i))%md;
        }
    }
    return ret;

}
const ll SZ = 102;
struct matr
{
    ll M[SZ][SZ];
    void ZERO()
    {
        for(ll i=0; i<SZ; ++i)
            fill(M[i] , M[i] + SZ , 0);
    }
    void ONE()
    {
        ZERO();
        for(ll i=0; i<SZ; ++i)
            M[i][i] = 1;
    }
    matr mul(const matr& w)
    {
        matr ret;
        ret.ZERO();
        for(ll i=0; i<SZ; ++i)
            for(ll j=0; j<SZ; ++j)
                for(ll k=0; k<SZ; ++k)
                {
                    ret.M[i][j] += (M[i][k] *1LL* w.M[k][j])%md;
                    if(ret.M[i][j] >= md)
                        ret.M[i][j] -= md;
                }
        return ret;
    }
};
matr POW(matr w , ll step)
{
    matr ret;
    ret.ONE();
    for(; step > 0ll; step >>= 1ll , w = w.mul(w))
        if(step&1ll) ret = w.mul(ret);
    return ret;
}
matr M;
int main()
{
    ll x;
    S2(n,m);
    for(ll i=1; i<=n; i++)
    {
        S(x);
        co[x]++;
    }
    SETR(DP);
    ll ans=dp(100);
    if(m<=100)
    {
        ans=dp(m);
        P(ans);
    }
    else
    {
        //cout<<m<<endl;
        for(ll i=100; i>=1; i--)dp(i);
        //ll A[103][103];
        //SET(A);
        M.ZERO();

        M.M[1][101]=1;
        for(ll i=1; i<=100; i++)
        {

            if(co[i]!=0)
            {

                M.M[1][i]=co[i];
            }
        }
        for(ll i=2; i<=100; i++)
        {
            M.M[i][i-1]=1;
        }
        M.M[101][101]=1;
        ll ro=m-100;
        // cout<<ro<<endl;

//            for(ll j=1;j<=101;j++){
//                cout<<A[1][j];
//            }


//        // cout<<ro<<endl;
       // matex(A,ro);
       M = POW(M ,  ro);
        ll ok=0;
        //DP[0]=1;
        // cout<<DP[0]<<endl;
        for(ll i=1; i<=101ll; i++)
        {
            ok=(ok+M.M[1][i]*DP[101-i])%md;
        }
        P(ok);

    }


    return 0;
}

