#include <stdio.h>
#include <stdlib.h>
void Warning(char *message)
{
    fprintf(stderr,"%s\n",message);
}
void Error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(EXIT_FAILURE);
}