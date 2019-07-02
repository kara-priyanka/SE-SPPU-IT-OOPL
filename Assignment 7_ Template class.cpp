// Name: KARA PRIYANKA      Batch: A1     Roll no.: 03
// Assignment 7: template class
/*Write a program in C++ using function/class template to read two matrice of different data
types such as integers and floating point values and perform simple arithmetic operations on
these matrice separately and display it.*/

#include<iostream>
using namespace std;

template<class T>
class matrice
{
    private:
        T a[10][10];
        int i,j,r1,r2,c1,c2;
    public:
        void fn_accept(int r,int c);
        void fn_display(int r,int c);
        matrice<T> fn_add (matrice<T> m1, matrice<T> m2, matrice<T> m3, int r1, int c1);
        matrice<T> fn_subtract (matrice<T> m1, matrice<T> m2, matrice<T> m4, int r1, int c1);
        matrice<T> fn_multiply (matrice<T> m1, matrice<T> m2, matrice<T> m5, int r1, int c1, int r2, int c2);
};


template<class T>
void matrice<T>::fn_accept(int r,int c)
{
    int i,j;
    cout<<"\nEnter the elements:\n";
    for(i=0;i<c;i++)
    {
        cout<<"Enter Row Elements:\n ";
        for(j=0;j<r;j++)
        {
            cin>>a[i][j];
        }
    }
}


template<class T>
void matrice<T>::fn_display(int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        cout<<"[";
        for(j=0;j<c;j++)
        {
            cout<<a[i][j];
            if(j<(c-1))
            {
               cout<<"\t";
            }
        }
        cout<<"]";
        cout<<"\n";
    }
}


template<class T>
matrice<T> matrice<T>::fn_add(matrice<T>m1,matrice<T>m2,matrice<T>m3,int r,int c)
{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				m3.a[i][j]=m1.a[i][j]+m2.a[i][j];
			}//for()
		}//for
		return m3;
}//fn_add()


template<class T>
//template function to subtract two matrix
matrice<T> matrice<T>::fn_subtract(matrice<T>m1, matrice<T>m2, matrice<T>m4, int r, int c)
{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				m4.a[i][j]=m1.a[i][j]-m2.a[i][j];
			}//for
		}//for
	return m4;
}//fn_subtract()


template<class T>
matrice<T> matrice<T>::fn_multiply(matrice<T> m1,matrice<T> m2,matrice<T> m5,int r1,int r2,int c1,int c2)
{
    int k;
    for(i=0;i<r1;i++)
        {
         	for(j=0;j<c2;j++)
         	{
         		 m5.a[i][j]=0;
          		 for(k=0;k<c1;k++)
         		 {
           			m5.a[i][j]=m1.a[i][k]*m2.a[k][j]+m5.a[i][j];
          		 }//for
        	 }//for
        }//for
        return m5;
}//fn_multiplication()
//main function



