#include <iostream>
#include <string>
#include <stack>
#include <map>  
#include <vector>
using namespace std;

int main(){
    string equation,postfix;
    stack<char> stack;
    map <char,int> precedence={{'/',4},{'*',3},{'+',2},{'-',1},{'(',0}};
    cout<<"Enter the equation : ";
    cin>>equation;
    for (int i=0;i<equation.length();i++){
        if (isalpha(equation[i])){
            postfix=postfix+equation[i];
        }
        else{
            if (stack.empty() || equation[i]=='('){
                stack.push(equation[i]);
            }
            else if(equation[i]==')'){
                postfix=postfix+string(1, stack.top());
                stack.pop();
                stack.pop();
            }
            else{
                auto pc=precedence.find(equation[i]);
                auto tc=precedence.find(stack.top());
                while (!stack.empty() && pc-> second <= tc->second){
                    postfix=postfix+string(1, stack.top());
                    stack.pop();
                }
                stack.push(equation[i]);
            }
        }     
    }
    while (!stack.empty()){
        postfix=postfix+string(1, stack.top());
        stack.pop();
    }
    int count=0;
    vector<string> var;
    vector<string> tac;
    int i=0,n=postfix.length(); 
    while(postfix.length()>1){
        if (!isalnum(postfix[i])){
            var.push_back("t"+to_string(count));
            string opr1=string(1,postfix[i-2]);
            string opr2=string(1,postfix[i-1]);
            if (isdigit(postfix[i-2])){
                opr1=var.at(stoi(string(1,postfix[i-2])));
            }
            if (isdigit(postfix[i-1])){
                opr2=var.at(stoi(string(1,postfix[i-1])));
            }
            tac.push_back(var.at(count)+" = "+opr1+postfix[i]+opr2);
            postfix.replace(i-2,3,to_string(count));
            i=0;
            count+=1;
            n=postfix.length();
            continue;
        }
        i++;
    }
    for (auto elem : tac) {
        cout<<elem<<endl;
    }
    return 0;
}