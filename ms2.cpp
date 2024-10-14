#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> sortedArr;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            sortedArr.push_back(left[i]);
            i++;
        } else {
            sortedArr.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        sortedArr.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        sortedArr.push_back(right[j]);
        j++;
    }

    return sortedArr;
}

vector<int> mergeSort(const vector<int>& arr) {
    if (arr.size() <= 1) return arr;

    size_t mid = arr.size() / 2;
    vector<int> left = mergeSort(vector<int>(arr.begin(), arr.begin() + mid));
    vector<int> right = mergeSort(vector<int>(arr.begin() + mid, arr.end()));

    return merge(left, right);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> sortedArr = mergeSort(arr);

    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
