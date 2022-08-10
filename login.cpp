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

    void Signup(string Username,string Password,int Securitycode){
        username=Username;
        password=Password;
        securitycode=Securitycode;
    }
    void Login(string username_,string password_,int securitycode_){
        if(username==username_ and password==password_){
          login_check=true;
        }
        else{
            login_check=false;
        }
    }
    void AdminLogin(string username_,string password_,int securitycode_){
        if(admin_username==username_ && admin_password==password_){
          admin_check=true;
        }
        else{
            admin_check=false;
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
    void LockUserAuthorization(){
        login_check=false;
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
                cout << "Username basariyle degistirildi ! >> Yeni username :" << current_username << endl;
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
            cout << "Mevcut Admin username:";
            cin>> current_username;
            cout << "Mevcut Admin password:";
            cin>> current_password;
            if(hak>3){
                break;
            }
            if(current_username!=admin_username || current_password!=admin_password){
                cout << "Mevcut Admin username ya da Admin password hatali !" << endl;
                hak++;
                goto AdminAccountUsernameChange_setup;
            }
            else{
                cout << "Yeni Admin password:";
                cin >> current_password;
                setAdminPassword(current_password);
                cout << "Admin Password basariyle degistirildi ! >> Yeni password :" << current_password << endl;
                free(current_username);
                free(current_password);
                break;

            }
        }
    }

    void UserAccountUsernameChange()
    {
        char *current_username;current_username=(char*)malloc(8*sizeof(char));
        char *current_password;current_password=(char*)malloc(8*sizeof(char));
        int hak=0;
        while(hak<3){
            AdminAccountUsernameChange_setup:
            if(hak>3){
                break;
            }
            if(getAuthorization()){
                cout << "Mevcut username:";
                cin>> current_username;
                cout << "Mevcut password:";
                cin>> current_password;
                if(current_username!=username || current_password!=password){
                    cout << "Mevcut username ya da password hatali !" << endl;
                    hak++;
                    goto AdminAccountUsernameChange_setup;
                }
                else{
                    cout << "Yeni username:";
                    cin >> current_username;
                    setUsername(current_username);
                    cout << "Username basariyle degistirildi ! >> Yeni username :" << current_username << endl;
                    free(current_username);
                    free(current_password);
                    break;
                }
            }
            else if(getAdminAuthorization()){
                cout << "Mevcut Admin username:";
                cin>> current_username;
                cout << "Mevcut Admin password:";
                cin>> current_password;
                if(current_username!=admin_username || current_password!=admin_password){
                    cout << "Mevcut Admin username ya da Admin password hatali !" << endl;
                    hak++;
                    goto AdminAccountUsernameChange_setup;
                }
                else{
                    cout << "Yeni username:";
                    cin >> current_username;
                    setUsername(current_username);
                    cout << "Username basariyle degistirildi ! >> Yeni username :" << current_username << endl;
                    free(current_username);
                    free(current_password);
                    break;
                }
            }
        }
    }

    void UserAccountPasswordChange()
    {
        char *current_username;current_username=(char*)malloc(8*sizeof(char));
        char *current_password;current_password=(char*)malloc(8*sizeof(char));
        int hak=0;
        while(hak<3){
            AdminAccountUsernameChange_setup:
            if(hak>3){
                break;
            }
            if(getAuthorization()){
                cout << "Mevcut username:";
                cin>> current_username;
                cout << "Mevcut password:";
                cin>> current_password;
                if(current_username!=username || current_password!=password){
                    cout << "Mevcut username ya da password hatali !" << endl;
                    hak++;
                    goto AdminAccountUsernameChange_setup;
                }
                else{
                    cout << "Yeni password:";
                    cin >> current_password;
                    setPassword(current_password);
                    cout << "Password basariyle degistirildi ! >> Yeni password :" << current_password << endl;
                    free(current_username);
                    free(current_password);
                    break;

                }
            }
            else if(getAdminAuthorization()){
                cout << "Mevcut Admin username:";
                cin>> current_username;
                cout << "Mevcut Admin password:";
                cin>> current_password;
                if(current_username!=admin_username || current_password!=admin_password){
                    cout << "Mevcut username ya da password hatali !" << endl;
                    hak++;
                    goto AdminAccountUsernameChange_setup;
                }
                else{
                    cout << "Yeni password:";
                    cin >> current_password;
                    setPassword(current_password);
                    cout << "Password basariyle degistirildi ! >> Yeni password :" << current_password << endl;
                    free(current_username);
                    free(current_password);
                    break;

                }   
            }
        }
    }
};


void sss(){
    for(int i=0;i<30;i++){
        cout << "=";
    }
    cout << endl;
}

