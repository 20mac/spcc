%{
#include <stdio.h>
%}

DIGIT [0-9]
%%
{DIGIT}+ {
  int num = atoi(yytext);
  if(num % 2 == 0) {
    printf("%d is even\n", num);
  }
  else {
    printf("%d is odd\n", num);
  }
}
.|\n {}

%%
int yywrap() {
  return 0;
}

int main() {
  yylex();
  return 0;
}
