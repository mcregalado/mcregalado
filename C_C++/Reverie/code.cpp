#include <iostream>
#include <unistd.h>
#include<conio.h>
using namespace std;

const int accounts=10, storage=10;
int account=0;
string username[accounts], password[accounts];
string weapon[storage]={"Kanemitsu", "Yoichi's Bow", "Wings of Vanth","Athame", "Romulus' Spear"};
string type[storage]={"Naginata", "Bow", "Gloves", "Knife", "Spear"};
string arcana[storage]={"Fool","Lovers","Emperor","Strength","Justice"};

int main();
class Game
{
  public:
  void weapons()
  {
    int counter=0;
    for(int i=0; i<storage; i++)
    {
      if(weapon[i]!="\0")
      {
      counter++;
      cout << "\n\t\t\t " << counter << " [WEAPON] " << weapon[i] << "\n\t\t\t [TYPE] ";
      cout << type[i]<< "\n\t\t\t [CLASS] " << arcana[i] << endl;
      }
    }  
  }
  void delWeap()
  {
    int cnt=0,i,delW;
    string inWeap;
    cout << "\n\t\t ________D i s p o s a l________\n";
    cout << "\n\t Which weapon to remove? Type in their weapon name."<< endl; weapons();
    cout << "\n\t Disassemble Weapon: "; cin.ignore(); getline(cin,inWeap);
    for (i=0; i<storage; i++)
      {
      if(weapon[i]==inWeap)
      {cnt++; delW=i; break;}
      }
    if(cnt==1)
      {
        for(i=delW;i<storage-1;i++)
        {
        weapon[i]=weapon[i+1];
        type[i]=type[i+1];
        arcana[i]=arcana[i+1];
        }
      }
    else {cout << "\n\n\tThis weapon is already not in your inventory.";sleep(4);}
  }
  void editEquip()
  {
    int counter=0,i;
    string editWeap,editType,editArcana,inWeap;
    cin.ignore();
    
    cout << "\n\t\t _______E n c h a n t m e n t_______\n";
    cout << "\n\t Which weapon to enhance? Type in their weapon name."<< endl; weapons();
    cout << "\n\tWeapon: "; getline(cin, inWeap);
    
    for (i=0; i<storage; i++)
    {
      if(weapon[i]==inWeap)
      {
      counter++;
      cout << "\n\tWeapon's new name: "; getline(cin, editWeap);
      cout << "\tNew type of Weapon: "; getline(cin, editType);
      cout << "\tNew class: "; getline(cin,editArcana);
      weapon[i]=editWeap;
      type[i]=editType;
      arcana[i]=editArcana;
      cout << "\n\tEnchanting";sleep(1);cout<<". ";sleep(1);cout<<". ";sleep(1);cout<<". ";sleep(1);
      cout << "\n\n\tWeapon upgraded!"; sleep(4); break;
      }
    }
    if(counter==0)
    {cout << "\n\tThis weapon does not exist in your inventory.";sleep(4);}
  }
  
  void addWeap()
  {
  string inWeap,inType,inArcana;
  cin.ignore();
    
  cout << "\n\t_______B l a c k s m i t h_______\n";
  cout << "\n\n\tWeapon's name: "; getline(cin, inWeap);
  cout << "\tType of Weapon: "; getline(cin, inType);
  cout << "\tClass: "; getline(cin,inArcana);
    
  for(int i=0;i<storage;i++)
    {
      if(weapon[i]=="\0")
      {
        weapon[i]=inWeap;
        type[i]=inType;
        arcana[i]=inArcana;
        cout << "\n\tForging weapon";sleep(1);cout<<". ";sleep(1);cout<<". ";sleep(1);cout<<". ";sleep(1);
        cout << "\n\n\tObtained new weapon!"; sleep(4); break;
      }
    }
  }
  
  void gotoStory()
    {
      cout << "\n\n\t\t ";sleep(1);cout<<"R ";sleep(1);cout<<"E ";sleep(1);cout<<"V ";sleep(1);cout<<"E ";sleep(1);
      cout<<"R ";sleep(1);cout<<"I ";sleep(1);cout<<"E ";sleep(1);cout<<" "<<endl; sleep(2);
      cout << "\n\t This section is still under construction.";
      cout <<"\n Please wait for the developer to gain more knowledge \n\t\t\t Thank you! ^^"<< endl; sleep(4);
    }
  
  void linkStart()
  {
    int p, counter=0;
    do{cout << "\n _____________________E Q U I P M E N T S_______________________" << endl;
    cout << "\n\n Prepare characters by harnessing their weapons to start off your journey!"<< endl;
    cout << "\t These starting gears are already provided!"<< endl; weapons();
    cout << "\n\t\t ____________________________________"<<endl;
    cout << "\n\t\t\t 1. Begin your story\n\t\t\t 2: Craft a new weapon"<<endl;
    cout << "\t\t\t 3: Enhance equipment\n\t\t\t 4: Dispose weaponry\n\t\t\t 5: Log out"<< endl;
    cout << "\n\t Action (no.): "; cin >> p;
    switch(p)
    {
      case 1: system("CLS"); gotoStory(); system("CLS"); break;
      case 2: system("CLS"); addWeap(); system("CLS"); break;
      case 3: system("CLS"); editEquip(); system("CLS"); break;
      case 4: system("CLS"); delWeap(); system("CLS"); break;
      case 5: system("CLS"); cout<< "\n\t [Logged out successfully]\n";sleep(2); main(); break;
    }
    }while (p!=5);
  }
};
  class AccountManager: public Game
  {
    public:
    void registration()
  {
  cout << "\n\t_______R E G I S T E R_______\n";
  if(account<accounts)
    {
    cout << "\n\n\tUsername: "; cin>> username[account];
    cout << "\tPassword: "; cin>> password[account];
    account++;
    cout << "\n\n\tSuccessfully created an account." << endl; sleep(2);system("CLS");
    }
  else
    {
    cout << "\n\n\tSorry. The server is now full." << endl;
    cout << "\n\t_____________________________\n";sleep(2);system("CLS");
    }
  }
  void login()
  {
    string username_input, password_input;
    int counter=0,i,numL;
    cout << "\n\t_______L O G I N_______\n";
    cout << "\n\n\tUsername: "; cin >> username_input;
    cout << "\tPassword: "; numL=getch();
    while (numL!=13)
    {password_input.push_back(numL); cout << "*"; numL=getch();}
    for(i=0; i<account; i++)
    {
      if((username_input==username[i])&&(password_input==password[i]))
      {counter++;}
    }
      if(counter==1)
      {cout << "\n\n\tSuccessfully logged in.";sleep(2);system("CLS");linkStart();}
      else
      {cout << "\n\n Username/Password not recognized."; sleep(2);system("CLS");main();}
  }
  void leave()
  {system("CLS"); cout << "\n\n\tThank you for testing the program.\n\t I hope it's to your liking!\n\n"; sleep(2);}
};

int main()
{
  AccountManager player;
  int choice;
  cout << "\n\t_______R e v e r i e_______\n" << "\n\n\n\t 1. Login\n\t 2. Create an Account\n\t 3. Exit\n\n";
  cout << "\n\n\tGo to: " ; cin >> choice; cout << endl;
  switch(choice)
    {
    case 1:
    system("CLS");
    player.login();
    break;
    case 2:
    system("CLS");
    player.registration();
    main();
    break;
    case 3:
    player.leave();
    break;
    default:
    system("CLS");
    cout<< "\n\t\t I'm sorry.\n\tIt was not in the given choices.\n\t\t Try again?" << endl;
    main();
    }
}
