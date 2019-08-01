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
#define mx 1000000
#define md 1000000007
#define maxp 2050180000

typedef pair<ll,ll> P;

////////define value/////
char a[mx+2];
char b[mx+2];
int main() {
    SC("%s",a+1);
    SC("%s",b+1);

    int ar[10+2];
    SET(ar);
    int br[10+2];
    SET(br);

    int l1=strlen(a+1);
    int l2=strlen(b+1);
    for(int i=1; i<=l1; i++) {
        ar[a[i]-'0']++;

    }
    for(int i=1; i<=l2; i++) {
        br[b[i]-'0']++;

    }
    int cr[12];
    int re=0;
    for(int j=1; j<=l1; j++) {
        //cout<<j<<endl;
        SET(cr);
        int x=j;
        re=0;
        while(x) {
            cr[x%10]++;
            x/=10;
            re++;
        }
        int sum=0;
        for(int i=0; i<=9; i++) {
            cr[i]=ar[i]-cr[i];
            sum+=cr[i];
            cr[i]-=br[i];
        }
        if(sum!=j)continue;
        //cout<<cr[0]<<" "<<re<<endl;
        if(cr[0]+br[0]+re==l1&&br[0]==l2) {
            //  lol;
            for(int i=0; i<=cr[0]; i++)cout<<0;
            NL;
            return 0;
        }

        int fl=0;
        if(b[1]>'0')fl=1;
        for(int i=0; i<=9; i++) {
            if(cr[i]<0) {
                fl=0;
                break;
            }
            if(i>0&&cr[i]>0)fl=1;
        }
        if(fl) {
            break;
        }
    }






    string s;
    for(int i=1; i<=9; i++) {
        if(cr[i]>0) {
            s+=('0'+i);

            cr[i]--;
            break;

        }
    }

    for(int i=0; i<=9; i++) {
        for(int j=1; j<=cr[i]; j++)
            s+=('0'+i);


    }

    string h=s;
    if(b[1]!='0') {
        sort(h.begin(),h.end());
        h=(b+1)+h;
        //lol;
    } else {
        h=h+(b+1);

    }
   // cout<<h<<endl;
//cout<<s<<endl;
    string h1;
    for(int i=0; i<s.size(); i++) {

        if(s[i]>=b[1]&&i!=0) {
            h1+=(b+1);
            for(int j=i; j<s.size(); j++)h1+=s[j];
            break;
        }
        h1+=s[i];
    }
   // cout<<h1<<endl;
   if(h1.size()!=h.size()||h1[0]=='0')h1=h;
    string h2=h1;
    int ind=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]<=b[1]) {
            ind=i;


        }
    }
    if(ind) {
            h2="";
        for(int j=0; j<s.size(); j++) {
            h2+=s[j];
            if(j==ind)h2+=(b+1);
        }
    }
    if(h2.size()!=h.size()||h2[0]=='0')h2=h;
    //cout<<h2<<endl;
    h=min(h,h1);
    h=min(h,h2);
    cout<<h<<endl;



    return 0;
}
