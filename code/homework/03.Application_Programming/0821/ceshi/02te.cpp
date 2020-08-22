#include <iostream>
using namespace std;
int main()
{
    int i = 0,sum = 0;
    while (i<=10)
    {
        sum = sum +i;
        i++;
    }
    cout << "sum = " << sum <<"\n";
    return 0;   
}