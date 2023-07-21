#include <stdio.h>

/* verifying the value of an expression */

main()
{
        int c;

        while (c=(getchar() != EOF))
        {
                printf("The value of c is: %d\n",c);
        }
        printf("The value of c is: %d\n", c);
}
