//#include <iostream>
//#include <vector>
//#include <random>
//#include <ctime>
//#include <cmath>
//
//using namespace std;
//
//static void insertion_sort_asc(vector<int>& arr) {
//    for (int i = 1; i < arr.size() / 2; ++i) {
//        int key = arr[i];
//        int j = i - 1;
//        while (j >= 0 && arr[j] > key) {
//            arr[j + 1] = arr[j];
//            j = j - 1;
//        }
//        arr[j + 1] = key;
//    }
//}
//
//static void insertion_sort_desc(vector<int>& arr) {
//    for (int i = arr.size() / 2; i < arr.size(); ++i) {
//        int key = arr[i];
//        int j = i - 1;
//        while (j >= 0 && arr[j] < key) {
//            arr[j + 1] = arr[j];
//            j = j - 1;
//        }
//        arr[j + 1] = key;
//    }
//}
//
//static bool is_prime(int num) {
//    if (num <= 1) return false;
//    if (num == 2) return true;
//    if (num % 2 == 0) return false;
//    for (int i = 3; i <= sqrt(num); i += 2) {
//        if (num % i == 0) return false;
//    }
//    return true;
//}
//
//bool hasRepeatedDigits(int num) {
//    vector<int> count(10, 0);
//    while (num > 0) {
//        int digit = num % 10;
//        if (count[digit] > 0) {
//            return true;
//        }
//        count[digit]++;
//        num /= 10;
//    }
//    return false;
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//
//    const int n = 12;
//
//    if (n < 10 || n % 2 != 0) {
//        cout << "Ошибка: n должно быть четным числом и >= 10." << endl;
//        return 1;
//    }
//
//    random_device genNum;
//    uniform_int_distribution<int> disNum(10, 100);
//
//    vector<int> arr1(n);
//    vector<int> arr2(n);
//
//    cout << "1 ЗАДАНИЕ:" << endl;
//
//    cout << "Массив arr1: ";
//    for (int i = 0; i < n; ++i) {
//        arr1[i] = disNum(genNum);
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
//
//    cout << "Массив arr2: ";
//    for (int i = 0; i < n; ++i) {
//        arr2[i] = disNum(genNum);
//        cout << arr2[i] << " ";
//    }
//    cout << endl << endl;
//
//    cout << "2 ЗАДАНИЕ: " << endl;
//
//    cout << "Простые числа из диапазона [0, 10] в массиве arr1: ";
//    int count = 0;
//    for (int num : arr1) {
//        if (count <= 10 && is_prime(num)) {
//            cout << num << " ";
//        }
//        count++;
//    }
//    cout << endl;
//
//    cout << "Простые числа из диапазона [0, 10] в массиве arr2: ";
//    count = 0;
//    for (int num : arr2) {
//        if (count <= 10 && is_prime(num)) {
//            cout << num << " ";
//        }
//        count++;
//    }
//    cout << endl << endl;
//
//    cout << "3 ЗАДАНИЕ: " << endl;
//
//    insertion_sort_asc(arr1);
//    insertion_sort_desc(arr2);
//
//    cout << "Отсортированный массив arr1 до переноса: ";
//    for (int element : arr1) {
//        cout << element << " ";
//    }
//    cout << endl;
//
//    cout << "Отсортированный массив arr2 до переноса: ";
//    for (int element : arr2) {
//        cout << element << " ";
//    }
//    cout << endl;
//
//    for (int i = 0; i < n / 2; ++i) {
//        int temp = arr1[i];
//        arr1[i] = arr2[i];
//        arr2[i] = temp;
//    }
//
//    cout << "Отсортированный массив arr1: ";
//    for (int element : arr1) {
//        cout << element << " ";
//    }
//    cout << endl;
//
//    cout << "Отсортированный массив arr2: ";
//    for (int element : arr2) {
//        cout << element << " ";
//    }
//    cout << endl << endl;
//
//    cout << "4 ЗАДАНИЕ" << endl;
//
//    random_device gen;
//    uniform_int_distribution<int> dis(65, 255);
//
//    const int arraySize = 20;
//    vector<char> charArray(arraySize);
//    vector<int> char2NumArray(arraySize);
//    for (char& c : charArray) {
//        int asciiCode = dis(gen);
//        while (true) {
//            if (asciiCode > 90 && asciiCode < 97) {
//                asciiCode += 6;
//            }
//            if ((asciiCode >= 65 && asciiCode <= 122) || (asciiCode >= 192 && asciiCode <= 255) || asciiCode == 168) {
//                c = static_cast<char>(asciiCode);
//                break;
//            }
//            else {
//                asciiCode = dis(gen);
//            }
//        }
//    }
//
//    cout << "Исходный массив символов: ";
//    for (char c : charArray) {
//        cout << c << " ";
//    }
//    cout << endl;
//
//    int i = 0;
//    for (char c : charArray) {
//        char2NumArray[i++] = static_cast<int>(c);
//    }
//
//    cout << "Массив чисел по ASCII до замены регистра: ";
//    for (int c : char2NumArray) {
//        cout << c << " ";
//    }
//    cout << endl;
//
//    int j = 0;
//    for (int c : char2NumArray) {
//        if ((c >= 65 && c <= 90) || (c >= -64 && c <= -33)) {
//            c += 32;
//            char2NumArray[j] = c;
//        }
//        else if ((c >= 91 && c <= 122) || (c >= -32 && c <= -1)) {
//            c -= 32;
//            char2NumArray[j] = c;
//        }
//        j++;
//    }
//
//    cout << "Массив чисел по ASCII после замены регистра: ";
//    for (int c : char2NumArray) {
//        cout << c << " ";
//    }
//    cout << endl;
//
//    int k = 0;
//    for (int c : char2NumArray) {
//        charArray[k++] = static_cast<char>(c);
//    }
//
//    cout << "Массив буковъ после замены регистра: ";
//    for (char c : charArray) {
//        cout << c << " ";
//    }
//    cout << endl << endl;
//
//    cout << "5 ЗАДАНИЕ" << endl;
//
//    const int size = 10;
//    vector<int> arr(size);
//    random_device gen2;
//    uniform_int_distribution<int> dist(1000, 2000);
//    for (int i = 0; i < size; ++i) {
//        arr[i] = dist(gen);
//    }
//
//    sort(arr.beg	in(), arr.end(), greater<int>());
//
//    vector<int> repeatedDigitsArr;
//    for (int num : arr) {
//        if (hasRepeatedDigits(num)) {
//            repeatedDigitsArr.push_back(num);
//        }
//    }
//
//    cout << "Исходный массив, отсортированный по убыванию: ";
//    for (int i = 0; i < size; ++i) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    cout << "Массив с элементами, содержащими повторяющиеся цифры: ";
//    for (int num : repeatedDigitsArr) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    return 0;
//}