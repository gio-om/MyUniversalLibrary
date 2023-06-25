#include <gtest/gtest.h>
#include <iostream>
#include "../Structures/MyVector.h"

TEST(MyVectorTest, AddTest) {
    MyVector<int> v(5);
    v.add_element(3);
    v.add_element(8);
    v.add_element(4);

    EXPECT_EQ(4, v.Size());
    EXPECT_EQ(5, v[0]);
    EXPECT_EQ(3, v[1]);
    EXPECT_EQ(8, v[2]);
    EXPECT_EQ(4, v[3]);
}

TEST(MyVectorTest, SortTest) {
    MyVector<int> v(5);
    v.add_element(3);
    v.add_element(8);
    v.add_element(4);
    v.sort();

    EXPECT_EQ(3, v[0]);
    EXPECT_EQ(4, v[1]);
    EXPECT_EQ(5, v[2]);
    EXPECT_EQ(8, v[3]);
}

TEST(MyVectorTest, DeleteTest) {
    MyVector<int> v(3);
    v.add_element(4);
    v.add_element(5);

    v.delete_element(0);
    EXPECT_EQ(2, v.Size());
    EXPECT_EQ(4, v[0]);
}

TEST(MyVectorTest, FindTest) {
    MyVector<int> v(3);
    v.add_element(4);
    v.add_element(5);

    EXPECT_EQ(-1, v.find(0));
    EXPECT_EQ(0, v.find(3));
    EXPECT_EQ(1, v.find(4));
    EXPECT_EQ(2, v.find(5));
}

TEST(MyVectorTest, AppropriationTest) {
    MyVector<int> v(3);
    v.add_element(4);
    v.add_element(5);

    MyVector<int> v2 = v;
    EXPECT_EQ(v2.Size(), v.Size());
    EXPECT_EQ(v2[0], v[0]);
    EXPECT_EQ(v2[1], v[1]);
    EXPECT_EQ(v2[2], v[2]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}