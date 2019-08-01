
/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include<bits/stdc++.h>
#include<string.h>
#include<stdio.h>
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
template <class T> inline T BM(T p, T e, T M) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M) {
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text ) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a, T b, T c) {
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

#define md 1000000007ll
#define  mx 200000

typedef pair<int,int >P;
//////////////////////////
/////////////////////////
int n,m;
int a[mx+2];
struct data {
    int info,l,r;
    data() {
        info=0;
        l=r=0;
    }

};

data tr[mx*40];
int sz;

void update(int no,int l,int r,int in,int val) {
    if(l==r) {
        //  cerr<<"up "<<l<<endl;
         //cout<<l<<" "<<r<<" "<<no<<" lol "<<val<<Endl;

        if(a[val]<a[tr[no].info])
        tr[no].info=val;
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=in) {
        if(tr[no].l==0) {
            tr[no].l=++sz;

            //cerr<<tr[no].l<<"left child of "<<no<<endl;
        }
        update(tr[no].l,l,mid,in,val);
    } else {
        if(tr[no].r==0) {
            tr[no].r=++sz;
            // cerr<<tr[no].r<<"right child of "<<no<<endl;
        }
        update(tr[no].r,mid+1,r,in,val);
    }
    if(a[tr[tr[no].l].info]>a[tr[tr[no].r].info])tr[no].info=tr[tr[no].r].info;
    else tr[no].info=tr[tr[no].l].info;
}
int qu(int no,int l,int r,int st,int en) {

    // cerr<<no<<" "<<l<<" "<<r<<endl;
    if(l>=st&&r<=en) {
        //cerr<<l<<" n "<<r<<" "<<no<<" "<<tr[no].info<<endl;
        return tr[no].info;
    }
    int mid=(l+r)>>1;

    if(mid>=en) {
       // cerr<<tr[no].l<<" left child of "<<no<<endl;

        return qu(tr[no].l,l,mid,st,en);
    }
    if(st>mid) {
       // cerr<<tr[no].r<<" right child of "<<no<<endl;
        return qu(tr[no].r,mid+1,r,st,en);
    }

    int l1=qu(tr[no].l,l,mid,st,mid);
    int r1=qu(tr[no].r,mid+1,r,mid+1,en);

    if(a[l1]>a[r1])return r1;
    else return l1;
}
int main() {
    I2(n,m);
    a[0]=2e9+1;
    ll matha[n+2];
    sz=1;
    for(int i=1; i<=n; i++) {
        I(a[i]);
        L(matha[i]);
        matha[i]+=a[i];

        //  cerr<<matha[i]<<" "<<i<<endl;
        int koth=min(matha[i],(ll)1e9);

        // cerr<<koth<<" "<<i<<endl;
        update(1,1,1e9,koth,i);
    }

    int ans[n+2];
    SET(ans);


   multiset<P>st;
   multiset<P>::iterator it;
    while(m--) {
        int x,y;
        I2(x,y);
        int as=qu(1,1,1e9,x,1e9);
        if(a[as]>x)
        {
                st.insert(mk(x,y));
                continue;
        }
         matha[as]+=y;
        ans[as]++;

        while(1)
        {
                it=st.lower_bound(mk(a[as],-1));
                if(it==st.end())break;
                P f=*it;
                if(matha[as]<f.x)break;
                st.erase(it);
                ans[as]++;
              matha[as]+=f.y;

        }

        // cerr<<as<<" lol"<<x<<" "<<y<<endl;
//        if(as>0) {
//            ans[as]++;
//            //cerr<<matha[as]<<" "<<y<<" ";
//            matha[as]+=y;
//            //cerr<<matha[as]<<" "<<as<<Endl;
//            int kop=min(matha[as],(int)1e9);
//            update(1,1,1e9,kop,as);
//        }
        int kop=min(matha[as],(ll)1e9);

       // cerr<<" eki "<< as<<endl;
        //cerr<<kop<<Endl;
        update(1,1,1e9,kop,as);
    }

    fr(i,1,n) {
        PC("%d %lld\n",ans[i],matha[i]-a[i]);
    }
    return 0;
}
