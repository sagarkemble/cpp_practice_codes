#include <iostream>
#include<list>
#include<limits>
#include<iomanip>
#include<iterator>
#include"classheader.h"

using namespace std;
int deletedata(list<info>&lst){
    int input;
    cout<<"enter the serial number of student"<<endl;
    cin>>input;
    clearBuffer();
    cls();
    
    if (cin.fail()) {
        // Clear error flag
        cin.clear();
        clearBuffer();

        return 2;
    }

    else if (lst.empty())
    {
        cin.clear();
        return 3;
    }

     else if (input > lst.size()) { 
        // clearBuffer();
        return 1;  
    }

    list<info>::iterator itr;
    itr=lst.begin();
    for (int i = 0; i <input-1&&itr!=lst.end(); i++)
    {
        itr++;
    }
     cout<<"|"<<setw(25)<<left<<"name"<<"|"<<setw(8)<<left<<"rollno"<<"|"<<setw(8)<<left<<"branch"<<"|"<<endl;
    itr->display();
    cout<<"is this the desired data u want to edit?"<<endl;
    cout<<"press 1 to delete data"<<endl;
    cout<<"press 2 to exit"<<endl;
    input=0;
    cin>>input;
    clearBuffer();
    cls();
    if (cin.fail()) {
        // Clear error flag
        cin.clear();
        clearBuffer();

        return 2;
    }
    
    else if (input==1)
    {
         lst.erase(itr);
    }
    else if(input==2){return 0;}
    else{
        return 2;
    }
    cout<<"data has been deleted"<<endl<<"press enter"<<endl;
    getchar();
    cls();
    
    return 0; 
    


    }
    bool compareByRollNumber(info &a, info &b) {
    return a.getrollno() < b.getrollno();
    }
int sortdata(list<info>&lst){
    int input;
    cout<<"note the data will be sorted according to roll number"<<endl;
    cout<<"press 1 to sort data in ascending order"<<endl;
    cout<<"press 2 to sort data in  descending order"<<endl;
    cout<<"press 3 to exit"<<endl;

    cin>>input;
    clearBuffer();
    cls();
if (cin.fail()) {
        // Clear error flag
        cin.clear();
        clearBuffer();

        return 2;
    }
else if (lst.empty())
    {
        cin.clear();
        return 3;
    }
    
    if (input == 1) {
        lst.sort(compareByRollNumber); 
        cout<<"the data has been sorted in ascending order"<<endl<<"press enter to continue";
        getchar();

        cls();
    }
    else if (input == 2) {
        lst.sort(compareByRollNumber); 
        lst.reverse(); 
        cout<<"the data has been sorted in descending order"<<endl<<"press enter to continue";
        getchar();

        cls();
    }
    
    else if(input==3){return 0;}
    else{
        return 2;
    }

}
void display(list<info>&lst){
        int i=0;
        cout<<"|"<<"sr"<<"|"<<"|"<<setw(25)<<left<<"name"<<"|"<<setw(8)<<left<<"rollno"<<"|"<<setw(8)<<left<<"branch"<<"|"<<endl;
        list<info>::iterator itr;
        for (itr=lst.begin(); itr!=lst.end(); itr++,i++)
        {
            cout<<"|"<<setw(2)<<right<<i+1<<"|";
            itr->display();
        }
        cout<<"press enter to continue";
        getchar();
        cls();
        return;
}
int edit2(list<info>&lst){
    int input;
    cout<<"enter the serial number of student"<<endl;
    cin>>input;
    clearBuffer();
    cls();
    if (cin.fail()) {
        // Clear error flag
        cin.clear();
        clearBuffer();

        return 2;
    }
    else if (lst.empty())
    {
        cin.clear();
        return 3;
    }
     else if (input > lst.size()) { 
        // clearBuffer();
        return 1;  
    }
    list<info>::iterator itr;
    itr=lst.begin();
    for (int i = 0; i <input-1&&itr!=lst.end(); i++)
    {
        itr++;
    }
     cout<<"|"<<setw(25)<<left<<"name"<<"|"<<setw(8)<<left<<"rollno"<<"|"<<setw(8)<<left<<"branch"<<"|"<<endl;
    itr->display();
    cout<<"is this the desired data u want to edit?"<<endl;
    cout<<"press 1 to edit"<<endl;
    cout<<"press 2 to exit"<<endl;
    input=0;
    cin>>input;
    clearBuffer();
    cls();
     if (cin.fail()) {
    // Clear error flag
     cin.clear();
    clearBuffer();

    return 2;
    }
    if (input==1)
    {
        cout<<'|'<<setw(25)<<left<<"name"<<"|"<<setw(8)<<left<<"rollno"<<"|"<<setw(8)<<left<<"branch"<<"|"<<endl;
        itr->display();
        return itr->changedata(lst);
    }
    else if (input==2)
    {
        return 0;
    }
    
    else{return 2;}
    
    //getchar();
    return 0;

}
int edit(list<info>&lst){
    
    int input;
    
    cout<<"press 1 to edit student data note:remeber the student sr no u want change"<<endl;
    cout<<"press 2 to delete the student data"<<endl;
    cout<<"press 3 to check sr no of student"<<endl;
    cout<<"press 4 to exit"<<endl;

    cin>>input;
    cls();
    if (cin.fail()||input>4) {
        // Clear error flag
        cin.clear();
        clearBuffer();

        return 2;
    }
    clearBuffer();
    
    
    if (input==1)
    {
        return edit2(lst);
    }
    else if (input==2)
    {
         return deletedata(lst);
        
    }
    
    else if (input==3)
    {
        display(lst);
        
        
        
    }
    return 0;
    

    


}

