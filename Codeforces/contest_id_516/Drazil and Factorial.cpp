/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
#include<cfloat>
#include<climits>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#define I int
#define LL long long int
#define UL unsigned long long int
#define D double
#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL(a) scanf("%lld",&a)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define FL(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
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
#define STN(a) stringtonumber<LL>(a)
using namespace std;
template <class T> inline T BM(T p,T e,T M)
{
    LL ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T MDINV(T a,T M)
{
    return BM(a,M-2,M);
}
template <class T> inline T PW(T p,T e)
{
    LL ret = 1;
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
typedef pair<int ,int >P;
////////define value//////////
#define MX 1000000000
#define MD 100000007
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a[10];
    SET(a);
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='2')a[2]++;
        else if(s[i]=='3')
        {
            a[2]++;
            a[3]++;

        }
        else if(s[i]=='4')
        {
            a[2]++;
            a[3]++;
            a[2]+=2;
        }
        else if(s[i]=='5')
        {
            a[2]++;
            a[3]++;
            a[2]+=2;
            a[5]++;

        }
        else if(s[i]=='6')
        {
            a[2]++;
            a[3]++;
            a[2]+=2;
            a[5]++;
            a[2]++;
            a[3]++;
        }
        else if(s[i]=='7')
        {

            a[2]++;
            a[3]++;
            a[2]+=2;
            a[5]++;
            a[2]++;
            a[3]++;
            a[7]++;
        }
        else if(s[i]=='8')
        {
            a[2]++;
            a[3]++;
            a[2]+=2;
            a[5]++;
            a[2]++;
            a[3]++;
            a[7]++;
            a[2]+=3;

        }
        else if(s[i]=='9')
        {
            a[2]++;
            a[3]++;
            a[2]+=2;
            a[5]++;
            a[2]++;
            a[3]++;
            a[7]++;
            a[2]+=3;
            a[3]+=2;

        }
    }

    for(int i=7; i>=2; i--)
    {
        if(i==7||i==5||i==3||i==2)
        {

            while(a[i]>0)
            {
                cout<<i;
                for(int j=i; j>=2; j--)
                {
                    if(j==7||j==5||j==3||j==2)a[j]--;
                    else if(j==6)
                    {
                        a[2]--;
                        a[3]--;
                    }
                    else if(j==4)
                    {
                        a[2]-=2;
                    }

                }
            }
        }
    }
    return 0;
}
