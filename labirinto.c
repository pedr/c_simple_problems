#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main()
{
    char map[10][10];
    int letters[26];

    for (int i = 0; i < 26; i++) {
        letters[i] = 65 + i;
    }


    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 10; k++) {
            map[i][k] = '.';
        }
    }

    // posição incial:
    int x, y;
    x = 0;
    y = 0;
    int movement;
    int west, east, north, south;
    int getout;
    srand((unsigned) time(NULL));


    map[x][y] = letters[0];

    for (int i = 1; i < 26; i++) {
    /* se if testa se o tile x++/x--/y++/y-- tem o caracter '.' nele, se não tiver muda a variavel aka torna falso */
        west = east = north = south = 1;
        if (map[x-1][y] != '.') {
            north = 0;
        }
        if (map[x+1][y] != '.') {
            south = 0;
        }
        if (map[x][y+1] != '.') {
            east = 0;
        }
        if (map[x][y-1] != '.') {
            west = 0;
        }
        if ((north + south + east + west) == 0) {
            i = 27;
            continue;
        }
        getout = 1;
	int count_if_is_stuck = 0;
        while (getout) {
            movement = rand() % 4;
            switch (movement) {
                case 0:
                    if (south && (x < 9)) {
                        x++;
                        getout = 0;
                    } break;
                case 1:
                    if (north && (x > 0)) {
                        x--;
                        getout = 0;
                    } break;
                case 2:
                    if (east && (y < 9)) {
                        y++;
                        getout = 0;
                    } break;
                case 3:
                    if (west && (y > 0)) {
                        y--;
                        getout = 0;
                    } break;
                }
		count_if_is_stuck++;
		if (count_if_is_stuck == 50) {
		    for (int j = 0; j < 10; j++) {
			for (int m = 0; m < 10; m++) {
			printf("%c ", map[j][m]);
		    }
		    printf("\n");
		    }
		    return 1;
		}
            }
        map[x][y] = letters[i];
    }

    for (int j = 0; j < 10; j++) {
        for (int m = 0; m < 10; m++) {
            printf("%c ", map[j][m]);
        }
        printf("\n");
    }

    return 0;
}
