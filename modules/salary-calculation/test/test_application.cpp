// Copyright 2017 Kiselev Ivan

#include <gtest/gtest.h>
#include "../include/Application.h"

TEST(Application, first_simple_test) {
    ASSERT_TRUE(true);
}

TEST(Application, Open_File) {
    Salary* sal = new Salary();

    sal->CalculateSalary();

    ASSERT_EQ(sal->GetSalary() , 3200);
}

TEST(Application, Constructor_copir) {
    Application app1;
    ASSERT_NO_FATAL_FAILURE(Application app2(app1));
}

TEST(Application, Operator) {
    Application app;
    char** chr = new char*[3];
    chr[1] = new char[1];
    chr[1][0] = '7';
    chr[2] = new char[1];
    chr[2][0] = '1';
    Salary sal;
    sal.CalculateSalary();
    ASSERT_EQ(app(3, chr), 3200);
}

TEST(Application, Char_To_Int_1) {
    char a[3] = { '1', '2', '3' };
    Application app;
    ASSERT_EQ(app.ToInt(a), 123);
}

TEST(Application, Char_To_Int_2) {
    char* a = new char[1];
    a[0] = '1';
    Application app;
    ASSERT_EQ(app.ToInt(a), 1);
}

TEST(Application, Imitation_real_work_test) {
    char** arr = new char*[15];
    Application app;
    for (int i = 1; i <= 13; i += 2) {
        arr[i] = new char[1];
        arr[i][0] = '0' + (i - 1) / 2 + 1;
    }
    arr[2] = new char[2];
    arr[2][0] = '5';
    arr[2][1] = '0';
    arr[4] = new char[2];
    arr[4][0] = '3';
    arr[4][1] = '0';
    arr[6] = new char[2];
    arr[6][0] = '6';
    arr[6][1] = '0';
    arr[8] = new char[1];
    arr[8][0] = '0';
    arr[10] = new char[2];
    arr[10][0] = '2';
    arr[10][1] = '0';
    arr[12] = new char[1];
    arr[12][0] = '8';
    arr[14] = new char[1];
    arr[14][0] = '0';
    int res = app(15, arr);
    ASSERT_EQ(res, 1600);
}

TEST(Application, Print_Help_1 ) {
        Application app;
        char** chr = new char*[3];
        chr[1] = new char[1];
        chr[1][0] = '0';
        chr[2] = new char[1];
        chr[2][0] = '1';
        Salary sal;
        sal.CalculateSalary();
        ASSERT_EQ(app(3, chr), 0);
}

TEST(Application, Print_Help_2 ) {
    Application app;
    char** chr = new char*[3];
    chr[1] = new char[1];
    chr[1][0] = '8';
    chr[2] = new char[1];
    chr[2][0] = '1';
    Salary sal;
    sal.CalculateSalary();
    ASSERT_EQ(app(3, chr), 0);
}
