/*
 * @Author: Chacha
 * @Date: 2022-03-03 13:51:04
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-03 18:55:10
 */

/**
 * 来源：https://www.runoob.com/cplusplus/cpp-multithreading.html
 *
 * C++ 多线程
 * 多线程是多任务处理的一种特殊形式，多任务处理允许让电脑同时运行两个或两个以上的程序。一般情况下，两种类型的多任务处理：基于进程和基于线程。
 * 1. 基于进程的多任务处理是程序的并发执行
 * 2. 基于线程的多任务处理是同一个程序片段的并发执行
 *
 * 多线程程序包含可以同时运行的两个或多个部分。这演的程序中每个部分称为一个线程，每个线程定义了一个单独执行路径。
 * 我们要使用 POSIX 编写多线程 C++ 程序。POSIX Threads 或 Pthreads 提供的 API 可在多种类 Unix POSIX 系统上可用，
 * 比如 FreeBSD、NetBSD、GNU/Linux、Mac OS X 和 Solaris。
 *
 * 创建线程
 * 下面的程序，我们可以用它来创建一个POSIX线程:
 * #include <pthread.h>
 * pthread_create (thread, attr, start_routine, arg)
 *
 * 在这里，pthread_create 创建一个新的线程，并让它可执行。下面是关于参数的说明：
 * 1. thread: 指向线程标志符指针。
 * 2. attr: 一个不透明的属性对象，可以被用来设置线程属性。您可以指定线程属性对象，也可以使用默认值 NULL。
 * 3. start_routine: 线程运行函数起始地址，一旦线程被创建就会执行。
 * 4. arg: 运行函数的参数。
 *
 * 创建线程成功时，函数返回 0，若返回值不为 0 则说明创建线程失败。
 *
 * 终止线程
 * 使用下面的程序，我们可以用它来终止一个 POSIX 线程：
 * #include <pthread.h>
 * pthread_exit (status)
 *
 * 在这里，pthread_exit 用于显式地退出一个线程。通常情况下，pthread_exit() 函数是在线程完成工作后无需继续存在时被调用。
 * 如果 main() 是在它所创建的线程之前结束，并通过 pthread_exit() 退出，那么其他线程将继续执行。否则，它们将在 main() 结束时自动被终止。
 *
 * 连接和分离线程
 * 我们可以使用以下两个函数来连接或分离线程：
 * pthread_join (threadid, status)
 * pthread_detach (threadid)
 *
 * pthread_join() 子程序阻碍调用程序，直到指定的 threadid 线程终止为止。直到指定的 threadid线程终止为止。当创建一个线程时，
 * 它的某个属性会定义它是否可以连接的（joinable）或者 可分离的（detached）。只有创建时定义为可连接的线程才可以被连接。如果
 * 线程创建时被定义为可分离，则它永远也不能被连接。
 *
 * std::thread
 * C++ 11 之后添加了新的标准线程库 std::thread，std::thread 在 <thread> 头文件中声明，因此使用 std::thread 时需要包含 在 <thread> 头文件。
 * std::thread 默认构造函数，创建一个空的 std::thread 执行对象。
 * #include<thread>
 * std::thread thread_object(callable)
 *
 *
 *
 */

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

struct thread_data
{
    int thread_id;
    char *message;
};

void *wait(void *t)
{
    int i;
    long tid;

    tid = (long)t;

    sleep(1);

    cout << "Sleeping in thread " << endl;
    cout << "Thread with id: " << tid << " ...exiting" << endl;

    pthread_exit(NULL);
};

void *sayHello(void *args)
{
    struct thread_data *data;

    data = (struct thread_data *)args;

    cout << "Thread ID: " << data->thread_id << endl;
    cout << "Message: " << data->message << endl;

    return 0;
};

int main(int argc, char const *argv[])
{
    pthread_t threads[NUM_THREADS];
    pthread_t threads1[NUM_THREADS];
    pthread_attr_t attr;
    struct thread_data td[NUM_THREADS];
    void *status;

    // 初始化并设置线程为可连接的（joinable）
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // for (int i = 0; i < NUM_THREADS; i++)
    // {
    //     cout << "创建线程, " << i << endl;

    //     td[i].thread_id = i;
    //     td[i].message = (char *)"This is Message";

    //     // 参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
    //     int ret = pthread_create(&threads[i], NULL, sayHello, (void *)&((td[i])));

    //     if (ret != 0)
    //     {
    //         cout << "pthread_create error: error_code=" << ret << endl;
    //         exit(-1);
    //     }
    // }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        cout << "创建线程, " << i << endl;

        // 参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
        int ret = pthread_create(&threads1[i], NULL, wait, (void *)&i);

        if (ret != 0)
        {
            cout << "pthread_create error: error_code=" << ret << endl;
            exit(-1);
        }
    }

    int rc;

    // 删除属性，并等待其他线程
    pthread_attr_destroy(&attr);

    for (int i = 0; i < NUM_THREADS; i++)
    {
        rc = pthread_join(threads1[i], &status);

        if (rc)
        {
            cout << "Error:unable to join," << rc << endl;
            exit(-1);
        }

        cout << "Main: completed thread id: " << i;
        cout << " exiting with status: " << status << endl;
    }

    cout << "Main: program exiting." << endl;

    // 等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来
    pthread_exit(NULL);

    return 0;
}