int main (){
    cls();
    list<info> lst;
    
    while(1){
    try{
        int input=0;
        cout<<"press following to add or edit the student data "<<endl;
        cout<<"1 for adding info"<<endl;
        cout<<"2 for displaying all data stored"<<endl;
        cout<<"3 for editing the data"<<endl;
        cout<<"4 to sort the data"<<endl;
        cout<<"5 for exit"<<endl;
        cin>>input;
        cls();
        clearBuffer();
        if (cin.fail()||input>5) {
        // Clear error flag
        cin.clear();
        loading("Wrong data entered",3,1,'.');
        return 0;
        

    }
        
        else if (input==1){
            info obj;
            int returnv=obj.addinfo();
            if(returnv==2){throw ("Wrong data enterd :(");}
            list<info>::iterator itr;
            bool rollnumberflag=true;
            for (itr=lst.begin(); itr!=lst.end(); itr++)
            {
                int rollno=itr->getrollno();
                int rollno2=obj.getrollno();
                if (rollno==rollno2)
                {
                    rollnumberflag=false;
                }
                
            }
            if (rollnumberflag==true)
            {
            lst.push_back(obj);
            cout<<"data added"<<endl<<"press enter to continue";
            getchar();
            cls();
            
            }
            else{
                throw("roll number exist try other roll number");
            }
            
            

        }
        else if (input==2)
        {
            display(lst);
        }
        
        else if (input==3)
        {
            int returnv =edit(lst);
            if (returnv==1){throw out_of_range("the data doest exist by the serial number you entered");}
            else if(returnv==2){throw ("Wrong data enterd :(");}
            else if(returnv==3){throw ("List empty no data present");}
            else if(returnv==4){throw ("Roll number exists try different roll no");}


        }
        
        else if (input==4)
        {
            int returnv=sortdata(lst);
            if(returnv==2){throw ("Wrong data enterd :(");}
            else if(returnv==3){throw ("List empty no data present");}

        }
        
        
        else{break;}
    }
    catch(out_of_range e){
        // cout<<e.what()<<endl;
        // clearBuffer();
        loading(e.what(),3,1,'.');
        cls();
        
        
    }
    catch (const char*wrongchoice){
        
        loading(wrongchoice,3,1,'.');
        cls();

    }
    }


    return 0;

}