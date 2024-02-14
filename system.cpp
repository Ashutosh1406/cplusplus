#include<iostream>
#include<fstream>  //file handling
#include<sstream>  //templates
#include<string>

using namespace std;

int main()
{
    int a,i=0;

    string text,old,password1,password2,pass,name,password0,age,user,word,word1;
    string creds[2];
    string cp[2];

    cout<<"\t Security System    "<<endl;

    cout<<"______________________"<<endl<<endl;
    cout<<"|| 1. Register         ||"<<endl;
    cout<<"|| 2. Login            ||"<<endl;
    cout<<"|| 3. Change_Password  ||"<<endl;
    cout<<"||_4. END_PROGRAM______||"<<endl;

    do{
        cout<<endl<<endl;
        cout<<"enter your choice:- ";
        cin>>a;
        switch(a)
        {
            case 1:{
                        cout<<"____________________"<<endl<<endl;
                        cout<<"------REGISTER------"<<endl;
                        cout<<"____________________"<<endl<<endl;
                        cout<<"ENTER NEW USERNAME:-"<<"\t";
                        cin>>name;
                        cout<<"ENTER THE Password:-"<<"\t";
                        cin>>password0;
                        cout<<"enter you age :-    "<<"\t";
                        cin>>age;

                        ofstream of1;
                        of1.open("file.txt");
                        if( of1.is_open())
                        {
                            of1<<name<<"\n";
                            of1<<password0;
                            cout<<"REGISTRATION SUCCESS!!"<<endl;

                        }
                        break;

                   }
            case 2: {
                        i=0;
                        cout<<"____________________"<<endl<<endl;
                        cout<<"------LOGIN------"<<endl;
                        cout<<"____________________"<<endl<<endl;

                        ifstream of2;

                        of2.open("file.txt");
                        cout<<"ENTER YOUR USERNAME:-"<<endl;
                        cin>>user;
                        cout<<"ENTER YOUR PASSWORD:-"<<endl;
                        cin>>pass;

                        if( of2.is_open())
                        {
                            while(!of2.eof() )
                            {
                                while(getline(of2,text))
                                {
                                    istringstream iss(text);
                                    iss>>word;
                                    creds[i]=word;
                                    i++;
                                }
                                if(user==creds[0] && pass==creds[1])
                                {
                                    cout<<"Login Successfull--";
                                    cout<<endl<<endl;

                                    cout<<"DETAILS\t"<<endl;

                                    cout<<"Username"+name<<endl;  //reading from array
                                    cout<<"Password"+pass<<endl;
                                    cout<<"Age     "+age<<endl;
                                }
                                else
                                {
                                    cout<<endl<<endl;
                                    cout<<"INVALID CREDS"<<endl;
                                    cout<<"|| PRESS 2 TO LOGIN           ||"<<endl;
                                    cout<<"|| PRESS 3 TO Change Password ||"<<endl;
                                    break;
                                }
                            }

                        }

                        break;
                    }
            case 3 : {
                            i=0;
                            cout<<"------------Change Password------------"<<endl;

                            ifstream of0;
                            of0.open("file.txt");
                            cout<<"ENTER the Old password";
                            cin>>old;
                            if(of0.is_open())
                            {
                                while(of0.eof())
                                {
                                    while(getline(of0,text))
                                    {
                                        istringstream iss(text);
                                        iss>>word1;
                                        cp[i]=word1;
                                        i++;
                                    }
                                    if(old==cp[1])
                                    {
                                        of0.close();
                                        ofstream of1;
                                        if(of1.is_open())
                                        {
                                            cout<<"ENTER NEW PASSWORD:- ";
                                            cin>>password1;
                                            cout<<"ENTER PASSWORD AGAIN:-";
                                            cin>>password2;
                                            if(password1==password2)
                                            {
                                                of1<<cp[0]<<"\n"; //username and then new line password
                                                of1<<password1;
                                                cout<<"PASSWORD CHANGED SUCCESSFULLY"<<endl;
                                            }
                                            else
                                            {
                                                of1<<cp[0]<<"\n";
                                                of1<<old;
                                                cout<<"PASSWORD NOT MATCHING";
                                            }
                                        }
                                    }
                                    else{
                                        cout<<"Please Enter a valid password \t"<<endl;
                                        break;
                                    }

                                }

                            }



                        break;
                     }

             case 4 : {

                            cout<<"THANK YOU WE ARE UPGRADING OUR SYSTEM FOR BETTER FUNCTIONALITIES\n";

                            break;

                      }
             default:
                cout<<"ENTER A VALID CHOICE\t";

        }
    }
    while(a!=4);
    return 0;
}
