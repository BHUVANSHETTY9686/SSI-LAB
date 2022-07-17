%{
	#include<stdio.h>
	#include<stdlib.h>
	int yylex();
	int yyerror();
	
%}
%token NUM ENTER
%left '+' '-'
%left '/' '*'
%% 
start:EXPR ENTER { printf("Valid Expression:%d\n",$$); exit(0);}
EXPR:EXPR '+' EXPR {$$=$1 + $3;}	
	|EXPR '-' EXPR {$$=$1 - $3;}
	|'-' EXPR {$$= - $2;}
	|EXPR '*' EXPR {$$=$1 * $3;}
	|EXPR '/' EXPR {if($3==0) {printf("Division by zero\n");exit(0);} else $$=$1/$3;}
	|'(' EXPR ')' {$$=$2;}
	|NUM {$$=$1;}
%% 
void main()
{
	printf("Enter the expression\n");
	yyparse();
}
		
int yyerror()
{
	printf("Invalid expression\n");
	return 0;
}

