/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
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
#define SL(a) scanf("%lld",&a)
#define SLD(a,b) scanf("%lld%lld",&a,&b)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PC(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define FL(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
#define PB(a) push_back(a)
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
#define pi 2.0*acos(0.0)
using namespace std;
#define MX 1000006
#define MD 1000000007
#define eps 1e-9
/////////////////////////////
////////////////////////////
////Function Area Start////[7
int main()
{
    string h[8]= {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    int n;
    cin>>n;
    char ch[n+3];
    scanf("%s",&ch);
   // cout<<ch<<endl;
    for(int i=0; i<=7; i++)
    {
    if(h[i].size()!=n)continue;
   // if()
        int l=0;
        for(int j=0; j<n; j++)
        {
            if(ch[j]!=h[i][j]&&ch[j]!='.')
            {
                l=1;

            }

        }
        if(l==0)
            {
                cout<<h[i]<<endl;
                return 0;
            }
    }

    return 0;
}

