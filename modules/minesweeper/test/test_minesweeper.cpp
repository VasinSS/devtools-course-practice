// Copyright 2017 Vasin Stanislav

#include <gtest/gtest.h>
#include "../include/minesweeper.h"

TEST(VS_S_MinesweeperTest, clic_on_cell_test_1) {
    // Arrange
    minesweeper m;
    char result;
    // Act
    result = m.clic_on_cell(0, 0);
    // Assert
    EXPECT_EQ(result, 9);
}

TEST(VS_S_MinesweeperTest, clic_on_cell_test_2) {
    // Arrange
    minesweeper m;
    char result;
    // Act
    result = m.clic_on_cell(0, 1);
    // Assert
    EXPECT_EQ(result, 2);
}

TEST(VS_S_MinesweeperTest, clic_on_cell_test_3) {
    // Arrange
    minesweeper m;
    char result;
    // Act
    result = m.clic_on_cell(0, 2);
    // Assert
    EXPECT_EQ(result, 1);
}

TEST(VS_S_MinesweeperTest, clic_on_cell_test_4) {
    // Arrange
    minesweeper m;
    char result;
    // Act
    result = m.clic_on_cell(0, 3);
    // Assert
    EXPECT_EQ(result, 0);
}

TEST(VS_S_MinesweeperTest, init_constructor_test_1) {
    // Arrange
    minesweeper m(10,10,7);
    char result;
    // Act
    result = m.get_x_size();
    // Assert
    EXPECT_EQ(result, 10);
}

TEST(VS_S_MinesweeperTest, init_constructor_test_2) {
    // Arrange
    minesweeper m(10,10,7);
    char result;
    // Act
    result = m.get_y_size();
    // Assert
    EXPECT_EQ(result, 10);
}

TEST(VS_S_MinesweeperTest, init_constructor_test_3) {
    // Arrange
    minesweeper m(10,10,7);
    char result;
    // Act
    result = m.get_mine_count();
    // Assert
    EXPECT_EQ(result, 7);
}

TEST(VS_S_MinesweeperTest, copy_constructor_test) {
    // Arrange
    minesweeper m1(10,10,7);
    minesweeper m2(m1);
    // Act
    // Assert
    EXPECT_TRUE( (m1.get_x_size() == m2.get_x_size() )
              && (m1.get_x_size() == m2.get_x_size() )
	      && (m1.get_x_size() == m2.get_x_size() ) );
}

TEST(VS_S_MinesweeperTest, get_x_size_test) {
    // Arrange
    minesweeper m;
    // Act

    // Assert
    EXPECT_EQ(m.get_x_size(), 10);
}

TEST(VS_S_MinesweeperTest, get_y_size_test) {
    // Arrange
    minesweeper m;
    // Act

    // Assert
    EXPECT_EQ(m.get_y_size(), 10);
}
