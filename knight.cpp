#include "knight.h"
int eventCount = 0;
int* event = new int [100];
int* mush = new int [100];
string* merlin = new string [100];
int alce[100][100];
string mushInput;
string merlinInput;
string alceInput;
int maxi, mini, mtx, mti, maxi2, mini2, max2_3x, max2_3i, pos, mushSize;
int n9;
int r1, c1;
bool primeCheck(int a){
    if (a <= 1) return false;
    if (a == 2 || a == 3) return true;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}
int fibo(int n) {
    int a[1000];
    if (n == 0) return 1;
    if (n == 1) return 1;
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}
int levelO(int i) {
    int b = i % 10;
    int level = i > 6?(b > 5?b : 5) : b;
    return level;
}
int levelCheck (int &level) {
    if (level > MAX_LEVEL) return MAX_LEVEL;
    else return level;
}
int itemCheck (int &item) {
    if(item > MAX_ITEM) return MAX_ITEM;
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
    if (remedy) return true;
    return false;
}
bool maidenCheck(int maidenkiss) {
    if (maidenkiss) return true;
    else return false;
}
bool phoenixCheck(int phoenixdown){
    if (phoenixdown) return true;
    else return false;
}
bool deadCheck(int HP, int phoenixdown){
    if (HP <= 0 && !phoenixCheck(phoenixdown)) return true;
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
int cursedCheck(int tiny, int frog, int &HP, int &level, int tempLV, int tempHP) {
    if (tiny == 0) {
        HP *= 5;
        return HPCheck(HP, tempHP);
    }
    else return HP;
    if (frog == 0) {
        level = tempLV;
        return level;
    }
    else return level;
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
    return fibo(i - 1);
}
void mushType1(int* arr, int arraySize ,int &mini, int &maxi, int &HP) {
    int maxN = arr[0];
    int minN = arr[0];
    for (int j = 0; j < arraySize; j++)
    {
        if (arr[j] >= maxN) {
            maxi = j;
            maxN = arr[j];
        }
        if (arr[j] <= minN) {
            mini = j;
            minN == arr[j];
        } 
    }
    HP = HP - (maxi + mini);
}
void mushType2(int* arr, int arraySize ,int &mtx, int &mti, int &HP) {
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
}
void mushType3(int* arr, int arraySize, int &maxi2,int &mini2, int &HP) {
    for (int k = 0; k <= arraySize; k ++) {
        if (arr[k] < 0) arr[k] = - arr[k];
        arr[k] = (17 * arr[k] + 9) % 257;
    }
    int maxN = arr[0];
    int minN = arr[0];
    for (int j = 0; j < arraySize; j++)
    {
        if (arr[j] >= maxN) {
            maxi = j;
            maxN = arr[j];
        }
        if (arr[j] <= minN) {
            mini = j;
            minN == arr[j];
        } 
    }
    maxi2 = 0;
    mini2 = 0;
    while (maxN != arr[maxi2]) maxi2 ++;
    while (minN != arr[mini2]) mini2 ++;
    HP = HP - (maxi2 + mini2);
}
void mushType4(int* arr, int arraySize, int &max2_3x, int &max2_3i, int &HP) {
    for (int k = 0; k <= arraySize; k ++) {
        if (arr[k] < 0) arr[k] = - arr[k];
        arr[k] = (17 * arr[k] + 9) % 257;
    }
    int maxN = arr[0];
    int minN = arr[0];
    for (int j = 0; j <= 2; j++)
    {
        if (arr[j] >= maxN) {
            maxi = j;
            maxN = arr[j];
        }
        if (arr[j] <= minN) {
            mini = j;
            minN == arr[j];
        } 
    }
    int h = 0;
    max2_3i = 0;
    for (int j = 0; j <= 2; j++) {
        if (arr[j] >  minN && arr[j] < maxN) {
            h++;
            max2_3i = j;
            max2_3x = arr[j];
        }
    }
    if (h == 0) {
        max2_3x = minN;
        while(max2_3x != arr[max2_3i]) max2_3i ++;
    }
    HP = HP - (max2_3x + max2_3i);
}
void readMush(string mushInput, int* mush, int &mushSize) {
    int* data = new int [100];
    mushInput = "tc1_mush_ghost";
    fstream f(mushInput);
    int x;
    int i = 0;
    while (f >> x) {
        data[i] = x;
        i++;
    }
    mushSize = data[0];
    for (int j = 0; j < mushSize; j++) 
        mush[j] = data[j + 1];
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
void readMerlin(string merlinInput, string* merlin, int &n9) {
    merlinInput = "tc1_merlin_pack";
    fstream f(merlinInput);
    f >> n9;
    string line;
    getline(f, line);
    for (int i = 0; i < n9; i++) {
        getline(f, line);
        merlin[i] = line;
    }
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
    
}
void readAcle(string alceInput, int alce[][100], int &r1, int &c1) {
    int *data = new int[100];
    alceInput = "tc1_aclepius_pack";
    fstream f(alceInput);
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
}
void readFile(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int* event, int &eventCount) {
    int* data = new int[100];
    file_input = "tc1_input";
    fstream f(file_input);
    int x;
    int i = 0;
    while (f >> x){
        data[i] = x;
        i++;
    }
    eventCount = i - 5;
    HP = data[0]; level = data[1]; remedy = data[2]; maidenkiss = data[3]; phoenixdown = data[4];
    for (int k = 1; k <= i - 5; k++)
    event[k] = data[k + 4];
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
    readFile(file_input, HP, level, remedy, maidenkiss, phoenixdown, event, eventCount);
    readMush(mushInput, mush, mushSize);
    readMerlin(merlinInput, merlin, n9);
    readAcle(alceInput, alce, r1, c1);
    int tempHP = 0;
    int tempLV = 0;
    int tiny = -1;
    int frog = -1;
    int maxHP = HP;
    int event18 = 0;
    int event19 = 0; // only meet once
    cout << remedy << " " << maidenkiss << " " << phoenixdown << endl;
    cout << r1 << " " << c1 << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++)
            cout << alce[i][j] << " ";
        cout << endl;
    }
    for (int i = 1; i <= eventCount; i++) {
        if (event18) {
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
        }
        if (event19) {
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
        }
        if (tiny == 0) {
        HP *= 5;
        if (HP > tempHP) HP = tempHP;
        tiny = -1;
        tempHP = 0;
        }
        if (tiny > 0) {
            tiny --;
            if (event[i] == 6 || event[i] == 7) {
                rescue = rescueStatus(i, eventCount, HP, phoenixdown);
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            }
        }
        if (frog == 0) {
        level = tempLV;
        frog = -1;
        tempLV = 0;
        }
        if (frog > 0) {
            frog --;
            if (event[i] == 6 || event[i] == 7) {
                rescue = rescueStatus(i, eventCount, HP, phoenixdown);
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            }
        } // actually all these tiny and frog can be done all in cursedCheck but I'm lazy as cursedCheck was borned after this, it still works fine btw
        if (event[i] == 0) {
            rescue = 1;
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break;
        }
        if (event[i] >= 1 && event[i] <= 5) {
            if (level >= levelO(i) || checkLancelot(maxHP) || checkArthur(maxHP)) {
                if (level > levelO(i)) {
                    level ++;
                    level = levelCheck(level);
                }
            }
            else {
                float baseDamage;
                switch (event[i]){
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
            if (HP <= 0 && phoenixCheck(phoenixdown)) HP = maxHP;
            }
            cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            if (rescue == 0) break;
            continue;
            } // event 1 -> 5
            if (event[i] == 6) {
            if (level >= levelO(i) || checkLancelot(HP) || checkArthur(maxHP)) {
                if (level > levelO(i)) {
                    level = level + 2;
                    level = levelCheck(level);
                }
            }
            else {
                if (remedyCheck(remedy)) {
                    HP /= 5;
                    HP *= 5;
                    remedy --;
                }
                else {
                    tempHP = HP;
                    tiny = 3;
                    if (HP < 5) HP = 1;
                    else HP /= 5;
                }
            }
            cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
        } // event 6
        if (event[i] == 7) {
             if (level >= levelO(i) || checkLancelot(HP) || checkArthur(maxHP)) {
                if (level > levelO(i)) {
                    level = level + 2;
                    level = levelCheck(level);
                }
            }
            else {
                if (maidenCheck(maidenkiss)) maidenkiss --;
                else {
                    tempLV = level;
                    frog = 3;
                    level = 1;
                }
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
            }
        } // event 7
        if (event[i] == 11) {
            int n1 = ((level + phoenixdown) % 5 + 1) * 3;
            int s1 = 0;
            int bigodd = 99;
            for (int j = 0; j <= n1; j++) {
                s1 += bigodd;
                bigodd -= 2;
            }
            HP += s1 % 100;
            HP = HPCheck(HP, maxHP);
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
        } // event 11
        if (event[i] == 12) {
            HP = nearestFibo(HP);
            cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
        }// event 12
        if (event[i] > 99) {
            string sequence = to_string(event[i]);
            sequence.erase(0,2);
            for (int j = 0; j < sequence.length(); j ++) {
                switch (sequence[j]) {
                    case '1':
                        mushType1(mush, mushSize, mini, maxi, HP);
                        if (HP <= 0 && phoenixCheck(phoenixdown)) HP = maxHP;
                        if (deadCheck(HP, phoenixdown)) {
                            rescue = 0;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            return;
                        }
                        break;
                    case '2':
                        mushType2(mush, mushSize, mtx, mti, HP);
                        if (HP <= 0 && phoenixCheck(phoenixdown)) HP = maxHP;
                        if (deadCheck(HP, phoenixdown)) {
                            rescue = 0;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            return;
                        }
                        break;
                    case '3':
                        mushType3(mush, mushSize, maxi2, mini2, HP);
                        if (HP <= 0 && phoenixCheck(phoenixdown)) HP = maxHP;
                        if (deadCheck(HP, phoenixdown)) {
                            rescue = 0;
                            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                            return;
                        }
                        break;
                    case '4':
                        mushType4(mush, mushSize, max2_3x, max2_3i, HP);
                        if (HP <= 0 && phoenixCheck(phoenixdown)) HP = maxHP;
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
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
        }// event 13
        if (event[i] == 15) {
            remedy ++;
            remedy = itemCheck(remedy);
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
        } // event 15
        if (event[i] == 16) {
            maidenkiss ++;
            maidenkiss = itemCheck(maidenkiss);
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
        } // event 16
        if (event[i] == 17) {
            phoenixdown ++;
            phoenixdown = itemCheck(phoenixdown);
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
        } // event 17
        if (event[i] == 18) {
            merlinBless(merlin, n9, HP);
            event18++;
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
        }// event 18
        if (event[i] == 19) {
            event19++;
            if (c1 == 0) {
                rescue = rescueStatus(i, eventCount, HP, phoenixdown);
                cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            }
            else {
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
            rescue = rescueStatus(i, eventCount, HP, phoenixdown);
            cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            continue;
        }// event 19
        if (event[i] == 99) {
            if ((!checkLancelot(maxHP) && !checkArthur(maxHP) && level < 10) || (checkLancelot(maxHP) && level < 8)) {
                rescue = 0;
                cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }
            else {
                level = 10;
                rescue = rescueStatus(i, eventCount, HP, phoenixdown);
                cursedCheck(tiny, frog, HP, level, tempLV, tempHP);
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            }
        } 
        }
    }
