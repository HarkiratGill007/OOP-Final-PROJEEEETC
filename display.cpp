#include "display.h"
#include <iostream>
#include <thread>
#include <chrono>
// class Display{
//     public:

//   !  static void printColoredText(const std::string& text,  Color color/*color*/ ) ;
//   !  static void printSlow(const std::string& text);

//   !  static void clearScreen();
//     static void printCentered(const std::string& text,  Color color/*color*/ );
//     static void printDivider();

//     static void playSound(const std::string& soundName);

//     // animations
//     static void playIntroAnimation();
//     static void playEndingAnimation();
//     static void playGameOverAnimation();
//     static void playEnterRegionAnimation();

//     //ASCII ARTT
//     static void printAscii(const std::vector<std::string>& art);
// };

void Display::printColoredText(const std::string& text,  Color color/*color*/){
    std::string code;
    switch (color) {
        case Color::red:      code = "\033[31m"; break;
        case Color::green:    code = "\033[32m"; break;
        case Color::yellow:   code = "\033[33m"; break;
        case Color::blue:     code = "\033[34m"; break;
        case Color::white:    code = "\033[37m"; break;
        case Color::orange:   code = "\033[38;5;208m";break ;  
        case Color::purple: code = "\033[38;5;129m"; break;
        case Color::_default: code = "\033[0m";  break;//_ for default name conflict
    }
    std::cout << code << text << "\033[0m";
}
void Display::printSlow(const std::string& text){
    for (char x : text){
        std::cout << x <<std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}
void Display::clearScreen(){
    {
     std::cout << "\033[2J\033[H";
    }
}
void Display::printCentered(const std::string& text,  Color color/*color*/ ){
    
}