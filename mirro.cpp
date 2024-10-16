#include "mirro.h"

bool flat_mirro::IsCross(light Light) {
    auto points = Light.GetPoints();

    double m_k = (A_.y - B_.y) / (A_.x - B_.x);
    double m_b = (B_.x * A_.y - A_.x * B_.y) / (B_.x - A_.x);

    double l_k = (points.first.y - points.second.y) / (points.first.x - points.second.x);
    double l_b = (points.second.x * points.first.y - points.first.x * points.second.y) / (points.second.x - points.first.x);

    double x = (m_b - l_b) / (l_k - m_k);
    double y = l_k * x + l_b;

    math_vector vec(points.first, Point(x, y));

    float res = Light.GetAngle(vec);

    return x - points.second.x <= 3 && x - points.second.x >= -3 &&
           y - points.second.y <= 3 && y - points.second.y >= -3 &&
               (x >= A_.x && x <= B_.x || x <= A_.x && x >= B_.x) &&
                   (y >= A_.y && y <= B_.y || y <= A_.y && y >= B_.y);
}


Point flat_mirro::Cross(light Light) {
    auto points = Light.GetPoints();

    double m_k = (A_.y - B_.y) / (A_.x - B_.x);
    double m_b = (B_.x * A_.y - A_.x * B_.y) / (B_.x - A_.x);

    double l_k = (points.first.y - points.second.y) / (points.first.x - points.second.x);
    double l_b = (points.second.x * points.first.y - points.first.x * points.second.y) / (points.second.x - points.first.x);

    double x = (m_b - l_b) / (l_k - l_b);
    double y = l_k * x + l_b;

    return Point(x, y);
}

light flat_mirro::Reflect(light Light) {
    light ans = Light;
    ans.setPoint(Light.GetPoints().second);
    ans = ans.Rotate(2 * std::min(ans.GetAngle(math_vector(A_, B_)), ans.GetAngle(math_vector(B_, A_))));

    return ans;
}