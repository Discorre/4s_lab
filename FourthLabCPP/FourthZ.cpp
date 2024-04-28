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
//    uniform_int_distribution<> dis(0, 1); // ��������� ����� ����� 0 � 1 (0 - ���������, 1 - ��������������)
//
//    return dis(gen); // ���������� ��������� �������� (0 ��� 1)
//}
//
//// ����������� ���������
//static bool alwaysCooperate(int32_t round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    return true; // ������ �������� ��������������
//}
//
//static bool alwaysBetray(int32_t round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    return false; // ������ �������� �������������
//}
//
//static bool unforgiving(int32_t round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    static bool cooperate = true; // ���� ��� �������� �������� ������: �������������� ��� ���������
//    static int betrayal_count = 0; // ������� ������� �� ��������������
//
//    if (round_number == 0) {
//        betrayal_count = 0; // �������� ������� � ������ ������ ����
//        return true; // � ������ ������ ������ ������������
//    }
//
//    // ��������� ���������� �������� ������
//    if (self_choices[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(round_number) - 1] && !enemy_choices[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(round_number) - 1]) {
//        betrayal_count++; // ����������� ������� ������� �� ��������������
//    }
//
//    // ���������, ��������� �� ���������� ������� ������������ ������
//    if (betrayal_count >= 3) { // ��������, ���� ������� ������ ����
//        cooperate = false; // ��������� � ����������� �������������
//    }
//
//    return cooperate;
//}
//
//static bool titForTat(int32_t round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    if (round_number == 0) {
//        return true; // � ������ ������ �������� ��������������
//    }
//
//    // ���������� �������� ���������� �� ����������� ������
//    return enemy_choices[static_cast<vector<bool, allocator<bool>>::size_type>(round_number) - 1];
//}
//
//static bool pavlov(int32_t round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    if (round_number == 0) {
//        return true; // � ������ ������ �������� ��������������
//    }
//
//    int self_last_score = 0, enemy_last_score = 0;
//
//    // ������ ��������� � ���������� ������
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
//    // ���������� ��������� �� ������ ����������� ����������� ������
//    if (self_last_score == enemy_last_score) {
//        return self_choices[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(round_number) - 1]; // ��������� ���������� ��������
//    }
//    else if (self_last_score > enemy_last_score) {
//        return true; // ������������
//    }
//    else {
//        return false; // ��������
//    }
//}
//
//
//int main() {
//    setlocale(LC_ALL, "ru");
//
//    random_device gen;
//    uniform_int_distribution<> dis(0, 6); // ��������� ����� ��������� �� 0 �� 3
//    uniform_int_distribution<> dis2(100, 200); // ��������� ����� ��������� �� 0 �� 3
//
//    int game_rounds = 10;//dis2(gen); // �������� ���������� ������� ��� �����������
//
//    vector<bool> self_choices(game_rounds, false), enemy_choices(game_rounds, false);
//    vector<bool (*)(int32_t, const vector<bool>&, const vector<bool>&)> strategies = { alwaysCooperate, alwaysBetray, titForTat, pavlov, randomChange, unforgiving };
//
//    int count = 0;
//    for (auto strategy : strategies) {
//        int self_score = 0, enemy_score = 0;
//
//        cout << "��������� ������: " << (strategy == alwaysCooperate ? "������ ������������" : (strategy == alwaysBetray ? "������ ��������" : (strategy == titForTat ? "TIT-FOR-TAT" : (strategy == pavlov ? "PAVLOV" : (strategy == randomChange ? "RANDOM" : ("��������� ����������")))))) << endl;
//
//        int enemy_strategy_index = dis(gen); // ��������� ����� ��������� ����������
//        auto enemy_strategy = strategies[enemy_strategy_index];
//        cout << "��������� ����������: " << (enemy_strategy == alwaysCooperate ? "������ ������������" : (enemy_strategy == alwaysBetray ? "������ ��������" : (enemy_strategy == titForTat ? "TIT-FOR-TAT" : (enemy_strategy == pavlov ? "PAVLOV" : (enemy_strategy == randomChange ? "RANDOM" : ("��������� ����������")))))) << endl;
//
//        for (int round = 0; round < game_rounds; ++round) {
//            bool self_action = strategy(round, self_choices, enemy_choices);
//            bool enemy_action = enemy_strategy(round, enemy_choices, self_choices);
//
//            self_choices[round] = self_action;
//            enemy_choices[round] = enemy_action;
//
//            cout << "����� " << round + 1 << ":\t\t";
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
//        cout << "���� ������: " << self_score << endl;
//        cout << "���� ����������: " << enemy_score << endl;
//        cout << endl;
//    }
//
//    return 0;
//}
