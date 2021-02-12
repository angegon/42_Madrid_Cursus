#include "get_next_line.h"

char    *ft_aux(char *s, char c)
{
    char    *str;
    int     i;
    i = 0;
    while(s[i])
        i++;
    if (!(str = (char *)malloc(i + 2)))
        return(0);
    i = 0;
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = c;
    str[i + 1] = '\0';
    free(s);
    return(str);
}
int     get_next_line(int fd, char **line)
{
    char    *buffer;
    int     flag;
    int     n;
    flag = 0;
    buffer = (char *)malloc(33);
    if (!line || !(*line = malloc(32)) || !buffer)
        return(-1);
    *line[0] = '\0';
    if ((flag = read(fd, buffer, 32)) > 0)
    {
        n = 0;
        while (n < 32)          
        {
            *line = ft_aux(*line, buffer[n]);
            n++;
            if (buffer[n] == '\n')
                {
                n = 0;
                line++;
                }
        }       
    }
    free(buffer);
    return(flag);
}
int main(void)
{
    char *line;
    int fd;
    int r;
    line = 0;
    fd = open("hola.txt", O_RDONLY);
    while((r = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        free (line);
        line = 0;
    } 
    printf("%s", line);
}