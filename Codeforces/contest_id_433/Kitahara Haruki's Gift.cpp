
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
    int n;
    cin>>n;
    int a[n+1];
    LL sum=0;
    int b=0,c=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]==100)b++;
        else c++;
    }
    int l=0;
    if(c%2==1)
    {
        b-=2;
    }
    int k=1;
    if(b<0)
    {
        k=0;
    }
    else
    {
        if(b%2==1)k=0;
    }

    if(k)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;

}
