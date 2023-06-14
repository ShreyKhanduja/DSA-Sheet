
#include <iostream>
using namespace std;

#define pii pair<int, int>

pii staircaseSearch(int *arr[], int m, int n, int key) {
    int row = 0, col = n - 1;
    pii p = make_pair(-1, -1);

    while(row < m and col >= 0) {
        if(arr[row][col] == key) {
            p = make_pair(row, col);
            return p;
        }
        else if(key < arr[row][col]) 
            col--;
        else 
            row++;
    }
    return p;
}

int main() {

    int r, c, key;
    cin >> r >> c >> key;

    int *arr[r];
    for(int i = 0; i < r; i++)
        arr[i] = new int[c];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) 
            cin >> arr[i][j];
    }

    pii p = staircaseSearch(arr, r, c, key);
    if(p.first == -1)
        cout << "element not found";
    else 
        cout << "element found at index : " << p.first << " " << p.second;

    return 0;
}