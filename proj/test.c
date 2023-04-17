#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
struct heap
{
    char name;
    int count;
};
typedef struct heap heap;

void print_heap()
{
    FILE *file;
    file = fopen("text.txt", "r");
    char str1[100];
    int numberheap = 0;
    char slash = '\n';
    while (fgets(str1, 99, file))
    {
        numberheap++;
        for (int i = 0; i < strlen(str1); i++)
        {
            if (str1[i] == slash)
            {
                str1[i] = str1[i + 1];
                break;
            }
        }
        if (numberheap == 1)
        {
            printf("| %s |", str1);
        }
        else
        {
            printf(" %s |", str1);
        }
    }
    printf("\n");
    fclose(file);
}

int main()
{
    print_heap();
    return 0;
}