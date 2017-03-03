// Authors Chiranth , Prasad , Sanjan
#ifndef _MAIN2_H
#define _MAIN2_H

#include "attributes.h"

int Auth::Usepwdcheck()
{
//handling exception if password lenght and username lenght is less than 6 and 4 respectively also if not matched.
        int maxchar = 10;
	int f=3;
	Display d;
	while (f > 0){
        try {
		system("clear");
		d.top(" Login " );
		cout << endl<< endl;
        	cout << cyan << " \t\t PLease Enter Username and Password to continue " << endl;
		cout << green << " \t\t Enter Username : ";
        	cin >> username;
        	if ( username.length() < 4)
        	{
                	throw "ERROR";
		}
 		else if (username != USERNAME)
        	{
                	throw 1.5;
        	}

 		else {

			cout << green << " \t\t Enter Password : ";
        		cin >> password;
			if ( password.length() < 4)
        		{
                		throw "ERROR";
        		}

			else if (password != PASSWORD) 
			{
                		throw -1;

        		}

        		else {
                		return 0;
	     		     }
		}

        	if ( username.length() > maxchar || password.length() > maxchar)
        	{
                	throw 1.0f;
        	}
        }

        	catch(const char* Message)
        	{
			cout << red <<  " \t\t Incorrect!! (username and password should be more than 4): " << endl<<endl;
        	}
        	catch(const float p)
        	{
                	cout << " \t\t Entered Value is too long "<< endl<<endl;
        	}
		catch(const double v)
        	{
			cout << red <<  " \t\t  Incorrect Username " << endl<<endl;
        	}
		catch(signed int m)
        	{
			cout << red <<  " \t\t  Incorrect Password" << endl<<endl;
        	}
		
		f--;
			cout <<  green << " \t\t you have " << f << "trial(s) left " << endl << endl;
			cin.ignore();
			cin.ignore();
		}
		return 1;
}

// checks the above function if correct user name password is entered or not and then instructs the function in mainui.cpp function to start the app
int Auth::Maincheck()
{
	a = Usepwdcheck();
	if (a == 0) {
		return 0;
	}
	else
	{
		return 1;

	}


}

//readsin the nth whole line into a string and sends to the respected function
string AttributeDB::ReadNthLine(int N)
{
	
	AttributeDB db;
	fstream in("xman.txt");

        string s;

	for(int i =0; i < N; ++i) // skips to nth line
		getline(in, s);
	getline(in,s);
	
	return s; //nth line is returned
	
}

// every line is read and ultimately whole file is read and stored in a vector
string AttributeDB::GetNthLine(int a, int b)	
{
	a= (a-1)*9+(b-1); // sets the value to the particular position( inspired by bitmap assignment)
        string s =new char[1000];
	string e;
	int d;
        string buf; // Have a buffer string
        vector<string> token; // Create vector to hold our words
       	token.reserve(350); // allocates 150 worth word space to the vector
        
       	for ( int i =0 ; i < 35; i++) // whole file is read in and stacked up to the vector, 35 represets the max number of line
        {
                s = ReadNthLine( i); 
                //cout << s << endl;
                stringstream ss(s); // Insert the string into a stream
                while (ss >> buf)
		{
                
			token.push_back(buf); // words are stored in to the vector of strings named token

                }
        }
        return token.at(a); // returns the particular value of word stored in the vecor where a position of the word in the vector
} 

// same is above but here the particula value is changed after the whole file is read and then after the change whole file is written back
int AttributeDB::WriteNthLine(int a, int b, string e)
{
	a = (a-1)*9+(b-1);
        string s = new char[1000];
	int d;
        string buf; // Have a buffer string

        vector<string> token; // Create vector to hold our words
	token.reserve(1500);
        for ( int i=0; i<35 ; i++)
        {
                s = ReadNthLine(i);
    		//cout << s << endl;
		stringstream ss(s); // Insert the string into a stream
                while (ss >> buf)
		{
                
			token.push_back(buf);

                }
        }
	
	ofstream out ("xman.txt");
        token.at(a) = e;
        for ( vector<string> ::iterator s = token.begin(); s!= token.end(); ++s)
	{
                if ( *s == "n") // have set n as the end of line in my text file
                {       out << "n"; // if end of line then \n is written so the remaining values are printed in next line just to have my txt file readable
                        out << "\n";
                }
                else
                {
                        out << *s;
                        out << "\t";
                }
        }
	return 0;


}

