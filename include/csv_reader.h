#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>
#include <vector>

struct Dataset {
    std::vector<std::vector<double>> images; //each image data stored in one line
    std::vector<std::vector<double>> labels; //each target label stored in one line (one-hot encoded)
};

Dataset readCSV(const std::string &filename, int size);


#endif