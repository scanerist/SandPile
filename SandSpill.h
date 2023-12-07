#ifndef IMAGE_CPP__SANDSPILL_H_
#define IMAGE_CPP__SANDSPILL_H_

#include <vector>
#include <string>

class SandSpill {
 private:
  std::vector<std::vector<int>> picture;
  std::string direct_path;
 public:
void sand_spill_model(int length,
                      int width_model,
                      int iterations,
                      std::vector<std::vector<int>> grids,
                      int frequency_model,
                      const std::string& direct_path_mdoel) const;

};

#endif //IMAGE_CPP__SANDSPILL_H_
