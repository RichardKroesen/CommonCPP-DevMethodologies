#include <iostream>
#include <cmath>

class FixedFloatConverter {
private: 
    int fractionalBits;

public:
    FixedFloatConverter(int fractionalBits) : fractionalBits(fractionalBits) {}

    /* Floating-point to Fixed-point converter function.
    *  Formula: 
    */
    const int floatToFixed(float floatValue) {
        return static_cast<int>(floatValue * (1 << fractionalBits));
    }

    /* Fixed-point to Floating-point converter function.
    *  Formula: FX * 1 / 2^FB 
    */
    const float fixedToFloat(int fixedValue) {
        return static_cast<float>(fixedValue) / (1 << fractionalBits);
    }

    const float getFractionalPrecision(void) {
        const int bitRange = std::pow(2, fractionalBits); 
        return (1.0f / static_cast<float>(bitRange));
    }
};

int main() {
    int fractionalBits = 1;
    float originalFloat = 3.14159;
    std::cout << "Please enter the fractional bit amount: ";
    std::cin >> fractionalBits;
    std::cout << std::endl << "You entered " << fractionalBits << " fractional bits." << std::endl;
    FixedFloatConverter converter(fractionalBits);
    std::cout << "Fractional bits precision is " << converter.getFractionalPrecision() << std::endl;

    int convertedFixed = converter.floatToFixed(originalFloat);
    float convertedFloat = converter.fixedToFloat(convertedFixed);

    std::cout << "Original Float: " << originalFloat << std::endl;
    std::cout << "Converted Fixed: " << convertedFixed << std::endl;
    std::cout << "Converted Float: " << convertedFloat << std::endl;

    return 0;
}
