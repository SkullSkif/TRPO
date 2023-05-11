#include <stdio.h>
#include <stdlib.h>
#define x 90
#define y 35
#define middle ((int)x / 3)
#define indent 6
#define width 5

void mainmenu()
{
    char interface[y][x];
    int i;
    unsigned char key = ' ';
    while (key!='q')
    {
    system("clear");
    // Окно игры
    for (i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            interface[i][j] = ' ';
    for (i = 0; i < y; i++) {
        interface[i][0] = '#';
        interface[i][x - 1] = '#';
    }
    for (i = 0; i < x; i++) {
        interface[0][i] = '#';
        interface[y - 1][i] = '#';
    }

    // Буквы с названием игры
    for (i = 3; i < 8; i++) {
        interface[i][middle] = '#';
        interface[i][middle + width] = '#';
        interface[i][middle + width + indent] = '#';
        interface[i][middle + width + indent + width] = '#';
        interface[i][middle + width + indent + width + indent] = '#';
        interface[i][middle + width + indent + width + indent + width + 1]
                = '#';
    }

    for (i = middle + 1; i < middle + width; i++)
        interface[5][i] = '#';

    interface[6][middle + width + indent + 1] = '#';
    interface[5][middle + width + indent + 2] = '#';
    interface[4][middle + width + indent + 3] = '#';

    interface[3][middle + width + indent + width + indent + 1] = '#';
    interface[4][middle + width + indent + width + indent + 2] = '#';
    interface[5][middle + width + indent + width + indent + 3] = '#';
    interface[4][middle + width + indent + width + indent + 4] = '#';
    interface[3][middle + width + indent + width + indent + 5] = '#';
    //  for (i = 3;i<8;i++)
    //      {
    //          interface[i][27] = '#';
    //          interface[i][32] = '#';
    //      }
    // interface[4][21] = '#';
    // interface[5][22] = '#';
    // interface[6][23] = '#';

    // interface[3][26] = '#';
    // for (int i = 5;i<8;i++)
    //     interface[i][26] = '#';
    // key=getch();
        
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++)
                printf("%c", interface[i][j]);
            printf("\n");
        }
    key=getchar();
    }
}

int main()
{
    mainmenu();
    system("clear");
    return 0;
}