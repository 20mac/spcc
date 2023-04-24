%{
#include <stdio.h>
int c = 0;
%}
%%
while|if|else|int|float {c++; printf("keyword: %s\n", yytext);}
[a-zA-Z_][a-zA-Z0-9_]*   {c++; printf("identifier: %s\n", yytext);}
==|=|\+\+|\+|\*|-         {c++; printf("operator: %s\n", yytext);}
[(){}|,;]                {c++; printf("separator: %s\n", yytext);}
[0-9]*\.[0-9]+           {c++; printf("float: %s\n", yytext);}
[0-9]+                   {c++; printf("integer: %s\n", yytext);}
.                        ;
\n                       {return 0;}
%%
int yywrap(){ return 0;}
int main()
{
    yylex();
    printf("Total number of tokens = %d\n", c);
    return 0;
}
