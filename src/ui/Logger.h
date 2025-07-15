#include <QObject>
#include <QDebug>
#include "utils/Singleton.h"

class Logger : public ui::utils::Singleton<Logger>, public QObject
{
    Q_OBJECT

public:
    void log(const std::string &message)
    {
        qDebug() << "Dupa\n";
        emit(newLogMessage);
    }
signals:
    void newLogMessage(const QString &message);

private:
    Logger() = default;
};