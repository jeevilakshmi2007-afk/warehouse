#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < (int)temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input\n";
        return 0;
    }

    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    mergeSort(weights, 0, n - 1);

    cout << "Sorted weights: ";
    for (int i = 0; i < n; i++) {
        cout << weights[i] << " ";
    }

    cout << endl;
    return 0;
}
