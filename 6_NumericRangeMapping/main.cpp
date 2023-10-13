#include <iostream>
#include <cmath>

// Linear mapping function
template <typename DataType>
DataType linearMap(DataType value, DataType inMin, DataType inMax, DataType outMin = 0, DataType outMax = 100) {
    static_assert(!std::is_same<DataType, std::string>::value, "Function does not work for strings.");
    double result = static_cast<double>(value - inMin) / static_cast<double>(inMax - inMin) * static_cast<double>(outMax - outMin) + outMin;
    
    return static_cast<DataType>(std::round(result));
}

// Exponential mapping function
template <typename DataType>
DataType exponentialMap(DataType value, DataType inMin, DataType inMax, DataType outMin, DataType outMax, DataType exponent) {
    static_assert(!std::is_same<DataType, std::string>::value, "Function does not work for strings.");
    double normalizedValue = static_cast<double>(value - inMin) / static_cast<double>(inMax - inMin);
    double result = static_cast<double>(outMin) + static_cast<double>(outMax - outMin) * std::pow(normalizedValue, static_cast<double>(exponent));

    return static_cast<DataType>(std::round(result));
}

int main() {
    double inputValue = 0.5;
    double linearMappedValue = linearMap<double>(inputValue, 0.0, 1.0);
    double exponentialMappedValue = exponentialMap<double>(inputValue, 0.0, 1.0, 0.0, 100.0, 1.5);

    std::cout << "Linear Mapping: " << linearMappedValue << std::endl;
    std::cout << "Exponential Mapping: " << exponentialMappedValue << std::endl;
    std::cout << "\n";

    int inputValue2 = 282*2;
    int linearMappedValue2 = linearMap<int>(inputValue2, 0, 800);
    int exponentialMappedValue2 = exponentialMap<int>(inputValue2, 0, 800, 0, 100, 4);

    std::cout << "Linear Mapping: " << linearMappedValue2 << std::endl;
    std::cout << "Exponential Mapping: " << exponentialMappedValue2 << std::endl;

    return 0;
}
