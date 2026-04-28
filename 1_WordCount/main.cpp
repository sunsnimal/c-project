#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <vector>

std::string cleanWord(std::string word);

int main(int argc, char* argv[]) {
    if(argc < 2){
        std::cout << "用法：" << argv[0] << " <文件名> [TopN数量] [导出文件名.csv]" <<std::endl;
        return 1;
    }
    std::string filename = argv[1];
    int topN = (argc >= 3) ? std::stoi(argv[2]) : 0; // 0表示默认输出所有
    std::string exportFile = (argc >= 4) ? argv[3] : "";
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

    file.close();
    std::vector<std::pair<std::string, int>> sortedWords(wordCount.begin(), wordCount.end());
    std::sort(sortedWords.begin(), sortedWords.end(), [](const auto& a, const auto& b){
        return a.second > b.second;
            }); //降序
    
    size_t limit = (topN > 0 && topN < sortedWords.size()) ? topN : sortedWords.size();
    
    if(! exportFile.empty()){
        std::ofstream outFile(exportFile);
        outFile << "Word,Frequency\n";
        for(size_t i = 0; i < limit; ++i) {
            outFile << sortedWords[i].first << "," << sortedWords[i].second << "\n";
        }
        std::cout << "结果已导出至：" << exportFile << std::endl;
    } else {
        std::cout << "--- 单词计数统计结果（Top" << limit << "）---" << std::endl;
        std::cout << "排名\t单词\t\t次数" << std::endl;
        for(size_t i = 0; i < limit; ++i){
            std::cout << i + 1 << "\t" << sortedWords[i].first << "\t\t"<< sortedWords[i].second << std::endl;
        }
    }
    
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
