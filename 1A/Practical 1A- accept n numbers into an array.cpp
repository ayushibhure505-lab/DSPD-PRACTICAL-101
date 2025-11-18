  #include <stdio.h>

int main() {
    int n, i, arr[50];
    int evenSum = 0, oddSum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if(i % 2 == 0)
            evenSum += arr[i];
        else
            oddSum += arr[i];
    }

    printf("Sum of even position elements = %d\n", evenSum);
    printf("Sum of odd position elements = %d\n", oddSum);
    return 0;
}
