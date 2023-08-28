#include <stdio.h>

#define MAXLINE 1000

/* the width of a tab is assumed to be 8 characters */
#define TABWIDTH 8

int get_line(char line[], int maxline);
void detab(char line[], int len);

/* print longest input line */
int main()
{
        int len;                /* current line length */
        char line[MAXLINE];     /* current input line */

        while((len = get_line(line, MAXLINE)) > 0)
        {
                detab(line, len);
                printf("%s", line);
        }

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
        return i;
}

/* detab:       replaces the tabs in s with blanks achieving the same spacing
                if the resulting string would be longer than MAXLINE,
                the function stops and returns */
void detab(char s[], int len)
{
        int last_i = len;
        int i;
        int j;
        int offset;

        for(i=0; s[i]!='\0'; i++)
        {
                if(s[i]=='\t')
                {
                        offset = 8-(i%8)-1;
                        if(last_i+offset > MAXLINE-1)
                                break;

                        for(j=last_i; j>i; j--)
                        {
                                s[j+offset] = s[j];
                        }

                        last_i = last_i + offset;
                        for(; offset>=0; offset--)
                        {
                                s[j+offset] = ' ';
                        }
                }
        }
}
