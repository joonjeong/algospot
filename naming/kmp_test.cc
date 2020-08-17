#include <iostream>
#include <string>
#include <vector>

std::vector<int> getPartialMatch(const std::string& N);
std::vector<int> kmp(const std::string& H, const std::string& N);

int main(int argc, char* argv[]) {
    std::cout << "args" << std::endl;
    for(int argi = 0; argi < argc; ++argi) {
        std::cout << " - " << argv[argi] << std::endl;
    }

    std::string mode(argv[1]);
    if(mode == "partial") {
        std::string N(argv[2]);
        std::vector<int> result = getPartialMatch(N);
        for(int v : result) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    } else if(mode == "kmp") {
        std::string H(argv[2]);
        std::string N(argv[3]);

        std::vector<int> result = kmp(H, N);
        for(int v : result) {
            std::cout << v << " ";
        }
        std::cout << std::endl;

    }

    return 0;
}