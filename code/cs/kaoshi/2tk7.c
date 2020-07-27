#include<stdio.h>
int divisor(int a,int b)
{ 
    int r;
    r=a%b;
    while(r!=0)
    {
        a=b;b=r;r=a%b;
    }
    return b;
}
void main()
{	 
    int a,b,d,t;
    scanf("%d %d",&a,&b);
    if (a<b)
    { 
        t=a; a=b; b=t; 
    }
    d=divisor(a,b);
    printf("\n gcd=%d",d);
}
