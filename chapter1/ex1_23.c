#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 100000

void decomment(char *buf, int size);

int main()
{
        int fd_src, fd_dest, retval;
        char buf[BUFSIZE]="";

        fd_src = open("ex1_23.c", O_RDONLY);
        if(fd_src<0)
        {
                fprintf(stderr, "Error while opening file.\n");
                return -1;
        }

        fd_dest = open("ex1_23_out.c", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(fd_dest<0)
        {
                fprintf(stderr, "Error while opening file2.\n");
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
        {
                decomment(buf, retval);
                if(write(fd_dest, buf, retval) != retval)
                {
                        fprintf(stderr, "Error while writing to file.\n");
                        return -1;
                }
                fprintf(stdout, "%d bytes have been written.\n",retval);
        }

        retval = close(fd_src);
        if(retval)
        {
                fprintf(stderr, "Error while closing file.\n");
                return -1;
        }

        retval = close(fd_dest);
        if(retval)
        {
                fprintf(stderr, "Error while closing file.\n");
                return -1;
        }
        return 0;
}

/* decomment: this function removes comments from buf replacing their content with blanks. */
/* The original spacing will be preserved. */
/* size is the length of the buffer. */
void decomment(char *buf, int size)
{
        int i;
        int in_comment1 = 0;            /* single-line comments: these comments will be replaced by blanks. */
        int in_comment2 = 0;            /* multi-line comments: these comments will be replaced by blanks. */

        if(size<3)                      // the minimum length of an empty single-line comment is 3.
                return;                 // the minimum length of an empty multi-line comment is 4.

        for(i=0; i<size-1; i++)
        {
                if(in_comment1 || in_comment2)
                {
                        if(in_comment1 && buf[i] == '\n')
                        {
                                /* newline is not replaced. Furthermore, if buf[size-1] is a newline, it is also not replaced. */
                                in_comment1 = 0;
                        }
                        else if(in_comment2 && buf[i] == '*' && buf[i+1] == '/')
                        {
                                buf[i]= ' ';
                                buf[i+1] = ' ';
                                in_comment2 = 0;
                                i++;
                        }
                        else if(buf[i]!=' ' && buf[i]!='\t')
                        {
                                buf[i] = ' ';
                        }
                }
                else if(buf[i] == '/' && buf[i+1]== '/')
                {
                        buf[i] = ' ';
                        buf[i+1] = ' ';
                        in_comment1 = 1;
                        i++;
                }
                else if(buf[i] == '/' && buf[i+1] == '*')
                {
                        buf[i] = ' ';
                        buf[i+1] = ' ';
                        in_comment2 = 1;
                        i++;
                }
        }
}
