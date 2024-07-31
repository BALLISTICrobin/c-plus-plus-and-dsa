#include"colors.hpp"

int main(int argc, char const *argv[])
{
    std::cout << "--- Foreground Named Colors ---" << "\n";
    std::cout << colors::grey << "Grey text" << colors::reset << "\n";
    std::cout << colors::red << "Red text" << colors::reset << "\n";
    std::cout << colors::green << "Green text" << colors::reset << "\n";
    std::cout << colors::yellow << "Yellow text" << colors::reset << "\n";
    std::cout << colors::blue << "Blue text" << colors::reset << "\n";
    std::cout << colors::magenta << "Magenta text" << colors::reset << "\n";
    std::cout << colors::cyan << "Cyan text" << colors::reset << "\n";
    std::cout << colors::white << "White text" << colors::reset << "\n";
    std::cout << colors::bright_grey << "Bright grey text" << colors::reset << "\n";
    std::cout << colors::bright_red << "Bright red text" << colors::reset << "\n";
    std::cout << colors::bright_green << "Bright green text" << colors::reset << "\n";
    std::cout << colors::bright_yellow << "Bright yellow text" << colors::reset << "\n";
    std::cout << colors::bright_blue << "Bright blue text" << colors::reset << "\n";
    std::cout << colors::bright_magenta << "Bright magenta text" << colors::reset << "\n";
    std::cout << colors::bright_cyan << "Bright cyan text" << colors::reset << "\n";
    std::cout << colors::bright_white << "Bright white text" << colors::reset << "\n";
    return 0;
}
