
#include <iostream>
#include <unordered_map>
using namespace std;

int countXOR(int *arr, int n, int m) {
    unordered_map<int, int> freq;
    int count = 0, prefix_xor = 0;

    for(int i = 0; i < n; i++) {
        prefix_xor ^= arr[i];
        if(prefix_xor == m)
            count++;
        
        if(freq.find(prefix_xor ^ m) != freq.end())
            count += freq[prefix_xor ^ m];
        
        // update value in the map
        freq[prefix_xor]++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int m;
    cin >> m;

    cout << countXOR(arr, n, m);

    return 0;
}