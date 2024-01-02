#include "file.hpp"

int main(int ac, char **av)
{
    if (!av[2][0])
        return 0;
    if(ac == 4 && av[2][0])
    {
        std::string buffer;
        std::ifstream in_file(av[1]);
        if(in_file.is_open() && av[2][0])
        {
            std::string newFileName = std::string(av[1]) + ".replace";
            std::ofstream out_file(newFileName.c_str());
            while(std::getline(in_file, buffer))
            {
                int index = buffer.find(av[2]);
                while(index >= 0)
                {
                    buffer.erase(index, strlen(av[2]));
                    buffer.insert(index, av[3]);
                    index = buffer.find(av[2], index + strlen(av[3]));
                }
                out_file << buffer << std::endl;
            }
            in_file.close();
            out_file.close();
            std::cout << "File have been created successfully\n";
        }
        else
        {
            std::cout << "Failed to open the input file. Please make sure the file exists and you have the necessary permissions to read it.\n";
        }
    }
    else
        std::cout << "you should 4 arguments like this: \n" << av[0] << " <input_filename> <string_to_find> <replacement_string>\n";
}