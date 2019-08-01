#include<stdio.h>
int main(){
int i,j,k,l,o,p,a[1000],b[1000],e=0,f,c;
scanf("%d%d",&o,&p);k=0;e=0,c=1;
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
    for(i=1;i<=o;i++){
        for(j=c;j<=p;j++){e=0;f=0;
            for(l=1;l<=k;l++)
            {
                if(i==a[l])e=1;
                   //||(i==b[l]&&j==a[l]))
                if(j==b[l])f=1;

            } if((e==0&&f==1)||(e==1&&f==0)||e==0&&f==0){ ++k;
                        a[k]=i;b[k]=j;c=j;}
        }


}
  printf("%d\n",k);
for(i=1;i<=k;i++){
    printf("%d %d\n",a[i],b[i]);



}











return 0;

}
