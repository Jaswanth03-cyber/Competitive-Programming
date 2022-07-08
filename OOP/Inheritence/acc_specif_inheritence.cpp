/*
This file is just to get an idea on the access specifiers and the functions.
*/
class A {
public:
  int x;
  void func() ;

protected:
  int y;
  void funct() ;

private:
  int z;
  void function() ;
};

class B : public A {
/*
   x is public
   y is protected
   z is not accessible from B and also can not be accessed inside class B tooo 

   func() can be accessed inside class B and also can be accessed  by class B obj outside the class tooo
   funct() can be accessed inside the class B but can not be accessed outside the class by class B obj
   function() can not be accessed inside class B and also can not be accessed by class B obj outside the class tooo

*/
};

class C : protected A {
/*
   x is protected
   y is protected
   z is not accessible from C and also can not be accessed inside class C tooo 

   func() can be accessed inside class B but can not be accessed  by class B obj outside the class tooo as it will be protec
   funct() can be accessed inside the class B but can not be accessed outside the class by class B obj
   function() can not be accessed inside class B and also can not be accessed by class B obj outside the class tooo
*/

};

class D : private A{  //  'private' is default for classes, so even if we write class D : A{}; this is same as this 
/*
   x is private
   y is private
   z is not accessible from D and also can not be accessed inside class D tooo 

   func() can be accessed inside class B but can not be accessed  by class B obj outside the class tooo as it will be protec but here 
   the func() is private so can not be accessed by a class derived from D
   funct() can be accessed inside the class B but can not be accessed outside the class by class B obj
   function() can not be accessed inside class B and also can not be accessed by class B obj outside the class tooo but here 
   the func() is private so can not be accessed by a class derived from D
   
*/


};
