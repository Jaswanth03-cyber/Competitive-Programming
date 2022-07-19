/*
The edit distance or Levenshtein distance1
is the minimum number of editing operations needed to transform a string into another string. The allowed
editing operations are as follows:
• insert a character (e.g. ABC → ABCA)
• remove a character (e.g. ABC → AC)
• modify a character (e.g. ABC → ADC)
For example, the edit distance between LOVE and MOVIE is 2, because we can
first perform the operation LOVE → MOVE (modify) and then the operation MOVE →
MOVIE (insert). This is the smallest possible number of operations, because it is
clear that only one operation is not enough.
Suppose that we are given a string x of length n and a string y of length m,
and we want to calculate the edit distance between x and y. To solve the problem,
we define a function distance(a,b) that gives the edit distance between prefixes
x[0...a] and y[0...b]. Thus, using this function, the edit distance between x and
y equals distance(n−1,m−1).
*/

#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std ;

int edit_distance(string a, string b){

    int **distance ;

    int n = a.size() ;

    int m = b.size() ;

    distance = new int*[n + 1] ;
    for(int i = 0 ; i <= n ; i++){
        distance[i] = new int[m + 1] ;
    }

    for(int i = 0 ; i <= n ; i++){
        distance[i][0] = i ;
    }
    for(int j = 1 ; j <= m ; j++){
        distance[0][j] = j ;
    }

    string string1 = " " + a ; 
/*
Here I am adding a space character because to avoid indexing problem later in the for loop further just to avoid confusion 

*/
    string string2 = " " + b ;

    for(int i = 1 ; i <= n; i++){
        for(int j = 1 ; j <= m ; j++){

            int cost ;
            int minimum ;

            if(string1[i] == string2[j]){
                cost = 0 ;
            }
            else{
                cost = 1 ;
            }
            minimum = min(distance[i][j-1] + 1 , distance[i-1][j] + 1) ;
            distance[i][j] = min(distance[i-1][j-1] + cost, minimum) ;
        }
    }

    int result = distance[n][m] ; 

    for(int i = 0 ; i <= n ; i++){
        delete[] distance[i] ; 
    }
    delete[] distance ;

    return result ;
}

/*
Here distance[i][j] denotes the edit distance of string a[0...i-1] and b[0...j-1] or 
x and y are two given strings and we are finding distance(a,b)
Here cost(a,b) = 0 if x[a] = y[b], and otherwise cost(a,b) = 1. The formula
considers the following ways to edit the string x:
• dis1 = distance(a,b −1): insert a character at the end of x
• dis2 = distance(a−1,b): remove the last character from x
• dis3 = distance(a−1,b −1): match or modify the last character of x if matched no need to add cost so cost is 0 if not
then modify one of the strings lets say here x .

distance(a,b) = min(dis1, dis2, dis3)
*/
int main(){

    string a = "love" ;
    string b = "movie" ;

    string str1 = "sunday";
    string str2 = "saturday";

    string c = "food" ;
    string d = "money" ;

    cout<<"Edit distance between the given two strings "<<a<<" and "<<b<<" is : " ;
    cout<<edit_distance(a,b)<<endl ;

    cout<<"Edit distance between the given two strings "<<str1<<" and "<<str2<<" is : " ;
    cout<<edit_distance(str1, str2)<<endl;

    cout<<"Edit distance between the given two strings "<<c<<" and "<<d<<" is : " ;
    cout<<edit_distance(c, d)<<endl;


    return 0 ;
}