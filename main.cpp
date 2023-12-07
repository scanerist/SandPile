#include "Image.h"
#include "Image.cpp"
#include "Parse.h"
#include "Parse.cpp"
#include "SandSpill.h"
#include "SandSpill.cpp"


int main(int argc, char *argv[]) {
Parse parse;
parse.parse_console(argc, argv);
SandSpill sanding;
parse.tsv_file_parsing();
sanding.sand_spill_model(parse.get_length(),
                         parse.get_width(),
                         parse.get_iterations(),
                         parse.get_model(),
                         parse.get_frequency(),
                         parse.get_path_output());
    Image image(parse.get_length(), parse.get_width());
    return 0;
}