#include <vector>
#include <stdexcept>
#include <cstdint>

std::vector<uint64_t> calculateFactorials(int n) {
    if (n < 0) {
        throw std::invalid_argument("Input must be non-negative");
    }
    
    std::vector<uint64_t> result;
    result.reserve(n);
    
    uint64_t current = 1;
    for (int i = 1; i <= n; ++i) {
        if (current > UINT64_MAX / i) {
            throw std::overflow_error("Factorial exceeds uint64_t capacity");
        }
        current *= i;
        result.push_back(current);
    }
    
    return result;
}
