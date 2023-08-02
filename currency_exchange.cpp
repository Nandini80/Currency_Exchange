///HEADER FILES USED IN THIS PROGRAM
#include <iostream>
#include <string>
#include <conio.h>
#include<windows.h>
#include <ctime>
#include<fstream>

using namespace std;

class people
{
protected  :
    string name ;
    int age ;
    string nationality ;
    int passport ;

public :
    void setData ()
    {
        cout << "enter customer name : ";
        cin >> name ;

        cout << "enter customer age : ";
        cin >> age ;

        cout << "enter nationality : ";
        cin >> nationality ;

    }

    string name_cus()
    {
        return name ;
    }

    int age_cus()
    {
        return age ;
    }

    string nationality_cus ()
    {
        return nationality ;
    }

    void printData ()
    {
        cout << "name of customer= " << name  << endl;
        cout << "age of customer = " << age << endl ;
        cout << "nationality of customer = " << nationality << endl;
    }

};


class customer : public people
{
   int passport;

   public :

   void setData ()
    {
        cout << "enter customer name : ";
        cin >> name ;

        cout << "enter customer age : ";
        cin >> age ;

        cout << "enter nationality : ";
        cin >> nationality ;

        cout << "enter passport number : ";
        cin >> passport ;
    }

    int passport1()
    {
        return passport;
    }

};


class currency 
{
protected :
    double rupee ;
    double euro ;
    double dollar ;
    double pound ;
    
public :

    currency()
    {
        rupee = 0;
        euro = 0;
        dollar = 0;
        pound = 0;
    }
    
    double return_amount()
    {
        if ( rupee !=0 )
        {
            return rupee ;
        }

         if ( euro !=0 )
        {
            return euro ;
        }

         if ( dollar !=0 )
        {
            return dollar ;
        }

         if ( pound !=0 )
        {
            return pound ;
        }

    }

    double convert ( int choice );
    
};


void ownerLogin()
{
    ifstream MyFile3("owner.txt");

    string name;
    getline(MyFile3,name);

    string age;
    getline(MyFile3,age);

    string password ;
    getline(MyFile3,password);

    string earning ;
    getline(MyFile3,earning);

    string user_password;
    cout<<"Enter the password ";
    cin>>user_password;

    if(user_password == password)
    {
       cout << "name of owner = " << name << endl;
       cout << "age of owner = " << age << endl;
       cout << "earning = " << earning << endl;
    }

    else
    {
        cout<<"Wrong Password"<<endl;
    }

    MyFile3.close();

    cout<<"Press any key to exit"<<endl;
    getch();
}


double convert_dollar_to_Rupee(double dollar)
{
    double rupee = dollar * 81.51;
    return rupee;
}

double convert_Rupee_to_dollar(double rupee)
{
     double dollar = rupee * 0.012;
    return dollar;
}

double convert_pound_to_Rupee (double pound)
{
     double rupee = pound * 113.11;
    return rupee;
}

double convert_Rupee_to_pound (double rupee)
{
     double pound = rupee * 0.0088;
    return pound;
}

double convert_euro_to_Rupee (double euro)
{
     double rupee = euro * 94.92;
    return rupee;
}

double convert_Rupee_to_euro (double rupee)
{
    double euro = rupee * 0.0105;
    return euro;
}

double convert_dollar_to_pound (double dollar)
{
    double pound = dollar * 0.73;
    return pound;
}

double convert_pound_to_dollar (double pound)
{
    double dollar = pound * 1.37;
    return dollar;
}

double convert_dollar_to_euro ( double dollar)
{
    double euro = dollar * 0.86;
    return euro;
}

double convert_euro_to_dollar ( double euro)
{
    double dollar = euro * 1.16;
    return dollar;
}

double convert_euro_to_pound ( double euro)
{
    double pound = euro * 0.90;
    return pound;
}

double convert_pound_to_euro ( double pound)
{
    double euro = pound * 1.11;
    return euro;
}



