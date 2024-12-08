#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *tr()
{
char word[] = "Hello world";

    char *newWord = (char*)malloc(sizeof(char) * strlen(word));

    char *value = strtok(word, " ");
    value = strtok(NULL, " ");
    newWord = value; 
    // printf("%d\n", strlen(word));
    // printf("%s\n", word);
    // printf("%s\n", newWord);

    return newWord;
}

int main(void)
{
    
    printf("%s\n", tr());
    return 0;
}
