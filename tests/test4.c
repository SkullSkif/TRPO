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

void getStringData(char* filename, int lines_count, char** strObjects) // 
{
    FILE *data;
    char buffer[maxstr] = {};
    data = fopen(filename,"r");
    for (int i = 1;i<lines_count;i++)
    {
        fgets(buffer,maxstr, data);
        for (int j=0;j<strlen(buffer);j++)
        strObjects[i][j]=buffer[j];
    }
}

int main()
{
    char filename[maxvalue] = "values.txt";
    int lines_count = 0;
    lines_count = objectsCount(filename);
    char strObjects[maxvalue][maxstr] = {{"aba"},{"chq"}};
    getStringData(filename, lines_count, &strObjects[0][0]);
    puts(strObjects);
    return 0;
}