#include <fstream>
#include <string> 
#include "doubly_linked_list.h"

int print_list(DoublyLinkedList& list) { //リストの要素を先頭から順に全て標準出力する

    DoublyLinkedList::Iterator it;

    for (it = list.getHead(); it != list.getEnd(); ++it) {
        printf("%d %s\n", (*it).score, (*it).userName.c_str());
    }
    return 0;
}

int main()
{
    DoublyLinkedList l;
    
    //テキストファイルのファイル名
    //Scores.txtはプロジェクトフォルダ内に同封している
    const char* fileName = "Scores.txt";

    std::ifstream ifs(fileName);
    if (!ifs)
    {
        std::string str = "ファイルが開けませんでした。";
        printf("%s", str.c_str());
        return 0;
    }

    while (true) { //ファイルの末尾まで一行ずつリストに挿入する

        std::string score;
        std::string userName;

        ifs >> score; //空白区切り
        std::getline(ifs, userName); //改行区切り

        // while(ifs.eof())では1回余分にループに入るので
        // 終了判定をinsertの直前に変更した
        if (ifs.eof()) {
            break;
        }

        l.insert(score, userName);
    }

    print_list(l);

    return 0;
}
