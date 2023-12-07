//
// Created by aliye on 10/30/2022.
//
#include "SandSpill.h"
#include "Image.h"
#include <string>

void SandSpill::sand_spill_model(int length,
                                 int width_model,
                                 int iterations_model,
                                 std::vector<std::vector<int>> grids,
                                 int frequency_model,
                                 const std::string &direct_path_model) const {
    for (int k = 0; k <= iterations_model; k++) {
        Image image(width_model, length);
        bool check_grids = false;
        for (int j = 0; j < width_model; j++) {
            for (int i = 0; i < length; i++) {
                if (grids[i][j] > 3) {
                    check_grids = true;
                    grids[i][j] -= 4;
                    if (i + 1 < grids.size()) {
                        grids[i + 1][j] += 1;
                    }

                    if (j + 1 < grids[i].size()) {
                        grids[i][j + 1] += 1;
                    }

                    if (i - 1 > 0) {
                        grids[i - 1][j] += 1;
                    }

                    if (j - 1 > 0) {
                        grids[i][j - 1] += 1;
                    }
                }
            }
        }

        if (frequency_model != 0 && (k % frequency_model == 0 || !check_grids)) {
            for (int l = 0; l < length; ++l) {
                for (int w = 0; w < width_model; ++w) {
                    if (grids[l][w] == 0) {
                        image.SetColor(Color(1.0f, 1.0f, 1.0f), w, l);
                    }
                    if (grids[l][w] == 1) {
                        image.SetColor(Color(0.0f, 1.0f, 0.0f), w, l);
                    }
                    if (grids[l][w] == 2) {
                        image.SetColor(Color(1.0f, 0.0f, 1.0f), w, l);
                    }
                    if (grids[l][w] == 3) {
                        image.SetColor(Color(1.0f, 1.0f, 0.0f), w, l);
                    }
                    if (grids[l][w] > 3) {
                        image.SetColor(Color(0.0f, 0.0f, 0.0f), l, w);
                    }

                }

            }
            if (frequency_model == 0 ){
                image.Export(direct_path_model + "\\" + std::to_string(k) + ".bmp");
            }
            image.Export(direct_path_model + "\\" + std::to_string(k) + ".bmp");
        }
        if (!check_grids) {
            break;
        }
    }
}