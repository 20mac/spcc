%{
/* Definition section */
#include<stdio.h>
#include<stdlib.h>
int i,m,k=0;
%}

%token A B C NL

/* Rule Section */
%%
stmt: expr NL { if ((i==k) && (k==m))printf("valid string\n");else printf("invalid string\n");
			exit(0); }
;
expr:s j l
s: s A {i++;} |
j: j B {k++}  |
l: l C {m++}  |
;
%%

int yyerror(char *msg)
{
/* printf("invalid string\n"); */
exit(0);
}

//driver code
main()
{
printf("enter the string\n");
yyparse();
}
