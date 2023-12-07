
#include "Parse.h"
void Parse::tsv_file_parsing() {

    int buf_smb;
    int x_coords;
    int y_coords;

    std::ifstream fin(tsv_filepath);
    if(!fin){
        std::cout<<"error";
    }

    model.resize(length, std::vector<int>(width, 0));



    while(std::getline(fin, buf, '\n')){
        std::stringstream str;
        str<< buf;
        str >> x_coords >> y_coords>>buf_smb;
        model[x_coords][y_coords] = buf_smb;
    }

}


void Parse::parse_console(int numb_of_arguments, char **argument) {
    std::vector<std::string> opts;
    for (int i = 0; i < numb_of_arguments; i++) {
        opts.push_back(argument[i]);
    }
    for (int k = 1; k < numb_of_arguments; k++) {
        if (strcmp(argument[k], "-l") == 0 || strcmp(argument[k], "--length") == 0) {
            length = std::stoi(argument[k + 1]);
        }
        if (strcmp(argument[k], "-w") == 0 || strcmp(argument[k], "--width") == 0) {
            width = std::stoi(argument[k + 1]);
        }
        if (strcmp(argument[k], "-i") == 0 || strcmp(argument[k], "--input") == 0) {
            tsv_filepath = argument[k + 1];
        }
        if (strcmp(argument[k], "-o") == 0 || strcmp(argument[k], "--output") == 0) {
            output_filepath = argument[k + 1];
        }
        if (strcmp(argument[k], "-m") == 0 || strcmp(argument[k], "--max-iter") == 0) {
            iterations = std::stoi(argument[k + 1]);
        }
        if (strcmp(argument[k], "-f") == 0 || strcmp(argument[k], "--frequency") == 0) {
            frequency = std::stoi(argument[k + 1]);
        }
    }

}


uint16_t Parse::get_length() {

    return length;
}

uint16_t Parse::get_width() const {

    return width;
}

int Parse::get_iterations() const {

    return iterations;
}

uint32_t Parse::get_frequency() const {

    return frequency;
}
std::string Parse::get_path_output() {

    return output_filepath;
}

std::vector<std::vector<int>> Parse::get_model() const  {

    return model;
}