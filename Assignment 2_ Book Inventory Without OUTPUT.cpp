//Name: KARA PRIYANKA    Roll no.: 03    Batch:A1
//Assignment 2: Book Inventory.
#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
static int c;
static int d;
class books
{
   char *title;
   char *author;
   char *pub;
   float price;
   int avst;
   public:
     void display();
     void update(books b[],int);
     void search(char key[],books b[],int);
     void purchase(books b[],int);
     void record(int n);
     books(){} // We need it because we have created an object without passing the parameters in it.
     books(char t[30],char a[30],char publ[30],float pr,int avlst)
     {
        title=new char[20];
        author=new char[20];
        pub=new char[20];
        price=0;
        avst=0;
        strcpy(title,t);
        strcpy(author,a);
        strcpy(pub,publ);
        price=pr;
        avst=avlst;
     }
};
// Beginning of main();
int main()
{
    int n;
    cout<<"Enter the number of books to be entered:\n";
    cin>>n;
    class books b[10],b1;
    int ch;
    char key[20];
    do
    {
        cout<<"\t \nMENU \t \n"<<"1.Enter the books\n2.Display\n3.Update\n4.Search\n5.Purchase\n6.Record no of successful/unsuccessful transaction\n7.EXIT"<<endl;
        cin>>ch;
        switch (ch)
        {
         case 1:
             {
                for(int i=0;i<n;i++)
                {
                    cout<<"\nEnter the data:";
                    char t[30];
                    cout<<"\nEnter the name of Book:\t";
                    cin>>t;
                    char a[30];
                    cout<<"Enter The Name Of Author:\t";
                    cin>>a;
                    char p[30];
                    cout<<"Enter The name of Publisher:\t";
                    cin>>p;
                    float pr;
                    cout<<"Enter the Price of book:\t";
                    cin>>pr;
                    int st;
                    cout<<"Enter Stock of book:\t";
                    cin>>st;
                    b[i]=books(t,a,p,pr,st);
                }
                break;
             }
         case 2:
            {
                cout<<"\nTITLE"<<"\t"<<"AUTHOR"<<"\t\t"<<"PUBLISHER"<<"\t"<<"PRICE"<<"\t"<<"AVAILABLE STOCK"<<"\n";
                for(int i=0;i<n;i++)
                {
                   b[i].display();
                }
                break;
             }
         case 3:
             {
                  b1.update(b,n);
                  break;
             }

         case 4:
            {
                cout<<"Enter the title of the book to be searched for \n";
                cin>>key;
                b1.search(key,b,n);
                break;
            }
         case 5:
            {
                b1.purchase(b,n);
                break;
            }
         case 6:
            {
                b1.record(0);// We entered 0 in the parameter because here no such transaction has occurred and we need the successful and unsuccessful transaction.
                break;
            }
        }// end of switch case.
    }while(ch!=7);// End of do... while loop.
    return 0;
}
// Display function.
void books::display()
{
        cout<<title<<"\t"<<author<<"\t\t"<<pub<<"\t"<<price<<"\t"<<avst<<"\n";
}
// Search function.
void books::search(char key[],books b[],int n)
{
 int i,j;
 for(i=0;i<n;i++)
 {
    if(strcmp(key,b[i].title)==0)
    {
        cout<<"RECORD FOUND: \n";
        cout<<"TITLE"<<"\t"<<"AUTHOR"<<"\t"<<"PUBLISHER"<<"\t"<<"PRICE"<<"\t"<<"AVAILABLE STOCK"<<"\n";
        b[i].display();
        break;
    }
    else
      cout<<"RECORD NOT FOUND\n";
 }//end of for loop.
}
// Update function.
void books::update(books b[],int n)
{
    char t[20],a[20];
    int ch,newprice,newavst,i;
    char newt[20],newa[20],newp[20];
    cout<<"Enter the Title of the book to be updated: \n";
    cin>>t;
    cout<<"Enter the Author of the book to be updated:\n";
    cin>>a;
    for(i=0;i<n;i++)
     {
          if((strcmp(t,b[i].title)==0)&&(strcmp(a,b[i].author)==0))
          {
            do
            {
                cout<<"\nWhat do you want to modify? \n 1.Title\n2.Author\n3.Publisher\n4.Price\n5.Available Stock\n6.EXIT\n";
                cin>>ch;
                switch(ch)
                {
                     case 1:
                         {
                             cout<<"Enter the new title to be updated \n";
                             cin>>newt;
                             strcpy(b[i].title,newt);
                             break;
                         }
                     case 2:
                         {
                             cout<<"Enter the new Author to be updated \n";
                             cin>>newa;
                             strcpy(b[i].author,newa);
                             break;
                         }
                     case 3:
                        {
                             cout<<"Enter the new publisher to be updated \n";
                             cin>>newp;
                             strcpy(b[i].pub,newp);
                             break;
                        }

                     case 4:
                        {
                             cout<<"Enter the new price to be updated \n";
                             cin>>newprice;
                             b[i].price=newprice;
                             break;
                        }

                     case 5:
                        {
                             cout<<"Enter the new available stock to be updated \n";
                             cin>>newavst;
                             b[i].avst=newavst;
                             break;
                        }
                }// end of switch.
          }while(ch!=6);//end of do..while
        }// end of if.
    }// end of for loop.
}// end of function update.

// Purchase function.
void books::purchase(books b[],int n)
{
    char key[20];
    int i,q;
    books b4;
    cout<<"Enter the title of the book to be purchased \n";
    cin>>key;
    for(i=0;i<n;i++)
     {
          if(strcmp(key,b[i].title)==0)
          {
            cout<<"Enter the quantity of the books to be purchased \n";
            cin>>q;
            if(q<=b[i].avst)
            {
                b4.record(1);
                cout<<"Total Bill:\t"<<(q*b[i].price)<<"\n";
                b[i].avst=(b[i].avst-q);
            }// end of inner if.
            else
            {
                b4.record(2);
                cout<<"Specified quantity unavailable \n";
            }// end of else.
          }// end of outer if.
    }// end f for loop.
}
// Record function.
void books::record(int n)
{
    if(n==1)
      c++;
    if(n==2)
      d++;
    cout<<"Number of successful transactions: "<<c<<"\n";
    cout<<"Number of unsuccessful transactions: "<<d<<"\n";
}

/*
OUTPUT:

*/
