#pragma once

#include <QObject>
#include <QUrl>
#include "utils/Singleton.h"

#include "../PointCloudLoader.h"

namespace ui::models{
    class PointCloudLoaderModel : public QObject, public Singleton<PointCloudLoaderModel>
    {
        Q_OBJECT
    
    public:
        Q_INVOKABLE void loadPointCloudXYZ(QUrl path);

        private:
            PointCloudLoader _pointCloudLoader;
    };
}
