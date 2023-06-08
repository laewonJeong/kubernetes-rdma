#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <thread>
#include <stdlib.h>
#include <math.h>
#include <unordered_map>

#define df 0.85
#define buf_size1 1048676*30

using namespace std;
class Pagerank{
    public:
       void create_graph_data(string path, string del);
       void initial_pagerank_value();
       static void calc_pagerank_value(int start, int end, double x, double y);
       void run_pagerank(int iter);
       void gather_pagerank(string opcode);
       void scatter_pagerank();
       string max_pr();
       void init_connection(const char* ip, string server[], 
                            int number_of_server, int Port, int num_of_vertex);
       void print_pr();
       int get_num_of_vertex(); 
    private:
        vector<vector<size_t>> graph;
        vector<vector<size_t>> outgoing;
        string my_ip;
        int num_of_vertex;
        int num_of_server;
        string *node;
        string server_ip;
        int start1;
        int end1;
        double diff;
        vector<int> num_outgoing;
        bool add_arc(size_t from, size_t to);
        template <class Vector, class T> bool insert_into_vector(Vector& v,
                                                             const T& t);
};