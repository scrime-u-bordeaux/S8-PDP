#ifndef DEF_CASE
#define DEF_CASE

#include "../VisualImpro/utilities.hpp"
#include <QRect>

class Case : public QRect {
public:
  Case();
  void setColor(Triplet triplet);
  ~Case();

private:
};
#endif // DEF_CASE
