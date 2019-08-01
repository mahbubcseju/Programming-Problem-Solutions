#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,c;
    int a[100009];
    cin>>t>>c;
    if(t==c)
    {
        printf("-1\n");
    }
    else
    {
        if (t-1==c)
        {
            for(int i=1; i<=t; i++)
            {
                a[i]=i;
            }

        }
        else if(c==0)
        {
            for(int e=1; e<t; e++)
            {
                a[e]=e+1;

            }
            a[t]=1;

        }

        else
        {
            int i,y=0;
            for( i=2; ; i++)
            {
                y++;

                a[i]=i;
                if(y==c)break;
            }
            a[1]=i+1;
            int r=i+1;


            for(int j=i+1; j<t; j++)
            {
                r++;
                a[j]=r;

            }
            a[t]=1;
        }
        int y=0;

        for(int d=1; d<=t; d++)
        {
            if(y==0)
                printf("%d",a[d]);
            else printf(" %d",a[d]);

            y++;

        }
        printf("\n");
    }


    return 0;

}
