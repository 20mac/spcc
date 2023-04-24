%{
#include <stdio.h>

int line_count = 0;
int num_count = 0;
int space_count = 0;
%}

%%

\n              { line_count++; }
[0-9]+          { num_count++; }
[ \t]           { space_count++; }
.               { /* ignore all other characters */ }

%%

int main()
{
    printf("Enter input:\n");
    yylex();
    printf("Line count: %d\n", line_count);
    printf("Number count: %d\n", num_count);
    printf("Blank space count: %d\n", space_count);
    return 0;
}

int yywrap()
{
    return 1;
}
