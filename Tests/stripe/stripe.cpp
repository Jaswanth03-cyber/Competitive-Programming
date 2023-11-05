# include <bits/stdc++.h>

using namespace std;

void calculate_payouts(string part, string bank_account_currencies[], string charges[]){
    string defaultcur = bank_account_currencies[0];

    int n = bank_account_currencies.size();

    int m = charges.size();
    vector<tuple<string, string, float>> partings(m);

    // There are two commas in the string, seperate those out and make a triplet
    for(int i=0; i<m; i++){
        string charge = charges[i];
        int first_comma = charge.find(",");
        int second_comma = charge.find(",", first_comma+1);
        string date = charge.substr(0, first_comma);
        string currency = charge.substr(first_comma+1, second_comma-first_comma-1);
        string amount = charge.substr(second_comma+1, charge.size()-second_comma-1);
        float amount = stof(amount/100);
        partings[i] = make_tuple(date, currency, amount);
    }

    // Map the conversions to the default currency 

    // 1 CHF = 0.97 USD, 1 EUR = 1.05 USD, 1 GBP = 1.24 USD 
    map<string, string> conversion;
    conversion["CHF"] = "0.97USD";
    conversion["EUR"] = "1.05USD";   
    conversion["GBP"] = "1.24USD";

    if(part == "partOne"){
        // Check whether the currencies in charges are present in the bank account currencies array else convert into the default currency and then calculate the payouts
            // The currency is present in the bank account currencies array
            // Calculate the payouts
            for(int i=0; i<m; i++){
                string currency = partings[i].second;   
                if(find(bank_account_currencies.begin(), bank_account_currencies.end(), currency) != bank_account_currencies.end()){
                    currency = partings[i].second;
                    float amount = (partings[i].third)*0.98;
                }
                else{
                    // Default currency can be anything 
                    // Convert the currency into the default currency

                    // 1 CHF = 0.97 USD, 1 EUR = 1.05 USD, 1 GBP = 1.24 USD
                    if(defaultcur == "CHF"){
                        if(currency == "EUR"){
                            amount = amount*0.98*1.05/0.97;
                        }
                        else if(currency == "GBP"){
                            amount = amount*0.98*1.24/0.97;
                        }
                    }
                    else if(defaultcur == "EUR"){
                        if(currency == "CHF"){
                            amount = amount*0.98*0.97/1.05;
                        }
                        else if(currency == "GBP"){
                            amount = amount*0.98*1.24/1.05;
                        }
                    }
                    else{
                        if(currency == "CHF"){
                            amount = amount*0.98*0.97;
                        }
                        else if(currency == "EUR"){
                            amount = amount*0.98*1.05;
                        }
                        else{
                            amount = amount*0.98*1.24;
                        }
                    }
                    currency = defaultcur;
                }

            }

            // Print the payouts

            map<string, float> payouts;
            for(int i=0; i<m; i++){
                string currency = partings[i].second;
                float amount = partings[i].third;
                payouts[currency] += amount;
            }

            sort(payouts.begin(), payouts.end());
            for(auto it=payouts.begin(); it!=payouts.end(); it++){
                cout << it->first << " " << round(it->second) << endl;
            }

        
        
    }
    else{
        // time for CHF = 3days, EUR = 2days, GBP = 1day, USD=0 days
        for(int i=0; i<m; i++){
                string currency = partings[i].second;   
                if(find(bank_account_currencies.begin(), bank_account_currencies.end(), currency) != bank_account_currencies.end()){
                    currency = partings[i].second;
                    // Date is in the format YYYY-MM-DD, so we need to extract the day
                    int day = stoi(partings[i].first.substr(8, 2));
                    int month = stoi(partings[i].first.substr(5, 2));
                    int year = stoi(partings[i].first.substr(0, 4));
                    // Check the days, months, years properly with number of days in it 
                    // Months of 1, 3, 5, 7, 8, 10, 12 have 31 days, 4, 6, 9, 11 have 30 days, 2 has 28 days and 29 days in leap year
                    // Check for leap year, which month and then add the days accordingly and then update the dates of payout
                    if(currency == "CHF"){
                        if(day+3 > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)){
                            if(month == 12){
                                year++;
                                month = 1;
                                day = day+3-31;
                            }
                            else{
                                month++;
                                day = day+3-31;
                            }
                        }
                        else{
                            if(month == 2){
                                if(day+3 > 28 && (year%4 != 0)){
                                    month++;
                                    day = day+3-28;
                                }
                                else{
                                    if(day+3 > 29 && (year%4 == 0)){
                                        month++;
                                        day = day+3-29;
                                    }
                                    else{
                                        day = day+3;
                                    }
                                }
                            }
                            else{
                                if(day+3 > 30){
                                    month++;
                                    day = day+3-30;
                                }
                                else{
                                    day = day+3;
                                }
                            }
                        }
                    }
                    else if(currency == "EUR"){
                        if(day+2 > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)){
                            if(month == 12){
                                year++;
                                month = 1;
                                day = day+2-31;
                            }
                            else{
                                month++;
                                day = day+2-31;
                            }
                        }
                        else{
                            if(month == 2){
                                if(day+3 > 28 && (year%4 != 0)){
                                    month++;
                                    day = day+3-28;
                                }
                                else{
                                    if(day+3 > 29 && (year%4 == 0)){
                                        month++;
                                        day = day+3-29;
                                    }
                                    else{
                                        day = day+3;
                                    }
                                }
                            }
                            else{
                                if(day+2 > 30){
                                    month++;
                                    day = day+2-30;
                                }
                                else{
                                    day = day+2;
                                }
                            }
                        }
                    }
                    else if(currency == "GBP"){
                        if(day+1 > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)){
                            if(month == 12){
                                year++;
                                month = 1;
                                day = day+1-31;
                            }
                            else{
                                month++;
                                day = day+1-31;
                            }
                        }
                        else{
                            if(month == 2){
                                if(day+3 > 28 && (year%4 != 0)){
                                    month++;
                                    day = day+3-28;
                                }
                                else{
                                    if(day+3 > 29 && (year%4 == 0)){
                                        month++;
                                        day = day+3-29;
                                    }
                                    else{
                                        day = day+3;
                                    }
                                }
                            }
                            else{
                                if(day+1 > 30){
                                    month++;
                                    day = day+1-30;
                                }
                                else{
                                    day = day+1;
                                }
                            }
                        }
                    }
                    else{
                        day = day;
                    }
                    string date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);

                    partings[i].first = date;

                    float amount = (partings[i].third)*0.98;
                }
                else{
                    // Default currency can be anything 
                    // Convert the currency into the default currency

                    // 1 CHF = 0.97 USD, 1 EUR = 1.05 USD, 1 GBP = 1.24 USD
                    if(defaultcur == "CHF"){
                        if(currency == "EUR"){
                            amount = amount*0.98*1.05/0.97;
                        }
                        else if(currency == "GBP"){
                            amount = amount*0.98*1.24/0.97;
                        }
                    }
                    else if(defaultcur == "EUR"){
                        if(currency == "CHF"){
                            amount = amount*0.98*0.97/1.05;
                        }
                        else if(currency == "GBP"){
                            amount = amount*0.98*1.24/1.05;
                        }
                    }
                    else{
                        if(currency == "CHF"){
                            amount = amount*0.98*0.97;
                        }
                        else if(currency == "EUR"){
                            amount = amount*0.98*1.05;
                        }
                        else{
                            amount = amount*0.98*1.24;
                        }
                    }
                    currency = defaultcur;

                    if(currency == "CHF"){
                        if(day+3 > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)){
                            if(month == 12){
                                year++;
                                month = 1;
                                day = day+3-31;
                            }
                            else{
                                month++;
                                day = day+3-31;
                            }
                        }
                        else{
                            if(month == 2){
                                if(day+3 > 28 && (year%4 != 0)){
                                    month++;
                                    day = day+3-28;
                                }
                                else{
                                    if(day+3 > 29 && (year%4 == 0)){
                                        month++;
                                        day = day+3-29;
                                    }
                                    else{
                                        day = day+3;
                                    }
                                }
                            }
                            else{
                                if(day+3 > 30){
                                    month++;
                                    day = day+3-30;
                                }
                                else{
                                    day = day+3;
                                }
                            }
                        }
                    }
                    else if(currency == "EUR"){
                        if(day+2 > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)){
                            if(month == 12){
                                year++;
                                month = 1;
                                day = day+2-31;
                            }
                            else{
                                month++;
                                day = day+2-31;
                            }
                        }
                        else{
                            if(month == 2){
                                if(day+3 > 28 && (year%4 != 0)){
                                    month++;
                                    day = day+3-28;
                                }
                                else{
                                    if(day+3 > 29 && (year%4 == 0)){
                                        month++;
                                        day = day+3-29;
                                    }
                                    else{
                                        day = day+3;
                                    }
                                }
                            }
                            else{
                                if(day+2 > 30){
                                    month++;
                                    day = day+2-30;
                                }
                                else{
                                    day = day+2;
                                }
                            }
                        }
                    }
                    else if(currency == "GBP"){
                        if(day+1 > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)){
                            if(month == 12){
                                year++;
                                month = 1;
                                day = day+1-31;
                            }
                            else{
                                month++;
                                day = day+1-31;
                            }
                        }
                        else{
                            if(month == 2){
                                if(day+3 > 28 && (year%4 != 0)){
                                    month++;
                                    day = day+3-28;
                                }
                                else{
                                    if(day+3 > 29 && (year%4 == 0)){
                                        month++;
                                        day = day+3-29;
                                    }
                                    else{
                                        day = day+3;
                                    }
                                }
                            }
                            else{
                                if(day+1 > 30){
                                    month++;
                                    day = day+1-30;
                                }
                                else{
                                    day = day+1;
                                }
                            }
                        }
                    }
                    else{
                        day = day;
                    }
                    string date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
                    partings[i].first = date;
                    partings[i].second = currency;
                    partings[i].third = amount;
                }

            }
        

        sort(partings.begin(), partings.end());
        // If both the currencies and the strings are same, then only add the amounts
        // Create a map of the string "date,currency" to the amount

        map<string, float> payouts;

        for(int i=0; i<m; i++){
            string date = partings[i].first;
            string currency = partings[i].second;
            float amount = partings[i].third;
            payouts[date+","+currency] += amount;
        }

        // Print the payouts

        for(auto it=payouts.begin(); it!=payouts.end(); it++){
            cout << it->first << "," << round(it->second) << endl;
        }


    }


}


int main{
    string part;
    string bank_account_currencies[n];
    string charges[m];
    cin >> part;
    for(int i=0; i<n; i++){
        cin >> bank_account_currencies[i];
    }
    for(int i=0; i<m; i++){
        cin >> charges[i];
    }
    calculate_payouts(part, bank_account_currencies, charges);
    return 0;
}
