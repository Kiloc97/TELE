#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include "telepix.h"

using namespace std;
namespace fs = std::filesystem;

void print_hwmon_info() {
    const string hwmon_path = "/sys/class/hwmon";
    vector<fs::path> hwmons;

    // hwmon 디렉토리 탐색
    for (const auto& entry : fs::directory_iterator(hwmon_path)) {
        if (entry.is_directory()) {
            hwmons.push_back(entry.path());
        }
    }
    cout << "hwmon 디바이스 개수: " << hwmons.size() << endl;

    // 각 hwmon 디바이스별 온도 센서 탐색
    for (const auto& hwmon : hwmons) {
        // 이름 출력 (name 파일이 있을 경우)
        string name = "(이름 없음)";
        ifstream name_file(hwmon / "name");
        if (name_file) getline(name_file, name);
        cout << "디바이스: " << name << endl;

        // 온도 센서 파일 탐색 (temp*_input)
        bool found_temp = false;
        for (const auto& file : fs::directory_iterator(hwmon)) {
            string fname = file.path().filename();
            if (fname.find("temp") == 0 && fname.find("_input") != string::npos) {
                ifstream temp_file(file.path());
                int temp_millic;
                if (temp_file >> temp_millic) {
                    cout << "  현재 온도: " << temp_millic / 1000.0 << " °C" << endl;
                    found_temp = true;
                }
            }
        }
        if (!found_temp) {
            cout << "  온도 센서 없음" << endl;
        }
    }
}