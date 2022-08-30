#include <bits/stdc++.h>
using namespace std ;


string* listify(int n,int &count){
    string* res;
    if(n == 1) {
        res = new string[2];
        res[0] = '0'; res[1] = '1';
        count = 2;
    }
	else if(n == 2){
        res = new string[4];
        res[0] = "00"; res[1] = "01"; res[2] = "11"; res[3] = "10";
        count = 4;        
    }
    else{
        int c;
        string* list = listify(n-2,c);
        count = 4*c;
        res = new string[count];
        string add[4] = {"00","01","11","10"};
        string revadd[4] = {"10","11","01","00"};
        string* curr = add;
        for (int i = 0; i < c; i++){
            res[4*i]   = list[i] + curr[0];
            res[4*i+1] = list[i] + curr[1];
            res[4*i+2] = list[i] + curr[2];
            res[4*i+3] = list[i] + curr[3];
            if(curr == add){
				curr = revadd;
			}
            else{
				curr = add;
			}
        }
    }
    return res;
}
int main() {
    int n = 0, c;
    cin >> n;
    string* list = listify(n,c);
    for (int i = 0; i < c; i++){
        cout << list[i] << endl;
    }
}