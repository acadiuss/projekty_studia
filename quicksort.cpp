#include <iostream>
#include <algorithm>
using namespace std;



int partition(int arr[], int head, int tail) {
    int pivot = arr[tail];
    int i = head - 1;

    for (int j = head; j <= tail - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[tail]);
    return i + 1;
}

void quick_sort(int arr[], int head, int tail) {
    if (head < tail) {
        int pivot_index = partition(arr, head, tail);

        quick_sort(arr, head, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, tail);
    }
}

int main() {
    int unsorted_list[] = {9, 8, 7, 6, 5, 4, 3, 2, 1,8,9,99,4,67,8,1};
    int n = sizeof(unsorted_list) / sizeof(unsorted_list[0]);

    std::cout << "Lista przed posortowaniem:";
    for (int i = 0; i < n; i++) {
        std::cout << " " << unsorted_list[i]<< endl;
    }
    std::cout << std::endl;

    quick_sort(unsorted_list, 0, n - 1);

    std::cout << "Lista po posortowaniu:";
    for (int i = 0; i < n; i++) {
        std::cout << " " << unsorted_list[i]<<endl;
    }
    std::cout << std::endl;

    return 0;
}
