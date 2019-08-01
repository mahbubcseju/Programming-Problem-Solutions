/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <deque>
#include <climits>
#include <complex>
#include <bitset>
#include <limits>
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
//#define pi 2.0*acos(0.0)
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
#define mx 200000ll
#define md 23377788ll
#define md1 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<int , int > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////
#define max_node 200005

struct HOPCROFT_KARP {
    vector<int>G[max_node];
    int matching;
    int match[max_node];
    int dist[max_node];
    int n,m;
    // there are two sets : A & B
    // n = number of elements in set A (element are numbered as 1,2,3,...n)
    // m = number of elements in set B (element are numbered as 1,2,3,...m)
    void init(int n,int m) { // initilize with number of elements of A & B
        this->n = n;
        this->m = m;
        for(int i=0; i<=n+m; i++) G[i].clear(); // clear adjacency list
    }
    // add a edge between in x and y
    // x = index of the node in set A
    // y = index of the node in set B
    void add_edge(int x,int y) {
        G[x].push_back(y+n);
        G[y+n].push_back(x);
    }
    bool bfs() {
        int i, u, v, len;
        queue< int > Q;
        for(i=1; i<=n; i++) {
            if(match[i]==0) {
                dist[i] = 0;
                Q.push(i);
            } else dist[i] = INT_MAX;
        }

        dist[0] = INT_MAX;

        while(!Q.empty()) {
            u = Q.front();
            Q.pop();
            if(u!=0) {
                len = G[u].size();
                for(i=0; i<len; i++) {
                    v = G[u][i];
                    if(dist[match[v]]==INT_MAX) {
                        dist[match[v]] = dist[u] + 1;
                        Q.push(match[v]);
                    }
                }
            }
        }
        return (dist[0]!=INT_MAX);
    }

    bool dfs(int u) {
        int i, v, len;
        if(u!=0) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==dist[u]+1) {
                    if(dfs(match[v])) {
                        match[v] = u;
                        match[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = INT_MAX;
            return false;
        }
        return true;
    }

    int find_maximum_matching() { // returns number of maximum matching possible
        matching = 0;

        memset(match,0,sizeof(match));

        while(bfs())
            for(int i=1; i<=n; i++)
                if(match[i]==0 && dfs(i))
                    matching++;

        return matching;
    }
    // show the matching
    // match[i]  = 0 means i'th element of set A does not matched with any element of set B
    // match[i] != 0 means i'th element of set A matched with match[i]'th element of set B
    void show_match() {
        for(int i=1; i<=n; i++) {
          // printf("%d ----- %d\n",i,match[i]-n);
          match[i]-=n;
        }
    }

} HK;

int main() {

    int n;
    I(n);
    string a[2][n+2];
    map<string ,int>mp;
    for(int i=1; i<=n; i++) {
        string s;
        cin>>s;
        for(int j=0; j<3; j++)a[0][i]+=s[j];
        for(int j=0; j<2; j++)a[1][i]+=s[j];
        cin>>s;
        a[1][i]+=s[0];
        mp[a[0][i]]++;
    }
    HK.init(n,2*n);
    map<string,int>mp1;
    string ar[n*2+2];
    int sz=0;
    for(int i=1; i<=n; i++) {

        if(mp[a[0][i]]==1) {
            if(mp1[a[0][i]]==0) {
               mp1[a[0][i]]=++sz;
                ar[sz]=a[0][i];
            }
            HK.add_edge(i,mp1[a[0][i]]);
        }

        if(mp1[a[1][i]]==0) {
            mp1[a[1][i]]=++sz;
            ar[sz]=a[1][i];
        }
        HK.add_edge(i,mp1[a[1][i]]);
    }
    int x=HK.find_maximum_matching();
    if(x<n)PC("No\n");
    else
    {
        PC("Yes\n");
        HK.show_match();
        for(int i=1;i<=n;i++)
        {
            cout<<ar[HK.match[i]]<<endl;
        }
    }


    return 0;
}
