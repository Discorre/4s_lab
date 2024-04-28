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
//        cout << "������: n ������ ���� ������ ������ � >= 10." << endl;
//        return 1;
//    }
//
//    random_device genNum;
//    uniform_int_distribution<int> disNum(10, 100);
//
//    vector<int> arr1(n);
//    vector<int> arr2(n);
//
//    cout << "1 �������:" << endl;
//
//    cout << "������ arr1: ";
//    for (int i = 0; i < n; ++i) {
//        arr1[i] = disNum(genNum);
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
//
//    cout << "������ arr2: ";
//    for (int i = 0; i < n; ++i) {
//        arr2[i] = disNum(genNum);
//        cout << arr2[i] << " ";
//    }
//    cout << endl << endl;
//
//    cout << "2 �������: " << endl;
//
//    cout << "������� ����� �� ��������� [0, 10] � ������� arr1: ";
//    int count = 0;
//    for (int num : arr1) {
//        if (count <= 10 && is_prime(num)) {
//            cout << num << " ";
//        }
//        count++;
//    }
//    cout << endl;
//
//    cout << "������� ����� �� ��������� [0, 10] � ������� arr2: ";
//    count = 0;
//    for (int num : arr2) {
//        if (count <= 10 && is_prime(num)) {
//            cout << num << " ";
//        }
//        count++;
//    }
//    cout << endl << endl;
//
//    cout << "3 �������: " << endl;
//
//    insertion_sort_asc(arr1);
//    insertion_sort_desc(arr2);
//
//    cout << "��������������� ������ arr1 �� ��������: ";
//    for (int element : arr1) {
//        cout << element << " ";
//    }
//    cout << endl;
//
//    cout << "��������������� ������ arr2 �� ��������: ";
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
//    cout << "��������������� ������ arr1: ";
//    for (int element : arr1) {
//        cout << element << " ";
//    }
//    cout << endl;
//
//    cout << "��������������� ������ arr2: ";
//    for (int element : arr2) {
//        cout << element << " ";
//    }
//    cout << endl << endl;
//
//    cout << "4 �������" << endl;
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
//    cout << "�������� ������ ��������: ";
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
//    cout << "������ ����� �� ASCII �� ������ ��������: ";
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
//    cout << "������ ����� �� ASCII ����� ������ ��������: ";
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
//    cout << "������ ������ ����� ������ ��������: ";
//    for (char c : charArray) {
//        cout << c << " ";
//    }
//    cout << endl << endl;
//
//    cout << "5 �������" << endl;
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
//    cout << "�������� ������, ��������������� �� ��������: ";
//    for (int i = 0; i < size; ++i) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    cout << "������ � ����������, ����������� ������������� �����: ";
//    for (int num : repeatedDigitsArr) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    return 0;
//}