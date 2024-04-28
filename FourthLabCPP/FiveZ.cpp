#include <iostream>
#include <vector>

using namespace std;

class RC4 {
private:
    vector<int> S;
    int i, j;

public:
    RC4(vector<int> key) {
        // Инициализация таблицы замен S
        S.resize(65536);
        for (int i = 0; i < 65536; i++) {
            S[i] = i;
        }

        // Перемешивание S с использованием ключа
        j = 0;
        for (int i = 0; i < 65536; i++) {
            j = (j + S[i] + key[i % key.size()]) % 65536;
            swap(S[i], S[j]);
        }

        // Инициализация индексов
        i = j = 0;
    }

    int generate() {
        // Псевдослучайная генерация
        i = (i + 1) % 65536;
        j = (j + S[i]) % 65536;
        swap(S[i], S[j]);
        int t = (S[i] + S[j]) % 65536;
        return S[t];
    }
};

int main() {
    // Пример использования
    vector<int> key = { 987656865 }; // Пример ключа, замените на свой
    RC4 rc4(key);

    // Генерация псевдослучайных чисел
    for (int k = 0; k < 100; k++) {
        cout << rc4.generate() << " ";
        if ((k + 1) % 10 == 0) cout << endl;
    }
    cout << endl;

    return 0;
}
