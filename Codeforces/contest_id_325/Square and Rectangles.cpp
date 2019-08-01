#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(){int i,k,j,l,o,p,a[1000],b[1000],c[1000],d[1000];
double w,x1,y1,z,x2,y2,m,m1,m2,m3,m4,area,ar;
scanf("%d",&p);
for(i=1;i<=p;i++){
    scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
}area=0.0;
for(i=1;i<=p;i++){
    x1=(double)a[i];x2=(double)c[i];y1=(double)b[i];y2=(double)d[i];
area+=(y2-y1)*(x2-x1);
}m=31455.0;m1=31455.0;m3=0.0;m4=0.0;
for(i=1;i<=p;i++){
        if(m>a[i])m=a[i];
if(m3<a[i])m3=a[i];
if(m>c[i])m=c[i];
if(m3<c[i])m3=c[i];
 if(m1>b[i])m1=b[i];
if(m4<b[i])m4=b[i];
if(m1>d[i])m1=d[i];
if(m4<d[i])m4=d[i];

}ar=(m4-m1)*(m3-m);
if(area==ar&&m4-m1==m3-m)
   printf("YES\n");
else printf("NO\n");









return 0;
}

