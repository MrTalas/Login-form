#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

string username_;
string password_;
int securitycode_;



class User{
private:
    string username;
    string password;
    int securitycode;
    string admin_username="admin";
    string admin_password="admin";
    int admin_securitycode=0000;
    bool admin_check=false;
public:
    bool login_check=false;
    bool getAuthorization(){
        return login_check;
    }
    bool getAdminAuthorization(){
        return admin_check;
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
        if(username==username_ and password==password_){
          login_check=true;
        }
    }
    void AdminLogin(string username_,string password_,int securitycode_){
        if(admin_username==username_ and admin_password==password_){
          admin_check=true;
        }
    }
    void setUsername(string username_){
        username=username_;
    }
    void setPassword(string password_){
        password=password_;
    }
    void setSecurityCode(int securitycode_){
        securitycode=securitycode_;
    }
};


void sss(){
    for(int i=0;i<50;i++){
        cout <<i;
    }
    cout <<endl;
    Sleep(1000);
    for(int i=50;i>0;i--){
        cout << i;
    }
}
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

void AdminLogin(){
    cout << "\tAdmin Login System Screen" << endl;
    cout << "Enter admin username:";
    cin >> username_;
    cout << "Enter admin password:";
    cin >> password_;
    cout << "Enter admin security code:";
    cin >> securitycode_;  
}

void AdminPanel(){
    int sec;
    cout << "\tAdmin paneline hosgeldiniz"<<endl;
    cout << "1-Kayitli uyeleri goruntule" << endl;
    cout << "2-Kullanici adi degistir" << endl;
    cout << "3-Parola degistir" <<endl;
    cout << "4-Admin hesap ayarlarini degistir"<<endl;
    cin >>sec;
}


inline void main_menu(){
    for(int i=0;i<30;i++){
        cout << "=";
    }
    cout << endl;
    cout << "\tLogin System V1" << endl;
    cout << "1-Sign up" << endl;
    cout << "2-Login" << endl;
    cout << "3-Quit" << endl;
    cout << "4-Admin Management System" <<endl;
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
                user=User(username_,password_,securitycode_);
                goto menu_setup;
                break;
            case 2:
                Login();
                user.Login(username_,password_,securitycode_);
                if(user.getAuthorization()){
                    cout <<"Giris basarili";
                }
                else if(user.getAuthorization()==0){
                    cout << "Member not find";
                }
                goto menu_setup;
                break;
            case 3:
                exit(0);
                break;
            case 4:
                AdminLogin();
                user.AdminLogin(username_,password_,securitycode_);
                if(user.getAdminAuthorization()){
                    AdminPanel();
                }
                goto menu_setup;
                break;
            default:
                break;
        }
    }



    
    return 0;
}