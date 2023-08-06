#include "ArrayList.h"

bool isEmpty(ArrayList *list) {
    return list->size == 0;
}

ArrayList *createArrayList(size_t capacity) {
    ArrayList *newList = (ArrayList *) malloc(sizeof(ArrayList));

    if (newList == NULL) {
        printf("An error occurred while creating ArrayList!\n");
        exit(-1);
    }

    newList->data = (void **) malloc(sizeof(void *) * capacity);
    newList->size = 0;
    newList->capacity = capacity;

    if (newList->data == NULL) {
        free(newList);
        printf("An error occurred while creating ArrayList!\n");
        exit(-1);
    }

    return newList;
}

void add(ArrayList *list, void *newData, size_t index) {
    if (index > list->size) {
        printf("Invalid index!\n");
        return;
    }

    if (list->size == list->capacity) {
        void **data = (void **) realloc(list->data, sizeof(void *) * ++list->capacity);

        if (data == NULL) {
            printf("An error occurred while adding data to ArrayList!\n");
            exit(-1);
        }

        list->data = data;
    }

    for (size_t i = list->size; i > index; i--)
        list->data[i] = list->data[i - 1];

    list->data[index] = newData;
    list->size++;
}

void addBegin(ArrayList *list, void *newData) {
    if (list->size == list->capacity) {
        void **data = (void **) realloc(list->data, sizeof(void *) * ++list->capacity);

        if (data == NULL) {
            printf("An error occurred while adding data to ArrayList!\n");
            exit(-1);
        }

        list->data = data;
    }

    for (size_t i = list->size; i > 0; i--)
        list->data[i] = list->data[i - 1];

    list->data[0] = newData;
    list->size++;
}

void addEnd(ArrayList *list, void *newData) {
    if (list->size == list->capacity) {
        void **data = (void **) realloc(list->data, sizeof(void *) * ++list->capacity);

        if (data == NULL) {
            printf("An error occurred while adding data to ArrayList!\n");
            exit(-1);
        }

        list->data = data;
    }

    list->data[list->size++] = newData;
}

void delete(ArrayList *list, size_t index) {
    if (isEmpty(list)) {
        printf("List is empty!\n");
        return;
    }

    if (index > list->size) {
        printf("Invalid index!\n");
        return;
    }

    char *strValue = (char *) list->data[index];
    if (strValue != NULL) {
        free(strValue);
    }

    for (size_t i = index; i < list->size; i++)
        list->data[i] = list->data[i + 1];

    list->size--;
}

void deleteBegin(ArrayList *list) {
    if (isEmpty(list)) {
        printf("List is empty!\n");
        return;
    }

    char *strValue = (char *) list->data[0];
    if (strValue != NULL) {
        free(strValue);
    }

    for (size_t i = 0; i < list->size; i++)
        list->data[i] = list->data[i + 1];

    list->size--;
}

void deleteEnd(ArrayList *list) {
    if (isEmpty(list)) {
        printf("List is empty!\n");
        return;
    }

    char *strValue = (char *) list->data[list->size];
    if (strValue != NULL)
        free(strValue);

    list->size--;
}

void clearArrayList(ArrayList *list) {
    size_t size = list->size;
    for (size_t i = 0; i < size; i++) {
        if (list->data[i] != NULL)
            free(list->data[i]);
    }

    free(list->data);
    free(list);
}

void printArrayList(ArrayList *list, void (*printFunction)(void *)) {
    printf("List: ");
    for (size_t i = 0; i < list->size; i++) {
        printFunction(list->data[i]);
    }
    printf("\n");
}

void printInt(void *value) {
    int *intValue = (int *) value;
    printf("%d ", *intValue);
}

void printDouble(void *value) {
    double *doubleValue = (double *) value;
    printf("%lf ", *doubleValue);
}

void printFloat(void *value) {
    float *floatValue = (float *) value;
    printf("%f ", *floatValue);
}

void printChar(void *value) {
    char *charValue = (char *) value;
    printf("%c ", *charValue);
}

void printString(void *value) {
    char *strValue = (char *) value;
    printf("%s ", strValue);
}

void printBool(void *value) {
    bool *boolValue = (bool *) value;
    printf("%s ", *boolValue ? "true" : "false");
}
