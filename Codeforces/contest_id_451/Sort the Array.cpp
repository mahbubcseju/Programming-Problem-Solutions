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
    int n;
    cin>>n;
    int a[n+10];
    int d[n+10];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        d[i]=a[i];
    }
    sort(d+1,d+n+1);
    map<int,int>mp;
    for(int j=1; j<=n; j++)
    {
        mp[d[j]]=j;
    }
    int l1=0,k;
    int lo=0,hi=0;

    for(int i=1; i<=n; i++)
    {
        if(mp[a[i]]!=i)
        {
            lo=i;
            hi=mp[a[i]];
            int l=lo;
            int h=hi;
            while(l<=h)
            {
                if(mp[a[h]]!=l||mp[a[l]]!=h)
                {
                    l1=1;
                    break;
                }
                l++;
                h--;
            }
            break;
        }

    }
    for(int i=hi+1; i<=n; i++)
    {
        if(mp[a[i]]!=i)
        {
            l1=1;
            break;
        }
    }
    if(l1)cout<<"no"<<endl;
    else
    {

        cout<<"yes"<<endl;
        lo=max(lo,1);
        hi=max(hi,1);
        cout<<lo<<" "<<hi<<endl;
    }
   // main();

    return 0;
}
