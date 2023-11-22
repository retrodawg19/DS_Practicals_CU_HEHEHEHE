#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100
#define MAX_MEMORY_LOCATIONS 50

// Structure to represent an employee record
struct Employee {
    int key;
    // Other employee data can be added here
};

// Structure to represent a hash table entry
struct HashTableEntry {
    int key;
    struct Employee employee;
};

// Function to initialize the hash table
void initializeHashTable(struct HashTableEntry hashTable[], int m) {
    for (int i = 0; i < m; i++) {
        hashTable[i].key = -1; // -1 indicates an empty slot
    }
}

// Hash function: H(K) = K mod m
int hashFunction(int key, int m) {
    return key % m;
}

// Function to insert a record into the hash table using linear probing
void insertIntoHashTable(struct HashTableEntry hashTable[], int m, struct Employee employee) {
    int key = employee.key;
    int index = hashFunction(key, m);

    // Linear probing to handle collisions
    while (hashTable[index].key != -1) {
        index = (index + 1) % m; // Move to the next location
    }

    // Insert the record into the hash table
    hashTable[index].key = key;
    hashTable[index].employee = employee;
}

// Function to display the contents of the hash table
void displayHashTable(struct HashTableEntry hashTable[], int m) {
    printf("\nHash Table:\n");
    printf("Index\tKey\tEmployee\n");
    for (int i = 0; i < m; i++) {
        printf("%d\t%d", i, hashTable[i].key);
        if (hashTable[i].key != -1) {
            printf("\t%d", hashTable[i].employee.key);
            // Display other employee data as needed
        }
        printf("\n");
    }
}

int main() {
    struct HashTableEntry hashTable[MAX_MEMORY_LOCATIONS];
    struct Employee employees[MAX_EMPLOYEES];
    int m, n; // m is the number of memory locations, n is the number of employees

    printf("Enter the number of memory locations (m): ");
    scanf("%d", &m);

    initializeHashTable(hashTable, m);

    printf("Enter the number of employees (n): ");
    scanf("%d", &n);

    printf("Enter the employee records (key only):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &employees[i].key);
        // You can input other employee data here
        insertIntoHashTable(hashTable, m, employees[i]);
    }

    displayHashTable(hashTable, m);

}
