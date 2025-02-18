//
// Created by Alfredo on 18/02/2025.
//

#include <complex>
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }


    int root = sqrt(n);
    for (int i = 3; i <= root; i += 3) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n = 999;
    if (isPrime(n)) {
        cout << "its Prime" << endl;
    } else {
        cout << "its not prime" << endl;
    }

    return 0;
}
