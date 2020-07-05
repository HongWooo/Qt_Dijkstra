#include "Dijkstra.h"
#include"EdtGraph.h"
#include"ChoosePoint.h"
#include"qdebug.h"
#include"qpainter.h"
#include"qmessagebox.h"
#include"qfiledialog.h"
#include<cmath>

#define PI 3.1415926

Dijkstra::Dijkstra(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.action_edt, SIGNAL(triggered()), this, SLOT(onEditGraph()));
	connect(ui.action_start, SIGNAL(triggered()), this, SLOT(onChoose()));
	connect(ui.btn_nextstep, SIGNAL(clicked()), this, SLOT(onNext()));
	connect(ui.action_load, SIGNAL(triggered()), this, SLOT(onFileOpen()));
	connect(ui.btn_finish, SIGNAL(clicked()), this, SLOT(onFinish()));
}	

int Dijkstra::onEditGraph() {
	EdtGraph edtg;
	int ret = edtg.exec();
	if (ret == QDialog::Accepted) {

		qDebug() <<edtg.v_num << endl;
		qDebug() << edtg.info << endl;

		if (edtg.v_num != ""&&edtg.info != "") {

			ui.action_start->setEnabled(true);	//可以选择起点
					
			int temp_v = edtg.v_num.toInt();
			g = new Graph(temp_v);
			initPos(temp_v, "");	//初始化画图位置
			g->createGraph(edtg.info);	//初始化图class

			count = 1;	//重置count

		}
		else {
			QMessageBox::information(this, "error", u8"请输入完整的图的信息");
		}
	}
 	return 0;
}


int Dijkstra::onFileOpen() {
	QString filepath = QFileDialog::getOpenFileName(this, u8"加载文件");
	qDebug() <<"fp = " <<filepath << endl;
	if (filepath == "")
		return 0;
	FILE *fp = fopen(filepath.toStdString().c_str(), "rb");
	char buf[1000];
	int n = fread(buf, 1, 1000, fp);
	buf[n] = 0;
	fclose(fp);
	QString text = buf;
	QString newtext = "";
	QString temp = "";
	int vn = 0;
	bool tag = true;
	if (text[text.size() - 1] != '\n') {
		text += "\r\n";
	}
	for (int i = 0;i < text.size();i++) {
		if (text[i] == '\r'||text[i] == '\0') {
			if (tag) {	//第一行
				vn = temp.toInt();
				tag = false;
				temp = "";
			}
			else {
				newtext += temp;
				temp = "";
			}
		}
		else {
			temp += text[i];
		}
	}
	QString s = "";
	for (int i = 1;i < newtext.size();i++) {
		s += newtext[i];
	}
	qDebug() <<"s = " <<s << endl;
	ui.action_start->setEnabled(true);	//可以选择起点
	g = new Graph(vn);
	initPos(vn, "");	//初始化画图位置
	g->createGraph(s);	//初始化图class

	count = 1;	//重置count

	return 0;
}

//选择起点
int Dijkstra::onChoose() {
	ChoosePoint cp;
	QStringList slist;
	QTableWidgetItem *items = new QTableWidgetItem[vnum-1];
	for (int i = 1;i <= vnum;i++) {
		slist.append(QString::number(i));
		items->setText(QString::number(i));
	}
	cp.ui.cb_start->addItems(slist);
	int ret = cp.exec();
	if (ret == QDialog::Accepted) {
		//选择起点后
		ui.table->setRowCount(vnum);    //设置行数
		ui.table->setColumnCount(2); //设置列数
		ui.table->setHorizontalHeaderLabels(QStringList()<<u8"距离"<<u8"路径");
		//ui.table->setEnabled(false);
		ui.btn_nextstep->setEnabled(true);
		ui.btn_finish->setEnabled(true);
		begin = cp.startpoint;
		qDebug() <<u8"起点" <<begin << endl;

		//设置起点的到起点的路径为0
		g->dis[begin - 1].value = 0;
		g->arc[begin - 1][begin - 1] = 0;
		g->dis[begin - 1].visit = true;
		for (int i = 0;i < vnum;i++) {
			g->dis[i].path = "v" + QString::number(begin) + "--v" + QString::number(i + 1);
			g->dis[i].value = g->arc[begin - 1][i];
			if (g->dis[i].value == INT_MAX) {
				ui.table->setItem(i, 0, new QTableWidgetItem(u8"∞"));
				ui.table->setItem(i, 1, new QTableWidgetItem(u8"无"));
			}
			else {
				ui.table->setItem(i, 0, new QTableWidgetItem(QString::number(g->dis[i].value)));
				ui.table->setItem(i, 1, new QTableWidgetItem(g->dis[i].path));
			}

			//ui.table->item(begin - 1, 0)->setForeground(Qt::red);
			
			count = 1;	//重置count
			for (int i = 0;i < vnum;i++) {
				if (i + 1 == begin)
					continue;
				g->dis[i].visit = false;
			}
		}
	}
	return 0;
}

void Dijkstra::initPos(int v, QString s) {
	m_nodePos.clear();
	vnum = v;
	float delta = (360.0 / (vnum))*PI / 180.0;
	int radius = height() / 2 - 70;
	QPoint center(width() / 2 - 180, height() / 2);
	for (int i = 0; i < vnum; i++)
	{
		QPoint c;
		c.setX(center.x() + radius * sin(delta*i));
		c.setY(center.y() + radius * cos(delta*i));

		m_nodePos.push_back(c);
	}
	update();
}

