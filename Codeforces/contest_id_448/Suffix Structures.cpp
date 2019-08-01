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
#define MD 10000007
#define eps 1e-9
/////////////////////////////
////////////////////////////
////Function Area Start////
int main()
{
    string a,b;
    cin>>a>>b;
    int k=0,p=0,i,j;
    for(i=0; i<b.size(); i++)
    {

        for(j=k; j<a.size(); j++)
        {
            if(b[i]==a[j])
            {
                k=j+1;
                break;
            }
        }
        if(j>=a.size())
        {
            p=1;
            break;
        }

    }
    if(p==0)
    {
        cout<<"automaton"<<endl;

    }
    else
    {
        int c[30];
        int d[30];
        SET(c);
        SET(d);
        for(i=0; i<a.size(); i++)
        {
            int h=a[i]-96;
            c[h]++;
        }
        for(i=0; i<b.size(); i++)
        {
            int h=b[i]-96;
            d[h]++;
        }
        int y=0;
        for(int i=0; i<=29; i++)
        {
            if(d[i]>c[i])
            {
                y=1;
                break;
            }
        }
        if(y==1)cout<<"need tree"<<endl;
        else if(SZ(a)==SZ(b)&&y==0)cout<<"array"<<endl;
        else cout<<"both"<<endl;
    }
   // main();
    return 0;
}
