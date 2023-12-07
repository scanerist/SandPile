
#ifndef IMAGE_CPP__PARSE_H_
#define IMAGE_CPP__PARSE_H_
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include<sstream>

class Parse {
 private:
  std::vector<std::vector<int>> model;

  uint16_t length;
  uint16_t width;

  std::string tsv_filepath;
  std::string output_filepath;

  uint32_t iterations;
  uint32_t frequency;



  std::string buf;


 public:
  void parse_console(int numb_of_options, char **options);
  void tsv_file_parsing();
  uint16_t get_length();
  uint16_t get_width() const;
  int get_iterations() const;
  uint32_t get_frequency() const;
  std::string get_path_output();
  std::vector<std::vector<int>> get_model() const;
};

#endif //IMAGE_CPP__PARSE_H_
