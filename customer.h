#include"classes.h"

void Customer::Login(){
    string username;
    string password;
    
   
    
    system("cls");
    int n;
    ofstream otfile;
    ifstream ifile;

    cout << "\n1. Don't Have an Account (Sign Up): ";
    cout << "\n2. Already Have an Account? (Sign In): "<<endl;
    cin >> n;

    switch (n) {
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
void Customer::signup(){
     ofstream otfile;
    ifstream ifile;
    string username;
    string password;
     int flag2=0;
    system("cls");

            otfile.open("Credintialscu.dat", ios::binary | ios::app);
            ifile.open("Credintialscu.dat", ios::binary | ios::in);

            cout << "Enter your Phone number to generate your username: ";
            cin >> username;
            if(username.length()==10){

            ifile.read((char *)&u, sizeof(u));
            while (!(ifile.eof())) {
                if (u.username_comp() == username) {
                    flag2 = 1;
                    cout << "\nPhone Number Already Used.";
                    cout << "Please Use Another username." << endl;
                    cout<<"\nPress any key to  restart your journey.";
                    getch();
                    break;
                }
                ifile.read((char *)&u, sizeof(u));
            }

            if (flag2 == 0) {
                cout << "\nYou Can Use This Phone Number As Username.";
                u.getpersonalinfo();
                u.getinfo();
                otfile.write((char *)&u, sizeof(u));
              
            }
            

            ifile.close();
            otfile.close();
            cout<<"\nAccount Created Successfully........";
            cout<<"\nPlease wait 2 seconds while you are redirected to the login page.";
            Sleep(2000);
            Login();
            }
            else{
                cout<<"Phone number must be of 10 digits."<<endl;
                cout<<"Press any key to return to Login page"<<endl;
                getch();
                Login();
            }


}
void Customer::signin(){
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
        cout<<endl;
     
    


            

            ifile.open("Credintialscu.dat", ios::binary | ios::in);
            ifile.read((char *)&u, sizeof(u));

            while (!ifile.eof()) {
                if (u.username_comp() == username && u.password_comp() == password) {
                    
                    
                    flag = 1;
                    this->userfile=username;
                    cout << "LogIn Successful";
                    cout << "\nPress any key to continue...";
                    getch();
                    Homepage();
                    break;
                }
                ifile.read((char *)&u, sizeof(u));
                
            }

            if (flag == 0) {
                cout<<username;
                cout << "\nUsername and Password didn't match";
                cout<<"\nPress any key to try again....";
                getch();
                Login();
            }

            ifile.close();


}
void Customer::Homepage(){
       int n;
    system("cls");
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Sleep(100);
     SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    
    cout<<"-------------------------------------";
    string s="WELCOME  TO CONSOLE BAAZAR ";
    for(int i=0;i<s.length();i++){
        cout<<s[i];
        Sleep(100);
    }
    cout<<"--------------------------------------";
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

 
   
    cout<<endl;
    Sleep(1000);
    cout<<"\n1.Start Shopping"<<endl;
    cout<<"\n2.Generate Bill"<<endl;
    cout<<"\n3.See your Previous Buyings"<<endl;
    cout<<"\n4.Exit"<<endl;
    cin>>n;
    switch(n){
        case 1:
       StartShopping();
        Homepage();

        case 2:
       generatebill(userfile);
        Homepage();

        case 3:
        previoushist();
        Homepage();

 
        case 4:
        exit(3);

         
          
    }

}
void Customer::StartShopping(){
    system("cls");
    
    cout<<"\n1.Store 1";
    cout<<"\n2.Store 2";
    cout<<"\n3.Store 3"<<endl;
    cout<<"\n4.Return to Home Page"<<endl;
    cout<<"Choose The Store To Buy The Products"<<endl;
    int n;
    cin>>n;
    switch(n){
        case 1:
        cout<<"----------------------------------------------------------------------\n";
          cout<<setw(6)<<"Code"<<setw(15)<<"Name"<<setw(20)<<"Quantity"<<setw(8)<<"Price"<<endl;
          cout<<"-----------------------------------------------------------------------\n";
          BuyingStore("store1.dat");
          StartShopping();

        case 2:
        cout<<"----------------------------------------------------------------------\n";
          cout<<setw(6)<<"Code"<<setw(15)<<"Name"<<setw(20)<<"Quantity"<<setw(8)<<"Price"<<endl;
          cout<<"-----------------------------------------------------------------------\n";
          BuyingStore("store2.dat");
          StartShopping();

        case 3:
        cout<<"----------------------------------------------------------------------\n";
          cout<<setw(6)<<"Code"<<setw(15)<<"Name"<<setw(20)<<"Quantity"<<setw(8)<<"Price"<<endl;
          cout<<"-----------------------------------------------------------------------\n";
          BuyingStore("store3.dat");
          StartShopping();

        case 4:
            Homepage();

          default:
          cout<<"Please Choose a valid option";
          getch();
          StartShopping();


          

          
          
    }





}
void Customer::BuyingStore(string sn){
    int flag=0;
    char ch;
    int code;
   
     ifstream infile;
     ofstream otfile;
    infile.open(sn,ios::app|ios::in);
    infile.read((char *)&p,sizeof(p));
    while((!infile.eof())){
        p.putinfo();
        infile.read((char *)&p,sizeof(p));

    }
    infile.close();
    cout<<endl;
    do{
        ShoppingProduct(sn);
        cout<<"Buy More Products From This Store:[y/n] "<<endl;
        cin>>ch;
    
            


        }while(ch=='y'||ch=='Y');
        
    
    }


    


void Customer::ShoppingProduct(string st) {
    string name;
    float price;
    int num;
    
    int flag = 0;
    int code;
    char ch;
    ifstream infile;
    ofstream otfile;

    cout << "Enter the Code of The Product You Would Like To Buy: ";
    cin >> code;
    cout << "Enter the quantity of The Product You Would Like To Buy: ";
    cin >> quantity;

    infile.open(st, ios::binary | ios::in);
    otfile.open(userfile + ".txt", ios::app | ios::binary);

    while (!infile.eof()) {
        infile.read((char*)&p, sizeof(p));
        if (p.code_ret() == code) {
            flag = 1;
            if(quantity>p.quantity){
                cout<<endl<<"Not Enough Quantity.";
                cout<<"Press BackSpace to move backwards "<<endl;
                getch();
                StartShopping();
            }
            num=p.quantity-quantity;
            code=p.code;
            name=p.name;
            price=p.price; 
            otfile<<'\t'<<code<<'\t';
            otfile<<'\t'<<name<<'\t';
            otfile<<'\t'<<price<<'\t';
            otfile<<'\t'<<quantity<<'\t';
            otfile<<endl;
            sum+=quantity*price;
        }
        update(st,code,num);

    }

    infile.close();
    otfile.close();

    if (flag == 0) {
        cout << "Product with that code doesn't exist." << endl;
        cout<<"Press any key to return to continue to store"<<endl;
        getch();


    }
}
void Customer::update(string st,int c,int q){
    

    fstream file;
    file.open(st,ios::binary |ios::in |ios::out);
    if(!file){
        cout<<st;
        cout<<"File Doesn't Exists"<<endl;
        getch();
    }
    while(file.read((char*)&p,sizeof(p))){
        if(p.code_ret()==c){
            p.update_quantity(q);
            int pos=sizeof(p);
            file.seekp(-pos,ios::cur);
            file.write((char *)&p,sizeof(p));
        }




    }
    file.close();

    











}
void Customer::generatebill(string st){
    string name;
    float price;
    
    int flag = 0;
    int code;
    char ch;
    string line;
    ifstream infile;
    ofstream otfile;
    string username=st+".txt";
    const char *cptr=username.c_str();
    

   
   otfile.open(st +"his.txt",ios::app);
    infile.open( st +".txt",ios::in);
   

    infile.seekg(0,ios::end);
    if(infile.tellg()==0){
        cout<<"You Haven't Bought any Product From Our Store.";
        cout<<endl;
        cout<<"First Buy Some Products From Our Store.";
        StartShopping();

    }
    infile.seekg(0,ios::beg);
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"\tCode\t\tName\t\tPrice\t\tQuantity\t"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
   while (std::getline(infile, line)) {
        std::cout << line << std::endl; 
        otfile<<line<<endl;
       
    }
    cout<<"\t\t\t\t\t\t\t\tTotal : "<<sum;
    
  
    infile.close();
    remove(cptr);
    

    otfile.close();
    
     getch();
    











}
void Customer::previoushist(){
    
    ifstream infile;
    string line;
    infile.open(userfile +"his.txt",ios::in);
    if(!(infile.good())){
        cout<<"You Don't Have  Any Buying History"<<endl;
        cout<<"Press BackSpace to move to previous page";
        getch();
        Homepage();

    }
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout <<userfile<<"   Your History So Saved Here Are: " << std::endl;

    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
  cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"\tCode\t\tName\t\tPrice\t\tQuantity\t"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
      while (std::getline(infile, line)) {
        std::cout << line << std::endl; 
        
       
    }
    getch();
    }