#include "FileScanner.hpp"
#include <iostream>

int main(){
    FileScanner scanner(".");

    scanner.scan();

    std::cout << "扫描成功，当前文件夹的文件数：" << scanner.getPaths().size() << std::endl;

    return 0;
}