int main()
{
    int r1,r2,c1,c2,ch1,ch2;
    matrice<int>m1,m2,m3,m4,m5,m6;
    matrice<float>f1,f2,f3,f4,f5,f6;
    do
    {
        cout<<"*****MENU***** \n1.MATRICE WITH INTEGERS\n2.MATRICES WITH DECIMAL \n3.Exit"<<endl;
        cin>>ch1;
    switch(ch1)
    {
        case 1:
        {
          do
          {
            cout<<"\n*****SUB-MENU***** \n1.ACCEPT\n2.DISPLAY\n3.ADD\n4.SUBTRACT\n5.MULTIPLY\n6.EXIT\n";
            cin>>ch2;
            switch(ch2)
            {
                case 1:
                    cout<<"Enter the number of rows and columns in your 1st matrix \n";
                    cin>>r1>>c1;
                    m1.fn_accept(r1,c1);
                    cout<<"Enter the number of rows and columns in your 2nd matrix \n";
                    cin>>r2>>c2;
                    m2.fn_accept(r2,c2);
                    break;
                case 2:
                    cout<<"\nMATRICE 1:\n";
                    m1.fn_display(r1,c1);
                    cout<<"\n";
                    cout<<"MATRICE 2:\n";
                    m2.fn_display(r2,c2);
                    cout<<"\n";
                    break;
                case 3:
                    if(r1==r2&&c1==c2)
                    {
                        m3=m3.fn_add(m1,m2,m3,r1,c1);
                        cout<<" ADDED MATRICE :\n";
                        m3.fn_display(r1,c1);
                        cout<<"\n";
                    }
                    else
                        cout<<"The two matrices cannot be added\n";
                    break;
                case 4:
                    if(r1==r2&&c1==c2)
                    {
                        m4=m4.fn_subtract(m1,m2,m4,r1,c1);
                        cout<<" Matrix 1-Matrix 2=\n";
                        m4.fn_display(r1,c1);
                        cout<<"\n";
                        m6=m6.fn_subtract(m2,m1,m6,r1,c1);
                        cout<<" Matrix 2-Matrix 1=\n";
                        m6.fn_display(r1,c1);
                        cout<<"\n";
                    }
                    else
                        cout<<"The two matrice cannot be subtracted\n";
                    break;
                case 5:
                    if(r2==c1)
                    {
                        m5=m5.fn_multiply(m1,m2,m5,r1,r2,c1,c2);
                        cout<<"Matrix 1 x Matrix 2=\n";
                        m5.fn_display(r1,c2);
                        cout<<"\n";
                    }
                    else
                        cout<<"The two entered matrice cannot be multiplied\n";
                    break;
            }
            }while(ch2!=6);
        }

            case 2:
            {
              do
              {
                cout<<"\n*****SUB-MENU***** \n1.ACCEPT\n2.DISPLAY\n3.ADD\n4.SUBTRACT\n5.MULTIPLY\n6.EXIT\n";
                cin>>ch2;
                switch(ch2)
                {
                    case 1:
                        cout<<"Enter the number of rows and columns in your matrix 1 \n";
                        cin>>r1>>c1;
                        f1.fn_accept(r1,c1);
                        cout<<"Enter the number of rows and columns in your matrix 2 \n";
                        cin>>r2>>c2;
                        f2.fn_accept(r1,c1);
                        break;
                    case 2:
                        cout<<"MATRICE 1:\n";
                        f1.fn_display(r1,c1);
                        cout<<"\n";
                        cout<<"MATRICE 2:\n";
                        f2.fn_display(r2,c2);
                        cout<<"\n";
                        break;
                    case 3:
                        if(r1==r2&&c1==c2)
                        {
                            f3=f3.fn_add(f1,f2,f3,r1,c1);
                            cout<<"ADDED MATRICE :\n";
                            f3.fn_display(r1,c1);
                            cout<<"\n";
                        }
                        else
                            cout<<"The two matrice cannot be added\n";
                        break;
                    case 4:
                        if(r1==r2&&c1==c2)
                        {
                            f4=f4.fn_subtract(f1,f2,f4,r1,c1);
                            cout<<"Matrix 1-Matrix 2=\n";
                            f4.fn_display(r1,c1);
                            cout<<"\n";
                            f6=f6.fn_subtract(f2,f1,f6,r1,c1);
                            cout<<"Matrix 2-Matrix 1=\n";
                            f6.fn_display(r1,c1);
                            cout<<"\n";
                        }
                        else
                            cout<<"The two matrice cannot be subtracted\n";
                        break;
                    case 5:
                        if(r2==c1)
                        {
                            f5=f5.fn_multiply(f1,f2,f5,r1,r2,c1,c2);
                            cout<<"Matrix 1 x Matrix 2=\n";
                            f5.fn_display(r1,c2);
                            cout<<"\n";
                        }
                        else
                            cout<<"The two entered matrice cannot be multiplied\n";
                        break;
              }
            }while(ch2!=6);
          }// end larger Case 2
        }// end of larger switch
    }while(ch1!=3);// end of menu do ....while
     return 0;
}


