//#include <iostream>
//#include <vector>
//#include <random>
//#include <algorithm>
//
//using namespace std;
//
//static bool randomChange(int32_t round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<> dis(0, 1); // случайный выбор между 0 и 1 (0 - изменение, 1 - сотрудничество)
//
//    return dis(gen); // возвращаем случайное действие (0 или 1)
//}
//
//// Определение стратегий
//static bool alwaysCooperate(int32_t round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    return true; // Всегда выбираем сотрудничество
//}
//
//static bool alwaysBetray(int32_t round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    return false; // Всегда выбираем предательство
//}
//
//static bool unforgiving(int32_t round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    static bool cooperate = true; // Флаг для хранения текущего выбора: сотрудничество или изменение
//    static int betrayal_count = 0; // Счетчик штрафов за сотрудничество
//
//    if (round_number == 0) {
//        betrayal_count = 0; // Обнуляем счетчик в начале каждой игры
//        return true; // В первом раунде всегда сотрудничаем
//    }
//
//    // Проверяем результаты текущего раунда
//    if (self_choices[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(round_number) - 1] && !enemy_choices[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(round_number) - 1]) {
//        betrayal_count++; // Увеличиваем счетчик штрафов за сотрудничество
//    }
//
//    // Проверяем, превышает ли количество штрафов определенный предел
//    if (betrayal_count >= 3) { // Например, если штрафов больше трех
//        cooperate = false; // Переходим к постоянному предательству
//    }
//
//    return cooperate;
//}
//
//static bool titForTat(int32_t round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    if (round_number == 0) {
//        return true; // В первом раунде выбираем сотрудничество
//    }
//
//    // Возвращаем действие противника из предыдущего раунда
//    return enemy_choices[static_cast<vector<bool, allocator<bool>>::size_type>(round_number) - 1];
//}
//
//static bool pavlov(int32_t round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    if (round_number == 0) {
//        return true; // В первом раунде выбираем сотрудничество
//    }
//
//    int self_last_score = 0, enemy_last_score = 0;
//
//    // Расчет выигрышей в предыдущем раунде
//    if (self_choices[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(round_number) - 1] && enemy_choices[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(round_number) - 1]) {
//        self_last_score = 24;
//        enemy_last_score = 24;
//    }
//    else if (!self_choices[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(round_number) - 1] && !enemy_choices[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(round_number) - 1]) {
//        self_last_score = 4;
//        enemy_last_score = 4;
//    }
//    else if (self_choices[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(round_number) - 1] && !enemy_choices[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(round_number) - 1]) {
//        self_last_score = 0;
//        enemy_last_score = 20;
//    }
//    else {
//        self_last_score = 20;
//        enemy_last_score = 0;
//    }
//
//    // Обновление стратегии на основе результатов предыдущего раунда
//    if (self_last_score == enemy_last_score) {
//        return self_choices[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(round_number) - 1]; // Повторяем предыдущее действие
//    }
//    else if (self_last_score > enemy_last_score) {
//        return true; // Сотрудничаем
//    }
//    else {
//        return false; // Изменяем
//    }
//}
//
//
//int main() {
//    setlocale(LC_ALL, "ru");
//
//    random_device gen;
//    uniform_int_distribution<> dis(0, 6); // случайный выбор стратегии от 0 до 3
//    uniform_int_distribution<> dis2(100, 200); // случайный выбор стратегии от 0 до 3
//
//    int game_rounds = 10;//dis2(gen); // уменьшим количество раундов для наглядности
//
//    vector<bool> self_choices(game_rounds, false), enemy_choices(game_rounds, false);
//    vector<bool (*)(int32_t, const vector<bool>&, const vector<bool>&)> strategies = { alwaysCooperate, alwaysBetray, titForTat, pavlov, randomChange, unforgiving };
//
//    int count = 0;
//    for (auto strategy : strategies) {
//        int self_score = 0, enemy_score = 0;
//
//        cout << "Стратегия игрока: " << (strategy == alwaysCooperate ? "Всегда сотрудничать" : (strategy == alwaysBetray ? "Всегда изменять" : (strategy == titForTat ? "TIT-FOR-TAT" : (strategy == pavlov ? "PAVLOV" : (strategy == randomChange ? "RANDOM" : ("Стратегия непрощения")))))) << endl;
//
//        int enemy_strategy_index = dis(gen); // случайный выбор стратегии противника
//        auto enemy_strategy = strategies[enemy_strategy_index];
//        cout << "Стратегия противника: " << (enemy_strategy == alwaysCooperate ? "Всегда сотрудничать" : (enemy_strategy == alwaysBetray ? "Всегда изменять" : (enemy_strategy == titForTat ? "TIT-FOR-TAT" : (enemy_strategy == pavlov ? "PAVLOV" : (enemy_strategy == randomChange ? "RANDOM" : ("Стратегия непрощения")))))) << endl;
//
//        for (int round = 0; round < game_rounds; ++round) {
//            bool self_action = strategy(round, self_choices, enemy_choices);
//            bool enemy_action = enemy_strategy(round, enemy_choices, self_choices);
//
//            self_choices[round] = self_action;
//            enemy_choices[round] = enemy_action;
//
//            cout << "Раунд " << round + 1 << ":\t\t";
//            cout << (self_action ? "+" : "-") << "\t" << (enemy_action ? "+" : "-") << endl;
//
//            if (self_action && enemy_action) {
//                self_score += 24;
//                enemy_score += 24;
//            }
//            else if (!self_action && !enemy_action) {
//                self_score += 4;
//                enemy_score += 4;
//            }
//            else if (self_action && !enemy_action) {
//                self_score += 0;
//                enemy_score += 20;
//            }
//            else {
//                self_score += 0;
//                enemy_score += 20;
//            }
//        }
//        if (count < 2) {
//            count++;
//        }
//        else {
//            break;
//        }
//
//        cout << "Очки игрока: " << self_score << endl;
//        cout << "Очки противника: " << enemy_score << endl;
//        cout << endl;
//    }
//
//    return 0;
//}
