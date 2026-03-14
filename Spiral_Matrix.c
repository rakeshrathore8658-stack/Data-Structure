/* Spiral Matrix */

#include <stdio.h>
#include <conio.h>

void main()
{
    int i, j, k = 1;
    int x = 1, y = 1;

    clrscr();

    for (j = 4; j >= 1; j--)
    {
        for (i = 1; i <= 8 * j; i++)
        {
            (i <= (j * 2 + 1)) ? (x += 5) :
            (i <= (j * 4 + 1)) ? (y += 3) :
            (i <= (j * 6 + 1)) ? (x -= 5) : (y -= 3);

            gotoxy(x, y);
            printf("%d", k++);
        }
    }

    printf(" %d", k);
    getch();
}