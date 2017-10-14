// Copyright 2017 Yashkov Vladislav

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include "sstream"

#include "include/credit_calculator_app.h"
#include "include/credit_calculator.h"

Application::Application() {}

void Application::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a credit calculator application\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <amount> <period> " +
        "<interest> <month_pas>\n" +

        "Where <amount>, <period> and <month_pas> are non-negative" +
        "integer numbers,\n <interest> is non-negative rational number";
}

bool Application::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 5) {
        Help(argv[0], "ERROR: Incorrect arguments num.\n\n");
        return false;
    }
    return true;
}

int ParseInt(const char* arg) {
    int value = std::stoi(arg);
    return value;
}

double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);
        if (end[0]) {
        throw std::string("Wrong number format!");
    }
    return value;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;
    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.amount = ParseInt(argv[1]);
        args.period = ParseInt(argv[2]);
        args.interest = ParseDouble(argv[3]);
        args.month_pas = ParseInt(argv[4]);
    }
    catch (std::string& str) {
        return str;
    }
    double monthlyPayment = CreditCalculator::MonthlyPayment(args.amount,
        args.period, args.interest);
    double totalPayout = CreditCalculator::TotalPayout(args.amount,
        args.period, args.interest);
    double overpaymentAmount = CreditCalculator::OverpaymentAmount(args.amount,
        args.period, args.interest);
    double checkBalance = CreditCalculator::CheckBalance(args.amount,
        args.period, args.interest, args.month_pas);
    std::ostringstream stream;
    stream << "Monthly Payment: " << monthlyPayment << "\nTotal Payout: "
        << totalPayout << "\nOverpayment Amount: "
        << overpaymentAmount << "\nCheck Balance (" << args.month_pas << "): "
        << checkBalance;
    message_ = stream.str();
    return message_;
}
