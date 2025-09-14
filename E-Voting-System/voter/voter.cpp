#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

class Voter{
            private:
            string name;
            string class_name;
            int roll_no;
            string sem;
            int age;
            string gender;
            string voterID;

            bool isVoterIDUnique(const string &id)
            {
                ifstream fin("registered_Voter.txt");
                string line;
                while(getline(fin,line))
                {
                    if(line.find("VoterID: "+id)!= string::npos)
                    {
                        return false;
                    }
                }
                fin.close();
                return true;
            }

            public:
            bool getdata()
            {
                cin.ignore();//to ignore input buffers
                cout<<"Enter Your name: "<<endl;
                getline(cin,name);

                cout<<"Enter your Class: "<<endl;
                getline(cin,class_name);

                cout<<"Enter your Roll no.: "<<endl;
                cin>>roll_no;
                cin.ignore();

                cout<<"Enter your semester: "<<endl;
                getline(cin,sem);

                
                cout<<"Enter your age: "<<endl;
                cin>>age;
                   if(age<18)
                   {
                    cout<<"You are not eligible to register!!"<<endl;
                    return false;
                   }
                   cin.ignore();

                   cout<<"Enter your gender(M,F,O): "<<endl;
                   getline(cin,gender);

                   cout<<"Enter your voterID: "<<endl;
                   getline(cin,voterID);
                   
                   if(!isVoterIDUnique(voterID))
                   {
                    cout<<"This voter id already exists! Please use a unique ID."<<endl;
                    return false;
                   }
                   return true;
                   
            }

            void savedata()
            {
                ofstream fout;
                fout.open("registered_Voter.txt",ios::app);
                if(!fout)
                {
                    cout<<"Error in opening file!!";
                }
                else
                {
                    fout<<"Name: "<<name<<endl;
                    fout<<"Class: "<<class_name<<endl;
                    fout<<"Roll No.: "<<roll_no<<endl;
                    fout<<"Semester: "<<sem<<endl;
                    fout<<"Age: "<<age<<endl;
                    fout<<"Gender: "<<gender<<endl;
                    fout<<"voterID: "<<voterID<<endl;
                    fout<<"---------------------------"<<endl;
                    fout.close();

                    cout<<"Voter Registered Successfully!!!"<<endl;
                }
            }

            void viewData()
            {
                string password, line;
                const string correct_password="Deepak1207";
                cin.ignore();
                
                cout<<"Enter password to view voter's detail...:"<<endl;
                getline(cin,password);
               
                if(password!=correct_password)
                {
                    cout<<"Wrong password!!. Please try again!!!!"<<endl;
                }
                else
                {
                    ifstream fin;
                    fin.open("registered_Voter.txt");
                    
                    if(!fin)
                    {
                        cout<<"No data found or error in opening file!!!!";
                        return;
                    }
                    else
                    {
                        cout<<"========== Registered Voters =========="<<endl;
                        while(getline(fin,line))
                        {
                            cout<<line<<endl;
                        }
                        fin.close();
                    }
                }
            }
};

int main()
{
    int choice;
    do {
         cout<<"========== Registration System: =========="<<endl;
         cout<<"Enter your choice: "<<endl;
         cout<<"1. To register."<<endl;
         cout<<"2. To view voter list.(Password protected!) "<<endl;
         cout<<"3.Exit. "<<endl;
         cout<<"-------------------"<<endl;
         cout<<"Enter Your choice: "<<endl;
        
         cin>>choice;

         switch(choice)
         {
            case 1:
            {
            Voter v;
           if( v.getdata()){
            v.savedata();}
            break;
           }
           case 2:{
            Voter v;
           v.viewData();
           break;
           }
         case 3:
         cout<<"Exiting page!!";
         exit(0);

         default:
         cout<<"Invalid choice!!"<<endl;
    }
   }
                
   while(choice!=3);
   return 0;
}


