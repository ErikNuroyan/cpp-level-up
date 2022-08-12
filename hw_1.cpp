#include <iostream>

using namespace std;

//Helper function
void printArray(int* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) { 
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


void squareAndSort(const int* input, int* output, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        const int val = input[i] * input[i];
        size_t outputIndex = 0;
        while(outputIndex < i && output[outputIndex] < val) {
            ++outputIndex;
        }
        for (int j = i; j > outputIndex; --j) {
            output[j] = output[j - 1];
        }
        
        output[outputIndex] = val;
    }
}

int sumOfDigits(int n) {
    int sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int calculateOddCount(int s, int e) {
    return (e - s + 1) % 2 == 0 ? (e - s + 1) / 2 : (e - s + 1) / 2 + s % 2;
}

int digitProductMinusSum(int n) {
    if (n == 0) return 0;
    
    int sum = 0;
    int product = 1;
    while(n != 0) {
        const int r = n % 10;
        sum += r;
        product *= r;
        n /= 10;
    }
    
    return product - sum;
}

int binarySearch(const int* arr, int value, int size) {
    int start = 0;
    int end = size - 1;
    while(end - start > 1) {
        int mid = (start + end) / 2;
        if (arr[mid] > value) {
            end = mid - 1;
        }
        else if (arr[mid] < value) {
            start = mid + 1;
        }
        else {
            return mid;
        }
    }
    
    if (arr[start] == value) {
        return start;   
    }
    
    if (arr[end] == value) {
        return end;
    }
    
    return -1;
}

int binarySearchRecursive(const int* arr, int value, int start, int end) {
    if (end - start <= 1) {
        if (arr[start] == value) {
            return start;
        }
        if (arr[end] == value) {
            return end;
        }
        
        return -1;
    }
    
    int mid = (start + end) / 2;
    if (arr[mid] > value) {
        return binarySearchRecursive(arr, value, start, mid - 1);
    }
    else if (arr[mid] < value) {
        return binarySearchRecursive(arr, value, mid + 1, end);
    }
    else {
        return mid;
    }
}

size_t calculateIndexDivisibleCount(const int* arr, size_t size) {
    size_t count = 0;
    for (size_t i = 0; i < size; ++i) {
        count += (arr[i] % (i + 1) == 0); //To avoid division by 0
    }
    return count;
}

unsigned int evenFibonacciSum() {
    int f1 = 1;
    int f2 = 1;
    unsigned int sum = 0;
    while(f2 = f1 + f2, f2 < 4e6) {
        sum += f2 % 2 == 0 ? f2 : 0;
        f1 = f2 - f1; 
    }
    
    return sum;
}

int squareOfSumMinusSumOfSquares(int n, bool iterative = false) {
    if (iterative) {
        int sum = 0;
        int sumOfSquares = 0;
        for (int i = 1; i <= n; ++i) {
            sum += i;
            sumOfSquares += i * i;
        }
        
        return sum * sum - sumOfSquares;
    }
    
    int sum = n * (n + 1) / 2;
    int sumOfSquares = n * (n + 1) * (2 * n + 1) / 6;
    return sum * sum - sumOfSquares;
}

void bubbleSort(int* input, size_t size) {
    bool swapped = true;
    size_t sortedStart = size;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < sortedStart - 1; ++i) {
            if (input[i] > input[i + 1]) {
                input[i] += input[i + 1];
                input[i + 1] = input[i] - input[i + 1];
                input[i] = input[i] - input[i + 1];
                swapped = true;
            }
        }
        --sortedStart;
    }
}

bool isPowerOfTwo(int n) {
    if (n == 0) {
        return false;   
    }
    while (n > 1) {
        if (n % 2 == 1) {
            return false;
        }   
        n = n >> 1;
    }
    return true;
}

int main()
{
    //Problem 1
    constexpr int size = 7;
    constexpr int input[size] = {5, 2, 3, 0, 1, 4, 2};
    int output[size];
    squareAndSort(input, output, size);
    std::cout << "Sorted array of squares" << std::endl;
    printArray(output, size);
    std::cout << std::endl;
    
    //Problem 2
    std::cout << "Sum of digits: " << sumOfDigits(875) << std::endl;
    std::cout << std::endl;
    
    //Problem 3
    std::cout << "Digit product - digit Sum: " << digitProductMinusSum(641) << std::endl;
    std::cout << std::endl;
    
    //Problem 4
    std::cout << "# of Odds in the range: " << calculateOddCount(2, 8) << std::endl;
    std::cout << std::endl;
    
    //Problem 5
    constexpr int sortedArr[size] = {1, 5, 8, 12, 17, 77, 99};
    std::cout << "Binary search iterative: " << binarySearch(sortedArr, 5, size) << std::endl;
    std::cout << "Binary search recursive: " << binarySearchRecursive(sortedArr, 99, 0, size - 1) << std::endl;
    std::cout << std::endl;
    
    //Problem 6
    std::cout << "# of elements divisibly by their index: " << calculateIndexDivisibleCount(sortedArr, size) << std::endl;
    std::cout << std::endl;
    
    //Problem 7
    std::cout << "Sum of even Fibonacci numbers: " << evenFibonacciSum() << std::endl;
    std::cout << std::endl;
    
    //Problem 8
    std::cout << "Square of sum till N - Sum of squares till N: "
              << (squareOfSumMinusSumOfSquares(100, true) == squareOfSumMinusSumOfSquares(100)) << std::endl;
    std::cout << std::endl;
    
    //Problem 9
    int array[size] = {6, 1, 4, 3, 0, 0, 1};
    bubbleSort(array, size);
    std::cout << "Bubble sort" << std::endl;
    printArray(array, size);
    std::cout << std::endl;
    
    //Problem 10
    std::cout << "Check if N is power of 2: " << isPowerOfTwo(8) << std::endl;
    std::cout << std::endl;
    
    return 0;
}