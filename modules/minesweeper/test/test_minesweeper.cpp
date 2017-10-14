// Copyright 2017 Vasin Stanislav

#include <gtest/gtest.h>
#include "../include/minesweeper.h"

TEST(VS_S_MinesweeperTest, clic_on_cell_test) {
    // Arrange
    minesweeper m();
    char result;
    // Act
    result = m.clic_on_cell_test(0, 0);
    // Assert
    EXPECT_EQ(result = -1);
}

TEST(VS_S_MinesweeperTest, get_x_size_test) {
    // Arrange
    minesweeper m();
    // Act

    // Assert
    EXPECT_EQ(m.get_x_size() = 10);
}

TEST(VS_S_MinesweeperTest, get_y_size_test) {
    // Arrange
    minesweeper m();
    // Act

    // Assert
    EXPECT_EQ(m.get_y_size() = 10);
}
