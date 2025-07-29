#include "PointCloudLoader.h"

#include <format>
#include <stdexcept>
#include "Logger.h"

namespace ui
{

    void PointCloudLoader::loadFromXYZ(const std::string &path)
    {
        std::ifstream fp(path);

        if (!fp.is_open())
        {
            Logger::instance()->errorf(std::format("Couldn't open file: {}", path));
            throw std::invalid_argument(std::format("Couldn't open file: {}", path));
        }

        _points.clear();

        auto numberOfPoints = getNumberOfPointsInXYZFile(fp);
        _points.resize(numberOfPoints);

        float x,y,z;
        std::string line;
        size_t lineNumber = 0;
        while(std::getline(fp, line))
        { 
            std::istringstream iss(line);
            if(!(iss >> x >> y >> z))
            {
                Logger::instance()->tracef(std::format("Skipping line {} due to incorrect point coords: {}", lineNumber,line));
                continue;
            }
            _points.push_back({x,y,z});
            ++lineNumber;
        }
        if (numberOfPoints != lineNumber)
        {
            Logger::instance()->tracef(std::format("NumberOfPoints == {} | LineNumber == {}", numberOfPoints, lineNumber));
        }
        Logger::instance()->infof(std::format("Loaded {} points!", lineNumber));
    }

    size_t PointCloudLoader::getNumberOfPointsInXYZFile(std::ifstream& fp)
    {
        size_t numberOfPoints = 0;
        std::string line;
        float x, y, z;
        while(std::getline(fp, line))
        { 
            std::istringstream iss(line);
            if(iss >> x >> y >> z)
            {
                ++numberOfPoints;
            }
        }
        fp.clear();
        fp.seekg(0);

        return numberOfPoints;
    }
}
