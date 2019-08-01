#include<stdio.h>
int main() {


      int a[]={6,2,5,5,4,5,6,3,7,6};


      int n;
      scanf("%d",&n);
      if(n%2==1)printf("7");
      else printf("1");

int j;
      for( j=2;j<=n/2;j++)printf("1");

    return 0;
}
