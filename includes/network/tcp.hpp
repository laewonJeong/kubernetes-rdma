#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include "map"
#define number_of_sock 100

using namespace std;
class TCP{
    public:
        void server(string server[]);
        void connect_tcp(const char* ip, string server[], int number_of_server, int Port);
        void client(string ip, int idx);
        void client_t(const char* ip, string server[]);
        void send_msg(const char* m,int ip);
        int recv_msg(int ip);
        string recv_message(int ip);
        int *client_sock();
        string domain_to_ip(string domain);
        map<string, string> read_rdma_info(int ip);
        string check_my_ip();

    private:
        int num_of_server;
        int sock;
        struct sockaddr_in serv_addr;
        struct sockaddr_in serv_adr, clnt_adr;
        int serv_sock, clnt_sock; 
        int clnt_adr_size;
        std::vector<std::thread> workers;
        char buffer[1048676] = {0};
        int valread;
        string result;
        string read_char;
        int clnt_cnt=0;
        int new_sock[number_of_sock];
        int clnt_socks[number_of_sock];
        int Port;
};