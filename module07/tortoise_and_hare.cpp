#include <chrono>   // for seconds
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time to use as random number generation seed
#include <iostream> // access to input/output streams
#include <string>
#include <thread> // for sleep

// length of race
const int finish_line{70};

// tortoise movement rules, using pointer based pass by reference
void move_tortoise(int *tortoise_position) {

    // move values
    const int fast_plod{3};
    const int slip{-6};
    const int slow_plod{1};

    // cumulative percentage cutoffs
    const int fast_plod_roll{5};  // 50% chance for fast plod
    const int slip_roll{7};       // 20% chance for slip
    const int slow_plod_roll{10}; // 30% chance for slow plod

    // generate random number for move chance
    const int random_min = 1;
    const int random_max = 10;
    int move = rand() % (random_max - random_min + 1) + random_min;

    // make move
    if (move <= fast_plod_roll) {
        *tortoise_position += fast_plod;
    } else if (move <= slip_roll) {
        *tortoise_position += slip;
    } else { // move <= slow_plod_roll
        *tortoise_position += slow_plod;
    }

    // limit position to 1 through finish_line
    if (*tortoise_position < 1) {
        *tortoise_position = 1;
    } else if (*tortoise_position > finish_line) {
        *tortoise_position = finish_line;
    }
}

// hare movement rules, using pointer based pass by reference
void move_hare(int *hare_position) {

    // move values
    const int sleep{0};
    const int big_hop{9};
    const int big_slip{-12};
    const int small_hop{1};
    const int small_slip{-2};

    // cumulative percentage cutoffs
    const int sleep_roll{2};       // 20% chance for sleep
    const int big_hop_roll{4};     // 20% chance for big hop
    const int big_slip_roll{5};    // 10% for big slip
    const int small_hop_roll{8};   // 30% chance for small hop
    const int small_slip_roll{10}; // 20% chance for small slip

    // generate random number for move chance
    const int random_min = 1;
    const int random_max = 10;
    int move = rand() % (random_max - random_min + 1) + random_min;

    // make move
    if (move <= sleep_roll) {
        *hare_position += sleep;
    } else if (move <= big_hop_roll) {
        *hare_position += big_hop;
    } else if (move == big_slip_roll) {
        *hare_position += big_slip;
    } else if (move <= small_hop_roll) {
        *hare_position += small_hop;
    } else { // move <= small_slip_roll
        *hare_position += small_slip;
    }

    // limit position to 1 through finish_line
    if (*hare_position < 1) {
        *hare_position = 1;
    } else if (*hare_position > finish_line) {
        *hare_position = finish_line;
    }
}

// display race with positions
void print_race(int tortoise_position, int hare_position) {
    for (int i{1}; i <= finish_line; ++i) {
        if (i == tortoise_position && tortoise_position == hare_position) {
            std::cout << "OUCH!!!";
            i += std::string("OUCH!!!").length() - 1; // skip extra characters
        } else if (i == tortoise_position) {
            std::cout << "T";
        } else if (i == hare_position) {
            std::cout << "H";
        } else {
            std::cout << "_";
        }
    }
    std::cout << std::endl;
}

int main() {
    // seed random number generator with current time
    srand(static_cast<unsigned int>(time(0)));

    // move interval for simulating clock speed
    const int move_interval{1}; // seconds

    // starting positions
    int tortoise_position{1};
    int hare_position{1};

    // display starting message
    std::cout << "BANG !!!!!" << std::endl;
    std::cout << "AND THEY'RE OFF !!!!!" << std::endl;

    // race loop
    while (tortoise_position < finish_line && hare_position < finish_line) {
        // make moves
        move_tortoise(&tortoise_position);
        move_hare(&hare_position);

        // display race state
        print_race(tortoise_position, hare_position);

        // use sleep to simulate clock
        std::this_thread::sleep_for(std::chrono::seconds(move_interval));
    }

    // check for winner and display results
    if (tortoise_position >= finish_line && hare_position >= finish_line) {
        std::cout << "It's a tie." << std::endl;
    } else if (tortoise_position >= finish_line) {
        std::cout << "TORTOISE WINS!!! YAY!!!" << std::endl;
    } else {
        std::cout << "Hare wins. Yuch." << std::endl;
    }
}
