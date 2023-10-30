#include "NetherPos.h"

#include <iostream>
#include <ostream>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qradiobutton.h>

struct Pos
{
	int x = 0;
	int y = 0;
	int z = 0;

	Pos() {}

	Pos(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	friend std::ostream& operator<<(std::ostream& os, const Pos& pos);
};

std::ostream& operator<<(std::ostream& os, const Pos& pos)
{
	os << "X=" << pos.x << '\n';
	os << "Y=" << pos.y << '\n';
	os << "Z=" << pos.z << '\n';
	return os;
}

Pos getNetherPos(Pos overworldPos)
{
	Pos netherPos;
	netherPos.x = overworldPos.x / 8;
	netherPos.y = overworldPos.y;
	netherPos.z = overworldPos.z / 8;
	return netherPos;
}

Pos getOverworldPos(Pos netherPos)
{
	Pos overworldPos;
	overworldPos.x = netherPos.x * 8;
	overworldPos.y = netherPos.y;
	overworldPos.z = netherPos.z * 8;
	return overworldPos;
}

NetherPos::NetherPos(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NetherPosClass())
{
    ui->setupUi(this);

	this->setFixedSize(this->size());

	connect(ui->calculatePushButton, &QPushButton::clicked, this, &NetherPos::calculatePushButton_clicked);

	connect(ui->worldRadioButton, &QRadioButton::toggled, this, &NetherPos::updateInstructionLabelWorld);
	connect(ui->netherRadioButton, &QRadioButton::toggled, this, &NetherPos::updateInstructionLabelNether);
}

NetherPos::~NetherPos()
{
    delete ui;
}

void NetherPos::calculatePushButton_clicked()
{
	if (!ui->netherRadioButton->isChecked() && !ui->worldRadioButton->isChecked())
	{
		QMessageBox::warning(this, "Warning", "You have not selected a mode.");
		return;
	}

	if (ui->netherRadioButton->isChecked())
	{
		Pos pos(ui->xSpinBox->value(), 1, ui->zSpinBox->value());
	    Pos netherPos = getNetherPos(pos);

		// update the label with the position data
		ui->resultLabel->setText("X:"+QString::number(netherPos.x)+", Z:" + QString::number(netherPos.z));
	}
	else if (ui->worldRadioButton->isChecked())
	{
		Pos pos(ui->xSpinBox->value(), 1, ui->zSpinBox->value());
		Pos netherPos = getOverworldPos(pos);

		// update the label with the position data
		ui->resultLabel->setText("X:" + QString::number(netherPos.x) + ", Z:" + QString::number(netherPos.z));
	}
}

void NetherPos::updateInstructionLabelWorld()
{
	if (ui->worldRadioButton->isChecked())
	{
		ui->instructionLabel->setText("Enter a world position");
	}
}

void NetherPos::updateInstructionLabelNether()
{
	if (ui->netherRadioButton->isChecked())
	{
		ui->instructionLabel->setText("Enter a nether position");
	}
}