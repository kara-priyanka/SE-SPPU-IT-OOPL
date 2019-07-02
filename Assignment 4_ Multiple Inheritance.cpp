// Name: KARA PRIYANKA       Roll no.:03        Batch: A1
// Assignment 4:Multiple Inheritance.   
#include<iostream>
using namespace std;
class derived;

class basic
{
  public:
   char *name;
   char *dob;
   char *bloodgrp;
   basic()
   {
     name=new char;
     dob=new char;
     bloodgrp=new char;
    }
};

class phy
{
  public:
   float height;
   float weight;
   phy()
    {
     height=0;
     weight=0;
    }
};

class ins
{
  public:
   long int polno;
   char *address;
   ins()
    {
     polno=0;
     address=new char;
    }

};

class derived:public basic,public phy,public ins
{
  public:
    long long int teleno;
    long long int licno;
    derived()
    {
     teleno=0;
     licno=0;
    }
    void accept();
    void display();
    int delete1(long int,class derived [],int );
    void edit(long int,class derived [],int);
    void search1(long int,class derived [],int);
};

int main()
{
   int n,no;
   cout<<"Enter number of data to be entered:\n";
   cin>>no;
   class derived d[30],b;
   do
   {
      cout<<"******MENU********\n1.Accept\n2.Display\n3.Insert\n4.Delete\n5.Edit\n6.Search\n7.EXIT\n";
      cin>>n;
      switch(n)
      {
         case 1:
            {
            for(int i=0;i<no;i++)
            {
               d[i].accept();
            }
            break;
            }
         case 2:
           {
            cout<<"name\tdob\t\tblg\theight\tweight\tpolicyno\taddress\t\tteleno\t\tlicno\n";
            for(int i=0;i<no;i++)
             {
               d[i].display();
             }
            break;
           }
         case 3:
           {
             cout<<"Enter number of datas to be inserted:\n";
             int y;
             cin>>y;
             for(int i=no;i<(no+y);i++)
             {
                d[i].accept();
             }
             no=no+y;
             cout<<"Total number of data present now is "<<no<<endl;
             break;
           }
         case 4:
           {
             long int policy;
             cout<<"Enter the Policy number of the person to be Deleted:\n ";
             cin>>policy;
             no=b.delete1(policy,d,no);
             cout<<"DATA DELETED!!!!!! "<<endl;
             break;
           }
         case 5:
           {
             long int policy;
             cout<<"Enter the Policy number of the person to be Edited:\n ";
             cin>>policy;
             b.edit(policy,d,no);
             break;
           }
         case 6:
           {
             long int policy;
             cout<<"Enter the Policy number of the person to be Edited:\n ";
             cin>>policy;
             b.search1(policy,d,no);
             break;
           }
       }//end of switch.
   }while(n!=7);//end of do...while
}//end of main().

// Accept function.
void derived:: accept()
{
  cout<<"\nEnter name:\n";
  cin>>name;
  cout<<"Enter the dob it the format of DD/MM/YYYY:\n";
  cin>>dob;
  cout<<"Enter blood group:\n";
  cin>>bloodgrp;
  cout<<"Enter height:\n";
  cin>>height;
  cout<<"Enter weight:\n";
  cin>>weight;
  cout<<"Enter Insurance policy number:\n";
  cin>>polno;
  cout<<"Enter address:\n";
  cin>>address;
  cout<<"Enter teleno:\n";
  cin>>teleno;
  cout<<"Enter license number:\n";
  cin>>licno;
}

//Display function.
void derived:: display()
{
  cout<<name<<"\t"<<dob<<"\t"<<bloodgrp<<"\t"<<height<<"\t"<<weight<<"\t"<<polno<<"\t"<<address<<"\t"<<teleno<<"\t"<<licno<<endl;
}

int derived::delete1(long int policy,class derived d[],int no)
{
  for(int i=0;i<no;i++)
  {
    if(d[i].polno==policy)
    {
      while(i!=(no-1))
      {
          d[i]=d[i+1];
          i++;
      }
      return no-1;
    }
  }
}

// Edits the data.
void derived::edit(long int policy,class derived d[],int no)
{
  int q,i;
  for(i=0;i<no;i++)
  {
    if(d[i].polno==policy)
    {
      do
      {
        cout<<"\n1.Edit Name\n2.Edit DOB\n3.Edit blood grp\n4.Edit Height\n5.Edit Weight\n6.Edit Address\n7.Edit Telephone Number\n8.Edit License number\n9.EXIT\n";
        cin>>q;
        switch(q)
        {
          case 1:
          {
             cout<<"Enter name:\n";
             cin>>d[i].name;
             break;
          }
          case 2:
          {
             cout<<"Enter DOB\n";
             cin>>d[i].dob;
             break;
          }
          case 3:
          {
             cout<<"Enter blood group\n";
             cin>>d[i].bloodgrp;
             break;
          }
          case 4:
          {
             cout<<"Enter Height\n";
             cin>>d[i].height;
             break;
          }
          case 5:
          {
             cout<<"Enter Weight\n";
             cin>>d[i].weight;
             break;
          }
          case 6:
          {
             cout<<"Enter Address\n";
             cin>>d[i].address;
             break;
          }
          case 7:
          {
             cout<<"Enter Telephone no.\n";
             cin>>d[i].teleno;
             break;
          }
          case 8:
          {
             cout<<"Enter License no.\n";
             cin>>d[i].licno;
             break;
          }
        }//end of switch.
      }while(q!=9);
      break;
    }
  }
  if(i==no)
  {
    cout<<"error!!!entered Policy is not present\n";
  }
  return;
}

