#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int start = 0, end = n - 1, mid;
    while(start <= end) {
        mid = (start + end) / 2;
        printf("Checking index %d (value = %d)\n", mid, arr[mid]);
        if(arr[mid] == key)
            return mid;
        else if(key > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main() {
    int n, arr[50], key, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter sorted elements:\n");
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, n, key);
    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("NULL (Element not found)\n");
    return 0;
}
