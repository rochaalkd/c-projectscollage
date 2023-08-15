#include"classes.h"
void Admin::Login() {
   
    
    string username;
    string password;
    system("cls");
    int n;
    ofstream otfile;
    ifstream ifile;

    cout << "\n1. Don't Have an Account (Sign Up): ";
    cout << "\n2. Already Have an Account? (Sign In): "<<endl;
    cin >> n;

    switch(n) {
        case 1:
            signup();
         
            
            break;

        case 2:
            signin();
            Homepage();
            break;

        default:
            cout << "\nPlease Select Correct option.";
    }
}
void Admin::signup(){
    ofstream otfile;
    ifstream ifile;
    string username;
    string password;
     int flag2=0;
    system("cls");

            otfile.open("Credintialsad.dat", ios::binary | ios::app);
            ifile.open("Credintialsad.dat", ios::binary | ios::in);

            cout << "Enter your Phone number to generate your username: ";
            cin >> username;
            if(username.length()==10){

            ifile.read((char *)&u1, sizeof(u1));
            while (!(ifile.eof())) {
                if (u1.username_comp() == username) {
                    flag2 = 1;
                    cout << "\nPhone Number Already Used.";
                    cout << "Please Use Another username." << endl;
                    cout<<"\nPress any key to return to agiain restart your journey.";
                    getch();
                    break;
                }
                ifile.read((char *)&u1, sizeof(u1));
            }

            if (flag2 == 0) {
                cout << "\nYou Can Use This Phone Number As Username.";
                u1.getinfo();
                otfile.write((char *)&u1, sizeof(u1));
              
            }
            

            ifile.close();
            otfile.close();
            Login();
            }
            else{
                cout<<"Phone number must be of 10 digits."<<endl;
                cout<<"Press any key to return to Login page"<<endl;
                getch();
                Login();
            }

}
void Admin::signin(){
    char ch;
    ofstream ofile;
    ifstream ifile;
     int flag=0;
     string username;
     string password;
    system("cls");
            cout << "Username: ";
            cin >> username;
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

            ifile.open("Credintialsad.dat", ios::binary | ios::in);
            ifile.read((char *)&u1, sizeof(u1));

            while (!ifile.eof()) {
                if (u1.username_comp() == username && u1.password_comp() == password) {
                   
                    
                    flag = 1;
                    cout << "LogIn Successful";
                    cout << "\nPress any key to continue...";
                    getch();
                    Homepage();
                    break;
                }
                ifile.read((char *)&u1, sizeof(u1));
            }

            if (flag == 0) {
                cout << "\nUsername and Password didn't match";
                cout<<"\nPress any key to try again....";
                getch();
                Login();
            }

            ifile.close();
           

}
void Admin::Homepage() {
    int n;
    system("cls");
    string s="--------------------- WELCOME ADMIN -----------------------------------";
    for(int i=0;i<s.length();i++){
        Sleep(100);
        cout<<s[i];
        
    }
    Sleep(1000);
    cout<<"\n1.Add Products in the stores."<<endl;
    cout<<"\n2.See Products in the stores."<<endl;
    cout<<"\n3.Exit"<<endl;
    cin>>n;
    switch(n){
        case 1:
        addrecord();
        Homepage();

        case 2:
        seeproduct();
        Homepage();

        case 3:
        cout<<"Terminating........";
        Sleep(1000);
        exit(4);

        default:
         cout<<"Enter Correct Option";
         Homepage();


         
          
    }

}
void Admin::addrecord(){
    int n;
    cout<<"\n1.Store 1";
    cout<<"\n2.Store 2";
    cout<<"\n3.Store 3"<<endl;
    cout<<"\n4.Go Back"<<endl;
    cin>>n;
    switch(n){

        case 1:
          diskwrite("store1.dat");
          addrecord();

        case 2:
        diskwrite("store2.dat");
        addrecord();

        case 3:
        diskwrite("stre3.dat");
        addrecord();


        case 4:
        Homepage();

        default:
           cout<<"\nUnmatched Choice";
           break;



    }
    
}
void Admin::seeproduct(){
    int n;
    cout<<"\n1.Store 1";
    cout<<"\n2.Store 2";
    cout<<"\n3.Store 3"<<endl;
    cin>>n;
    switch(n){
        case 1:
          cout<<"----------------------------------------------------------------------\n";
          cout<<setw(6)<<"Code"<<setw(15)<<"Name"<<setw(20)<<"Quantity"<<setw(8)<<"Price"<<endl;
          cout<<"-----------------------------------------------------------------------\n";
          diskread("store1.dat");

          cout<<"Press any Key to return back......";
          getch();
          Homepage();

        case 2:
          cout<<"----------------------------------------------------------------------\n";
          cout<<setw(6)<<"Code"<<setw(15)<<"Name"<<setw(20)<<"Quantity"<<setw(8)<<"Price"<<endl;
          cout<<"-----------------------------------------------------------------------\n";
          diskread("store2.dat");
          cout<<"Press any Key to return back......";
          getch();
          Homepage();


        case 3:
          cout<<"----------------------------------------------------------------------\n";
          cout<<setw(6)<<"Code"<<setw(15)<<"Name"<<setw(20)<<"Quantity"<<setw(8)<<"Price"<<endl;
          cout<<"-----------------------------------------------------------------------\n";
          diskread("store3.dat");
          cout<<"Press any Key to return back......";
          getch();
          Homepage();


        default:
        break;
    }
}

void Admin::diskwrite(string st){
    char ch;
    ofstream ofile;
    ofile.open(st,ios::app|ios::out);
    do{
        p1.getinfo();
        ofile.write((char *)&p1,sizeof(p1));
        cout<<"Add other records: [y/n]?";
        cin>>ch;

    }while(ch=='y'||ch=='Y');
    ofile.close();


}
void Admin::diskread(string sn){
    ifstream infile;
    infile.open(sn,ios::app|ios::in);
    infile.read((char *)&p1,sizeof(p1));
    while((!infile.eof())){
        p1.putinfo();
        infile.read((char *)&p1,sizeof(p1));

    }
    infile.close();




}
