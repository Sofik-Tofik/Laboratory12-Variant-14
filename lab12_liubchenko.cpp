#include <iostream>
#include <stdlib.h>

using namespace std;

const int SIZE = 3;

void sort_Last_Column(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = 0; j < SIZE - i - 1; ++j) {
            if (arr[j][SIZE - 1] < arr[j + 1][SIZE - 1]) {
                for (int k = 0; k < SIZE; ++k) {
                    int temp = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = temp;
                }
            }
        }
    }
}

int product_Of_Max_Indices_Sum(int arr[SIZE][SIZE]) {
    int max1 = arr[0][SIZE - 1];
    int max2 = arr[1][SIZE - 2];
    for (int i = 1; i < SIZE; ++i) {
        if (arr[i][SIZE - 1 - i] > max1) {
            max2 = max1;
            max1 = arr[i][SIZE - 1 - i];
        }
        else if (arr[i][SIZE - 1 - i] > max2) {
            max2 = arr[i][SIZE - 1 - i];
        }
    }
    return (SIZE - 1) * 2 * (max1 + max2);
}

int main() {
    int arr[SIZE][SIZE] = { {1, 2, 3},
                           {4, 5, 6},
                           {7, 8, 9} };

    sort_Last_Column(arr);

    int product = product_Of_Max_Indices_Sum(arr);

    cout << "Product of the sum of indices of two maximum elements on the secondary diagonal: " << product << endl;

    return 0;
}