#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int get_line(char line[], int maxline);

/* print longest input line */
int main()
{
        int len;                /* current line length */
        char line[MAXLINE];     /* current input line */

        while((len = get_line(line, MAXLINE)) >= 0)
                if(len)
                {
                        printf("%s", line);
                }

        return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
        int c, i, space;

        space = 0;

        for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
                s[i] = c;
        if(c=='\n')
        {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        i--;
        while(i>= 0 && (s[i]==' ' || s[i] == '\t' || s[i] == '\n'))
        {
                if(s[i] == '\n')
                        space = 1;
                s[i] = '\0';
                i--;
        }

        if((i==-1) && (c==EOF))
                return -1;
        else if (i==-1)
                return 0;
        else
        {
                i++;
                if(space)
                {
                        s[i]='\n';
                        i++;
                }
                return i;
        }
}
