#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */
#define FOLD_POS 15     /* position before we will attempt to fold a long line */

int get_line(char line[], int maxline);
void fold(char line[], int len);

int main()
{
        int len;                /* current line length */
        char line[MAXLINE];     /* current input line */

        while((len = get_line(line, MAXLINE)) > 0)
        {
                fold(line, len);
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

/* fold: folds long input lines into two or more shorter lines at the FOLD_POS-th column of input. */
void fold(char s[], int len)
{
        int i, j;
        int null_pos = len;
        int chars_left = len;

        for(j=1; len-j >= 0 && (s[len-j]=='\n' || s[len-j]==' ' || s[len-j] == '\t'); j++)
        {
                chars_left--;
        }

        /* Two cases:

        Case A: There is a blank before or at FOLD_POS: The blank is replaced with a newline.
        Case B: There isn't any blank before or at FOLD_POS: At column FOLD_POS we insert a '-' char
                followed by a newline: len increases by 2. It's assumed that there is enough free space in s. */

        for(i=0; s[i]!='\0'; i++)
        {
                if(chars_left < FOLD_POS)
                        break;

                for(j=i+FOLD_POS-1; j>i && s[j]!=' ' && s[j]!='\t'; j--)
                        ;

                /* Case A */
                if(j>i)
                {
                        s[j] = '\n';
                        chars_left = chars_left - (j-i+1);
                        i = j;
                }

                /* Case B */
                else
                {
                        for(j=null_pos; j>=i+FOLD_POS-1; j--)
                        {
                                s[j+2] = s[j];
                        }
                        s[j+1]='-';
                        s[j+2]='\n';
                        i=j+2;
                        chars_left = chars_left - FOLD_POS + 1;
                        null_pos+=2;
                }
        }
}
