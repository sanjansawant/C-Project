// Authors Chiranth , Prasad , Sanjan 
#ifndef _ATTRIBUTES_H
#define _ATTRIBUTES_H

#include <iostream>
#include <string>
#include "color.h"
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <stdexcept>


using namespace std;
// class used for authenticating at the start of the application
class Auth {
public:
	string USERNAME;
	string PASSWORD;// = "123456";
	string username, password;
	Auth(string USER = "sanjan", string PASS = "123456") : USERNAME(USER), PASSWORD(PASS) {}
	int a, b;
	int Usepwdcheck();
	int Maincheck();
};



// class having the methods for reading and writing a line from the txt file
class Attribute {

	string username, statement;
	double rent, carloan, elecgas, phone, insurance, groceries, commute, misc, rflag, threshold;
	fstream infile;
	ofstream ofile;

//public:

	//Attribute(double  r = 1000, double c = 400, double  e = 100, double p = 50, double  i = 800, double  g = 100, double co = 150, double  m = 400, double rf = 0, double  t = 1000) : rent(r), carloan(c), elecgas(e), phone(p), insurance(i), groceries(g), commute(co), misc(m), rflag(rf), threshold(t) {}
//	Attribute() : infile("xman.txt") {
		/*		GotoLine(1);
		infile >> rent;
		infile >> carloan;
		infile >> elecgas;
		infile >> phone;
		infile >> insurance;
		infile >> groceries;
		infile >> commute;
		infile >> misc;
		infile >> rflag;
		infile >> threshold;
		*/
//	}

public:
	double ew;
	int GetMonth();
	double CalMisc();
	int GetValue(int a);
	int CurrencyConv(string s);
};

class AttributeDB{
public:
	
	string	ReadNthLine( int N);
	string	GetNthLine( int a,int b );
	int 	WriteNthLine(int a,int b, string r);

};
//class used for displaying items i.e for UI purpose
class Display {
public:
	void welcome();
	void StartDisp();
	void top(string s);
	void dismainmenu(string s);
	void DisGoback();
	void disviewoedit();
	void Time();
	void ViewAdd(string s);
	void Statement(string s);
	int View(string a, int c);
	int Menu(int a, string s);
	int Add(string a);
	int Edit(string a, int b);
	int Mainmenu();
	int MainRent(int a);
	int MainCarLoan(int a);
	int MainElecGas(int a);
	int MainPhone(int a);
	int MainInsurance(int a);
	int MainGroceries(int a);
	int MainCommute(int a);
	int MainMisc(int h);
	int Goback(int j);
};

#endif

