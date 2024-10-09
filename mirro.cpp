#include "mirro.h"

template<class T>
bool flat_mirro<T>::IsCross(light<T> Light) {
  auto points = Light.GetPoints();

  T light_b = (points.first.y * points.second.x - points.first.x * points.second.y)
              / (points.second.x - points.first.x);
  T light_k = (points.first.y - points.second.y) / (points.first.x - points.second.x);

  T mirro_b = (A_.x * B_.y - A_.y * B_.x) / (A_.x - B_.x);
  T mirro_k = (A_.x - B_.x) / (A_.y - B_.y);

  Point<T> ans((mirro_b - light_b) / (light_k - mirro_k),
               (mirro_b * light_k - mirro_k * light_b) / (light_k - mirro_k));

  return Light.GetAngle(math_vector<T>(points.first, ans)) == 0;
}

template<class T>
Point<T> flat_mirro<T>::Cross(light<T> Light) {
    auto points = Light.GetPoints();

    T light_b = (points.first.y * points.second.x - points.first.x * points.second.y)
                / (points.second.x - points.first.x);
    T light_k = (points.first.y - points.second.y) / (points.first.x - points.second.x);

    T mirro_b = (A_.x * B_.y - A_.y * B_.x) / (A_.x - B_.x);
    T mirro_k = (A_.x - B_.x) / (A_.y - B_.y);

    Point<T> ans((mirro_b - light_b) / (light_k - mirro_k),
                 (mirro_b * light_k - mirro_k * light_b) / (light_k - mirro_k));

    return ans;
}

template<class T>
light<T> flat_mirro<T>::Reflect(light<T> Light) {
    light ans = Light;
    ans.setPoint(Light.GetPoints().second);
    ans = ans.Rotate(2 * min(ans.GetAngle(math_vector<T>(A_, B_)), ans.GetAngle(math_vector<T>(B_, A_))));

    return ans;
}