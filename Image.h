#include <vector>
#include<string>

#ifndef LABWORK3__IMAGE_H_
#define LABWORK3__IMAGE_H_

struct Color{
  float r;
  float g;
  float b;
  Color();
  Color(float r, float g, float b);
  ~Color();

};
class Image {
 public:
  Image(int width, int height);
  ~Image();

  Color GetColor(int x, int y) const;
  void SetColor(const Color& color, int x, int y);

  void Export(std::string path);
 private:
  int m_width;
  int m_height;
  std::vector<Color> m_colors;

};

#endif //LABWORK3__IMAGE_H_
