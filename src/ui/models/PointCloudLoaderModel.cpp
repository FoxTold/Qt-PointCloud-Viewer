#include "PointCloudLoaderModel.h"

#include "../Logger.h"
namespace ui::models{

    void PointCloudLoaderModel::loadPointCloudXYZ(QUrl path)
    {
        const auto pathString = path.toLocalFile().toStdString();
        Logger::instance()->tracef(std::format("Trying to load pointcloud from file: {}", pathString));
        _pointCloudLoader.loadFromXYZ(pathString);
        const auto points = _pointCloudLoader.getPoints();
        for(auto& point : points)
        {
            Logger::instance()->tracef(std::format("x:{:.4f}, y:{:.4f}, z:{:.4f}", point.x, point.y, point.z));
        }
    }
}
