#include "EdtGraph.h"
#include"qmessagebox.h"
EdtGraph::EdtGraph(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.btn_dlgok, SIGNAL(clicked()), this, SLOT(onOk()));
	connect(ui.btn_dlgcancel, SIGNAL(clicked()), this, SLOT(onCancel()));
	connect(ui.btn_dlgrand, SIGNAL(clicked()), this, SLOT(onRand()));
}

EdtGraph::~EdtGraph()
{
}

int EdtGraph::onOk() {
	v_num = ui.ledt_vnum->text();
	info = ui.edt_graphinfo->toPlainText();
	accept();
	return 0;
}
int EdtGraph::onCancel() {
	reject();
	return 0;
}

int  EdtGraph::onRand() {
	if (ui.ledt_vnum->text() == "") {
		QMessageBox::information(this, "error", u8"请填写顶点数");
	}
	else {
		int v = ui.ledt_vnum->text().toInt();
		QString temp = "";
		for (int i = 1; i <= v;i++) {
			for (int j = 1;j <= v;j++) {
				if (i == j)
					continue;
				if (rand() % 3 != 0)	//2/3几率
					continue;
				temp += (QString::number(i) + " ");
				temp += (QString::number(j) + " ");
				temp += (QString::number(rand() % 50));
				temp += "\n";
			}		
		}
		ui.edt_graphinfo->setPlainText(temp);
	}
	return 0;
}
