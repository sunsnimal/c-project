#pragma once
#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class FileScanner{
public:
    explicit FileScanner(std::string path);
    void scan();
    const std::vector<fs::path>& getPaths() const;
private:
    std::string rootPath_;
    std::vector<fs::path> filePaths_;
};
