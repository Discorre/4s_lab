import org.jetbrains.annotations.Contract;

import java.util.Random;

public class ThierdZ {
    static final int NUM_BINS = 10; // Количество интервалов для критерия хи-квадрат

    // Функция для вычисления значения критерия хи-квадрат
    static double chiSquare(int[] observed, int[] expected) {
        double chiSquareValue = 0.0;
        for (int i = 0; i < observed.length; ++i) {
            chiSquareValue += Math.pow(observed[i] - expected[i], 2) / expected[i];
        }
        return chiSquareValue;
    }

    public static void main(String[] args) {
        Random gen = new Random();
        int[] arraySizes = { 50, 100, 1000 };
        for (int arraySize : arraySizes) {
            int[] array = new int[arraySize];

            // Заполнение массива
            for (int i = 0; i < arraySize; i++) {
                array[i] = gen.nextInt(100) + 1; // Генерация чисел от 1 до 100
            }

            // Вычисление наблюдаемых частот для каждого интервала
            int[] observed = new int[NUM_BINS];
            for (int num : array) {
                int bin = (num - 1) / (100 / NUM_BINS);
                observed[bin]++;
            }

            // Вычисление ожидаемых частот, предполагая равномерное распределение
            int[] expected = new int[NUM_BINS];
            for (int i = 0; i < NUM_BINS; i++) {
                expected[i] = arraySize / NUM_BINS;
            }

            // Вычисление значения критерия хи-квадрат
            double chiSquareValue = chiSquare(observed, expected);

            // Вывод результатов
            System.out.println("Размер массива: " + arraySize);
            System.out.println("Значение критерия хи-квадрат: " + chiSquareValue);

            // Проведение проверки гипотезы
            double criticalValue = 16.919; // Критическое значение для 9 степеней свободы при alpha = 0.05
            if (chiSquareValue > criticalValue) {
                System.out.println("Гипотеза отвергнута: Распределение не является примерно равномерным.");
            } else {
                System.out.println("Гипотеза принята: Распределение примерно равномерное.");
            }

            // Вычисление ожидаемого и фактического среднего
            double expectedMean = 50.5; // Ожидаемое среднее для равномерного распределения от 1 до 100
            double actualMean = 0.0;

            for (int num : array) {
                actualMean += num;
            }
            actualMean /= arraySize;

            System.out.println("Ожидаемое среднее: " + expectedMean);
            System.out.println("Фактическое среднее: " + actualMean);
            System.out.println();
        }
    }
}
