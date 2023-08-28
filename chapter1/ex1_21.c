kit@tlinb:~/c_exercises/ch1$ cat entab.c
#include <stdio.h>

#define MAXLINE 1000

/* the width of a tab is assumed to be 8 characters */
#define TABWIDTH 8

int get_line(char line[], int maxline);
void entab(char line[], int len);

/* print longest input line */
int main()
{
        int len;                /* current line length */
        char line[MAXLINE];     /* current input line */

        while((len = get_line(line, MAXLINE)) > 0)
        {
                entab(line, len);
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

/* entab: replaces the blanks in s with tabs (and blanks) achieving the same spacing */
void entab(char s[], int len)
{
        int i, j, k;
        int num_blanks;
        int num_tabs;
        int offset;

        for(j=len-1; j>=0; j--)
        {
                if(s[j]==' ')
                {
                        for(i=j-1; s[i]==' ' && i>=0; i--)
                                ;

                        k = j+1;
                        num_tabs = 0;
                        num_blanks = 0;

                        for(i=i+1; i<=j && (j+1)%TABWIDTH != 0; j--)
                        {
                                num_blanks++;
                        }

                        for(; i<=j; j=j-TABWIDTH)
                        {
                                num_tabs++;
                        }

                        offset = (k-i) - (num_blanks+num_tabs);

                        for(j=i-1; num_tabs>0; num_tabs--)
                        {
                                s[j+num_tabs] = '\t';
                        }

                        if(offset)
                        {
                                for(; s[k]!='\0'; k++)
                                {
                                        s[k-offset] = s[k];
                                }

                                s[k-offset]=s[k];
                        }
                }
        }
}
kit@tlinb:~/c_exercises/ch1$
