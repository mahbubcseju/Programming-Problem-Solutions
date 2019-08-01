

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
    LL n;
    cin>>n;
    LL a[n+1];
    LL sum[n+1];
    LL su[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    sum[i]=sum[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    su[0]=0;
    for(int i=1;i<=n;i++){
    su[i]=su[i-1]+a[i];
    }
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    LL x,y,z;
    cin>>x>>y>>z;
    if(x==1){
    cout<<sum[z]-sum[y-1]<<endl;

    }
    else cout<<su[z]-su[y-1]<<endl;

    }
    return 0;
}
