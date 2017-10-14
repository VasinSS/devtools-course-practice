// Copyright 2017 Gorozhanin Mihail

#include "include/Application.h"
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>

Application::Application() {}

double ParseDouble(const char* arg) {
  char* end;
  double value = strtod(arg, &end);
  if (end[0]) {
    throw std::string("ERROR: Incorrect coordinate!");
  }
  return value;
}


void Application::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This application is to determine whether the segments that intersect.\n"

    + "Please choose the coordinates of the segments,\n" +
    "presenting the arguments in the following format:\n\n" +

    "  $ " + appname + "\n<X1> " +
    "<Y1> <X2> <Y2> " +
    "<X3> <Y3> <X4> <Y4>\n\n" +

    "Where each argument to the - coordinate of the point for x and for y." +
    "It has 8 arguments.\n";
}

bool Application::ValidateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 9) {
    help(argv[0], "ERROR: Should be 8 arguments.\n\n");
    return false;
  }
  return true;
}

std::string Application::operator()(int argc, const char** argv) {
  Segment_User args_1;
  Segment_True args_2;

  string Answer;
  std::string str1, str2;

  if (!ValidateNumberOfArguments(argc, argv)) {
    return message_;
  }

  try {
      args_1.X1U = ParseDouble(argv[1]);
      args_1.Y1U = ParseDouble(argv[2]);
      args_1.X2U = ParseDouble(argv[3]);
      args_1.Y2U = ParseDouble(argv[4]);
      args_2.X1T = ParseDouble(argv[5]);
      args_2.Y1T = ParseDouble(argv[6]);
      args_2.X2T = ParseDouble(argv[7]);
      args_2.Y2T = ParseDouble(argv[8]);
  }
  catch (std::string& str) {
    return str;
  }

  str1 += "(" + std::to_string(args_1.X1U) + ",";
  str1 += std::to_string(args_1.Y1U) + ")" + "\n";
  str1 += "(" + std::to_string(args_1.X2U) + ",";
  str1 += std::to_string(args_1.Y2U) + ")" + "\n";

  str2 += "(" + std::to_string(args_2.X1T) + ",";
  str2 += std::to_string(args_2.Y1T) + ")" + "\n";
  str2 += "(" + std::to_string(args_2.X2T) + ",";
  str2 += std::to_string(args_2.Y2T) + ")" + "\n";
  /*
  User_Line =
  LineSegment2D::LineSegment2D(args_1.X1U, args_1.Y1U, args_1.X2U, args_1.Y2U);

  True_Line =
  LineSegment2D::LineSegment2D(args_2.X1T, args_2.Y1T, args_2.X2T, args_2.Y2T);
  */
  LineSegment2D User_Line(args_1.X1U, args_1.Y1U, args_1.X2U, args_1.Y2U);
  LineSegment2D True_Line(args_2.X1T, args_2.Y1T, args_2.X2T, args_2.Y2T);

  Answer = User_Line.CheckIntersection(True_Line);

  std::ostringstream stream;
  stream << "Two segments with coordinates: \n\nSegment 1:\n"
         << str1 << "\nSegment 2:\n" << str2 << "\nAre checked"
         << "for intersection and correlation"<< "\n\nConclusion: "
         << Answer << "";
  message_ = stream.str();
  return message_;
}
