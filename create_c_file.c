#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void writefl(char path[], char datestring[]);
int checkfl(char path[]);
char *dateTime(char datestring[]);

int main(int argc, char *argv[]) {

    int len_path;
    char *path, r; 
    char datestring[30];

    if (argc != 2) {
	printf("Wrong number of args\n");
	return -1;
    }

    len_path = strlen(argv[1]);
    path = (char *)(malloc(sizeof(char)*len_path));

    for (int i = 0; i < len_path; i++) {
	path[i] = argv[1][i];
    }

    if (checkfl(path) == -1) {
	printf("Create a new file? yY\n");
	r = getchar();
	if ((r == 'y') || (r == 'Y')) {
	    printf("Creating file in \"%s\"\n", path);
	} else {
	    return 0;
	}
    }

    writefl(path, datestring);
    
    free(path);
    return 0;
}


int checkfl(char path[]) {

    if (access(path, F_OK) == -1) {
	printf("File or path doesn't exist yet!\n");
	return -1;
    } else  {
	return 0;
    }
}

void writefl(char path[], char datestring[]) {
    FILE *fp;

    fp = fopen(path, "w+");
    fprintf(fp, "#include <stdio.h>\n");
    fprintf(fp, "#include <stdlib.h>\n");
    fprintf(fp, "\n\n");
    fprintf(fp, "/**************************\n");
    fprintf(fp, " * %s", dateTime(datestring));
    fprintf(fp, "\n * created by me in mere 10hours\n");
    fprintf(fp, " **************************/\n\n\n");
    fprintf(fp, "int main()\n{\n");
    fprintf(fp, "\n\n\n\n\n\n");
    fprintf(fp, "    return 0;");
    fprintf(fp, "\n}");
    fclose(fp);

}

char *dateTime(char datestring[])
{
    time_t cur_t;
    struct tm *loc_t;
    char day[3], year[3], month[4];
    char hour[3], min[3];
    
    cur_t = time(NULL);
    loc_t = localtime(&cur_t);

    snprintf(day, sizeof(char) * 3, "%.2d", loc_t->tm_mday);
    snprintf(year, sizeof(char) * 3, "%.2d", loc_t->tm_year % 100);

    switch(loc_t->tm_mon){
	case 0:	    strcpy(month, "Jan"); break;
	case 1:	    strcpy(month, "Feb"); break;
	case 2:	    strcpy(month, "Mar"); break;
	case 3:	    strcpy(month, "Apr"); break;
	case 4:	    strcpy(month, "May"); break;
	case 5:	    strcpy(month, "Jun"); break;
	case 6:	    strcpy(month, "Jul"); break;
	case 7:	    strcpy(month, "Aug"); break;
	case 8:	    strcpy(month, "Sep"); break;
	case 9:	    strcpy(month, "Oct"); break;
	case 10:    strcpy(month, "Nov"); break;
	case 11:    strcpy(month, "Dez"); break;
    }

    snprintf(hour, sizeof(char) * 3, "%.2d", loc_t->tm_hour);
    snprintf(min, sizeof(char) * 3, "%.2d", loc_t->tm_min);

    strcpy(datestring, hour);
    strcat(datestring, ":");
    strcat(datestring, min);
    strcat(datestring, " ");
    strcat(datestring, day);
    strcat(datestring, "/");
    strcat(datestring, month);
    strcat(datestring, "/");
    strcat(datestring, year);

    return datestring;
}
