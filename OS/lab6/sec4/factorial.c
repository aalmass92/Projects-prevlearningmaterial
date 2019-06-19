/*factorial for endless loop */

#include <stdio.h>

main()
{
    int n, m;
    for(;;)
    {
    printf("Enter a number: ");
    scanf("%d", &n);
    m = fact(n);
    printf("The factorial of %d is %d.\n", n, m);
    }
}

fact(int n)
{
    if (n == 0)
        return(1);

    return(n * fact(n-1));
}