// used in editing a particular value. above function is called aftr asking user to specify the value to be changed and getting the confirmation
int  Attribute::GetValue(int b)
{
	string s;
	string r;
	int y;
	AttributeDB db;
	int month = GetMonth();
	cout << magenta << " \t\t Existing value is : " << db.GetNthLine(month,b)<< endl << endl;
	cout << red << " \t\t Please enter the new value :";
	cin >> r;
	cout << endl << endl;
	cout << magenta << " \t\t 1.Yes " << endl;
	cout << magenta << " \t\t 2.No " << endl << yellow;

	cout << red << " \t\t Please confirm :";
	cin >> y;
	cout << endl;
	if (y == 1)
	{
		db.WriteNthLine(month,b,r);
		cout << yellow << " \t\t Selection Confirmed" << endl << endl;
		return 0;
	}
	else
	{ 
		return 1;
	}
	
}


// allows the user to type the month in string and then returns the equivalent int value of month to WriteNthLine() to do further calculation	
int Attribute::GetMonth()
{
	Display d;
	int f=0;
	while (f < 3)
	{
	try {
	string mon;
	cout << magenta << " \t Please enter the month(eg: march14 or mar14 for 2014 and mar15 '15 and mar16 for '16 ) : ";
	cin.ignore();
	getline(cin, mon);
	//cin >> month;

	if (mon == "jan14" || mon == "january14" || mon == "feb14" || mon == "february14" || mon == "mar14" || mon == "march14" || mon == "apr14" || 
mon == "april14" || mon == "may14" || mon == "jun14" || mon == "june14" || mon == "jul14" || mon == "july14" || mon == "aug14" || mon == "august14" || 
mon == "sep14" || mon == "september14" || mon == "oct14" || mon == "october14" || mon == "nov14" || mon == "november14" || mon == "dec14" || mon == 
"december14"|| mon == "jan15" || mon == "january15" || mon == "feb15" || mon == "february15" || mon == "mar15" || mon == "march15" || mon == "apr15" || 
mon == "april15" || mon == "may15" || mon == "jun15" || mon == "june15" || mon == "jul15" || mon == "july15" || mon == "aug15" || mon == "august15" || 
mon == "sep15" || mon == "september15" || mon == "oct15" || mon == "october15" || mon == "nov15" || mon == "november15" || mon == "dec15" || mon == 
"december15" || mon == "jan16" || mon == "january16" || mon == "feb16" || mon == "february16" || mon == "mar16" || mon == "march16" || mon == "apr16" || 
mon == "april16" || mon == "may16" || mon == "jun16" || mon == "june16")
	{
					
			while (cin.good() == true)
			{

			map < string, int > month;
			month["jan14"] = 1;
			month["january14"] = 1;

			month["feb14"] = 2;
			month["february14"] = 2;

			month["mar14"] = 3;
			month["march14"] = 3;

			month["apr14"] = 4;
			month["april14"] = 4;

			month["may14"] = 5;

			month["jun14"] = 6;
			month["june14"] = 6;

			month["jul14"] = 7;
			month["july14"] = 7;

			month["aug14"] = 8;
			month["august14"] = 8;

			month["sep14"] = 9;
			month["september14"] = 9;

			month["oct14"] = 10;
			month["october14"] = 10;

			month["nov14"] = 11;
			month["november14"] = 11;

			month["dec14"] = 12;
			month["december14"] = 12;

			month["jan15"] = 13;
			month["january15"] = 13;

			month["feb15"] = 14;
			month["february15"] = 14;

			month["mar15"] = 15;
			month["march15"] = 15;

			month["apr15"] = 16;
			month["april15"] = 16;

			month["may15"] = 17;

			month["jun15"] = 18;
			month["june15"] = 18;

			month["jul15"] = 19;
			month["july15"] = 19;

			month["aug15"] = 20;
			month["august15"] = 20;

			month["sep15"] = 21;
			month["september15"] = 21;

			month["oct15"] = 22;
			month["october15"] = 22;

			month["nov15"] = 23;
			month["november15"] = 23;

			month["dec15"] = 24;
			month["december15"] = 24;

			month["jan16"] = 25;
			month["january16"] = 25;

			month["feb16"] = 26;
			month["february15"] = 26;

			month["mar16"] = 27;
			month["march16"] = 27;

			month["apr16"] = 28;
			month["april6"] = 28;

			month["may16"] = 29;

			month["jun16"] = 30;
			month["june16"] = 30;


			return month[mon];
			}
		}
		else {
			throw runtime_error(" \t\t\t\t Press Enter to try again \n ");
		     }
		}

		catch (runtime_error & e)
                      {
                        cout << yellow << " \t\t Exception occurred Please enter correct value ... Exiting"<<endl;
                        cout << e.what();
                        cin.ignore();
			d.Mainmenu();
                      }
			f++;
	}
}

