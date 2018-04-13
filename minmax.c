#include<stdio.h>
int a[50],count=0;
void  minmax(int i,int j,int *max,int *min)
{
        int mid,max1,min1;
        if(i==j)
        {
                *max=*min=a[i];
                count++;
        }
        
        else if(i==j-1)
        {
                if(a[i]>a[j])
                {
                        *max=a[i];
                        *min=a[j];
                }
        
                else
                {
                        *max=a[j];
                        *min=a[i];
                }
         count++;       
        }
        
        else
        {
                mid=(i+j)/2;
                minmax(i,mid,max,min);
                minmax(mid+1,j,&max1,&min1);
                if(*max<max1)
                {
                        *max=max1;
                }
                        count++;
                if(*min>min1)
                {
                        *min=min1;
                }
                        count++;
        }
}
int main()
{
        int i,n,max,min;
        printf("\nEnter the number of elements ");
        scanf("%d",&n);
        
        printf("\nEnter the elements ");
        
        for(i=0;i<n;i++)
        {
              scanf("%d",&a[i]);
        }
        
        printf("\nElements are: \t");
        
        for(i=0;i<n;i++)
        {
    
              printf("%d\t",a[i]);
        }
        printf("\n");
        minmax(0,n-1,&max,&min);
        printf("\nMax number is %d ",max);
        printf("\nMin number is %d ",min);
        
        printf("\nFrequency count is :%d\n",count);       
        return 0;
}
