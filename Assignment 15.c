Array and Functions in C Language

1. Write a function to find the greatest number from the given array of any size. (TSRS)
2. Write a function to find the smallest number from the given array of any size. (TSRS)
3. Write a function to sort an array of any size. (TSRS)
4. Write a function to rotate an array by n position in d direction. The d is an indicative
value for left or right. (For example, if array of size 5 is [32, 29, 40, 12, 70]; n is 2 and
d is left, then the resulting array after left rotation 2 times is [40, 12, 70, 32, 29] )
5. Write a function to find the first occurrence of adjacent duplicate values in the array.
Function has to return the value of the element.
6. Write a function in C to read n number of values in an array and display it in reverse
order.
7. Write a function in C to count a total number of duplicate elements in an array.
8. Write a function in C to print all unique elements in an array.
9. Write a function in C to merge two arrays of the same size sorted in descending
order.
10. Write a function in C to count the frequency of each element of an array.

Solution:-

1. #include <stdio.h>

int findGreatest(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {32, 29, 40, 12, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("The greatest number in the array is: %d\n", findGreatest(arr, size));
    return 0;
}

2. #include <stdio.h>

int findSmallest(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int arr[] = {32, 29, 40, 12, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("The smallest number in the array is: %d\n", findSmallest(arr, size));
    return 0;
}

3. #include <stdio.h>

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {32, 29, 40, 12, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    sortArray(arr, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

4. #include <stdio.h>

void rotateArray(int arr[], int size, int n, char direction) {
    int temp[size];
    if (direction == 'L' || direction == 'l') {
        for (int i = 0; i < size; i++) {
            temp[i] = arr[(i + n) % size];
        }
    } else if (direction == 'R' || direction == 'r') {
        for (int i = 0; i < size; i++) {
            temp[i] = arr[(i - n + size) % size];
        }
    }
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {32, 29, 40, 12, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 2;
    char direction = 'L';
    rotateArray(arr, size, n, direction);
    printf("Rotated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

5. #include <stdio.h>

int findFirstAdjacentDuplicate(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return arr[i];
        }
    }
    return -1; // Return -1 if no adjacent duplicates are found
}

int main() {
    int arr[] = {32, 29, 40, 40, 12, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = findFirstAdjacentDuplicate(arr, size);
    if (result != -1) {
        printf("The first adjacent duplicate value is: %d\n", result);
    } else {
        printf("No adjacent duplicate values found.\n");
    }
    return 0;
}

6. #include <stdio.h>

void displayReverse(int arr[], int size) {
    printf("Array in reverse order: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    displayReverse(arr, n);
    return 0;
}

7. #include <stdio.h>

int countDuplicates(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}

int main() {
    int arr[] = {32, 29, 40, 32, 12, 70, 29};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Total number of duplicate elements: %d\n", countDuplicates(arr, size));
    return 0;
}

8. #include <stdio.h>

void printUniqueElements(int arr[], int size) {
    printf("Unique elements: ");
    for (int i = 0; i < size; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        if (i == j) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {32, 29, 40, 32, 12, 70, 29};
    int size = sizeof(arr) / sizeof(arr[0]);
    printUniqueElements(arr, size);
    return 0;
}

9. #include <stdio.h>

void mergeArraysDescending(int arr1[], int arr2[], int merged[], int size) {
    int i = 0, j = 0, k = 0;
    while (i < size && j < size) {
        if (arr1[i] > arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < size) {
        merged[k++] = arr1[i++];
    }
    while (j < size) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {70, 40, 32, 29, 12};
    int arr2[] = {90, 45, 35, 25, 15};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int merged[size * 2];
    mergeArraysDescending(arr1, arr2, merged, size);
    printf("Merged array in descending order: ");
    for (int i = 0; i < size * 2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");
    return 0;
}

10. #include <stdio.h>

void countFrequency(int arr[], int size) {
    int frequency[size];
    for (int i = 0; i < size; i++) {
        frequency[i] = -1;
    }
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                frequency[j] = 0;
            }
        }
        if (frequency[i] != 0) {
            frequency[i] = count;
        }
    }
    printf("Element | Frequency\n");
    for (int i = 0; i < size; i++) {
        if (frequency[i] != 0) {
            printf("%d       | %d\n", arr[i], frequency[i]);
        }
    }
}

