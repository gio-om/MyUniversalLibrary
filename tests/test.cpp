#include <gtest/gtest.h>
#include <iostream>
#include "../Structures/MyVector.h"

struct MyVectorTest : public testing::Test {
    MyVector<int> *v;

    void SetUp() override { v = new MyVector<int>(5);
        v->add_element(3); v->add_element(8); v->add_element(4); }

    void TearDown() override { delete v; }
};

TEST_F(MyVectorTest, AddTest) {
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

TEST_F(MyVectorTest, SortTest) {
    v->sort();

    EXPECT_EQ(3, (*v)[0]);
    EXPECT_EQ(4, (*v)[1]);
    EXPECT_EQ(5, (*v)[2]);
    EXPECT_EQ(8, (*v)[3]);
}

TEST_F(MyVectorTest, DeleteTest) {
    v->delete_element(0);

    EXPECT_EQ(3, v->Size());
    EXPECT_EQ(3, (*v)[0]);
    EXPECT_EQ(8, (*v)[1]);
    EXPECT_EQ(4, (*v)[2]);
}

TEST_F(MyVectorTest, FindTest) {
    v->sort();

    EXPECT_EQ(-1, v->find(0));
    EXPECT_EQ(0, v->find(3));
    EXPECT_EQ(1, v->find(4));
    EXPECT_EQ(2, v->find(5));
    EXPECT_EQ(3, v->find(8));
}

TEST_F(MyVectorTest, AppropriationTest) {
    MyVector<int> v2 = (*v);

    EXPECT_EQ(v2.Size(), v->Size());
    EXPECT_EQ(v2[0], (*v)[0]);
    EXPECT_EQ(v2[1], (*v)[1]);
    EXPECT_EQ(v2[2], (*v)[2]);
    EXPECT_EQ(v2[3], (*v)[3]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}