%{
	#include<stdio.h>
	#include<stdlib.h>
	int yylex();
	int yyerror();
%}
%token A B ENTER
%%
start:S ENTER {printf("Grammar is correct\n"); exit(0); }
S:L B|B 
L: A| A L

%%
void main()
{
	printf("Enter string:\n");
	yyparse();
}
int yyerror()
{
	printf("Invalid\n");
	return 0;
}
