#include<iostream>
#include<cstring>
using namespace std ;
class Bank{
    private:      // access specifiers 
    int id ;
    string name ;
    int balance ;
    string acc_type ;
    public:         // access specifiers 
    Bank(){           // constructor 
        id = 3 ;
        name = "Nammu" ;
        balance = 1000 ;
        acc_type = "savings" ;
    }
    Bank(int id_){           // constructor 
        id = id_ ;
        name = "Nammu" ;
        balance = 1000 ;
        acc_type = "savings" ;
    }
    int getid(){        // Here we are declaring and implementing both are done over here itself 
        return this->id ;
    }
    int getbalance(){
        return this->balance ;
    }
    string getname(){
        return this->name ;
    }

    void deposit(int amount) ;      // just declraing but not implementing 

    void change_acc_type(string in) ;   // just declraing but not implementing, 
};

void Bank :: deposit(int amount){              // Implementation is done over here by this syntax do not change the input parameter names
    this->balance = this->balance + amount ;
    return ;
}
void Bank ::  change_acc_type(string in){
    this->acc_type = in ;
    return ;
}
int main(){
    Bank b ;         // when constructor not taking any inputs we need to just say b, but not b()
    cout<<b.getid()<<endl ;
    cout<<b.getbalance()<<endl ;
    cout<<b.getname()<<endl ;
    b.deposit(1000) ;
    cout<<b.getbalance()<<endl;
    Bank a(6) ;
    cout<<a.getid()<<endl ;
    cout<<a.getbalance()<<endl ;
    cout<<a.getname()<<endl ;
    a.deposit(1000) ;
    cout<<a.getbalance()<<endl;
    return 0 ;
}
