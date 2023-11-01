#ifndef NETHERPOS_H
#define NETHERPOS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class NetherPos; }
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
    Ui::NetherPos *ui;
};
#endif // NETHERPOS_H
