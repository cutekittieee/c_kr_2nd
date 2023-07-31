#include <stdio.h>

/* create a histogram of the frequencies of the characters in the input */
/* v2: vertical orientation */
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

        for (j=77; j>0; j--)
        {
                for(i=0; i<256; i++)
                {
                        if(freqs[i])
                        {
                                if(freqs[i]>=j)
                                {
                                        printf("%c",35);
                                }
                                else
                                {
                                        printf(" ");
                                }
                        }
                }
                printf("\n");
        }

        printf("\n");

        for(i=0; i<256; i++)
        {
                if(freqs[i])
                        printf("%d",i/100);
        }
        printf("\n");

        for(i=0; i<256; i++)
        {
                if(freqs[i])
                        printf("%d",(i%100)/10);
        }
        printf("\n");

        for(i=0; i<256; i++)
        {
                if(freqs[i])
                        printf("%d",(i%10));
        }
        printf("\n");

        return 0;
}
