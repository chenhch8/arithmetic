#include<iostream>
#include<fstream>
#include<vector>

int main() {
    std::ofstream out("Number.txt");
    std::vector<int> ve;
    int n;
    while (std::cin >> n) ve.push_back(n);
    for (unsigned i = 0; i < ve.size(); i++) {
        out << ve[i];
        if ((i + 1) % 4)
            out << " ";
        else out << "\n";
    }
    return 0;
}