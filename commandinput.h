#ifndef COMMANDINPUT_H
#define COMMANDINPUT_H

#include <ncurses.h>
#include<string>

class CommandInput {
    std::string prompt;
    std::string current_command;
    unsigned int current_command_pos;
    bool cmleft();
    bool cmright();
    void print_prompt();
    void run_current_command();
    void print_line(std::string string);
    void insert_char(int ch);
public:
    CommandInput(std::string prompt);
    void init();
    ~CommandInput();
};

#endif // COMMANDINPUT_H
