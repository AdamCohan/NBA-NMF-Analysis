#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

/**
 * \brief Converts a string to spongebob mocking capitalization.
 * \returns the modified string.
 */

string spongebobMocking(string input) {
    for (size_t i = 0; i < input.length(); ++i) {
        if (i % 2 == 0) {
            input[i] = tolower(input[i]);
        } else {
            input[i] = toupper(input[i]);
        }
    }

    return input;
}

/**
 * \brief Creates a meme with an image and a string of text.
 * \input Three strings, representing the name of the source image file,
 *        the text to add to the image, and the name of the destination
 *        image file.
 * \returns 0 if everything is successful, -1 otherwise.
 */
int makeMeme(string inputFilename, string text, string outputFilename) {
    // Open the image file
    cout << "Opening file: " << inputFilename << endl;
    Mat image = imread(inputFilename);

    if (image.empty()) {
        cerr << "Could not open or find the image " << inputFilename << endl;
        return -1;
    }

    int font = FONT_HERSHEY_TRIPLEX;
    float textScaling = 3.0;
    Scalar textColor{0, 0, 255};
    Point textPosition{0, 75};

    text = spongebobMocking(text);
    cout << "Adding text: " << text << endl;
    putText(image, text, textPosition, font, textScaling, textColor);

    // Write out the modified image
    cout << "Writing file: " << outputFilename << endl;
    bool isSuccess = imwrite(outputFilename, image);

    if (!isSuccess) {
        cerr << "Could not write the image " << outputFilename << endl;
        return -1;
    }

    return 0;
}

/**
 * \brief Gets input from the user, then uses that input to call makeMeme.
 * \input None, but asks for three input strings from the user with getline().
 * \returns 0 if everything is successful, -1 otherwise.
 */
int main() {
    // Gets input image filename from user
    string inputFilename;
    cout << "Enter image file name: ";
    getline(cin, inputFilename);

    // Gets meme text from user
    string memeText;
    cout << "Enter meme text: ";
    getline(cin, memeText);

    // Gets output filename from user
    string outputFilename;
    cout << "Enter output file name: ";
    getline(cin, outputFilename);

    return makeMeme(inputFilename, memeText, outputFilename);
}