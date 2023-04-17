#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define maxstr 255

struct heap
{
    char name;
    int stock;
};
typedef struct heap heap;

struct player
{
    char nameOfPile;
    int countOfItems;
};
typedef struct player player;

heap* getPiles()                                 // Функция считывает с файла данные и возвращает массив структур
{
    FILE* file;
    file = fopen("text.txt","r");
    int pile_count = 3;                                                 // Количество куч, потом можно сделать будет чтоб пользователь сам выбирал
    heap * pile_status = (heap *) calloc(pile_count, sizeof(heap));     // Динамически выделяю память под массив структур куч
    char strPile[maxstr] = " ";                                         // Сюда пойдет вся строка с файла
    char number[maxstr] = {};                                           // Сюда пойдут только числа после буквы и пробела(третий по счету символ) с строки
    int j = 0;
    for (int i = 0;i<=pile_count;i++)
    {
        fgets(strPile,maxstr,file);
        pile_status[i].name = strPile[0];                               // Записываю имя кучи из файла
        for (int i = 2;i<=strlen(strPile);i++)                          // Весь этот for чтобы скопировать из файла число в number
        {
            number[j] = strPile[i];
            j++;
        }
        j = 0;
        pile_status[i].stock = atoi(number);                            // Приводим число в number в int и записываем в структуру
    }
    return pile_status;
}

player* getPlayerPile()
{
    player * move = (player *) calloc(1, sizeof(player)); 
    char strPile[maxstr] = "";
    char number[maxstr] = {}; 
    int j = 0;
    scanf("%s",strPile);
    strPile[0] = toupper(strPile[0]);
    move->nameOfPile = strPile[0];
    for (int i = 1;i<=strlen(strPile);i++)                          
    {
        number[j] = strPile[i];
        j++;
    }
    j = 0;
    move->countOfItems = atoi(number);    

    return move;
}

void game(heap* pile_status)
{
    char playername = '2';
    while ((pile_status[0].stock + pile_status[1].stock + pile_status[2].stock) > 0)
    {
        if (playername == '1') playername = '2'; else playername = '1';
        printf("| %c%d | %c%d | %c%d |\n", pile_status[0].name,pile_status[0].stock,pile_status[1].name,pile_status[1].stock,pile_status[2].name,pile_status[2].stock);
        printf("Ход игрока %c\n", playername);
        player* move = getPlayerPile();
        for (int i = 0;i<=3;i++)
            {
                if (move->nameOfPile == pile_status[i].name) pile_status[i].stock -= move->countOfItems;
            }
        for (int i = 0;i<=3;i++)
        if (pile_status[i].stock < 0) pile_status[i].stock = 0;
        
    }
    printf("\nПобеда игрока %c\n", playername);
}



int main()
{
    heap* pile_status = getPiles();
    //player* move = getPlayerPile();
    game(pile_status);
    free(pile_status);
    return 0;
}