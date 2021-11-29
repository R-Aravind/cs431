#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

bool isOperator(char token)
{
	char checks[] = {'+', '-', '*', '/', '%', '='};
	for (int i = 0; i < 6; i++)
	{
		if (token == checks[i])
		{
			return true;
		}
	}
	return false;
}

bool isKeyword(char *str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") || !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "char") || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
		return (true);
	return (false);
}

bool isNumber(char *token)
{
	int idx = 0;
	while (token[idx] != '\0')
	{
		if (!(isdigit(token[idx]) == 1 || token[idx] == '\n' || token[idx] == ' ' || token[idx] == '.'))
		{
			return false;
		}
		idx++;
	}
	return true;
}

bool isDelimiter(char token)
{
	char checks[] = {',', ';', '{', '}', ' '};
	for (int i = 0; i < 5; i++)
	{
		if (token == checks[i])
		{
			return true;
		}
	}
	return false;
}

char *subStr(char *str, int left, int right)
{
	char *subStr = (char *)malloc(sizeof(char) * (right - left + 2));
	for (int i = left; i <= right; i++)
	{
		subStr[i - left] = str[i];
	}
	subStr[right - left + 1] = '\0';
	return (subStr);
}

void checkToken(char *token)
{
	if (isNumber(token))
	{
		printf(" Number : %s	 \n", token);
	}
	else if (isKeyword(token))
	{
		printf(" Keyword : %s	 \n", token);
	}
	else
	{
		printf(" Variable : %s \n", token);
	}
}

void analyze(char *line)
{

	int right = 0, left = 0;

	while (line[right] != '\0' && left <= right)
	{

		if (isDelimiter(line[right]) || isOperator(line[right]))
		{
			if (right != left)
			{
				char *token = subStr(line, left, right - 1);
				checkToken(token);
				left = right;
			}
			else if (isOperator(line[right]))
			{
				printf(" Operator : %c	 \n", line[right]);
				right++;
				left = right;
			}
			else if (isDelimiter(line[right]))
			{
				right++;
				left = right;
			}
			else
			{
				right++;
			}
		}
		else
		{
			right++;
		}
	}

	if (left != right)
	{
		char *token = subStr(line, left, right);
		checkToken(token);
	}

	return;
}

int main(int argc, char *argv[])
{

	if (argc < 2)
	{
		printf("\n Please provide a program to compile. \n\n");
	}
	else if (access(argv[1], F_OK) != 0)
	{
		printf("\n error! program does not exist. \n\n");
	}
	else
	{
		printf("\n Analyzing Program: %s \n\n", argv[1]);
		FILE *program;
		if (program = fopen(argv[1], "r"))
		{
			char line[256];
			while (fgets(line, sizeof(line), program))
			{
				if (line[0] != '\n')
					analyze(line);
			}
			printf("\n End of Program.\n");
		}
		fclose(program);
	}

	return 0;
}
