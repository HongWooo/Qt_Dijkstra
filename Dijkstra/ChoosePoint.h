#pragma once

#include <QDialog>
#include "ui_ChoosePoint.h"

class ChoosePoint : public QDialog
{
	Q_OBJECT

public:
	ChoosePoint(QWidget *parent = Q_NULLPTR);
	~ChoosePoint();

private slots:
	int onChooseOk();
public:
	Ui::ChoosePoint ui;
	int startpoint;
};
