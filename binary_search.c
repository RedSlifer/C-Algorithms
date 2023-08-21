#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int binary_search(const int array[], int key, size_t size);
int compare(const void* a, const void* b);

int main() {
    int array[] = {1, 3, 4, 5, 3, 2, 6, 8, 9, 10};
    int key = 2;

    qsort(array, SIZE, sizeof(int), compare);

    if (binary_search(array, key, SIZE))
        printf("Founded");
    else
        printf("Not founded");

    return 0;
}

int binary_search(const int array[], int key, size_t size) {
    size_t low_index = 0;
    size_t high_index = size - 1;
    size_t middle_index;

    while (high_index >= low_index) {
        middle_index =  (low_index + high_index) / 2;

        if (key > array[middle_index])
            low_index = middle_index + 1;
        else if (key < array[middle_index])
            high_index = middle_index - 1;
        else
            return 1;
    }

    return 0;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
