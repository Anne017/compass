#ifndef MYTYPE_H
#define MYTYPE_H

#include <QObject>

class MyType : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString helloWorld READ helloWorld WRITE setHelloWorld NOTIFY helloWorldChanged )

public:
    explicit MyType(QObject *parent = 0);
    ~MyType();
    Q_INVOKABLE int launch();
    Q_INVOKABLE QString calibrate();
    int x_offset,y_offset,x_ampl,y_ampl;
Q_SIGNALS:
    void helloWorldChanged();

protected:
    QString helloWorld() { return m_message; }
    void setHelloWorld(QString msg) { m_message = msg; Q_EMIT helloWorldChanged(); }

    QString m_message;
};

#endif // MYTYPE_H

