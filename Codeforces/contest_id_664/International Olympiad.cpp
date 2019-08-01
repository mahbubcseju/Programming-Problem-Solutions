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
#include<string.h>
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
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PB push_back
#define xx first
#define yy second
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
template <class T>bool ISLEFT ( T a,T b,T c)
{
    if(((a.xx-b.xx)*(b.yy-c.yy)-(b.xx-c.xx)*(a.yy-b.yy))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 5000000
#define md 10000000000007ll

#define maxp 100000000000000004
typedef pair<int , int >P;
typedef vector<int >V;

////////define value/////

int main()
{
    int n;
    I(n);
    while(n--)
    {
        char a[20];
        SC("%s",a+1);


        int l=strlen(a+1);
        string s;
        for(int j=l; j>=5; j--)
            s+=a[j];
        string b;
        if(s[0]=='9')b="9891";
        else
        {
            b+=a[l];
            b+="991";
        }
        int sz=s.size();
        int res=s[0]-'0';
        int sum=res;
        // cout<<sum<<res<<endl;
        // lol;
        for(int j=1; j<sz; j++)
        {
//            sum=sum*10+s[j]-'0';
//            res=res*10+b[j]-'0';
//           cout<<sum<<res<<endl;
            sum=0;
            res=0;
//            cout<<b<<" "<<s<<endl;
            for(int i=0; i<=j; i++)
            {
                if(i<s.size())
                sum=sum*10+s[i]-'0';
                else sum=sum*10;
                if(i<b.size())
                res=res*10+b[i]-'0';
                else res=res*10;
            }
//            cout<<j<<endl;
//            cout<<b<<" "<<s<<endl;
//cout<<j<<endl;
           string sd;
           for(int i=j+1;i<b.size();i++)sd+=b[i];
            b="";
            for(int i=0; i<=j; i++)b+=s[i];
            b+=sd;
//           cout<<res<<" "<<sum<<endl;
//           cout<<b<<" "<<s<<endl;
//           cout<<b.size()<<" "<<j<<" "<<s.size()<<endl;
////           NL;
//cout<<res<<" "<<sum<<endl;
//cout<<b<<" "<<s<<endl;
//lol;
            if(res>=sum)
            {
                //lol;

                int ca=1;
                for(int k=j+1; k<b.size(); k++)
                {
                    if(ca)
                    {
                        int x=b[k]-'0';
                        x=x+ca;
                        b[k]=(char)('0'+x%10);
                        //cout<<b[k]<<endl;
                        ca=x/10;
                    }
                    else break;
                }
                if(ca)b+="1";
                //cout<<b<<endl;
            }
//            cout<<b<<" ";
//            lol;
        }
        reverse(b.begin(),b.end());

        cout<<b<<endl;
    }
    return 0;
}