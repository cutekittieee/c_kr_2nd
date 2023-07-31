#include <stdio.h>

/* create a histogram of the lengths of the words in the input */
/* v1: horizontal orientation */
/* maximum allowed frequency for each word length: 77 */
/* maximum allowed number of different word lengths: 24 */

int main()
{
        int lengths[24];
        int freqs[24];

        int i, c, nc;

        nc = 0;
        for(i=0; i<24; i++)
        {
                lengths[i] = 0;
                freqs[i] = 0;
        }

        while((c=getchar()) != EOF)
        {
                if(c== ' ' || c== '\n' || c=='\t')
                {
                        if(nc != 0)
                        {
                                for(i=0; i<24; i++)
                                {
                                        if(lengths[i] == nc)
                                        {
                                                freqs[i]++;
                                                break;
                                        }
                                        else if(lengths[i]== 0)
                                        {
                                                lengths[i] = nc;
                                                freqs[i]++;
                                                break;
                                        }
                                }
                                if(i==24)
                                {
                                        printf("The list is full.\n");
                                }
                                nc = 0;
                        }
                }
                else
                {
                        ++nc;
                }
        }

        int j = 23;
        while(j>0)
        {
                for(i=0; i<j; i++)
                {
                        if(lengths[i]>lengths[i+1])
                        {
                                int buf = lengths[i];
                                lengths[i] = lengths[i+1];
                                lengths[i+1] = buf;

                                buf = freqs[i];
                                freqs[i] = freqs[i+1];
                                freqs[i+1] = buf;
                        }
                }
                j--;
        }

        for(i=0; i<24; i++)
        {
                if(lengths[i])
                {
                        int k;
                        printf("%2d ",lengths[i]);
                        for(k=0; k<freqs[i] && k<77; k++)
                        {
                                printf("%c", 35);
                        }
                        printf("\n");
                }
        }
        return 0;
}
