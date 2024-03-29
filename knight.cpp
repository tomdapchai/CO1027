#include "knight.h"
string* file = new string [3];
int* mush = new int [100];
string* merlin = new string [100];
int alce[100][100];
int maxi, mini, mtx, mti, maxi2, mini2, max2_3x, max2_3i, pos, mushSize;
int n9;
int r1, c1;
bool primeCheck(int a){
    if (a <= 1) return false;
    if (a == 2 || a == 3) return true;
    for (int i = 2; i <= a / 2; i++)
        if (a % i == 0) return false;
    return true;
}
int fibo(int n) {
    int a[1000];
    if (n == 0) return 1;
    if (n == 1) return 1;
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
        a[i] = a[i - 1] + a[i - 2];
    return a[n];
}
int levelO(int x) {
    int b = x % 10;
    int a = x > 6?(b > 5?b : 5) : b;
    return a;
}
int levelCheck (int &level) {
    if (level > 10) return 10;
    else return level;
}
int itemCheck (int &item) {
    if(item > 99) return 99;
    else return item;
}
int HPCheck (int HP, int maxHP) {
    if (HP > maxHP) return maxHP;
    else return HP;
}
bool checkArthur(int HP){
    if (HP == 999) return true;
    else return false;
}
bool checkLancelot(int HP){
    if (primeCheck(HP)) return true;
    else return false;
}
bool remedyCheck(int remedy) {
    if (remedy > 0) return true;
    else return false;
}
bool maidenCheck(int maidenkiss) {
    if (maidenkiss > 0) return true;
    else return false;
}
bool phoenixCheck(int phoenixdown){
    if (phoenixdown > 0) return true;
    else return false;
}
bool deadCheck(int HP, int phoenixdown){
    if (HP <= 0 && !phoenixCheck(phoenixdown)) return true;
    else return false;
}
bool winCheck (int level, int x) {
    if (level > levelO(x)) return true;
    else return false;
}
bool tieCheck (int level, int x) {
    if (level == levelO(x)) return true;
    else return false;
}
bool downsideCheck (int *arr, int n) {
    int k = 0;
    while ((arr[k] > arr[k + 1]) && (k < n - 1)) k++;
    if (k == n - 1) return true;
    else return false;
}
bool upsideCheck (int *arr, int n) {
    int k = 0;
    while ((arr[k] < arr[k + 1]) && (k < n - 1)) k++;
    if (k == n - 1) return true;
    else return false;
}
bool mountainCheck(int *arr, int n, int &pos) {
    int k = 0;
    while ((arr[k] < arr[k + 1]) && (k < n - 1)) k++;
    pos = k;
    while ((arr[k]) > arr[k + 1] && (k < n - 1)) k++;
    if (downsideCheck(arr, n) || upsideCheck(arr, n)) {
        return true;
    }
    else if (k == n - 1) return true;
    else return false;
}
int rescueStatus(int i, int eventCount, int HP, int phoenixdown) {
    if (deadCheck(HP, phoenixdown)) return 0;
    else if (i == eventCount) return 1;
    else if (i < eventCount) return -1;
}
void cursed(int &tiny, int &frog) {
    if (tiny > 0) tiny --;
    if (frog > 0) frog --;
}
void cursedCheck(int &tiny, int &frog, int &HP, int &level, int &tempLV, int &tempHP) {
    if (tiny == 0) {
        tiny = -1;
        HP *= 5;
        HP = HPCheck(HP, tempHP);
        tempHP = 0;
    }
    if (frog == 0) {
        frog = -1;
        level = tempLV;
        tempLV = 0;
    }
}
int nearestPrime(int n) {
    if (primeCheck(n)) n++;
    while (!primeCheck(n)) n++;
    return n;
}
int nearestFibo(int n) {
    if (n == 1) return 1;
    int delta0 = abs(n - fibo(0));
    int delta1 = 0;
    int i = 1;
    while (delta1 < delta0) {
        delta0 = abs(n - fibo(i));
        delta1 = abs(n - fibo(i + 1));
        i++;
    }
    if (fibo(i - 1) > n && fibo(i - 2) != n) return fibo(i - 2);
    else if (fibo(i - 1) == n) return fibo(i - 2);
    else return fibo(i - 1);
}
void mushType1(int* arr, int arraySize ,int &mini, int &maxi, int &HP, int maxHP) {
    int maxN = arr[0];
    int minN = arr[0];
    for (int j = 0; j < arraySize; j++)
    {
        if (arr[j] >= maxN) {
            maxi = j;
            maxN = arr[j];
        }
        if (minN >= arr[j]) {
            mini = j;
            minN = arr[j];
        }
    }
    HP = HP - (maxi + mini);
    HP = HPCheck(HP, maxHP);
}
void mushType2(int* arr, int arraySize ,int &mtx, int &mti, int &HP, int maxHP) {
    if (!mountainCheck(arr, arraySize, pos)) {
        mtx = -2;
        mti = -3;
    }
    else {
        if (downsideCheck(arr, arraySize)) {
            mtx = arr[0];
            mti = 0;
        }
        else if (upsideCheck(arr, arraySize)) {
            mtx = arr[arraySize - 1];
            mti = arraySize - 1;
        }
        else {
            mtx = arr[pos];
            mti = pos;
        }
    }
    HP = HP - (mtx + mti);
    HP = HPCheck(HP, maxHP);
}
void mushType3(int* arr1, int arraySize, int &maxi2,int &mini2, int &HP, int maxHP) {
    int *arr = new int [100];
    for (int k = 0; k <= arraySize; k++)
    arr[k] = arr1[k];
    for (int k = 0; k <= arraySize; k ++) {
        if (arr[k] < 0) arr[k] = - arr[k];
        arr[k] = (17 * arr[k] + 9) % 257;
    }
    int maxN = arr[0];
    int minN = arr[0];
    for (int j = 0; j < arraySize; j++)
    {
        if (arr[j] >= maxN) {
            maxN = arr[j];
        }
        if (arr[j] <= minN) {
            minN = arr[j];
        }
    }
    maxi2 = 0;
    mini2 = 0;
    while (maxN != arr[maxi2]) maxi2 ++;
    while (minN != arr[mini2]) mini2 ++;
    HP = HP - (maxi2 + mini2);
    HP = HPCheck(HP, maxHP);
}
void mushType4(int* arr1, int arraySize, int &max2_3x, int &max2_3i, int &HP, int maxHP) {
    int *arr = new int [100];
    for (int k = 0; k <= arraySize; k++)
    arr[k] = arr1[k];
    for (int k = 0; k <= arraySize; k ++) {
        if (arr[k] < 0) arr[k] = - arr[k];
        arr[k] = (17 * arr[k] + 9) % 257;
    }
    if (arr[0] == arr[1] && arr[1] == arr[2]) {
        max2_3x = -5;
        max2_3i = -7;
    }
    else {
    int maxN = arr[0];
    int minN = arr[0];
    for (int j = 0; j <= 2; j++)
    {
        if (arr[j] >= maxN) {
            maxN = arr[j];
        }
        if (arr[j] <= minN) {
            minN = arr[j];
        }
    }
    int h = 0;
    max2_3i = 0;
    for (int j = 0; j <= 2; j++) {
        if (arr[j] > minN && arr[j] < maxN) {
            h++;
            max2_3i = j;
            max2_3x = arr[j];
        }
    }
    if (h == 0) {
        max2_3x = minN;
        while(max2_3x != arr[max2_3i]) max2_3i ++;
    }
    }
    HP = HP - (max2_3x + max2_3i);
    HP = HPCheck(HP, maxHP);
}
void readMush(string mushFile, int* mush, int &mushSize) {
    int data;
    ifstream f;
    f.open(mushFile);
    f >> data;
    mushSize = data;
    f.close();
    ifstream f1;
    f1.open(mushFile);
    string strSequence;
    getline(f1, strSequence);
    getline(f1, strSequence);
    f1.close();
    string *temp = new string [1000];
    int h = 0;
    for (int j = 0; j < mushSize; j++) {
        while (strSequence[h] != ',' && h < strSequence.length()) {
            temp[j] += strSequence[h];
            h++;
        }
        h++;
    }
    for (int j = 0; j < mushSize; j++) 
        mush[j] = stoi(temp[j]);
}
bool enhanced(string str) {
    int m = 0, e = 0, r = 0, l = 0, i = 0, n = 0;
    for (int h = 0; h < str.length(); h++) {
        switch (str[h]) {
        case 'm': case 'M':
            m++;
            break;
        case 'e': case 'E':
            e++;
            break;
        case 'r': case 'R':
            r++;
            break;
        case 'l': case 'L':
            l++;
            break;
        case 'i': case 'I':
            i++;
            break;
        case 'n': case 'N':
            n++;
            break;
        default:
            break;
        }
    }
    if (m && e && r && l && i && n) return true;
    else return false;
}
bool enhancedPro(string str) {
    int k = 0;
    for (int o = 0; o < str.length() - 5; o++) {
        if (
            (str[o] == 'm' || str[o] == 'M') &&
            (str[o + 1] == 'e') &&
            (str[o + 2] == 'r') &&
            (str[o + 3] == 'l') &&
            (str[o + 4] == 'i') &&
            (str[o + 5] == 'n')
        ) k++;
    }
    if (k) return true;
    else return false;
}
void merlinBless(string *merlin, int n9, int &HP) {
    for (int j = 0; j < n9; j++) {
        if (enhanced(merlin[j])) {
            if (enhancedPro(merlin[j])) HP += 3;
            else HP +=2;
        }
    }
}
void readMerlin(string merlinFile, string* merlin, int &n9) {
    ifstream f;
    f.open(merlinFile);
    f >> n9;
    string line;
    getline(f, line);
    for (int i = 0; i < n9; i++) {
        getline(f, line);
        merlin[i] = line;
    }
    f.close();
}
void acleBless(int alce[][100], int r1, int c1, int &remedy, int &maidenkiss, int &phoenixdown) {
    if (c1 > 3) {
        for (int j = 0; j < r1; j++) {
            int n = 0;
            for (int k = 0; k < c1; k++) {
                if (n >= 3) break;
                if (alce[j][k] == 16) {
                    n++;
                    remedy++;
                }
                if (alce[j][k] == 17) {
                    n++;
                    maidenkiss++;
                }
                if (alce[j][k] == 18) {
                    n++;
                    phoenixdown++;
                }
            }
        }
    }
    else {
        for (int j = 0; j < r1; j ++) {
            for (int k = 0; k < c1; k++) {
                switch (alce[j][k]) {
                    case 16:
                        remedy++;
                        break;
                    case 17:
                        maidenkiss++;
                        break;
                    case 18:
                        phoenixdown++;
                        break;
                    default:
                        break;
                }
            }
        }
    }
    remedy = itemCheck(remedy);
    maidenkiss = itemCheck(maidenkiss);
    phoenixdown = itemCheck(phoenixdown);
}
void readAcle(string alceFile, int alce[][100], int &r1, int &c1) {
    int *data = new int[100];
    ifstream f;
    f.open(alceFile);
    int x;
    int i = 0;
    while (f >> x){
        data[i] = x;
        i++;
    }
    r1 = data[0]; c1 = data[1];
    int *tempdata = new int [100];
    for (int j = 0; j < r1 * c1; j++)
    tempdata[j] = data[j + 2];
    int count = 0;
    for (int j = 0; j < r1; j++){
        for (int k = 0; k < c1; k++) {
            alce[j][k] = tempdata[count];
            count++;
        }
    }
    f.close();
}
void readFile(string file_input, string *file, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, string* event, int &eventCount, string &mushFile, string &merlinFile, string &alceFile) {
    int* data = new int[100];
    string *data1 = new string[100];
    string line;
    ifstream f;
    f.open(file_input);
    string x;
    int i = 0;
    while (f >> x) {
        data1[i] = x;
        i++;
    }
    line = data1[i - 1];
    for (int j = 0; j < 5; j ++) {
        int t = 0;
        t = stoi(data1[j]);
        data[j] = t;
    }
    eventCount = i - 6;
    HP = data[0]; level = data[1]; remedy = data[2]; maidenkiss = data[3]; phoenixdown = data[4];
    for (int n = 1; n <= eventCount; n++)
        event[n] = data1[n + 4];
    int m = 0;
    for (int n = 0; n < 3; n ++) {
        while (line[m] != ',' && m < line.length()) {
            file[n] += line[m];
            m++;
        }
        m++;
    }
    f.close();
    mushFile = file[0]; merlinFile = file[2]; alceFile = file[1];
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
    string mushFile, merlinFile, alceFile;
    int eventCount = 0;
    string* event = new string [100];
    readFile(file_input, file, HP, level, remedy, maidenkiss, phoenixdown, event, eventCount, mushFile, merlinFile, alceFile);
    int tempHP = 0;
    int tempLV = 0;
    int tiny = -1;
    int frog = -1;
    int maxHP = HP;
    int event18 = 0;
    int event19 = 0; // only meet once
    for (int i = 1; i <= eventCount; i++) {
        if (event18 && event[i] == "18") {
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
        }
        if (event19 && event[i] == "19") {
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
        }
        if (tiny > 0 && (event[i] == "6" || event[i] == "7")) {
            tiny --;
                rescue = rescueStatus(i, eventCount, HP, phoenixdown);
                cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
        }
        if (frog > 0 && (event[i] == "6" || event[i] == "7")) {
            frog --;
                rescue = rescueStatus(i, eventCount, HP, phoenixdown);
                cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
        }
        cursed(tiny, frog);
        if (event[i] == "0") {
            rescue = 1;
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break;
        }
        if (event[i] == "1" || event[i] == "2" || event[i] == "3" || event[i] == "4" || event[i] == "5") {
            if (level >= levelO(i) || checkLancelot(maxHP) || checkArthur(maxHP)) {
                if (level > levelO(i) || checkLancelot(maxHP) || checkArthur(maxHP)) {
                    level ++;
                    level = levelCheck(level);
                }
            }
            else {
                int eventTemp = stoi(event[i]);
                float baseDamage;
                switch (eventTemp){
                case 1:
                    baseDamage = 1;
                    break;
                case 2:
                    baseDamage = 1.5;
                    break;
                case 3:
                    baseDamage = 4.5;
                    break;
                case 4:
                    baseDamage = 7.5;
                    break;
                case 5:
                    baseDamage = 9.5;
                    break;
                default:
                    break;
                }
            int damage = baseDamage * levelO(i) * 10;
            HP -= damage;
            if (HP <= 0 && phoenixCheck(phoenixdown)) {
                    HP = maxHP;
                    phoenixdown --;
                    }
                }
            } // event 1 -> 5
        if (event[i] == "6") {
            if (winCheck(level, i) || checkLancelot(maxHP) || checkArthur(maxHP)) {
                    level = level + 2;
                    level = levelCheck(level);
                }
            if (!winCheck(level, i) && !tieCheck(level, i)) {
                if (remedyCheck(remedy))
                    remedy --;
                else {
                    tempHP = HP;
                    tiny = 3;
                    if (HP < 5) HP = 1;
                    else HP /= 5;
                }
            }
            if (tieCheck(level, i)) goto here;
        } // event 6
        if (event[i] == "7") {
            if (winCheck(level, i) || checkLancelot(maxHP) || checkArthur(maxHP)) {
                    level = level + 2;
                    level = levelCheck(level);
                }
            if (!winCheck(level, i) && !tieCheck(level, i)) {
                if (maidenCheck(maidenkiss)) {
                    maidenkiss --;
                }
                else {
                    tempLV = level;
                    frog = 3;
                    level = 1;
                }
            if (tieCheck(level, i)) goto here;
            }
        } // event 7
        if (event[i] == "11") { //increment to nearest prime
            int n1 = ((level + phoenixdown) % 5 + 1) * 3;
            int s1 = 0;
            int bigodd = 99;
            for (int j = 0; j < n1; j++) {
                s1 += bigodd;
                bigodd -= 2;
            }
            HP += s1 % 100;
            HP = nearestPrime(HP);
            HP = HPCheck(HP, maxHP);
        } // event 11
        if (event[i] == "12") { // drop to neareat fibo
            HP = nearestFibo(HP);
        }// event 12
        if (event[i].length() > 2) {
            readMush(mushFile, mush, mushSize);
            string sequence = event[i].erase(0, 2);
            for (int j = 0; j < sequence.length(); j ++) {
                switch (sequence[j]) {
                    case '1':
                        mushType1(mush, mushSize, mini, maxi, HP, maxHP);
                        if (HP <= 0 && phoenixCheck(phoenixdown)) {
                            HP = maxHP;
                            phoenixdown --;
                        }
                        if (deadCheck(HP, phoenixdown)) {
                            rescue = 0;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            return;
                        }
                        break;
                    case '2':
                        mushType2(mush, mushSize, mtx, mti, HP, maxHP);
                        if (HP <= 0 && phoenixCheck(phoenixdown)) {
                            HP = maxHP;
                            phoenixdown --;
                        }
                        if (deadCheck(HP, phoenixdown)) {
                            rescue = 0;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            return;
                        }
                        break;
                    case '3':
                        mushType3(mush, mushSize, maxi2, mini2, HP, maxHP);
                        if (HP <= 0 && phoenixCheck(phoenixdown)) {
                            HP = maxHP;
                            phoenixdown --;
                        }
                        if (deadCheck(HP, phoenixdown)) {
                            rescue = 0;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            return;
                        }
                        break;
                    case '4':
                        mushType4(mush, mushSize, max2_3x, max2_3i, HP, maxHP);
                        if (HP <= 0 && phoenixCheck(phoenixdown)) {
                            HP = maxHP;
                            phoenixdown --;
                        }
                        if (deadCheck(HP, phoenixdown)) {
                            rescue = 0;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            return;
                        }
                        break;
                    default:
                        break;
                }
            }
        }// event 13
        if (event[i] == "15") {
            remedy ++;
            remedy = itemCheck(remedy);
            if (tiny > 0) {
                remedy --;
                HP *= 5;
                HP = HPCheck(HP, tempHP);
                tiny = -1;
            }
        } // event 15
        if (event[i] == "16") {
            maidenkiss ++;
            maidenkiss = itemCheck(maidenkiss);
            if (frog > 0) {
                frog = -1;
                level = tempLV;
                maidenkiss --;
            }
        } // event 16
        if (event[i] == "17") {
            phoenixdown ++;
            phoenixdown = itemCheck(phoenixdown);
        } // event 17
        if (event[i] == "18") {
            readMerlin(merlinFile, merlin, n9);
            merlinBless(merlin, n9, HP);
            HP = HPCheck(HP, maxHP);
            event18++;
        }// event 18
        if (event[i] == "19") {
            readAcle(alceFile, alce, r1, c1);
            event19++;
            if (c1 > 0) {
                acleBless(alce, r1, c1, remedy, maidenkiss, phoenixdown);
                if (tiny > 0 && remedyCheck(remedy)) {
                    HP *= 5;
                    if (HP > tempHP) HP = tempHP;
                    tiny = -1;
                    remedy --;
                }
                if (frog > 0 && maidenCheck(maidenkiss)) {
                    level = tempLV;
                    frog = -1;
                    maidenkiss --;
                }
            }
        }// event 19
        if (event[i] == "99") {
            if ((!checkLancelot(maxHP) && !checkArthur(maxHP) && level < 10) || (checkLancelot(maxHP) && level < 8)) {
                rescue = 0;
                cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }
            else level = 10;
        }
        here:
        rescue = rescueStatus(i, eventCount, HP, phoenixdown);
        cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        if (rescue == 0) break;
    }
}
