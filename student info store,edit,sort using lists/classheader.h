    #ifndef classheader
    #define classheader
    #include <iostream>
    #include<list>
    #include<limits>
    #include<iomanip>
    #include<iterator>
    using namespace std;
    void cls(){ 
        
        system("cls");
    }
    void clearBuffer() {

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    class info{
        private:
        string name;
        int rollno;
        string branch;
        public:
        info(){
            cout<<"Enter name of student"<<endl;
            getline(cin,name);
            cls();
            cout<<"Enter roll number of student"<<endl;
            cin>>rollno;
            clearBuffer();
            cls();
            cout<<"select the branch"<<endl;
            cout<<"1 for conuter science"<<endl;
            cout<<"2 for mechanical"<<endl;
            cout<<"3 for electrical"<<endl;
            int t;
            cin>>t;
            clearBuffer();
            cls();
            if (t==1)branch="cs";
            else if(t==2)branch="me";
            else if(t==3)branch="elec";
        }
        int getrollno(){
            return rollno;
        }
        void display()  
        {
            cout<<"|"<<setw(25)<<left<<name<<"|"<<setw(8)<<left<<rollno<<"|"<<setw(8)<<left<<branch<<"|"<<endl;
            return;
        }
        void editname(){cout<<"Enter name of student"<<endl;
            getline(cin,name);
            cls();
            return;}
        void editrollno(){
            cout<<"Enter roll number of student"<<endl;
            cin>>rollno;
            clearBuffer();
            cls();
            }
        void eidtbranch(){
            cout<<"select the branch"<<endl;
            cout<<"1 for conuter science"<<endl;
            cout<<"2 for mechanical"<<endl;
            cout<<"3 for electrical"<<endl;
            int t;
            cin>>t;
            clearBuffer();
            cls();
            if (t==1)branch="cs";
            else if(t==2)branch="me";
            else if(t==3)branch="elec";
        }
        void changedata(){
            int input;
            cout<<"press 1 to edit name"<<endl;
            cout<<"press 2 to edit roll no"<<endl;
            cout<<"press 3 to edit branch"<<endl;
            cin>>input;
            cls();
            clearBuffer();
            if (input==1){editname(); }
            else if (input==2){editrollno();}
            else if (input==3){eidtbranch();}
            else{cout<<"wrong data entered press enter"<<endl;
            getchar();
            return;
            }
            cout<<"data has been editied"<<endl<<"press enter"<<endl;

            getchar();
            cls();
            return;        
        }
        };  
        #endif 