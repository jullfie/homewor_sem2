#include <stdio.h>

#define MAX 100 // максимальный размер массива

// Функция отображения массива
void print(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Функция добавления элемента в конец массива
int append(int arr[], int size, int element) {
    if (size == MAX) {
        printf("Array overflow\n");
        return size;
    }
    arr[size++] = element;
    return size;
}

// Функция добавления элемента в середину массива
int insert(int arr[], int size, int element, int position) {
    if (position < 0 || position > size) {
        printf("Invalid position\n");
        return size;
    }

    if (size == MAX) {
        printf("Array overflow\n");
        return size;
    }
    
    for (int i = size-1; i >= position; i--) {
        arr[i+1] = arr[i];
    }
    
    arr[position] = element;
    
    return ++size;
}

int main() {
    int arr[MAX] = {1, 2, 3, 4, 5};
    int size = 5;

    // Print array
    print(arr, size);

    // Append element
    printf("Enter element to append: ");
    int element;
    scanf("%d", &element);
    size = append(arr, size, element);
    print(arr, size);

    // Insert element
    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter position to insert: ");
    int position;
    scanf("%d", &position);
    size = insert(arr, size, element, position);
    print(arr, size);

    // Test 1 for append
    printf("\nTest 1 for append:\n");
    printf("Before: ");
    print(arr, size);
    size = append(arr, size, 10);
    printf("After: ");
    print(arr, size);

    // Test 2 for append
    printf("\nTest 2 for append:\n");
    printf("Before: ");
    print(arr, size);
    size = append(arr, size, 20);
    printf("After: ");
    print(arr, size);

    // Test 3 for insert
    printf("\nTest 3 for insert:\n");
    printf("Before: ");
    print(arr, size);
    size = insert(arr, size, 30, 2);
    printf("After: ");
    print(arr, size);

    // Test 4 for insert
    printf("\nTest 4 for insert:\n");
    printf("Before: ");
    print(arr, size);
    size = insert(arr, size, 40, 0);
    printf("After: ");
    print(arr, size);

    // Test 5 for insert
    printf("\nTest 5 for insert:\n");
    printf("Before: ");
    print(arr, size);
    size = insert(arr, size, 50, 7); // invalid position
    printf("After: ");
    print(arr, size);

    return 0;
}