// Copyright 2017 Kiselev Ivan

#include <string>
#include <iostream>
#include "../include/Application.h"

Application::Application(int salary_per_hour, int needed_hours,
    int work_hours, int workday, int overtime_bonus) {
    worker_salary_ = new Salary(salary_per_hour, needed_hours, work_hours,
        workday);
    worker_salary_->SetOvertimeBonus(overtime_bonus);
    worker_salary_->CalculateSalary();
    instructions_ = new int[20];
}

Application::Application(const Application& pApp) {
    worker_salary_ = new Salary(pApp.worker_salary_->GetSalaryPerHour(),
        pApp.worker_salary_->GetNeededHours(),
        pApp.worker_salary_->GetWorkHours(),
        pApp.worker_salary_->GetWorkDay());
    worker_salary_->SetOvertimeBonus(pApp.worker_salary_->GetOvertimeBonus());
    worker_salary_->CalculateSalary();
    instructions_ = new int[20];
    for (int i = 0; i < 20; i++)
        instructions_[i] = pApp.instructions_[i];
}

int Application::operator()(int argc, char** argv) {
    if (argc == 1) return 0;
    //  function char** -> int**
    ToIntArray(argc, argv);
    //  cicle with options
    int i = 0;
    int result = 0;
    while (i < argc-1) {
        result = OneStep(instructions_[i], instructions_[i + 1]);
        i += 2;
    }
    return result;
}

int Application::OneStep(int instruction, int value) {
    switch (instruction) {
        case 0 : {
            PrintHelp();
        }
        case 1: {
            worker_salary_->SetSalaryPerHour(value);
            break;
        }
        case 2: {
            worker_salary_->SetWorkHours(value);
            break;
        }
        case 3: {
            worker_salary_->SetOvertimeBonus(value);
            break;
        }
        case 4: {
            worker_salary_->SetAdminRest(value);
            break;
        }
        case 5: {
            worker_salary_->SetNeededHours(value);
            break;
        }
        case 6: {
            worker_salary_->SetWorkDay(value);
            break;
        }
        case 7: {
            worker_salary_->CalculateSalary();
            return worker_salary_->GetSalary();
        }
        default: {
            PrintHelp();
            return 0;
        }
    }
    return instruction;
}

void Application::ToIntArray(int argc, char** argv) {
    int i = 1;
    while (i < argc) {
        instructions_[i-1] = ToInt(argv[i]);
        i++;
    }
}

int Application::ToInt(char* numb) {
    int i = 0, j = 0, result = 0;
    while (numb[i] && (numb[i] >= '0' && numb[i] <= '9'))
        i++;
    if (i == 0) return 0;
    while (j < i) {
        result = result * 10 + (numb[j] - '0');
        j++;
    }
    return result;
}

void Application::PrintHelp() {
    std::cout << "1 - Set salary per hour , Value \n";
    std::cout << "2 - Set work hours , Value \n";
    std::cout << "3 - Set overtime bonus , Value \n";
    std::cout << "4 - Set admin rest , Value \n";
    std::cout << "5 - Set needed hours\n";
    std::cout << "6 - Set How many hours in workday , Value \n";
    std::cout << "7 - Get Salary\n";
}
