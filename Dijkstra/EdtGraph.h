#pragma once

#include <QDialog>
#include "ui_EdtGraph.h"

class EdtGraph : public QDialog
{
	Q_OBJECT

public:
	EdtGraph(QWidget *parent = Q_NULLPTR);
	~EdtGraph();
private slots:
	int onOk();
	int onCancel();
	int onRand();
private:
	Ui::EdtGraph ui;
public:
	QString v_num, e_num, info;
};
