// Copyright 2017 Kalinin Vladimir & Kozlov Ilya

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>
#include <utility>

#include "include/Graph.h"

TEST(Kalinin_dijkstra_tests, Can_Create_Graph) {
  // Arrange

  // Act
  Graph gr1;
  Graph gr2(5);

  // Assert
  EXPECT_EQ(gr1.GetSize(), 0);
  EXPECT_EQ(gr2.GetSize(), 5);
}

TEST(Kozlov_dijkstra_tests, Can_Not_Create_Graph_With_Incorrect_Size) {
    // Arrange

    // Act

    // Assert
    EXPECT_ANY_THROW({ Graph gr(INF + 1); });
}

TEST(Kalinin_dijkstra_tests, IsConnect_Works) {
  // Arrange
  Graph gr(6);

  // Act
  gr.AddEdge(9, 1, 3);

  // Assert
  EXPECT_EQ(gr.IsConnect(1, 3), true);
  EXPECT_EQ(gr.IsConnect(3, 1), true);
  EXPECT_EQ(gr.IsConnect(1, 2), false);
}

TEST(Kalinin_dijkstra_tests, IsConnect_Does_Now_Works_With_Incorrect_Params) {
    // Arrange
    Graph gr(2);
    // Act

    // Assert
    EXPECT_ANY_THROW({ gr.IsConnect(1, 1); });
    EXPECT_ANY_THROW({ gr.IsConnect(3, 1); });
    EXPECT_ANY_THROW({ gr.IsConnect(1, 3); });
}

TEST(Kozlov_dijkstra_tests, Can_Create_Edge) {
    // Arrange
    Graph gr(2);
    // Act

    // Assert
    EXPECT_NO_THROW({ gr.AddEdge(1, 1, 0); });
}

TEST(Kozlov_dijkstra_tests, Can_Not_Create_Edge_With_Incorrect_Params) {
    // Arrange
    Graph gr(2);
    // Act

    // Assert
    EXPECT_ANY_THROW({ gr.AddEdge(1, 1, 1); });
    EXPECT_ANY_THROW({ gr.AddEdge(1, 2, 1); });
    EXPECT_ANY_THROW({gr.AddEdge(1, 1, 2);});
    EXPECT_ANY_THROW({ gr.AddEdge(INF + 1, 1, 0); });
    EXPECT_ANY_THROW({gr.AddEdge(1, INF + 1, 0); });
    EXPECT_ANY_THROW({ gr.AddEdge(1, 1, INF + 1); });
}

TEST(Kozlov_dijkstra_tests, Can_Not_Dijkstra_With_Incorrect_Param) {
    // Arrange
    Graph gr(2);
    // Act

    // Assert
    EXPECT_ANY_THROW(gr.Dijkstra(INF + 1););
}

TEST(Kalinin_dijkstra_tests, Diykstra_Result_Is_Correct) {
  // Arrange
  Graph gr(6);
  gr.AddEdge(7, 1, 2);
  gr.AddEdge(10, 2, 3);
  gr.AddEdge(9, 1, 3);
  gr.AddEdge(15, 2, 4);
  gr.AddEdge(11, 3, 4);
  gr.AddEdge(14, 1, 0);
  gr.AddEdge(2, 3, 0);
  gr.AddEdge(9, 5, 0);
  gr.AddEdge(6, 4, 5);
  std::vector<unsigned int> correct_answer = { 11, 0, 7, 9, 20, 20 };

  // Act
  vector<unsigned int> tmp = gr.Dijkstra(1);

  // Assert
  for (int i = 0; i < 6; i++) {
      EXPECT_EQ(correct_answer[i], tmp[i]);
  }
}

TEST(Kozlov_dijkstra_tests, Diykstra_Result_With_Unrelated_Graph) {
    // Arrange
    Graph gr(2);
    std::vector <unsigned int> correct_answer = { 0, INF };

    // Act
    std::vector<unsigned int> tmp = gr.Dijkstra(0);

    // Assert
    for (int i = 0; i < 2; i++) {
        EXPECT_EQ(correct_answer[i], tmp[i]);
    }
}

TEST(Kozlov_dijkstra_tests, Can_GetSize) {
    // Arrange
    const unsigned int size_to_test = 2;
    Graph gr(size_to_test);
    // Act

    // Assert
    EXPECT_NO_THROW(gr.GetSize(););
}

TEST(Kozlov_dijkstra_tests, GetSize_Is_Working_Correctly) {
    // Arrange
    const unsigned int size_to_test = 2;
    Graph gr(size_to_test);
    // Act

    // Assert
    EXPECT_EQ(gr.GetSize(), size_to_test);
}
