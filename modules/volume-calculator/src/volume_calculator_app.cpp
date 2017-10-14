// Copyright 2017 Kochin Ivan

#include "include/volume_calculator_app.h"
#include "include/volume_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

VolumeCalculator::VolumeCalculator() : message_("") {}

void VolumeCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a volume 3d figure calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <type of figure> " +
        "<...> - parameters \n\n" +

        "Where all parameters are double-unsigned numbers, " +
        "And Type is unsigned integer\n" +
        "The parameters are arranged in the order of their description\n" +
        "Types and parameters:\n" +
        "1 - Cube and Parameters is: a is side length \n" +
        "2 - Dodecahedron and Parameters is: a is rib length \n" +
        "3 - Cylinder and Parameters is: h is height of cylinder, r \n" +
        "4 - Parallelepiped and Parameters is: S is base area, h] \n" +
        "5 - Parallelepiped and Parameters is: a,b is rib of" +
        " base area, h is height \n" +
        "6 - Parallelepiped and Parameters is: a,b,c is non parallel" +
        " rib, x is argument of sine of slope angle\n" +
        "7 - Pyramid and Parameters is: S is base area of" +
        " pyramid, h is height\n" +
        "8 - Pyramid and Parameters is: a is rid of base triangle" +
        " of pyramid, base_h is height of base triangle\n" +
        " pyramid_h is height of pyramid /n" +
        "9 - Cone and Parameters is: h is height of cone," +
        " r is radius of cone \n" +
        "10 - Sphere and Parameters is: r is radius of sphere \n" +
        "11 - Ellipsoid and Parameters is: a, b, c is" +
        " radius of perpendicular axis of ellipsoid \n" +
        "12 - Paraboloid and Parameters is: r" +
        " is rarius of paraboloid, h is height of paraboloid \n" +
        "13 - RectangularParallelepiped and Parameters is: a,b,c" +
        " is perpendicular rib of rectangular parallelepiped \n" +
        "14 - Frustum and Parameters is: r_base_1, r_base_2 is" +
        " radius of bases of frustum, h is height of frustum \n";
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0] || value < 0) {
        throw std::string("Wrong number format!");
    }

    return value;
}
int parseInt(const char* arg) {
    int value = atoi(arg);
    double whole = parseDouble(arg);
        if (whole != value) {
            throw std::string("Wrong number format!");
    }
        return value;
}


bool VolumeCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else {
        try {
        switch (parseInt(argv[1])) {
        case 1:
            if (argc != 3) {
                help(argv[0], "ERROR: Should be 1 arguments.\n\n");
                return false;
            }
            return true;
            break;
        case 2:
            if (argc != 3) {
                help(argv[0], "ERROR: Should be 1 arguments.\n\n");
                return false;
            }
            return true;
            break;
        case 3:
            if (argc != 4) {
                help(argv[0], "ERROR: Should be 2 arguments.\n\n");
                return false;
            }
            return true;
            break;
        case 4:
            if (argc != 4) {
                help(argv[0], "ERROR: Should be 2 arguments.\n\n");
                return false;
            }
            return true;
            break;
        case 5:
            if (argc != 5) {
                help(argv[0], "ERROR: Should be 3 arguments.\n\n");
                return false;
            }
            return true;
            break;
        case 6:
            if (argc != 6) {
                help(argv[0], "ERROR: Should be 4 arguments.\n\n");
                return false;
            }
            return true;
            break;
        case 7:
            if (argc != 4) {
                help(argv[0], "ERROR: Should be 2 arguments.\n\n");
                return false;
            }
            return true;
            break;
        case 8:
            if (argc != 5) {
                help(argv[0], "ERROR: Should be 3 arguments.\n\n");
                return false;
            }
            return true;
            break;
        case 9:
            if (argc != 4) {
                help(argv[0], "ERROR: Should be 2 arguments.\n\n");
                return false;
            }
            return true;
            break;
        case 10:
            if (argc != 3) {
                help(argv[0], "ERROR: Should be 1 arguments.\n\n");
                return false;
            }
            return true;
            break;
        case 11:
            if (argc != 5) {
                help(argv[0], "ERROR: Should be 3 arguments.\n\n");
                return false;
            }
            return true;
            break;
        case 12:
            if (argc != 4) {
                help(argv[0], "ERROR: Should be 2 arguments.\n\n");
                return false;
            }
            return true;
            break;
        case 13:
            if (argc != 5) {
                help(argv[0], "ERROR: Should be 3 arguments.\n\n");
                return false;
            }
            return true;
            break;
        case 14:
            if (argc != 5) {
                help(argv[0], "ERROR: Should be 3 arguments.\n\n");
                return false;
            }
            return true;
            break;
        default:
            help(argv[0], "Incorrect type.\n\n");
            return false;
        }
        }
        catch (std::string& str) {
            message_ = "Type must be integer";
            return false;
        }
    }
    return true;
}


std::string VolumeCalculator::operator()(int argc, const char** argv) {
    int Arguments[4];
    int Type;
    Volume Calc;
    double result;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        Type = parseInt(argv[1]);
        for (int i = 2; i < argc; i++)
            Arguments[i - 2] = parseDouble(argv[i]);
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;

        switch (Type) {
        case 1:
            result = Calc.Cube(Arguments[0]);
            stream << "Volume = " << result;
            break;
        case 2:
            result = Calc.Dodecahedron(Arguments[0]);
            stream << "Volume = " << result;
            break;
        case 3:
            result = Calc.Cylinder(Arguments[0], Arguments[1]);
            stream << "Volume = " << result;
            break;
        case 4:
            result = Calc.Parallelepiped(Arguments[0], Arguments[1]);
            stream << "Volume = " << result;
            break;
        case 5:
            result = Calc.Parallelepiped(Arguments[0],
                    Arguments[1], Arguments[2]);
            stream << "Volume = " << result;
            break;
        case 6:
            result = Calc.Parallelepiped(Arguments[0],
                Arguments[1], Arguments[2], Arguments[3]);
            stream << "Volume = " << result;
            break;
        case 7:
            result = Calc.Pyramid(Arguments[0], Arguments[1]);
            stream << "Volume = " << result;
            break;
        case 8:
            result = Calc.Pyramid(Arguments[0],
                Arguments[1], Arguments[2]);
            stream << "Volume = " << result;
            break;
        case 9:
            result = Calc.Cone(Arguments[0], Arguments[1]);
            stream << "Volume = " << result;
            break;
        case 10:
            result = Calc.Sphere(Arguments[0]);
            stream << "Volume = " << result;
            break;
        case 11:
            result = Calc.Ellipsoid(Arguments[0], Arguments[1], Arguments[2]);
            stream << "Volume = " << result;
            break;
        case 12:
            result = Calc.Paraboloid(Arguments[0], Arguments[1]);
            stream << "Volume = " << result;
            break;
        case 13:
            result = Calc.RectangularParallelepiped(Arguments[0],
                Arguments[1], Arguments[2]);
            stream << "Volume = " << result;
            break;
        case 14:
            result = Calc.Frustum(Arguments[0], Arguments[1], Arguments[2]);
            stream << "Volume = " << result;
            break;
        }

    message_ = stream.str();
    return message_;
}
