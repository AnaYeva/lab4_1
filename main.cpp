#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {

    int pivot = arr[end];

    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {

        if (arr[j] > pivot) {

            i++;
            swap(arr[i], arr[j]);
        }
    }
        swap(arr[i + 1], arr[end]);
        return i + 1;
    }


void quickSort(int arr[], int start, int end){

    if (start < end) {

        int p = partition(arr, start, end);

        quickSort(arr, start, p - 1);

        quickSort(arr, p + 1, end);
    }
}

void print(int arr[], int length)
{
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
}
bool prime(int n) {
    bool is_prime = true;

    if (n == 0 || n == 1) {
        is_prime = false;
    }

    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }

    }
    return is_prime;
}

int main()
{
    std::cout << "Enter how many number you want to input: ";
    int length;
    std::cin >> length;
    int *array = new int[length];

    for (int i = 0; i < length; i++) {
        cin >> array[i];
    }

    bool allPrime =true;
    for (int i = 0; i < length; i++) {
        if(prime(array[i])){
            allPrime=false;
            break;
        }
    }
    if(allPrime){
        quickSort(array, 0, length-1);
    }
    print (array, length);
    delete[] array;
    return 0;
}