bool passwordCheck(string news){
    passwordCheck:
    int i=0,j=0;
    int upper_case=0;
    int lower_case=0;
    int number=0;
    int special_ch=0;
    int space_ch=0;
    bool check=false;
    while(news[i]!='\0'){
        if(islower(news[i])){
            lower_case++;
        }
        if(isupper(news[i])){
            upper_case++;
        }
        if(isspace(news[i])){
            space_ch++;
        }
        if(isdigit(news[i])){
            number++;
        }
        if(ispunct(news[i])){
            special_ch++;
        }
        j++; 
        i++;   
    }
    if(space_ch>0 || lower_case<1 || upper_case<1 || number<1 || special_ch<1){
        // cout << "Hatali parola ! >> Parolada bosluk olamaz - En az 1 buyuk/kucuk harf, rakam ve noktalama isareti olmasi gerekir" << endl;
        check=false;
    }
    else{
        check=true;
    }
    return check;
}
void Signup(){
    int hata=0;
    cout << "\tSign-up Screen" << endl;
    cout << "Enter username:";
    cin >> username_;
    cout << "Enter password:";
    cin >> password_;
    if(username_.size()<5 || password_.size()<5 || passwordCheck(password_)==0){
        sss();
        cout << "Username ve Password 5 harften kucuk olamaz" <<endl;
        cout << "En az 1 buyuk harf,kucuk harf,rakam,ozel karakter kullanmak zorunludur"<<endl;
        sss();
        hata=1;
    }
    if(hata==1)Signup();
    if(hata==0){cout << "Enter security code:";
    cin >> securitycode_;}
    cout << "Kayit basarili !" <<endl;
    Sleep(600);
}

void BackorMain(){
    cout << endl;
    cout << endl;
    sec=0;
    cout <<"[1]Geri gel" <<endl;
    cout <<"[2]Ana menu" <<endl;
    cout <<":";
    cin >> sec;

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
    sec=0;
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
    cout << "3-Geri gel" << endl;
    cout << "4-Ana menu" << endl;
    cout << ":" <<endl;
    cin >> sec;
}

void LoginMenu(){
    sec=0;
    cout << "[1]Hesap ayarlari" <<endl;
    cout << "[2]Ana menu"<<endl;
    cout << ":";
    cin >> sec;
}

void UserAccountSettingsChanges(){
    sec=0;
    cout << "[1]Username degistir" << endl;
    cout << "[2]Password degistir" << endl;
    cout << "[3]Geri gel" << endl;
    cout << "[4]Ana menu" << endl;
    cout << ":" ;
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
    //User user=User(username_,password_,securitycode_);
    User user;
    user.setAdminUsername("admin");
    user.setAdminPassword("admin");
    menu_setup:
    system("cls");
    int menu_secim;
    int secim=0;
    user.LockAdminAuthorization();
    user.LockUserAuthorization();
    menu_secim=0;
    main_menu();
    cin >> menu_secim;
    while(menu_secim!=0){
        switch(menu_secim){
            case 1:
                system("cls");
                Signup();
                user.Signup(username_,password_,securitycode_);
                goto menu_setup;
                break;
            case 2:
                system("cls");
                user.LockAdminAuthorization();
                Login();
                user.Login(username_,password_,securitycode_);
                if(user.getAuthorization()){
                    cout <<"Giris basarili"<<endl;
                    Sleep(600);
                    login_menu:
                    system("cls");
                    LoginMenu();
                    switch(sec){
                        case 1:
                            Sleep(600);
                            useraccountsetting_menu:
                            system("cls");
                            UserAccountSettingsChanges();
                            if(sec==1){
                                user.UserAccountUsernameChange();
                            }
                            else if(sec==2){
                                user.UserAccountPasswordChange();
                            }
                            else if(sec==3){
                                goto login_menu;
                            }
                            else if(sec==4){
                                goto menu_setup;
                            }
                            else{
                               goto useraccountsetting_menu; 
                            }
                            break;
                        case 2:
                            break;
                        default:
                            goto login_menu;
                    }
                }
                else if(user.getAuthorization()==0){
                    cout << "Member not find"<<endl;
                }
                Sleep(600);
                goto menu_setup;
                break;
            case 3:
                exit(0);
                break;
            case 4: //Admin management system
                system("cls");
                user.LockUserAuthorization();
                AdminLogin();
                user.AdminLogin(username_,password_,securitycode_);
                if(user.getAdminAuthorization()){
                    admin_setup:
                    system("cls");
                    AdminPanel(); // Admin panel seçim menusu
                    switch(sec){ // Admin panel işlem seçim.
                        case 1:
                            system("cls");
                            cout << "============Kayitli olan uyeler============" <<endl;
                            cout << user.showUsers() << "                     " << user.getPassword() << endl;
                            BackorMain();
                            if(sec==1)goto admin_setup;
                            if(sec==2)goto menu_setup;
                            break;
                        case 2:
                            system("cls");
                            cout << "Kullanici adi degistir" << endl;
                            user.UserAccountUsernameChange();
                            break;
                        case 3:
                            system("cls");
                            cout << "Parola degistir" << endl;
                            user.UserAccountPasswordChange();
                        case 4:
                            system("cls");
                            cout << "Admin hesap ayarlarini degistir" << endl;
                            AdminAccountSettingsChanges();
                            if(sec==1){
                                user.AdminAccountUsernameChange();
                            }
                            else if(sec==2){
                                user.AdminAccountPasswordChange();
                            }
                            else if(sec==3){
                                goto admin_setup;
                            }
                            else if(sec==4){
                                goto menu_setup;
                            }
                        case 5:
                            cout << "Ana menuye don" << endl;
                        default:
                            break;
                    }
                }
                else{
                    cout << "Hatali username ya da parola" << endl;
                    Sleep(600);
                }
                goto menu_setup;
                break;
            default:
                break;
        }
    }


    return 0;
}