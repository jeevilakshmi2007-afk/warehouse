#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted halves arr[left..mid] and arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while (i <= mid)   temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (size_t k = 0; k < temp.size(); k++)
        arr[left + k] = temp[k];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n;
    cout << "Enter number of packages: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid number of packages.\n";
        return 1;
    }

    vector<int> weights(n);
    cout << "Enter " << n << " package weights: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> weights[i])) {
            cout << "Invalid weight entered.\n";
            return 1;
        }
    }

    cout << "\nBefore sorting: ";
    for (int w : weights) cout << w << " ";

    mergeSort(weights, 0, n - 1);

    cout << "\nAfter sorting (ascending): ";
    for (int w : weights) cout << w << " ";
    cout << "\n";

    return 0;
}
