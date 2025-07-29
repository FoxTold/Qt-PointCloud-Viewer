#pragma once

#include <string>
#include <vector>
#include <fstream>

namespace ui
{

    struct Point3D
    {
        float x, y, z;
    };

    class PointCloudLoader
    {
    public:
        PointCloudLoader() = default;

        void loadFromXYZ(const std::string &);

        const std::vector<Point3D> &getPoints() const { return _points; };

    private:
        size_t getNumberOfPointsInXYZFile(std::ifstream&);
    private:
        std::vector<Point3D> _points;
    };
}
