#include <iostream>
#include <filesystem>

auto recursiveGetFileNamesByExtension = [](const std::filesystem::path p, const std::string myExtension) {
    for (auto& c : std::filesystem::recursive_directory_iterator(p)) {
        if (c.path().extension() == myExtension)
            std::cout << c.path() << '\n';
    }
};

int main() {
    std::string myExtension = ".exe";
    std::filesystem::path p = "C:\\skillbox";
    std::cout << p << std::endl;
    for (auto& c : std::filesystem::recursive_directory_iterator(p)) {
        if (c.path().extension() == myExtension)
            std::cout << c.path() << '\n';
    }
    recursiveGetFileNamesByExtension(p, myExtension);
}
