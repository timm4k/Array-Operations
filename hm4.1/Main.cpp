#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    const int arrayLength = 15;
    int numbers[arrayLength];

    srand(static_cast<unsigned>(time(0)));

    cout << "Array: ";
    for (int i = 0; i < arrayLength; i++) {
        numbers[i] = rand() % 101 - 50;
        cout << numbers[i] << " ";
    }
    cout << endl;

    int minValue = numbers[0];
    int maxValue = numbers[0];

    for (int number : numbers) {
        minValue = min(minValue, number);
        maxValue = max(maxValue, number);
    }

    // Виведення результатів
    cout << "Min element: " << minValue << endl;
    cout << "Max element: " << maxValue << endl;

    return 0;
}