//small cool function to display real time on right side of the application
void Display::Time()
{
	time_t now = time(0);
	tm*ltm = localtime(&now);
	cout << 1 + ltm->tm_mon << "/" << 1 + ltm->tm_mday << "/" << 1900 + ltm->tm_year << "  " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
}
// Display class has been defined for the UI purpose

void Display::welcome()
{
	cout << " \n\n\n";

	cout << red << " \t ****************************************************************************************" << endl;
	cout << red << " \t ****************************" << blue << " Welcome to Expense Manager " << red << "********************************" << endl;

	cout << red << " \t ****************************************************************************************" << endl;
	cout << endl;
	cout << endl;
	cout << reset;
}

void Display::top(string s)
{
	cout << " \n\n\n";
	cout << red << " \t ****************************************************************************************" << endl;
	cout << red << " \t ****************************" << blue << " Welcome to Expense Manager " << red << "********************************" << endl;
	cout << red << " \t ****************************************************************************************" << endl;
	cout << white << " \t\t\t\t\t\t\t\t Date & Time:";
	Time();
	cout << blue << " \t (" << s << ")" << "\t\t" << endl;
	cout << reset << endl;
}

void Display::DisGoback()
{
	cout << magenta << " \t\t 1. Go to Previous Menu" << endl;
	cout << magenta << " \t\t 2. Go to Main Menu" << endl;
	cout << reset << endl;
}
void Display::ViewAdd(string s)
{
	top(s);
	cout << magenta << " \t\t 1. View  " << endl;
	cout << magenta << " \t\t 2. Edit  " << endl;
	cout << magenta << " \t\t 3. Add  " << endl;
	cout << magenta << " \t\t 4. Statement " << endl;
	cout << magenta << " \t\t 5. Exit " << endl << endl;
	cout << magenta << " \t\t Choice : ";

}

void Display::dismainmenu(string s) {
	top(s);
	cout << magenta << " \t\t 1. Rent " << endl;
	cout << magenta << " \t\t 2. car loan " << endl;
	cout << magenta << " \t\t 3. Electricity and gas " << endl;
	cout << magenta << " \t\t 4. Phone " << endl;
	cout << magenta << " \t\t 5. Insurance " << endl;
	cout << magenta << " \t\t 6. Groceries " << endl;
	cout << magenta << " \t\t 7. Commute " << endl;
	cout << magenta << " \t\t 8. Miscellaneous " << endl;
	cout << magenta << " \t\t 9. Previous Menu " << endl;
	cout << magenta << " \t\t 10. Exit " << endl;
	cout << yellow << " \n\t\t choose an option : ";

}
// once the authentication has been done this function is called to start the application asking user to view,edit or add

