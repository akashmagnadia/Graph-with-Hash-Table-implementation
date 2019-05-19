#include <iostream>
#include "Graph.h"


int main(int argc, char* argv[]) {
	graph g;
	std::vector<graph::vertex_label> bfs_rpt;
	std::vector<graph::vertex_label> dfs_rpt;

	std::vector<graph::vertex_label> dag_critical_paths;
	std::vector<graph::vertex_label> dag_num_paths;

	/*if (argc != 3) {
		std::cout << "usage:  ./bfs <filename> <source-vertex>\n";
		return 0;
	}
	else {
		if (!g.read_file(argv[1])) {
			std::cout << "could not open file '" << argv[1] << "'\n";
			return 0;
		}
	}*/

	string fileName = "input2.txt";
	if (!g.read_file(fileName))
		std::cout << "could not open file '" << fileName << "'\n";

	std::cout << "\nADJACENCY-LIST REPRESENTATION:\n\n";
	g.display();
	std::cout << "\nEND ADJACENCY LIST:\n\n";

	std::string source = "a"; //source verrtex it starts bfs 
	if (!g.bfs(source, bfs_rpt)) {
		std::cout << "bfs failed -- bad source vertex name '" <<
			source << "'\n";
		return 0;
	}
	else {
		std::cout << "\nBFS REPORT:\n\n";
		g.disp_report(bfs_rpt, true);
		std::cout << "\nEND BFS REPORT\n\n";
	}

	g.dag_critical_paths(dag_critical_paths);

	std::cout << "Printing dag_ciritcal_paths predcessors and max dist" << std::endl;
	g.disp_report(dag_critical_paths, false);
	std::cout << "End of dag_critical_paths" << std::endl << std::endl;


	g.dag_num_paths(dag_num_paths);
	std::cout << "Printing dag_num_paths predcessors and max dist" << std::endl;
	g.disp_report(dag_num_paths, false);
	std::cout << "End of dag_num_paths" << std::endl << std::endl;

	std::vector<int> extractedVector;
	g.extract_path(bfs_rpt, 9, extractedVector);
	if (g.valid_topo_order(extractedVector)) {
		std::cout << "Success" << std::endl;
	}
	else {
		std::cout << "No Success" << std::endl;
	}

	return 0;
}
