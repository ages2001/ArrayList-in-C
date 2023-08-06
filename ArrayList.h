#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ArrayList {
    void **data;
    size_t capacity;
    size_t size;
} ArrayList;

bool isEmpty(ArrayList *list);

ArrayList *createArrayList(size_t capacity);

void add(ArrayList *list, void *newData, size_t index);

void addBegin(ArrayList *list, void *newData);

void addEnd(ArrayList *list, void *newData);

void delete(ArrayList *list, size_t index);

void deleteBegin(ArrayList *list);

void deleteEnd(ArrayList *list);

void clearArrayList(ArrayList *list);

void printArrayList(ArrayList *list, void (*printFunction)(void *));

void printInt(void *value);

void printDouble(void *value);

void printFloat(void *value);

void printChar(void *value);

void printString(void *value);

void printBool(void *value);
