#include <gtest/gtest.h>

TEST(FactorialTest, HandlesZero) {
    auto result = calculateFactorials(0);
    EXPECT_TRUE(result.empty());
}

TEST(FactorialTest, HandlesPositiveNumbers) {
    auto result = calculateFactorials(5);
    std::vector<uint64_t> expected = {1, 2, 6, 24, 120};
    EXPECT_EQ(result, expected);
}

TEST(FactorialTest, ThrowsOnNegativeInput) {
    EXPECT_THROW(calculateFactorials(-1), std::invalid_argument);
}

TEST(FactorialTest, ThrowsOnOverflow) {
    EXPECT_THROW(calculateFactorials(100), std::overflow_error);
}
