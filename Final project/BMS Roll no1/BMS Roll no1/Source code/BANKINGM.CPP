
//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************


#include<fstream.h>
#include<ctype.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include"log.cpp"
//#include"main.cpp"



//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class account
{

	int acno;
	int ano1,ano2,ano3;
	char name[50];
	char add[20];
	char phoneno[10];
	int deposit;
	char type;
public:
       account()
       {
	ano1=NULL;
	ano2=NULL;
	ano3=NULL;
       }

	void create_account();
	void show_account();
	void modify();
	void getdata();
	void datetime();
	void dep(int);
	void draw(int);
	void report();
	int retacno();
	int retdeposit();
	char rettype();
	void details();
};

void account::create_account()
{
//	cout<<"\n Creation of New Account";
	cout<<"\nEnter The account No. :";
	cin>>acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	gets(name);
  //	cin>>name;
	cout<<"\n Enter Address of The account Holder :";
	cin>>add;
	cout<<"\n Enter Contact no :";
	cin>>phoneno;
	cout<<"\nEnter Type of The account (S/C): ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	time_t now=time(0);
	tm *ltm=localtime(&now);
	cout<<"\nDate:";
	cout<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/";
	cout<<1900+ltm->tm_year<<"\n";
	cout<<"\nTime";
	cout<<1+ltm->tm_hour<<":";
	cout<<1+ltm->tm_min<<":";
	cout<<1+ltm->tm_sec<<"\n";

	cout<<"\n\n\nAccount Created..";
}

void account::show_account()
{

	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name :"<<name;
	cout<<"\nAccount Holder Address :"<<add;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
	cout<<"\nAccout Holder Contact no :"<<phoneno;

}


void account::modify()
{
	cout<<"\nThe account No."<<acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	gets(name);
	cout<<"\nEnter Type of The account (S/C) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The amount : ";
	cin>>deposit;
}

void account::getdata()
{  int num;
	cout<<"\nThe account No."<<acno;
	cout<<"\n\nEnter The Name of The account Holder as per aadhar: ";
	gets(name);
 //	cin>>name;
	cout<<"\nEnter Your Aadhar number(>=12): ";
	cin>>ano1>>ano2>>ano3;
	 cout<<"\n Account no:"<<acno;
	 cout<<"\n Account no linked to ur account is:";
      cout<<"\n"<<ano1<<ano2<<ano3;
      cout<<"\nAccount Holder Name : "<<name;
     cout<<"\n Record saved....";

}
void datetime()
{
time_t now=time(0);
tm *ltm=localtime(&now);
cout<<"\t\t\t\t\t\t\t\tDate:";
cout<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/";
cout<<1900+ltm->tm_year<<"\n";
cout<<"\t\t\t\t\t\t\t\tTime";
cout<<1+ltm->tm_hour<<":";
cout<<1+ltm->tm_min<<":";
cout<<1+ltm->tm_sec<<"\n";
}
void account::details()
{
	  clrscr();
	  time_t now=time(0);
	  tm *ltm=localtime(&now);
	  cout<<"\nTransaction Details:\n";
	 cout<<"\nTransaction Date:"<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/";
	cout<<1900+ltm->tm_year<<"\n";
	 cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name :"<<name;
	cout<<"\nRemaining Balance amount : "<<deposit;
 }
 void intro()
{       abc.menu();
	clrscr();
	cout<<"\n\n\t\t\t\t  BANK";
	cout<<"\n\n\t\t\t\tMANAGEMENT";
	cout<<"\n\n\t\t\t\t  SYSTEM";
	cout<<"\n\n\n\n\t\tMADE BY : Kshitij Bansod & Suraj Takale";
	cout<<"\n\n\t\tcollege : KIT'S IMER,Kolhapur";
	getch();
}

void account::dep(int x)
{
	deposit+=x;
	details();
}

void account::draw(int x)
{
	deposit-=x;
	details();
}

void account::report()
{      time_t now=time(0);
      tm *ltm=localtime(&now);
      cout<<acno<<setw(10)<<" "<<name<<setw(7)<<" "<<type<<setw(7)<<deposit<<setw(7)<<" "<<add<<setw(7)<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<setw(5)<<" "<<ano1<<ano2<<ano3<<endl;
}

int account::retacno()
{
	return acno;
}

int account::retdeposit()
{
	return deposit;
}

char account::rettype()
{
	return type;
}


//***************************************************************
//    	function declaration
//****************************************************************
void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function
void getdatashow(int);
//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
	char ch;
	int num;
	clrscr();
	datetime();
	intro();
	do
	{
		clrscr();
		datetime();
		cout<<"\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08.LINK YOUR AADHAR NO";
		cout<<"\n\n\t09. EXIT";
		cout<<"\n\n\tSelect Your Option (1-9) ";
		ch=getche();
		clrscr();
		switch(ch)
		{
		case '1':
			 datetime();
			 clrscr();
			write_account();
			break;
		case '2':
			 datetime();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			 datetime();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			 datetime();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			 datetime();
			display_all();
			break;
		case '6':
			 datetime();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
			datetime();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
			  datetime();
		       //	  check();
			  cout<<"\n\n\tEnter The account No. : "; cin>>num;
			  getdatashow(num);
		//	 display_sp(num);
			 break;
		  case '9':
			cout<<"\n\n\tThanks for using bank managemnt system";
			break;
		 default :cout<<"\a";
		}
		getch();
    }while(ch!='9');
	return 0;
}


//***************************************************************
//    	function to write in file
//****************************************************************

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.data",ios::binary|ios::app);
	ac.create_account();
	outFile.write((char *) &ac, sizeof(account));
	outFile.close();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	account ac;
	int flag=0;
	ifstream inFile;
    inFile.open("account.data",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
    while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=1;
		}
	}
    inFile.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
}


//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_account(int n)
{
	int found=0;
	account ac;
	fstream File;
    File.open("account.data",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*sizeof(account);
			File.seekp(pos,ios::cur);
		    File.write((char *) &ac, sizeof(account));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		  }
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}

//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.data",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.data",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write((char *) &ac, sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.data");
	rename("Temp.data","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}

//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.data",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"==============================================================================\n";
	cout<<"A/c no.      NAME           Type  Balance  Address  Last Access    Aadharno.\n";
	cout<<"==============================================================================\n";
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

//***************************************************************
//    	function to deposit and withdraw amounts
//****************************************************************

void deposit_withdraw(int n, int option)
{
	int amt;
	int found=0;
	account ac;
	fstream File;
    File.open("account.data", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)* sizeof(ac);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=1;
	       }
	 }
    File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}
void getdatashow(int n)
{

	int found=0;
	int yes;
	account ac;
	fstream File;
    File.open("account.data",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{


			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.getdata();
			int pos=(-1)*sizeof(account);
			File.seekp(pos,ios::cur);
		    File.write((char *) &ac, sizeof(account));
		    cout<<"\n\n\t Record Updated";
		    found=1;

		  }
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";

}

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

/*void intro()
{
	cout<<"\n\n\t\t\t\t  BANK";
	cout<<"\n\n\t\t\t\tMANAGEMENT";
	cout<<"\n\n\t\t\t\t  SYSTEM";
	cout<<"\n\n\n\n\t\tMADE BY : Kshitij Bansod & Suraj Takale";
	cout<<"\n\n\t\tcollege : KIT'S IMER,Kolhapur";
	getch();
} */

//***************************************************************
//    			END OF PROJECT
//***************************************************************
