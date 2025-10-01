#include <iostream>
#include <sys/utsname.h>
#include "telepix.h"

using namespace std;

void unameload() {
    struct utsname buf;
    if (uname(&buf) != 0) {
        cerr << "uname() failed" << endl;
        exit(1);
    }
    cout << "커널 버전: " << buf.release << endl;
}