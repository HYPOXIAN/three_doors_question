#include <iostream>
#include <random>
#include <vector>
#include<algorithm>

using namespace std;

int main() {
    const int NUM_SIMULATIONS = 100000;
    int win_if_switch = 0;
    int win_if_stick = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> door_dist(0, 2);

    for (int i = 0; i < NUM_SIMULATIONS; ++i) {
        int prize_door = door_dist(gen);
        int player_choice = door_dist(gen);

        vector<int> available_doors = {0, 1, 2};
        available_doors.erase(remove(available_doors.begin(), available_doors.end(), player_choice), available_doors.end());
        available_doors.erase(remove(available_doors.begin(), available_doors.end(), prize_door), available_doors.end());
        int host_choice = available_doors[door_dist(gen) % available_doors.size()];

        int new_choice = 3 - player_choice - host_choice;

        if (new_choice == prize_door) {
            ++win_if_switch;
        }
        if (player_choice == prize_door) {
            ++win_if_stick;
        }
    }

    cout << "Total simulations: " << NUM_SIMULATIONS << endl;
    cout << "Wins if switch: " << win_if_switch << " (" << (win_if_switch * 100.0 / NUM_SIMULATIONS) << "%)" << endl;
    cout << "Wins if stick: " << win_if_stick << " (" << (win_if_stick * 100.0 / NUM_SIMULATIONS) << "%)" << endl;

    return 0;
}
