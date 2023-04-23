%{
    #include <stdio.h>
    int vow=0;
    int cons=0;
%}

%%
[aeiouAEIOU] {printf("\nVowel     -> %s",yytext);vow++;}
[^aeiouAEIOU' '] {printf("\nConsonant -> %s",yytext);cons++;}
%%

int main(){
    printf("Enter the string: ");
    yylex();
    printf("\n\nThe number of vowels is %d",vow);
    printf("\nYhe number of consonants is %d\n",cons);
    return 0;
}

int yywrap(){
    return 1;
}