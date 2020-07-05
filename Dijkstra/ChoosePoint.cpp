#include "ChoosePoint.h"

ChoosePoint::ChoosePoint(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.btn_chok, SIGNAL(clicked()), this, SLOT(onChooseOk()));
}

ChoosePoint::~ChoosePoint()
{
}
int ChoosePoint::onChooseOk() {
	startpoint = ui.cb_start->currentText().toInt();
	accept();
	return 0;
}
