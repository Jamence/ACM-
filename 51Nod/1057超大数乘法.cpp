#include <stdio.h>
#define MAX 1000000+5
int main()
{
    int n,a[MAX];
    int i,j,k,count,temp;
    while(~scanf("%d",&n))
    {
        a[0]=1;
        count=1;
        for(i=1;i<=n;i++)
        {
            k=0;
            for(j=0;j<count;j++)
            {
                temp=a[j]*i+k;
                a[j]=temp%10;
                k=temp/10;    
            }
            while(k)//记录进位    
             {
                a[count++]=k%10;
                k/=10;
            }
        }
        for(j=MAX-1;j>=0;j--)      
            if(a[j])
                break;//忽略前导0
        for(i=count-1;i>=0;i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
