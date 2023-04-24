%{
#include <stdio.h>
int count = 0;
%}

%%
[A-Z]+  { count++; }
.       ;
\n      { printf("Number of tokens with uppercase characters: %d\n", count); count = 0; }
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
