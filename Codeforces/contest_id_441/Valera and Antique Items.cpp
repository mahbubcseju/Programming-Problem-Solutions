

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
    int n,v;
    cin>>n>>v;
    vector<int>V;
    for(int t=1; t<=n; t++)
    {
        int m;
        cin>>m;
        int a=9999999;
        int u=0;
        for(int i=1; i<=m; i++)
        {
            int x;
            cin>>x;
            if(x<v)u=1;
        }
        if(u)V.PB(t);
    }

    cout<<SZ(V)<<endl;
    for(int i=0; i<SZ(V); i++)
    {
        if(i==0)cout<<V[i];
        else if(i==SZ(V)-1)cout<<" "<<V[i]<<endl;
        else cout<<" "<<V[i];
    }

    return 0;
}
