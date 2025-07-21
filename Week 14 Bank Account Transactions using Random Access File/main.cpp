#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "Account.h"

using namespace std;

  int enterChoice () ;
  void createTextFile(fstream&);
  void updateRecord(fstream&);
  void deleteRecord(fstream&);
  void outputLine(ostream& ,const ClientData &);
  int newRecord(fstream &);
  int getAccount (const char * const);
  enum Choices {PRINT=1 , UPDATE, NEW , DELETE , END};
  void printAllRecords(fstream &);

int main()
{

 fstream inOutCredit("credit.dat", ios::in |ios::out |ios::binary);

 if(!inOutCredit)
 {
     cerr<<"File could not be opened" <<endl ;
     exit(1);

 }
   int  choices ;
printAllRecords (inOutCredit);
   while ((choices =enterChoice() )!=END)
   {
       switch (choices )
       {
           case PRINT :
           createTextFile (inOutCredit);
           break ;
           case UPDATE:
           updateRecord (inOutCredit);
           break ;
           case NEW :
           newRecord (inOutCredit);
           break;
           case DELETE:
           deleteRecord(inOutCredit);
           break ;
           default:
           cerr<<"Incorrect choice" <<endl ;
           break ;
       }

       inOutCredit.clear();
   }
printAllRecords (inOutCredit);

   // return 0;
}

int enterChoice()
{
    cout <<"\nEnter your choice" << endl
    <<"1-Store a formatted text file of accounts"<< endl
    <<"2-Update an account " << endl
    <<"3-add a new account" << endl
    <<"4- delete an account " << endl
    <<"5 - end program \n?";

    int menuChoice ;
    cin >>menuChoice;
    return menuChoice;
}

void printAllRecords(fstream &myprint)
{
    for (int i = 1; i <= 100; i++)
    {
        myprint.seekg((i-1) * sizeof (ClientData));
        ClientData client;
        myprint.read(reinterpret_cast<char * > (&client), sizeof(ClientData));

        if (client.getAccountNumber()!=0)
        {
            outputLine(cout ,client);
        }
    }
    myprint.clear();
}
void createTextFile(fstream &readFromFile)
{
    ofstream outPrintFile ("print.txt", ios::out);
    if (!outPrintFile)
    {
        cerr<<"File could not be created. "<<endl ;
        exit (1);
    }

    outPrintFile << left << setw(10) << "Account " <<setw(16) << "Last Name " << setw(11) << "first Name" << right << setw(10) << "Balance" << endl ;
    readFromFile.seekg(0);

    ClientData client ;
     readFromFile.read (reinterpret_cast <char * > (&client), sizeof(ClientData));

     while ( !readFromFile.eof())
     {
         if(client.getAccountNumber()!=0)
         outputLine(outPrintFile,client);

         readFromFile.read (reinterpret_cast<char * > (&client), sizeof(ClientData));
     }
}
void updateRecord(fstream &updateFile)
{
    int accountNumber = getAccount("Enter account to Update");

    updateFile.seekg ((accountNumber-1) * sizeof (ClientData));

    ClientData client ;
    updateFile.read (reinterpret_cast<char * > (&client), sizeof(ClientData));

        if (client.getAccountNumber()!=0 )
        {
            outputLine(cout ,client);
            cout <<"\nEnter charge (+) or payment (-)";
            double transaction;
            cin >> transaction;
            double oldBalance = client.getBalance();
            client.setBalance(oldBalance+transaction);
            outputLine (cout , client);

            updateFile.seekp ((accountNumber-1) *sizeof(ClientData));

            updateFile.write (reinterpret_cast<char * > (&client),
            sizeof(ClientData));
        }
        else
        {
            cerr << "Account #" << accountNumber <<"has no information ." << endl ;
        }
}

int getValidAccountNumber(fstream &readFromFile)

{
    int smallest=1;
    readFromFile.seekg(0);

    ClientData myclient;

     while ( !readFromFile.eof())
    {
        readFromFile.read(reinterpret_cast<char *>(&myclient), sizeof(ClientData));
        if (myclient.getAccountNumber() == 0)
            return smallest;
        else
        smallest++;
    }
    return 0;
}

int newRecord(fstream &insertInFile )
{
    int accountNumber =getValidAccountNumber(insertInFile) ;
    insertInFile.seekg((accountNumber-1)*sizeof(ClientData));
    ClientData client;

    insertInFile.read (reinterpret_cast<char * > (&client), sizeof(ClientData));

    if (accountNumber!=0)
    {
        string lastname;
        string firstname ;
        double balance ;

        cout <<"Enter lastname , firstname , balance\n?";
        cin >>setw(15) >>lastname ;
        cin>>setw(10)>>firstname;
        cin >>balance;

        client.setLastName(lastname);
        client.setFirstName(firstname);
        client.setBalance(balance);
        client.setAccountNumber(accountNumber);

        insertInFile.seekp ((accountNumber-1)*sizeof(ClientData));

        insertInFile.write (reinterpret_cast<char * > (&client), sizeof(ClientData));

        cout <<" New account created successfully : " << accountNumber << endl;
    }
    else
    {
        cerr<<"Account is not created!\n" ;
    }
    return 0;
}

void outputLine(ostream &output , const ClientData &record)

{
    output <<left <<setw (10) <<record.getAccountNumber()
    <<setw(16) <<record.getLastName()
    <<setw(11) <<record.getFirstName()
    <<setw(10) <<setprecision(2) <<right <<fixed
    <<showpoint <<record.getBalance() <<endl;
}

void deleteRecord (fstream &deleteFromFile)
{
    int accountNumber =getAccount("Enter account to delete");
    deleteFromFile.seekg((accountNumber-1)*sizeof(ClientData));

ClientData client;

deleteFromFile.read (reinterpret_cast<char * > (&client),
                        sizeof(ClientData));

if (client.getAccountNumber()!=0)

{
    ClientData blankClient;


deleteFromFile.seekp ((accountNumber-1)*sizeof(ClientData));
deleteFromFile.write (reinterpret_cast<char * > (&blankClient),
                        sizeof(ClientData));

cout <<"Account #"<<accountNumber <<" deleted.\n";

}
else

cerr <<"Account # " <<accountNumber <<" is empty.\n";
}





int getAccount(const char *const prompt)

{
    int accountNumber ;

    do
    {
        cout <<prompt <<"(1-100 ): ";
        cin >>accountNumber;


    }while (accountNumber <1 ||accountNumber>100);
    return accountNumber;
}
