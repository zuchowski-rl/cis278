// read file containing integers separated by white space into a vector using istream_iterator
// print contents of the vector

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

// class for reading integers from a file into a vector
class FileReader {
  private:
    std::vector<int> values; // vector to store integers read from the file

  public:
    void read_file(const std::string &file_path) {
        std::ifstream input_file(file_path);
        if (!input_file) {
            std::cerr << "Error, could not open file: " << file_path << std::endl;
            return;
        }

        // use istream_iterator to read integers from file
        std::istream_iterator<int> start(input_file);
        std::istream_iterator<int> end;

        // copy values from file into vector using back_inserter
        values.clear(); // ensure vector is empty
        std::copy(start, end, std::back_inserter(values));

        input_file.close();
    }

    void display_values() const {
        std::cout << "Values read from file: ";
        for (int value : values) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    FileReader reader;
    std::string file_path;

    std::cout << "Enter file path: ";
    std::cin >> file_path;

    reader.read_file(file_path);
    reader.display_values();
}
