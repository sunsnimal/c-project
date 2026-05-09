#include "FileScanner.hpp"
#include <iostream>

FileScanner::FileScanner(std::string path) : rootPath_(std::move(path)) {}

void FileScanner::scan(){
    for(const auto& entry : fs::recursive_directory_iterator(rootPath_, 
                fs::directory_options::skip_permission_denied)){
        if(entry.is_regular_file()){
            filePaths_.push_back(entry.path());
        }
    }
}

const std::vector<fs::path>& FileScanner::getPaths() const {
    return filePaths_;
}


