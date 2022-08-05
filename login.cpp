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



int main(){
    Signup();
    User user=User(username_,password_,securitycode_);
    Login();
    user.Login(username_,password_,securitycode_);
    if(user.getAuthorization()){
        cout << "Basarili";
    }

    

}