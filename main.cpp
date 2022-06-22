#include <iostream>
#include<windows.h>
#include<fstream>
#define pass 0000
using namespace std;
//creating and defining new structure
struct Car
{
    int car_id;
    string model;
    bool status;
    int year,label;;
    int price;
    string per_name;
    int phone_no;
    Car *next;
};
Car *head=NULL;
// Function Declaration
int inputInt();
char inputChar();
void file();
void file2();
void home();
bool acess();
void menu();
void About ();
void car_statues();
void display_car();
void display_all();
void display_Scar(bool y);//status car
void delete_car();
void deleteAtBeginning();
void deleteAtMiddle();
void deleteAtEnd();
void add_car();
void addAtBeginning();
void addAtMiddle();
void addAtEnd();
void sort_car();
void sort_by(int i);
void search_car();


int main()
{
    home();
    return 0;
}
// home function////////////////////
void home()
{
    system("cls");
    system("color 5f");
    int a=0,count=14;
    char b;
// A line to Draw Car//////////////////////
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
            Sleep(6);
            n++;
        }
        cout<<endl;
    }
    while(3>a)
    {
        cout<<"\t\t\t\t";
        for(int n=0; n<25; n++)
        {
            Sleep(6);
            cout<<"$"<<" ";
        }
        cout<<endl;
        a++;
    }
    cout<<"\t\t\t\t\t 00\t\t\t 00\n";
    cout<<"\t\t\t\t\t0000\t\t\t0000\n";
    cout<<"\t\t\t\t\t 00\t\t\t 00\n";
    cout<<"\n\n\t\t\t\t ||CAR RENTAL MANGEMENT SYSTEM(CRMS)||"<<endl;
    cout<<"\n\t\t\t\t\tTo Continue 'Y' or 'y'"<<endl;
    cout<<"\t\t\t\t\tTo Exit Any Key"<<endl;
