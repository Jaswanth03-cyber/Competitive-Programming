#include<iostream>
#include<string.h>      
/* we have to use cstring/string.h for these functions strcpy() strcat() strlen() strcmp() otherwise string is fine
except for these four functions we can use either string.h or string or cstring
but if we are using these we must have cstring/string.h but not string
*/
using namespace std ;
int main(){

    /*
    many of the functions are similar to vectors 
    can be accessed as usual str[i]
    Append : Append to string (public member function )
    Push_back : Append character to string (public member function )
    Assign : Assign content to string (public member function )
    Insert : Insert into string (public member function )
    Erase : Erase characters from string (public member function )
    Replace : Replace portion of string (public member function )
    Swap : Swap string values (public member function )
    Pop_back : Delete last character (public member function )
    */

    string s = "hello this is jaswanth" ; // In strings we do not have null character at the end unlike character arrays 

    /*
        getline()   This function is used to store a stream of characters as entered by the user in the object memory.
        istream& getline(istream& is, string& str, char delim);
        Parameters: 
        is: It is an object of istream class and tells the function about the stream from where to read the input from.
        str: It is a string object, the input is stored in this object after being read from the stream.
        delim: It is the delimitation character which tells the function to stop reading further input after reaching this character.
        This is for character array
    */
    char y_name[60], y_address[60], about_y[60];
  
    cout << "Enter your name: "<<endl;
    cin.getline (y_name, 6);        // max length is 6 can not be more than that, if u exceed that takes upto 5 characters only as last one is for \0(null character)
    cout<<y_name<<endl ;
  
    cout << "Enter your City: "<<endl;
    // cin.getline (y_address, 60);
  
    cout << "Enter your profession (press $ to complete): "<<endl;
    // cin.getline (about_y, 60, '$');    //$ is a delimiter

    /* 
    For string istream& getline (istream& is, string& str);
    The second declaration is almost the same as that of the first one. The only difference is, this have an delimitation character which is by default newline(\n)character.
    Parameters: 
    is: It is an object of istream class and tells the function about the stream from where to read the input from.
    str: It is a string object, the input is stored in this object after being read from the stream.
    */
    string p ;
    cout<<"Give input via command line,you are taking input using get line and by default delimiter is new line"<<endl ;
    getline(cin,p) ;
    cout<<p<<endl ; // here by default delimiter is newline 
    cout<<endl ;

    /* push_back() This function is used to input a character at the end of the string.
    void string:: push_back (char c)
    Parameters:  Character which to be appended. 
    Return value: None
    Error: throws length_error if the 
    resulting size exceeds the maximum number of characters(max_size).

    s.push_back("hello") this does not work because its a char array we have to only provide character
    */
    
    s.push_back('$') ; // we can give space also as it is also a character  we can give a single character but not multiple
    cout<<s<<endl ;

    // pop_back() introduced from C++11(for strings), this function is used to delete the last character from the string. 

    s.pop_back() ;
    cout<<s<<endl ;


    /*
    capacity()	This function returns the capacity allocated to the string, which can be equal to or more than the size of the string.  
    Additional space is allocated so that when the new characters are added to the string, the operations can be done efficiently.
    resize()	This function changes the size of the string, the size can be increased or decreased.
    length()	This function finds the length of the string.
    shrink_to_fit()	This function decreases the capacity of the string and makes it equal to the minimum capacity of the string. This operation is useful to save additional memory if we are sure that no further addition of characters has to be made.
    */

    cout<<s.length()<<endl ;


    /*
    begin()	This function returns an iterator to the beginning of the string.
    end()	This function returns an iterator to the end of the string.
    rbegin()	This function returns a reverse iterator pointing at the end of the string.
    rend()	This function returns a reverse iterator pointing at beginning of the string.

    we can even have this instead of auto but anyway auto we use generally for vectors and other containers in stl library
    string::iterator it = s.begin() ;
    cout<<*it<<endl ;

    */

    auto g = s.begin() ; 

    // Returns a bidirectional  iterator pointing to the first element in the vector, its not of type int* or int 
    // so we write as auto so that during run time compiler finds the proper data type

    cout<<*g<<endl ;
    cout<<endl ;

    // cout<<*--g<<endl ;     this gives 0 as the output
    // int *t = s.begin() ;     this gives a compile time error
    // cout<<*s<<endl ;         this is an error

    // 1
    cout<<"1) " ;
    for(auto i = s.begin(); i != s.end(); i++){
        cout<<*i;
    }
    cout<<endl ;
    cout<<endl ;

    auto n = s.end() ; 

    //  Returns a bidirectional iterator pointing to the theoretical element that follows the last element in the vector, its not of type int* or int 
    // so we write as auto so that during run time compiler finds the proper data type

    cout<<*n<<endl ;    // see the output this gives 0
    cout<<endl ;

    cout<<*--n<<endl ;   // Now see the output obtained 
    cout<<endl ;

    // 2
    cout<<"2) " ;
    for(auto i = s.end() - 1 ; i != s.begin(); i--){
        cout<<*i ;
    }
    cout<<endl ;         // different start positions observe the outputs 
    cout<<endl ;

    // 3
    cout<<"3) " ;
    for(auto i = s.end() ; i != s.begin(); i--){
        cout<<*i;
    }
    cout<<endl ;
    cout<<endl ;

    // 4
    cout<<"4) " ;
    for(auto i = s.begin() ; i < s.end(); i++){
        cout<<*i ;
    }
    cout<<endl ;
    cout<<endl ;

    // 5
    cout<<"5) " ;
    for(auto i = s.end()- 1 ; i >= s.begin(); i--){
        cout<<*i ;
    }
    cout<<endl ;
    cout<<endl ;

    auto m = s.rbegin() ;

    // Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element its not of type int* or int 
    // so we write as auto so that during run time compiler finds the proper data type

    // auto m = s.rend() ;

    // Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

    // 6
    cout<<"6) " ;
    for(auto i = s.rbegin(); i < s.rend() ; i++){
        cout<<*i ;
    }
    cout<<endl ;
    cout<<endl ;

    // 7
    cout<<"7) " ;
    for(auto i = s.rend() ; i >= s.rbegin() ; i--){
        cout<<*i ;
    }
    cout<<endl ;
    cout<<endl ;

    // 8
    cout<<"8) " ;
    for(auto i = s.rend() - 1 ; i >= s.rbegin() ; i--){
        cout<<*i ;
    }
    cout<<endl ;
    cout<<endl ;


    // swap() This function swaps one string with other.
    string str1 = "hello" ;
    string str2 = "howareyou" ;
    cout<<"before swapping"<<endl ;
    cout<<str1<<endl ;
    cout<<str2<<endl ;
    str1.swap(str2) ;
    cout<<"after swapping"<<endl ;
    cout<<str1<<endl ;
    cout<<str2<<endl ;

    /* 
    copy(“char array”, len, pos) 	This function copies the substring in the target character array mentioned in its arguments. 
    It takes 3 arguments, target char array, length to be copied, and starting position in the string to start copying.
    */

    char ex[20] ;
    str1.copy(ex, 3, 1) ;
    for(int i = 0 ; i < 3 ; i++){
        if(ex[i] == '\0'){
            break ;
        }
        else{
            cout<<ex[i] ;
        }
    }
    cout<<endl ;

    /* string substr (size_t pos, size_t len) const;
    Parameters:
    pos: Position of the first character to be copied.
    len: Length of the sub-string.
    size_t: It is an unsigned integral type.
    Return value: It returns a string object.

    To copy string after a position 
    str.substr(int pos) ;
*/ 
    string r ;
    r = s.substr(2,6) ;
    cout<<r<<endl ;





/*
strcpy()
This is the string copy function. It copies one string into another string.
Syntax:
char* strcpy(string1, string2);
The two parameters to the function, string1 and string2, are strings. The function will copy the string string1 into the string 1.

strcat()
This is the string concatenate function. It concatenates strings.
Syntax:
char* strcat(string1, string2);
The two parameters to the function, string1 and string2 are the strings to be concatenated. The above function will concatenate the string string2 to the end of the string string1.

int strlen()
This is the string length function. It returns the length of the string passed to it as the argument.
Syntax:
strnlen(string1)
The parameter string1 is the name of the string whose length is to be determined. The above function will return the length of the string string1.

strcmp()
This is the string compare function. It is used for string comparison.
Syntax:
int strcmp(string1, string2);
The above function will return 0 if strings string1 and string2 are similar, less than 0 if string1<string2 and greater than 0 if string1>string2.
comparision is done via lexicographical order
*/

	char name1[10] = "Guru99";
	char name2[10] = "John";
	char name3[10];

	int  len = 0 ;
	strcpy(name3, name1);
	cout << "strcpy( name3, name1) : " << name3 << endl;

	strcat(name1, name2);
	cout << "strcat( name1, name2): " << name1 << endl; // concatenates str2 to str1 after that str2 is destroyed
    // cout<<name2<<endl ; nothing is being printed over here str2 got added to str1 

	len = strlen(name1);
	cout << "strlen(name1) : " << len << endl;


    return 0 ;
}