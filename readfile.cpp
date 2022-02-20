#include "readfile.h"
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QList>
#include <QStringList>


ReadFile::ReadFile(QObject *parent)
{
    QFile file("../testCanvas/pomiary.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        qInfo("return");
        return;
    }

    QTextStream in(&file);
    QTextStream out(stdout);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList data = line.split(";");

        this->m_data.append(data[0].toInt());
        this->m_data.append(data[1].toInt());
    }
    out << this->m_data.length() << " length\n";
    file.close();

}


QVector<int> ReadFile::data() const
{
    return m_data;
}

void ReadFile::setData(const QVector<int>& _data)
{
    this->m_data = _data;
    emit dataChanged();
}
