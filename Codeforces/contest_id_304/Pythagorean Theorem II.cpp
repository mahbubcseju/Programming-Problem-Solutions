#include<stdio.h>
#include<math.h>
int main(){

 long long int i,j,k,n,l,p,sum;sum=0;
while(scanf("%lld",&n)!=EOF){sum=0;
 for(i=1;i<=n;i++){

for(j=i+1;j<=n;j++){
l=i*i+j*j;p=(int)sqrt(l);
  if(l<=n*n&&sqrt(l)==p){sum++;}



}

  }

printf("%lld\n",sum);

}
return 0;
}

