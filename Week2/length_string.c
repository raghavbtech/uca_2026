# include <stdio.h>


int str_len (const char *str)
{
    int count = 0;

    while ( *str != '\0')
    {
        count++;
        str++;
    }
    return count;
}


int main () 
{
    char str[] = "Hello World";
    printf( "Length: %d \n", str_len(str));
    return 0;
}