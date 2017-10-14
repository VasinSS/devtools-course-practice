// Copyright 2017 Vasin Stanislav

#include <gtest/gtest.h>
#include "../include/minesweeper.h"

TEST(VS_MinesweeperTest, Copy_constructor_equality_field_size_test) {
    // Arrange
    minesweeper  M1(10, 10, 5);
    minesweeper  M2(M1);
    unsigned int x_size;
    unsigned int y_size;

    // Act
    x_size = M2.get_x_size_field();
    y_size = M2.get_y_size_field();

    // Assert
    EXPECT_TRUE((x_size == 10) && (y_size == 10));
}

TEST(VS_MinesweeperTest, Copy_constructor_equality_field_cell_test) {
    // Arrange
    minesweeper  M1(10, 10, 5);
    minesweeper  M2(M1);
    bool result;

    // Act
    result = true;
    for (unsigned int i = 0; i < M2.get_x_size_field(); i++)
        for (unsigned int j = 0; j < M2.get_y_size_field(); j++) {
            if (M1.clic_on_field(i, j) != M2.clic_on_field(i, j)) {
                result = false;
            }
        }

    // Assert
    EXPECT_TRUE(result);
}

TEST(VS_MinesweeperTest, Copy_constructor_equality_mine_count_test) {
    // Arrange
    minesweeper  M1(10, 10, 5);
    minesweeper  M2(M1);

    // Act


    // Assert
    EXPECT_EQ(M1.get_mine_count(), M2.get_mine_count());
}

TEST(VS_MinesweeperTest, Assignment_operator_equality_field_size_test) {
    // Arrange
    minesweeper  M1(10, 10, 6);
    minesweeper  M2(20, 20, 10);
    unsigned int x_size;
    unsigned int y_size;

    // Act
    M2 = M1;

    x_size = M2.get_x_size_field();
    y_size = M2.get_y_size_field();

    // Assert
    EXPECT_TRUE((x_size == 10) && (y_size == 10));
}

TEST(VS_MinesweeperTest, Assignment_operator_equality_field_cell_test) {
    // Arrange
    minesweeper  M1(10, 10, 6);
    minesweeper  M2(20, 20, 10);
    bool result;

    // Act
    result = true;
    M2 = M1;

    for (unsigned int i = 0; i < M2.get_x_size_field(); i++)
        for (unsigned int j = 0; j < M2.get_y_size_field(); j++) {
            if (M1.clic_on_field(i, j) != M2.clic_on_field(i, j)) {
                result = false;
            }
        }

    // Assert
    EXPECT_TRUE(result);
}

TEST(VS_MinesweeperTest, Assignment_operator_equality_mine_count_test) {
    // Arrange
    minesweeper  M1(10, 10, 6);
    minesweeper  M2(20, 20, 10);

    // Act
    M2 = M1;

    // Assert
    EXPECT_EQ(M1.get_mine_count(), M2.get_mine_count());
}

TEST(VS_MinesweeperTest, defult_constructor_field_size_test) {
    // Arrange
    minesweeper  M;

    // Act

    // Assert
    EXPECT_TRUE((M.get_y_size_field() == 5) &&
                (M.get_x_size_field() == 5));
}

TEST(VS_MinesweeperTest, defult_constructor_mine_count_test) {
    // Arrange
    minesweeper  M;

    // Act

    // Assert
    EXPECT_EQ(M.get_mine_count(), (unsigned int)5);
}

TEST(VS_MinesweeperTest, constructor_incorrect_input_x_size_test) {
    // Arrange
    minesweeper  M(-200, -200, -50);

    // Act

    // Assert
    EXPECT_EQ(M.get_x_size_field(), (unsigned int)200);
}

TEST(VS_MinesweeperTest, constructor_incorrect_input_y_size_test) {
    // Arrange
    minesweeper  M(-200, -200, -50);

    // Act

    // Assert
    EXPECT_EQ(M.get_y_size_field(), (unsigned int)200);
}

TEST(VS_MinesweeperTest, constructor_incorrect_input_mine_count_test) {
    // Arrange
    minesweeper  M(-200, -200, -50);

    // Act

    // Assert
    EXPECT_EQ(M.get_mine_count(), (unsigned int)1);
}

TEST(VS_MinesweeperTest, out_of_range_x_clic_coord_test) {
    // Arrange
    minesweeper M(100, 100, 10);
    unsigned int out_of_range_value = 111;

    // Act

    // Assert
    EXPECT_EQ(M.clic_on_field(out_of_range_value, 15),
              M.clic_on_field(out_of_range_value %
              M.get_x_size_field(), 15));
}

TEST(VS_MinesweeperTest, out_of_range_y_clic_coord_test) {
    // Arrange
    minesweeper M(100, 100, 10);
    unsigned int out_of_range_value = 111;

    // Act

    // Assert
    EXPECT_EQ(M.clic_on_field(15, out_of_range_value),
              M.clic_on_field(15, out_of_range_value %
              M.get_x_size_field()));
}
