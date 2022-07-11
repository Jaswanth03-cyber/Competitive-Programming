/*
Fast fourier Transform is used to find the coefficients of product of two polynomials in O(nlogn) time but brute force takes O(n^2)

This is based on the discrete fourier transform and inverse discrete fourier transform 

*/

#include<iostream>
#include<complex>
#include<cmath>
#include<vector>
using namespace std ;
typedef complex<double> com_num ;   // this is for defining new data type 

/*
typedef data_type new_data_type_name ;

complex(double) means complex number class with real and imaginary numbers as double data type
*/

/*
here we are sending invert as parameter to dft as if we just want evaluation of the nth square roots of unity from the coefficients
we are sending false if we want coefficients from the n evaluations we are sending true as we can get coefficients from the 
n evaluations, here n is the degree of the polynomial + 1 study cp algorithms/ fast fourier transform to get more clarity on this 
*/

template<typename T> T *brute_force(T A[], T B[], int m, int n){   // taking degrees too as parameters 

   T *prod = new T[m+n-1];

    for (int i = 0; i<m+n-1; i++){
        prod[i] = 0;
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            prod[i+j] += A[i]*B[j];
        }
    }
  
   return prod;
}
void dft(vector<com_num> &arr , bool invert){      

    long int n = arr.size() ;

    if(n == 1){
        return ;
    }

    vector<com_num> res_even, res_odd ;     // Here we are using Divide and Conquer property 

    res_even.resize(n/2) ;
    res_odd.resize(n/2) ;

    for(int i = 0 ; 2*i < n ; i++){
        res_even[i] = arr[2*i] ;
        res_odd[i] = arr[2*i + 1] ;
    }

    dft(res_even, invert) ;
    dft(res_odd, invert) ;

    if(invert){
        double Pi = acos(-1) ;

        double ang = (2*Pi*(-1))/n ;         // if inverse fourier transform we have to evaluate at alpha power (-1)

        com_num alpha(1,0) ;          // nothing but creating a complex number with real and imag parts initialised as 1 and 0 resp

        com_num w(cos(ang), sin(ang)) ; // w as nth roots are 1, w, w^2, w^3, ...  w^(n-1)

        com_num a(2,0) ;    // this I created because division of int and complex is not supported so 

        for(int i = 0 ; 2*i < n ; i++){

            arr[i] = res_even[i] + (alpha)*(res_odd[i]) ;

            arr[i + n/2] = res_even[i] - (alpha)*(res_odd[i]) ;
/*
This part we do as at the end we have to divide the matrix by n if we want to get coefficients from the evaluations
so if we do this recursively we will end up by dividing with n ;
*/
            arr[i] = arr[i]/a ;

            arr[i + n/2] = arr[i + n/2]/a ;

            alpha = alpha*w ;
        }

    }
    else{

        // when invert is false evaluating the values of the polynomials at nth roots of unity 
        double Pi = acos(-1) ;
        double ang = (2*Pi)/n ;
        com_num alpha(1,0) ;
        com_num w(cos(ang), sin(ang)) ;
        for(int i = 0 ; 2*i < n ; i++){

            arr[i] = res_even[i] + (alpha)*(res_odd[i]) ;

            arr[i + n/2] = res_even[i] - (alpha)*(res_odd[i]) ;

            alpha = alpha*w ;
        } 

    }
}

// multiplication function 
template<typename T> vector<T> multiplication(vector<T> const &a, vector<T> const &b){

/*
Polynomials we wanted to multiply
*/
    vector<com_num> f ;      
    vector<com_num> g ;

    for(int i = 0 ; i < a.size(); i++){

        com_num num(a[i], 0) ;
        f.push_back(num) ;

    }
    for(int j = 0 ; j < b.size(); j++){

        com_num num(b[j], 0) ;
        g.push_back(num) ;

    }

    int n = 1;
    while (n < a.size() + b.size()){
        n <<= 1;
    }
   // cout<<n<<endl ; 

    f.resize(n) ;
    g.resize(n) ;


    dft(f, false) ;

    dft(g, false) ;

    vector<com_num> prod_at_n_roots(n) ;

    for(int i = 0 ; i < n ; i++){

        prod_at_n_roots[i] = f[i]*g[i] ;       // evaluation of polynomial h at nth roots of unity where h is f*g 

    }

/*
There we passed the vector by reference if u see the function so values changed will be reflected 
*/
    dft(prod_at_n_roots, true) ;       // from the evaluations we are obtaining coefficients 

    vector<T> fin_res(n) ;

    for(int i = 0 ; i < n ; i++){
        fin_res[i] = round(prod_at_n_roots[i].real()) ;    // this rounding is done for accuracy actually no idea for them tooo
    }

    return fin_res ;
}

int main(){
    vector<int> res ;

    vector<int> a ;
    vector<int> b ;

    a.push_back(9) ;
    a.push_back(-10) ;
    a.push_back(7) ;
    a.push_back(6) ;

    b.push_back(-5) ;
    b.push_back(4) ;
    b.push_back(0) ;
    b.push_back(-2) ;

    res = multiplication<int>(a, b) ;
/*
If I am using i < res.size() I am getting another values extra tooo but those are also 0 ;

This is because for suppose we take degree of f to be n1 and degree of g to be n2 

if we see the function we use n here 2*Pi/n

here n is the least number of the form pow(2,k) and n > n1 + n2 -1 so that there will be no problem while solving subcases
as we have n/2 

extra coefficients will be zero anyway.
*/
    for(int i = 0 ; i < res.size() ; i++){   
        cout<<res[i]<<" " ;
    }
    cout<<endl ;


    int arr1[] = {9, -10, 7, 6} ;

    int arr2[] = {-5, 4, 0, -2} ;

    int m = sizeof(arr1)/sizeof(arr1[0]) ;
    int n = sizeof(arr2)/sizeof(arr2[0]) ;

    int *prod = brute_force<int>(arr1, arr2, m, n) ;


    for(int i = 0 ; i < m + n -1  ; i++){
        cout<<prod[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}

