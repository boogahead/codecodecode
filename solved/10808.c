#include <stdio.h>
#include <string.h>
int main(void)
{
    char string[100];
    scanf("%s",string);
    int alph[26];
    for(int i=0;i<26;i++)
    {
        alph[i]=0;
    }
    for(int i=0;i<strlen(string);i++)
    {
        alph[string[i]-97]++;
    }
    for(int i=0;i<26;i++)
    {
        printf("%d ",alph[i]);
    }
    printf("\n");
    return 0;
}
