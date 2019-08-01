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
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define Endl "\n"
#define mk make_pair
using namespace std;

#define md 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29
#define mx 100003

typedef pair<int ,int > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////


int main()
{

   int n;
   I(n);

   char ar[n+2];
   ar[0]='0';
   ar[1]='a';
   cout<<'a';
   for(int i=2;i<=n;i++)
   {
       for(char j='a';j<='z';j++)
       {
           if(ar[i-2]!=j){

            ar[i]=j;
            break;
           }
       }
       PC("%c",ar[i]);
   }
   NL;

    return 0;
}
