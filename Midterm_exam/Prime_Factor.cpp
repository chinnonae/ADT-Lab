#include <iostream>
#include <stack>
using namespace std;

bool checkPrime(int num){
    bool isBreaked = false;
    int divisible_num = 0;
    for(int i = 2; i < num; i++){
        if(num % i == 0) {
            isBreaked = true;
            break;
        }
    }
    if(!isBreaked){
        return true;
    }else{
        return false;
    }

}

int getNextPrime(int currPrime){
    if(currPrime == 2) currPrime += 1;
    else currPrime += 2;
    bool isPrime = false;
    while(!isPrime){
        isPrime = checkPrime(currPrime);
        if(!isPrime){
            currPrime += 2;
        }
    }
    return currPrime;
}

int main(){
    int n;
    cin >> n;
    if(checkPrime(n)){
        cout << 1 << endl;
        return 0;
    }
    int prime = 2;
    stack<int> primes;
    while(n > 1){
        if(n % prime == 0){
            n /= prime;
            if(primes.empty() || primes.top() != prime){
                primes.push(prime);
            }
        }else{
            prime = getNextPrime(prime);
        }
    }
    cout << primes.size() << endl;
}
