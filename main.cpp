#include"headers.h"
#include"classes.h"
#include"admin.h"
#include"customer.h"

using namespace std;

int main() {
    Admin a1;
    Customer c1;
  char ch;
  cout<<"\n a.Enter as Admin";

  cout<<"\nb.Enter as Customer"<<endl;
  cin>>ch;
  switch(ch){
    case 'a':
       a1.Login();

    case 'b':
       c1.Login();



    default:
    cout<<"Enter a valid option";

 }
 return 0;

}