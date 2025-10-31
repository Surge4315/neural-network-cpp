#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "csv_reader.h"

Dataset readCSV(const std::string &filename, int size)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
        exit(EXIT_FAILURE);
    }

    Dataset dataset;
    std::string line;

    // Skip the first line (header)
    if (!std::getline(file, line))
    {
        std::cerr << "File is empty: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    while (std::getline(file, line))
    {
        if (line.empty())
            continue; // skip empty lines

        std::vector<double> image(784, 0.0); //28x28
        std::vector<double> label(10, 0.0); //0-9 hence vector of size 10

        std::stringstream ss(line);
        std::string value;

        bool isLabel = true;
        int labelIndex = -1;

        while (std::getline(ss, value, ','))
        {
            try
            {
                double val = std::stod(value);
                if (isLabel)
                {
                    labelIndex = static_cast<int>(val);
                    if (labelIndex < 0 || labelIndex >= size)
                    {
                        std::cerr << "Label out of range: " << labelIndex << std::endl;
                        exit(EXIT_FAILURE);
                    }
                    isLabel = false;
                }
                else
                {
                    image.push_back(val / 255.0); // Normalize pixel value
                }
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << "Invalid number in CSV: " << value << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        label[labelIndex] = 1.0; // One-hot encoding
        /*
        for (int i = 0; i < label.size(); i++)
        {
            std::cout << label[i] << " ";
        }
        std::cout << std::endl
                  << std::endl;
        */
        dataset.labels.push_back(label);
        dataset.images.push_back(image);
    }

    return dataset;
}
