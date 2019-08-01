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


typedef pair<int, int > P;
typedef vector<int> V;

//////////////////////
///////////////////////////
#define mx 300000
bool chk(char c) {
    if(c=='.'||c=='F')return true;
    return false;
}

map<char,char>mp;
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
char df[]= {'D','U','R','L'};

void changeR() {
    PC("R\n");
    fflush(stdout);
    int x,y;
    I2(x,y);

    if(y==1) {
        mp['L']='R';
        mp['R']='L';
    } else {
        PC("L\n");
        fflush(stdout);
        int x,y;
        I2(x,y);
    }
}

void changeD() {
    PC("D\n");
    fflush(stdout);
    int x,y;
    I2(x,y);
    //cout<<x<<" "<<endl;
    if(x==1) {
        mp['D']='U';
        mp['U']='D';
    } else {
        PC("U\n");
        fflush(stdout);
        int x,y;
        I2(x,y);
    }
}
char a[102+2][102+2];
vector<P>v;
void bfs(int x,int y) {
    queue<P>q;
    q.push(mk(x,y));
    P vis[102][102];
    SETR(vis);
    vis[x][y]=mk(0,0);
    P ko=mk(x,y);

    // cout<<x<<" "<<y<<endl;
    while(!q.empty()) {
        P f=q.front();
        if(a[f.x][f.y]=='F')ko=f;
        // cout<<f.x<<" "<<f.y<<endl;
        q.pop();

        for(int i=0; i<4; i++) {
            int x1=dx[i]+f.x;
            int y1=dy[i]+f.y;
            //cout<<x1
            if(chk(a[x1][y1])&&vis[x1][y1]==mk(-1,-1)) {
                vis[x1][y1]=f;
                q.push(mk(x1,y1));
                //  cout<<x1<<" "<<y1<<endl;

            }
        }
    }

    // v.PB(ko);
    // cout<<ko.x<<" "<<ko.y<<endl;
    while(ko.x>0) {
        v.PB(ko);
        ko=vis[ko.x][ko.y];
        // cout<<ko.x<<" "<<ko.y<<endl;

    }
    reverse(v.begin(),v.end());
}

int main() {
    int n,m;
    I2(n,m);

    for(char c1='A'; c1<='Z'; c1++)mp[c1]=c1;

    for(int i=1; i<=n; i++) {
        SC("%s",a[i]+1);
    }

    if(n*m==1) {

        PC("U\n");
        fflush(stdout);
        int x,y;
        I2(x,y);
        // SC("%d %d",&x,&y);
    } else if(a[1][2]=='F'||a[2][1]=='F') {
        if(a[1][2]=='F') {
            PC("R\n");
            fflush(stdout);
            int x,y;
            I2(x,y);
            if(y==1) {
                PC("L\n");
                fflush(stdout);
                int x,y;
                I2(x,y);
            }
        } else {
            PC("D\n");
            fflush(stdout);
            int x,y;
            I2(x,y);
            //cout<<x<<" "<<endl;
            if(x==1) {
                PC("U\n");
                fflush(stdout);
                int x,y;
                I2(x,y);
            }
        }

    } else if(chk(a[1][2])&&chk(a[2][1])) {
        // lol;
        changeR();
        changeD();
        bfs(1,1);
        if(a[1][1]=='F')return 0;
        int x=1,y=1;
        for(int i=0; i<v.size(); i++) {
            for(int j=0; j<4; j++) {
                int f1=x+dx[j];
                int f2=y+dy[j];
                if(f1==v[i].x&&f2==v[i].y) {
                    PC("%c\n",mp[df[j]]);
                    //  cout<<j<<" "<<df[j]<<endl;
                    fflush(stdout);
                    I2(x,y);
                    break;
                }
            }
        }

    } else if(chk(a[1][2])) {

        changeR();
        int x=1,y=1;
        while(!chk(a[x+1][y])) {
            PC("%c\n",mp['R']);
            fflush(stdout);
            I2(x,y);

            if(a[x][y]=='F')return 0;
            //  cout<<x+1<<" "<<y<<" bal "<<a[x+1][y]<<endl;
        }

        // cout<<x<<" brftgh "<<y<<endl;
        changeD();
        // cout<<mp['D']<<" "<<mp['U']<<endl;
        bfs(x,y);
        // lol;
        //  cout<<v.size()<<endl;
        for(int i=0; i<v.size(); i++) {
            for(int j=0; j<4; j++) {
                int f1=x+dx[j];
                int f2=y+dy[j];
                if(f1==v[i].x&&f2==v[i].y) {
                    PC("%c\n",mp[df[j]]);
                    // cout<<df[j]<<" "<<j<<endl;
                    fflush(stdout);
                    I2(x,y);
                    break;
                }
            }
        }

    } else {

        changeD();
        int x=1,y=1;
        while(!chk(a[x][y+1])) {
            PC("%c\n",mp['D']);
            fflush(stdout);
            I2(x,y);
            if(a[x][y]=='F')return 0;
            //  cout<<x+1<<" "<<y<<" bal "<<a[x+1][y]<<endl;
        }

        // cout<<x<<" brftgh "<<y<<endl;
        changeR();
        // cout<<mp['D']<<" "<<mp['U']<<endl;
        bfs(x,y);
        // lol;
        //  cout<<v.size()<<endl;
        for(int i=0; i<v.size(); i++) {
            for(int j=0; j<4; j++) {
                int f1=x+dx[j];
                int f2=y+dy[j];
                if(f1==v[i].x&&f2==v[i].y) {
                    PC("%c\n",mp[df[j]]);
                    // cout<<df[j]<<" "<<j<<endl;
                    fflush(stdout);
                    I2(x,y);
                    break;
                }
            }
        }



    }



    return 0;
}
