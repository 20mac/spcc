%{
    #include <stdio.h>
    int phone=0;
%}

%%
[0-9] {phone++;}
%%

int main(){
    printf("Enter the phone number: ");
    yylex();
    if (phone==10){
        printf("\nThe phone number is valid\n");
    }
    else{
        printf("\nThe phone number is invalid\n");
    }
    return 0;
}
int yywrap(){
    return 1;
}
