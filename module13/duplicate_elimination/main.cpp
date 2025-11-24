// get 20 intergers from user
// remove duplicates using unique_copy algorithm
// display unique values

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

// class for eliminating duplicate integers using unique_copy
class Deduplicator {
  private:
    std::array<int, 20> user_input; // array to store user input
    std::vector<int> unique_values; // vector to store unique values

  public:
    void read_input() {
        std::cout << "Enter 20 integers:" << std::endl;
        for (int i = 0; i < 20; ++i) {
            std::cin >> user_input[i];
        }
    }

    void deduplicate() {
        // sort input first for unique_copy algorithm
        std::sort(user_input.begin(), user_input.end());

        // directly copy unique elements into unique_values vector using unique_copy
        unique_values.clear(); // ensure vector is empty
        std::unique_copy(user_input.begin(), user_input.end(), std::back_inserter(unique_values));

        // print header for results
        std::cout << "Unique values: ";

        for (int value : unique_values) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Deduplicator deduplicator;
    deduplicator.read_input();
    deduplicator.deduplicate();
}
