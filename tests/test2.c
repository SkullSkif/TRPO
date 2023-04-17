#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxvalue 100
#define maxstr 255

int objectsCount(char* filename)
{
    FILE *data;
    int count;
    data = fopen(filename,"r");
    while (! feof(data))
    {
        if (fgetc(data) == '\n')
            count++;
    }
    count++;
    fclose(data);
    return count;
}

void getStringData(char* filename, int lines_count, char* strObjects) // 
{
    FILE *data;
    data = fopen(filename,"r");
}

int main()
{
    char filename[maxvalue] = "values.txt";
    int lines_count = 0;
    lines_count = objectsCount(filename);
    char strObjects[maxvalue];
    for (int i=0;i<lines_count;i++)
        strObjects[i] = (char*)malloc(sizeof(char) * maxstr);
    //char strObjects[maxvalue][maxstr] = {{"aba"},{"chq"}};
    //getStringData(filename, lines_count, strObjects);
    //puts(strObjects);
    return 0;
}