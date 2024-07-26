#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <chrono>

// const size_t DATA_SIZE = 100 * 1024 * 1024; // 100 MB

// void benchmark_pipe() {
//     int pipefd[2];
//     char *data = new char[DATA_SIZE];
//     memset(data, 1, DATA_SIZE);
//     pipe(pipefd);
//     auto start = std::chrono::high_resolution_clock::now();

//     if (fork() == 0) {
//         close(pipefd[0]);
//         std::cout << "write: " << write(pipefd[1], data, DATA_SIZE) << '\n';
//         close(pipefd[1]);
//         delete[] data;
//         exit(0);
//     } else {
//         close(pipefd[1]);
//         char *buffer = new char[DATA_SIZE];
//         std::cout << "read: " << read(pipefd[0], buffer, DATA_SIZE) << '\n';
//         close(pipefd[0]);
//         delete[] buffer;
//         wait(NULL);
//     }

//     auto end = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> duration = end - start;
//     std::cout << "Pipe time: " << duration.count() << " seconds" << std::endl;
// }

// void benchmark_socketpair() {
//     int sockfd[2];
//     socketpair(AF_UNIX, SOCK_STREAM, 0, sockfd);
//     char *data = new char[DATA_SIZE];
//     memset(data, 1, DATA_SIZE);
//     auto start = std::chrono::high_resolution_clock::now();

//     if (fork() == 0) {
//         close(sockfd[0]);
//         std::cout << "sock write: " << write(sockfd[1], data, DATA_SIZE) << '\n';
//         close(sockfd[1]);
//         delete[] data;
//         exit(0);
//     } else {
//         close(sockfd[1]);
//         char *buffer = new char[DATA_SIZE];
//         std::cout << "sock read: " << read(sockfd[0], buffer, DATA_SIZE) << '\n';
//         close(sockfd[0]);
//         delete[] buffer;
//         wait(NULL);
//     }

//     auto end = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> duration = end - start;
//     std::cout << "Socketpair time: " << duration.count() << " seconds" << std::endl;
// }

class   test_error1
{
public:
    test_error1(): tester("test") {
        std::cout << "callllllll\n";
    }
    test_error1(const char*  str){
        tester = str;
    }
    virtual ~test_error1()throw(){};
    virtual const char* what() const throw()
    {
        return  tester.c_str();
    }

private:
    std::string tester;
};

class   test_error2: private test_error1
{
public:
    test_error2(): tester("test") {}
    test_error2(const char*  str){
        tester = str;
    }
    ~test_error2()throw(){};
    const char* what() const throw()
    {
        return  tester.c_str();
    }

private:
    std::string tester;
};

int main() {
    // benchmark_pipe();
    // benchmark_socketpair();
    test_error2* tes2 = new test_error2;
    test_error1 &tes1 = tes2;
    // try
    // {
    //     throw test_error("test1");
    // }
    catch(const std::exception &e)
    // {
    //     std::cout << e.what() << '\n';
    // }
    
    return 0;
}