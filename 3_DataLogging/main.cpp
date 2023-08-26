#include <iostream>
#include <fstream>

class DataStorage {
private:
    using stringType = std::string;
public:
    static inline void saveData(const stringType& filename, const stringType& data) {
        std::ofstream outputFile(filename);        
        if (outputFile.is_open()) {
            outputFile << data;
            outputFile.flush(); // Flush the data to the file
            outputFile.close(); // Close the file
            std::cout << "Data saved to " << filename << std::endl;
        } else {
            std::cout << "Unable to open " << filename << " for writing." << std::endl;
        }
    }

    static inline stringType loadData(const std::string& filename) {
        std::string data;
        std::ifstream inputFile(filename);
        if (inputFile.is_open()) {
            std::getline(inputFile, data, '\0'); // Read the entire file into data
            inputFile.close();
        } else {
            std::cout << "Unable to open " << filename << " for reading." << std::endl;
        }
        return data;
    }
};

int main(void) {
    std::string filename = "log_data.txt";
    std::string data = "Error: Default text saved.";

    std::cin >> data;
    DataStorage::saveData(filename, data);
    std::cout << DataStorage::loadData(filename) << std::endl;
    return 0;
}
