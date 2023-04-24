#include<iostream>
#include<conio.h>
#include"convert.h"

using namespace std;
int main()
{ float c,f,cf,l,m,result;
int x;
cout<<"1.Convert Fahrenheit to Celsius \n2.Convert Celsius to Fahrenheit\n3.Convert Feet to M\n4.Convert M to Feet\n5.Convert Litre to cubic feet\n6.Convert cubic feet to litre\n";
cout<<"Enter the operation to be performed:"<<endl;
cin>>x;
switch(x)
{ case 1:
cout<<"Enter the value for F: ";
cin>>f;
result=cel(f);
cout<<"Result is: "<<result;
break;
case 2:
cout<<"Enter the value for C: ";
cin>>c;
result=fah(c);
cout<<"Result is: "<<result;
break;
case 3:
cout<<"Enter the value for F: ";
cin>>f;
result=metre(f);
cout<<"Result is: "<<result;
break;
case 4:
cout<<"Enter the value for M: ";
cin>>m;
result=feet(m);
cout<<"Result is: "<<result;
break;
case 5:
cout<<"Enter the value for Litre: ";
cin>>l;
result=cubft(l);
cout<<"Result is: "<<result;
break;
case 6:
cout<<"Enter the value for Cubic feet: ";
cin>>cf;
result=litre(cf);
cout<<"Result is: "<<result;
break;
} return 0;
}