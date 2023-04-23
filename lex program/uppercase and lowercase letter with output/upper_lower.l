%{
    #include <stdio.h>
    int upr=0;
    int lwr=0;
%}

%%
[A-Z] {printf("\nUppercase -> %s",yytext);upr++;}
[a-z] {printf("\nLowercase -> %s",yytext);lwr++;}
%%

int main(){
    printf("Enter the string: ");
    yylex();
    printf("\n\nThe number of uppercase characters are : %d",upr);
    printf("\nThe number of lowercase characters are : %d\n",lwr);
    return 0;
}

int yywrap(){
    return 1;
}