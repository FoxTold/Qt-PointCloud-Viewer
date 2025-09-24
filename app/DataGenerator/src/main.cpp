#include <iostream>
#include <fstream>
#include <vector>
#include <numbers>
#include <format>
namespace
{

    struct Point3D{
        double x,y,z;
    };
}

int main(void)
{
    constexpr int N = 1000;
    constexpr float radius = 25.0;
    const double phi = std::numbers::pi * (3.0 - std::sqrt(5.0));


    std::vector<Point3D> points;
    points.reserve(N);
    
    for (int i = 0; i < N; i++) {
        double z = 1.0 - (2.0 * i) / (N - 1.0);
        double r = std::sqrt(1.0 - z * z);

        double theta = phi * i;

        double x = r * std::cos(theta);
        double y = r * std::sin(theta);

        points.push_back({radius * x, radius * y, radius * z});
    }

    std::ofstream fp;
    fp.open("data.xyz");
    for(const auto& point : points)
    {
        fp << std::format("{} {} {}\n", point.x, point.y, point.z);
    }
    return 0;
}