void Display :: Statement(string str)
{
        int mon;
        Attribute a;
        AttributeDB db;
        top(str);
        mon =  a.GetMonth();
        string s = new char[10000];
        //string sum;
        string buf1;
        int sum = 0;
        int hu;
	int number;
        vector <string> statement;
        statement.reserve(1555);
                s = db.ReadNthLine(mon-1);
                stringstream ss(s); // Insert the string into a stream
                while (ss >> buf1)
                {

                        statement.push_back(buf1);

               }


	string s1 = "Rent CarLoan ElectricityGas Phone Insurance Groceries Commute Misc ";
        string buf2;
        stringstream ss1(s1);
        vector <string> r;
        while ( ss1 >> buf2)
	{
		r.push_back(buf2);
	}
	
	for ( int i=0 ; i <8; i++)
        {
        stringstream convert(statement.at(i));// convert function is used to convert a string present in i to int.
                convert >> hu;
		if (r.at(i) == "Rent" || r.at(i) == "Phone" || r.at(i) == "Misc")
		{
			cout << yellow << " \t\t "<< r.at(i) << "\t\t\t\t\t : "<< hu << endl;
		}
		else
		{
			cout << yellow << " \t\t "<< r.at(i) << "\t\t\t\t : "<< hu << endl;
	
		}
                sum=sum+hu;
        }
	cout << endl;
        cout << cyan << " \t\tTotal expenditure for this month is ($)\t : " << sum << endl;
	string Result;          // string which will contain the result

	ostringstream convert;   // stream used for the conversion

	convert << sum;
	Result = convert.str();
	a.CurrencyConv(Result);
	DisGoback();
	Goback(4);

}

int Display::Mainmenu() {
	int g, h, i;
	char c;
	system("clear");
	ViewAdd(" Main ");
	cin >> h;
	if (cin.good() == true)
	{
		system(" clear");
		switch (h)
		{
		case 1:
			Menu(h," View ");
			break;
		case 2:
			Menu(h," Edit ");
			break;
		case 3:
			Add (" Add ");
			break;
		case 4:
			Statement(" Statement ");
			break;
		case 5:
			exit(1);
			break;
		default:
			cout << " \n\n\n ";
			cout << cyan << " \t\t Please provide an valid input " << endl;
			cout << cyan << " \t\t Press enter to continue " << endl;
			cin.ignore();
			cin.ignore();
			Mainmenu();
			break;
		}
		cin.ignore();
		system("clear");
	}
	else
	{
		cout << endl;
		cout << cyan << " \t\t Please enter an Integer value " << endl;
		cout << cyan << " \t\t Press any key to continue : ";
		cin.ignore();
		cin.ignore();
		cin.ignore();
		

	}
}
//displays the attributes defined to user to take further actions
int Display::Menu(int a, string s) {
	int g, h, i;
	char c;
	system("clear");
	dismainmenu(" Main Menu --> "+ s);
	cin >> h;
	if (cin.good() == true)
	{
		system(" clear");
		switch (h)
		{
		case 1:
			MainRent(a);
			break;
		case 2:
			MainCarLoan(a);
			break;
		case 3:
			MainElecGas(a);
			break;
		case 4:
			MainPhone(a);
			break; 

		case 5:
			MainInsurance(a);
			break;
		case 6:
			MainGroceries(a);
			break; 
		case 7:
			MainCommute(a);
			break;
		case 8:
			MainMisc(a);
			break;

		case 9:
			Mainmenu();
			break;
		case 10:
			exit(1);
		default:
			cout << " \n\n\n ";
			cout << cyan << " \t\t Please provide an valid input " << endl;
			cout << cyan << " \t\t Press enter to continue " << endl;
			cin.ignore();
			cin.ignore();
			Mainmenu();
			break;
		}
		cin.ignore();
		system("clear");
	}
	else
	{
		cout << endl;
		cout << cyan << " \t\t Please enter an Integer value " << endl;
		cout << cyan << " \t\t Press any key to continue : ";
		cin.ignore();
		cin.ignore();
		cin.ignore();
		system("./xman.exe");
	}
}
// view fucntion is called when the user chooses to view a value of an attribute. this calls the getnthline() to get the value
int Display::View(string a, int c) {

	Attribute b;
	AttributeDB db;
	string Nth;
	int month;
	system("clear");
	top(a);
	month = b.GetMonth(); // gets the mapped intt value of monnth entered in string by user
	Nth = db.GetNthLine(month,c);
	cout << cyan << " \t\t Value ($): " << Nth << endl << endl;
	//cout << cyan << " \t\t Value : " << db.GetNthLine(month,c)  << endl << endl;
	b.CurrencyConv(Nth);
	DisGoback();
	Goback(1);
}
int Display::Edit(string s, int b)
{
	Attribute a;
	AttributeDB db;
	system("clear");
	top(s); //sets new value of rent and rec flag to 1
	a.ew = a.GetValue(b);// getvalue returns 0 if operation is completed succesfully and 1 if unsuccesful
	if (a.ew != 1)
	{
		DisGoback();
		Goback(2);
	}
	else
	{
		Mainmenu();
	}

}
// adds value of attributes to next month
int Display::Add(string s)
{
	Attribute a;
        AttributeDB db;
        system("clear");
        top(s); //sets new value of rent and rec flag to 1
       	int month = a.GetMonth();
        int g;
        //a.ew = db.WriteNthLine(month,b);

        string s1 = "c Rent CarLoan Elec&Gas Phone Insurance Groceries Commute Misc ";
        string buf2;
        string e;
        stringstream ss1(s1);
        vector <string> r;
        while ( ss1 >> buf2)
        {
                r.push_back(buf2);
        }
        for ( int i=1; i <9 ; i++)
        {
                cout << yellow << " \t\t Enter the value for "<<r.at(i)<<" 		: ";
                cin >> e;
                db.WriteNthLine(month,i,e);
               // cout << endl;
                cout << " \t\t Value " << e << " has been added " << endl << endl;
        }

        DisGoback();
	Goback(3);

}
//a small function called to decide on view,add or edit 
int Display::MainRent(int h) {

	Attribute a;
	system("clear");
	switch (h)
	{

	case 1: // this views the value of rent
		View(" Main Menu --> View --> Rent", 1);
		break;

	case 2:// this changes or adds the value of rent along with rec o non rec
		Edit(" Main Menu --> Edit --> Rent", 1);
		break;

/*
	case 3:// this changes or adds the value of rent along with rec o non rec
		Add(" Main Menu --> Add --> Rent", 1);
		break;
*/
	default:
		cout << " \t\t please provide an input " << endl;
		cin.ignore();
		cin.ignore();
		system("clear");
		cin.ignore();
		cout << reset;
		break;

	}
}

