#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

/* count lines, words, and characters in input */

main()
{
        int c, state, first_word;

        state = OUT;
        first_word = 1;

        while((c=getchar()) != EOF)
        {
                if(c== ' ' || c== '\n' || c=='\t')
                {
                        state = OUT;
                }
                else if(state == OUT)
                {
                        state = IN;
                        if(first_word==0)
                        {
                                putchar('\n');
                        }
                        first_word = 0;
                        putchar(c);
                }
                else
                {
                        putchar(c);
                }
        }
        putchar('\n');
}
