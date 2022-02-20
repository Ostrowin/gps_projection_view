#ifndef READFILE_H
#define READFILE_H
#include <QList>
#include <QObject>
#include <QDateTime>
#include <QVector>

class ReadFile : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<int> data READ data WRITE setData NOTIFY dataChanged)

public:
    ReadFile(QObject *parent = nullptr);
    QVector<int> data() const;//READ interface
    void setData(const QVector<int>& _data);//WRITE interface

signals:
    QVector<int> dataChanged();//NOTIFY signal (not required)

private:
    QVector<int> m_data;//Private attributes
};

#endif // READFILE_H