int Display::MainCommute(int h) {

	Attribute a;
	system("clear");
	switch (h)
	{

	case 1: // this views the value of Commute
		View(" Main Menu --> View --> Commute", 7);
		break;

	case 2:// this changes or adds the value of rent along with rec o non rec
		Edit(" Main Menu --> Edit --> Commute", 7);
		break;

	default:
		cout << " \t\t please provide an input " << endl;
		cin.ignore();
		cin.ignore();
		system("clear");
		cin.ignore();
		cout << reset;
		break;

	}
}

int Display::MainCarLoan(int h) {

        Attribute a;
        system("clear");
        switch (h)
        {

        case 1: // this views the value of CarLoan
                View(" Main Menu --> View --> CarLoan", 2);
                break;

        case 2:// this changes or adds the value of rent along with rec o non rec
                Edit(" Main Menu --> Edit --> CarLoan", 2);
                break;

        default:
                cout << " \t\t please provide an input " << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
                cin.ignore();
                cout << reset;
                break;

        }
}

int Display::MainInsurance(int h) {

        Attribute a;
        system("clear");
        switch (h)
        {

        case 1: // this views the value of Insurance 
                View(" Main Menu --> View --> Insurance", 5);
                break;

        case 2:// this changes or adds the value of rent along with rec o non rec
                Edit(" Main Menu --> Edit --> Insurance", 5);
                break;

        default:
                cout << " \t\t please provide an input " << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
                cin.ignore();
                cout << reset;
                break;

        }
}

int Display::MainGroceries(int h) {

        Attribute a;
        system("clear");
        switch (h)
        {

        case 1: // this views the value of Groceries
                View(" Main Menu --> View --> Groceries", 6);
                break;

        case 2:// this changes or adds the value of rent along with rec o non rec
                Edit(" Main Menu --> Edit --> Groceries", 6);
                break;

        default:
                cout << " \t\t please provide an input " << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
                cin.ignore();
                cout << reset;
                break;

        }
}
int Display::MainElecGas(int h) {

        Attribute a;
        system("clear");
        switch (h)
        {

        case 1: // this views the value of Groceries
                View(" Main Menu --> View --> Electricity and Gas", 3);
                break;

        case 2:// this changes or adds the value of rent along with rec o non rec
                Edit(" Main Menu --> Edit --> Electricity and Gas", 3);
                break;

        default:
                cout << " \t\t please provide an input " << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
                cin.ignore();
                cout << reset;
                break;

        }
}
int Display::MainPhone(int h) {

        Attribute a;
        system("clear");
        switch (h)
        {

        case 1: // this views the value of Groceries
                View(" Main Menu --> View --> Phone", 4);
                break;

        case 2:// this changes or adds the value of rent along with rec o non rec
                Edit(" Main Menu --> Edit--> Phone", 4);
                break;

        default:
                cout << " \t\t please provide an input " << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
                cin.ignore();
                cout << reset;
                break;

        }
}

