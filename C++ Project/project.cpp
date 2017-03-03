#include <iostream> 
#include <string> 

using namespace std;



int f(string USERNAME,string PASSWORD,string username,string password){

cout << "\n"<<"Enter Username : ";
        cin >> username;


        if(username.length() < 4)
        {
                cout << "Username length must be atleast 4 characters long."<<"\n";
        }
        else
        {

                cout << "Enter Password : ";
                cin >> password;


                if(password.length() < 6 )
                {
                        cout <<"\n"<< "Password length must be atleast 6 character long."<<"\n";

                }
    }




if(username == USERNAME && password == PASSWORD){

return 0;
}

else{
cout<<"Inserted wrong userid or password try again"<<"\n";
return 1;
}





}





int main()
{
	int a;

	const string USERNAME = "sanjan";
	const string PASSWORD = "123456";
	 
	string username, password;

	a=f(USERNAME,PASSWORD,username,password);

 
      		
			
			
if(a==1){
int i=0;
while(i<3){

if(username != USERNAME || password != PASSWORD){
a=f(USERNAME,PASSWORD,username,password);
if(a==0){

break;
}

else{

i++;}
}


}
}
			
			
if(a==0){
cout<<"end";

}
                           


return 0;
}







