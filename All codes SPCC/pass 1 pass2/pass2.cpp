#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int count=0,instr=0,st=0;
string symtb[50][2];
string passes[50][50][2];
int start;



void checker(string arg){
   string instructions[22][2]={{"STOP","00"},{"ADD","01"},{"SUB","02"},{"MULTI","03"},{"MOVER","04"},{"MOVEM","05"},{"COMP","06"},{"BC","07"},{"DIV","08"},{"READ","09"},{"PRINT","10"},
   {"START","01"},{"END","02"},{"ORIGIN","03"},{"EQU","04"},{"LTORG","05"},
   {"DS","01"},{"DC","02"},
   {"AREG","01"},{"BREG","02"},{"CREG","03"},{"DREG","04"}};
   string symbols[4]={"A","B","C","D"};
   int rows;
   bool found;

   rows=end(symbols)-begin(symbols);
   for(int x=0; x<rows; x++){
       if (symbols[x]==arg){
           passes[count][instr][0]="S";
           for (int y=0; y<50; y++){
               if (symtb[y][0]==""){
                   break;
               }
               if (symtb[y][0]==arg){
                   passes[count][instr][1]=to_string(y);
                   return;
               }
           }
           symtb[st][0]=arg;
           symtb[st][1]=to_string(start);
           start+=1;
           passes[count][instr][1]=to_string(st);
           st++;
           instr++;
           return;
       }
   }
  
   found=false;
   int x=0,cols=2;
   rows=sizeof(instructions)/sizeof(instructions[0]);
   for(x ; x < rows; x++){
       for(int y = 0; y < cols; y++){
           if(instructions[x][y]==arg){
               found = true;
               break;
           }
       }
       if (found==true){
           break;
       }
   }
   if (found){
       if (x>=0 && x<=10){
           passes[count][instr][0]="IS";
           passes[count][instr][1]=instructions[x][1];
           instr++;
           return;
       }
       if (x>=11 && x<=15){
           passes[count][instr][0]="AD";
           passes[count][instr][1]=instructions[x][1];
           instr++;
           return;
       }
       if (x>=16 && x<=17){
           passes[count][instr][0]="DL";
           passes[count][instr][1]=instructions[x][1];
           instr++;
           return;
       }
       if (x>=18 && x<=21){
           passes[count][instr][0]="RG";
           passes[count][instr][1]=instructions[x][1];
           instr++;
           return;
       }
   }
   else{
       if (! start){
           start=stoi(arg);
       }
       passes[count][instr][0]="C";
       passes[count][instr][1]=arg;
       instr++;
   }

}

int main(){  
   string opcd[22][2]={{"STOP","00"},{"ADD","01"},{"SUB","02"},{"MULTI","03"},{"MOVER","04"},{"MOVEM","05"},{"COMP","06"},{"BC","07"},{"DIV","08"},{"READ","09"},{"PRINT","10"},
   {"START","01"},{"END","02"},{"ORIGIN","03"},{"EQU","04"},{"LTORG","05"},
   {"DS","01"},{"DC","02"},
   {"AREG","01"},{"BREG","02"},{"CREG","03"},{"DREG","04"}};
   string line,res,word="";

   ifstream file("srcprg.txt");
   if (file.is_open()){
       while (file.peek() != EOF){
           getline(file, line, '\n');
           for (auto x : line){
               if (x == ' '){
                   checker(word);
                   word = "";
               }
               else {
                   if (x != ','){
                       word = word + x;
                   }
               }
           }
           checker(word);
           count+=1;
           instr=0;
           word="";
          
       }
   }
   else{
       cout << "Couldn't open the file\n";
   }
   cout<<"Pass 2: "<<endl;
   for(int i=0;i<50;i++){
       if (passes[i][0][0]==""){
           break;
       }
       if (passes[i][0][0]=="IS"){
           for(int j=0;j<50;j++){
               if (passes[i][j][0]==""){
                   break;
               }
               if (j==1 && passes[i][j][0]=="S"){
                   cout<<"00 "<<symtb[stoi(passes[i][j][1])][1]<<endl;
               }
               else{
                   if (passes[i][j][0]=="S"){
                       cout<<symtb[stoi(passes[i][j][1])][1]<<endl;
                   }
                   else{
                       cout<<passes[i][j][1]<<" ";
                   }
               }
           }
       }
   }
   cout<<"\nSymbol table : "<<endl;
   for(int i=0;i<50;i++){
       if(symtb[i][0]!=""){
           cout<<i<<" "<<symtb[i][0]<<" "<<symtb[i][1]<<endl;
       }
   }
   return 0;
}

