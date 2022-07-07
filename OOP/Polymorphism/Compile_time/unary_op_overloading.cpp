#include<iostream>
using namespace std ;
class Weight{
    private:
    int weight ;
    public:
    Weight(){
        weight = 0 ;
    }
    Weight(int a){
        weight = a ;
    }
    void display(){
        cout<<"The weight is : "<<weight  ;
    }

    Weight operator ++ (){
        Weight temp ;
        temp.weight = weight++ ;
        return temp ;
    }
    // we added int to make difference for above and this we can even write Weight operator ++(int) but can not write void
    Weight operator ++ (int a){  
        Weight temp ;   
        temp.weight = ++weight ;
        return temp ;      
    }
    Weight operator -- (){
        Weight temp ;
        temp.weight = weight-- ;
        return temp ;
    }
    // we added int to make difference for above and this we can even write Weight operator --(int) but can not write void
    Weight operator -- (int b){ 
        Weight temp ;
        temp.weight = --weight ;   
        return temp ;                        
    }
};
int main(){
    Weight obj1(1) ;
    Weight obj2(3) ;
    Weight obj3(6) ;
    Weight obj4(9) ;
    int x = 2 ;
    int y ;
    y = x++ ;
    cout<<y<<" "<<x<<endl ;
    int z = 2 ;
    int w ;
    w = ++z ;
    double n = 9.9 ;
    n++ ;
    cout<<n<<endl ;
    cout<<w<<" "<<z<<endl ;        // observe the difference similarly for - 
    // obj1++ ;
/*
this gives a compile time error we did not define unary operator ++/-- for these type of obj only defined 
for numeric primitive data types
so we define for them too using operator overloading 
*/
    Weight obj5 = obj1++ ;
    Weight obj6 = ++obj2 ;
    Weight obj7 = obj3-- ;
    Weight obj8 = --obj4 ;

    obj1.display() ;
    cout<<" " ;
    obj5.display() ;
    cout<<endl ;

    obj2.display() ;
    cout<<" " ;
    obj6.display() ;
    cout<<endl ;

    obj3.display() ;
    cout<<" " ;
    obj7.display() ;
    cout<<endl ;

    obj4.display() ;
    cout<<" " ;
    obj8.display() ;
    cout<<endl ;


    /*
    If u just want 
    obj1++ ;

    return type should be void

    void operator ++(){
        weight++ ;
    }
    */

    return 0 ;
}