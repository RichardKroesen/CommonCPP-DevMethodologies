#include <type_traits>
#include <iostream>

// Enum class for demonstration
enum class MyEnum : int {
    Value1 = 10,
    Value2 = 20,
    Value3 = 30
};

// Function to convert enumeration to underlying type
template <typename E>
constexpr typename std::underlying_type<E>::type to_underlying(E e) noexcept {
    return static_cast<typename std::underlying_type<E>::type>(e);
}

int main() {
    MyEnum enumValue = MyEnum::Value2;
    int underlyingValue = to_underlying(enumValue);

    // Test the conversion
    std::cout << "Enumeration value: " << static_cast<int>(enumValue) << std::endl;
    std::cout << "Underlying value: " << underlyingValue << std::endl;

    // You can now use the underlying value for operations or comparisons
    if (underlyingValue > 15) {
        std::cout << "The underlying value is greater than 15." << std::endl;
    }

    return 0;
}
