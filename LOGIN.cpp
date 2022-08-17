#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
using namespace std;

//DECLARING VARIABLES
int choice1;
string name;
string gmail;
string password;
string filename;
FILE *file;
int sno=1;
string word;
string wording;
string username;
string pass;
int offset;
int flag=1;
char choice2;
string usernametodelete;
string passwordtodelete;
string gmailtodelete;
string line;


//DECLARING PROTOTYPES
void home();
void option();
void redirect(int);
void LOGIN();
void SIGNUP();
void DISPLAY();
void DELOTE();
void QUIT();


//MAIN FUNCTION
int main(int argc, char const *argv[])
{
    system("CLS");
    cout<<"\t\t\t\t"<<"WELCOME TO J.S. WORLD....";
    home();
    return 0;
}


//HOME FUNCTION FOR DISPLAYING THE PURPOSE OF PROJECT....
void home()
{
    cout<<"\n\n\n\tThis is one of the simplest projects to start with to learn about file systems in C++.";
    cout<<"\n\n\n\tThe project involves a user registration process by asking username and password.";
    cout<<"\n\n\n\tUpon successful registration, a user file is created with the credentials.\n\n\n\tIf the user does not exist, upon login, an error will be shown.";
    cout<<"\n\n\n\tYou will also learn how to use Visual Studio to create a simple project.";
    cout<<"\n\n\n";
    system("PAUSE");
    option();
}


//OPTION FUNCTION FOR USER TO SELECT FROM MULTIPLE OPTION.....
void option()
{
    system("CLS");
    cout<<"\t\tSELECT THE APPROPRIATE CHOICE:\n\n";
    cout<<"\tPRESS '1' FOR LOG-IN\n\n";
    cout<<"\tPRESS '2' FOR SIGN-UP\n\n";
    cout<<"\tPRESS '3' FOR DISPLAYING ALL THE USERS.\n\n";
    cout<<"\tPRESS '4' FOR DELETING ACCOUNT\n\n";
    cout<<"\tPRESS '0' FOR QUITING THE PROGRAM\n\n\n";
    cout<<"ENTER YOUR CHOICE: ";
    cin>>choice1;
    redirect(choice1);
}


//REDIRECTION FUNCTION WILL HELP TO USER TO JUMP FROM ONE FUNCTION TO ANOTHER....
void redirect(int choice1)
{
    system("CLS");
    cout<<"YOU HAVE TO ";
    if(choice1==1)
    {
        cout<<"LOGIN THE ACCOUNT";
        cout<<endl;
        cout<<endl;
        system("pause");
        LOGIN();
    }
    else if(choice1==2)
    {
        cout<<"SIGNUP THE ACCOUNT";
        cout<<endl;
        cout<<endl;
        system("pause");
        SIGNUP();
    }
    else if(choice1==3)
    {
        cout<<"DISPLAY THE ACCOUNTS";
        cout<<endl;
        cout<<endl;
        system("pause");
        DISPLAY();
    }
    else if(choice1==4)
    {
        cout<<"DELETE THE ACCOUNTS";
        cout<<endl;
        cout<<endl;
        system("pause");
        DELOTE();
    }
    else if (choice1==0)
    {
        cout<<"TERMINATE THE PROGRAM";
        cout<<endl;
        cout<<endl;
        system("pause");
        QUIT();
    }
    else
    {
        cout<<"\t\tPLEASE ENTER THE CORRECT OPTION....!";
        option();
    }
}

