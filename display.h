#pragma once
#include <string>
#include <vector>

enum class Color{
    red , 
    blue,
    green,
    yellow,
    purple,
    orange,
    white,
    _default
    //etc
};

class Display{
    public:

    static void printColoredText(const std::string& text,  Color color/*color*/ ) ;
    static void printSlow(const std::string& text);

    static void clearScreen();
    static void printCentered(const std::string& text,  Color color/*color*/ );
    static void printDivider();

    static void playSound(const std::string& soundName);

    // animattions
    static void playIntroAnimation();
    static void playEndingAnimation();
    static void playGameOverAnimation();
    static void playEnterRegionAnimation();

    //ASCII ARTT
    static void printAscii(const std::vector<std::string>& art);
};