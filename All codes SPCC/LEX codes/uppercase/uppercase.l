%{
#include<stdio.h>
int Upper=0;
int Lower=0;
%}
%%
[A-Z] {printf("Uppercase\t\n");Upper++;}
[a-z] {printf("Lowercase\t\n");Lower++;}
\n    {printf("Uppercase=%d and Lowercase=%d",
Upper,Lower);}
%%
int main()
{
printf("Enter a string\n");
yylex();
}
int yywrap()
{ return 1; }