void Dijkstra::paintEvent(QPaintEvent *event) {
	QPainter painter(this);

	if (m_nodePos.size() == 0)
		return;

	for (int i = 0; i < vnum; i++)
	{
		QPoint c(m_nodePos[i]);

		// draw node
		if(i+1==begin)
			painter.setBrush(QBrush(QColor(255, 0, 0, 160)));
		else if(g->dis[i].visit){
			painter.setBrush(QBrush(QColor(0, 255, 0, 160)));
		}
		else
			painter.setBrush(QBrush(QColor(1, 101, 187, 160)));
		painter.setPen(QPen(QColor(255, 255, 255, 0)));
		painter.drawEllipse(c, 20, 20);

		QPen pen(QColor(54, 52, 51));
		pen.setWidth(4);
		painter.setPen(pen);
		painter.setFont(QFont("Consolas", 19));
		QPoint tc(c.x() - 7, c.y() + 7);
		painter.drawText(tc, QString::number(i+1));
	}

	// draw edge
	for (int i = 1; i <= vnum; i++)
	{
		for (int k = 1; k <= vnum ; k++)
		{
			int length = g->getDis(i,k);	//i到k的距离

			if (length == INT_MAX || length==0)	//没有通路
				continue;

			QPoint s(m_nodePos[i-1]);
			QPoint e(m_nodePos[k-1]);
			QPoint tpos;	//距离标注的位置
			if (e.x() - s.x() == 0) {
				tpos.setX((s.x() + e.x()) / 2);
				tpos.setY((s.y() + e.y()) / 2 - 30 * (e.y() - s.y()) / abs(e.y() - s.y()));
			}
			else if (e.y() - s.y() == 0) {
				tpos.setX((s.x() + e.x()) / 2 - 30 * (e.x() - s.x()) / abs(e.x() - s.x()));
				tpos.setY((s.y() + e.y()) / 2);
			}
			else {
				tpos.setX((s.x() + e.x()) / 2 - 30 * (e.x() - s.x()) / abs(e.x() - s.x()));
				tpos.setY((s.y() + e.y()) / 2 - 30 * (e.y() - s.y()) / abs(e.y() - s.y()));
			}

			//箭头
			double alpha = atanf(1.0*(e.y() - s.y()) / (e.x() - s.x()));
			double r = 20.0;

			double a1 = PI / 4 + alpha;
			double a2 = PI / 4 - alpha;
			QPoint p1;
			QPoint p2;
			if (e.x() >= s.x()) {
				p1.setX(e.x() - r * cos(a1));
				p1.setY(e.y() - r * sin(a1));
				p2.setX(e.x() - r * cos(a2));
				p2.setY(e.y() + r * sin(a2));
			}
			else {
				p1.setX(e.x() + r * cos(a1));
				p1.setY(e.y() + r * sin(a1));
				p2.setX(e.x() + r * cos(a2));
				p2.setY(e.y() - r * sin(a2));
			}

			QPen pen(QColor(124, 122, 121, 150));
			pen.setWidth(3);
			painter.setPen(pen);
			painter.drawLine(s, e);
			painter.drawLine(e, p1);
			painter.drawLine(e, p2);


			QPen pen1(QColor(28, 114, 14));
			pen1.setWidth(2);
			painter.setPen(pen1);
			painter.setFont(QFont("Consolas", 19));
			painter.drawText(tpos, QString::number(length));
		}
	}
}


void Dijkstra::mousePressEvent(QMouseEvent *event)
{
	QPoint pos = event->pos();
	m_currentID = -1;

	for (int i = 0; i < m_nodePos.size(); i++)
	{
		int dx = pos.x() - m_nodePos[i].x();
		int dy = pos.y() - m_nodePos[i].y();

		int dist = sqrt(dx*dx + dy * dy);

		if (dist < 20)
		{
			m_currentID = i;

		}
	}
}

void Dijkstra::mouseMoveEvent(QMouseEvent *event)
{

	if (m_currentID == -1)
		return;

	m_nodePos[m_currentID] = event->pos();

	update();
}

void Dijkstra::mouseReleaseEvent(QMouseEvent *event)
{
	m_currentID = -1;
}

//主要算法
int Dijkstra::onNext() {
	if (count != vnum) {
		//temp用于保存当前dis数组中最小的那个下标
		//min记录的当前的最小值
		int temp = 0;
		int min = INT_MAX;
		for (int i = 0;i < vnum;i++) {
			if (!g->dis[i].visit&&g->dis[i].value <= min) {
				min = g->dis[i].value;
				temp = i;
			}
		}
		qDebug() << "temp = " << temp << endl;
		g->dis[temp].visit = true;
		ui.table->item(temp, 0)->setForeground(Qt::darkGreen);
		update();
		++count;
		if (min != INT_MAX) {
			for (int i = 0;i < vnum;i++) {
				if (!g->dis[i].visit && g->arc[temp][i] != INT_MAX 
					&& (g->dis[temp].value + g->arc[temp][i]) < g->dis[i].value) {
					g->dis[i].value = g->dis[temp].value + g->arc[temp][i];
					g->dis[i].path = g->dis[temp].path + "--v" + QString::number(i + 1);
					ui.table->setItem(i, 0, new QTableWidgetItem(QString::number(g->dis[i].value)));
					ui.table->setItem(i, 1, new QTableWidgetItem(g->dis[i].path));
				}
			}		
		}
	}
	else {
		ui.btn_nextstep->setEnabled(false);
	}
	return 0;
}

int Dijkstra::onFinish() {
	while (count != vnum) {
		onNext();
	}
	ui.btn_nextstep->setEnabled(false);
	return 0;
}