// part allows as to continue to menu page//////////////////////////////
    cin>>b;

    if(b=='y'||b=='Y')
    {
        if(acess()==true)

            menu();
    }
    else
        About();
}
//to validate input to be an integer only and promote to continue to our program without error
int inputInt()
{
    int n;
    bool valid=false;
    while(valid==false)
    {
        valid=true;
        cin>>n;
        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout<<"\t\t\t\n*Enter an integer only->";
            valid=false;
        }

    }
    return n;
}
//to validate input to be an integer only and promote to continue to our program without error
char inputChar()
{
    char n;
    bool valid=false;
    while(valid==false)
    {
        valid=true;
        cin>>n;
        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(CHAR_MAX,'\n');
            cout<<"\t\t\t\n*Enter a proper choice->";
            valid=false;
        }

    }
    return n;
}
//A function for password validation/////////////
bool acess()
{
    short password,count=0;
    cout<<"\t\t\t\tENTER PASSWORD\n\t\t\t---->";
    while(count!=4)
    {
        password=inputInt();
        if(pass==password)
        {
            system("cls");
            file();
            return true;
        }
        else
            count++;
        if(count<=3)
        {
            cout<<"\t\t\t\tINCORRECT PASSWORD,TRY AGAIN\n\t\t\t---->";
        }
    }
    if(count>3)
    {
        system("cls");
        cout<<"\t\t\t\tTO MANY TRY,CHAW\n\t\t\t";
        Sleep(15);
        About();
    }
    return false;
}
// menu function redirect us to different functions as our choice
void menu()
{

    system("cls");
    int c;
    cout<<"\n\n\t\t**************************************:   ¶"<<endl;
    cout<<"\t\t* press 1 To Add a New Car            :   ¶"<<endl;
    cout<<"\t\t* press 2 To Delete Car               :   ¶"<<endl;
    cout<<"\t\t* press 3 To Change Car Statues       :   ¶"<<endl;
    cout<<"\t\t* press 4 To Display Car Information  :   ¶"<<endl;
    cout<<"\t\t* press 5 To SORT Car                 :   ¶"<<endl;
    cout<<"\t\t* press 6 To Search A Car             :   ¶"<<endl;
    cout<<"\t\t* press Any Key to Credits and Exit   :   ¶"<<endl;
    cout<<"\t\t**************************************:   ¶"<<endl;
    cin>>c;
    switch(c)
    {
    case 1:
        add_car();
        break;
    case 2:
        delete_car();
        break;
    case 3:
        car_statues();
        break;
    case 4:
        display_car();
        break;
    case 5:
        sort_car();
        break;
    case 6:
        search_car();
        break;
    default :
        About();
    }

}
//menu for displaying car
void display_car()
{
    int choice;
    char x;
    system("cls");
    cout<<"\n\n\t\t**************************************************:   ¶"<<endl;
    cout<<"\t\t* press 1 to Display all Cars                     :   ¶"<<endl;
    cout<<"\t\t* press 2 to Display Rented Cars Only             :   ¶"<<endl;
    cout<<"\t\t* press 3 to Display Available Cars Only          :   ¶"<<endl;
    cout<<"\t\t* press 4 to back to main menu:                   :   ¶"<<endl;
    cout<<"\t\t**************************************************:   ¶"<<endl;
    choice=inputInt();
    switch(choice)
    {
    case 1:
        display_all();
        break;
    case 2:
        display_Scar(true);
        break;
    case 3:
        display_Scar(false);
        break;
    case 4:
        menu();
        break;
    default:
        home();
    }
    system("cls");
    cout<<"\n\t\t**Press B/b to back to main menu           :"<<endl;
    cout<<"\n\t\t**Press C/c to back to Display menu        :"<<endl;
    cout<<"\n\t\t**Press any key to exit                    :"<<endl;
    cin>>x;
    if(x=='B'||x=='b')
    {
        menu();
    }
    else if(x=='C'||x=='c')
    {
        display_car();
    }
    else
    {
        About();
    }
}
void display_all()
{
    char x;
    system("cls");
    Car*temp1;
    temp1=head;
    if(head==NULL)
    {
        cout<<"\n\t\t*     NO CAR FOUND!!         :"<<endl;
    }
    else
    {
        while(temp1!=NULL)
        {
            cout<<"\n\t\t________________________________";
            cout<<"\n\t\t* CAR ID : "<<temp1->car_id;
            cout<<"\n\t\t* CAR MODEL : "<<temp1->model;
            cout<<"\n\t\t* CAR YEAR  : "<<temp1->year;
            cout<<"\n\t\t* CAR STAR : "<<temp1->label;
            cout<<"\n\t\t* CAR PRICE : "<<temp1->price;
            if(temp1->status==true)
            {
                cout<<"\n\t\t* CAR STATUS : "<<"RENTED";
                cout<<"\n\t\t* RENTED BY : "<<temp1->per_name;
                cout<<"\n\t\t* PHONE NO : "<<temp1->phone_no;
            }
            else
            {
                cout<<"\n\t\t* CAR STATUS : "<<"NOT RENTED";
            }
            cout<<"\n\t\t________________________________";
            temp1=temp1->next;
        }

    }
    cout<<"\n\t\t**Press B/b to back to main menu           :"<<endl;
    cout<<"\n\t\t**Press C/c to back to Display menu        :"<<endl;
    cout<<"\n\t\t**Press any key to exit                    :"<<endl;

    cin>>x;
    if(x=='B'||x=='b')
    {
        menu();
    }
    else if(x=='C'||x=='c')
    {
        display_car();
    }

    else
    {
        About();
    }

}
//the parameter of the ff function if it is true it refers rented cars and if it is false is refer not rented cars
void display_Scar(bool y)
{
    char x;
    string name="Available";
    int count=0;
    system("cls");
    if(y==true)
    {
        name="rented";
    }
    Car*temp;
    temp=head;
    if(head==NULL)
    {
        cout<<"\n\t\t*     NO CAR FOUND!!         :"<<endl;
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->status==y)
            {
                cout<<"\n\t\t________________________________";
                cout<<"\n\t\t* CAR ID : "<<temp->car_id;
                cout<<"\n\t\t* CAR MODEL : "<<temp->model;
                cout<<"\n\t\t* CAR YEAR : "<<temp->year;
                cout<<"\n\t\t* CAR STAR :"<<temp->label;
                cout<<"\n\t\t* CAR PRICE : "<<temp->price<<" $ per week";
                cout<<"\n\t\t* CAR STATUS : "<<name;
                if(y==true)
                {
                    cout<<"\n\t\t* RENTED BY : "<<temp->per_name;
                    cout<<"\n\t\t* PHONE NO : "<<temp->phone_no;
                }
                count++;
            }


            temp=temp->next;
        }
        cout<<"\n\t\t________________________________\t";
        cout<<"\t\t***total "<<name<<"="<<count<<"***\t";
    }
    cout<<"\n\t\t* press B/b to back to main menu           :"<<endl;
    cout<<"\t\t* press any key to exit                    :"<<endl;
    cin>>x;
    if(x=='B'||x=='b')
    {
        menu();
    }

    else
    {
        About();
    }

}

