#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char kor[100];
	char eng[100];
} word;

typedef struct{
	int size;
	word* words;
} Dict;

/*
int read(char* file, word dict[], int *no) {
	FILE *fp = NULL;
	fp = fopen(file, "r");
	if(fp == NULL) {
		printf("* unable to open file %s.\n", file);
		return -1;
	}

	int count = 0;
	while(1) {
		if(fscanf(fp, "%s %s", dict[i].eng, dict[i].kor) == EOF) {
			*no = i;
			return 0;
		}
		while(getc(fp) != '\n');

		int len = strlen(dict[i].kor) - 1;
		if(dict[i].kor[len] == ',')
			dict[i].kor[len] = '\0';

		printf("%2d: %s -> %s\n", i, dict[i].eng, dict[i].kor);
	}
	fclose(fp);
	return 0;
}

char* search(word* dict, int no, char* query) {


}
*/

Dict* newDict(const char* path) {
	FILE* fp = NULL;
	fp = fopen(path, "r");
	if(fp == NULL) {
		printf("* error. unable to open file %s.\n", path);
		return NULL;
	}
	Dict* d = (Dict*)malloc(sizeof(Dict));
	word w[6000];

	int count = 0;
	while(1) {
		if(fscanf(fp, "%s %s", w[count].eng, w[count].kor ) == EOF)
			break;
		while(fgetc(fp) != '\n');
		int len = strlen(w[count].kor) - 1;
		if(w[count].kor[len] == ',')
			w[count].kor[len] = '\0';

		count++;
	}
	d->size = count;
	d->words = (word*)malloc(sizeof(word) * count);
	for(int i = 0; i < count; i++) {
		strcpy(d->words[i].kor, w[i].kor);
		strcpy(d->words[i].eng, w[i].eng);
	}

	return d;
}

int main(void) {
	Dict* d = NULL;
	char input[100];
	d = newDict("./engkordic.txt");
	while(1) {
		gets(input);
		if(strlen(input) == 0) {
			printf("==== End Program ====\n");
			break;
		}
		find(input);
	}

}
