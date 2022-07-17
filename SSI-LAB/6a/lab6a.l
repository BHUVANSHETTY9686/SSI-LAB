%{
	#include<stdio.h>
	int s=0,m=0,flag=0;
%}

%%
"/*" {flag=1;}
"*/" {m++;flag=0;}
"//".* {s++;}
. {if(flag==0) ECHO;}
%% 
int yywrap() {}
int main()
{	
	yyin=fopen("6ain.c","r");
	yyout=fopen("6aout.c","w");
	yylex();
	printf("Number of single line comments: %d \n Number of multi line comments: %d \n",s,m);	
	return 0;
	
}

