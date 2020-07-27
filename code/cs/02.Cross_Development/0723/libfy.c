#include<stdio.h>
int main()
{
    int s[5]={0};
  
    int i;
    for(i=0;i<=5;i++)
    {
        scanf("%d\n",&s[i]);
        if(s[i+1]>=s[i])
        {
            return s[i+1];
        }
        else
        {
            int t;
            t=s[i];
            s[i] = s[i+1];
            s[i+1] = t;
        }
        
    }
    printf("%d\n",s[i]);
    return 0;
}