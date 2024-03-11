#include <iostream>
#include <cctype>

// clear console window depending on OS
#ifdef _WIN32
    #define CLEAR_CONSOLE "cls" 
#else
    #define CLEAR_CONSOLE "clear" 
#endif

using namespace std;

void convertFile() {
    string fileType;
    cout << "Input file type (image, video, audio): ";
    cin >> fileType;

    for (char& c : fileType) {
        c = tolower(c);
    }

    if (fileType == "image") {
        cout << "Image converted successfully." << endl;
    } else if (fileType == "video") {
        cout << "Video converted successfully." << endl;
    } else if (fileType == "audio") {
        cout << "Audio converted successfully." << endl;
    } else {
        cout << "Unsupported file type." << endl;
    }
}

int main() {
    do {
        system(CLEAR_CONSOLE); 
        convertFile();

        char response;
        cout << "Convert another file? [Y/N]" << endl;
        cin >> response;

        if (response != 'Y' && response != 'y') {
            break;
        }
    } while (true);

    system(CLEAR_CONSOLE); 
    return 0;
}
