#include "Image.h"

#include <fstream>
#include <iostream>

Color::Color()
    : r(0), g(0), b(0) {
}
Color::Color(float r, float g, float b)
    : r(r), g(g), b(b) {}
Color::~Color() {
}

Image::Image(int width, int height)
    : m_width(width), m_height(height), m_colors(std::vector<Color>(width * height)) {}

Image::~Image() {}

Color Image::GetColor(int x, int y) const {
    return m_colors[y * m_width + x];
}

void Image::SetColor(const Color &color, int x, int y) {
    m_colors[y * m_width + x].r = color.r;
    m_colors[y * m_width + x].g = color.g;
    m_colors[y * m_width + x].b = color.b;
}

void Image::Export(std::string path) {
    std::ofstream file;
    file.open(path, std::ios::out | std::ios::binary);

    if (!file.is_open()) {
        std::cout << "file could not be opened\n";
        return;
    }

    unsigned char bmp_pad[3] = {0, 0, 0};
    const int padding_amount = ((4 - (m_width * 3) % 4) % 4);

    const int file_header_size = 14;
    const int information_header_size = 40;
    const int
        file_size = file_header_size + information_header_size + m_width * m_height * 3 + padding_amount * m_height;

    unsigned char file_header[file_header_size];

    file_header[0] = 'B';
    file_header[1] = 'M';
    file_header[2] = file_size;
    file_header[3] = file_size >> 8;
    file_header[4] = file_size >> 16;
    file_header[5] = file_size >> 24;
    file_header[6] = 0;
    file_header[7] = 0;
    file_header[8] = 0;
    file_header[9] = 0;
    file_header[10] = file_header_size + information_header_size;
    file_header[11] = 0;
    file_header[12] = 0;
    file_header[13] = 0;

    unsigned char information_header[information_header_size];

    information_header[0] = information_header_size;
    information_header[1] = 0;
    information_header[2] = 0;
    information_header[3] = 0;

    information_header[4] = m_width;
    information_header[5] = m_width >> 8;
    information_header[6] = m_width >> 16;
    information_header[7] = m_width >> 24;

    information_header[8] = m_height;
    information_header[9] = m_height >> 8;
    information_header[10] = m_height >> 16;
    information_header[11] = m_height >> 24;

    information_header[12] = 1;
    information_header[13] = 0;

    information_header[14] = 24;
    for (int i = 15; i < information_header_size; i++) {
        information_header[i] = 0;
    }

    file.write(reinterpret_cast<char *>(file_header), file_header_size);
    file.write(reinterpret_cast<char *>(information_header), information_header_size);

    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            unsigned char r = static_cast<unsigned char>(GetColor(x, y).r * 255.0f);
            unsigned char g = static_cast<unsigned char>(GetColor(x, y).g * 255.0f);
            unsigned char b = static_cast<unsigned char>(GetColor(x, y).b * 255.0f);

            unsigned char color[] = {b, g, r};

            file.write(reinterpret_cast<char *>(color), 3);
        }
        file.write(reinterpret_cast<char *>(bmp_pad), padding_amount);
    }
    file.close();

}
