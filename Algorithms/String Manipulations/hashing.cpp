/*
Taking a as 1, b as 2, c as 3, ....
*/#include<bits/stdc++.h>
using namespace std ;

long long int hashing(string s){

    int p = 31 ;
    int m = 1e9 + 9 ;
    long long int hash_value = 0 ; 
    long long int pow = 1 ;
    for(int i = 0 ; i < s.size() ; i++){
        hash_value = ( hash_value + (pow)*(s[i] - 'a' + 1) )%m ;
        pow = ((p)*(pow))%m ;
    }

    return hash_value ;
}
// Application 1 
/*
Applications finding duplicate strings in a given array of strings
*/

vector<vector<string>> group_identical_strings(vector<string> s){

    int n = s.size() ;  
    vector<pair<long long int, string>> groups ;
    for(int i = 0 ; i < n ; i++){
        long long int hash_value = hashing(s[i]) ;
        groups.push_back(make_pair(hash_value, s[i])) ;
    }

    sort(groups.begin(), groups.end()) ; // by deafult its sorted by first element, lets find number of different groups 

    int k = 1 ;
    for(int i = 1 ; i < n ; i++){
        if(groups[i].first != groups[i-1].first){
            k++ ;
        }
    }

    vector<vector<string>> final_group(k);
    int m = 0 ;
    final_group[m].push_back(groups[0].second) ;
    for(int i = 1 ; i < n ; i++){ 
        if(groups[i].first != groups[i-1].first){
            m++ ;
            final_group[m].push_back(groups[i].second) ;
        }
        else{
            final_group[m].push_back(groups[i].second) ;
        }
    }

    return final_group ;

}
/*
Two different methods here its usage of vectors properly 
there is a difference between emplace and push by using push we can not add an empty one but by emplace we can add an empty one 
*/
vector<vector<string>> group_identicalstrings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, string>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {hashing(s[i]), s[i]};

    sort(hashes.begin(), hashes.end());

    vector<vector<string>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first){
            groups.emplace_back();
        }                                // adds an empty element creates memory 
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

// Application 2 
/*
Finding number of substrings in a given string, if possible will try to add those strings tooo 
*/

/*
according to definition of hash for a string 
hash(s[i...j]) = sum((s[k]*pow(p, k-i))%m) k going from i to j 

hash(s[i...j])*pow(p, i) = sum((s[k]*pow(p, k))%m) k going from i to j 
hash(s[i...j])*pow(p, i) = ( hash(s[0...j] - hash(s[0...i-1]) )%m

So by knowing the hash value of each prefix of the string , we can compute the hash of any substring directly using this formula.
The only problem that we face in calculating it is that we must be able to divide hash(s[0...j] - hash(s[0...i-1]) by pow(p, i). Therefore we need to find the
modular multiplicative inverse of  and then perform multiplication with this inverse. We can precompute the inverse of every pow(p, i),
which allows computing the hash of any substring of  in  time.

However, there does exist an easier way. In most cases, rather than calculating the hashes of substring exactly, it is enough 
to compute the hash multiplied by some power of p. Suppose we have two hashes of two substrings, one multiplied by pow(p, i) and the 
other by pow(p, j). If i < j then we multiply the first hash by pow(p, j-i) , otherwise, we multiply the second hash by pow(p, i-j) . By doing this, we get both the
hashes multiplied by the same power of  p(which is the maximum of i and j) and now these hashes can be compared easily with no need
for any division.
we are using the same over here 

Here pow[i] is nothing but pow(p, i) 

Here hash_value[i] is nothing but the hash value of the string from s[0...i-1] string of length "i"

To solve this problem, we iterate over all substring lengths l = 1...n. For every substring length  we construct an array of hashes of all 
substrings of length l multiplied by the same power of p to all the substrings of length l. The number of different elements in the array is equal to the number of 
distinct substrings of length l in the string. This number is added to the final answer.
*/
vector<string> unique_substrings(string s){

    vector<string> result ;
    int p = 31 ;
    int m = 1e9 + 9 ;
    int n = s.size() ;

    long long int pow[n] ;
    pow[0] = 1 ;
    for(int i = 1 ; i < n ; i++){
        pow[i] = pow[i-1]*p ;
    }

    vector<long long int> hash_value(n+1, 0) ;
    for(int i = 1 ; i <=n ; i++){
        hash_value[i] = (hash_value[i-1] + (s[i] - 'a' + 1)*pow[i-1])%m ;      // finding hash value and remembering it of s[0...i]
    } 
    int count = 0 ;
    for(int length = 1 ; length <=n ; length++){ // length is the length of the string 
        set<long long int> hs ;
        set<long long int> value ;
        for(int i = 0 ; i <= n - length ; i++){   // here i is the starting index of the string max will be n - length only 
            long long int current_hash_value = (hash_value[i + length]  - hash_value[i])%m ;
            current_hash_value = (current_hash_value*pow[n-1-i])%m ;
            value.insert(current_hash_value) ;
            if(hs.count(current_hash_value) != 1){      
                string add = "" ;
                for(int k = i ; k < i + length ; k++){
                    add = add + s[k] ;                        // concattening the strings 
                }
                result.push_back(add) ;
                hs.insert(current_hash_value) ;
            }
        }
        count = count + value.size() ;
    }
    cout<<count<<endl ;
    return result;
}

/*
here we are searching in the set if there is a string with hash value of this string that string is nothing but 
s[i...i + length -1] so if count is one then no need to add this string if not 1 we need to add so for adding we used a for loop
*/




int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    string s1 = "jasssu" ;
    long long int hash_value = hashing(s1) ;
    cout<<hash_value<<endl ;

    vector<string> s ;
    s.push_back("hello") ;
    s.push_back("hi") ;
    s.push_back("how") ;
    s.push_back("go") ;
    s.push_back("hello") ;
    s.push_back("hi") ;
    s.push_back("how") ;
    s.push_back("go") ;
    s.push_back("bye") ;
    s.push_back("how") ;
    vector<vector<string>> final = group_identicalstrings(s) ;

    for(int i = 0 ; i < final.size() ; i++){
        cout<<final[i][0]<<" " ;
    }
    cout<<endl ;

    vector<string> result = unique_substrings(s1) ;
    for(int i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}