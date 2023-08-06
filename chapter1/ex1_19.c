#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int get_line(char line[], int maxline);
void reverse(char s[]);

/* print longest input line */
int main()
{
        int len;                /* current line length */
        char line[MAXLINE];     /* current input line */

        while((len = get_line(line, MAXLINE)) > 0)
        {
                        reverse(line);
                        printf("%s",line);
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

/* reverse: reverses the string s */
void reverse(char s[])
{
        int i=MAXLINE-1;
        char buf;
        int end = 0;

        while(s[end]!='\0' )
                end++;

        end--;

        while(s[end]==' ' || s[end]=='\n' || s[end]==' ' || s[end]=='\t')
                end--;

        for(i=0; i<end-i; i++)
        {
                buf = s[end-i];
                s[end-i] = s[i];
                s[i] = buf;
        }

}
