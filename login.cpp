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
    string getPassword(){
        return password;
    }
    User(string Username,string Password,int Securitycode){
        username=Username;
        password=Password;
        Securitycode=securitycode;
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

int main(){
    cout << "Start";
    Signup();
    User user=User(username_,password_,securitycode_);

}