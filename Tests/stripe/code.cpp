#include <bits/stdc++.h>
using namespace std ;

tuple<string, string, float> tokenize(string &s){
    tuple<string, string, float> ans ;
    int n = s.length() ;
    string curr = "" ;
    int counter = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == ',' && counter == 0){
            get<0>(ans) = curr ;
            curr = "" ;
            counter++ ;
        }
        else if(s[i] == ',' && counter == 1){
            get<2>(ans) = stof(curr)/100.0 ;
            curr = "" ;
        }
        else{
            curr = curr + s[i] ;
        }
    }
    get<1>(ans) = curr ;

    return ans ;
}
void calculate_payouts(string part, vector<string> &bank_accounnts, vector<string> &charges){

    set<string> st ;
    int n = bank_accounnts.size() ;
    for(int i = 0 ; i < n ; i++){
        st.insert(bank_accounts[i]) ;
    }

    string defaultbank = bank_account[0] ;

    int m = charges.size() ;
    vector<tuple<string, string, float>> tokens(m, {"", "", 0.0}) ;

    for(int i = 0 ; i < m ; i++){
        tokens[i] = tokenize(charges[i]) ;
    }

    map<string, float> payouts ;

    if(part == "part_one"){
        for(int i = 0 ; i < m ; i++){
            string currcurrency = get<1>(tokens[i]) ;

            if(st.find(currcurrency) != st.end()){
                if(payouts.find(currcurrency) != payouts.end()){
                    float amount = (get<2>(tokens[i]))*(0.98) ;
                    payouts[currcurrency] += amount ;
                }
                else{
                    payouts.insert({currcurrency, amount}) ;
                }
            }
            else{
                float amount = (get<2>)tokens[i]*0.98 ;
                if(defaultbank == "CHF"){
                    if(currcurrency == "EUR"){
                        amount = amount*(1.05/0.97) ;
                    }
                    else if(currcurrency == "GBP"){
                        amount = amount*(1.24/0.97) ;
                    }
                    else if(currcurrency == "USD"){
                        amount = amount*(1.0/0.97) ;
                    }
                }
                if(defaultbank == "EUR"){
                    if(currcurrency == "CHF"){
                        amount = amount*(0.97/1.05) ;
                    }
                    else if(currcurrency == "GBP"){
                        amount = amount*(1.24/1.05) ;
                    }
                    else if(currcurrency == "USD"){
                        amount = amount*(1.0/1.05) ;
                    }
                }
                if(defaultbank == "GBP"){
                    if(currcurrency == "EUR"){
                        amount = amount*(1.05/1.24) ;
                    }
                    else if(currcurrency == "CHF"){
                        amount = amount*(0.97/1.24) ;
                    }
                    else if(currcurrency == "USD"){
                        amount = amount*(1.0/1.24) ;
                    }
                }
                if(defaultbank == "USD"){
                    if(currcurrency == "EUR"){
                        amount = amount*(1.05) ;
                    }
                    else if(currcurrency == "GBP"){
                        amount = amount*(1.24) ;
                    }
                    else if(currcurrency == "CHF"){
                        amount = amount*(0.97) ;
                    }
                }

                if(payouts.find(defaultbank) != payouts.end()){
                    payouts[defaultbank] += amount ;
                }
                else{
                    payouts.insert({defaultbank, amount}) ;
                }
            }
        }

        for(auto it = payouts.begin() ; it != payouts.end() ; it++){
            string ans = "" ;
            ans = ans + it->first ;
            ans.push_back(',') ;
            cout<<ans<<fixed<<setprecision(2)<<it->second<<endl ;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    vector<string> bank_account ;
    vector<string> charges ;
    calculate_payouts("part_one", bank_account, charges) ;
    return 0 ;
}