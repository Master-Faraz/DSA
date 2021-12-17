#include <stdio.h>
#include <string.h>
int main()
{
    char a[] = "Faraz";
    char b[] = "'F','a','r','a','z'";
    printf("%d\t%d\n", sizeof(a)/sizepf(a[0]), sizeof(b)/sizepf(a[0]));
    return 0;
}