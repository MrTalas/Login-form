#include <iostream>
#include <windows.h>

using namespace std;

string username_;
string password_;
int securitycode_;



class User{
private:
    string username;
    string password;
    int securitycode;
public:
    bool login_check=false;
    bool getAuthorization(){
        return login_check;
    }
    string getUsername(){
        return username;
    }
    string getPassword(){
        return password;
    }
    int getSecurityCode(){
        return securitycode;
    }
    User(string Username,string Password,int Securitycode){
        username=Username;
        password=Password;
        securitycode=Securitycode;
    }
    void Login(string username_,string password_,int securitycode_){
        if(username==username_ and password==password_ and securitycode==securitycode_){
          login_check=true;
        }
    }
};

void Signup(){
    int hata=0;
    cout << "\tSign-up Screen" << endl;
    cout << "Enter username:";
    cin >> username_;
    cout << "Enter password:";
    cin >> password_;
    if(username_.size()<5 || password_.size()<5){
        cout << "Username ve Password 5 harften kucuk olamaz" <<endl;
        hata=1;
    }
    if(hata==1)Signup();
    if(hata==0){cout << "Enter security code:";
    cin >> securitycode_;}
}

void Login(){
    cout << "\tLogin Screen" << endl;
    cout << "Enter username:";
    cin >> username_;
    cout << "Enter password:";
    cin >> password_;
    cout << "Enter security code:";
    cin >> securitycode_;  
}


void main_menu(){
    for(int i=0;i<30;i++){
        cout << "=";
    }
    cout << endl;
    cout << "\tLogin System V1" << endl;
    cout << "1-Sign up" << endl;
    cout << "2-Login" << endl;
    cout << "3-Quit" << endl;
    for(int i=0;i<30;i++){
        cout << "=";
    }
    cout << endl;
    cout << ": ";
}
int main(){
    User user=User(username_,password_,securitycode_);
    int menu_secim;
    menu_setup:
    menu_secim=0;
    main_menu();
    cin >> menu_secim;
    while(menu_secim!=0){
        switch(menu_secim){
            case 1:
                Signup();
                User(username_,password_,securitycode_);
                goto menu_setup;
                break;
            case 2:
                Login();
                user.Login(username_,password_,securitycode_);
                if(user.getAuthorization()){
                    cout << "Basarili";
                }
                break;
            case 3:
                system("quit");
                break;
            default:
                break;
        }
    }



    
    return 0;
}