// menu function for adding function
void add_car()
{
    int c;
    char x;
    system("cls");
    cout<<"\n\n\t\t***********************************************:   ¶"<<endl;
    cout<<"\t\t* press 1 to Add A New Car At the Beginning    :   ¶"<<endl;
    cout<<"\t\t* press 2 to Add A New Car At the Middle       :   ¶"<<endl;
    cout<<"\t\t* press 3 to Add A New Car At the End          :   ¶"<<endl;
    cout<<"\t\t* press 4 to back to main menu                 :   ¶"<<endl;
    cout<<"\t\t* press Any Key to Exit                        :   ¶"<<endl;
    cout<<"\t\t***********************************************:   ¶"<<endl;
    cin>>c;
    switch(c)
    {
    case 1:
        addAtBeginning();
        break;
    case 2:
        addAtMiddle();
        break;
    case 3:
        addAtEnd();
        break;
    case 4:
        menu();
        break;
    default:
        About();
    }

    cout<<"\n\t\t**Press B/b to back to main menu           :"<<endl;
    cout<<"\n\t\t**Press C/c to add another Car Information :"<<endl;
    cout<<"\n\t\t**Press any key to exit                    :"<<endl;
    cin>>x;
    if(x=='B'||x=='b')
    {
        menu();
    }
    else if(x=='C'||x=='c')
    {
        add_car();
    }
    else
    {
        About();
    }
}
void addAtBeginning()
{
    int count;
    Car *temp=new Car;
    temp->next=NULL;
    temp->status=false;
    temp->per_name="0";
    temp->phone_no=0;
    cout<<"\n\t\t* Enter Car Id                   :->  ";
    temp->car_id=inputInt();
    do
    {

        count=0;
        for(Car *i=head; i!=NULL; i=i->next)
        {
            if(temp->car_id==i->car_id)
            {
                count=1;
                cout<<"This id number is taken by another car,Try different id-> ";
                temp->car_id=inputInt();
            }
        }
    }
    while(count!=0);

    cout<<"\n\t\t* Enter Car Model                :->  ";
    cin>>temp->model;
    cout<<"\n\t\t* Enter Manufactured Year        :->  ";
    temp->year=inputInt();
    cout<<"\n\t\t* Enter car star from to 1 to 5  :->  ";
D:
    temp->label=inputInt();
    if(temp->label<=5&&temp->label>0) {}
    else
    {
        cout<<"\n\t\t***Car star must be from 1 to 5 only*** :->";
        goto D;
    }
    cout<<"\n\t\t* Enter car price                :->  ";
    temp->price=inputInt();

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;

    }
    system("cls");
    cout<<"\t\t\t***********NEW CAR SUCCESFULLY ADDED***********"<<endl;

}
void addAtMiddle()
{
    Car *temp=new Car;
    temp->next=NULL;
    int id,found=0,count;
    temp->status=false;
    temp->per_name="0";
    temp->phone_no=0;
    cout<<"\n\t\t* Enter Car Id                   :->  ";
    temp->car_id=inputInt();
    do
    {
        count=0;
        for(Car *i=head; i!=NULL; i=i->next)
        {
            if(temp->car_id==i->car_id)
            {
                count=1;
                cout<<"This id number is taken by another car try different id-> ";
                temp->car_id=inputInt();
            }
        }
    }
    while(count!=0);
    cout<<"\n\t\t* Enter Car Model                :->  ";
    cin>>temp->model;
    cout<<"\n\t\t* Enter Manufactured Year        :->  ";
    temp->year=inputInt();
    cout<<"\n\t\t* Enter car star from to 1 to 5  :->  ";
E:
    temp->label=inputInt();
    if(temp->label<=5&&temp->label>0) {}
    else
    {
        cout<<"\n\t\t***Car star must be from 1 to 5 only*** :->";
        goto E;
    }
    cout<<"\n\t\t* Enter car price                :->  ";
    temp->price=inputInt();
G:
    cout<<"\n\t******AFTER WHICH ID DO YOU WANT TO ADD***** :->";
    id=inputInt();
    if(head==NULL)
    {
        head=temp;
        found=2;

    }
    else
    {
        for(Car *temp1=head; temp1!=NULL; temp1=temp1->next)
        {
            if(temp1->car_id==id)
            {
                temp->next=temp1->next;
                temp1->next=temp;
                found=1;
                break;
            }
        }
    }
    system("cls");
    if(found==0)
    {
        cout<<"\n\t\t*****ID IS NOT FOUND,CORRECT YOUR ID**********";
        goto G;
    }
    else if(found==2)
    {
        cout<<"\n\t\t*****NO CAR FOUND,CAR ADDED AT THE BEGGINING**********";
    }
    else
    {
        cout<<"\t\t\t***********NEW CAR SUCCESFULLY ADDED*************"<<endl;
    }

}
void addAtEnd()
{
    int count;
    Car *temp=new Car;
    temp->next=NULL;
    temp->status=false;
    temp->per_name="0";
    temp->phone_no=0;
    cout<<"\n\t\t* Enter Car Id                   :->  ";
    temp->car_id=inputInt();
    do
    {
        count=0;
        for(Car *i=head; i!=NULL; i=i->next)
        {
            if(temp->car_id==i->car_id)
            {
                count=1;
                cout<<"This id number is taken by another car try different id-> ";
                temp->car_id=inputInt();
            }
        }
    }
    while(count!=0);
    cout<<"\n\t\t* Enter Car Model                :->  ";
    cin>>temp->model;
    cout<<"\n\t\t* Enter Manufactured Year        :->  ";
    temp->year=inputInt();
    cout<<"\n\t\t* Enter car star from to 1 to 5  :->  ";
D:
    temp->label=inputInt();
    if(temp->label<=5&&temp->label>0) {}
    else
    {
        cout<<"\n\t\t***Car star must be from 1 to 5 only*** :->";
        goto D;
    }
    cout<<"\n\t\t* Enter car price                :->  ";
    temp->price=inputInt();
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        Car *temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next = temp;

    }
    system("cls");
    cout<<"\t\t\t***********NEW CAR SUCCESFULLY ADDED*************"<<endl;

}
void delete_car()
{
    int c;
    char x;
    system("cls");
    if(head==NULL)
    {
        cout<<"Empty List!"<<endl;

    }
    else
    {
        cout<<"\n\n\t\t***********************************************:   **"<<endl;
        cout<<"\t\t* press 1 to Delete A New Car At the Beginning :   ¶"<<endl;
        cout<<"\t\t* press 2 to Delete A New Car At the Middle    :   ¶"<<endl;
        cout<<"\t\t* press 3 to Delete A New Car At the End       :   ¶"<<endl;
        cout<<"\t\t* press 4 to back to main menu                 :   ¶"<<endl;
        cout<<"\t\t* press Any Key to Exit                        :   ¶"<<endl;
        cout<<"\t\t***********************************************:   ¶"<<endl;
        cin>>c;
        switch(c)
        {
        case 1:
            deleteAtBeginning();
            break;
        case 2:
            deleteAtMiddle();
            break;
        case 3:
            deleteAtEnd();
            break;
        case 4:
            menu();
            break;
        default:
            About();
        }
    }

    cout<<"\n\t\t**Press B/b to back to main menu              :"<<endl;
    cout<<"\n\t\t**Press C/c to delete another Car Information :"<<endl;
    cout<<"\n\t\t**Press any key to exit                       :"<<endl;
    cin>>x;
    if(x=='B'||x=='b')
    {
        menu();
    }
    else if(x=='C'||x=='c')
    {
        delete_car();
    }
    else
    {
        About();
    }

}

