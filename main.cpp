// g++ compiler

#include <iostream>
#include <future>
#include <syncstream>
#include <thread>
#include <chrono>

using namespace std;

void slow (const string & name)
{
    this_thread::sleep_for(chrono::seconds(7));
    osyncstream(cout) << name << endl;
}

void quick (const string & name)
{
    this_thread::sleep_for(chrono::seconds(1));
    osyncstream(cout) << name << endl;
}

void work ()
{
    auto time1 = chrono::system_clock::now();

    auto f1 = async(launch::async, slow, "A2");
    quick("A1");
    quick("C1");
    quick("C2");
    quick("D2");
    f1.wait();
    slow("B");
    quick("D1");

    auto time2 = chrono::system_clock::now();
    auto tdiff = chrono::duration_cast <chrono::seconds> (time2 - time1);
    osyncstream(cout) << "Execution time: " << tdiff <<  "\nWork is done!";
}

int main()
{
    work();
    return 0;
}
