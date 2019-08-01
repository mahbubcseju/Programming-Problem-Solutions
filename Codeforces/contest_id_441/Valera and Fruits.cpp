

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
#define M 9999999999
#define eps 1e-9
////
////
//START FROM HERE MAHBUB//
//using namespace std;//
int main()
{
    int n,m;
    cin>>n>>m;
    int a[3004];
    SET(a);
    for(int i=1; i<=n; i++)
    {
        int x,y;
        cin>>x>>y;
        a[x]+=y;
    }
    LL sum=0;
    for(int j=3003; j>=1; j--)
    {
        if(a[j]<=m)
        {

            sum+=a[j];
            int l=m-a[j];
            if(l>=a[j-1])
            {
                sum+=a[j-1];
                a[j-1]=0;

            }
            else
            {
                sum+=l;
                a[j-1]-=l;
            }
        }
        else sum+=m;
    }
    cout<<sum<<endl;

    return 0;
}