void deleteAtBeginning()
{
    char x;
    Car *temp;

    cout<<" Are you sure to delete Car information? Press Y/N :-> ";
    x=inputChar();
    if(x=='Y'||x=='y')
    {
        temp=head;
        head=temp->next;
        delete temp;
        system("cls");
        cout<<"\t\t\t***********CAR SUCCESFULLY DELETED*************"<<endl;
    }
    else
    {
        cout<<" You canceled the operation"<<endl;
    }
    cout<<"done"<<endl;
}
void deleteAtMiddle()
{
    Car *temp=head,*temp1=head;
    int id;
    char x;
    cout<<"\n\t\t* Enter Car Id                   :->  "<<endl;
    id=inputInt();
    cout<<" Are you sure to delete Car information? Press Y/N :-> ";
    x=inputChar();
    if(x=='Y'||x=='y')
    {
        while(temp->car_id!=id && temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        if(temp->car_id!=id)
        {
            cout<<"***********THE ID IS NOT FOUND***********"<<endl;
        }
        else
        {
            if(temp==head)
            {
                head=head->next;
                delete temp;
            }
            else
            {
                temp1->next=temp->next;
                delete temp;
            }
            system("cls");
            cout<<"\t\t\t***********CAR SUCCESFULLY DELETED*************"<<endl;
        }
    }

}


void deleteAtEnd()
{
    char x;
    Car *temp1;
    temp1=head;

    cout<<" Are you sure to delete Car information? Press Y/N :-> ";
    x=inputChar();
    if(x=='Y'||x=='y')
    {
        if(temp1->next==NULL)
        {
            head=NULL;
            delete temp1;
        }
        else
        {
            Car *temp2;
            while(temp1->next!=NULL)
            {
                temp2=temp1;
                temp1=temp1->next;
            }
            temp2->next=NULL;
            delete temp1;

        }
        system("cls");
        cout<<"\t\t\t***********CAR SUCCESFULLY DELETED*************"<<endl;
    }
    else
    {
        cout<<" You canceled the operation"<<endl;
    }

}
//function to enable as to change the statues of car from rented to non rented and vice versa
void car_statues()
{
    system("cls");
    int id,a;
    char x;
    Car *temp;
C:
    temp=head;

    cout<<"\n\t\t* Enter a Car id to change the status      :->";
    id=inputInt();
    if(head==NULL)
    {
        cout<<"\n\t\t*     EMPTY LIST!!        :"<<endl;
        Sleep(500);
        menu();
    }

    while(temp->car_id!=id&&temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->car_id==id)
    {
        cout<<"\n\t\t\t\t******CAR FOUND*******"<<endl;
        cout<<"\n\t\t*  Press 1 to change the car statues to rented     :"<<endl;
        cout<<"\n\t\t*  Press 2 to change the car statues to not rented :"<<endl;
        cout<<"\n\t\t*  Press 3 to back to main menu                    :"<<endl;
B:
        a=inputInt();
        if(a==1)
        {
            cout<<"\n\t\t* Enter a Person name who rented it      :->";
            cin>>temp->per_name;
            cout<<"\n\t\t* Enter a Phone no of the Person         :->";
            cin>>temp->phone_no;
            temp->status=true;
        }
        else if(a==2)
        {
            temp->per_name="0";
            temp->phone_no=0;
            temp->status=false;
        }
        else if(a==3)
        {
            menu();
        }
        else
        {
            cout<<"\n\t\t**Wrong no**"<<endl;
            cout<<"\n\t\t**Enter again->";
            goto B;
        }
    }
    else
    {
        cout<<"\n\t\t****Car not Found ***";
        goto A;
    }
    system("cls");
    cout<<"\n *********Car status is changed successfully.**********\n";
A:
    cout<<"\n\t\t**Press B/b to back to main menu           :"<<endl;
    cout<<"\n\t\t**Press C/c to change another Car Status   :"<<endl;
    cout<<"\n\t\t**Press any key to exit                    :"<<endl;
    cin>>x;
    if(x=='B'||x=='b')
    {
        menu();
    }
    else if(x=='C'||x=='c')
    {
        car_statues();
    }
    else
    {
        About();
    }
}

void sort_car(){
int c;
char x;



    system("cls");
    cout<<"\n\n\t\t***********************************************:   **"<<endl;
    cout<<"\t\t* press 1 to Sort by id                        :   **"<<endl;
    cout<<"\t\t* press 2 to Sort by Price                     :   **"<<endl;
    cout<<"\t\t* press Any Key to Exit                        :   **"<<endl;
    cout<<"\t\t***********************************************:   **"<<endl;
    cin>>c;
    switch(c)
    {
    case 1:
        sort_by(1);
        break;
    case 2:
       sort_by(2);
        break;
      default:
        About();
    }

    cout<<"\n\t\t**Press B/b to back to main menu           :"<<endl;
    cout<<"\n\t\t**Press C/c to add another Car Information :"<<endl;
    cout<<"\n\t\t**Press any key to exit                    :"<<endl;
    cin>>x;
    if(x=='B'||x=='b')
    {
        menu();
    }
    else if(x=='C'||x=='c')
    {
        sort_car();
    }
    else
    {
        About();
    }
}
//the parameter of the ff function to be set 1 to sort according to id and 2 to sort according to price
void sort_by(int i)
{
    Car *temp;
    Car *temp1;
    int swap1;
    int swap2;

    if(head==NULL)
    {
        cout<<"\n\t\t*     NO CAR FOUND!!         :"<<endl;
    }
    else
    {
        for(temp=head; temp->next!=NULL; temp=temp->next)
        {
            for(temp1=temp->next; temp1!=NULL; temp1=temp1->next)
            {
                if(i==1)
                {
                    swap1=temp->car_id;
                    swap2=temp1->car_id;
                }
                else if(i==2)
                {
                    swap1=temp->price;
                    swap2=temp1->price;
                }
                if(swap1>swap2)
                {
                    Car *temp2 =new Car;
                    temp2->price=temp->price;
                    temp2->status=temp->status;
                    temp2->year=temp->year;
                    temp2->car_id=temp->car_id;
                    temp2->label=temp->label;
                    temp2->model=temp->model;
                    temp2->per_name=temp->per_name;
                    temp2->phone_no=temp->phone_no;

                    temp->price=temp1->price;
                    temp->status=temp1->status;
                    temp->year=temp1->year;
                    temp->car_id=temp1->car_id;
                    temp->label=temp1->label;
                    temp->model=temp1->model;
                    temp->per_name=temp1->per_name;
                    temp->phone_no=temp1->phone_no;

                    temp1->price=temp2->price;
                    temp1->status=temp2->status;
                    temp1->year=temp2->year;
                    temp1->car_id=temp2->car_id;
                    temp1->label=temp2->label;
                    temp1->model=temp2->model;
                    temp1->per_name=temp2->per_name;
                    temp1->phone_no=temp2->phone_no;

                }
            }
        }
        display_all();
    }
}
//read from file
void file()
{
    string line;
    Car *temp1;
    ifstream thefile("data.txt");
    if(thefile.is_open())
    {
        while(true)
        {
            Car *temp=new Car;
            thefile>>temp->car_id;
            thefile>> temp->model;
            thefile>>temp->year;
            thefile>>temp->label;
            thefile>>temp->price;
            thefile>> temp->status;
            thefile>>temp->per_name;
            thefile>>temp->phone_no;
            if(head==NULL)
            {
                head=temp;
                temp->next=NULL;
            }
            else
            {
                temp->next=head;
                head=temp;

            }
            if (thefile.fail())
            {
                break;
            }

        }

        temp1=head;
        head=temp1->next;
        delete temp1;
        thefile.close();

    }



}
//write to the file
void file2()
{
    ofstream file1;
    Car *temp=head;
    file1.open("data.txt");
    file1.clear();
    if(file1.is_open())
    {

        while(temp!=NULL)
        {
            file1<<temp->car_id<<" ";
            file1<< temp->model<<" ";
            file1<<temp->year<<" ";
            file1<<temp->label<<" ";
            file1<<temp->price<<" ";
            file1<< temp->status<<" ";
            file1<<temp->per_name<<" ";
            file1<<temp->phone_no<<" ";
            file1<<endl;
            temp=temp->next;
        }

    }
       file1.close();
}
void search_car()
{
    Car *temp1;
    char a;
    int found=0,l,x;
    string m;
    system("cls");
  D:  cout<<"\t\t\t\t***********SEARCH A CAR***********"<<endl;
    cout<<"\t\t****ENTER A CAR MODEL->"<<endl;
    cin>>m;
    cout<<"\t\t****ENTER A CAR STAR->"<<endl;
    l=inputInt();
    for(temp1=head; temp1!=NULL; temp1=temp1->next)
    {
        if(temp1->model==m&&temp1->label==l)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        cout<<"\n\t\t\t\t******CAR FOUND*******"<<endl;
        cout<<"\n\t\t*  Press 1 to see the car information              :"<<endl;
        cout<<"\n\t\t*  Press 2 to back to main menu                    :"<<endl;
        cout<<"\n\t\t*  Press ANY key to exit                           :"<<endl;
        x=inputInt();
        switch(x)
        {
        case 1:
        {
            cout<<"\t\t________________________________";
            cout<<"\n\t\t* CAR ID : "<<temp1->car_id;
            cout<<"\n\t\t* CAR MODEL : "<<temp1->model;
            cout<<"\n\t\t* CAR STAR : "<<temp1->label;
            cout<<"\n\t\t* CAR PRICE : "<<temp1->price;
            if(temp1->status==true)
            {
                cout<<"\n\t\t* CAR STATUS : "<<"RENTED";
                cout<<"\n\t\t* RENTED BY : "<<temp1->per_name;
                cout<<"\n\t\t* PHONE NO : "<<temp1->phone_no<<endl;
            }
            else
            {
                cout<<"\n\t\t* CAR STATUS : "<<"NOT RENTED";
                cout<<endl;
            }

        }
        break;
        case 2:
        {
            menu();
        }
        default:
            About();

        }
    }
    else
    {
        cout<<"\n\t\t*     CAR NOT FOUND!!        :"<<endl;

    }

    cout<<"\t\t**Press B/b to back to main menu           :"<<endl;
    cout<<"\n\t\t**Press C/c to back to Search again        :"<<endl;
    cout<<"\n\t\t**Press any key to exit                    :"<<endl;
    cin>>a;
    if(a=='B'||a=='b')
    {
        menu();
    }
    else if(a=='C'||a=='c')
    {
        search_car();
    }
    else
    {
        About();
    }
}

void About()
{
    system("cls");
    system("color c0");
    cout<<"done by eyasu";
    file2();
    exit(0);
}

