%{
#include<stdio.h>
int vowel=0;
int con=0;
%}

%%

[aeiouAEIOU] {
    printf("Vowel: %s\n", yytext);
    vowel++;
}

[^aeiouAEIOU \t\n] {
    printf("Consonant: %s\n", yytext);
    con++;
}

\n {
    printf("Vowel count: %d and Consonant count: %d\n", vowel, con);
    vowel = con = 0;
}
%%

int main()
{ 
    printf("Enter a string\n"); 
    yylex(); 
}

int yywrap()
{ 
    return 1; 
}