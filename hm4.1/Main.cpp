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

    cout << "Min element: " << minValue << endl;
    cout << "Max element: " << maxValue << endl;

    return 0;
}

// task 2
#include <iostream>

using namespace std;

int main() {
    const int monthsInYear = 12;
    double monthlyProfits[monthsInYear];

    cout << "Enter profit for each of the 12 months:" << endl;
    for (int i = 0; i < monthsInYear; i++) {
        cout << "Month " << (i + 1) << ": ";
        cin >> monthlyProfits[i];
    }

    int startMonth, endMonth;

    cout << "Enter range to search for (for example, 3 and 6, with space):" << endl;
    cout << "Initial month: ";
    cin >> startMonth;
    cout << "Final month: ";
    cin >> endMonth;

    if (startMonth < 1 || endMonth > monthsInYear || startMonth > endMonth) {
        cout << "Invalid range. Check the input data." << endl;
        return 1;
    }

    double maxProfit = monthlyProfits[startMonth - 1];
    double minProfit = monthlyProfits[startMonth - 1];
    int maxProfitMonth = startMonth;
    int minProfitMonth = startMonth;

    for (int i = startMonth; i <= endMonth; i++) {
        if (monthlyProfits[i - 1] > maxProfit) {
            maxProfit = monthlyProfits[i - 1];
            maxProfitMonth = i;
        }
        if (monthlyProfits[i - 1] < minProfit) {
            minProfit = monthlyProfits[i - 1];
            minProfitMonth = i;
        }
    }

    cout << "Month with max profit in the range: " << maxProfitMonth
        << " (: " << maxProfit << ")" << endl;
    cout << "Month with min profit in the range: " << minProfitMonth
        << " (Profit: " << minProfit << ")" << endl;

    return 0;
}

// task 3
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n;
    cout << "Enter num of elements in the array: ";
    cin >> n;

    vector<double> numbers(n);

    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    double sumOfNegative = 0;
    double productOfEvenIndex = 1;
    double productBetweenMinAndMax = 1;
    double sumBetweenFirstAndLastNegative = 0;

    int minIndex = 0, maxIndex = 0;
    int firstNegativeIndex = -1, lastNegativeIndex = -1;

    for (int i = 0; i < n; i++) {
        if (numbers[i] < 0) {
            sumOfNegative += numbers[i];
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
            lastNegativeIndex = i;
        }

        if (numbers[i] < numbers[minIndex]) {
            minIndex = i;
        }

        if (numbers[i] > numbers[maxIndex]) {
            maxIndex = i;
        }

        if (i % 2 == 0) {
            productOfEvenIndex *= numbers[i];
        }
    }

    int startIndex = min(minIndex, maxIndex);
    int endIndex = max(minIndex, maxIndex);

    if (startIndex + 1 < endIndex) {
        for (int i = startIndex + 1; i < endIndex; i++) {
            productBetweenMinAndMax *= numbers[i];
        }
    }
    else {
        productBetweenMinAndMax = 0;
    }

    if (firstNegativeIndex != -1 && lastNegativeIndex != -1 && firstNegativeIndex < lastNegativeIndex) {
        for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; i++) {
            sumBetweenFirstAndLastNegative += numbers[i];
        }
    }
    else {
        sumBetweenFirstAndLastNegative = 0;
    }

    cout << "Sum of negative elements: " << sumOfNegative << endl;
    cout << "Product of elements with even indices: " << productOfEvenIndex << endl;
    cout << "Product of elements between min and max: " << productBetweenMinAndMax << endl;
    cout << "Sum of elements between first and last negative elements: " << sumBetweenFirstAndLastNegative << endl;

    return 0;
}
