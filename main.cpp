
#include <algorithm>
#include <fstream>
#include <iostream>

#include "functions.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }

    std::fstream in(argv[1], std::ios_base::in | std::ios_base::binary);
    std::fstream out;
    
    if (argc < 3) {
        out.std::ios::rdbuf(std::cout.rdbuf());
    }
    else {
        out.open(argv[2], std::ios_base::out | std::ios_base::binary);
    }

    if (!in.good()) {
        std::cerr << "could not open input file\n";
    }
    else if(!out.good()) {
        std::cerr << "could not open output file\n";
    }
    else {
        auto words = map_to_list(calc_words(in));
        double sum = std::accumulate(words.begin(), words.end(), 0.0, num_sum);

        words.sort(cmp);
        words_to_CSV(words.begin(), words.end(), out, sum);
    }

    return 0;
}
