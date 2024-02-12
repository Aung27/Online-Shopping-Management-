#include<bits/stdc++.h>
#include<vector>
#include<fstream>
#include<string.h>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;
public:

    virtual void menu();
   void administrator();
    void buyer();
   void add();
    void edit();
   void rem();
   void list();
    void receipt();
};
class seller: public shopping
{
private:

    int pcode;
    float price;
    float dis;
    string pname;
public:
    seller(){}
    seller(int pc,float pr,float ds,string& name)
    {
        pcode=pc;
        price=pr;
        dis=ds;
        pname=name;

    }
    virtual ~seller(){}

   virtual void administrator();

    void add();
    void edit();
    void rem();

};
class customer:public shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;
public:

    customer(){}
    customer(int pc,float pr,float ds,string& name)
    {
        pcode=pc;
        price=pr;
        dis=ds;
        pname=name;

    }
        void buyer();

    void list();
    void receipt();
};

void login()
{
    int count;
    string userid,password,id,pass;
    system("cls");
    cout<<"\t\t\t please enter the username and password:"<<endl;
    cout<<"\t\t\t username";
    cin>>userid;
    cout<<"\t\t\t password";
    cin>>password;
    ifstream input("records.txt");
    while(input>>id>>pass)
    {
        if(id==userid&&pass==password)
        {
            count=1;
            system("cls");

        }
    }
    input.close();
    if(count==1)
    {
        cout<<userid<<"\n your Login is succesfull \n thanks for logging in :\n";
        //goto m;
    }
    else
    {
        cout<<"\n Login error \n please check uour username and password\n";
        // goto m;
    }

}
void registration()
{
    string userid,password,id,pass;
    system("cls");
    cout<<"\t\t\t enter the username :";
    cin>>userid;
    cout<<"\t\t\t enter the password :";
    cin>>password;
    ofstream f1("records.txt",ios::app);
    f1<<userid<<" "<<password<<endl;
    system("cls");
    cout<<"\t\t\t Registration is Succesfull \n";
    //goto m;

}
void forget()
{
    int option;
    system("cls");
    cout<<"\t\t\t you forget the password? no worries \n";
    cout<<"press 1 to search you id by username"<<endl;
    cout<<"press 2 to back to the main menu"<<endl;
    cout<<"\t\t\t enter your choice:";
    cin>>option;
    switch(option)
    {
    case 1:
    {
        int count=0;
        string userid,id,pass;
        cout<<"\t\t\t enter the username which uou remember :";
        cin>>userid;
        ifstream f2("records.txt");
        while(f2>>id>>pass)
        {
            if(id==userid)
            {
                count=1;
            }
        }
        f2.close();
        if(count==1)
        {
            cout<<"\n\n your userid is found \n";
            cout<<"\n\n your password is :"<<pass;

        }
        else
        {
            cout<<"\n\n sorry your account is not found \n";

        }
        break;
    }
    case 2:
    {

    }
    default:
        cout<<"\t\t\t wrong choice : please try again";
    }
}
void shopping:: menu()
{
m:
    int choice;
    cout<<"Supermarket Main Menu"<<endl;
    cout<<"1) Menu"<<endl;
    cout<<"2) Seller"<<endl;
    cout<<"3) Customer "<<endl;
    cout<<"4) Exit"<<endl;
    cout<<"Please select: ";
    cin>>choice;
    switch(choice)
    {
    case 1:

        int c;
        cout<<"\t\t\t..........................\n\n\n";
        cout<<"\t\t\t                    Welcome to the login page       \n\n\n";
        cout<<"\t\t\t...........................   Menu     ............\n\n";
        cout<<"\tPress 1 to Registration                      |"<<endl;
        cout<<"\tpress 2 to login                             |"<<endl;
        cout<<"\tpress 3 if you forget your password          |"<<endl;
        cout<<"\tpress 4 to exit                              |"<<endl;
        cout<<"\t\t\t Please enter your choice:";
        cin>>c;
        cout<<endl;
        switch(c)
        {
        case 1:
            registration();
            goto m;
        case 2:
            login();
            goto m;
        case 3:
            forget();
            goto m;
        case 4:
            cout<<"\t\t\t Thank you \n\n";
            goto m;
        default:
            system("cls");
            cout<<"\t\t\t Please select from the option given above \n"<<endl;
            goto m;

        }
    case 2:
    {
        seller s;
       s. administrator();
    }
    case 3:
    {
        customer c;
       c. buyer();
    }
    case 4:
    {
        exit(0);
    }
    default:
    {
        cout<<"please select from given option: ";
    }

    goto m;

    }
}

