#include <stdio.h>

/* copy input to output replacing each string of blanks with a single blank (space) */

main()
{
        int c;
        int in_blank_str;

        in_blank_str = 0;
        c = getchar();
        while (c != EOF)
        {
                if(c==' ')
                        in_blank_str = 1;
                else if(c=='\t')
                        in_blank_str = 1;
                else if(c=='\n')
                        in_blank_str = 1;
                else if(in_blank_str==1)
                {
                        putchar(' ');
                        in_blank_str = 0;
                }

                if(in_blank_str==0)
                        putchar(c);
                c = getchar();
        }
}
