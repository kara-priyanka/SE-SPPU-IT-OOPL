//Name: KARA PRIYANKA       Roll no.: 03       Batch: A1
//Assignment 1: Weather report.
#include <iostream>
#include<stdio.h>
using namespace std;
class weatherreport
{
    private:
        int day_of_month;
        float hightemp;
        float lowtemp;
        float amount_rain;
        float amount_snow;
    public:
        weatherreport();
        weatherreport(int,float,float,float,float);
        int dom();
        float avght();
        float avglt();
        float avgar();
        float avgas();
};
weatherreport::weatherreport()//default constructor
{
    day_of_month=0;
    hightemp=0;
    lowtemp=0;
    amount_rain=0;
    amount_snow=0;
}
weatherreport::weatherreport(int dom,float ht,float lt,float r,float s)
 {
     day_of_month= dom;
     hightemp=ht;
     lowtemp=lt;
     amount_rain=r;
     amount_snow=s;
 }
// Function returning the Day Of Month.
int weatherreport::dom()
{
  return day_of_month;
}
// Returns Average High Temperature.
float weatherreport::avght()
{
    return(hightemp);
}
// Returns Lowest Temperature.
float weatherreport::avglt()
{
    return(lowtemp);
}
// Returns Amount Of Rain.
float weatherreport::avgar()
{
    return(amount_rain);
}
// Returns Amount Of Snow.
float weatherreport::avgas()
{
    return(amount_snow);
}
// Beginning of the main Function.
int main()
{
    int n;
    cout<<"Enter the number of data to be entered:\n";
    cin>>n;
    weatherreport obj[n];//declaring an array of objects
    int ch;
    float a1=0,a2=0,a3=0,a4=0,r1,r2,r3,r4;
    do
    {
      cout<<"\t\n MENU\n1.Input the Data \n2.Display the data\n3.EXIT\n";
      cin>>ch;
      switch (ch)
        {
            case 1:
                {
                   for(int i=0;i<n;i++)
                   {
                     hello:
                       int dom;
                       cout<<"\nEnter day of month:\n";
                       cin>>dom;
                       int ht ;
                       cout<<"\tEnter maximum temperature in degree celsius:\t";
                       cin>>ht;
                       int lt;
                       again:
                          cout<<"\tEnter the minimum temperature:\t";
                          cin>>lt;
                          if(lt>ht)
                          {
                             cout<<"AGAIN:";
                             goto again;
                          }
                       int r;
                       cout<<"\tEnter amount of rainfall in mm:\t";
                       cin >>r;
                       int s;
                       cout<<"\tEnter amount of snowfall in cm:\t";
                       cin >> s;
                       obj[i]=weatherreport(dom,ht,lt,r,s);
                       for(int j=0;j<i;j++)
                       {
                           if(obj[i].dom()==obj[j].dom())// Confirming the day of month is not repeated.
                           {
                              cout<<"\n\nAGAIN:";
                              goto hello;
                           }
                       }//End of inner for loop
                       a1+=obj[i].avght();//accessing the high temp and adding it to a1 so as to calculate the average.
                       a2+=obj[i].avglt();
                       a3+=obj[i].avgar();
                       a4+=obj[i].avgas();
                   }
                   r1=a1/n;
                   r2=a2/n;
                   r3=a3/n;
                   r4=a4/n;
                   break;
                }

            case 2:
                {
                    cout<<"\t\t\t WEATHER REPORT \t\n\n DAY\t HIGHESTTEMP\t LOWESTTEMP\t AMT OF RAIN\t AMT OF SNOW \n";
                    for(int j=0;j<n;j++)
                    {
                       cout<<obj[j].dom()<<"\t\t"<<obj[j].avght()<<"\t\t"<<obj[j].avglt()<<"\t\t"<<obj[j].avgar()<<"\t\t"<<obj[j].avgas()<<"\n";
                    }
                    // Printing the average.
                    cout<<"AVG:"<<"\t\t"<<r1<<"\t\t"<<r2<<"\t\t"<<r3<<"\t\t"<<r4<<"\n";
                    break;
                }

        }//end of switch case
    }while(ch!=3);//end of do..while()
    return 0;
}//end of main()
/*
  OUTPUT:
Enter the number of data to be entered:
5

 MENU
1.Input the Data
2.Display the data
3.EXIT
1

Enter day of month:
1
        Enter maximum temperature in degree celsius:    34
        Enter the minimum temperature:  35
AGAIN:  Enter the minimum temperature:  23
        Enter amount of rainfall in mm: 100
        Enter amount of snowfall in cm: 0

Enter day of month:
2
        Enter maximum temperature in degree celsius:    34
        Enter the minimum temperature:  12
        Enter amount of rainfall in mm: 89
        Enter amount of snowfall in cm: 00

Enter day of month:
1
        Enter maximum temperature in degree celsius:    45
        Enter the minimum temperature:  23
        Enter amount of rainfall in mm: 90
        Enter amount of snowfall in cm: 2


AGAIN:
Enter day of month:
3
        Enter maximum temperature in degree celsius:    45
        Enter the minimum temperature:  23
        Enter amount of rainfall in mm: 90
        Enter amount of snowfall in cm: 2

Enter day of month:
4
        Enter maximum temperature in degree celsius:    23
        Enter the minimum temperature:  12
        Enter amount of rainfall in mm: 0
        Enter amount of snowfall in cm: 5

Enter day of month:
5
        Enter maximum temperature in degree celsius:    12
        Enter the minimum temperature:  -3
        Enter amount of rainfall in mm: 0
        Enter amount of snowfall in cm: 5

 MENU
1.Input the Data
2.Display the data
3.EXIT
2
                         WEATHER REPORT

 DAY     HIGHESTTEMP     LOWESTTEMP      AMT OF RAIN     AMT OF SNOW
1               34              23              100             0
2               34              12              89              0
3               45              23              90              2
4               23              12              0               5
5               12              -3              0               5

AVG             29.6            13.4            55.8            2.4

 MENU
1.Input the Data
2.Display the data
3.EXIT
3

Process returned 0 (0x0)   execution time : 76.612 s
Press any key to continue.
*/
