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
LL ka,l,su;
LL ans(LL i,LL j,LL k)
{
   LL o=min(min(i,j),k);
   i-=o;
   j-=o;
   k-=o;
   l=max(max(i,j),k);
//cout<<i<<"   "<<j<<"   "<<k<<"   "<<su<<"   "<<l<<endl;
if(i+j+k>su||(su-i-j-k)%3!=0)return 0;
//cout<<i<<"   "<<j<<"   "<<k<<"   "<<ka<<"   "<<l<<endl;
    if(i<l)
    {

        ka-=(l-i);
        i=l;
    }
    if(j<l)
    {

        ka-=(l-j);
        j=l;
    }
    if(k<l)
    {

        ka-=(l-k);
         k=l;
    }
  // cout<<ka<<endl;
    if(ka%3==0&&ka>=0)
    {//cout<<1<<endl;
        return 1;
    }
    else return 0;

}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        LL a,b,c,d;
        cin>>a>>b>>c>>d;
        LL re=a-b;
        LL i=0,j=0,k=0;
        LL res=0;
        i+=c;
        k+=d;
        ka=re;
        su=b;
        l=max(max(i,j),k);
        res=max(ans(i,j,k),res);
       // cout<<res<<endl;
        i=c+d;
        j=d;
        k=0;
        ka=re;
        l=max(i,j);
        res=max(ans(i,j,k),res);
        i=0;
        j=c;
        k=c+d;
        ka=re;
        l=max(max(i,j),k);
        res=max(ans(i,j,k),res);
        i=d;
        j=c+d;
        k=c;
        ka=re;
        l=max(max(i,j),k);
        res=max(ans(i,j,k),res);
        if(res>0)cout<<"yes"<<endl;
        else cout<<"no"<<endl;

    }

    return 0;
}
