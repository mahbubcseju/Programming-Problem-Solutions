#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d",a)
#define PL(a) printf("%lld",a)
#define PT(t) printf("Case %d: ",t)
#define PB push_back
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())-1


#define lol printf("BUG\n")
#define Endl "\n"
#define mk make_pair
using namespace std;

#define md 1000000007ll
#define  mx 10004
#define base 193ll




char a[mx+2];
int part[mx+2];

ll DP[mx+2][202][2][2];
int cum[mx+2];
int vis[mx+2][202][2][2];
int cs=0;
ll rel(ll ans,ll ans1,bool fl)
{
  if(fl==0)return  max(ans,ans1);
  else return min(ans,ans1);
}
ll dp(int i,int p,bool fl,bool cl) {
    if(part[i]==i) {
        return a[i]-'0';
    }
    ll &ret=DP[i][p][fl][cl];
    if(vis[i][p][fl][cl]==1)return ret;
    vis[i][p][fl][cl]=1;
//    cerr<<i<<" "<<p<<Endl;
//
//    getchar();getchar();

  if(cl==0)
    ret=-2e18;
    else ret=2e18;
    int p1=part[i+1];



    if(fl==0) {

        if(p>0) {
            //  cerr<<i<<" cp"<<p<<endl;
            for(int j=0; j<p; j++) {
                int cal=cum[part[i+1]]-cum[i];
                int cal1=cum[part[i]]-cum[p1+1];
                if(cal>=j&&cal1>=p-j-1)
                {
                    if(cl==0)
                    ret=rel(ret,dp(i+1,j,fl,0)+dp(p1+2,p-j-1,fl,0),cl);
                    else ret=rel(ret,dp(i+1,j,fl,1)+dp(p1+2,p-j-1,fl,1),cl);
                }
            }
            // cerr<<i<<" +  "<<ret<<Endl;
        }
        int ache=cum[part[i]]-cum[i-1];
        ache-=p;
        if(ache>0) {
            for(int j=0; j<=p; j++) {
                int cal=cum[part[i+1]]-cum[i];
                int cal1=cum[part[i]]-cum[p1+1];
                if(cal>=j&&cal1>=p-j){
                   if(cl==0)
                    ret=rel(ret,dp(i+1,j,fl,0)-dp(p1+2,p-j,fl,1),cl);
                    else
                    {
                           ret=rel(ret,dp(i+1,j,fl,1)-dp(p1+2,p-j,fl,0),cl);
                    }
                }
            }
            // cerr<<i<<" - "<<ret<<Endl;
        }

    } else {


        if(p>0) {
            //  cerr<<i<<" cp"<<p<<endl;
            for(int j=0; j<p; j++) {
                int cal=cum[part[i+1]]-cum[i];
                int cal1=cum[part[i]]-cum[p1+1];
                if(cal>=j&&cal1>=p-j-1)
                {
                    if(cl==0)
                    ret=rel(ret,dp(i+1,j,fl,0)-dp(p1+2,p-j-1,fl,1),cl);
                    else  ret=rel(ret,dp(i+1,j,fl,1)-dp(p1+2,p-j-1,fl,0),cl);
                }
            }
            // cerr<<i<<" +  "<<ret<<Endl;
        }
        int ache=cum[part[i]]-cum[i-1];
        ache-=p;
        if(ache>0) {
            for(int j=0; j<=p; j++) {
                int cal=cum[part[i+1]]-cum[i];
                int cal1=cum[part[i]]-cum[p1+1];

                if(cal>=j&&cal1>=p-j)
                {
                    if(cl==0)
                    ret=rel(ret,dp(i+1,j,fl,0)+dp(p1+2,p-j,fl,0),cl);
                    else  ret=rel(ret,dp(i+1,j,fl,1)+dp(p1+2,p-j,fl,1),cl);
                }
                // cerr<<dp(i+1,j)<<" "<<dp(p1+2,p-j)<<" "<<i<<" "<<j<<" "<<p<<" "<<(p-j)<<Endl;
            }
            // cerr<<i<<" - "<<ret<<Endl;
        }
    }
    return ret;
}
int main() {
    SC("%s",a+1);
    int l=strlen(a+1);
    if(l==1) {
        PC("%c",a[1]);

        return 0;
    }
//    if(l==3){
//        PC("%c",a[2]);
//
//       return 0;
//    }
//    if(l==2)while(1);
    int st[l+2];
    int s=0;
    for(int i=1; i<=l; i++) {
        if(a[i]=='(')st[++s]=i;
        else if(a[i]==')') {
            int f=st[s];
            s--;
            part[f]=i;
        } else if(isdigit(a[i])==1) {
            part[i]=i;
            //cerr<<i<<" "<<part[i]<<Endl;
        }
        cum[i]=cum[i-1];
        if(a[i]=='?')cum[i]++;
    }
    //++cs;
    // for(int i=1;i<=l;i++)cerr<<i<<" "<<part[i]<<Endl;
    int n,m;
    I2(n,m);

    int path=n;
    bool fl=0;
    if(n>m) {
        path=m;
        fl=1;
    }
    // cerr<<path<<" "<<fl<<Endl;
    ll ans=dp(1,path,fl,0);
    PC("%lld\n",ans);
    return 0;
}
