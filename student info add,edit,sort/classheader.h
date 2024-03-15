    #ifndef classheader
    #define classheader
    #include <iostream>
    #include<list>
    #include<limits>
    #include<iomanip>
    #include<iterator>
    #include<windows.h>
    #include<unistd.h>
    using namespace std;
    void loading(string str,int iteration,int time,char symbol){
    cout<<str;
    for (int i = 0; i < iteration; i++)
    {
        cout<<symbol;
        sleep(time);
    }
    
    return;
}
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
        string branch="empty";
        public:
        int addinfo(){
            cout<<"Enter name of student"<<endl;
            getline(cin,name);
            cls();
            
            cout<<"select the branch"<<endl;
            cout<<"1 for conuter science"<<endl;
            cout<<"2 for mechanical"<<endl;
            cout<<"3 for electrical"<<endl;
            int t;
            cin>>t;
            clearBuffer();
            cls();
            if (cin.fail()) {
            // Clear error flag
            cin.clear();
            clearBuffer();

            return 2;
             }
            else if (t==1)branch="cs";
            else if(t==2)branch="me";
            else if(t==3)branch="elec";
            else{
            return 2;
            }
            cout<<"Enter roll number of student"<<endl;
            cin>>rollno;
            clearBuffer();
            if (cin.fail()) {
            // Clear error flag
            cin.clear();
            clearBuffer();

            return 2;
             }

            cls();
        }
        int getrollno(){
            return rollno;
        }
        void display()  
        {
            cout<<"|"<<setw(25)<<left<<name<<"|"<<setw(8)<<left<<rollno<<"|"<<setw(8)<<left<<branch<<"|"<<endl;
            return;
        }
        int editname(){cout<<"Enter name of student"<<endl;
            getline(cin,name);
            cls();

            cout<<"data has been changed"<<endl<<"press enter to continue"<<endl;
            getchar();
            cls();

            return 0;}
        int editrollno(list<info>&obj){
            int r;
            cout<<"Enter roll number of student"<<endl;
            cin>>r;
            clearBuffer();
            cls();
            if (cin.fail()) {
            // Clear error flag
            cin.clear();
            clearBuffer();

            return 2;
             }
             list<info>::iterator itr;
            bool rollnumberflag=true;
            for (itr=obj.begin(); itr!=obj.end(); itr++)
            {
                int trollno=itr->getrollno();
                if (trollno==r)
                {
                    rollnumberflag=false;
                }
                
                
            }
                if (rollnumberflag==true)
                {
                    rollno=r;
                cout<<"data changed"<<endl<<"press enter to continue";
                getchar();
                cls();

                }
                else{return 4;}
             cout<<"data has been changed"<<endl<<"press enter to continue"<<endl;
             getchar();
             cls();
             return 0;
            }
        int eidtbranch(){
            cout<<"select the branch"<<endl;
            cout<<"1 for conuter science"<<endl;
            cout<<"2 for mechanical"<<endl;
            cout<<"3 for electrical"<<endl;
            int t;
            cin>>t;
            clearBuffer();
            cls();
            if (cin.fail()) {
            // Clear error flag
            cin.clear();
            clearBuffer();

            return 2;
             }
            else if (t==1)branch="cs";
            else if(t==2)branch="me";
            else if(t==3)branch="elec";
            else{
            return 2;
            }
            cout<<"data has been changed"<<endl<<"press enter to continue"<<endl;
            getchar();
            cls();
            return 0;
        }
        int changedata(list<info>&obj){
            int input;
            cout<<"press 1 to edit name"<<endl;
            cout<<"press 2 to edit roll no"<<endl;
            cout<<"press 3 to edit branch"<<endl;
            cout<<"press 4 to exit"<<endl;
            cin>>input;
            cls();
            clearBuffer();
            if (cin.fail()||input>4) {
            // Clear error flag
            cin.clear();
            clearBuffer();
            

            return 2;
            }
            if (input==1){return editname(); }
            else if (input==2){return editrollno(obj);}
            else if (input==3){return eidtbranch();}
            else if (input==4){return 0;}
            
            
            cout<<"data has been editied"<<endl<<"press enter"<<endl;

            getchar();
            cls();
            return 0;        
        }
        };  
        #endif 