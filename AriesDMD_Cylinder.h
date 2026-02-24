#ifndef ARIES_DMD_CYLINDER_H
#define ARIES_DMD_CYLINDER_H

#include "AriesDMD.h"

class AriesDMD_Cylinder {
public:
  AriesDMD_Cylinder(AriesDMD &dmd);

  void writePixel(int x, int y, bool on);

  int height() const;   // vertical (160)
  int circum() const;   // circumference (320)

private:
  AriesDMD &base;
  int wrapY(int y) const;
};

#endif
