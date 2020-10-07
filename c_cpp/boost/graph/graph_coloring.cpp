#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/sequential_vertex_coloring.hpp>

// Original post:
// https://www.boost.org/doc/libs/1_67_0/libs/graph/doc/sequential_vertex_coloring.html

using namespace boost;
using namespace std;

typedef adjacency_list<listS, vecS, undirectedS> Graph;
typedef property_map<Graph, vertex_index_t>::const_type vertex_index_map;

typedef std::pair<int, int> Edge;
enum nodes {A, B, C, D, E, n};
  
int main () {
    Edge edge_array[] = { Edge(A, C), Edge(B, B), Edge(B, D), Edge(B, E), 
                        Edge(C, B), Edge(C, D), Edge(D, E), Edge(E, A), 
                        Edge(E, B) };
    int m = sizeof(edge_array) / sizeof(Edge);
    Graph g(edge_array, edge_array + m, n);

    // Create a color vector
    std::vector<int> color_vec(num_vertices(g));

    // Create a color map
    iterator_property_map<int*, vertex_index_map>
        color(&color_vec.front(), get(vertex_index, g));

    int num_colors = sequential_vertex_coloring(g, color);
    cout << "# of colors " << num_colors << endl;
    
    // Get color from color map
    auto vpair = vertices(g);
    for(auto iter=vpair.first; iter!=vpair.second; iter++) {
        cout << "vertex " << *iter << " color " << color[*iter] << endl;
    }
}  
  