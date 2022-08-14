#include<bits/stdc++.h>
using namespace std ;

vector<int> z_function_trivial(string s) {
    int n = (int) s.length();
    vector<int> z(n, 0);
    for (int i = 1; i < n; ++i){
        while ( (i + z[i] < n) && (s[z[i]] == s[i + z[i]]) ){
            z[i]++ ;
        }
    }
    return z;
}

/*
This function we write is to decrease the number of comparisions we use already calculated z values to get the new ones further

basically what we do is that we normally calculate the z array and we also maintain a z box with starting index as l and ending 
index as r, so for example if at a particular position z[i] is greater than 1 then we will have a z-box otherwise only one 
element so like for suppose we have a z-box lets says as shown 
                0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
                a a b x a a b x c a a  b  x  a  a  b  x  a  y 
                        l-----r                          
                0 1 0 0 4
Here for i belongs to [l, r] we can reduce the number of comparisions as z[4] = 4 so for i = 5,6,7 we need not again compare from 
the start as u see z[4] is 4 so z[5..7] should match with z[1..3] so which means till r indexes z value of 5,6,7 will be those of
1,2,3 but its till index r only we did not check after r so until then we can reduce atleast those comparisions we check from 
next index r so what we do is that take min(z[i-l] and r - i + 1) beacuse we did not yet see whats the string after r so until r 
only we find z later update it after that normally in the trivial way by checking and simulatenously we change our l and r values 
that is change our z box.
*/

vector<int> z_function(string s){
    int n = s.size() ;

    vector<int> z(n,0) ;
    int l = 0 ; 
    int r = 0 ; 
    for(int i = 1 ; i < n ; i++){

        if(i <= r){
            z[i] = min(z[i - l], r - i + 1) ;
        }
        while((i + z[i] < n) && (s[z[i]] == s[i + z[i]])){
            z[i]++ ;
        }
        if(i + z[i] - 1 > r){
            l = i ; 
            r = i + z[i] - 1 ;
        }
    }
    return z ;
}

/*
Used for sub string searching lets say we are given two strings substring and a text what we do is we concatinate both the strings 
with first string as substring and next one is the text with a different character between them which is not in both the strings and 
now calculate the z array for this string now in the text where the z value is same as length of the size of the substring at that 
position we will be having our substring started in the text.
*/

vector<int> find_substring_position(string s, string text){

    string total = s + "$" + text ; 
    vector<int> z = z_function(total) ;
    vector<int> result ;
    for(int i = s.size() + 1 ; i < total.size() ; i++){ // we have to check in the text so starting index of text in total will be s.size() + 1
        if(z[i] == s.size()){
            result.push_back(i - s.size() - 1) ;     // we subtract s.size() as we need to find the positions in the text not in total
        }
    }
    return result ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    string sub_string = "aab" ;
    string text = "aabxaabxcaabxaabxay" ;
    vector<int> z ; 
    z = z_function(text) ;
    for(int i = 0 ; i < z.size() ; i++){
        cout<<z[i]<<" " ;
    }
    cout<<endl ;

    vector<int> z1 ; 
    z1 = z_function_trivial(text) ;
    for(int i = 0 ; i < z1.size() ; i++){
        cout<<z1[i]<<" " ;
    }
    cout<<endl ;

    vector<int> result = find_substring_position(sub_string, text) ;
    cout<<"Positions in the "<<text<<" where "<<sub_string<<" will start is : " ;
    for(int i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;

    return 0 ;
}