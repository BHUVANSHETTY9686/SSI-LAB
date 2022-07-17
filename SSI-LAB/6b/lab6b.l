%{
#include "y.tab.h"


%}
%%
"int"|"float"|"void"|"main"|"printf" {printf("Keyword is:%s\n",yytext);return KEYWORD;}
[a-zA-Z]* {printf("Identifier is:%s\n",yytext);return ID;}
[0-9]+  {yylval=atoi(yytext);printf("Identifier is:%d\n",yylval);return DIGIT;}
[+|-|*|/]+  {printf("Operator is:%s \n",yytext);return OP;}
. ;
%%
