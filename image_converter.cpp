#include "image_converter.h"

void image() {
    std::string inputFileName;
    std::cout << "\nEnter file name with extension (excluding path): ";
    std::cin >> inputFileName;

    std::string inputFolderPath = "input/";
    std::string inputFilePath = inputFolderPath + inputFileName;

    if (!fs::exists(inputFilePath)) {
        std::cerr << "\n[!] Error: Image not found in directory." << std::endl;
        return;
    }

    cv::Mat image = cv::imread(inputFilePath, cv::IMREAD_UNCHANGED);

    if (image.empty()) {
        std::cerr << "\n[!] Error: Image could not be loaded." << std::endl;
        return;
    }

    std::string outputFormat;
    std::cout << "\nEnter the desired output format [PNG, JPEG, WebP, TIFF]: ";
    std::cin >> outputFormat;

    for (char& c : outputFormat) {
        c = std::toupper(c);
    }

    if (outputFormat != "PNG" && outputFormat != "JPEG" && outputFormat != "WEBP" && outputFormat != "TIFF") {
        std::cerr << "\n[!] Error: Image format not supported. "
            << "Supported formats: PNG, JPEG, WebP, TIFF."
            << std::endl;
        return;
    }

    size_t extensionIndex = inputFileName.find_last_of(".");
    std::string inputExtension = inputFileName.substr(extensionIndex);
    std::string originalFileName = inputFileName.substr(0, extensionIndex);

    std::string outputExtension;

    if (outputFormat == "PNG") {
        outputExtension = ".png";
    }
    else if (outputFormat == "JPEG") {
        outputExtension = ".jpeg";
        cv::imwrite("output/" + originalFileName + outputExtension, image, { cv::IMWRITE_JPEG_QUALITY, 90 });
    }
    else if (outputFormat == "WEBP") {
        outputExtension = ".webp";
        cv::imwrite("output/" + originalFileName + outputExtension, image, { cv::IMWRITE_WEBP_QUALITY, 90 });
    }
    else if (outputFormat == "TIFF") {
        outputExtension = ".tiff";
        cv::imwrite("output/" + originalFileName + outputExtension, image);
    }

    std::cout << "\nSuccessfully coverted " << inputExtension << " to " << outputExtension << "! Saved as 'output/" << originalFileName << outputExtension << "'." << std::endl;
}
