#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NP_WARNINGS

int Lcount(FILE* f) {
	int count = 0;
	char chr[10000];
	while (1) {
		if (feof(f) != 0) {
			break;
		}
		fgets(chr, sizeof(chr), f);
			count++;
	}
	return count;
}
int Wcount(FILE* f) {
	int count = 0, n = 0;;
	char chr[10000];
	while (1) {
		if (feof(f)) {
			break;
		}
		fgets(chr, sizeof(chr), f);
		while (1) {
			if (chr[n] == 32) {
				count++;
				n++;
			}
			else if (chr[n] == 0) {
				n = 0;
				break;
			}
			else {
				n++;
			}
		}
	}
	return count;
}
int Ccount(FILE* f) {
	int count = 0, n = 0;;
	char chr[10000];
	while (1) {
		if (feof(f) != 0) {
			break;
		}
			fgets(chr, sizeof(chr), f);
			while (1) {
			if (chr[n] > 32 && chr[n] < 126) {
				count++;
				n++;
			}
			else if (chr[n] == 0) {
				n = 0;
				break;
			}
			else {
				n++;
			}
		}
	}
	return count;
}
FILE* reverse(FILE* f,char* fname) {
	FILE* newf;
	char newchr[10000] = { 0 };
	int n = 0;
	newf = fopen(fname, "w");
	while (!feof(f)) {
		char c = fgetc(f);
		if (c > 64 && c < 91) {
			fprintf(newf, "%c", c + 32);
		}
		else if (c > 96 && c < 123) {
			fprintf(newf, "%c", c - 32);
		}
		else {
			fprintf(newf, "%c", c);
		}
		n++;
	}
	fprintf(newf, "%s", newchr);
	return newf;
}

int main(int argc, char* argv[]) {

	FILE* f,* newf;
	if ((f = fopen(argv[1], "r")) == NULL) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}
	printf("line count :		%d\n", Lcount(f));
	rewind(f);
	printf("word count :		%d\n", Wcount(f));
	rewind(f);
	printf("character count :	%d\n", Ccount(f));
	rewind(f);

	char* fname = "REVParadigmShift.txt";
	newf = reverse(f,fname);
	if (newf == NULL) {
		printf("파일이 저장되지 않았습니다.\n");
		exit(1);
	}
	else {
		printf("파일이 저장되었습니다.\n");
	}
	fclose(newf);
	fclose(f);
	system("pause");
	return 0;
}