customer customerInfo ()
{
    customer c1;
    c1.setData();

    ofstream of;
    of.open("customers.txt", ios::app);

    of << c1.name_cus() << "  " << c1.age_cus() << "  " << c1.nationality_cus() <<"  "<<c1.passport1()<< endl;
    
    of.close();
    
    return c1;
}



double getMoney()
{
    ifstream MyFile3("owner.txt");

    string name;
    getline(MyFile3, name);

    string age;
    getline(MyFile3, age);

    string password;
    getline(MyFile3, password);

    string earning;
    getline(MyFile3, earning);

    MyFile3.close();

    // Typecasting
    double money2 = atof(earning.c_str());
    return money2;
}


double currency :: convert (int choice)
{
    if(choice == 1)
    {

        cout<< "Enter dollars to convert to Rupee " << endl;
        cin >> dollar;
        rupee = convert_dollar_to_Rupee(dollar);

        ifstream Myfile("dollar.txt");

        double account_dollar;
        string tempdollar;

        getline(Myfile, tempdollar);

        account_dollar = atof(tempdollar.c_str());

        if(account_dollar < dollar)
        {
            cout << "not enough amount";
        }

        else
        {          
            account_dollar -= dollar;
            Myfile.close();
        }

        ofstream Myfile1("dollar.txt");
        Myfile1 << account_dollar;

        Myfile1.close();

        double earning1 = 0.05 * rupee;
        cout << dollar <<" Dollars In Rupee = "<<rupee - earning1<<endl ;
        return earning1;

    }

    else if(choice == 2)
    {

        cout << "Enter Rupee to convert to Dollar " << endl;
        cin >> rupee;
        dollar = convert_Rupee_to_dollar(rupee);

        ifstream Myfile("rupee.txt");
        double account_rupee;
        string temprupee;

        getline( Myfile, temprupee );
        account_rupee = atof(temprupee.c_str());

        if(account_rupee < rupee)
        {
            cout << "not enough amount";
        }

        else
        {          
            account_rupee -= rupee;
            Myfile.close();
        }

        ofstream Myfile1("rupee.txt");
        Myfile1 << account_rupee;
        Myfile1.close();

        double earning1 = 0.05*rupee;
        cout << rupee <<" Rupees In Dollar = "<< dollar<< endl;
        return earning1;

    }
  
    else if (choice == 3)
    {
       
        cout << "Enter Pound to convert to Rupee " << endl;
        cin >> pound;
        rupee = convert_pound_to_Rupee(pound);

        ifstream Myfile("pound.txt");
        double account_pound;
        string temppound;

        getline( Myfile, temppound );
        account_pound = atof(temppound.c_str());

        if(account_pound < pound)
        {
            cout << "not enough amount";
        }

        else
        {          
            account_pound -= pound;
            Myfile.close();
        }

        ofstream Myfile1("pound.txt");
        Myfile1 << account_pound;
        Myfile1.close();

        double earning1 = 0.05*rupee;
        cout << pound <<" Pounds In Rupee = "<< rupee<< endl;
        return earning1;
        
    }

    else if(choice == 4)
    {
       
        cout << "Enter Rupee to convert to Pound " << endl;
        cin >> rupee;
        pound = convert_Rupee_to_pound(rupee);

        ifstream Myfile("rupee.txt");
        double account_rupee;
        string temprupee;
    
        getline( Myfile, temprupee );
        account_rupee = atof(temprupee.c_str());
    
        if(account_rupee < rupee)
        {
            cout << "not enough amount";
        }

        else
        {          
            account_rupee -= rupee;
            Myfile.close();
        }

        ofstream Myfile1("rupee.txt");
        Myfile1 << account_rupee;
        Myfile1.close();

        double earning1 = 0.05*rupee;
        cout << rupee <<" Rupees In Pound = "<< pound<< endl;
        return earning1;
    
    }

    else if (choice == 5)
    {
    
        cout << "Enter Euro to convert to Rupee " << endl;
        cin >> euro;
        rupee = convert_euro_to_Rupee(euro);

        ifstream Myfile("euro.txt");
        double account_euro;
        string tempeuro;
    
        getline( Myfile, tempeuro );
        account_euro = atof(tempeuro.c_str());
    
        if(account_euro < euro)
        {
            cout << "not enough amount";
        }
        
        else
        {          
            account_euro -= euro;
            Myfile.close();
        }

        ofstream Myfile1("euro.txt");
        Myfile1 << account_euro;
        Myfile1.close();

        double earning1 = 0.05*rupee;
        cout << euro <<" Euro In Rupee = "<< rupee<< endl;
        return earning1 ;
        
    }

    else if(choice == 6)
    {

        cout << "Enter Rupee to convert to Euro " << endl;
        cin >> rupee;
        euro = convert_Rupee_to_euro(rupee);

         ifstream Myfile("rupee.txt");
        double account_rupee;
        string temprupee;
    
        getline( Myfile, temprupee );
        account_rupee = atof(temprupee.c_str());
    
        if(account_rupee < rupee)
        {
            cout << "not enough amount";
        }
        
        else
        {          
            account_rupee -= rupee;
            Myfile.close();
        }

        ofstream Myfile1("rupee.txt");
        Myfile1 << account_rupee;
        Myfile1.close();

        double earning1 = 0.05*rupee;
        cout << rupee <<" Rupees In Euro = "<< euro<< endl;
        return earning1;
        
    }

    else if (choice == 7)
    {
    
        cout << "Enter Dollar to convert to Pound " << endl;
        cin >> dollar;
        pound = convert_dollar_to_pound(dollar);
        double rupee = convert_dollar_to_Rupee(dollar);

        ifstream Myfile("dollar.txt");
        double account_dollar;
        string tempdollar;
    
        getline(Myfile, tempdollar);
        account_dollar = atof(tempdollar.c_str());
    
        if(account_dollar < dollar)
        {
            cout << "not enough amount";
        }
        
        else
        {          
            account_dollar -= dollar;
            Myfile.close();
        }

        ofstream Myfile1("dollar.txt");
        Myfile1 << account_dollar;
        Myfile1.close();

        double earning1 = 0.05*rupee;
        cout << dollar <<" Dollars In Pound = "<< pound << endl;
        return earning1;
        
    }

    else if(choice == 8)
    {
       
        cout << "Enter Pound to convert to Dollar " << endl;
        cin >> pound;
        dollar = convert_pound_to_dollar(pound);
        double rupee = convert_dollar_to_Rupee(dollar);

        ifstream Myfile("pound.txt");
        double account_pound;
        string temppound;
    
        getline( Myfile, temppound );
        account_pound = atof(temppound.c_str());
    
        if(account_pound < pound)
        {
            cout << "not enough amount";
        }
        
        else
        {          
            account_pound -= pound;
            Myfile.close();
        }

        ofstream Myfile1("pound.txt");
        Myfile1 << account_pound;
        Myfile1.close();

        double earning1 = 0.05*rupee;
        cout << pound <<" Pounds In Dollar = "<< dollar << endl;
        return earning1;
    
    }

    else if (choice == 9)
    {
       
        cout << "Enter Dollar to convert to Euro " << endl;
        cin >> dollar;
        euro = convert_dollar_to_euro(dollar);
        double rupee = convert_dollar_to_Rupee(dollar);

        ifstream Myfile("dollar.txt");
        double account_dollar;
        string tempdollar;
    
        getline(Myfile, tempdollar);
        account_dollar = atof(tempdollar.c_str());
    
        if(account_dollar < dollar)
        {
            cout << "not enough amount";
        }
        
        else
        {          
            account_dollar -= dollar;
            Myfile.close();
        }

        ofstream Myfile1("dollar.txt");
        Myfile1 << account_dollar;
        Myfile1.close();

        double earning1 = 0.05*rupee;
        cout << dollar <<" Dollars In Euro = "<< euro << endl;
        return earning1;
        
    }

    else if(choice == 10)
    {
       
        cout << "Enter Euro to convert to Dollar " << endl;
        cin >> euro;
        dollar = convert_euro_to_dollar(euro);
        double rupee = convert_dollar_to_Rupee(dollar);

        ifstream Myfile("euro.txt");
        double account_euro;
        string tempeuro;
    
        getline( Myfile, tempeuro );
        account_euro = atof(tempeuro.c_str());
    
        if(account_euro < euro)
        {
            cout << "not enough amount";
        }
        
        else
        {          
            account_euro -= euro;
            Myfile.close();
        }

        ofstream Myfile1("euro.txt");
        Myfile1 << account_euro;
        Myfile1.close();

        double earning1 = 0.05*rupee;
        cout << euro <<" Euro In Dollar = "<< dollar << endl;
        return earning1;
        
    }

    else if (choice == 11)
    {
       
        cout << "Enter Euro to convert to Pound " << endl;
        cin >> euro;
        pound = convert_euro_to_pound(euro);
        double rupee = convert_euro_to_Rupee(euro);

        ifstream Myfile("euro.txt");
        double account_euro;
        string tempeuro;
    
        getline( Myfile, tempeuro );
        account_euro = atof(tempeuro.c_str());
    
        if(account_euro < euro)
        {
            cout << "not enough amount";
        }
        
        else
        {          
            account_euro -= euro;
            Myfile.close();
        }

        ofstream Myfile1("euro.txt");
        Myfile1 << account_euro;
        Myfile1.close();

        double earning1 = 0.05*rupee;
        cout << euro <<" Euro In Pound = "<< pound << endl;
        return earning1;
        
    }

    else if(choice == 12)
    {
       
        cout << "Enter Pound to convert to Euro " << endl;
        cin >> pound;
        euro = convert_pound_to_euro(pound);
        double rupee = convert_euro_to_Rupee(euro);

        ifstream Myfile("pound.txt");
        double account_pound;
        string temppound;
    
        getline( Myfile, temppound );
        account_pound = atof(temppound.c_str());
    
        if(account_pound < pound)
        {
            cout << "not enough amount";
        }
        
        else
        {          
            account_pound -= pound;
            Myfile.close();
        }

        ofstream Myfile1("pound.txt");
        Myfile1 << account_pound;
        Myfile1.close();

        double earning1 = 0.05*rupee;
        cout << pound <<" Pounds In Euro = "<< euro << endl;
        return earning1;
        
    }

    else
    {
        cout << "Invalid choice, please select between 1 - 12" << endl;
        return 0;
    }

}

