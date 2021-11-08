#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <stdbool.h> 

bool isOperator(char token) {
	char checks[] = {'+', '-', '*', '/', '%', '='};
	for (int i=0; i<=sizeof(checks); i++) {
		if(token == checks[i]) {
			return true;		
		}
	}
	return false;
}

bool isKeyword(char *token) {}

bool isNumber(char *token) {}

bool isVariable(char *token) {}

bool isDelimiter(char token) {
	char checks[] = {',', ';', '{', '}', ' '};
	for (int i=0; i<=sizeof(checks); i++) {
		if(token == checks[i]) {
			return true;		
		}
	}
	return false;
}

char* subStr(char* line, int left, int right) {
	char str = (char *) malloc (right - left + 2);
}

void analyze(char* line) {
		
	int left = 0, i=0;
	while(line[i]) {

		printf("%c", line[i]);

		if(isOperator(line[i])) printf(" - operator");

		if (isDelimiter(line[i]) || isOperator(line[i])) {
			if (i - left > 0) {			
				if(isNumber)) printf(" - number");
				if(isKeyword(line, left, i)) printf(" - number");
				if(isVariable(line, left, i)) printf(" - variable");
			}
			left = i+1;
		}
	i++;	
	}

	return;
	
}

int main(int argc, char*argv[]) {
	
	if (argc < 2) {

		printf("\n Please provide a program to compile. \n\n");

	} else if (access(argv[1], F_OK) != 0) {

		printf("\n error! program does not exist. \n\n");

	} else {

		printf("\n Analyzing Program: %s \n\n", argv[1]);
		
		FILE *program;

		if (program = fopen(argv[1], "r")) {
			
			char line[256];
			while(fgets(line, sizeof(line), program)) {

				analyze(line);
				printf("\n%s\n", line);				

			} 

			printf("\n End of Program.\n");

		}

		fclose(program);
	}
	
	return 0;
}
