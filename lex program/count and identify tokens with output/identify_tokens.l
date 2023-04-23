%{
    #include <stdio.h>
    int keywords=0;
    int symbols=0;
    int numbers=0;
    int identifiers=0;
    int tokens=0;
%}

%%
"if"|"else"|"while"|"dowhile"|"for"|"break"|"int"|"float"|"long"|"char"|"double"|"printf" {printf("\nKeyword    -> %s",yytext);keywords++;tokens++;}
"("|")"|"{"|"}"|"<"|">"|";"|":"|"&"|"@"|"$"|"#"|"+"|"-"|"*"|"%"|"!"|"=="|"=" {printf("\nSymbol     -> %s",yytext);symbols++;tokens++;}
[A-Za-z]+ {printf("\nIdentifier -> %s",yytext);identifiers++;tokens++;}
[0-9]+ {printf("\nNumber     -> %s",yytext);numbers++;tokens++;}
%%

int main(){
    printf("Enter the code:\n");
    yylex();
    printf("\n\nKeywords     : %d\nSymbols      : %d\nIdentifiers  : %d",keywords,symbols,identifiers);
    printf("\nNumbers      : %d\nTotal tokens : %d\n",numbers,tokens);
    return 0;
}

int yywrap(){
    return 1;
}