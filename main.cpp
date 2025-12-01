#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int mid = left + (right - left) / 2;
    int leftSize = mid;
    int rightSize = size - mid - 1;
    int leftArr[leftSize];
    int rightArr[rightSize];
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    if (arr[mid] == target) {
            return mid;
    }
    if (size <= 0) {
        return -1;
    }
    if (size<= 1) {
        return arr[0];
    }
    if (arr[mid] < target) {
        int res = binarySearch(rightArr, rightSize, target);
        return (res == -1 ? -1 : mid + 1 + res);
    } else {
        return binarySearch(leftArr, leftSize, target);
    }


}

int main() {
    int size, target;
    cout << "Enter size";
    cin >> size;
   cout << "Enter target";
    cin >> target;
    int arr[size];
    cout << "Enter array elements";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << binarySearch(arr, size, target);
}
