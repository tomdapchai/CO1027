#include "knight.h"
#define MAX_LEVEL = 10
#define MAX_ITEM = 99
#define MADBEAR = 1
#define BANDIT = 1.5
#define LORDLUPIN = 4.5
#define ELF = 7.5
#define TROLL = 9.5
int line[3][100];
void nhap(){
    string lines;
    int i = 0;
    ifstream input("tc1_input");
    if (input.is_open()){
    string num_lines;
    getline(input, num_lines);
    for (int i = 0; getline(input, lines); ++i)
    {
        std::istringstream is(lines);
        string number;
        for (int j = 0; is >> number; ++j)
            line[i][j] = number;
    }
    }
}
bool primeCheck(int a){
    if (a <= 1) return false;
    if (a == 2 || a == 3) return true;
    for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
    else return true;
}
int fibo(int n) {
    int a[1000];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}
int levelO(int i, int b) {
    int level = i > 6?(b > 5?b : 5) : b;
    return level;
}
int levelCheck (int level) {
    if (level > MAX_LEVEL) return MAX_LEVEL;
}
int itemCheck (int item) {
    if(item > MAX_ITEM) return MAX_ITEM;
}
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {

}
