#include "link_pro.h"


int treeNum = 1;
QMap<int, int> vecOjbs;
QMap<int, Vertex> mapVertex;

class custom_dfs_visitor : public boost::default_dfs_visitor 
{ public: template < typename Vertex, typename Graph >
void discover_vertex(Vertex u, const Graph & g)
const { std::cout << "At " << vertex(u,g) << std::endl; }
template < typename Edge, typename Graph >
void examine_edge(Edge e, const Graph& g) 
const { 
	int in_id = source(e, g);
	int out_id = target(e, g);
	if(vecOjbs[in_id] > 0)
	{
		vecOjbs[out_id] = vecOjbs[in_id];
	}else if(vecOjbs[out_id] > 0)
	{
		vecOjbs[in_id] = vecOjbs[out_id];
	}else
	{
		vecOjbs[in_id] = treeNum;
		vecOjbs[out_id] = treeNum;
		++treeNum;
	}
	qDebug() << source(e, g) << " <--> " << target(e, g);
} 
}; 

link_pro::link_pro(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	DBConnection::Singleton()->init();
	QSqlTableModel *model1 = DBConnection::Singleton()->getModel("target");
	model1->select();
	int modelSize1 = model1->rowCount();
	Graph g;
	for(int i = 0; i < modelSize1; ++i){
		QSqlRecord record = model1->record(i);
		int id = record.value("id").toInt();
		Vertex v = add_vertex(id, g);
		mapVertex[id] = v;
	}
	QSqlTableModel *model = DBConnection::Singleton()->getModel("link");
	model->select();
	int modelSize = model->rowCount();
	property_map<Graph, edge_weight_t>::type weightmap = get(edge_weight, g);
	for(int i = 0; i < modelSize; ++i){
		QSqlRecord record = model->record(i);
		int id = record.value("id").toInt();
		int in_id = record.value("in_id").toInt();
		int out_id = record.value("out_id").toInt();
		Edge e; 
		bool inserted;
		boost::tie(e, inserted) = add_edge(mapVertex[in_id], mapVertex[out_id], g);
		weightmap[e] = 1;
	}
	//Edge e; 
	//bool inserted;
	//boost::tie(e, inserted) = add_edge(mapVertex[4], mapVertex[3], g);
	//weightmap[e] = 1;
	//std::list< Edge > spanning_tree;
	//kruskal_minimum_spanning_tree(g, std::back_inserter(spanning_tree));
	//for (std::list < Edge >::iterator ei = spanning_tree.begin(); ei != spanning_tree.end(); ++ei)
	//{
	//	qDebug() << source(*ei, g) << " <--> " << target(*ei, g);
	//}
	model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("IN_ID"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("OUT_ID"));
	mView = new QTableView;
	mView->setModel(model);
	mView->show();

	custom_dfs_visitor vis;
	depth_first_search(g, visitor(vis));
	std::vector<int> d(num_vertices(g));
	// get the first vertex
	// invoke variant 2 of Dijkstra's algorithm
	foreach(Vertex v, mapVertex)
	{
		dijkstra_shortest_paths(g, v, distance_map(&d[0]));
	}
}

link_pro::~link_pro()
{

}

