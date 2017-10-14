// Copyright 2017 Fedorov Igor

#include "./include/saper.h"
#include <string>
#include <sstream>


Saper::Saper(int wth, int hght, int countbomb) {
    field_ = new Field(wth, hght, countbomb);
}

bool Saper::TouchResult(int x, int y) {
    if (!field_->OpenCurrentCell(x, y)) {
        std::cout << "Pleas, try another one.";
        return true;
    }
    if ((*field_)[x][y].isBomb) {
        return false;
    } else if ((*field_)[x][y].num == 0) {
            field_->OpenNearCell(x, y);
    }
    return true;
}

std::string Saper::operator()(int argc, const char ** argv) {
    if (argc == 1) {
        message_ += "exit\n";
        PrintHelp(argv[0]);
        return message_;
    }
    if (!validateNumberOfArguments(argc, argv)) {
        message_ += "Wrong arguments!\n";
        PrintHelp(argv[0]);
        return message_;
    }
    switch (args_.choose) {
    case 0:
        field_->MarkCell(args_.x, args_.y);
        return "You make a flag!\n";
        break;
    case 1:
        if (TouchResult(args_.x, args_.y)) {
            if (field_->IsWin())
                return "You win!\n";
            return "Good move!\n";
        } else {
            //  system("cls");
            std::cout << "\t Bad move :(" << std::endl;
            std::cout << "Ba Ba Ba Bah!" << std::endl;
            std::cout << "Ba Ba Ba Bah!" << std::endl;
            std::cout << "Ba Ba Ba Bah!" << std::endl;
            std::cout << "Ba Ba Ba Bah!" << std::endl;
            std::cout << "Sory, you lose(" << std::endl;
            return "You lose\n";
        }
        break;
    case 2:
        return field_->PrintField();
        break;
    }
    return "exit\n";
}

void Saper::PrintHelp(const char *appname) {
    message_ += "This is a simple saper application. Usage:\n";
    message_ += "\n    ";
    message_ += appname;
    message_ += " <x> <y> <option>";
    message_ += "\n   <option> = 0 - touch cell. 1 - mark cell. 3 - exit. ";
    message_ += "2 - print the result";
    message_ += "\n    ";
    message_ += appname;
    message_ += " <somth>";
    message_ += "\n        -- exit";
    message_ += "\n           a formal parameter is int ";
    message_ += "\n";
}

bool Saper::validateNumberOfArguments(int argc, const char ** argv) {
    if (argc != 4) {
        return false;
    }
    args_.x = atoi(argv[1]);
    args_.y = atoi(argv[2]);
    args_.choose = atoi(argv[3]);
    if (args_.x < 0 || args_.y < 0)
        return false;
    return true;
}
