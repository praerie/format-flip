#include <iostream>
using namespace std;

void convertFile() {
    string fileType;
    cout << "Input file type (image, video, audio): ";
    cin >> fileType;

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
        convertFile();

        char response;
        cout << "Convert another file? [Y/N]" << endl;
        cin >> response;

        if (response != 'Y' && response != 'y') {
            break;
        }
    } while (true);

    return 0;
}
