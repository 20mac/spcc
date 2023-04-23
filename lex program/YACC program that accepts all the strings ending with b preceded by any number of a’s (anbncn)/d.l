%{
/* Definition section */
#include "d.tab.h"
%}

/* Rule Section */
%%
[aA] {return A;}
[bB] {return B;}
[cC] {return C;}
\n {return NL;}
. {return yytext[0];}
%%

int yywrap()
{
return 1;
}
