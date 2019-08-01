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
#define I int
#define LL long long int
#define UL unsigned long long int
#define S(a) scanf("%d",&a)
#define SD(a,b) scanf("%d%d",&a,&b)
#define SL(a) scanf("%I64d",&a)
#define SLD(a,b) scanf("%I64d%I64d",&a,&b)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%I64d\n",a)
#define PC(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define FL(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
#define PB(a) push_back(a)
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
using namespace std;
#define MX 99999999999
#define MD 10000
#define eps 1e-9
/////////////////////////////
////////////////////////////
////Function Area Start////

int main()
{int n,m;
SD(n,m);
F(i,1,n){
F(j,1,n){
    if(j!=1)cout<<" ";
    if(i==j)cout<<m;
    else cout <<0;
}
cout<<endl;
}


    return 0;
}

