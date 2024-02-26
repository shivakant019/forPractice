#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<windows.h>

using namespace std;

class book
{
	char bno[6];
	char bname[50];
	char aname[20];
  public:
	void create_book()
	{
        cout<<"\nNEW BOOK ENTRY...\n";
        cout<<"\nEnter The book no.";
        cin>>bno;
        cout<<"\n\nEnter The Name of The Book ";
        cin>>bname;
        cout<<"\n\nEnter The Author's Name ";
        cin>>aname;
        cout<<"\n\n\nBook Created..";
    }

    void show_book()
    {
        cout<<"\nBook no. : "<<bno;
        cout<<"\nBook Name : ";
        puts(bname);
        cout<<"Author Name : ";
        puts(aname);
    }

    void modify_book()
    {
        cout<<"\nBook no. : "<<bno;
        cout<<"\nModify Book Name : ";
        gets(bname);
        cout<<"\nModify Author's Name of Book : ";
        gets(aname);
    }

    char* retbno()
    {
        return bno;
    }

    void report()
    {
        cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
    }


};         //class ends here




class student
{
    char admno[6];
    char name[20];
    char stbno[6];
    int token;
public:
    void create_student()
    {
        system("cls");;
         cout<<"\nNEW STUDENT ENTRY...\n";
        cout<<"\nEnter The admission no. ";
        cin>>admno;
        cout<<"\n\nEnter The Name of The Student ";
        cin>>name;
        token=0;
        stbno[0]='/0';
        cout<<"\n\nStudent Record Created..";
    }

    void show_student()


    void modify_student()


    char* retadmno()


    char* retstbno()


    int rettoken()


    void addtoken()

    void resettoken()

    void getstbno(char t[])


    void report()


};         //class ends here







void write_book()
{

}

void write_student()
{

}


//

void display_spb(char n[])
{


void display_sps(char n[])
{

}


void modify_book()



void modify_student()
{

}



void delete_student()
{

}


void delete_book(){}






void display_alls()
{

}


//***************************************************************
//        function to display Books list
//****************************************************************

void display_allb()
{

}



void book_issue()
{

}

void book_deposit()
{

}







//***************************************************************
//        ADMINISTRATOR MENU FUNCTION
//****************************************************************

void admin_menu()
{
    system("cls");;
    int ch2;
    cout<<"\n\n\n\tADMINISTRATOR MENU";
    cout<<"\n\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
    cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
    cout<<"\n\n\t4.MODIFY STUDENT RECORD";
    cout<<"\n\n\t5.DELETE STUDENT RECORD";
    cout<<"\n\n\t6.CREATE BOOK ";
    cout<<"\n\n\t7.DISPLAY ALL BOOKS ";
    cout<<"\n\n\t8.DISPLAY SPECIFIC BOOK ";
    cout<<"\n\n\t9.MODIFY BOOK ";
    cout<<"\n\n\t10.DELETE BOOK ";
    cout<<"\n\n\t11.BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-11) ";
    cin>>ch2;

}



