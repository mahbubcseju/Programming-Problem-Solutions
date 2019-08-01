/********************************************
*                                           *
*    Solved By : Bir Bahadur Khatri(B'ru)   *
*      Be Positive,be Happy.                *
*                                           *
*********************************************/

#define ff first
#define D double
#define sz size()
#define ss second
#define PB push_back
#define MP make_pair
#define SQR(n) (n*n)
#define CHR getchar()
#define NL printf("\n")
#include<bits/stdc++.h>
#define ULL unsigned LL
#define PI 2.0*acos(0.0)
#define LL long long int
#define S1(a) a=in<int>()
#define SL1(a) a=in<LL>()
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define all(a) a.begin(),a.end()
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define SL2(a,b) a=in<LL>(),b=in<LL>()
#define F(i,a,b) for(int i=a;i<b; i++)
#define S2(a,b) a=in<int>(),b=in<int>()
#define R(i,a,b) for(int i=a-1;i>=b; i--)
#define BitCnt(a) __builtin_popcountll(a)
#define MEM(a,val) memset(a,val,sizeof(a))
#define SL3(a,b,c) a=in<LL>(),b=in<LL>(),c=in<LL>()
#define S3(a,b,c) a=in<int>(),b=in<int>(),c=in<int>()
#define _cin ios_base::sync_with_stdio(0); cin.tie(0)
#define cp printf("***** here here here here *****\n");
#define trace1(x)                cerr << #x << ": " << x << endl;
#define InpOut freopen("A.in","r",stdin),freopen("A1.out","w",stdout)
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

using namespace std;
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
template<typename T>inline T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template<typename T>inline T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template<typename T>inline T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
long long Bigmod(long long base, long long power, long long MOD){long long ret=1;while(power){if(power & 1)ret=(ret*base)%MOD;base=(base*base)%MOD;power>>=1;}return ret;}
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
template <typename T> LL isLeft(T a,T b,T c) {return(a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);}
long long ModInverse(long long number, long long MOD){return Bigmod(number, MOD-2, MOD);}
bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
///**********************************************************//

#define MD1 1000000007ULL
#define MD2 1000000009ULL
#define MD3 1000000021ULL
#define BS1 10000019ULL
#define BS2 10000079ULL
#define BS3 10000103ULL
#define PUL pair<ULL,ULL>
#define PLL pair<LL,LL>
#define PII pair<int,int>

///         0123456789
#define MX  200007
#define MOD 1000000007
#define INF 2000000000
#define EPS 1e-9


/// ==========================================////

string S[1002];
int a[MX];
int n,m;

string Make(string s,string p) {
    string ans;

    F(i,0,s.sz){
        if( s[i]==p[i] ) {
            ans+=s[i];
        }
        else ans+='?';
    }
    return ans;
}
int vis[1002];

int Mile(string s,string p) {
//    cout<<s<< " "<<p<<endl;
    if(s.sz!=p.sz) return 1;
    F(i,0,s.sz) {
        if(s[i]=='?') continue;
        if(s[i]==p[i]) continue;
        return 1;
    }
    return 0;
}

int OK(string s) {
    F(i,1,n+1) {
        if(!vis[i]) {
            if(!Mile(s,S[i])) {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    cin>>n>>m;

    F(i,1,n+1) cin>>S[i];

    F(i,1,m+1) {cin>>a[i];vis[ a[i] ]=1;}

    string s=S[ a[1] ];

    for(int i=2;i<=m;i++) {
        string p=S[ a[i] ];
        if(s.sz!=p.sz) {
            printf("No\n"); return 0;
        }
        s=Make(s,p);
    }
//    cout<<s<<endl;
    if(OK(s)) {
        printf("Yes\n");
        cout<<s<<endl;
    }
    else{
        printf("No\n");
    }

    return 0;
}
///============= Thank You ===================///