void printBill ( customer p1 , currency c1 )
{

    cout << endl ;
    cout << endl ;

    cout << "This is your Bill " << endl ;
    cout << "NAME OF CUSTOMER= " << p1.name_cus() << endl ;
    cout << "AGE OF CUSTOMER= " << p1.age_cus() << endl ;
    cout << "NATIONALITY OF CUSTOMER= " << p1.nationality_cus() << endl ;
    cout << "AMOUNT = " << c1.return_amount() << endl ;
    cout << "Thanks for choosing "  << endl ;

    Sleep(4000);
}



void mainbody ()
{
    customer p1 = customerInfo();
    int choice ;
    cout << "\n1) Choose a currency and convert" << endl;
    cout << "2) Check value of in different currences " << endl;

    cout << "3) EXIT THIS MENU" << endl;

    cout << "enter choice : ";
    cin >> choice ;

    while(choice!=3)
    {
        currency c1;

        if (choice == 1)
        {
            cout << "\t\t\tchoose from below options to convert" << endl;
            cout << "\t\t\t [1] Dollar (USD) to Rupee(INR) " << endl;
            cout << "\t\t\t [2] Rupee (INR) to Dollar(USD) " << endl;
            cout << "\t\t\t [3] Pound (GBP) to Rupee (INR) " << endl;
            cout << "\t\t\t [4] Rupee (INR) to Pound (GBP) " << endl;
            cout << "\t\t\t [5] Euro (EUR) to Rupee (INR) " << endl;
            cout << "\t\t\t [6] Rupee (INR) to Euro (EUR) " << endl;
            cout << "\t\t\t [7] Dollar (USD) to Pound (GBP) " << endl;
            cout << "\t\t\t [8] Pound (GBP) to Dollar (USD) " << endl;
            cout << "\t\t\t [9] Dollar (USD) to Euro (EUR) " << endl;
            cout << "\t\t\t [10] Euro (EUR) to Dollar (USD) " << endl;
            cout << "\t\t\t [11] Euro (EUR) to Pound (GBP) " << endl;
            cout << "\t\t\t [12] Pound (GBP) to Euro (EUR) " << endl;
            cout << endl;
            cout << endl;
            cout << "Enter your choice to convert from one currency to other:\n";
            int choice1;
            cout << "enter option : ";
            cin >> choice1;
            double money = getMoney();
            money += c1.convert(choice1);


            ifstream MyFile3("owner.txt");
    
            string name;
            getline(MyFile3, name);
    
            string age;
            getline(MyFile3, age);
    
            string password;
            getline(MyFile3, password);
    
            string earning;
            getline(MyFile3, earning);
    
            MyFile3.close();

            
            ofstream of;
            of.open("owner.txt");
    
            of << name << endl;
            of << age << endl;
            of << password << endl;
            of << money << endl;
    
            of.close();
    
            if(choice1 > 0 && choice1 < 13)
            {
                printBill(p1,c1);
            }
            
        }

        else if (choice == 2)
        {

            cout << "Rupee value in different currencies  :" << endl;
            cout << "1 Rupee = 0.0098 pound " << endl;
            cout << "1 pound = 101.90 rupees " << endl;
            cout << "1 Rupee = 0.012 dollar " << endl;
            cout << "1 dollar = 82.08 rupees " << endl;
            cout << "1 rupee = 0.011 euro " << endl ;
            cout << "1 Euro = 90.07 rupees " << endl;
            cout << "1 dollar = 0.81 pound " << endl;
            cout << "1 pound = 1.24 dollars" << endl ;
            cout << "1 Euro = 0.88 pound " << endl;
            cout << "1 pound = 1.13 euro " << endl;
            cout << "1 dollar = 0.91 euro " << endl;
            cout << "1 euro = 1.10 dollars " << endl;

        }

        else if(choice == 3)
        {
            cout << "RETURNING..." << endl;
            break;
        }
        
        else
        {
            cout<<" try again " ;
        }

        cout << "\n1) Choose a currency and convert" << endl;
        cout << "2) Check value of in different currences " << endl;
        cout << "3) EXIT THIS MENU" << endl;
        
        cout << "enter choice : ";
        cin >> choice ;

    }
}

