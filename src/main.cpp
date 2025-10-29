#include <iostream>
#include "csv_reader.h"




int main() {
        Dataset data = readCSV("../data/mnist_test.csv", 10000); // assuming 10 classes for one-hot encoding
        std::cout << "Loaded " << data.images.size() << " samples." << std::endl;
    return 0;
}