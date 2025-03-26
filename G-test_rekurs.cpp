TEST(ReverseListTest, HandlesEmptyList) {
    EXPECT_EQ(reverseListRecursive(nullptr), nullptr);
}

TEST(ReverseListTest, HandlesSingleNode) {
    Node* head = new Node(1);
    auto result = reverseListRecursive(head);
    EXPECT_EQ(result->data, 1);
    EXPECT_EQ(result->next, nullptr);
    delete head;
}

TEST(ReverseListTest, ReversesList) {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    
    auto result = reverseListRecursive(head);
    
    EXPECT_EQ(result->data, 3);
    EXPECT_EQ(result->next->data, 2);
    EXPECT_EQ(result->next->next->data, 1);
    EXPECT_EQ(result->next->next->next, nullptr);
    
    // Cleanup
    delete result->next->next;
    delete result->next;
    delete result;
}
