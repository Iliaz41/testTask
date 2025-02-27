#include <iostream>
#include <fstream>
#include <string>
#include <map>

std::string cipher(std::string input, std::map<char, char>& cipher_map) {
	std::string output;
    for (char c : input) {
        if (cipher_map.count(c)) {
            output += cipher_map[c];
        } else {
            output += c;
        }
    }
    return output;
}

int main() {
	std::map<char, char> cipher_map = {
        {'a', 'u'}, {'b', 'v'}, {'c', 'w'}, {'d', 'x'}, {'e', 'y'},
        {'f', 'z'}, {'g', 'a'}, {'h', 'b'}, {'i', 'c'}, {'j', 'd'},
        {'k', 'e'}, {'l', 'f'}, {'m', 'g'}, {'n', 'h'}, {'o', 'i'},
        {'p', 'j'}, {'q', 'k'}, {'r', 'l'}, {'s', 'm'}, {'t', 'n'},
        {'u', 'o'}, {'v', 'p'}, {'w', 'q'}, {'x', 'r'}, {'y', 's'},
        {'z', 't'}
    };

	std::ifstream input_file("input.bin", std::ios::binary);
    if (!input_file.is_open()) {
    	std::cout << "File wasn't opened input.bin" << std::endl;
        return 1;
    }

    std::ofstream output_file("output.bin", std::ios::binary);
    if (!output_file.is_open()) {
    	std::cout << "File wasn't created output.bin" << std::endl;
        return 1;
    }

    char buffer;
    while (input_file.read(&buffer, sizeof(buffer))) {
    	std::string input_str(1, buffer);
    	std::string output_str = cipher(input_str, cipher_map);
        output_file.write(output_str.c_str(), output_str.length());
    }

    input_file.close();
    output_file.close();

    return 0;
}
