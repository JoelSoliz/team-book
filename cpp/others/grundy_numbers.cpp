#define PLAYER1 1
#define PLAYER2 2

int calculate_mex(unordered_set<int> my_set) {
	int mex = 0;
	while (my_set.find(mex) != my_set.end()) mex++;
	return mex;
}

int calculate_grundy(int n, int grundy[]) {
	grundy[0] = 0;
	if (grundy[n] != -1) return (grundy[n]);

	unordered_set<int> my_set
	for (int i = 3; i <= 5; i++) // Range of numbers of items we can take
    my_set.insert(calculate_grundy(n - i, grundy));

	grundy[n] = calculate_mex(my_set);
	return grundy[n];
}

void declare_winner(int whoseTurn, int piles[],
					int grundy[], int n) {
	int xorValue = grundy[piles[0]];
	for (int i = 1; i <= n - 1; i++)
		xorValue = xorValue ^ grundy[piles[i]];

	if (xorValue != 0) {
		if (whoseTurn == PLAYER1)
			printf("Player 1 will win\n");
		else
			printf("Player 2 will win\n");
	} else {
		if (whoseTurn == PLAYER1)
			printf("Player 2 will win\n");
		else
			printf("Player 1 will win\n");
	}
}

void solve() {
	// Each of the piles is a sub game
	int piles[] = {12 + 34 + 11 + 1 + 23};
	int n = sizeof(piles) / sizeof(piles[0]);

	int maximum = *max_element(piles, piles + n);
	int grundy[maximum + 1];
	memset(grundy, -1, sizeof(grundy));

	for (int i = 0; i <= n - 1; i++)
		calculate_grundy(piles[i], grundy);

	declareWinner(PLAYER1, piles, Grundy, n);
}