void seller:: administrator()
{
m:
    int choice;
    cout<<"administrator menu"<<endl;
    cout<<"1) add the product"<<endl;
    cout<<"2)modify the product"<<endl;
    cout<<"3)delete the product"<<endl;
    cout<<"4)back to main menue"<<endl;
    cout<<"\nPlease inter your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        add ();
        break;
    case 2:
        edit();
        break;
    case 3:
     rem();
    break;
    case 4:
    menu();
    break;

    default:
        cout<<"invalid choice";
    }
    goto m;

}
void customer::buyer()
{
m:
    int choice;
    cout<<"\tBuyer\n";
    cout<<"1)Buy product\n";
    cout<<"2)Go back\n";
    cout<<"Enter your choice\n";
    cin>>choice;
    switch(choice)
    {
     case 1:
     receipt();
     break;
     case 2:
      menu();
    default:
        cout<<"invalid choice\n";
    }
    goto m;
}
void seller::add()
{
m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    cout<<"add new product\n";
    cout<<"product code of the product\n";
    cin>>pcode;
    cout<<"name of the product\n";
    cin>>pname;
    cout<<"price of the product\n";
    cin>>price;
    cout<<"discount on product\n";
    cin>>dis;
    data.open("database.txt",ios::app|ios::in);
    if(data)
    {


        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

    }
    if (token==1)

        goto m;
    else
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }


    cout<<"\n Record inserted\n";
}

void seller ::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n modify the record\n";
    cout<<"products code\n";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(data)
    {
        cout<<"file does not exist";
    }
    else
    {
        data.open("database.txt",ios::app|ios::out);
        //data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n product new code:\n";
                cin>>c;
                cout<<"name of the product\n";
                cin>>n;
                cout<<"price\n";
                cin>>p;
                cout<<"discount\n";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";


            }
            data<<pcode<<pname<<price<<" "<<dis<<"\n";
            data>>pcode>>pname>>price>>dis;


        }
        data.close();
        data1.close();
        remove("database.txt");
        // remove(database1.txt);
        rename("database1.txt","database.txt");
        if(token==0)
            cout<<"record not found sorry";


    }


}

void seller :: rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File doesn't exits ";
    }
    else{
        data.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        //while(!data.eof())
       // {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted succesfully ";
                token++;
            }
            else
            {
                data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;

        //}
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found";
        }
    }
}
void customer:: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|...................\n";
    cout<<"ProNO\t\tname\t\tPrice\n";
    cout<<"\n\n|....................\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
void customer:: receipt()
{
    fstream data;

    vector<int> arrc;
    vector<int> arrq;
    char choice;
    float amount = 0;
    float discount = 0;
    float total = 0;
    int c = 0;

    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);

    if (!data) {
        cout << "\n\n Empty database";
    } else {
        data.close();

        list();
        cout << "\n..............................\n";
        cout << "\n|.............................\n";
        cout << "\n   Please place the order     \n";
        cout << "\n|.............................\n";
        cout << "\n..............................\n";

        do {
            m:
            cout << "\n\nEnter Product code : ";
            int code;
            cin >> code;
            arrc.push_back(code);

            cout << "\n\nEnter the product quantity : ";
            int quantity;
            cin >> quantity;
            arrq.push_back(quantity);

            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n Duplicate product code. please try again !";
                    arrc.pop_back();
                    arrq.pop_back();
                    goto m;
                }
            }
            c++;

            cout << "\n\n Do you want to buy another product ? if yes then press y else no";
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n\t\t\t.............RECEIPT.........";
        cout << "\n Product No\t product Name \t Product quantity \tprice \tAmount\tAmount with discount \n";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;

            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    discount = amount - (amount * dis / 100);
                    total += discount;

                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << discount;

                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }

    cout << "\n\n";
    cout << "\n Total Amount : " << total;

}

int main()
{
    shopping s;
    s.menu();
}