void LOGIN()
{
    system("CLS");
    ifstream fout;
    fout.open("JSSIGNUPDATA.txt");
    cout<<"ENTER THE CORRECT DETAILS\n\n";
    cout<<"ENTER THE USERNAME: ";
    cin>>username;
    cout<<"ENTER THE PASSWORD: ";
    cin>>pass;
    if(fout.is_open())
    {
    while(!fout.eof())
    {
        getline(fout,wording);
        if((offset=wording.find(username,0))!=string::npos)
        {
            cout<<"YOU HAVE LOGED IN SUCCESSFULLY...!";
            flag=0;
        }
    }
    fout.close();
    }
    else
    {
        cout<<"OOPS! SOMETHING WENT WRONG...!\n\n";
    }
    cout<<endl;
    cout<<endl;
    if(flag==0)
    {
        cout<<"THANKS FOR VISITING TO OUR WORLD...!\n\n\n";
        exit(0);
    }
    else
    {
        cout<<"INVALID USERNAME...!\n\n";
        cout<<"PLEASE CHECK YOU HAVE SIGNBED UP YETR OR NOT...!";
    }
}

void SIGNUP()
{
    system("CLS");
    filename="JSSIGNUPDATA.txt";
    ofstream fout;

    if (file = fopen(filename.c_str(),"r")) 
    {
        fout.open(filename.c_str(),ios::app);
        cout<<"\n\n\t\t\tSIGN-UP FORM\n\n\n";
        cout<<"\t\tPLEASE ENTER THE CORRECT DETAILS::\n\n";
        cout<<"\t\t\t USERNAME[MUST BE 13 LETTERS]: ";
        cin>>name;
        fout<<name<<"\t\t\t";
        cout<<"\t\t\t GMAIL-ID: ";
        cin>>gmail;
        fout<<gmail<<"\t\t         ";
        cout<<"\t\t\t PASSWORD: ";
        cin>>password;
        fout<<password<<"\n";
        fout.close();
    }
    else
    {
        fout.open(filename.c_str(),ios::out);
        fout<<"NAME\t\t\t        GMAIL\t\t\t                     PASSWORD\n\n";
        cout<<"\n\n\t\t\tSIGN-UP FORM\n\n\n";
        cout<<"\t\tPLEASE ENTER THE CORRECT DETAILS::\n\n";
        cout<<"\t\t\t USERNAME[MUST BE 13 LETTERS]: ";
        cin>>name;
        fout<<name<<"\t\t\t";
        cout<<"\t\t\t GMAIL-ID: ";
        cin>>gmail;
        fout<<gmail<<"\t\t         ";
        cout<<"\t\t\t PASSWORD: ";
        cin>>password;
        fout<<password<<"\n";
        fout.close();
    }
    
}

void DISPLAY()
{
    filename="JSSIGNUPDATA.txt";
    system("CLS");
    fstream fout;
    fout.open(filename.c_str());
    while(getline(fout,word))
    {
        cout << word<<endl;
    }
    fout.close();
    option();  
}

void DELOTE()
{
    system("CLS");
    cout<<"ARE YOU SURE YOU WANNA DELETE YOU ACCOUNT FORM J.S. WORLD[Y/N]: ";
    cin>>choice2;
    if(choice2=='y' || choice2=='Y')
    {
        cout<<"ENTER YOUR USERNAME: ";
        cin>>usernametodelete;
        cout<<"ENTER YOUR GMAIL: ";
        cin>>gmailtodelete;
        cout<<"ENTER YOUR PASSWORD: ";
        cin>>passwordtodelete;

        ifstream in("JSSIGNUPDATA.txt");
        if (!in.is_open()) 
        {
            cout << "Input file failed to open\n";
        }
        ofstream out("outfile.txt");
        while (getline(in, usernametodelete)) 
        {
            if (line != usernametodelete)
            {
               out << line << endl;
            }   
        }
        in.close();
        out.close();
        remove("JSSIGNUPDATA.txt");
        rename("outfile.txt", "JSSIGNUPDATA.txt");
        cout << "\nChanges has Successfully been made...... Data Saved\n" << endl;
        option();
    }
    else if(choice2=='N' || choice2=='n')
    {
        option();
    }
    else
    {
        cout<<"\nPLEASE ENTER THE CORRECT OPTION\n\n";
        DELOTE();
    }
}

void QUIT()
{
    system("CLS");
    cout<<"\t\tTHANKS FOR BEING HERE..!\n\n";
    exit(0);
}