#pragma once

#include <QObject>
#include <QDebug>
#include <QMutex>
#include "utils/Singleton.h"

namespace ui
{

    class Logger : public QObject, public Singleton<Logger>
    {
        Q_OBJECT
    public:
        enum class Level
        {
            Trace = 0,
            Debug,
            Info,
            Warning,
            Error,
            Critical
        };
        Q_ENUM(Level)

        Q_INVOKABLE void trace(const QString& message);
        Q_INVOKABLE void debug(const QString& message);
        Q_INVOKABLE void info(const QString& message);
        Q_INVOKABLE void warn(const QString& message);
        Q_INVOKABLE void error(const QString& message);
        Q_INVOKABLE void critical(const QString& message);

        void tracef(const std::string& message);
        void debugf(const std::string& message);
        void infof(const std::string& message);
        void warnf(const std::string& message);
        void errorf(const std::string& message);
        void criticalf(const std::string& message);

        Logger() = default;

    private:
        void log(Level level, const QString& message);
        QString levelToString(Level level);

        Level _logLevel = {Logger::Level::Trace};
        QMutex _mutex;

    signals:
        void newLogMessage(const QString& message);
    };
}
