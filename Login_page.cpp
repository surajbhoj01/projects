#include <iostream>
#include <fstream> //file stream
#include <stdlib.h> //include library function exit(1)
#include <cstring>  //Include string functions
#include <sstream>  //INcludes the string stream library

using namespace std;

class manage
{
    string username, Email, Password;
    string searchName, searchEmail ,searchPassword;
    fstream file;

public:
    void Signup();
    void Login();
    void forgot();

} obj;

int main()
{
    int choice;
    cout << "-------------ENTER your choice---------------" << endl;
    cout << "\n Enter 1 for Signup::"<<endl
         << "\n Enter 2 for Login::"<<endl
         << "\n Enter 3 if you forgot your password::";

    cin >> choice;
    switch (choice)
    {
    case 1:
        obj.Signup();
        break;

    case 2:
        obj.Login();


        break;

    case 3:
        obj.forgot();
        break;

    default:
        cout<<"~Enter a valid operation!!"<<endl;

    }

    return 0;
}

void manage :: Login(){
    file.open("login_data.txt", ios::in);//to open a file in read mode using ios class

    if(!file.is_open()){  //checking if file is open
        cout<<"An error occured"<<endl;
        exit(1);
    }

    cout<<"|--------------LOGIN--------------|"<<endl;

    cout<<"Enter your username:: ";
    cin>>searchName;

    cout<<"Enter your password:: ";
    cin>>searchPassword;

    string line;
    int found = 0;

    while(getline(file,line)){ //get line and return if exist
        if(line.find(username) != string::npos && line.find(searchPassword) != string::npos){ //to search two definite word in the file
            cout<<"<---------Your are Logged in--------->"<<endl;
            found = 1;
        }
        
    }

    if(!found){
            cout<<"!!!!!!!!Wrong credentials.........."<<endl;
        }

    

    file.close();
}

void manage :: Signup(){
    string pass;
    cout<<"|-------------SIGN UP-----------|"<<endl;
    cout<<"Enter your Email id (eg:- abc@gmail.com):: ";
    cin>>Email;

    cout << "Enter username:: ";
    cin>>username;


    

    file.open("login_data.txt",ios :: out | ios :: app ); //out means write mode and app means append mode



    if(!file.is_open()){
        cout<<"An error occured"<<endl;
        exit(1);
    }

    again:

    cout<< "Enter a password:: ";
    cin>>Password;

    cout<< "Confirm password:: ";
    cin>>pass;



    if(pass == Password){//to check if confirm password matches with password given earlier

        cout<<"(:---------Conguratulation You are signed up--------:)"<<endl;
        file<<Email<<" "<<username<<" "<<Password<<"\n";
    }

    else {
        cout<<"<-----! Your password mismatch / Enter again------>"<<endl;
        goto again;
    }

    file.close();    
}

void manage :: forgot(){
    
    file.open("login_data.txt", ios::in );

    if(!file.is_open()){
        cout<<"An error occured"<<endl;
        exit(1);
    }

    cout<<"Enter your Email :: ";
    cin>>searchEmail;


    string usr;
    string pass;
    string line;
    string temp;
    int count = 0;

    while(getline(file,line)){
            string word;
            stringstream iss(line);
            while(iss >> word){ // to extract word from the line
                if(word == searchEmail){ //check if extracted word matches our search
                    temp = line; //store the line in which email found
                    break;
                }
            }
              
        }
    


    istringstream stream(temp);//extract the words from a string
    string word;
    while(stream >> word){
        if(count == 1){
            usr = word;
        }

        else if(count == 2){
            pass = word;
        }

        count++;
    }
   cout << "Your username is :: "<<usr<<endl;
   cout << "your password is(If you ever forget it again you are dead) :: "<<pass;


}