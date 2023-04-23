%{
#include<stdio.h>
int u=0;
int l=0;
%}
%%
[A-Z] {printf("Uppercase: ");ECHO;u++;printf("\t\n");}
[a-z] {printf("Lowercase: ");ECHO;l++;printf("\t\n");}
. ;
%%
int main()
{
printf("Enter a string\n");
yylex();
printf("Uppercase=%d and Lowercase=%d",u,l);
}
int yywrap()
{
return 1;
}
