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

void getStringData(char* filename, char* buffer) // 
{
    FILE *data;
    data = fopen(filename,"r");
    fgets(buffer,maxstr-1,data);
   // return buffer;
}

int main()
{
    
    char filename[maxvalue] = "values.txt";
    FILE *data;
    data = fopen(filename,"r");
    int lines_count = 0;
    lines_count = objectsCount(filename);
    char buffer[maxstr] = {};
    char strObjects[maxvalue][maxstr] = {{}};
    
    for (int i=0;i<lines_count;i++)
    {
        getStringData(filename, buffer);
        for (int j=0;j<maxstr;j++)
        {
            getc(data);
            strObjects[i][j] = buffer[j];
        
        }
    }
    return 0;
}