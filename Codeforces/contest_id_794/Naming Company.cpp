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
template <class T> inline T BM(T p, T e, T M)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if (b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M)
{
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1) ret = (ret * p);
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
template <class T>bool ISLEFT ( T a, T b, T c)
{
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 300000ll
#define md 23377788ll
#define md1 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<int,int >P;
//////////////////////////
/////////////////////////

char a[mx+2];
char b[mx+2];
int main()
{
    SC("%s%s",a+1,b+1);



    int l=strlen(a+1);
    sort(a+1,a+l+1);
    sort(b+1,b+l+1);
    reverse(b+1,b+l+1);

    int ar[27];
    int br[27];
    SET(ar);
    SET(br);
    int l1=(l+1)/2;
    for(int i=1; i<=l1; i++)
    {
        ar[a[i]-'a'+1]++;

    }

    for(int i=1;i<=l/2;i++)
    {
          br[b[i]-'a'+1]++;
    }

    int st=1,en=l;
    char bl[l+2];

    bool fl1=0;
    while(st<=en)
    {
        if(fl1==0)
        {
            int x=0;
            fr(i,1,26)
            {
                if(ar[i])
                {
                    x=i;
                    break;
                }
            }

            bool fl=0;

            for(int j=x+1; j<=26; j++)
            {
                if(br[j])fl=1;
            }

            if(!fl)
            {
                for(int j=26; j>=1; j--)
                {
                    if(ar[j])
                    {
                        ar[j]--;
                        bl[en--]='a'+j-1;
                        break;
                    }
                }

            }
            else
            {
                for(int j=1; j<=26; j++)
                {
                    if(ar[j])
                    {
                        ar[j]--;
                       // cout<<j<<" "<<st<<endl;
                        bl[st++]='a'+j-1;
                        break;
                    }
                }
            }
        }
        else
        {

            int x=0;
            for(int j=26; j>=1; j--)
            {
                if(br[j])
                {
                    x=j;
                    break;
                }
            }

            bool fl=0;

            for(int j=1; j<x; j++)
            {
                if(ar[j])fl=1;
            }

            if(!fl)
            {
                for(int j=1; j<=26; j++)
                {
                    if(br[j])
                    {
                        br[j]--;
                        bl[en--]='a'+j-1;
                        break;
                    }
                }

            }
            else
            {
                for(int j=26; j>=1; j--)
                {
                    if(br[j])
                    {
                        br[j]--;
                        bl[st++]='a'+j-1;
                        break;
                    }
                }
            }

        }
        fl1^=1;
    }

    for(int i=1; i<=l; i++)
        PC("%c",bl[i]);
    NL;
    return 0;
}
