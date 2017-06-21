// Copyright 2017 Nazarov Aleksandr

#include <gtest/gtest.h>

#include <fstream>
#include <string>
#include <vector>

#include "include/deque_text_editor_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class  DequeTextEditorAppTest : public ::testing::Test {
    protected:
        void Act(vector<string> args) {
            vector<const char*> options;
            
                options.push_back("appname");
            for (size_t i = 0; i < args.size(); ++i) {
                options.push_back(args[i].c_str()); 
            }
            
                const char** argv = &options.front();
            int argc = static_cast<int>(args.size()) + 1;
            
                output_ = app_(argc, argv);
        }
        
            void Assert(std::string expected) {
            EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
        }
        
            private:
                DequeTextEditorApp app_;
                string output_;
};

TEST_F(DequeTextEditorAppTest, can_print_help) {
    vector<string> args = {};

    Act(args);

    Assert("This is deque of strings application.*");
}

TEST_F(DequeTextEditorAppTest,
    cant_do_smth_with_incorrect_number_of_arguments) {
    vector<string> args = {"testarg"};

    Act(args);

    Assert("wrong numbers of arguments.*");
}

TEST_F(DequeTextEditorAppTest,
    cant_do_smth_with_incorrect_flags) {
    vector<string> args = { "-incorrectflags", "testfile.txt", "teststring" };

    Act(args);

    Assert("wrong flags.*");
}

TEST_F(DequeTextEditorAppTest,
    cant_do_smth_without_flags) {
    vector<string> args = { "notflag", "testfile.txt", "teststring" };

    Act(args);

    Assert("wrong arguments, you don't write falgs.*");
}

TEST_F(DequeTextEditorAppTest,
    cant_do_smth_with_incorrect_second_flags) {
    vector<string> args = { "-slf", "testfile.txt", "teststring",
        "-secincflags", "testfile.txt" };

    Act(args);

    Assert("wrong second flags.*");
}

TEST_F(DequeTextEditorAppTest,
    cant_do_smth_with_too_much_flags) {
    vector<string> args = { "-slf", "testfile.txt", "-slf",
        "-slf", "testfile.txt" };

    Act(args);

    Assert("too much flags.*");
}

TEST_F(DequeTextEditorAppTest,
    can_load_and_front_insert_string_to_text_file) {
    std::string filename = "testfile.txt";
    std::ofstream filestream(filename, std::ios_base::trunc);
    filestream << "teststring1" << std::endl;
    filestream.close();
    vector<string> args = { "-lsfw", filename, "teststring2",};

    Act(args);

    Assert("teststring1\nteststring2.*");
}

TEST_F(DequeTextEditorAppTest,
    can_load_and_back_insert_string_to_text_file) {
    std::string filename = "testfile.txt";
    std::ofstream filestream(filename, std::ios_base::trunc);
    filestream << "teststring2" << std::endl;
    filestream.close();
    vector<string> args = { "-lsbw", filename, "teststring1", };

    Act(args);

    Assert("teststring1\nteststring2.*");
}

TEST_F(DequeTextEditorAppTest,
    can_use_second_flags_and_use_it_to_save_to_other_file) {
    std::string filename1 = "testfile1.txt";
    std::string filename2 = "testfile2.txt";
    std::ofstream filestream(filename1, std::ios_base::trunc);
    if (filestream) {
        filestream << "teststring2" << std::endl;
        filestream.close();
    }
    vector<string> args = { "-lb", filename1, "teststring1", "-sw",
        filename2 };

    Act(args);
    std::string result;
    std::ifstream filestream2(filename2);
    if (filestream2) {
        std::string buffer = "";
        while (!filestream2.eof()) {
            std::getline(filestream2, buffer);
            result += buffer;
        }
        filestream2.close();
    }

    EXPECT_TRUE(RE::PartialMatch(result, RE("teststring1teststring2.*")));
}

TEST_F(DequeTextEditorAppTest,
    can_use_second_file_to_insert_to_front_string_file) {
    std::string filename1 = "testfile1.txt";
    std::string filename2 = "testfile2.txt";
    std::ofstream filestream(filename2, std::ios_base::trunc);
    if (filestream) {
        filestream << "teststring2" << std::endl;
        filestream.close();
    }
    vector<string> args = { "-sb", filename1, "teststring1", "-lsfw",
        filename2 };

    Act(args);
    std::string result;
    std::ifstream filestream2(filename2);
    if (filestream2) {
        std::string buffer = "";
        while (!filestream2.eof()) {
            std::getline(filestream2, buffer);
            result += buffer;
        }
        filestream2.close();
    }

    EXPECT_TRUE(RE::PartialMatch(result, RE("teststring2teststring1.*")));
}

TEST_F(DequeTextEditorAppTest,
    can_use_second_file_to_insert_to_back_string_file) {
    std::string filename1 = "testfile1.txt";
    std::string filename2 = "testfile2.txt";
    std::ofstream filestream(filename2, std::ios_base::trunc);
    if (filestream) {
        filestream << "teststring2" << std::endl;
        filestream.close();
    }
    vector<string> args = { "-sb", filename1, "teststring1", "-lsbw",
        filename2 };

    Act(args);
    std::string result;
    std::ifstream filestream2(filename2);
    if (filestream2) {
        std::string buffer = "";
        while (!filestream2.eof()) {
            std::getline(filestream2, buffer);
            result += buffer;
        }
        filestream2.close();
    }

    EXPECT_TRUE(RE::PartialMatch(result, RE("teststring1teststring2.*")));
}