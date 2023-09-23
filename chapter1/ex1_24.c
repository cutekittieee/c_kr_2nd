#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 100000

void check_errors(char *buf, int size);

int main()
{
        int fd_src, retval;
        char buf[BUFSIZE]="";

        fd_src = open("ex1_24.c", O_RDONLY);
        if(fd_src<0)
        {
                fprintf(stderr, "Error while opening file.\n");
                return -1;
        }

        retval = read(fd_src, buf, BUFSIZE);
        if(retval<0)
        {
                fprintf(stderr, "Error while reading file.\n");
                return -1;
        }
        fprintf(stdout, "%d bytes have been read.\n",retval);

        if(retval)
                check_errors(buf, retval);

        retval = close(fd_src);
        if(retval)
        {
                fprintf(stderr, "Error while closing file.\n");
                return -1;
        }

        return 0;
}

/* check_errors: this function checks a C program (stored in buf) for rudimentary syntax errors and prints the report. */
/* The buffer has to be zero terminated at buf[size]. */
/* Size is the length of the buffer not including the terminating zero. */
void check_errors(char *buf, int size)
{
        int i;
        int in_comment1 = 0;
        int in_comment2 = 0;
        int errors_sum = 0;
        int parantheses = 0;
        int brackets = 0;
        int braces = 0;
        int quotes = 0;
        int dquotes = 0;
        int escape_seq_errors = 0;
        int comment_errors = 0;

        for(i=0; i<size; i++)
        {
                // we don't check for syntax errors within C code comments
                if(in_comment1 || in_comment2)
                {
                        if(in_comment1 && buf[i] == '\n')
                        {
                                in_comment1 = 0;
                        }
                        else if(in_comment2 && buf[i] == '*' && buf[i+1] == '/')
                        {
                                in_comment2 = 0;
                                i++;
                        }
                }
                else if(buf[i] == '/' && buf[i+1]== '/')
                {
                        in_comment1 = 1;
                        i++;
                }
                else if(buf[i] == '/' && buf[i+1] == '*')
                {
                        in_comment2 = 1;
                        i++;
                }

                // (if we are outside code comments) this expression means that the start of the comment is missing
                else if(buf[i] == '*' && buf[i+1] == '/')
                {
                        comment_errors++;
                        i++;
                }

                // escape sequences
                else if(buf[i] == '\\')
                {
                        switch(buf[i+1])
                        {
                                case 'a':
                                        break;
                                case 'b':
                                        break;
                                case 'f':
                                        break;
                                case 'n':
                                        break;
                                case 'r':
                                        break;
                                case 't':
                                        break;
                                case 'v':
                                        break;
                                case '\\':
                                        break;
                                case '\'':
                                        break;
                                case '\"':
                                        break;
                                case '\?':
                                        break;
                                default:
                                        escape_seq_errors++;
                        }
                        i++;
                }

                // we are outside of comments and escape sequences
                else
                {
                        switch(buf[i])
                        {
                                case '(':
                                        parantheses++;
                                        break;
                                case ')':
                                        parantheses--;
                                        break;
                                case '[':
                                        brackets++;
                                        break;
                                case ']':
                                        brackets--;
                                        break;
                                case '{':
                                        braces++;
                                        break;
                                case '}':
                                        braces--;
                                        break;
                                case '\'':
                                        quotes++;
                                        break;
                                case '\"':
                                        dquotes++;
                                        break;
                        }
                }
        }

        // the code ends without properly closing the comments
        if(in_comment2)
        {
                comment_errors++;
        }

        // parantheses are unbalanced
        if(parantheses)
                errors_sum++;
        if(brackets)
                errors_sum++;
        if(braces)
                errors_sum++;

        // quotes are unbalanced (this is only checked outside of comments)
        if(quotes%2 == 1)
                errors_sum++;
        if(dquotes%2 == 1)
                errors_sum++;

        // we have found some unknown escape sequences
        if(escape_seq_errors)
                errors_sum++;

        // we have found some commenting errors
        if(comment_errors)
                errors_sum++;

        if(errors_sum)
        {
                printf("The program has found %d different types of syntax errors.\n\n",errors_sum);
                if(parantheses)
                        printf("There is/are %d missing ( or ) character(s) in the code.\n",abs(parantheses));
                if(brackets)
                        printf("There is/are %d missing [ or ] character(s) in the code.\n",abs(brackets));
                if(braces)
                        printf("There is/are %d missing { or } character(s) in the code.\n",abs(braces));
                if(quotes%2 == 1)
                        printf("There are some missing \' characters in the code.\n");
                if(dquotes%2 == 1)
                        printf("There are some missing \" characters in the code.\n");
                if(escape_seq_errors)
                        printf("There is/are %d invalid escape sequence(s) in the code.\n",escape_seq_errors);
                if(comment_errors)
                        printf("There is/are %d incorrectly formatted comment(s) in the code.\n",comment_errors);
        }
        else
        {
                printf("The program hasn\'t found any syntax errors in your code.\n");
        }
}
