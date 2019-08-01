/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define PB push_back
#define x first
#define y second
#define xx first.first
#define xy first.second
#define yx second.first
#define yy second.second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M)
{
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number )
{
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text )
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a,T b,T c)
{
    if(((a.xx-b.xx)*(b.yy-c.yy)-(b.xx-c.xx)*(a.yy-b.yy))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define MX 1000003
#define mx 1000003
#define md 1000000007
#define maxp 2050180000

typedef pair<int ,int > P;

////////define value/////
int pat[MX+2];
int funct(char b[],int l)
{
    //cout<<b<<endl;
    int k=-1;
    int i=0;
    pat[0]=-1;
    while(i<l)
    {
        if(k>-1&&b[k]!=b[i])k=pat[k];
        else
        {
            k++;
            i++;
            pat[i]=k;
        }
    }
//cout<<pat[l]<<endl;
    return pat[l];
}
bool check(char a[],char b[],int l,int l1)
{
    int k=0;
    int i=0;
    while(i<l1)
    {
        if(k>-1&&a[k]!=b[i])k=pat[k];
        else
        {
            k++;
            i++;
            if(k==l)return true;
        }

    }
    return false;

}
char a[3][mx+2],b[3][mx+2],a2[3][mx+2];
char b1[mx+2];
char c[mx+2];
int main()
{


    while(SC("%s",a2[0])!=EOF)
    {
        SC("%s",a2[1]);
        SC("%s",a2[2]);
        for(int i=0; i<3; i++){strcpy(a[i],a2[i]);
            reverse(a[i],a[i]+strlen(a[i]));}


             int res=mx;
        for(int j=1; j<(1<<3); j++)
        {

            int lp=-1;
            for(int k=0; k<3; k++)
            {
                if((j&(1<<k))>0)
                {
                    lp++;

                    strcpy(b[lp],a[k]);
                }
            }

            lp++;
            bool fl1=1;
            for(int k=0; k<3; k++)
            {
                if((j&(1<<k))==0)
                {
                    int lo=strlen(a[k]);
                    funct(a[k],lo);
                    bool fl=0;
                    for(int k1=0; k1<lp; k1++)
                    {
                        if(check(a[k],b[k1],lo,strlen(b[k1])))fl=1;

                    }
                    if(fl==0)
                    {
                        fl1=0;
                        break;

                    }
                }
            }
            if(fl1==0)continue;

            if(lp==1)
            {
                res=min(res,(int )strlen(b[0]));
               // cout<<res<<endl;
                continue;
            }

            int a1[]= {0,1,2};

            do
            {

                strcpy(b1,b[a1[0]]);
                strcat(b1,"#");
                strcat(b1,b[a1[1]]);
                int l=strlen(b1);
                int ans=0;

                ans+=(l-funct(b1,l));
                if(lp==3)
                {
                    strcpy(b1,b[a1[1]]);
                      strcat(b1,"#");
                    strcat(b1,b[a1[2]]);
                    l=strlen(b1);
                    ans+=(strlen(b[a1[2]])-funct(b1,l));
                }

                res=min(res,ans-1);
                //cout<<a1[0]<<" "<<a1[1]<<" "<<a1[2]<<endl;
                //getchar();

            }
            while(next_permutation(a1,a1+lp));
        }
        PI(res);

    }



    return 0;
}