int Display::MainMisc(int h) {

        Attribute a;
        system("clear");
        switch (h)
        {

        case 1: // this views the value of Groceries
                View(" Main Menu --> View --> Misc", 8);
                break;

        case 2:// this changes or adds the value of rent along with rec o non rec
                Edit(" Main Menu --> Edit--> Misc", 8);
                break;

        default:
                cout << " \t\t please provide an input " << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
                cin.ignore();
                cout << reset;
                break;
	}
}

int Attribute::CurrencyConv(string s)
{
	int v,c;
	cout << " \t\tPlease enter the conversion rate \t : ";
	cin >> c;
	stringstream convert(s);// convert function is used to convert a string present in i to int.
        convert >> v;
	cout << " \t\tConverted value is \t\t\t : "<< c*v<<endl;
	cin.ignore();
	return 0;
}
    
int Display::Goback(int j) { // This is for go back option for all menu.

	int i;
	cout << yellow << " \t\t choose an option : ";
	cin >> i;
	if (cin.good() == false)
	{
		cout << " \t\t Please enter an integer " << endl;
		cin.ignore();
		cin.ignore();
		return -1;
	}
	else
	{
		system("clear");
		if (i == 1 && j == 1)
		{
			Menu(1," View ");
		}
		else if (i == 1 && j == 2)
		{
			Menu(2," Edit");
		}
		else if (i == 1 && j == 3)
		{
			Add( " Add " );
		}
		else if (i == 1 && j == 4)
		{
			Statement(" Statement  ");
		}
	
		else
		{
			Mainmenu();
		}
	}
}

void Display :: StartDisp()
{

	cout << endl <<endl <<endl<<endl;
	cout << yellow << " \t\t*********************************************************************************************************************************"<< endl;
	cout << yellow << " \t\t*********************************************************************************************************************************" << endl;
	cout << yellow << " \t\t*********************************************************************************************************************************" << endl;
	cout << yellow << " \t\t*********************************************************************************************************************************" << endl;
	cout << yellow << " \t\t*********************************************************************************************************************************" << endl;
	cout << yellow << " \t\t*********************************************************************************************************************************" << endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t****************************  	 		      		*****************************************************************"<< endl;
	cout << " \t\t**************************** 			      		*****************************************************************"<< endl;
	cout << " \t\t****************************"<< red <<" 	     	WELCOME		" << yellow <<"        *****************************************************************"<< endl;
	cout << " \t\t****************************"<< red <<" 	       	  TO		 " << yellow <<"     	*****************************************************************"<< endl;
	cout << " \t\t****************************"<< red <<" 	     	EXPENSE		" << yellow <<"   	*****************************************************************"<< endl;
	cout << " \t\t****************************"<< red <<" 	     	MANAGER		" << yellow <<"	*****************************************************************"<< endl;
	cout << yellow <<" \t\t**************************** 				      	*****************************************************************"<< endl;
	cout << " \t\t**************************** 				      	*****************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*******************************************************************"<< green <<" Application BY:  	 " << yellow <<"	 ********************************"<< endl;
	cout << " \t\t*******************************************************************"<< green <<"		 " << yellow <<"	         ********************************"<< endl;
	cout << " \t\t*******************************************************************"<< green <<" 	Chiranth,Prasad & Sanjan " << yellow <<"********************************"<< endl;
	cout << " \t\t*******************************************************************"<< green <<" 			  " << yellow <<"       ********************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
	cout << " \t\t*********************************************************************************************************************************"<< endl;
}

#endif
