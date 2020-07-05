#include "Dijkstra.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Dijkstra w;
	w.show();
	return a.exec();
}
