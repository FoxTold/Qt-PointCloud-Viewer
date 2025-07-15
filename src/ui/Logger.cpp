#include "Logger.h"
#include <QDateTime>

namespace ui
{
    void Logger::log(Level level, const QString &message)
    {
        QMutexLocker locker(&_mutex);

        if (level < _logLevel)
        {
            return;
        }

        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        QString levelStr = levelToString(level);
        QString formatted = QString("[%1] [%2] %3").arg(timestamp, levelStr, message);

        emit newLogMessage(formatted);
        qDebug() << formatted;
    }

    QString Logger::levelToString(Level level)
    {
        switch (level)
        {
        case Level::Trace:
            return QString::fromStdString("TRACE");
        case Level::Debug:
            return QString::fromStdString("DEBUG");
        case Level::Info:
            return QString::fromStdString("INFO");
        case Level::Warning:
            return QString::fromStdString("WARNING");
        case Level::Error:
            return QString::fromStdString("Error");
        case Level::Critical:
            return QString::fromStdString("CRITICAL");
        default:
            return QString::fromStdString("UNKNOWN");
        }
    }

    void Logger::trace(const QString &message)
    {
        log(Level::Trace, message);
    }

    void Logger::debug(const QString &message)
    {
        log(Level::Debug, message);
    }

    void Logger::info(const QString &message)
    {
        log(Level::Info, message);
    }

    void Logger::warn(const QString &message)
    {
        log(Level::Warning, message);
    }

    void Logger::error(const QString &message)
    {
        log(Level::Error, message);
    }

    void Logger::critical(const QString &message)
    {
        log(Level::Critical, message);
    }

    void Logger::tracef(const std::string& message)
    {
        log(Level::Trace, QString::fromStdString(message));
    }

    void Logger::debugf(const std::string& message)
    {
        log(Level::Debug, QString::fromStdString(message));
    }

    void Logger::infof(const std::string& message)
    {
        log(Level::Info, QString::fromStdString(message));
    }

    void Logger::warnf(const std::string& message)
    {
        log(Level::Info, QString::fromStdString(message));
    }

    void Logger::errorf(const std::string& message)
    {
        log(Level::Error, QString::fromStdString(message));
    }
    void Logger::criticalf(const std::string& message)
    {
        log(Level::Critical, QString::fromStdString(message));
    }
}
