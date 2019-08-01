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
#define SZ(a) ((int)a.size())-1
#define f(i,a,b) for(int i=a;i<=b; i++)
#define fr(i,a,b) for(int i=a;i<=b; i++)
#define frr(i,a,b) for(int i=a;i>=b; i--)
#define frv(i,a)  for(int i=0;i<a.size();i++)
#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define Endl "\n"
#define mk make_pair
using namespace std;

#define md 1000000007ll
#define  mx 200004
#define base 193ll

typedef pair<int,int >P;

///////////////////////////
///////////////////////////
////////define value/////

set <pair< ll, pair<int,int > >  > st;
int f[mx+2],l[mx+2];

int n;

int main()
{
    I(n);

    if(n==1)
    {
        PC("YES");
        return 0;
    }

    ll ar[n+2];
    for(int i=1; i<=n; i++)
    {
        L(ar[i]);

    }

    ar[0]=0;
    int fi=0;

    for(int i=1; i<=n; i++)
    {
        if(ar[i]!=ar[i-1])
        {
            if(i>1)
            {


                f[i-1]=fi;
                l[fi]=i-1;
                st.insert(mk(ar[i-1],mk(fi,i-1)));
            }
            fi=i;
        }
    }

    st.insert(mk(ar[n],mk(fi,n)));
    f[n]=fi;
    l[fi]=n;
    set <pair< ll, pair<int,int > >  > ::iterator it;


//    for(it=st.begin(); it!=st.end(); it++)
//    {
//
//        pair< ll, pair<int,int > >  fo=*it;
//
//        cout<<fo.x<<" "<<fo.yx<<" "<<fo.yy<<endl;
//    }

     while(st.size()>1)
     {
         it=st.begin();
        pair< ll, pair<int,int > >  fo=*it;
        st.erase(it);
      //  cout<<fo.x<<" "<<fo.yx<<" "<<fo.yy<<endl;
        if((fo.yy-fo.yx+1)%2==1){
            PC("NO\n");
            return 0;
        }
        int suru=fo.yx;
        int last=fo.yy;

      //  cout<<suru<<" "<<last<<endl;
        ll konta=2e18;
        if(suru-1>=1)
        {
           // ll ke=ar[suru-1];
            konta=min(konta,ar[suru-1]);
        }
        if(last+1<=n)
        {
            konta=min(konta,ar[last+1]);
        }
        if(suru-1>=1&&konta==ar[suru-1])
        {

            st.erase(mk(ar[suru-1],mk(f[suru-1],suru-1)));
         suru=f[suru-1];

        }
        if(last+1<=n&&konta==ar[last+1])
        {

            st.erase(mk(ar[last+1],mk(last+1,l[last+1])));
             last=l[last+1];
        }
       // cout<<suru<<" "<<last<<endl;
        ar[suru]=konta;
        ar[last]=konta;
        f[last]=suru;
        l[suru]=last;

        st.insert(mk(ar[suru],mk(suru,last)));
     }
     PC("YES\n");

    return 0;
}
