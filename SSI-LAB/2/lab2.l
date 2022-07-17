%{
	#include "y.tab.h"
%}
%% 
"a" {return A;}
"b" {return B;}
"\n" {return ENTER;}
. {printf("Invalid expression\n");exit(0);}
%%

