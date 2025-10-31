#include <iostream>
#include "csv_reader.h"

int main()
{
    Dataset test = readCSV("../data/mnist_test.csv", 10000); 
    std::cout << "Loaded " << test.images.size() << " samples." << std::endl;
    Dataset train = readCSV("../data/mnist_train.csv", 60000); 
    std::cout << "Loaded " << train.images.size() << " samples." << std::endl;
    return 0;
}