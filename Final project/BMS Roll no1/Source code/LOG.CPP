#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
//#include"pwdtry.cpp"
class login
{
  protected:
   char login[20];
   char login_pw[20];
   char username[20];
   char password[20];
   int c,i;

public:
       void user()
       {
	 ofstream file;
	 file.open("user.txt");
	 file<<"\n\t\t\t Username :";
	 file<<"kshitij";
	 file<<"suraj";              //write a useename
	 file.close();
	}

	 void pass()
	 {

	  ofstream file1;
	  file1.open("pass.txt");
	  file1<<"\n\t\t\t Password";
	  file1<<"9896";
	  file1<<"1234";
	  file1.close();
	}

	void if_user()
	{

	  ifstream uname;
	  uname.open("user.txt");
	  uname.getline(username,50);


	    while(strcmp("kshitij",login)!=0)
	     {
	      cout<<"\n\t\t\t\t Username:";
	      cin>>login;
	       if(strcmp(login,"kshitij")==0)
		{

		  cout<<"\n\t\t\t\t Password:";
		 }
		else
		 {

		 if_user();

		}
	     }

	     uname.close();
	    }


	     void if_pass()
	     {

	       ifstream pin;
	       pin.open("pass.txt");
	       pin.getline(password,50);
		while(strcmp("9896",login_pw)!=0)
		 {

		  while(i<4)
		  {
		    login_pw[i]=getch();
		    cout<<"*";
		    ++i;
		     }

		     if(strcmp(login_pw,"9896")==0)
		    {
		       char ch,sml=987;
			ch=sml;
			cout<<"\n\n\t\t\t\t";
			  for(i=0;i<20;i++)
			  {
			   delay(200);
			   cout<<ch;
			   }
		      }
		    else
		      {

			cout<<"\b\b\b\bInvalid";

			delay(200);

		      exit(0);
		     }

		  }
		  pin.close();

		}


		 void display()
		 {

		   user();
		   pass();
		   if_user();
		   if_pass();
		 }

		 void menu()
		 {
	   //	 login obj;
		 int op;
		 cout<<"\n\n********************************************************************************\n";
		 cout<<"\t\t\t\t  BANK\n";

		 cout<<"\n\t\t\t\tMANAGEMENT\n";

		 cout<<"\n\t\t\t\t  SYSTEM\n";
		  cout<<"\n********************************************************************************";


		 cout<<"\n\t\t\t\t Admin Login\n";

		 display();
	     getch();
		   }

		   }abc;


























