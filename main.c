#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxvalue 100
#define maxstr 255

int objectsCount(char* filename) //  кол-во строк в файле
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

int main()
{
    
    char filename[maxvalue] = "values.txt";
    FILE *data;
    data = fopen(filename,"r");
    int lines_count = 0;
    lines_count = objectsCount(filename);
    char strObjects[maxvalue][maxstr] = {{}}; // объявляю и инициализирую двумерный массив куда буду помещать строки
    for (int i=0;i<lines_count;i++)
    fgets(strObjects[i],maxstr,data); // считываю строки с файла
    fclose(data);
    return 0;
}