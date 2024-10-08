#include "mirro.h"

template<class T>
bool flat_mirro<T>::IsCross(light<T> light) {
  auto p = light.GetPoints().second;

  T x_len = abs(A_.x - B_.x) / 1e5;
  T y_len = abs(A_.y - B_.y) / 1e5;

  T i = min(A_.x, B_.x);
  T j = min(A_.y, B_.y);

  while (i <= max(A_.x, B_.x) && j <= max(A_.y, B_.y)) {
    if (p.x == i && p.y == j) return 1;

    i += x_len;
    j += y_len;
  }

  return 0;
}

template<class T>
light<T> flat_mirro<T>::Reflect(light<T> Light) {
  light<T> ans(Light.getPoints().second);
  ans = -Light;
  return ans;
}