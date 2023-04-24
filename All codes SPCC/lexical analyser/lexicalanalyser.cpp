#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<string> keyword {"if","then"};
vector<string> action {"they"};
vector<string> verb {"hate","like"};
vector<string> noun;
int k=0,a=0,v=0,n=0,o=0,ex=0;
int location(vector<string> vect, string arg){
vector <string> :: iterator itr;
itr = find (vect.begin(), vect.end(), arg);
if (itr != vect.end ()){
int index = distance(vect.begin (), itr);
return index;
}
else{
return -1;
}
}
void result(string token){
if (location(keyword,token)!=-1){
cout<<"Keyword : "<<token<<endl;
k+=1; }
else if(location(action,token)!=-1){
cout<<"Action : "<<token<<endl;
a+=1; }
else if(location(verb,token)!=-1){
cout<<"Verb : "<<token<<endl;
v+=1; }
else{
if(location(noun,token)!=-1){
cout<<"Noun "<<location(noun,token)+1<<" : "<<token<<endl;
ex+=1; }
else{
cout<<"Noun "<<n+1<<" : "<<token<<endl;
noun.push_back(token);
n+=1; } } }
int main(){
string inp,token="";
cout<<"\nEnter the state for lexical analyzing: ";
getline(cin,inp);
cout<<"\n";
for ( int i=0; i<inp.length(); i++){
if (inp[i]!=' '){
if (inp[i]=='.'){
if (token!=""){
result(token);
token=""; }
cout<<"Operator(.)\n"<<endl;
o+=1; }
else{
token+=inp[i];
} }
else{
if (token!=""){
result(token);
token="";
}
}
}
cout<<"<eof>\n"<<endl;
cout<<"Symbol table -\n";
for(int i=0; i < noun.size(); i++){
cout<<i+1<<" "<<noun[i]<<endl;
}
cout<<"\nTotal number of keywords : "<<k<<endl;
cout<<"Total number of actions : "<<a<<endl;
cout<<"Total number of verbs : "<<v<<endl;
cout<<"Total number of nouns : "<<n+ex<<endl;
cout<<"Total number of operators : "<<o<<endl;
cout<<"------------------------------"<<endl;
cout<<"Total number of tokens : "<<k+a+v+n+o+ex<<"\n"<<endl;
return 0;
}

/*
input is "if dogs hate cats then they chase. if cats love milk then they drink. $"
*/