#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NetherPos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NetherPosClass; };
QT_END_NAMESPACE

class NetherPos : public QMainWindow
{
    Q_OBJECT

public:
    NetherPos(QWidget *parent = nullptr);
    ~NetherPos();

public slots:
    void calculatePushButton_clicked();

    void updateInstructionLabelWorld();
    void updateInstructionLabelNether();

private:
    Ui::NetherPosClass *ui;
};
