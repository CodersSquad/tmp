#include <functional>
#include <iostream>
#include <queue>
#include <string_view>
#include <vector>
#include "utils.h"

namespace utils {

    int generateRandomInt(int min, int max) {
    // Obtain a seed from the system clock
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Create a random number engine (Mersenne Twister is a good choice)
    std::mt19937 generator(seed);

    // Define a uniform integer distribution for the desired range
    std::uniform_int_distribution<int> distribution(min, max);

    // Generate and return the random number
    return distribution(generator);
  }

}

