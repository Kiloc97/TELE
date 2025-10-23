#include <iostream>
#include <sys/sysinfo.h>
#include "tele.h"

using namespace std;

void print_uptime() {
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        cerr << "sysinfo() failed" << endl;
        exit(1);
    }
    cout << "시스템 가동 시간: " << info.uptime << " 초" << endl;
}