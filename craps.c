#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int roll_dice(void);
bool play_game(void);

int main() {

    srand(time(NULL));
    bool state;
    int win, lose;
    char user_reply[2];

    win = 0;
    lose = 0;

    do {
	state = play_game();

	if (state) {
	    printf("You win!\n");
	    win++;
	} else {
	    printf("You lose!\n");
	    lose++;
	}

	printf("\nPlay again?(y/n) ");
	scanf("%s", user_reply);
    } while (strcmp(user_reply, "y") == 0);

    printf("\nWins: %d\t Losses: %d\n", win, lose);
    return 0;
}

int roll_dice(void) {

    rand();
    int dice1, dice2, rnd;

    rnd = rand();
    dice1 = (rnd % 6) + 1;
    rnd = rand();
    dice2 = (rnd % 6) + 1;

    return (dice1+dice2);
}

bool play_game(void) {
    int result;
    int point;

    point = 0;
    for (;;) {
	result = roll_dice();
	printf("You rolled: %d\n", result);

	switch (result) {
	    case 2:
	    case 3:
	    case 12:
		return false;
		break;
	    case 7:
	    case 11:
		return true;
		break;
	    default:
		if (point == result) {
		    return true;
		}
		if (point == 0) {
		    point = result;
		    printf("Your point is %d\n", point);
		}
		break;
	};
    }
}

