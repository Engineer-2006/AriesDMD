#include "AriesDMD_Cylinder.h"

AriesDMD_Cylinder::AriesDMD_Cylinder(AriesDMD &dmd)
  : base(dmd) {}

int AriesDMD_Cylinder::height() const {
  return base.height();
}

int AriesDMD_Cylinder::circum() const {
  return base.width();
}

int AriesDMD_Cylinder::wrapY(int y) const {
  int w = base.width();
  return (y % w + w) % w;
}

void AriesDMD_Cylinder::writePixel(int x, int y, bool on) {
  if (x < 0 || x >= base.height()) return;
  base.writePixel(x, wrapY(y), GRAPHICS_NORMAL, on);
}
