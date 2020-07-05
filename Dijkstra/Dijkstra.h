#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Dijkstra.h"
#include"Graph.h"
class Dijkstra : public QMainWindow
{
	Q_OBJECT

public:
	Dijkstra(QWidget *parent = Q_NULLPTR);
	void initPos(int v,QString s);
private slots:
	int onEditGraph();
	int onChoose();
	int onNext();
	int onFinish();
	int onFileOpen();
private:
	Ui::DijkstraClass ui;
	QList<QPoint> m_nodePos;
	int vnum;
	Graph *g;
	int begin = -1;	//起点
	void dij(int begin);
	int count = 1;	//下一步按钮的计数器
protected:
	int m_currentID;
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
};
