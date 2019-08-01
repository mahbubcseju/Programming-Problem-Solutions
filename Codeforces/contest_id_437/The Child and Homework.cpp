
/*
MAHBUBCSEJU
CSE 22
JAHANGIRNAGAR UNIVERSITY
TIMUS:164273FU
UVA>>LIGHTOJ>>HUST:mahbubcseju
*/
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
#define LL long long int
#define LLR unsigned long long int
#define SC(a) scanf("%d",&a)
#define SCR(a) scanf("%lld",&a)
#define SCD(a,b) scanf("%I64d%I64d",&a,&b)
#define PF(t) printf("Case %d: ",t)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
#define PB(a) push_back(a)
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
using namespace std;
#define M 99999999
#define eps 1e-9
////
////
//START FROM HERE MAHBUB//
//using namespace std;//
int main()
{
    string s;
    cin>>s;
    int a=s.size()-2;
    cin>>s;
    int b=s.size()-2;
    cin>>s;
    int c=s.size()-2;
    cin>>s;
    int d=s.size()-2;
    char ch;
    int t=0,T=0;
    if(a*2<=b&&a*2<=c&&a*2<=d)t=1;
    if(b*2<=a&&b*2<=c&&b*2<=d)t=2;
    if(c*2<=a&&c*2<=b&&c*2<=d)t=3;
    if(d*2<=b&&d*2<=a&&d*2<=c)t=4;
    if(a/2>=b&&a/2>=c&&a/2>=d)T=1;
    if(b/2>=a&&b/2>=c&&b/2>=d)T=2;
    if(c/2>=a&&c/2>=b&&c/2>=d)T=3;
    if(d/2>=b&&d/2>=a&&d/2>=c)T=4;
    if(t==1&&T==0||T==1&&t==0)cout<<"A"<<endl;
    else if(t==2&&T==0||T==2&&t==0)cout<<"B"<<endl;
    else if(t==3&&T==0||T==3&&t==0)cout<<"C"<<endl;
    else if((t==4&&T==0||T==4&&t==0))cout<<"D"<<endl;
    else cout<<"C"<<endl;
    return 0;
}
