#ifndef LINK_PRO_H
#define LINK_PRO_H

#include <QtGui/QMainWindow>
#include "ui_link_pro.h"

#include "DBConnection.h"
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlRecord>
#include <QDebug>
#include <iostream>
#ifndef Q_MOC_RUN 
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#endif

using namespace boost;

typedef property<edge_weight_t, int> EdgeWeightProperty;
typedef adjacency_list < vecS, vecS, undirectedS, int, EdgeWeightProperty > Graph;
typedef std::pair<int, int> E;
typedef graph_traits<Graph>::edge_descriptor Edge;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef property_map<Graph, vertex_bundle_t>::type VerAll;

class custom_dfs_visitor;
class link_pro : public QMainWindow
{
	Q_OBJECT
	friend custom_dfs_visitor;
public:
	link_pro(QWidget *parent = 0, Qt::WFlags flags = 0);
	~link_pro();

private:
	Ui::link_proClass ui;
	QTableView *mView;
	
	void initModel();
	void initView();
};

#endif // LINK_PRO_H