int main()
{

    system("title Currency Converter @copyassignment");
    system("color B0");  // To give blue colour to background
    string currency;
    int choice;

    system("cls");

    cout << "\t\t<================================================================================>" << endl;
    cout << "\t\t|                        WELCOME TO CURRENCY CONVERTER                           |" << endl;
    cout << "\t\t|            Please NOTE that the currency value fluctuates frequently           |" << endl;
    cout << "\t\t|      So if you find the conversion to be inaccurate, that might be the cause   |" << endl;
    cout << "\t\t<================================================================================>" << endl;
    cout << endl;

    cout << "\nEnter the choice " << endl ;
    cout << "[1] To exchange currency " << endl ;
    cout << "[2] To login as an owner " << endl ;
    cout << "[3] To exit " << endl;

    cin >> choice ;

    while (choice != 3)
    {
        
        if (choice == 1)
        {
            mainbody ();
        }
        else if (choice == 2)
        {
            ownerLogin();
        }
        else if (choice == 3)
        {
            cout << "Exiting the Program..." << endl ;
            cout << "Thank You..." << endl ;
            exit(0);
        }
        else
        {
            cout << "Invalid Choice "  << endl ;
            cout << "Enter Valid Choice " << endl ;

            Sleep(3000);
        }
        system("cls"); // To clear the screen 
        
        cout << "[1] To exchange currency " << endl ;
        cout << "[2] To login as an owner " << endl ;
        cout << "[3] To exit " << endl;
        cout << "\nEnter the choice ";
        cin>>choice;

    }
}