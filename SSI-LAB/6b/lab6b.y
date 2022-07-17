%{
 #include<stdio.h>
 #include<stdlib.h>
int yyerror();
int yylex();
extern FILE *yyin;
int id=0,digit=0,operator=0,key=0;
%}
%token ID DIGIT OP KEYWORD
%% 
input:ID input{ id++;}
     |ID {id++;}
     |DIGIT input{digit++;}
     |DIGIT {digit++;}
     |OP input{operator++;}
     |OP {operator++;}
     |KEYWORD input{ key++;}
     |KEYWORD {key++;}
     ;
%%
void main()
{
	yyin=fopen("lab6b.c","r");
	yyparse();
	printf("count of identifier is %d\n",id);

	printf("count of digit is %d\n",digit);

	printf("count of operator is %d\n",operator);


	printf("count of identifier is %d\n",key);
}
int yyerror()
{
	printf("invalid");
}