// Searches the data.
void derived::search1(long int policy,class derived d[],int no)
{
  int i;
  for(i=0;i<no;i++)
  {
    if(d[i].polno==policy)
    {
      cout<<"name\tdob\tblg\theight\tweight\tpolicyno\taddress\tteleno\tlicno\n";
      cout<<d[i].name<<"\t"<<d[i].dob<<"\t"<<d[i].bloodgrp<<"\t"<<d[i].height<<"\t"<<d[i].weight<<"\t"<<d[i].polno<<"\t"<<d[i].address<<"\t"<<d[i].teleno<<"\t"<<d[i].licno<<endl;
      return;
    }
  }
  if(i==no)
  {
    cout<<"error!!!entered Policy is not present\n";
  }
}


/*
OUTPUT:
[student@localhost Documents]$ g++ oopl4.cpp
[student@localhost Documents]$ ./a.out
Enter number of data to be entered:
2
******MENU********
1.Accept
2.Display
3.Insert
4.Delete
5.Edit
6.Search
7.EXIT
1

Enter name:
kara
Enter the dob it the format of DD/MM/YYYY:
04/07/1998
Enter blood group:
O+
Enter height:
164
Enter weight:
54
Enter Insurance policy number:
12345670
Enter address:
lohegaon
Enter teleno:
9673126798
Enter license number:
12345653

Enter name:
amit
Enter the dob it the format of DD/MM/YYYY:
29/12/1997
Enter blood group:
O+
Enter height:
178
Enter weight:
65
Enter Insurance policy number:
12345671
Enter address:
lohegaon
Enter teleno:
8446864474
Enter license number:
123432
******MENU********
1.Accept
2.Display
3.Insert
4.Delete
5.Edit
6.Search
7.EXIT
2
name	dob		blg	height	weight	policyno	address		teleno		licno
kara	04/07/1998	O+	164	54	12345670	lohegaon	9673126798	12345653
amit	29/12/1997	O+	178	65	12345671	lohegaon	8446864474	123432
******MENU********
1.Accept
2.Display
3.Insert
4.Delete
5.Edit
6.Search
7.EXIT
3
Enter number of datas to be inserted:
2

Enter name:
uttu
Enter the dob it the format of DD/MM/YYYY:
25/08/1997
Enter blood group:
A+
Enter height:
154
Enter weight:
34
Enter Insurance policy number:
12345672
Enter address:
mathura
Enter teleno:
8765432190
Enter license number:
1243254

Enter name:
ketaki
Enter the dob it the format of DD/MM/YYYY:
04/09/1998
Enter blood group:
B+
Enter height:
170
Enter weight:
45
Enter Insurance policy number:
12345673
Enter address:
vimanna
Enter teleno:
1234567890
Enter license number:
123465
Total number of data present now is 4
******MENU********
1.Accept
2.Display
3.Insert
4.Delete
5.Edit
6.Search
7.EXIT
2
name	dob		blg	height	weight	policyno	address		teleno		licno
kara	04/07/1998	O+	164	54	12345670	lohegaon	9673126798	12345653
amit	29/12/1997	O+	178	65	12345671	lohegaon	8446864474	123432
uttu	25/08/1997	A+	154	34	12345672	mathura	8765432190	1243254
ketaki	04/09/1998	B+	170	45	12345673	vimanna	1234567890	123465
******MENU********
1.Accept
2.Display
3.Insert
4.Delete
5.Edit
6.Search
7.EXIT
5
Enter the Policy number of the person to be Edited:
 12345672

1.Edit Name
2.Edit DOB
3.Edit blood grp
4.Edit Height
5.Edit Weight
6.Edit Address
7.Edit Telephone Number
8.Edit License number
9.EXIT
6
Enter Address
loheagaon

1.Edit Name
2.Edit DOB
3.Edit blood grp
4.Edit Height
5.Edit Weight
6.Edit Address
7.Edit Telephone Number
8.Edit License number
9.EXIT
9
******MENU********
1.Accept
2.Display
3.Insert
4.Delete
5.Edit
6.Search
7.EXIT
2
name	dob		blg	height	weight	policyno	address		teleno		licno
kara	04/07/1998	O+	164	54	12345670	lohegaon	9673126798	12345653
amit	29/12/1997	O+	178	65	12345671	lohegaon	8446864474	123432
uttu	25/08/1997	A+	154	34	12345672	loheagaon	8765432190	1243254
ketaki	04/09/1998	B+	170	45	12345673	vimanna	1234567890	123465
******MENU********
1.Accept
2.Display
3.Insert
4.Delete
5.Edit
6.Search
7.EXIT
6
Enter the Policy number of the person to be Edited:
 12345671
name	dob	blg	height	weight	policyno	address	teleno	licno
amit	29/12/1997	O+	178	65	12345671	lohegaon	8446864474	123432
******MENU********
1.Accept
2.Display
3.Insert
4.Delete
5.Edit
6.Search
7.EXIT
7
[student@localhost Documents]$ 



*/
