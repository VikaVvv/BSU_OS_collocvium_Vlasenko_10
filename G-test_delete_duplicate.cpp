TEST(RemoveDuplicatesTest, HandlesEmptyInput) {
    std::vector<int> input = {};
    auto result = removeDuplicates(input);
    EXPECT_TRUE(result.empty());
}

TEST(RemoveDuplicatesTest, HandlesNoDuplicates) {
    std::vector<int> input = {1, 2, 3};
    auto result = removeDuplicates(input);
    EXPECT_EQ(input, result);
}

TEST(RemoveDuplicatesTest, RemovesDuplicates) {
    std::vector<int> input = {1, 2, 2, 3, 3, 3};
    std::vector<int> expected = {1, 2, 3};
    auto result = removeDuplicates(input);
    EXPECT_EQ(result, expected);
}

TEST(RemoveDuplicatesTest, PreservesOrder) {
    std::vector<int> input = {3, 1, 2, 1, 3};
    std::vector<int> expected = {3, 1, 2};
    auto result = removeDuplicates(input);
    EXPECT_EQ(result, expected);
}