/*
OUTPUT:

*****MENU*****
1.MATRICE WITH INTEGERS
2.MATRICES WITH DECIMAL
3.Exit
1

*****SUB-MENU*****
1.ACCEPT
2.DISPLAY
3.ADD
4.SUBTRACT
5.MULTIPLY
6.EXIT
1
Enter the number of rows and columns in your 1st matrix
2
2

Enter the elements:
Enter Row Elements:
 1
2
Enter Row Elements:
 3
4
Enter the number of rows and columns in your 2nd matrix
2
2

Enter the elements:
Enter Row Elements:
 3
2
Enter Row Elements:
 0
1

*****SUB-MENU*****
1.ACCEPT
2.DISPLAY
3.ADD
4.SUBTRACT
5.MULTIPLY
6.EXIT
2

MATRICE 1:
[1      2]
[3      4]

MATRICE 2:
[3      2]
[0      1]


*****SUB-MENU*****
1.ACCEPT
2.DISPLAY
3.ADD
4.SUBTRACT
5.MULTIPLY
6.EXIT
3
 ADDED MATRICE :
[4      4]
[3      5]


*****SUB-MENU*****
1.ACCEPT
2.DISPLAY
3.ADD
4.SUBTRACT
5.MULTIPLY
6.EXIT
4
 Matrix 1-Matrix 2=
[-2     0]
[3      3]

 Matrix 2-Matrix 1=
[2      0]
[-3     -3]


*****SUB-MENU*****
1.ACCEPT
2.DISPLAY
3.ADD
4.SUBTRACT
5.MULTIPLY
6.EXIT
5
Matrix 1 x Matrix 2=
[3      4]
[9      10]


*****SUB-MENU*****
1.ACCEPT
2.DISPLAY
3.ADD
4.SUBTRACT
5.MULTIPLY
6.EXIT
6

*****SUB-MENU*****
1.ACCEPT
2.DISPLAY
3.ADD
4.SUBTRACT
5.MULTIPLY
6.EXIT
6
*****MENU*****
1.MATRICE WITH INTEGERS
2.MATRICES WITH DECIMAL
3.Exit
2

*****SUB-MENU*****
1.ACCEPT
2.DISPLAY
3.ADD
4.SUBTRACT
5.MULTIPLY
6.EXIT
1
Enter the number of rows and columns in your matrix 1
2
2

Enter the elements:
Enter Row Elements:
 2.2
3.2
Enter Row Elements:
 1
0
Enter the number of rows and columns in your matrix 2
2
2

Enter the elements:
Enter Row Elements:
 3
4.2
Enter Row Elements:
 1
2

*****SUB-MENU*****
1.ACCEPT
2.DISPLAY
3.ADD
4.SUBTRACT
5.MULTIPLY
6.EXIT
2
MATRICE 1:
[2.2    3.2]
[1      0]

MATRICE 2:
[3      4.2]
[1      2]


*****SUB-MENU*****
1.ACCEPT
2.DISPLAY
3.ADD
4.SUBTRACT
5.MULTIPLY
6.EXIT
3
ADDED MATRICE :
[5.2    7.4]
[2      2]


*****SUB-MENU*****
1.ACCEPT
2.DISPLAY
3.ADD
4.SUBTRACT
5.MULTIPLY
6.EXIT
4
Matrix 1-Matrix 2=
[-0.8   -1]
[0      -2]

Matrix 2-Matrix 1=
[0.8    1]
[0      2]


*****SUB-MENU*****
1.ACCEPT
2.DISPLAY
3.ADD
4.SUBTRACT
5.MULTIPLY
6.EXIT
5
Matrix 1 x Matrix 2=
[9.8    15.64]
[3      4.2]


*****SUB-MENU*****
1.ACCEPT
2.DISPLAY
3.ADD
4.SUBTRACT
5.MULTIPLY
6.EXIT
6
*****MENU*****
1.MATRICE WITH INTEGERS
2.MATRICES WITH DECIMAL
3.Exit
3

Process returned 0 (0x0)   execution time : 75.052 s
Press any key to continue.


*/
