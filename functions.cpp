
#include "functions.h"


std::map<std::string, unsigned> calc_words(std::istream &in) {
    std::string line;
    std::map<std::string, unsigned> words;

    while (in.good()) {
        std::getline(in, line);

        for (auto it1 = line.begin(); line.end() != it1; ) {
            auto it2 = it1;

            while ((line.end() != it2) && !isalnum(*it2))
                ++it2;

            it1 = it2;
            
            while((line.end() != it2) && isalnum(*it2))
                ++it2;


            if (it1 != it2)
                ++words[std::string(it1, it2)];

            it1 = it2;
        }
    }

    return words;
}

std::list<std::pair<std::string, unsigned> >  map_to_list(const std::map<std::string, unsigned> &words) 
{
    std::list<std::pair<std::string, unsigned> > output;

    for (auto it = words.begin(); words.end() != it; ++it)
        output.push_back(*it);

    return output;
}

bool cmp(const std::pair<std::string, unsigned> &v1, const std::pair<std::string, unsigned> &v2)
{
    return v1.second > v2.second;
}

double num_sum(double v1, const std::pair<std::string, unsigned> &v2)
{
    return v1 + static_cast<double>(v2.second);
}
