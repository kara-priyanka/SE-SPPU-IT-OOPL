// Name: Kara Priyanka   Batch: A1  Roll no.: 03
// Assignment 6: Exception Handling

#include<iostream>
using namespace std;

/*reads Input from the user */
void fn_read(double *a,double *b)
{
  double x,y;
  cout<<"Enter the Two numbers to be divided:\n";
  cin>>x;
  cin>>y;
  *a=x;
  *b=y;
}

/*Divides the two values*/
double fn_divide(double a,double b)
{
  if(b!=0)
  {
    double c=a/b;
    return c;
  }
  else 
   throw(b);// We did this because the denominator cannot be 0 . therefore it is a case of exception.
}

/*Beginning of main function*/
int main()
{
  /*Declaring variables*/
  double a,b,c;
  int n;
 
  do
  {
    cout<<"\n******MENU******\n1.Input\n2.Display\n3.Divide\n4.EXIT\n";
    cin>>n;
    switch(n)
    {
      case 1:
      {
          /*Reads the input from keyboard*/
          fn_read(&a,&b);// Pass by reference.
          break;
      }
      case 2:
      {
          cout<<"The entered values are:\n"<<a<<endl<<b<<endl;
          break;
      }
      case 3:
      {
          //Handling the Exception Cases
          try
          {
            c=fn_divide(a,b);
            cout<<"Division of "<<a<<"and "<<b<<" is "<<c<<endl;
          }
          // Catches the thrown value by the function to handle the exception.
          catch(double b)
          {
            cout<<"Exception Caught\n";
            cout<<"Denominator cannot be zero\n";
          }
          break;
       }
     }//end of switch case.
  }while(n!=4);// end of do while
  return 0;
}// end of main()


/*
OUTPUT:

[student@localhost Documents]$ g++ a6.cpp
[student@localhost Documents]$ ./a.out

******MENU******
1.Input
2.Display
3.Divide
4.EXIT
1
Enter the Two numbers to be divided:
2
3

******MENU******
1.Input
2.Display
3.Divide
4.EXIT
2
The entered values are:
2
3

******MENU******
1.Input
2.Display
3.Divide
4.EXIT
3
Division of 2and 3 is 0.666667

******MENU******
1.Input
2.Display
3.Divide
4.EXIT
1
Enter the Two numbers to be divided:
2
0

******MENU******
1.Input
2.Display
3.Divide
4.EXIT
2
The entered values are:
2
0

******MENU******
1.Input
2.Display
3.Divide
4.EXIT
3
Exception Caught
Denominator cannot be zero

******MENU******
1.Input
2.Display
3.Divide
4.EXIT
1
Enter the Two numbers to be divided:
0
2

******MENU******
1.Input
2.Display
3.Divide
4.EXIT
2
The entered values are:
0
2

******MENU******
1.Input
2.Display
3.Divide
4.EXIT
3
Division of 0and 2 is 0

******MENU******
1.Input
2.Display
3.Divide
4.EXIT
4
[student@localhost Documents]$ 



*/


