// FileIO_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// FileIO_6.cpp : Processing of  BMP File Format for 24-bit True Color Images


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <string_view>
#include <tuple>
#include <stdexcept>
#include <utility>
/**
Processes a pixel by forming the negative.
    @param blue the blue value of the pixel
    @param green the green value of the pixel
    @param red the red value of the pixel
 */
void process(int& blue, int& green, int& red) {
    blue = (blue - 120) % 256;
    green = (green - 120) % 256;
    red = (red - 120) % 256;
}

/**
Gets an integer from a binary stream.
@param stream the stream
@param offset the offset at which to read the integer
@return the integer starting at the given offset
 */
int get_info(std::fstream& iostream, unsigned offset) {
    iostream.seekg(offset, std::ios::beg);
    int result{ 0 };
    int base{ 1 };
    constexpr size_t number_of_bytes_in_integer{ 4 };
    for (size_t i{ 1 }; i <= number_of_bytes_in_integer; i++) {
        result = result + iostream.get() * base;
        base = base * 256;
    }

    return result;
}
/*

char MyBytes[4];  //set values to this also.
int Int32 = 0;

Int32 = (Int32 << 8) + MyBytes[3];
Int32 = (Int32 << 8) + MyBytes[2];
Int32 = (Int32 << 8) + MyBytes[1];
Int32 = (Int32 << 8) + MyBytes[0];
 */

std::string get_file_name() {
    std::string filename{};
    std::cout << "Please enter the file name: ";
    std::cin >> filename;
    return filename;
}

using imageinfo = std::tuple<int, int, int, int>;

imageinfo get_image_meta_data(std::fstream& io_stream) {
    // Get the Meta data
    int file_size_byte{ 2 }; // Get the image size
    int file_size = get_info(io_stream, file_size_byte);

    const int data_start_offset{ 10 }; // Offset to the starting of data in file
    int start = get_info(io_stream, data_start_offset);

    const int image_width_byte{ 18 }; // image Width 
    int width = get_info(io_stream, image_width_byte);

    const int image_height_byte{ 22 }; // image height 
    int height = get_info(io_stream, image_height_byte);

    return imageinfo{ file_size,start,width,height };
}

int get_padding_factor(unsigned scanline_size) {
    // Scan lines must occupy multiples of four bytes
    int padding{ 0 };
    const int scan_line_factor{ 4 };
    if (scanline_size % scan_line_factor != 0) {
        padding = scan_line_factor - (scanline_size % scan_line_factor);
    }
    return padding;
}

void process_image_file(std::string_view filename) {

    std::fstream io_stream{};
    // Open as a binary file
    io_stream.open(filename.data(), std::ios::in | std::ios::out | std::ios::binary);
    if (io_stream.fail()) {
        throw std::runtime_error("file not found\n");
    }

    imageinfo img_info = get_image_meta_data(io_stream);
    auto& [file_size, start, width, height] = img_info; //unpacking of tuple : structure binding


    const int number_of_bytes_in_pixel{ 3 };
    int scanline_size = width * number_of_bytes_in_pixel;
    int padding = get_padding_factor(scanline_size);

    /*  file_size != (meta_data + image_data) */
    if (file_size != (start + (scanline_size + padding) * height)) {
        throw std::runtime_error("Not a  24 -bit true color image file.");
    }

    // Go to the start of the pixels of image data
    io_stream.seekg(start, std::ios::beg);
    //  io_stream.seekp(start, std::ios::beg);
    for (int row = 1; row <= height; ++row) // For each scan line
    {
        for (int pixel = 1; pixel <= width; ++pixel) // For each pixel
        {
            std::streampos pos = io_stream.tellg(); // Go to the start of the pixel

             /* Reads One Pixel with 3 get()*/
            int blue = io_stream.get();   //get the blue color value
            int green = io_stream.get();   //get the green color value
            int red = io_stream.get();     //get the red color value

            process(blue, green, red); // Process the pixel

            io_stream.seekp(pos, std::ios::beg); // Go back to the start of the pixel

            io_stream.put(blue); // Write the pixel
            io_stream.put(green);
            io_stream.put(red);
        }
        // Skip the padding
        io_stream.seekg(padding, std::ios::cur);
    }

    io_stream.close();
}

int main() {
    try {
        std::string filename = get_file_name();
        process_image_file(filename);
    }
    catch (std::exception& err) {
        std::cerr << err.what();
    }
    return 0;
}

//
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <string>
//using namespace std;
//
///**
//Processes a pixel by forming the negative.
//@param blue the blue value of the pixel
// @param green the green value of the pixel
// @param red the red value of the pixel
// */
//void process(int& blue, int& green, int& red) {
//    blue = 255 - blue;
//    green = 255 - green;
//    red = 255 - red;
//}
//
///**
//Gets an integer from a binary stream.
//@param stream the stream
//@param offset the offset at which to read the integer
//@return the integer starting at the given offset
// */
//int get_int(fstream& stream, int offset) {
//    /*Reposition get Pointer to position number 2*/
//    stream.seekg(offset, ios::beg);
//    int result = 0;
//    int base = 1;
//    for (int i = 0; i < 4; i++) {
//        result = result + stream.get() * base;
//        base = base * 256;
//    }
//    return result;
//}
//
///*
// 
//char MyBytes[4];  //set values to this also.
//int Int32 = 0;
//
//Int32 = (Int32 << 8) + MyBytes[3];
//Int32 = (Int32 << 8) + MyBytes[2];
//Int32 = (Int32 << 8) + MyBytes[1];
//Int32 = (Int32 << 8) + MyBytes[0];
// */
//
//
//int main() {
//    cout << "Please enter the file name: ";
//    string filename;
//    cin >> filename;
//
//    fstream stream;
//    // Open as a binary file
//    stream.open(filename.c_str(), ios::in | ios::out | ios::binary);
//
//    int file_size = get_int(stream, 2); // Get the image dimensions
//    int start = get_int(stream, 10);
//    int width = get_int(stream, 18);
//    int height = get_int(stream, 22);
//
//    // Scan lines must occupy multiples of four bytes
//    int scanline_size = width * 3;
//    int padding = 0;
//    if (scanline_size % 4 != 0) {
//        padding = 4 - scanline_size % 4;
//    }
//
//    if (file_size != start + (scanline_size + padding) * height) {
//        cout << "Not a  24 -bit true color image file." << endl;
//        return 1;
//    }
//
//    //Reposition get pointer to the image data
//    stream.seekg(start, ios::beg); // Go to the start of the pixels
//
//    for (int i = 0; i < height; i++) // For each scan line
//    {
//        for (int j = 0; j < width; j++) // For each pixel
//        {
//            int pos = stream.tellg(); // Go to the start of the pixel
//
//            // Read the one pixel
//            int blue = stream.get();
//            int green = stream.get();
//            int red = stream.get();
//
//            process(blue, green, red); // Process the pixel
//            // Go back to the start of the pixel
//            stream.seekp(pos, ios::beg);
//
//            stream.put(blue); // Write the pixel
//            stream.put(green);
//            stream.put(red);
//        }
//        // Skip the padding
//        stream.seekg(padding, ios::cur); 
//    }
//
//    stream.close();
//    return 0;
//}