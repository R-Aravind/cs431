%{
#include<stdio.h>
int single=0;
int multi=0;    
%}
%%
"//".*\n  {++single;}
"/*"[^*/]*"*/"  {++multi;}
%%
int main(int argc, int **argv)
{
    yyin=fopen("abc.txt","r+");
    yylex();
    printf("no of single line comment = %d ", single);
    printf("no of multi line comment = %d ", multi);
    return 0;
}
