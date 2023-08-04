#include <stdio.h>

int get_line(char line[], int maxline);

/* print longest input line */
int main()
{
        char line[81];          /* current input line */

        while(get_line(line, 81) > 0)
                ;

        return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
        int c, i;

        for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
                s[i] = c;
        if(c=='\n')
        {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';

        if(c==EOF || c=='\n')
                return i;

        else
        {
                printf("%s", s);
                while((c=getchar())!=EOF && c!='\n')
                        putchar(c);

                putchar('\n');
                return 1;
        }
}
