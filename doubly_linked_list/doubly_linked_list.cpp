﻿#include <fstream>
#include <string> 
#include "doubly_linked_list.inl"
//#include <iostream>


int print_list_score(DoublyLinkedList<Score>& list) { //リストの要素を先頭から順に全て標準出力する

    DoublyLinkedList<Score>::Iterator it;

    for (it = list.begin(); it != list.end(); ++it) {
        printf("%d %s\n", (*it).score, (*it).userName.c_str());
    }
    return 0;
}


int main()
{
    /*
    DoublyLinkedList<Score> scoreList;

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

        scoreList.insert(Score(score, userName));
    }

    print_list_score(scoreList);

    // scoreで昇順
    scoreList.sort(0, 0);
    */

    
    // int型リストの動作確認
    DoublyLinkedList<int> intList;
    intList.insert(4);
    intList.insert(1);
    intList.insert(6);
    intList.insert(4);
    intList.insert(9);
    intList.insert(3);

    DoublyLinkedList<int>::Iterator iit;
    for (iit = intList.begin(); iit != intList.end(); ++iit) {
        printf("%d\n", (*iit));
    }

    //intList.sort(0,0);

    DoublyLinkedList<int>::Iterator it0, it1;
    it0 = intList.begin();
    it1 = intList.end();

    std::cout << (it0 < it1) << std::endl;
    std::cout << (it0 > it1) << std::endl;


    /*
    // string型リストの動作確認
    DoublyLinkedList <std::string> stringList;
    DoublyLinkedList<std::string>::Iterator sit;
    for (int i = 0; i < 10; i++) {
        stringList.insert("hello");
    }
    for (sit = stringList.begin(); sit != stringList.end(); ++sit) {
        std::cout << *sit << std::endl;
    }
    */

    return 0;
}
