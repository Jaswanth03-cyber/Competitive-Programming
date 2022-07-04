# Asymptotic Analysis 

To simplify analysis of running time by getting rid of details which may be effected by specific compiler and hardware, so to capture the assence we use asymptotic analysis

## Asymptotic Upper Bound 

If I have functions f(n) and g(n) which are non negative and non decreasing we say 
f(n) = O(g(n)) if there exists constants c and n<sub>0</sub> such that  f(n) is less than or equal to cg(n) for all n greater than or equal to n<sub>0</sub>

We drop lower order terms and constant factors, we use O-notation to express number of primitive operations executed as function of the input given. Like O-notation there are many other notations which u can look below as shown 

1. f(n) = O(g(n))    
2. f(n) = o(g(n)) here f(n) is strictly less than cg(n) for all n greater than or equal to n<sub>0</sub>
3. f(n) = w(g(n)) here f(n) is strictly greater than cg(n) for all n greater than or equal to n<sub>0</sub>
4. f(n) = omega(g(n)) here f(n) is greater than or equal to cg(n) for all n greater than or equal to n<sub>0</sub>
5. f(n) = Theta(g(n)) here there exists c<sub>1</sub> and c<sub>2</sub> such that c<sub>1</sub>g(n) less than or equal to f(n)  less than or equal to c<sub>2</sub>g(n) for all n greater than or equal to n<sub>0</sub>  