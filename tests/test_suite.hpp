#include <gtest/gtest.h>

class TestSuite: public ::testing::Test
{
protected:
    TestSuite() {}
    virtual ~TestSuite() {}
};

TEST_F(TestSuite, count_nodes_with_nodes_merging_on)
{
    // EXPECT_EQ(ug->GetNumberOfPoints(), 8);
}

TEST_F(TestSuite, count_nodes_with_nodes_merging_off)
{
    // EXPECT_EQ(ug->GetNumberOfPoints(), 10);
}

TEST_F(TestSuite, check_merged_nodes_coordinates)
{
    // EXPECT_EQ(node_2_coords[0], node_8_coords[0]);
    // EXPECT_EQ(node_2_coords[1], node_8_coords[1]);
}

TEST_F(TestSuite, check_coordinates_after_translation)
{
    // EXPECT_EQ(node_0_coords[0], 1.0);
    // EXPECT_EQ(node_0_coords[1], 2.0);
}
