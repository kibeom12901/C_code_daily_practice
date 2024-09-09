#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Person structure
typedef struct {
    int id;
    char name[64];
} Person;

int main(int argc, char *argv[]) {
    // Dynamically allocate memory for a Person structure
    // *pPerson is the dereference and Person* is the memory type for mallod
  
    Person *pPerson = (Person*)malloc(sizeof(Person));

    // Check if malloc was successful
    if (pPerson == NULL) {
        puts("Memory allocation failed");
        return -1;
    }

    // Set values for the Person structure
    pPerson->id = 1;
    strcpy(pPerson->name, "John Doe");

    // Print values stored in the Person structure
    printf("ID: %d, Name: %s\n", pPerson->id, pPerson->name);

    // Free the dynamically allocated memory to avoid memory leaks
    free(pPerson);

    return 0;
}
