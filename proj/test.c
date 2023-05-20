#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#define MAXSTR 255
#define x 90
#define y 35
#define middle ((int)x / 3)
#define indent 6
#define width 5

// void mainmenu()
// {
//     char interface[y][x];
//     int i;
//     unsigned char key = ' ';
//     while (key!='q')
//     {
//     system("clear");
//     // Окно игры
//     for (i = 0; i < y; i++)
//         for (int j = 0; j < x; j++)
//             interface[i][j] = ' ';
//     for (i = 0; i < y; i++) {
//         interface[i][0] = '#';
//         interface[i][x - 1] = '#';
//     }
//     for (i = 0; i < x; i++) {
//         interface[0][i] = '#';
//         interface[y - 1][i] = '#';
//     }

//     // Буквы с названием игры
//     for (i = 3; i < 8; i++) {
//         interface[i][middle] = '#';
//         interface[i][middle + width] = '#';
//         interface[i][middle + width + indent] = '#';
//         interface[i][middle + width + indent + width] = '#';
//         interface[i][middle + width + indent + width + indent] = '#';
//         interface[i][middle + width + indent + width + indent + width + 1]
//                 = '#';
//     }

//     for (i = middle + 1; i < middle + width; i++)
//         interface[5][i] = '#';

//     interface[6][middle + width + indent + 1] = '#';
//     interface[5][middle + width + indent + 2] = '#';
//     interface[4][middle + width + indent + 3] = '#';

//     interface[3][middle + width + indent + width + indent + 1] = '#';
//     interface[4][middle + width + indent + width + indent + 2] = '#';
//     interface[5][middle + width + indent + width + indent + 3] = '#';
//     interface[4][middle + width + indent + width + indent + 4] = '#';
//     interface[3][middle + width + indent + width + indent + 5] = '#';
//         for (int i = 0; i < y; i++) {
//             for (int j = 0; j < x; j++)
//                 printf("%c", interface[i][j]);
//             printf("\n");
//         }
//     key=getchar();
//     }
// }

void mainmenu()
{
    // initscr();
    // WINDOW* screen = newwin(5, 5, 10, 10);
    // box(screen, 0, 0);
    // wrefresh(screen);
    // noecho();
    // curs_set(0);
    // printw("@");
    // getch();
    // endwin();
    int i;
    char str[20];
 
    for (i=0; (str[i]=getchar())!='\n'; i++);
    str[i] = '\0';
    int h = atoi(str);
    printf("\n%d\n", h);
}


int main()
{
    mainmenu();
   // system("clear");
    return 0;
}