#include <iostream>

void solveHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return;
    }

    solveHanoi(n - 1, source, destination, auxiliary);
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;
    solveHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int numDisks = 3;
    solveHanoi(numDisks, 'A', 'B', 'C');
}