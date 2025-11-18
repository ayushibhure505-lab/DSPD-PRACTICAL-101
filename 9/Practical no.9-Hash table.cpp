#include <stdio.h>
#define SIZE 7

int main() {
    int hash[SIZE];
    for(int i=0;i<SIZE;i++) hash[i]=-1;
    int n, key, index;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        printf("Enter key: ");
        scanf("%d", &key);
        index = key % SIZE;
        while(hash[index] != -1)
            index = (index + 1) % SIZE;
        hash[index] = key;
    }

    printf("\nHash Table:\n");
    for(int i=0;i<SIZE;i++)
        printf("Index %d -> %d\n", i, hash[i]);
    return 0;
}
