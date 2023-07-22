#include <stdio.h>

/* count blanks, tabs, and newlines */

main()
{
        int c, nblanks, ntabs, nlines;

        nblanks = 0;
        ntabs = 0;
        nlines = 0;
        while((c=getchar()) != EOF)
        {
                if(c=='\n')
                        ++nlines;
                if(c==' ')
                        ++nblanks;
                if(c=='\t')
                        ++ntabs;
        }
        printf("Lines: %d\nTabs: %d\nBlanks: %d\n", nlines,ntabs,nblanks);
}
