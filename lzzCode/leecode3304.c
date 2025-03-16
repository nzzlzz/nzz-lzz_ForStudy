/*************  ✨ Codeium Command ⭐  *************/
char getKthCharacter(int k) {
    if (k == 1) return 'a';
    int n = 1;
    while (n < k) {
        n = n * 2 + 1;
    }
    n /= 2;
    if (n == k) return 'a';
    return getKthCharacter(k - n) + 1;
}
/******  b0cc7fe0-d342-4381-bb8d-80d04e2c2887  *******/