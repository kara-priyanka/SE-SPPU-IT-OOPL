// Name: KARA PRIYANKA    Batch: A1   Roll no.: 03
// Assignment 9: Biodata

/*9. Create employee bio-data using following classes i) Personal record ii) Professional record iii)
Academic record Assume appropriate data members and member function to accept required data & print bio-data. Create bio-data using multiple inheritance using C++.*/


#include<iostream>
#include<string>

using namespace std;

class personal;
class academics;
class professional;
class biodata;

class personal
{
   public:
     string name;
     string fname;
     string mname;
     int age;
     char gender;
};

class professional
{
   public:
     int yrs;
     string company;
};

class academics
{
   public:
     float per10;
     float per12;
     float perdeg;
};


class biodata:public personal,public academics,public professional
{
   public:
     void fn_accept();
     void fn_display();
};

// Function to accept data.
void biodata::fn_accept()
{
     cout<<"\nEnter the Data:\n";
     cout<<"enter the name of the candidate:"<<endl;
     getline(cin,name);
     getline(cin,name);
     cout<<"enter father's name:"<<endl;
     getline(cin,fname);
     cout<<"enter mother's name:"<<endl;
     getline(cin,mname);
     cout<<"enter the age:"<<endl;
     cin>>age;
     cout<<"enter gender as female=f and male =m"<<endl;
     cin>>gender;
     cout<<"enter the percentage of class 10th,12th and degree: "<<endl;
     cin>>per10>>per12>>perdeg;
     cout<<"enter years of experience:"<<endl;
     cin>>yrs;
     cout<<"Enter Company Worked in the company worked in:"<<endl;
     getline(cin,company);
     getline(cin,company);
}

// Function to display the data.
void biodata::fn_display()
{
    cout<<"Personal data:\n";
    cout<<"name of the candidate:"<<name<<endl;
    cout<<"father's name:"<<fname<<endl;
    cout<<"mother's name:"<<mname<<endl;
    cout<<"age:"<<age<<endl;
    cout<<"gender:"<<gender<<endl;

    cout<<"Academics :\n";
    cout<<"percentage in class 10th,12th and degree:\n "<<per10<<endl<<per12<<endl<<perdeg<<endl;

    cout<<"Personal data:\n";
    cout<<"years of experience:"<<yrs<<endl;
    cout<<"company worked in:"<<company<<endl;
}

int main()
{
    biodata a[100];
    int enter,no;
    do
    {
      cout<<"*****MENU*****\n1.Accept data\n2.Display data\n3.EXIT\n";
      cin>>enter;
      switch(enter)
      {
        case 1:
        {
          cout<<"Enter number of data to be entered:\n";
          cin>>no;
          for(int i=0;i<no;i++)
           {
           cout<<"\nEmployee : "<<i+1;
           a[i].fn_accept(); }
           break;
        }
        case 2:
        {
          for(int i=0;i<no;i++)
          {
            cout<<"\nDATA NO "<<i+1<<endl;
            a[i].fn_display();
          }
          break;
        }//end of case 2
      }//end of switch
    }while(enter!=3);// end of do....while
    return 0;
}


/*
OUTPUT:

*****MENU*****
1.Accept data
2.Display data
3.EXIT
1
Enter number of data to be entered:
2

Employee : 1
Enter the Data:
enter the name of the candidate:
kara
enter father's name:
kara shankar rao
enter mother's name:
kara aruna
enter the age:
19
enter gender as female=f and male =m
f
enter the percentage of class 10th,12th and degree:
95
91.6
76
enter years of experience:
5
Enter Company Worked in the company worked in:
google

Employee : 2
Enter the Data:
enter the name of the candidate:
kara shankar rao

enter father's name:
kara biswanath
enter mother's name:
kara erramma
enter the age:
49
enter gender as female=f and male =m
m
enter the percentage of class 10th,12th and degree:
76
87
80
enter years of experience:
20
Enter Company Worked in the company worked in:
indian navy
*****MENU*****
1.Accept data
2.Display data
3.EXIT
2

DATA NO 1
Personal data:
name of the candidate:kara
father's name:kara shankar rao
mother's name:kara aruna
age:19
gender:f
Academics :
percentage in class 10th,12th and degree:
 95
91.6
76
Personal data:
years of experience:5
company worked in:google

DATA NO 2
Personal data:
name of the candidate:kara shankar rao
father's name:kara biswanath
mother's name:kara erramma
age:49
gender:m
Academics :
percentage in class 10th,12th and degree:
 76
87
80
Personal data:
years of experience:20
company worked in:indian navy
*****MENU*****
1.Accept data
2.Display data
3.EXIT
3
*/
