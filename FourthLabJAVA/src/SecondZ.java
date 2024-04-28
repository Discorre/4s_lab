import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class SecondZ {

    static void insertionSortAsc(@NotNull List<Integer> arr) {
        for (int i = 1; i < arr.size() / 2; ++i) {
            int key = arr.get(i);
            int j = i - 1;
            while (j >= 0 && arr.get(j) > key) {
                arr.set(j + 1, arr.get(j));
                j = j - 1;
            }
            arr.set(j + 1, key);
        }
    }

    static void insertionSortDesc(@NotNull List<Integer> arr) {
        for (int i = arr.size() / 2; i < arr.size(); ++i) {
            int key = arr.get(i);
            int j = i - 1;
            while (j >= 0 && arr.get(j) < key) {
                arr.set(j + 1, arr.get(j));
                j = j - 1;
            }
            arr.set(j + 1, key);
        }
    }

    static boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }

    static boolean hasRepeatedDigits(int num) {
        int[] count = new int[10];
        while (num > 0) {
            int digit = num % 10;
            if (count[digit] > 0) {
                return true;
            }
            count[digit]++;
            num /= 10;
        }
        return false;
    }

    public static void main(String[] args) {
        final int n = 12;

        if (n < 10 || n % 2 != 0) {
            System.out.println("Ошибка: n должно быть четным числом и >= 10.");
            System.exit(1);
        }

        Random gen = new Random();
        List<Integer> arr1 = new ArrayList<>();
        List<Integer> arr2 = new ArrayList<>();

        System.out.println("1 ЗАДАНИЕ:");

        System.out.print("Массив arr1: ");
        for (int i = 0; i < n; ++i) {
            arr1.add(10 + gen.nextInt(91));
            System.out.print(arr1.get(i) + " ");
        }
        System.out.println();

        System.out.print("Массив arr2: ");
        for (int i = 0; i < n; ++i) {
            arr2.add(10 + gen.nextInt(91));
            System.out.print(arr2.get(i) + " ");
        }
        System.out.println("\n");

        System.out.println("2 ЗАДАНИЕ: ");

        System.out.print("Простые числа из диапазона [0, 10] в массиве arr1: ");
        int count = 0;
        for (int num : arr1) {
            if (count <= 10 && isPrime(num)) {
                System.out.print(num + " ");
            }
            count++;
        }
        System.out.println();

        System.out.print("Простые числа из диапазона [0, 10] в массиве arr2: ");
        count = 0;
        for (int num : arr2) {
            if (count <= 10 && isPrime(num)) {
                System.out.print(num + " ");
            }
            count++;
        }
        System.out.println("\n");

        System.out.println("3 ЗАДАНИЕ: ");

        insertionSortAsc(arr1);
        insertionSortDesc(arr2);

        System.out.print("Отсортированный массив arr1 до переноса: ");
        for (int element : arr1) {
            System.out.print(element + " ");
        }
        System.out.println();

        System.out.print("Отсортированный массив arr2 до переноса: ");
        for (int element : arr2) {
            System.out.print(element + " ");
        }
        System.out.println();

        for (int i = 0; i < n / 2; ++i) {
            int temp = arr1.get(i);
            arr1.set(i, arr2.get(i));
            arr2.set(i, temp);
        }

        System.out.print("Отсортированный массив arr1: ");
        for (int element : arr1) {
            System.out.print(element + " ");
        }
        System.out.println();

        System.out.print("Отсортированный массив arr2: ");
        for (int element : arr2) {
            System.out.print(element + " ");
        }
        System.out.println("\n");

        System.out.println("4 ЗАДАНИЕ");
        // Определение размера списка
        int size = 12;

        // Создание списка символов
        ArrayList<Character> charList = new ArrayList<>();

        // Инициализация списка случайными символами верхнего или нижнего регистра
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            char randomChar;
            if (random.nextBoolean()) { // случайный выбор алфавита
                randomChar = (char) (random.nextInt(26) + 'a'); // случайная буква латиницы нижнего регистра
            } else {
                randomChar = (char) (random.nextInt(32) + 'А'); // случайная буква кириллицы верхнего регистра
            }
            if (random.nextBoolean()) { // случайный выбор регистра
                randomChar = Character.toUpperCase(randomChar);
            }
            charList.add(randomChar);
        }

        // Вывод исходного списка
        System.out.print("Исходный список: ");
        for (char ch : charList) {
            System.out.print(ch + " ");
        }
        System.out.println();

        // Замена регистра букв в списке
        int i1 = 0;
        for (char ch: charList){
            ch = charList.get(i1);
            if (Character.isLowerCase(ch)) {
                charList.set(i1, Character.toUpperCase(ch));
            } else if (Character.isUpperCase(ch)) {
                charList.set(i1, Character.toLowerCase(ch));
            }
            i1++;
        }

        // Вывод измененного списка
        System.out.print("Список с измененным регистром: ");
        for (char ch : charList) {
            System.out.print(ch + " ");
        }
        System.out.println("\n");

        System.out.println("5 ЗАДАНИЕ");

        final int sizeArr = 10;
        List<Integer> numList = new ArrayList<>();

        for (int i = 0; i < sizeArr; ++i) {
            numList.add(1000 + gen.nextInt(1001));
        }

        numList.sort(null);

        List<Integer> repeatedDigitsList = new ArrayList<>();
        for (int num : numList) {
            if (hasRepeatedDigits(num)) {
                repeatedDigitsList.add(num);
            }
        }

        System.out.print("Исходный массив, отсортированный по возрастанию: ");
        for (int num : numList) {
            System.out.print(num + " ");
        }
        System.out.println();

        System.out.print("Массив с элементами, содержащими повторяющиеся цифры: ");
        for (int num : repeatedDigitsList) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
