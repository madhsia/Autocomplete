/* Name: Madeline Hsia
   Login: cs100wew */ 

#include "util.hpp"
#include "DictionaryBST.hpp"
#include "DictionaryHashtable.hpp"
#include "DictionaryTrie.hpp"
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {

    if(argc != 5){
        std::cout << "Incorrect number of arguments." << std::endl;
        std::cout << std::endl;
        exit(-1);
    }

    int min_size = atoi(argv[1]);
    int step_size = atoi(argv[2]);
    int iterations = atoi(argv[3]);

    std::ifstream in;
    in.open(argv[4],std::ios::binary);
    Timer T;

    cout << "DictionaryTrie" << endl;
    for (int i=0; i<iterations; i++) {
        int size = min_size + (i*step_size);
        DictionaryTrie *dictTrie = new DictionaryTrie();

        //bool result;
        long long duration =0;
        Utils::load_dict(*dictTrie,in,size);
        in.clear();
        in.seekg(0,std::ios::beg);

        T.begin_timer();
        dictTrie->find("rebeccawillyoumarryme");
        duration += T.end_timer();

        T.begin_timer();
        dictTrie->find("nosirjeffers");
        duration += T.end_timer();

        T.begin_timer();
        dictTrie->find("wabalabadubdub");
        duration += T.end_timer();

        T.begin_timer();
        dictTrie->find("iknowwhenthatyichardring");
        duration += T.end_timer();

        T.begin_timer();
        dictTrie->find("sharkysharksayssharkyshark");
        duration += T.end_timer();

        T.begin_timer();
        dictTrie->find("momsaidicouldhave");
        duration += T.end_timer();

        T.begin_timer();
        dictTrie->find("justonepeanutbuttersquare");
        duration += T.end_timer();

        T.begin_timer();
        dictTrie->find("butnotuntilaft");
        duration += T.end_timer();

        T.begin_timer();
        dictTrie->find("ertheycool");
        duration += T.end_timer();

        T.begin_timer();
        dictTrie->find("downnnnnnn");
        duration += T.end_timer();

        duration = duration/iterations;
        cout << size << "\t" << duration << endl;
        delete dictTrie;
    }

    cout << endl;
    cout << "DictionaryBST" << endl;
    for (int i=0; i<iterations; i++) {
        int size = min_size + (i*step_size);
        DictionaryBST *dictBST = new DictionaryBST();
        //bool result;
        long long duration =0;
        Utils::load_dict(*dictBST,in,size);
        in.clear();
        in.seekg(0,std::ios::beg);

        T.begin_timer();
        dictBST->find("rebeccawillyoumarryme");
        duration += T.end_timer();

        T.begin_timer();
        dictBST->find("nosirjeffers");
        duration += T.end_timer();

        T.begin_timer();
        dictBST->find("wabalabadubdub");
        duration += T.end_timer();

        T.begin_timer();
        dictBST->find("iknowwhenthatyichardring");
        duration += T.end_timer();
        duration = duration/iterations;

        T.begin_timer();
        dictBST->find("sharkysharksayssharkyshark");
        duration += T.end_timer();

        T.begin_timer();
        dictBST->find("momsaidicouldhave");
        duration += T.end_timer();

        T.begin_timer();
        dictBST->find("justonepeanutbuttersquare");
        duration += T.end_timer();

        T.begin_timer();
        dictBST->find("butnotuntilaft");
        duration += T.end_timer();

        T.begin_timer();
        dictBST->find("ertheycool");
        duration += T.end_timer();

        T.begin_timer();
        dictBST->find("downnnnnnn");
        duration += T.end_timer();

        cout << size << "\t" << duration << endl;
        delete dictBST;
    }

    cout << endl;
    cout << "DictionaryHashtable" << endl;
    for (int i=0; i<iterations; i++) {
        int size = min_size + (i*step_size);
        DictionaryHashtable *dictHash = new DictionaryHashtable();
        //bool result;
        long long duration =0;
        Utils::load_dict(*dictHash,in,size);
        in.clear();
        in.seekg(0,std::ios::beg);

        T.begin_timer();
        dictHash->find("rebeccawillyoumarryme");
        duration += T.end_timer();

        T.begin_timer();
        dictHash->find("nosirjeffers");
        duration += T.end_timer();

        T.begin_timer();
        dictHash->find("wabalabadubdub");
        duration += T.end_timer();

        T.begin_timer();
        dictHash->find("iknowwhenthatyichardring");
        duration += T.end_timer();
        duration = duration/iterations;

        T.begin_timer();
        dictHash->find("sharkysharksayssharkyshark");
        duration += T.end_timer();

        T.begin_timer();
        dictHash->find("momsaidicouldhave");
        duration += T.end_timer();

        T.begin_timer();
        dictHash->find("justonepeanutbuttersquare");
        duration += T.end_timer();

        T.begin_timer();
        dictHash->find("butnotuntilaft");
        duration += T.end_timer();

        T.begin_timer();
        dictHash->find("ertheycool");
        duration += T.end_timer();

        T.begin_timer();
        dictHash->find("downnnnnnn");
        duration += T.end_timer();

        cout << size << "\t" << duration << endl;
        delete dictHash;
    }

return 0;
}