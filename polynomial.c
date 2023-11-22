#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial terms
struct Node {
    int coefficient;
    int power_x;
    int power_y;
    int power_z;
    struct Node *next;
};

// Function to create a new node with given coefficients and powers
struct Node *createNode(int coef, int px, int py, int pz) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->coefficient = coef;
    newNode->power_x = px;
    newNode->power_y = py;
    newNode->power_z = pz;
    newNode->next = NULL;

    return newNode;
}

// Function to insert a term into the polynomial
void insertTerm(struct Node **poly, int coef, int px, int py, int pz) {
    struct Node *newNode = createNode(coef, px, py, pz);
    if (*poly == NULL) {
        // If the list is empty, make the new node the head
        *poly = newNode;
        newNode->next = *poly;
    } else {
        // Insert the new node at the end of the circular linked list
        struct Node *temp = *poly;
        while (temp->next != *poly) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *poly;
    }
}

// Function to display the polynomial
void displayPolynomial(struct Node *poly, const char *polyName) {
    struct Node *temp = poly;

    printf("%s: ", polyName);

    if (temp == NULL) {
        printf("0\n");
    } else {
        do {
            printf("%dx^%dy^%dz^%d", temp->coefficient, temp->power_x, temp->power_y, temp->power_z);
            temp = temp->next;
            if (temp != poly) {
                printf(" + ");
            }
        } while (temp != poly);
        printf("\n");
    }
}

// Function to evaluate the polynomial for given values of x, y, and z
int evaluatePolynomial(struct Node *poly, int x, int y, int z) {
    struct Node *temp = poly;
    int result = 0;

    if (temp == NULL) {
        return 0; // If the polynomial is empty, the result is 0
    } else {
        do {
            result += temp->coefficient * pow(x, temp->power_x) * pow(y, temp->power_y) * pow(z, temp->power_z);
            temp = temp->next;
        } while (temp != poly);
        return result;
    }
}

// Function to add two polynomials and store the result in a new polynomial
struct Node *addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;
    struct Node *temp1 = poly1;
    struct Node *temp2 = poly2;

    // Iterate through each term of both polynomials and add them
    do {
        int coefSum = temp1->coefficient + temp2->coefficient;
        insertTerm(&result, coefSum, temp1->power_x, temp1->power_y, temp1->power_z);
        temp1 = temp1->next;
        temp2 = temp2->next;
    } while (temp1 != poly1 && temp2 != poly2);

    return result;
}

// Function to free the memory allocated for the polynomial
void freePolynomial(struct Node *poly) {
    if (poly != NULL) {
        struct Node *temp = poly;
        struct Node *prev = NULL;

        do {
            prev = temp;
            temp = temp->next;
            free(prev);
        } while (temp != poly);
    }
}

int main() {
    // Represent and evaluate polynomial P(x, y, z) = 6x^2y^2z - 4yz^5 + 3x^3yz + 2xy^5z - 2xyz^3
    struct Node *polyP = NULL;
    insertTerm(&polyP, 6, 2, 2, 1);
    insertTerm(&polyP, -4, 0, 1, 5);
    insertTerm(&polyP, 3, 3, 1, 1);
    insertTerm(&polyP, 2, 1, 5, 1);
    insertTerm(&polyP, -2, 1, 1, 3);

    displayPolynomial(polyP, "P(x, y, z)");

    int x = 2, y = 3, z = 4;
    int resultP = evaluatePolynomial(polyP, x, y, z);
    printf("P(%d, %d, %d) = %d\n", x, y, z, resultP);

    // Find the sum of two polynomials POLY1(x, y, z) and POLY2(x, y, z)
    struct Node *poly1 = NULL;
    insertTerm(&poly1, 3, 2, 1, 3);
    insertTerm(&poly1, -2, 1, 4, 2);

    struct Node *poly2 = NULL;
    insertTerm(&poly2, 5, 2, 1, 3);
    insertTerm(&poly2, 1, 1, 4, 2);

    displayPolynomial(poly1, "POLY1(x, y, z)");
    displayPolynomial(poly2, "POLY2(x, y, z)");

    struct Node *polySum = addPolynomials(poly1, poly2);
    displayPolynomial(polySum, "POLYSUM(x, y, z)");

    // Free allocated memory for polynomials
    freePolynomial(polyP);
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(polySum);

    return 0;
}
