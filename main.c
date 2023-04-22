#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define maxvalue 100
#define maxstr 255

struct Point
{
    int x;
    int y;
};
typedef struct Point point;

struct Circle
{
    double rad;
    point* coord;
};
typedef struct Circle circle;

void checkFile()
{
    FILE* data;
    if ((data = fopen("values.txt", "r"))==NULL)
    {
    printf("Файл с входными данными не обнаружен.\n");
    exit(1);
    }
}


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

void checkName(char* strObject)
{
    char strTemplateCircle[maxstr] = {"circle(0 0, 1.5)"};
    char strName[maxstr];
    int i = 0;
    while ((strName[i]>96) & (strName[i]<123))
    {
        strName[i] = tolower(strObject[i]);
        i++;

    }
    
    
    for (int i = 0;i<=strlen(strName);i++)
    {
        if (strName[i]!=strTemplateCircle[i])
        {
            printf("Ошибка в %d символе, неверно введена фигура ожидалось circle", i);
            exit(1);
        }
    }

}

void checkColumn(char* strObject)
{
    if (strObject[6]!='(')
    {
        printf("Ошибка в 6 символе, ожидалось (");
        exit(1);
    }
}

int checkPointX(char* strObject, circle* Object)
{
    int i = 7;
    int j = 0;
    char number[maxstr] = {'a',};
    while (isdigit(strObject[i]))
    {
        number[j]=strObject[i];
        j++;i++;
    }
    Object->coord->x= atoi(number);
    if (number[0]=='a')
    {
        printf("Ошибка в координате X, ожидалось целое число");
        exit(1);

    }
    return i;
}

int checkPointY(char* strObject, circle* Object, int i)
{
    int j = 0;
    char number[maxstr] = {'a',};
    while (!isdigit(strObject[i]))
        i++;
    while (isdigit(strObject[i]))
    {
        number[j]=strObject[i];
        j++;i++;
    }
    Object->coord->y= atoi(number);
    if (number[0]=='a')
    {
        printf("Ошибка в координате Y, ожидалось целое число");
        exit(1);

    }
    return i;
}

void checkPointRad(char* strObject, circle* Object,int i)
{
    int j = 0;
    char number[maxstr] = {'a',};
    while (!isdigit(strObject[i]))
        i++;
        while (isdigit(strObject[i]))
    {
        number[j]=strObject[i];
        j++;i++;
    }
    if (i=='.')
    {
        i++;
        while (isdigit(strObject[i]))
        {
        number[j]=strObject[i];
        j++;i++;
        }
    }
    Object->rad=atof(number);
    if (number[0]=='a')
    {
        printf("Ошибка в радиусе, ожидалось число");
        exit(1);

    }
    if (strObject[i+1]!=')')
    {
        printf("Ошибка в %d символе, ожидалась )",i);
        exit(1);
    }
}


void checkError(char* strObject,circle* Object);
{
    //char strTemplateCircle[maxstr] = {"circle(0 0, 1.5)"};
        checkName(strObject);
        checkColumn(strObject);
        checkPointY(strObject,Object,checkPointX(strObjects[i])

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