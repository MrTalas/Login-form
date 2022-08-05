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
        Securitycode=securitycode;
    }
    void Login(string Uusername,string Ppassword,int Ssecuritycode){
        if(username==Uusername and password==Ppassword){
          login_check=true;
        }
    }
};

void Signup(){
    cout << "\tSign-up Screen" << endl;
    cout << "Enter username:";
    cin >> username_;
    cout << "Enter password:";
    cin >> password_;
    cout << "Enter security code:";
    cin >> securitycode_;
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
    cout << "Start";
    Signup();
    User user=User(username_,password_,securitycode_);
    Login();
    user.Login(username_,password_,securitycode_);
    if(user.getAuthorization()){
        cout << "Basarili";
    }
    

}