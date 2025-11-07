#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

class keyboards {
private:
    string IMEI;
public:
    string name;
    string condition;
    string color;
    string model;

    string get_IMEI() {
        return IMEI;
    }
    void set_IMEI() {
        cin >> IMEI;
    }
};

void print_vector(vector<string> data) {
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << "\t";
    }
    cout << endl;
}

int main() {
    ifstream file("KeyboardData.txt");

    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    print_vector(lines);

    keyboards member;
    char d;
    do {
        cout << "Name: "; cin >> member.name;
        cout << "Condition: "; cin >> member.condition;
        cout << "Color "; cin >> member.color;
        cout << "Model: "; cin >> member.model;
        cout << "IMEI: "; member.set_IMEI();
        cout << "Continue? Y/N "; cin >> d;

        lines.push_back(member.name);
        lines.push_back(member.condition);
        lines.push_back(member.color);
        lines.push_back(member.model);

        ofstream file("KeyboardData.txt", ios::app);
        file << member.name << "\t";
        file << member.condition << "\t";
        file << member.color << "\t";
        file << member.model << "\t";

    } while (d == 'y' || d == 'Y');


    return 0;
}
