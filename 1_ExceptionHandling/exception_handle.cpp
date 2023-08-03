#include <iostream>
#include <stdexcept>

// Custom exception class
class MyException : public std::exception {
private:
    std::string errorMessage;

public:
    MyException(const std::string& message) : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};

// Function that throws the custom exception
void someFunction(int value) {
    if (value == 0) {
        throw MyException("Value cannot be zero.");
    }
}

int main() {
    try {
        int userInput;
        std::cout << "Enter a non-zero integer: ";
        std::cin >> userInput;
        someFunction(userInput);
    } catch (const MyException& err) {
        std::cout << "Caught exception: " << err.what() << std::endl;
    } catch (const std::exception& err) {
        std::cout << "Caught standard exception: " << err.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception." << std::endl;
    }

    return 0;
}
