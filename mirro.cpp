#include "mirro.h"

bool flat_mirro::IsCross(light Light) {
  auto points = Light.GetPoints();

    double light_b = (points.first.y * points.second.x - points.first.x * points.second.y)
              / (points.second.x - points.first.x);
    double light_k = (points.first.y - points.second.y) / (points.first.x - points.second.x);

    double mirro_b = (A_.x * B_.y - A_.y * B_.x) / (A_.x - B_.x);
    double mirro_k = (A_.x - B_.x) / (A_.y - B_.y);

  Point ans((mirro_b - light_b) / (light_k - mirro_k),
               (mirro_b * light_k - mirro_k * light_b) / (light_k - mirro_k));

  return Light.GetAngle(math_vector(points.first, ans)) == 0;
}


Point flat_mirro::Cross(light Light) {
    auto points = Light.GetPoints();

    double light_b = (points.first.y * points.second.x - points.first.x * points.second.y)
                / (points.second.x - points.first.x);
    double light_k = (points.first.y - points.second.y) / (points.first.x - points.second.x);

    double mirro_b = (A_.x * B_.y - A_.y * B_.x) / (A_.x - B_.x);
    double mirro_k = (A_.x - B_.x) / (A_.y - B_.y);

    Point ans((mirro_b - light_b) / (light_k - mirro_k),
                 (mirro_b * light_k - mirro_k * light_b) / (light_k - mirro_k));

    return ans;
}

light flat_mirro::Reflect(light Light) {
    light ans = Light;
    ans.setPoint(Light.GetPoints().second);
    ans = ans.Rotate(2 * std::min(ans.GetAngle(math_vector(A_, B_)), ans.GetAngle(math_vector(B_, A_))));

    return ans;
}