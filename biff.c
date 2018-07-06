#include <stdio.h>

#define MAX_SIZE 200

int main (void) {
    
    char phrase[MAX_SIZE];
    int k;
    k = 0;
    printf("Enter the message: ");

    fgets(phrase, MAX_SIZE, stdin);

    while ((phrase[k] != '\0') &&  (phrase[k] != '\n')) {
	if (((phrase[k] > 64) && (phrase[k] < 91)) ||
	    ((phrase[k] > 96) && (phrase[k] < 123))) {
	    switch(phrase[k]) {
		case 'a':
		case 'A':
		    printf("4");
		    break;
		case 'b':
		case 'B':
		    printf("8");
		    break;
		case 'e':
		case 'E':
		    printf("3");
		    break;
		case 'i':
		case 'I':
		    printf("1");
		    break;
		case 'o':
		case 'O':
		    printf("0");
		    break;
		case 's':
		case 'S':
		    printf("5");
		    break;
		default:
		    if ((phrase[k] > 64) && (phrase[k] < 91)) {
			printf("%c", phrase[k]);
		    } else {
			printf("%c", phrase[k] - 32);
		    }
		    break;
	    }
	} else {
	    printf("%c", phrase[k]);
	}
    k++;
    }
    printf("!!!!!!!!");

    return 0;
}

