#include <iostream>
#include<windows.h>
#include<conio.h>
#define pass 1212
using namespace std;
void home();
void display();
void display2();
bool acess();
struct car
{
    int car_id,label;
    string model;
    bool status;
};
struct person
{
    string name;
    int phone,id_no;
    car id;
};


int main()
{

        home();




    getch();
    return 0;
}
void home()
{
    system("color 5f"); //5f,f5,50;
    int a=0,count=14,x;
    for(int i=4; i>0; i--)
    {
        int n=0;
        count=count+1;
        cout<<"\t\t\t\t";
        for(int j=i+3; j>=0; j--)
    {
            cout<<" ";
        }
        while(n<count)
        {
            cout<<"#"<<" ";
            Sleep(10);
            n++;
        }
        cout<<endl;
    }
    while(3>a)
    {
        cout<<"\t\t\t\t";
        for(int n=0; n<25; n++)
        {
            Sleep(7);
            cout<<"$"<<" ";
        }
        cout<<endl;
        a++;
    }
    cout<<"\t\t\t\t\t 00\t\t\t 00\n";
    cout<<"\t\t\t\t\t0000\t\t\t0000\n";
    cout<<"\t\t\t\t\t 00\t\t\t 00\n";
    cout<<"\n\n\t\t\t\t ||CAR RENTAL MANGEMENT SYSTEM(CRMS)||"<<endl;
    cout<<"\n\t\t\t\t\tAdmin press 1\n\t\t\t\t\tCustomer press 2"<<endl;


    cin>>x;
    system("cls");
    switch(x)
    {
    case 1:
    {
        if(acess()==true)

            display();

        }
}
}
bool acess(){
    short password,count=0;
    cout<<"\t\t\t\tENTER PASSWORD\n\t\t\t---->";
    while(count!=4){
    cin>>password;
    if(pass==password){
        system("cls");
         return true;}
    else count++;
    if(count<=3){
    cout<<"\t\t\t\tINCORRECT PASSWORD TRY AGAIN\n\t\t\t---->";}
    }
    if(count>3){
         cout<<"\t\t\t\tTO MANY TRY CHAW\n\t\t\t";
         Sleep(150);
         system("cls");
        home();}
     return false;
    }
void display(){
    cout<<"select service do you want"<<endl;
    cout<<"\n\t\t* press 1  Add a New Car                                :   **";
    cout<<"\n\t\t* press 2  Delete Car                                   :   **";
    cout<<"\n\t\t* press 3  Add a New Customer                           :   **";
    cout<<"\n\t\t* press 3  Delete  Customer                             :   **";
    cout<<"\n\t\t* press 4  Display Car Information in the List          :   **";
    cout<<"\n\t\t* press 5  Count the number of nodes in the List        :   **";
    cout<<"\n\t\t* press 9  SORT LIST                                    :   **";
    cout<<"\n\t\t* press 10 About                                        :   **";
    cout<<"\n\t\t* press 11 to back to main menu of  the program         :   **"<<endl;
    }
