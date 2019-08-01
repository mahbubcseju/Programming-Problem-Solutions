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
#define MX 3000000
#define MD    1000000007LL
#define eps FLT_EPSILON
/////////////////////////////
////////////////////////////
////Function Area Start////
string s,s1;
LL k;
LL l;
LL vis[400][400][3];
LL dp(LL i,LL j,LL cho)
{

    if(i==l)
    {
        if(j==k&&cho==1)
        {
            return vis[i][j][cho]=1;
        }
        else return vis[i][j][cho]=0;
    }
    if(j>k)return vis[i][j][cho]=0;
    LL &ret=vis[i][j][cho];
    if(ret!=-1)return ret;
    ret=0;
    if(cho==0)
    {
        LL st=s[i]-'0';
        for(LL i1=st; i1<=9; i1++)
        {
            if(i1==st)
            {
                ret|=dp(i+1,j+i1,cho);
            }
            else ret|=dp(i+1,j+i1,1);
        }
    }
    else
    {
        for(LL i1=0; i1<=9; i1++)
        {
            ret|=dp(i+1,j+i1,cho);
        }
    }
    return ret;
}

void rec(LL i,LL j,LL ch)
{
    if(i==l)
    {
        // cout<<s<<endl;

        return ;
    }
    LL lo=0;
    if(ch==0)
    {
        lo=s[i]-'0';
    }
    for(LL i1=lo; i1<=9; i1++)
    {
        LL ko=0,ok;
        if(ch==0)
        {
            if(i1==lo)
            {
                ko=vis[i+1][j+i1][ch];
                if(ko==1)
                {
                    s1+=('0'+i1);
                    rec(i+1,j+i1,ch);
                    return;
                }
            }
            else
            {
                ko=vis[i+1][j+i1][1];

                if(ko==1)
                {
                    s1+=('0'+i1);
                    rec(i+1,j+i1,1);
                    return;
                }
            }
        }
        else
        {
            ko=vis[i+1][j+i1][ch];
            if(ko==1){
                if(ko==1)
                {
                    s1+=('0'+i1);
                    rec(i+1,j+i1,ch);
                    return;
                }
            }

        }


    }
}
int main()
{
    int n;
    S(n);
    string h="";
    s1="0";
    for(int i=1; i<=n; i++)
    {
        SL(k);
        h="";
        for(LL j=1; j<400; j++)
        {
            SETR(vis);
            s=h+s1;
            l=s.size();
            h+='0';
            LL op=dp(0,0,0);
            if(op==1)
            {
                s1="";
                rec(0,0,0);
                cout<<s1<<endl;
                break;
            }
        }

    }
    return 0;
}
