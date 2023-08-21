#include <stdio.h>
#define SIZE 10

void bubble_sort(int array[], size_t size);

int main() {
    int array[] = {1, 3, 4, 5, 3, 2, 6, 8, 9, 10};

    bubble_sort(array, SIZE);

    for (size_t i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

void bubble_sort(int array[], size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                int hold = array[j];
                array[j] = array[j + 1];
                array[j + 1] = hold;
            }
        }
    }
}
