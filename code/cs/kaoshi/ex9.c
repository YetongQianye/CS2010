#include<stdio.h>
int main() 
{  
    int s[12 ]={1,2,3,4,4,3,2,1,1,1,2,3}, c[5]={0}, i; 
    for ( i=0; i<12; i++ )  
        c[s[i]]++; 
    for ( i=1; i<5; i++ )  
        printf("%d ", c[i] ); 
    printf("\n");  
}
