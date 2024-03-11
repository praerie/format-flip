#include <iostream>
#include <cctype>
#include <string>
#include "image_converter.h" 

// clear console window depending on OS
#ifdef _WIN32
    #define CLEAR_CONSOLE "cls" // Windows
#else
    #define CLEAR_CONSOLE "clear" // Linux and MacOS
#endif

void convertFile() {
    std::string fileType;
    std::cout << "Input file type (image, video, audio): ";
    std::cin >> fileType;

    for (char& c : fileType) {
        c = std::tolower(c);
    }

    if (fileType == "image") {
        image();
    }
    else if (fileType == "video") {
        std::cout << "Video converted successfully." << std::endl;
    }
    else if (fileType == "audio") {
        std::cout << "Audio converted successfully." << std::endl;
    }
    else {
        std::cerr << "Unsupported file type." << std::endl;
    }
}

int main() {
    do {
        system(CLEAR_CONSOLE);
        convertFile();

        char response;
        std::cout << "\nConvert another file? [Y/N]" << std::endl;
        std::cin >> response;

        if (response != 'Y' && response != 'y') {
            break;
        }
    } while (true);

    system(CLEAR_CONSOLE);
    return 0;
}
