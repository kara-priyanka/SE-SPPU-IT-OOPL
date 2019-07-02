// Name: KARA PRIYANKA  Roll no.: 03   Batch: A1
// Assignment 3:Operator Overloading.
#include<iostream>
using namespace std;
class complex
{
   float x; 
   float y; 
   public:
     complex() 
     {
       x=0;
       y=0;
     }
     complex(float real,float imaginary)
     {
        x=real;
        y=imaginary;
     }
     void display(class complex); 
     friend complex operator+(class complex,class complex);
     friend complex operator-(class complex,class complex);
     complex operator*(class complex);
     complex operator/(class complex);
};
// friend function used for + operator overloading.
complex operator+(class complex c1,class complex c2)
{
  complex c;
  c.x=c1.x+c2.x;
  c.y=c1.y+c2.y;
  return c;
}
// friend function used for - operator overloading.
complex operator-(class complex c1,class complex c2)
{
  complex c;
  c.x=c1.x-c2.x;
  c.y=c1.y-c2.y;
  return c;
}
// member function used for * operator overloading.
complex complex::operator*(class complex c2)// only c2 is passed as implicitly the c1 was passed by the compiler.
{
  complex mul;
  mul.x=x*c2.x;
  mul.y=y*c2.y;
  return mul;
}
// member function used for / operator overloading.
complex complex::operator/(class complex c2)// only c2 is passed as implicitly the c1 was passed by the compiler.
{
  complex div;
  div.x=x/c2.x;
  div.y=y/c2.y;
  return div;
}
// Displays the Complex number.
void complex::display(class complex c)
{
  cout<<"("<<c.x<<")"<<"+"<<"("<<c.y<<")"<<"i"<<endl;
  
}
// Beginning of the main function.
int main()
{
   complex call;// for calling for display.
   complex c1,c2,c;
   int n;
   float x,y,a,b; 
  do
  { 
   cout<<"\n1.Accept\n2.Display\n3.Addition\n4.Subtraction\n5.Multiplication\n6.Division\n7.EXIT\n";
   cin>>n;
   switch(n)
   {
     case 1:
       cout<<"Enter the real part of the 1st complex number:\n";
       cin>>x;
       cout<<"Enter the imaginary part of the 1st complex number:\n";
       cin>>y;
       c1=complex(x,y);
       cout<<"Enter the real part of the 2nd complex number:\n";
       cin>>a;
       cout<<"Enter the imaginary part of the 2nd complex number:\n";
       cin>>b;
       c2=complex(a,b);
       break;
    case 2:
       cout<<"1st complex number:\n";
       call.display(c1);
       cout<<"2nd complex number:\n";
       call.display(c2);
       break;
    case 3:
       c=c1+c2;
       cout<<"Addition of the two complex numbers:\n";
       call.display(c);
       break;
    case 4:
       c=c1-c2;
       cout<<"Subtraction :1st complex no.-2nd complex no.:\n";
       call.display(c);
       c=c2-c1;
       cout<<"Subtraction: 2nd complex no.-1st complex no:\n";
       call.display(c);
       break;
    case 5:
       c=c1*c2;
       cout<<"Multiplication of two complex number:\n";
       call.display(c);
       break;
    case 6:
       c=c1/c2;
       cout<<"Division of two complex number:\n";
       call.display(c);
       break;
    }// End of switch case.
  }while(n!=7);// End of do...while loop.
  return 0;
}// End of main function.

/*
OUTPUT:

[fedora20@localhost Documents]$ g++ p.cpp
[fedora20@localhost Documents]$ ./a.out

1.Accept
2.Display
3.Addition
4.Subtraction
5.Multiplication
6.Division
7.EXIT
1
Enter the real part of the 1st complex number:
2
Enter the imaginary part of the 1st complex number:
3.4
Enter the real part of the 2nd complex number:
6.45
Enter the imaginary part of the 2nd complex number:
4

1.Accept
2.Display
3.Addition
4.Subtraction
5.Multiplication
6.Division
7.EXIT
2
1st complex number:
(2)+(3.4)i
2nd complex number:
(6.45)+(4)i

1.Accept
2.Display
3.Addition
4.Subtraction
5.Multiplication
6.Division
7.EXIT
3
Addition of the two complex numbers:
(8.45)+(7.4)i

1.Accept
2.Display
3.Addition
4.Subtraction
5.Multiplication
6.Division
7.EXIT
4
Subtraction :1st complex no.-2nd complex no.:
(-4.45)+(-0.6)i
Subtraction: 2nd complex no.-1st complex no:
(4.45)+(0.6)i

1.Accept
2.Display
3.Addition
4.Subtraction
5.Multiplication
6.Division
7.EXIT
5
Multiplication of two complex number:
(12.9)+(13.6)i

1.Accept
2.Display
3.Addition
4.Subtraction
5.Multiplication
6.Division
7.EXIT
6
Division of two complex number:
(0.310078)+(0.85)i

1.Accept
2.Display
3.Addition
4.Subtraction
5.Multiplication
6.Division
7.EXIT
7
[fedora20@localhost Documents]$ 

*/

