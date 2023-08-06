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

    int newValue = 50;
    replace(list, &newValue, 3); // Replace fourth data with new data

    printArrayList(list, printInt);

    clearArrayList(list); // clear list from memory

    /* Another example for string (char*) data type */

    printf("Enter size of string array list: ");
    scanf("%zu", &size2);

    ArrayList *list2 = createArrayList(size2);

    for (size_t i = 0; i < size2; i++) {
        char *data = (char *) malloc(sizeof(char) * STR_LIMIT); // character limit is 100, you can choose different value in header file
        printf("Data %zu: ", i + 1);
        scanf("%s", data);

        addBegin(list2, data);
    }

    printArrayList(list2, printString); // printString function is for printing string (char*) values

    delete(list2, 1); // Delete second data in the array list

    printArrayList(list2, printString);

    char *newStr = (char *) malloc(sizeof(char) * STR_LIMIT);
    strcpy(newStr, "newValue");
    replace(list2, newStr, 2); // Replace third data with new data

    printArrayList(list2, printString);

    for (size_t i = 0; i < list2->size; i++) { // free all string data from memory
        if (list->data[i] != NULL)
            free(list->data[i]);
    }

    clearArrayList(list2); // clear list2 from memory

    return 0;
}
