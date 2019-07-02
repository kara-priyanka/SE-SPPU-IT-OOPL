// Name: KARA PRIYANKA    Roll no.: 03     Batch: A1
// Assingment 5: Virtual Function.
#include<iostream>
using namespace std;
// Base Class
class shape
{
  double x;
  double y;
  public:
   shape();
   void input(double ,double );
   virtual double compute_area(double,double);
};
// Derived Class
class rectangle:public shape
{
  public:
    double compute_area(double,double);
};
// Derived CLass
class triangle:public shape
{
  public:
   double compute_area(double,double);
};
// Constructor of base class, helps in initializing the variables
shape::shape()
{
  x=0;
  y=0;
}
// Compute_area function of base class: Which is made virtual 
double shape::compute_area(double l,double b)
{
   cout<<"Area not calculated!!!"<<endl;
   return 0;
}
// Input function: Takes the input by the user.
void shape::input(double l,double b)
{
  x=l;
  y=b;
}
// Computes area of a rectangle.
double rectangle::compute_area(double l,double b)
{
  return l*b;
}
// Computes area of a traingle.
double triangle::compute_area(double ht,double base)
{
   return 0.5*ht*base;
}
/*Beginning of the main function*/
int main()
{
   int n;
   double l,b,ht,base;
   shape *s[3],sh;
   rectangle r;
   triangle t;
   s[0]=&r; // Initializes the base class pointer to the address of rectangle(derived class) object.
   s[1]=&t;// Initializes the base class pointer to the address of triangle(derived class) object.
   s[2]=&sh;// Initializes the base class pointer to the address of base class object.
   do
   {
      cout<<"*******Menu******\n1.Shape\n2.Rectangle\n3.Triangle\n4.Exit\n";// Menu 
      cin>>n;
      switch(n)
      {
        case 1:
          {
           double l,b;
           cout<<"Enter the Dimensions of the shape:\n";
           cin>>l>>b;// Takes input from user. 
           s[2]->input(l,b);// Assigns the input to the variables of the class.
           double v=s[2]->compute_area(l,b);// computes the area for the virtual function.
           break;
          }
        case 2:
          {
            cout<<"Enter the length and breadth of the rectangle respectively:\n";
            cin>>l>>b;
            s[0]->input(l,b);// Assigns the input to the variables of the class.
            double arear=s[0]->compute_area(l,b);// computes the area for the rectangle.
            cout<<"The area of the Rectangle having dimensions "<<l<<"x"<<b<<" is "<<arear<<endl;
            break;
         }
        case 3:
         {
           cout<<"Enter the length of base and height of the traingle respectively:\n";
           cin>>ht>>base;
           s[0]->input(ht,base);// Assigns the input to the variables of the class.
           double areat=s[1]->compute_area(ht,base);// computes the area for the triangle.
           cout<<"The area of the Traingle having height="<<ht<<" and base="<<base<<" is area="<<areat<<endl;
           break;
         } // end of case 3.
      }//end of switch.
    }while(n!=4);// end of do...while
}// end of main().
/*
 OUTPUT:
*******Menu******
1.Shape
2.Rectangle
3.Triangle
4.Exit
1
Enter the Dimensions of the shape:
2
3
Area not calculated!!!
*******Menu******
1.Shape
2.Rectangle
3.Triangle
4.Exit
2
Enter the length and breadth of the rectangle respectively:
2
3
The area of the Rectangle having dimensions 2x3 is 6
*******Menu******
1.Shape
2.Rectangle
3.Triangle
4.Exit
3
Enter the length of base and height of the traingle respectively:
2
3
The area of the Traingle having height=2 and base=3 is area=3
*******Menu******
1.Shape
2.Rectangle
3.Triangle
4.Exit
4

Process returned 0 (0x0)   execution time : 17.610 s
Press any key to continue.

*/
