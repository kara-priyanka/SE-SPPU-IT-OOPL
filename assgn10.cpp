/*	Name: Sushrut Naik
	RollNo: 231041
	Assignment: File Handling*/



#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class student
{
	int roll_no;
	char name[50];
	public:
	void fn_getdata();
	void fn_putdata();
	int fn_rollno()
	{
		return roll_no;
	}	 
};

void student::fn_getdata()
{
	cout<<"Enter the name\n";
	ws(cin);
	cin.getline(name,50);
	cout<<"Enter the roll number\n";
	cin>>roll_no;
}

void student::fn_putdata()
{
	cout<<name<<"\t"<<roll_no<<endl;
}

class seq_file
{
	char filename[];
	public:
	seq_file();
	void fn_create();
	void fn_display();
	void fn_add();
	void fn_search(int key);
	void fn_modify(int key);
	void fn_delete(int key);
};
seq_file::seq_file()
{
	ofstream file("stud.txt");
	strcpy(filename,"stud.txt");
	if(file.eof()!=0)
	{
		cout<<"File created successfully\n";
	}
	else
	{
		cout<<"Error in creating file\n";
	}
	file.close();
}
void seq_file::fn_create()
{
	ofstream file;
	file.open("stud.txt");
	student s;
	s.fn_getdata();
	file.write(reinterpret_cast<char *>(&s),sizeof(s));
	file.close();
}
void seq_file::fn_display()
{
	ifstream file;
	file.open("stud.txt");
	student s;
	cout<<"Name\tRoll Number\n";
	file.read(reinterpret_cast<char *>(&s),sizeof(s));
	while(!file.eof())
	{ 
		s.fn_putdata();
		file.read(reinterpret_cast<char *>(&s),sizeof(s));
		
	}
	file.close();
}
void seq_file::fn_add()
{
	ofstream file;
	file.open("stud.txt",ios::app);
	student s;
	s.fn_getdata();
	file.write(reinterpret_cast<char *>(&s),sizeof(s));
	file.close();
}


int main()
{
	int i, choice, num, key;
	seq_file obj;
	ofstream file;
	do
	{	
		cout<<"Enter 1 to create database\nEnter 2 to display database\nEnter 3 to exit\n";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"Enter number of records\n";
			cin>>num;
			obj.fn_create();
		        for(i = 0; i < (num - 1); i++)
		        	obj.fn_add();
			break;
			 	
		case 2:
			file.seekp(0);
			obj.fn_display();
			break;
			 	
		case 3:
			break;
		}
	}while(choice != 3);
        return 0;
}
/*	OUTPUT
File created successfully
Enter 1 to create database
Enter 2 to display database
Enter 3 to exit
1
Enter number of records
3
Enter the name
a
Enter the roll number
1
Enter the name
b
Enter the roll number
2
Enter the name
c
Enter the roll number
3
Enter 1 to create database
Enter 2 to display database
Enter 3 to exit
2
Name	Roll Number
a	1
b	2
c	3
Enter 1 to create database
Enter 2 to display database
Enter 3 to exit
3*/

