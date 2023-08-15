#include "headers.h"

using namespace std;
class Customer;
class Products{
    private:
    int code;
    char name[50];
    float price;
    int quantity;
    friend class Customer;
    

    public:
    void getinfo(){
        cout<<"Name of Product: ";
        cin>>name;
        cout<<"Price: ";
        cin>>price;
        cout<<"Quantity: ";
        cin>>quantity;
        cout<<"Code of product: ";
        cin>>code;
    }
    void putinfo(){
        cout<<setw(6)<<code<<setw(15)<<name<<setw(20)<<quantity<<setw(8)<<price<<endl;
    }
    int code_ret(){
        return code;
    }
    

};

class User{
    private: 
    char ch;
    string username;
    string password;
    string name;
    string address;
    friend class Admin;
    friend class Customer;
   

    public:
    void getpersonalinfo(){
        cout<<"\nName: ";
      cin>>name;
      cin.ignore();
       
        cout<<"\nAddress: ";
        cin>>address;
        cin.ignore();
         }

     void getinfo() {
       
    cout << "Username: ";
    cin >> username;
    
    
    if (username.length() == 10) {

        cout << "Password: ";
       
        
         while ((ch = getch()) != '\r') {
            if (ch == '\b') {
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b";
                }
            } else {
                password.push_back(ch);
                cout << '*';
            }
        }
        

       
    } 
    
    else {
        cout << "Username should be a phone number with 10 digits." << endl;
        exit(1);
    }
}

     string &username_comp(){
        return username;
     }
     string &password_comp(){
        return password;
     }


};
class Admin{
    User u1;
    Products p1;

  public: 
    void Login();
    void Homepage();
    void signup();
    void signin();
    void options();
    void addrecord();
    void diskwrite(string s);
    void diskread(string st);
    void seeproduct();

};
class Customer{
     float sum=0.0;
    int quantity;
    User u;
    Products p;
    Admin a;
    string userfile;

public:
void Login();
void signup();
void signin();
void Homepage();
void StartShopping();
void BuyingStore(string s);
void ShoppingProduct(string s);
};