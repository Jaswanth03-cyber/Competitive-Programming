#include<iostream>
#include<string>
using namespace std ;

void print(char **arr, string a, int i, int j){
    if((i == 0) || (j == 0)){
        return ;
    }
    if(arr[i][j] == 'd'){
        print(arr, a, i-1, j-1) ;
        cout<<a[i]<<" " ; 
    }
    else if(arr[i][j] == 'u'){
        print(arr, a, i-1, j) ;
    }
    else{
        print(arr, a, i, j-1) ;
    }
}

void subsequence(string a, string b){

    string string1 = 'e' + a ;
    string string2 = 'e' + b ;

    int length1 = a.size() ;
    int length2 = b.size() ;

    int **max_length ;
    max_length = new int*[length1 + 1] ;
    for(int i = 0 ; i <= length1 ; i++){
        max_length[i] = new int[length2 + 1] ;
    }

    char **direction ;

    direction = new char*[length1+1] ;
    for(int i = 0 ; i <= length1 ; i++){
        direction[i] = new char[length2 + 1] ;
    }

    for(int i = 0 ; i <= length1 ; i++){
        max_length[i][0] = 0 ;
        direction[i][0] = 'e' ;
    }
    for(int j = 1 ; j <= length2 ; j++){
        max_length[0][j] = 0 ;
        direction[0][j] = 'e' ;
    }

    for(int i = 1 ; i <= length1 ; i++){
        for(int j = 1 ; j <= length2 ; j++){
            if(string1[i] == string2[j]){
                max_length[i][j] = max_length[i-1][j-1] + 1 ;
                direction[i][j] = 'd' ;
            }
            else if(max_length[i-1][j] > max_length[i][j-1]){
                max_length[i][j] = max_length[i-1][j] ;
                direction[i][j] = 'u' ;
            }
            else{
                max_length[i][j] = max_length[i][j-1] ;
                direction[i][j] = 'l' ;
            }
        }
    }


    print(direction, string1, length1, length2) ;
    cout<<endl ;
}

int main(){
    string a = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA" ;
    string b = "GTCGTTCGGAATGCCGTTGCTCTGTAAA" ;

    subsequence(a,b) ;

    return 0 ;
}