#include<iostream>
#include<conio.h>
#include"area.h"

using namespace std;
int main()
{ int b,h,s,r,l,x;
float area;
cout<<"1.Area of square\n2.Area of rectangle\n3.Area of triangle\n4.Area of Circle\n";
cout<<"Enter the operation to be performed: ";
cin>>x;
switch(x)
{ case 1:
cout<<"enter the side of square ";
cin>>s;
area=area_square(s);
cout<<"Area of square is: "<<area;
break;
case 2:
cout<<"enter the length and breadth of rectangle ";
cin>>l>>b;
area=area_rectanglr(l,b);
cout<<"Area of rectangle is: "<<area;
break;
case 3:
cout<<"enter the base and height of triangle ";
cin>>b>>h;
area=area_traingle(b,h);
cout<<"Area of triangle is: "<<area;
break;
case 4:
cout<<"enter the radius of circle ";
cin>>r;
area=area_circle(r);
cout<<"Area of circle is: "<<area;
break;
} return 0;
}