
#include <iostream>
using namespace std;

int findMSB(int n) {
    
    n = n | n >> 1;
    n = n | n >> 2;
    n = n | n >> 4;
    n = n | n >> 8;
    n = n | n >> 16;

    n = n + 1;

    return (n >> 1);
}

int main() {

    int n;
    cin >> n;

    cout << findMSB(n) << endl;

    return 0;
}