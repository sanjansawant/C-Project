#include<iostream>
#include<string>
using namespace std;

void f(string& username,string& password){
cout<<"\n"<<"Enter the preferred username: ";
cin>>username;
int j;
if(username.length() < 4)
{

                for(j=0;j<=2;j++){
                cout << "Username length must be atleast 4 characters long."<<"\n";
                cout<<"\n"<<"Enter the preferred username: ";
                cin>>username;
                if(username.length()>4){
                goto step1;

                }

                }
      
cout<<"you have reached max limit";
}  else{


step1:                cout << "Enter Password : ";
                      cin >> password;
        int k;
        if(password.length() < 6)
       {
                for(k=0;k<=2;k++){
                cout << "password length must be atleast 6 characters long."<<"\n";
                cout<<"\n"<<"Enter password: ";
                cin>>password;
if(password.length() > 6){
cout<<"end";
break;
}
                }
cout<<"you have reached max limit";
}



}


//step2:cout<<"End";
//step3:cout<<"you have reached the max limit";


}



void g(string username,string password,string security1,string security2,string security3){
if(username.length()>=4 && password.length()>=6){
int s;

cout<<"\n"<<"Do you want to have security questions"<<"\n";
cout<<"press 1 for yes"<<"\n";
cout<<"press 0 for no"<<"\n";
cin>>s;
switch(s){
case 0: break;
case 1:cout<<"what was the name of your 1st pet"<<"\n";
      cin>>security1;
case 2:cout<<"Name of your grandfather"<<"\n";
      cin>>security2;
case 3:cout<<"Name of your 1st child"<<"\n";
      cin>>security3;
      break;
}
}
else{
cout<<"\n"<<"Try again tomorrow";
}

}














int main(){
string sex,fname,lname,username,password;
int age;
string security1,security2,security3;

cout << "\n"<<"Enter First Name : ";
cin >>fname;

cout<<"\n"<<"Enter Last name: ";
cin>>lname;

cout<<"\n"<<"Enter your Gender:";
cin>>sex;

cout<<"\n"<<"Enter your age: ";
cin>>age;
f(username,password);

g(username,password,security1,security2,security3);        


}
