#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

std::string cleanWord(std::string word);

int main(int argc, char* argv[]) {
    if(argc < 2){
        std::cout << "请输入文件名" << std::endl;
    }
    std::string filename = argv[1];
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cerr << "错误：无法打开文件'" << filename << "'!" << std::endl;
        return 1;
    }
    std::string word;
    std::unordered_map<std::string, int> wordCount;

    while (file >> word){
        std::string cleaned = cleanWord(word);
        if(!cleaned.empty()){
            wordCount[cleaned]++;
        }
    }

    std::cout << "单词计数统计结果：" << std::endl;
    for(const auto& pair: wordCount){
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    file.close();
    return 0;
}

std::string cleanWord(std::string word){
    //转小写
    std::transform(word.begin(), word.end(), word.begin(), 
            [](unsigned char c) {return std::tolower(c);});

    //剔除标点符号
    word.erase(std::remove_if(word.begin(), word.end(), 
                [](unsigned char c) {return std::ispunct(c);}),
            word.end());

    //过滤纯数字
    if (word.empty() || std::all_of(word.begin(), word.end(), ::isdigit)) {
        return "";
    }

    return word;
}
