#include <iostream>

void swap(int* array, int i, int j) {
    int temp = array[j];
    array[j] = array[i];
    array[i] = temp;
}

int partition(int array[], int low, int high, int& count) {
    int i = low - 1, j = high;
    while (true) {
        while (array[++i] < array[high]) count++;
        while (array[high] < array[--j]) {
            count++;
            if (j == low) break;
        }
        if (i >= j) break;
        swap(array, i, j);
    }
    swap(array, i, high);
    return i;
}

int quick_sort(int array[], int l, int r) {
    int count = 0;
    if (r <= l) return 0;
    int i = partition(array, l, r, count);
    return count + quick_sort(array, l, i - 1) + quick_sort(array, i + 1, r);
}


int main() {

    string filename("input.txt");
    int number;
    int arr[10000] = {};

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    int index = 0;

    while (input_file >> number) {
        cout << number << "  ";
        arr[index++] = number;
    }
    cout << endl;
    input_file.close();

    std::cout << "\n number of comparisons is " << quick_sort(arr, 0, n - 1) << std::endl;

    return 0;
}