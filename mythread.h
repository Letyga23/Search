﻿#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <functional>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSharedPointer>
#include <QMutex>
#include <QVector>
#include <math.h>
#include <QAtomicInt>

class MyThread : public QThread
{
    Q_OBJECT
    std::function<void()> _task;
    QSharedPointer<QSqlDatabase> _db;
    QSharedPointer<QSqlQueryModel> _query;

public:
    QMutex _runThreadMutex;
    static QMutex _searchMutex;
    static bool _resultIsFound;

public:
    MyThread(QObject* parent = nullptr);
    ~MyThread() override;
    void setTask(std::function<void()> task);
    void completion(QSharedPointer<QSqlQueryModel> model, QString nameTable, int limit, int offset, QString filters, QString columnsSort, QString typeSort);
    void getMaxPage(QString nameTable, int rowsPerPage, QString filters);
    void search(QString nameTable, QString column, QString like, QString typeSearch, QString filters, QString columnsSort, QString typeSort, int limit, int offset, int rowsPerPage);
    void getNameColumn(QString nameTable);
    bool isRun();
    void request(QString request);

protected:
    void run() override;

signals:
    void returnMaxPage(int);
    void completedSuccessfully();
    void searchResultFound(int, bool);
    void toSendNameColumng(QVector<QString>*);
    void requestFinished();
};

#endif // MYTHREAD_H
