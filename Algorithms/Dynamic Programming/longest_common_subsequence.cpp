/*
We formalize this last notion of similarity as the longest-common-subsequence
problem. A subsequence of a given sequence is just the given sequence with zero or
more elements left out. Formally, given a sequence X  = ( x 1, x 2...x m ), another
sequence Z =  (z1, z2...zi) is a subsequence of X if there exists a strictly
increasing sequence h = (i1, i 2,...,ik) of indices of X such that for all j = (1, 2...k)
we have xij =  zj . For example, Z = (B, C, D, B) is a subsequence of X =
A, B, C, B, D, A, B with corresponding index sequence (2,3,5,7)


1. If xm = yn , then zk = xm = yn and Zk-1 is an LCS of Xm-1 and Yn-1 .
2. If xm != yn , then zk != x m implies that Zk is an LCS of Xm-1 and Yn .
3. If xm != yn , then zk != y n implies that Zk is an LCS of Xm and Yn-1 .

so if xm != yn we will be having two cases case 2 and 3 we have to choose longest sequence of these two
*/
#include<bits/stdc++.h>
using namespace std ;


void print(char **arr, string a, int i, int j){
    if((i == 0) || (j == 0)){
        return ;
    }
    if(arr[i][j] == 'd'){
        print(arr, a, i-1, j-1) ;
        cout<<a[i]<< ; 
    }
    else if(arr[i][j] == 'u'){
        print(arr, a, i-1, j) ;
    }
    else{
        print(arr, a, i, j-1) ;
    }
}
/*
Here I am storing extra char so that when we along the matrix of Xm and Yn which element to take we start from the bottom 
that is last element [m-1][n-1] d implies diagnol movement u implies up and l implies left 
*/

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

/*
To find the number of common subsequences in two string, say S and T, we use Dynamic Programming by defining a 2D array dp[][], where dp[i][j] is the number of common subsequences in the string S[0…i-1] and T[0….j-1]. 

Now, we can define dp[i][j] as = dp[i][j-1] + dp[i-1][j] + 1, when S[i-1] is equal to T[j-1] 
This is because when S[i-1] == S[j-1], using the above fact all the previous common sub-sequences are doubled as they get appended by one more character. Both dp[i][j-1] and dp[i-1][j] contain dp[i-1][j-1] and hence it gets added two times in our recurrence which takes care of doubling of count of all previous common sub-sequences. Addition of 1 in recurrence is for the latest character match : common sub-sequence made up of s1[i-1] and s2[j-1]  = dp[i-1][j] + dp[i][j-1] – dp[i-1][j-1], when S[i-1] is not equal to T[j-1] 
Here we subtract dp[i-1][j-1] once because it is present in both dp[i][j – 1] and dp[i – 1][j] and gets added twice.
*/
int CommonSubsequencesCount(string s, string t){
    int n1 = s.length();
    int n2 = t.length();
    int dp[n1+1][n2+1];
 
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s[i - 1] == t[j - 1]){
                dp[i][j] = 1 + dp[i][j - 1] + dp[i - 1][j];      
            }     
            else{
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] -dp[i - 1][j - 1];  
            }         
        }
    }
 
    return dp[n1][n2];
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    string a = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA" ;
    string b = "GTCGTTCGGAATGCCGTTGCTCTGTAAA" ;

    subsequence(a,b) ;

    return 0 ;
}