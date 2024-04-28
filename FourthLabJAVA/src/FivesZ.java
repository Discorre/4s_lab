import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class FivesZ {
    private List<Integer> S;
    private int i, j;

    public FivesZ(List<Integer> key) {
        // Инициализация таблицы замен S
        S = new ArrayList<>();
        for (int i = 0; i < 1024; i++) {
            S.add(i);
        }

        // Перемешивание S с использованием ключа
        j = 0;
        for (int i = 0; i < 1024; i++) {
            j = (j + S.get(i) + key.get(i % key.size())) % 1024;
            Collections.swap(S, i, j);
        }

        // Инициализация индексов
        i = j = 0;
    }

    public int generate() {
        // Псевдослучайная генерация
        i = (i + 1) % 1024;
        j = (j + S.get(i)) % 1024;
        Collections.swap(S, i, j);
        int t = (S.get(i) + S.get(j)) % 1024;
        return S.get(t);
    }

    public static void main(String[] args) {
        // Пример использования
        List<Integer> key = new ArrayList<>();
        key.add(987656865);
        FivesZ rc4 = new FivesZ(key);

        // Генерация псевдослучайных чисел
        for (int k = 0; k < 100; k++) {
            System.out.print(rc4.generate() + " ");
            if ((k + 1) % 10 == 0) System.out.println();
        }
        System.out.println();
    }
}
