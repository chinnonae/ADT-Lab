#include <iostream>
#include <stack>
using namespace std;

int getNextPrime(int currPrime){
    if(currPrime == 2) currPrime += 1;
    else currPrime += 2;
    bool isPrime = false;
    while(!isPrime){
        int divisible_num = 0;
        for(int i = 2; i < currPrime; i++){
            if(currPrime % i == 0) divisible_num += 1;
        }
        if(divisible_num > 0){
            currPrime += 2;
        }else{
            isPrime = true;
        }
    }
    return currPrime;
}


int main(){
    int n;
    cin >> n;

    int prime = 2;
    stack<int> primes;
    while(n > 1){
        if(n % prime == 0){
            n /= prime;
            if(primes.empty() || (!primes.empty() && primes.top() != prime)){
                primes.push(prime);
            }
        }else{
            prime = getNextPrime(prime);
        }
    }
    cout << primes.size() << endl;
}
