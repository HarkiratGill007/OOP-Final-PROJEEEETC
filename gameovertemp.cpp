// #include <iostream>
// #include <vector>
// #include <string>
// #include <thread>
// #include <chrono>
// #include <algorithm>

// using namespace std::chrono_literals;
// using std::cout, std::cin, std::string;
// const int TERMINAL_WIDTH = 148; // matches currentterminal

// // ---- Your ASCII art, one string per row ----
// // Keep every row roughly the same length for clean alignment.
// std::vector<string> gameOverArt = {
//     " _____ _____ _____ _____    _____ _____ _____ _____ ", // width = 52
//     "|   __|  _  |     |   __|  |     |  |  |   __| __  |",
//     "|  |  |     | | | |   __|  |  |  |  |  |   __|    -|",
//     "|_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|"

// };

// void clearScreen()
// {
//     std::cout << "\033[2J\033[H";
// }
// // current terminal size = 21r X 148c
// // loops needed 100(width of art + either side) : 1 col in 1st 2 in sec ....
// void showGO(){
//     clearScreen();
//     for (int i = 0; i < 100; i++){
    
            
//         if (i != 0)clearScreen();
//         cout<<"\n\n\n\n\n\n";
//                 int j = i;
//                 if (j > 51) {j = 51;}
                 
//                 for (string x : gameOverArt){
                    
                   
//                     string padding;
//                     if (i>=51){
//                     padding = string(i-51, ' ');}
//                     else { padding = "";}
//                     cout << padding << x.substr(52-(j+1)) << "\n";
                //first commit    

//                 }
//                 std::this_thread::sleep_for(30ms);
                
//                 cout<<"\n\n\n\n\n\n";
//             }
//     }

// int main(){
//     showGO();
//     int k;
//     cout<<"Enter next command:";
//     cin>>k;
// }