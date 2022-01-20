
#include <algorithm>
#include <iostream>
#include <list>
#include <fstream>
#include <map>
#include <numeric>
#include <string>


std::map<std::string, unsigned> calc_words(std::istream &in);

std::list<std::pair<std::string, unsigned> > map_to_list(const std::map<std::string, unsigned> &words);

template<class Iterator>
void words_to_CSV(Iterator first, Iterator last, std::ostream &out, double sum = 0) {
    while (first != last) {
        out << first->first << "," << first->second;
        if (0.0 < sum)
            out << "," << (100.0 * static_cast<double>(first->second) / sum) << "%";
        out << "\n";
        ++first;
    }
}

bool cmp(const std::pair<std::string, unsigned> &v1, const std::pair<std::string, unsigned> &v2);

double num_sum(double v1, const std::pair<std::string, unsigned> &v2);
