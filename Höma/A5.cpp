#include "A5.hpp"

void print(std::vector<int> vec){
    std::cout << "(";
    for(int i=0; i<vec.size(); i++){
        std::cout << vec[i];
        if(i<vec.size()-1) std::cout << "|";
    }
    std::cout << ")" << std::endl << std::endl;
}

void testFunctionality(){
    std::cout << "Test:" << std::endl << std::endl;
    CRandom rdm;
    std::vector<int> tmp;
    
    for(int i=0; i<20; i++){
        std::cout << "Lauf " << i+1 << " Festes n (=10)" <<std::endl;
        rdm.init(10);
        tmp = rdm.test(3, 7, 10000);
        print(tmp);
    }
    
    for(int i=0; i<20; i++){
        int n = rand()%100;
        std::cout << "Lauf " << i+1 << " Unterschiedliche n (=" << n << ")" <<std::endl;
        rdm.init(n);
        tmp = rdm.test(3, 7, 10000);
        print(tmp);
    }
    
    for(int i=0; i<20; i++){
        int n = time(NULL);
        std::cout << "Lauf " << i+1 << " n in Abhängigkeit von Zeit (=" << n << ")" <<std::endl;
        rdm.init(n);
        tmp = rdm.test(3, 7, 10000);
        print(tmp);
    }
    
    tmp = rdm.test_wrong(3, 7, 10000);
    print(tmp);
}

void monteCarlo(int N, int according, std::string cmpWith, CLotto lotto){
    double res = 0;
    int tmp = 0;
    if(cmpWith == "bill"){
        for(int i=0; i<N; i++){
            tmp = lotto.cmpWithBettingSlip();
            if(tmp == according) res++;
        }
        res /= N;
        res *= 100;
        std::cout << "Die Wahrscheinlichkeit, dass bei " << N << " Ziehungen" << std::endl << "genau " << according << " Zahlen mit dem Schein übereinstimmen liegt bei " << res << "%." << std::endl;
    }else{
        for(int i=0; i<N; i++){
            tmp = lotto.cmpTwoGames();
            if(tmp == according) res++;
        }
        res /= N;
        res *= 100;
        std::cout << "Die Wahrscheinlichkeit, dass bei " << N << " Durchläufen zwei Ziehungen hintereinander" << std::endl << "in genau " << according << " Zahlen übereinstimmen liegt bei " << res << "%." << std::endl;
    }
}
