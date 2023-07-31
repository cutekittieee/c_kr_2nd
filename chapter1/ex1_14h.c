#include <stdio.h>

/* create a histogram of the frequencies of the characters in the input */
/* v1: horizontal orientation */
/* maximum allowed frequency for each character: 77 */
/* this program stores 256 different (ascii) characters */

int main()
{
        int freqs[256];
        int i, j, c;

        for(i=0; i<256; i++)
        {
                freqs[i] = 0;   /* frequency of character code i */
        }

        while((c=getchar()) != EOF)
        {
                freqs[c]++;
        }

        for(i=0; i<256; i++)
        {
                if(freqs[i])
                {
                        printf("char code %3d ",i);
                        for(j=0; j<freqs[i] && j<77; j++)
                        {
                                printf("%c", 35);
                        }
                        printf("\n");
                }
        }
        return 0;
}
