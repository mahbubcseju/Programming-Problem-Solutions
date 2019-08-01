#include<cfloat>
#include<climits>
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
#define PI(a) printf("%d",a)
#define ll long long int
#define  ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define x first
#define y second
#define NL printf("\n")
#define mk make_pair
#define W(a) freopen(a, "w", stdout);
using namespace std;

#define md 1000000007ll
#define  mx 2000004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
/////////////////////////

int main()
{
    int n;
    I(n);
    int ar[n+2];
    priority_queue<int>pq;
    priority_queue<P>p;
    for(int i=1; i<=n; i++)
    {
        I(ar[i]);

        //cerr<<i<<"->> "<<ar[i]<<" ";
        if(pq.size()>0&&p.size()>0)
        {
            P f=p.top();

            if(-pq.top()<ar[i])
            {
                int fi=-f.x+f.y+pq.top()+ar[i];
                int lav=ar[i]+f.y;
                if(fi>lav)
                {
                    //cerr<<ar[i]<<" pq"<<" p"<<pq.top()<<endl;
                    p.push(mk(-ar[i],pq.top()));
                    pq.pop();
                }
                else
                {
                    p.pop();
                    pq.push(f.x);
                    //cerr<<ar[i]<<" pq"<<" p"<<f.y<<endl;
                    p.push(mk(-ar[i],f.y));
                }

            }
            else
            {
                if(-f.x<ar[i])
                {
                    p.pop();
                   // cerr<<ar[i]<<" pq"<<" p"<<f.y<<endl;
                    p.push(mk(-ar[i],f.y));
                    pq.push(f.x);
                }
                else pq.push(-ar[i]);
            }

        }
        else  if(p.size()>0)
        {
            P f=p.top();
            int fi=-f.x+f.y;
            int lav=ar[i]+f.y;
            if(lav>fi)
            {
                p.pop();
                pq.push(f.x);
                //cerr<<ar[i]<<" lol  "<<f.y<<endl;
                p.push(mk(-ar[i],f.y));
            }
            else pq.push(-ar[i]);
        }
        else  if(pq.size()>0)
        {
            int lo=pq.top();
            int fi=ar[i]+pq.top();
            if(fi>0)
            {
                pq.pop();
                //cerr<<ar[i]<<"  "<<lo<<endl;
                p.push(mk(-ar[i],lo));
            }
            else pq.push(-ar[i]);
        }
        else pq.push(-ar[i]);
        //cerr<<endl;
    }
    ll res=0;
    while(!p.empty())
    {
        P x=p.top();
        p.pop();
        res-=x.x;
        res+=x.y;
    }
    cout<<res<<endl;
    return 0;
}
