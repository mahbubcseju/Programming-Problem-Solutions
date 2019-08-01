
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
#define D double
#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define SL(a) scanf("%lld",&a)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define FL(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
#define PB(a) push_back(a)
#define FI first
#define SD second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);

using namespace std;
typedef pair<I, I>P;
#define MX 10000000000000;
#define MD  1000000007
#define eps 1e-6
#define inf 100000000000000000LL
/////////////////////////////
////////////////////////////
////Function Area Start////
LL n, m, k;
LL a[5004],b[5004];
LL res[5004][5004];
LL dp(LL i,LL j){
    if(i>(n-m+1)){
        if(j==k)return 0;
        else return -inf;
    }
    LL &ret=res[i][j];
    if(ret!=-1)return ret;
    ret=-inf;
    ret=max(ret,b[i]+dp(i+m,j+1));
    ret=max(ret,dp(i+1,j));
   // cout<<ret<<endl;
    return ret;

}
int main()
{
    cin >> n >> m >> k;
    for(LL i = 1; i <= n; i++)
    {
        SL(a[i]);
    }
    for(LL i = 1; i <= (n - m + 1); i++)
    {
        LL y = 0;
        LL sum = 0;
        for(LL j = i, y = 1; j <= n && y <= m; j++, y++)
        {
            sum += a[j];

        }
        b[i]=sum;
    }
    SETR(res);
    LL ans = dp(1, 0);
    cout << ans << endl;
//for(int i=1;i<=n;i++)cout<<b[i]<<endl;
    return 0;
}
