#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[32] = {0};
    char buff[32] = {0};
    int j = 0;
    int len;

    printf("Enter a sequence of brackets: ");
    gets(str);
    len = strlen(str);

    if(str[0] == ')' || str[0] == ']' || str[0] == '}')
    {
        printf("FALSE\n");
        exit(1);
    }
    else if(str[len-1] == '(' || str[len-1] == '[' || str[len-1] == '{')
    {
        printf("FALSE\n");
        exit(1);
    }
 
    for(int i=0; str[i] != '\0'; i++)
    {
        if(str[i] == '(')
        {
            buff[j] = str[i];
            j++;
            continue;
        }
        else if(str[i] == ')' && buff[j-1] == '(')
        {
            j--;
            continue;
        }
        else if(str[i] == '[')
        {
            buff[j] = str[i];
            j++;
            continue;
        }
        else if(str[i] == ']' && buff[j-1] == '[')
        {
            j--;
            continue;
        }
        else if(str[i] == '{')
        {
            buff[j] = str[i];
            j++;
            continue;
        }
        else if(str[i] == '}' && buff[j-1] == '{')
        {
            j--;
            continue;
        }
        else 
        {
            printf("FALSE\n");
            exit(1);
        }
    }

    printf("TRUE\n");

    return 0;
}
