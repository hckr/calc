#include "commandinput.h"

CommandInput::CommandInput(std::string prompt_str) {
    prompt = prompt_str;
    current_command_pos = 0;
}

bool CommandInput::cmleft() {
    int x, y;
    getyx(curscr, y, x);
    if(current_command_pos >= 1) {
        move(y, x-1);
        current_command_pos -= 1;
        return true;
    }
    return false;
}

bool CommandInput::cmright() {
    int x, y;
    getyx(curscr, y, x);
    if(current_command_pos < current_command.length()) {
        move(y, x+1);
        current_command_pos += 1;
        return true;
    }
    return false;
}

void CommandInput::init() {
    int ch;
    initscr();
    scrollok(stdscr, true);
    noecho();
    keypad(stdscr, true);
    print_prompt();
    do {
        ch = getch();
        switch(ch) {
        case KEY_UP:

            break;
        case KEY_RIGHT:
            cmright();
            break;
        case KEY_DOWN:

            break;
        case KEY_LEFT:
            cmleft();
            break;
        case KEY_STAB:
            addstr("TAB\n");
            break;
        case KEY_BACKSPACE:
            cmleft();
            addstr(" ");
            cmleft();
            refresh();
            break;
        case '\n':
            while(cmright())
                refresh();
            addstr("\n");
            run_current_command();
            print_prompt();
            break;
        default:
            insert_char(ch);
        }
    } while(true);
    endwin();
}

void CommandInput::insert_char(int ch) {
    if(current_command_pos == current_command.length()) {
        addch(ch);
        current_command += (char)ch;
        current_command_pos += 1;
    } else {
        insch(ch);
        current_command = current_command.substr(0, current_command_pos) +
                          (char)ch +
                          current_command.substr(current_command_pos);
    }
}

void CommandInput::print_prompt() {
    addstr(prompt.c_str());
}

void CommandInput::run_current_command() {
    print_line("Command: " + current_command);
    current_command = "";
    current_command_pos = 0;
}

void CommandInput::print_line(std::string string) {
    addstr(string.c_str());
    addstr("\n");
}

CommandInput::~CommandInput() {

}

