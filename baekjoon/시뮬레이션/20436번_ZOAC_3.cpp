// https://www.acmicpc.net/problem/20436

#include <bits/stdc++.h>

using namespace std;

#define ZA 0
#define MO 1

char l, r;
string str;
map<char, int> alpha_za_mo_table; // alphabet, korean za or mo
map<char, pair<int,int>> keyboard; // korean, coordinate
int ans;

int cal_taxi_dist(int type, char to_char) {
    pair<int,int> from;
    pair<int,int> to;
    switch(type) {
        case ZA:
            from = keyboard[l];
            to = keyboard[to_char];
            break;
        case MO:
            from = keyboard[r];
            to = keyboard[to_char];
            break;
    }

    return abs(from.first - to.first) + abs(from.second - to.second) + 1; // + key press
}

int main() {
    cin >> l >> r;
    cin >> str;

    alpha_za_mo_table['q'] = ZA; alpha_za_mo_table['w'] = ZA; alpha_za_mo_table['e'] = ZA; alpha_za_mo_table['r'] = ZA; alpha_za_mo_table['t'] = ZA;
    alpha_za_mo_table['y'] = MO; alpha_za_mo_table['u'] = MO; alpha_za_mo_table['i'] = MO; alpha_za_mo_table['o'] = MO; alpha_za_mo_table['p'] = MO;
    alpha_za_mo_table['a'] = ZA; alpha_za_mo_table['s'] = ZA; alpha_za_mo_table['d'] = ZA; alpha_za_mo_table['f'] = ZA; alpha_za_mo_table['g'] = ZA;
    alpha_za_mo_table['h'] = MO; alpha_za_mo_table['j'] = MO; alpha_za_mo_table['k'] = MO; alpha_za_mo_table['l'] = MO;
    alpha_za_mo_table['z'] = ZA; alpha_za_mo_table['x'] = ZA; alpha_za_mo_table['c'] = ZA; alpha_za_mo_table['v'] = ZA;
    alpha_za_mo_table['b'] = MO; alpha_za_mo_table['n'] = MO; alpha_za_mo_table['m'] = MO;

    keyboard['q'] = {0,0}; keyboard['w'] = {0,1}; keyboard['e'] = {0,2}; keyboard['r'] = {0,3}; keyboard['t'] = {0,4};
    keyboard['y'] = {0,5}; keyboard['u'] = {0,6}; keyboard['i'] = {0,7}; keyboard['o'] = {0,8}; keyboard['p'] = {0,9};
    keyboard['a'] = {1,0}; keyboard['s'] = {1,1}; keyboard['d'] = {1,2}; keyboard['f'] = {1,3}; keyboard['g'] = {1,4};
    keyboard['h'] = {1,5}; keyboard['j'] = {1,6}; keyboard['k'] = {1,7}; keyboard['l'] = {1,8};
    keyboard['z'] = {2,0}; keyboard['x'] = {2,1}; keyboard['c'] = {2,2}; keyboard['v'] = {2,3};
    keyboard['b'] = {2,4}; keyboard['n'] = {2,5}; keyboard['m'] = {2,6};

    for(int i=0; i<str.size(); i++) {
        char ch = str[i];

        switch(alpha_za_mo_table[ch]) {
            case ZA:
                ans += cal_taxi_dist(ZA, ch);
                l = ch;
                break;
            case MO:
                ans += cal_taxi_dist(MO, ch);
                r = ch;
                break;
        }
    }

    cout << ans;
    return 0;
}