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
#define mx 50000
#define md 1000000007
#define maxp 2050180000

typedef pair<int ,int > P;

////////define value/////
char a[5005];
int n;
int tab[5002][5002];
struct da {
    int info,in;
    int ar[2];
    da() {
        info=0;
        in=0;
        SETR(ar);
    }

};
da node[5000*5000+2];
int st=0;
int l;
int  t[5000+2];
void insert(int i) {
    int cur=0;

    for(int f=i; t[f]; f++) {
        if(node[cur].ar[a[f]-'a']==-1) {
            node[cur].ar[a[f]-'a']=++st;
        }
        //cout<<cur<<" "<<node[cur].ar[a[f]-'a']<<endl;
        cur=node[cur].ar[a[f]-'a'];
        node[cur].info+=t[f];
        if(tab[i][f]){node[cur].in++;
       // cout<<"lol"<<cur<<endl;
        }
      //  if(i==4)cout<<a[f]<<endl;
    }


}
void insert(int i,int j) {
    int cur=0;
    for(int f=i; f<=j; f++) {
        if(node[cur].ar[a[f]-'a']==-1) {
            node[cur].ar[a[f]-'a']=++st;
        }
        cur=node[cur].ar[a[f]-'a'];
        node[cur].info++;
    }
    node[cur].in++;

}
void  ans(int cur,int val) {
    // lol;
    //cout<<val<<endl;
    string s;
    while(cur>-1) {
        val-=node[cur].in;
        for(int i=0; i<=1; i++) {
            if(node[cur].ar[i]==-1)continue;

            if(node[node[cur].ar[i]].in>=val) {
                s+=(char)('a'+i);
                cur=-1;
                break;
            } else if(node[node[cur].ar[i]].info>=val) {
                s+=(char)('a'+i);
                int x=cur;
                cur=node[cur].ar[i];
                break;
            } else {
                val-=node[node[cur].ar[i]].info;
            }
        }
    }
    cout<<s;

}
int main() {

    SC("%s%d",a+1,&n);
    l=strlen(a+1);
    for(int i=l; i>=1; i--) {
        tab[i][i]=1;
        if(a[i+1]==a[i])tab[i][i+1]=1;
        if(a[i]==a[i+2])tab[i][i+2]=1;
        if(a[i]==a[i+3])tab[i][i+3]=1;

        for(int j=i+4; j<=l; j++) {
            if(i+2<=j-2&&a[i]==a[j]) {
                tab[i][j]=tab[i+2][j-2];
                // if(tab[i][j])t[i][j]=1;
            }
        }


    }

    //assert(l<=100);
//
    for(int i=1; i<=l; i++) {
            SET(t);
            for(int j=l; j>=i; j--) {
            t[j]=tab[i][j]+t[j+1];
        }
        insert(i);

        }

//for(int i=1;i<=l;i++)
//    for(int j=1;j<=l;j++)
//    if(tab[i][j])insert(i,j);



    ans(0,n);


    return 0;
}
