#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>

struct Pixel
{
    uint8_t blue{};
    uint8_t green{};
    uint8_t red{};
    Pixel() = default;
    Pixel(uint8_t val) : blue{val}, green{val}, red{val} {}
    uint8_t to_gray_scale()
    {
        return 0.21 * red + 0.72 * green + 0.07 * blue;
    }
};

class Image
{
public:
    Image(const std::string &file_name) : file_stream{file_name, std::ios::binary | std::ios::in}
    {
        size = read_integer_at_position(file_stream, 2);
        start = read_integer_at_position(file_stream, 10);
        columns = read_integer_at_position(file_stream, 18);
        rows = read_integer_at_position(file_stream, 22);
    }

    void save_grayscale_to(const std::string &file_name)
    {
        std::ofstream out{file_name, std::ios::binary | std::ios::out};
        file_stream.seekg(0);

        // metadata
        char *metadata{new char[start + 1]};
        file_stream.read(metadata, start);
        out.write(metadata, start);
        delete[] metadata;

        // calculate padding length
        uint32_t true_width = columns * 3;
        if (true_width % 4 != 0)
        {
            true_width = (true_width / 4 + 1) * 4;
        }
        unsigned padding_length = true_width-columns*3;

        for (unsigned row = 0; row < rows; row++)
        {
            for (unsigned column = 0; column < columns; column++)
            {
                // write row pixels
                Pixel pixel;
                file_stream.read(reinterpret_cast<char *>(&pixel), sizeof(Pixel));
                uint8_t grayscale_value = pixel.to_gray_scale();
                Pixel grayscale_pixel{grayscale_value};
                out.write(reinterpret_cast<const char *>(&grayscale_pixel), sizeof(Pixel));
            }

            //write padding
            char* padding_content=new char[padding_length+1];
            file_stream.read(padding_content, padding_length);
            out.write(padding_content, padding_length);
            delete[] padding_content;
        }
    }

private:
    uint32_t read_integer_at_position(std::istream &in, unsigned pos)
    {
        uint32_t integer{};
        in.seekg(pos);
        in.read(reinterpret_cast<char *>(&integer), sizeof(uint32_t));
        return integer;
    }
    std::ifstream file_stream;
    uint32_t size;
    uint32_t start;
    uint32_t columns;
    uint32_t rows;
};

int main(int argc, char* argv[])
{
    Image img{argv[1]};
    img.save_grayscale_to("output.bmp");
    return 0;
}