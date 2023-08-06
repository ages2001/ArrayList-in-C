#include "ArrayList.h"

int main() {
    size_t size, size2;

    /* Example for integer data type */

    printf("Enter size of integer array list: ");
    scanf("%zu", &size);

    ArrayList *list = createArrayList(size);

    for (size_t i = 0; i < size; i++) {
        int *data = (int *) malloc(sizeof(int));
        printf("Data %zu: ", i + 1);
        scanf("%d", data);

        addEnd(list, data);
    }

    printArrayList(list, printInt); // printInt function is for printing integer values

    delete(list, 2); // Delete third data in the array list

    printArrayList(list, printInt);
    clearArrayList(list); // Free memory

    /* Another example for string (char*) data type */

    printf("Enter size of string array list: ");
    scanf("%zu", &size2);

    ArrayList *list2 = createArrayList(size2);

    for (size_t i = 0; i < size2; i++) {
        char *data = (char *) malloc(sizeof(char) * 100); // 100 is character limit, you can choose different value
        printf("Data %zu: ", i + 1);
        scanf("%s", data);

        addBegin(list2, data);
    }

    printArrayList(list2, printString); // printString function is for printing string (char*) values

    delete(list2, 1); // Delete second data in the array list

    printArrayList(list2, printString);
    clearArrayList(list2); // Free memory

    return 0;
}
