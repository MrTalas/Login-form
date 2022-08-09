#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

string username_;
string password_;
int securitycode_;
int sec;

class User{
private:
    string username;
    string password;
    int securitycode;
    string admin_username;
    string admin_password;
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
    string getAdminUsername(){
        return admin_username;
    }

    string getAdminPassword(){
        return admin_password;
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
        if(admin_username==username_ && admin_password==password_){
          admin_check=true;
        }
    }
    void setAdminUsername(string username_){
        admin_username=username_;
    }
    void setUsername(string username_){
        username=username_;
    }
    void setPassword(string password_){
        password=password_;
    }
    void setAdminPassword(string password_){
        admin_password=password_;
    }
    void setSecurityCode(int securitycode_){
        securitycode=securitycode_;
    }
    void LockAdminAuthorization(){
        admin_check=false;
    }
    string showUsers(){
        return username;
    }
    void AdminAccountUsernameChange()
    {
        char *current_username;current_username=(char*)malloc(8*sizeof(char));
        char *current_password;current_password=(char*)malloc(8*sizeof(char));
        int hak=0;
        while(hak<3){
            AdminAccountUsernameChange_setup:
            cout << "Mevcut username:";
            cin>> current_username;
            cout << "Mevcut password:";
            cin>> current_password;
            if(hak>3){
                break;
            }
            if(current_username!=admin_username || current_password!=admin_password){
                cout << "Mevcut username ya da password hatali !" << endl;
                hak++;
                goto AdminAccountUsernameChange_setup;
            }
            else{
                cout << "Yeni username:";
                cin >> current_username;
                setAdminUsername(current_username);
                setAdminPassword(current_password);
                free(current_username);
                free(current_password);
                break;

            }
        }
    }
    void AdminAccountPasswordChange()
    {
        char *current_username;current_username=(char*)malloc(8*sizeof(char));
        char *current_password;current_password=(char*)malloc(8*sizeof(char));
        int hak=0;
        while(hak<3){
            AdminAccountUsernameChange_setup:
            cout << "Mevcut username:";
            cin>> current_username;
            cout << "Mevcut password:";
            cin>> current_password;
            if(hak>3){
                break;
            }
            if(current_username!=admin_username || current_password!=admin_password){
                cout << "Mevcut username ya da password hatali !" << endl;
                hak++;
                goto AdminAccountUsernameChange_setup;
            }
            else{
                cout << "Yeni password:";
                cin >> current_password;
                setAdminUsername(current_username);
                setAdminPassword(current_password);
                free(current_username);
                free(current_password);
                break;

            }
        }
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
    cout << "\tAdmin paneline hosgeldiniz"<<endl;
    cout << "1-Kayitli uyeleri goruntule" << endl;
    cout << "2-Kullanici adi degistir" << endl;
    cout << "3-Parola degistir" <<endl;
    cout << "4-Admin hesap ayarlarini degistir"<<endl;
    cout << "5-Ana menuye don" << endl;
    cout << ":" <<endl;
    cin >>sec;
}

void AdminAccountSettingsChanges(){
    cout << "\tAdmin Hesap Ayarlari" << endl;
    cout << "1-Username degistir" <<endl;
    cout << "2-Parola degistir" << endl;
    cout << "3-Ana menuye don" << endl;
    cout << ":" <<endl;
    cin >> sec;
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
    user.setAdminUsername("admin");
    user.setAdminPassword("admin");
    int menu_secim;
    int secim;
    menu_setup:
    user.LockAdminAuthorization();
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
                    AdminPanel(); // Admin panel seçim menusu
                    switch(sec){ // Admin panel işlem seçim.
                        case 1:
                            cout << "============Kayitli olan uyeler============" <<endl;
                            cout << user.showUsers() << "                     " << user.getPassword() << endl;
                            break;
                        case 2:
                            cout << "Kullanici adi degistir" << endl;
                        case 3:
                            cout << "Parola degistir" << endl;
                        case 4:
                            cout << "Admin hesap ayarlarini degistir" << endl;
                            AdminAccountSettingsChanges();
                            if(sec==1){
                                user.AdminAccountUsernameChange();
                            }
                            else if(sec==2){
                                user.AdminAccountPasswordChange();
                            }
                            else if(sec==3){
                                goto menu_setup;
                            }
                        case 5:
                            cout << "Ana menuye don" << endl;
                        default:
                            break;
                    }
                }
                goto menu_setup;
                break;
            default:
                break;
        }
    }


    return 0;
}