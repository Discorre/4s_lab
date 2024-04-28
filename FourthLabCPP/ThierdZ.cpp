//#include <iostream>
//#include <random>
//#include <cmath>
//#include <vector>
//
//using namespace std;
//
//constexpr int NUM_BINS = 10; // ���������� ���������� ��� �������� ��-�������
//
//// ������� ��� ���������� �������� �������� ��-�������
//static double chiSquare(const vector<int>& observed, const vector<int>& expected) {
//    double chiSquareValue = 0.0;
//    for (size_t i = 0; i < observed.size(); ++i) {
//        chiSquareValue += pow(observed[i] - expected[i], 2) / expected[i];
//    }
//    return chiSquareValue;
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//
//    random_device gen;
//    uniform_int_distribution<> dis(1, 100); // ��������� ����� �� 1 �� 100
//
//    // ������� ��������
//    vector<int> arraySizes = { 50, 100, 1000 };
//    for (int arraySize : arraySizes) {
//        vector<int> array(arraySize); // ������������ ��������� ������ ��� �������
//
//        // ���������� �������
//        for (int& num : array) {
//            num = dis(gen);
//        }
//
//        // ���������� ����������� ������ ��� ������� ���������
//        vector<int> observed(NUM_BINS, 0);
//        for (int num : array) {
//            int bin = (num - 1) / (100 / NUM_BINS);
//            ++observed[bin];
//        }
//
//        // ���������� ��������� ������, ����������� ����������� �������������
//        vector<int> expected(NUM_BINS, arraySize / NUM_BINS);
//
//        // ���������� �������� �������� ��-�������
//        double chiSquareValue = chiSquare(observed, expected);
//
//        // ����� �����������
//        cout << "������ �������: " << arraySize << endl;
//        cout << "�������� �������� ��-�������: " << chiSquareValue << endl;
//
//        // ���������� �������� ��������
//        double criticalValue = 16.919; // ����������� �������� ��� 9 �������� ������� ��� alpha = 0.05
//        if (chiSquareValue > criticalValue) {
//            cout << "�������� ����������: ������������� �� �������� �������� �����������." << endl;
//        }
//        else {
//            cout << "�������� �������: ������������� �������� �����������." << endl;
//        }
//
//        // ���������� ���������� � ������������ ��������
//        double expectedMean = 50.5; // ��������� ������� ��� ������������ ������������� �� 1 �� 100
//        double actualMean = 0.0;
//
//        for (int num : array) {
//            actualMean += num;
//        }
//        actualMean /= arraySize;
//
//        cout << "��������� �������: " << expectedMean << endl;
//        cout << "����������� �������: " << actualMean << endl;
//        cout << endl;
//    }
//
//    return 0;
//}
