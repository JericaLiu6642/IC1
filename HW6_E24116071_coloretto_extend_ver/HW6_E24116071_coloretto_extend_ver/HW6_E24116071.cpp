// HW6_E24116071
#include <iostream> // // allows program to output data to the screen
#include <cstdlib> // contains function prototype for rand
#include <iomanip> // for clear display on the screen
#include <ctime> // generate random number
#include <algorithm> // for sorting
using namespace std; // program uses names from the std namespace

// 卡牌設定: 1紅色 2粉色 3黃色 4橘色 5藍色 6綠色 7灰色 8彩色 9 +2卡 

static int howManyCard3 = 20; // 61 - 9 = 52
static int howManyCard4 = 20; // 在結束卡出現之前會有61張卡
static int howManyCard5 = 15;
static int redCard = 9;
static int pinkCard = 9;
static int yellowCard = 9;
static int orangeCard = 9;
static int blueCard = 9;
static int greenCard = 9;
static int grayCard = 9;
static int plus2Card = 10;
static int colorfulCard = 3;
static int pile1[3] = { 0 }; //初始化卡牌行列成0，判斷裡面是否有牌
static int pile2[3] = { 0 };
static int pile3[3] = { 0 };
static int pile4[3] = { 0 };
static int pile5[3] = { 0 };
static int counterPile1 = 3;
static int counterPile2 = 3;
static int counterPile3 = 3;
static int counterPile4 = 3;
static int counterPile5 = 3;
static int whichPile = 0;
static int userarray[10] = { 0 };
static int player1array[10] = { 0 };
static int player2array[10] = { 0 };
static int player3array[10] = { 0 };
static int player4array[10] = { 0 };
int numberOfPlayer = 0;
enum pileStatus { noCard, canPutCard, full, unusable };
enum allPlayerStatus { play, endplay };
pileStatus isPile1Usable;
pileStatus isPile2Usable;
pileStatus isPile3Usable;
pileStatus isPile4Usable;
pileStatus isPile5Usable;
allPlayerStatus userCanPlay;
allPlayerStatus player1CanPlay;
allPlayerStatus player2CanPlay;
allPlayerStatus player3CanPlay;
allPlayerStatus player4CanPlay;

bool cmp(int, int);

// 不同玩家數的初始化函式
void playerSetUp3();
void playerSetUp4();
void playerSetUp5();

// 3位玩家的函式
void playerColor3();
int drawCard3();
void placeCard3(int, int);
void showPile3();
int choosePile_place3();
int choosePile_take3();
void userTakePile3(int);
void showAllPlayerArray3();
void userPlayTheGame3();
void player1PlayTheGame3();
void player2PlayTheGame3();
void CountPoint3();


// 4位玩家的函式
void playerColor4();
int drawCard4();
void placeCard4(int, int);
void showPile4();
int choosePile_place4();
int choosePile_take4();
void userTakePile4(int);
void showAllPlayerArray4();
void userPlayTheGame4();
void player1PlayTheGame4();
void player2PlayTheGame4();
void player3PlayTheGame4();
void CountPoint4();

// 5位玩家的函式
void playerColor5();
int drawCard5();
void placeCard5(int, int);
void showPile5();
int choosePile_place5();
int choosePile_take5();
void userTakePile5(int);
void showAllPlayerArray5();
void userPlayTheGame5();
void player1PlayTheGame5();
void player2PlayTheGame5();
void player3PlayTheGame5();
void player4PlayTheGame5();
void CountPoint5();


int main()
{
	cout << "How many players are in this game (3, 4, 5):";
	cin >> numberOfPlayer;
	switch (numberOfPlayer)
	{
	case 3:
		playerSetUp3();
		break;
	case 4:
		playerSetUp4();
		break;
	case 5:
		playerSetUp5();
		break;
	}
}

void playerSetUp3()
{
	isPile1Usable = noCard;
	isPile2Usable = noCard;
	isPile3Usable = noCard;
	userCanPlay = play;
	player1CanPlay = play;
	player2CanPlay = play;
	playerColor3(); // 每個玩家的初始變色龍顏色
	showPile3(); // 卡堆初始情況 
	userPlayTheGame3();
}


void playerColor3()
{
	int userInitialColor = 0;
	int player1InitialColor = 0;
	int player2IntialColor = 0;

	do {
		srand(time(NULL));
		userInitialColor = rand() % 6 + 1;
		player1InitialColor = rand() % 6 + 1;
		player2IntialColor = rand() % 6 + 1;
	} while (userInitialColor == player1InitialColor || userInitialColor == player2IntialColor || player1InitialColor == player2IntialColor);

	switch (userInitialColor) // 玩家user的第一隻變色龍顏色，存進玩家的array
	{
	case 1:
		userarray[1]++;
		redCard--;
		howManyCard3--;
		break;
	case 2:
		userarray[2]++;
		pinkCard--;
		howManyCard3--;
		break;
	case 3:
		userarray[3]++;
		yellowCard--;
		howManyCard3--;
		break;
	case 4:
		userarray[4]++;
		orangeCard--;
		howManyCard3--;
		break;
	case 5:
		userarray[5]++;
		blueCard--;
		howManyCard3--;
		break;
	case 6:
		userarray[6]++;
		greenCard--;
		howManyCard3--;
		break;
	}

	switch (player1InitialColor) //電腦1顏色，存進電腦1的array
	{
	case 1:
		player1array[1]++;
		redCard--;
		howManyCard3--;
		break;
	case 2:
		player1array[2]++;
		pinkCard--;
		howManyCard3--;
		break;
	case 3:
		player1array[3]++;
		yellowCard--;
		howManyCard3--;
		break;
	case 4:
		player1array[4]++;
		orangeCard--;
		howManyCard3--;
		break;
	case 5:
		player1array[5]++;
		blueCard--;
		howManyCard3--;
		break;
	case 6:
		player1array[6]++;
		greenCard--;
		howManyCard3--;
		break;
	}

	switch (player2IntialColor) //電腦2顏色
	{
	case 1:
		player2array[1]++;
		redCard--;
		howManyCard3--;
		break;
	case 2:
		player2array[2]++;
		pinkCard--;
		howManyCard3--;
		break;
	case 3:
		player2array[3]++;
		yellowCard--;
		howManyCard3--;
		break;
	case 4:
		player2array[4]++;
		orangeCard--;
		howManyCard3--;
		break;
	case 5:
		player2array[5]++;
		blueCard--;
		howManyCard3--;
		break;
	case 6:
		player2array[6]++;
		greenCard--;
		howManyCard3--;
		break;
	}
	showAllPlayerArray3();
}

void showAllPlayerArray3() //顯示玩家user手牌
{
	cout << endl;
	cout << "All players' card:" << endl;
	cout << "Your card {Red:" << userarray[1] << " Pink:" << userarray[2] << " Yellow:" << userarray[3] << " Orange:" << userarray[4] << " Blue：" << userarray[5] <<
		" Green:" << userarray[6] << " Rainbow:" << userarray[8] << " +2:" << userarray[9] << "}" << endl << endl;

	cout << "Computer player1's card {Red:" << player1array[1] << " Pink:" << player1array[2] << " Yellow:" << player1array[3] << " Orange:" << player1array[4] << " Blue：" << player1array[5] <<
		" Green:" << player1array[6] << " Rainbow:" << player1array[8] << " +2:" << player1array[9] << "}" << endl << endl;

	cout << "Computer player 2's card {Red:" << player2array[1] << " Pink:" << player2array[2] << " Yellow:" << player2array[3] << " Orange:" << player2array[4] << " Blue：" << player2array[5] <<
		" Green:" << player2array[6] << " Rainbow:" << player2array[8] << " +2:" << player2array[9] << "}" << endl << endl;
}

void showPile3()
{
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Card set up   0:no card 1:Red 2:Pink 3:Yellow 4:Orange 5:Blue 6:Green  8:Rainbow 9:+2" << endl;
	cout << "Row 1 { "; // 輸出行列一內的牌
	for (int i = 0; i < 3; i++) {
		cout << pile1[i] << " ";
	}
	cout << "}" << endl;

	cout << "Row 2 { "; // 輸出行列二內的牌
	for (int i = 0; i < 3; i++) {
		cout << pile2[i] << " ";
	}
	cout << "}" << endl;

	cout << "Row 3 { "; // 輸出行列三內的牌
	for (int i = 0; i < 3; i++) {
		cout << pile3[i] << " ";
	}
	cout << "}" << endl;

	cout << "-------------------------------------------------------------------------------------------------------------" << endl;
}


int drawCard3()
{
	int drawColorNumber = 0;
	srand(time(NULL));

	do {
		drawColorNumber = rand() % 9 + 1;
	} while (drawColorNumber == 7);


	switch (drawColorNumber)
	{
	case 1:
		// 卡顏色為紅色
		if (redCard != 0) {
			cout << "\nGet a red card\n";
			howManyCard3--;
			redCard--;
			return drawColorNumber;
		}
		else {
			drawCard3();
		}
		break;
	case 2:
		// 卡顏色為粉色
		if (pinkCard != 0) {
			cout << "\nGet a pink card\n";
			howManyCard3--;
			pinkCard--;
			return drawColorNumber;
		}
		else {
			drawCard3();
		}
		break;
	case 3:
		// 卡顏色為黃色
		if (yellowCard != 0) {
			cout << "\nGet a yellow card\n";
			howManyCard3--;
			yellowCard--;
			return drawColorNumber;
		}
		else {
			drawCard3();
		}
		break;
	case 4:
		// 卡顏色為橘色
		if (orangeCard != 0) {
			cout << "\nGet a orange card\n";
			howManyCard3--;
			orangeCard--;
			return drawColorNumber;
		}
		else {
			drawCard3();
		}
		break;
	case 5:
		// 卡顏色為藍色
		if (blueCard != 0) {
			cout << "\nGet a blue card\n";
			howManyCard3--;
			blueCard--;
			return drawColorNumber;
		}
		else {
			drawCard3();
		}
		break;
	case 6:
		// 卡顏色為綠色
		if (greenCard != 0) {
			cout << "\nGet a green card\n";
			howManyCard3--;
			greenCard--;
			return drawColorNumber;
		}
		else {
			drawCard3();
		}
		break;
	case 8:
		// 卡顏色為彩色
		if (colorfulCard != 0) {
			cout << "\nGet a rainbow card\n";
			howManyCard3--;
			colorfulCard--;
			return drawColorNumber;
		}
		else {
			drawCard3();
		}
		break;
	case 9:
		// +2卡
		if (plus2Card != 0) {
			cout << "\nGet a +2 card\n";
			howManyCard3--;
			plus2Card--;
			return drawColorNumber;
		}
		else {
			drawCard3();
		}
		break;
	}
}


void placeCard3(int whichPile, int drawColorNumber)
{
	if (whichPile == 1) {
		if (counterPile1 != 0) {
			if (isPile1Usable != unusable) {
				for (int i = 0; i < 3; i++) {
					if (pile1[i] == 0) {
						pile1[i] = drawColorNumber;
						counterPile1--;
						isPile1Usable = canPutCard;
						break;
					}
				}
			}
			else {
				cout << "Row 1 has bee taken. Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place3();
				placeCard3(whichPile, drawColorNumber);
			}
		}
		else {
			isPile1Usable = full;
			cout << "Row 1 is already full. Please Choose another row to place your card:" << endl;
			int whichPile = choosePile_place3();
			placeCard3(whichPile, drawColorNumber);
		}
	}

	else if (whichPile == 2) {
		if (counterPile2 != 0) {
			if (isPile2Usable != unusable) {
				for (int i = 0; i < 3; i++) {
					if (pile2[i] == 0) {
						pile2[i] = drawColorNumber;
						counterPile2--;
						isPile2Usable = canPutCard;
						break;
					}
				}
			}
			else {
				cout << "Row 2 has bee taken, Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place3();
				placeCard3(whichPile, drawColorNumber);
			}
		}
		else {
			if (isPile2Usable = full) {
				cout << "Row 2 is already full. Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place3();
				placeCard3(whichPile, drawColorNumber);
			}
		}
	}

	else if (whichPile == 3) {
		if (counterPile3 != 0) {
			if (isPile3Usable != unusable) {
				for (int i = 0; i < 3; i++) {
					if (pile3[i] == 0) {
						pile3[i] = drawColorNumber;
						counterPile3--;
						isPile3Usable = canPutCard;
						break;
					}
				}
			}
			else {
				cout << "Row 3 has bee taken, Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place3();
				placeCard3(whichPile, drawColorNumber);
			}
		}
		else {
			cout << "Row 3 is already full. Please Choose another row to place your card:" << endl;
			int whichPile = choosePile_place3();
			placeCard3(whichPile, drawColorNumber);
		}
	}
}

int choosePile_place3()
{
	cout << "Which row do you want to put your card:";
	int choose_a_pile_to_place;
	cin >> choose_a_pile_to_place;
	return choose_a_pile_to_place;
}

int choosePile_take3()
{
	cout << "Which row do you want to take back:";
	int choose_a_pile_to_take = 0;
	cin >> choose_a_pile_to_take;
	return choose_a_pile_to_take;
}


void userTakePile3(int whichPile)
{
	if (whichPile == 1 || whichPile == 2 || whichPile == 3 || whichPile == 4) {
		bool inputError = true;
		if (whichPile == 1) {
			if (isPile1Usable == canPutCard || isPile1Usable == full) {
				for (int i = 0; i < 3; i++) {
					userarray[pile1[i]]++;
					pile1[i] = 0;
				}
				isPile1Usable = unusable;
				userCanPlay = endplay;
			}
			else {
				cout << "Row 1 can not be taken for now. Please choose your move again:" << endl;
				while (inputError) {
					cout << "1:draw a card  2:take a row back   Please enter your choice of move:";
					int choice;
					cin >> choice;
					if (choice == 1) {
						int drawColorNumber = drawCard3();
						int whichPile = choosePile_place3();
						placeCard3(whichPile, drawColorNumber);
						inputError = false;
					}
					else if (choice == 2) {
						cout << "Which row do you want to take back:";
						int whichPile = choosePile_take3();
						userTakePile3(whichPile);
						inputError = false;
					}
					else {
						cout << "Input error please try again!" << endl;
					}
				}
			}
		}

		else if (whichPile == 2) {
			if (isPile2Usable == canPutCard || isPile2Usable == full) {
				for (int i = 0; i < 3; i++) {
					userarray[pile2[i]]++;
					pile2[i] = 0;
				}
				isPile2Usable = unusable;
				userCanPlay = endplay;
			}
			else {
				cout << "Row 2 can not be taken for now. Please choose your move again:" << endl;
				while (inputError) {
					cout << "1:draw a card  2:take a row back   Please enter your choice of move:";
					int choice;
					cin >> choice;
					if (choice == 1) {
						int drawColorNumber = drawCard3();
						int whichPile = choosePile_place3();
						placeCard3(whichPile, drawColorNumber);
						inputError = false;
					}
					else if (choice == 2) {
						cout << "Which row do you want to take back:";
						int whichPile = choosePile_take3();
						userTakePile3(whichPile);
						inputError = false;
					}
					else {
						cout << "Input error please try again!" << endl;
					}
				}
			}
		}

		else if (whichPile == 3) {
			if (isPile3Usable == canPutCard || isPile3Usable == full) {
				for (int i = 0; i < 3; i++) {
					userarray[pile3[i]]++;
					pile3[i] = 0;
				}
				isPile3Usable = unusable;
				userCanPlay = endplay;
			}
			else {
				cout << "Row 3 can not be taken for now. Please choose your move again:" << endl;
				while (inputError) {
					cout << "1:draw a card  2:take a row back   Please enter your choice of move:";
					int choice;
					cin >> choice;
					if (choice == 1) {
						int drawColorNumber = drawCard3();
						int whichPile = choosePile_place3();
						placeCard3(whichPile, drawColorNumber);
						inputError = false;
					}
					else if (choice == 2) {
						cout << "Which row do you want to take back:";
						int whichPile = choosePile_take3();
						userTakePile3(whichPile);
						inputError = false;
					}
					else {
						cout << "Input error please try again!" << endl;
					}
				}
			}
		}
	}
	else {
		cout << "Input error please try again!" << endl;
		cout << "Which row do you want to take back:";
		int whichPile;
		cin >> whichPile;
		userTakePile3(whichPile);
	}
}


void userPlayTheGame3() // 玩家user的主要程式，包含user的所有選擇
{
	int userChoiceOfMove; //紀錄玩家選擇
	cout << "\n***Your round***" << endl;
	cout << "1:draw a card  2:take a row back   Please enter your choice of move:";

	do {
		cin >> userChoiceOfMove;

		if (userChoiceOfMove == 1) {
			int drawColorNumber = drawCard3();
			int whichPile = choosePile_place3();
			placeCard3(whichPile, drawColorNumber);
			showAllPlayerArray3();
			showPile3();
			break;
		}
		else if (userChoiceOfMove == 2) {
			int whichPile = choosePile_take3();
			userTakePile3(whichPile);
			showAllPlayerArray3();
			showPile3();
			break;
		}
		else {
			cout << "Input error please try again! 1:draw a card  2:take a row back   Please enter your choice of move:";
		}
	} while (userChoiceOfMove != 1 || userChoiceOfMove != 2);

	// 如果該輪還沒結束，則繼續進行，判斷下一位是誰能玩
	if (player1CanPlay == play) {
		player1PlayTheGame3();
	}
	else if (player2CanPlay == play) {
		player2PlayTheGame3();
	}
	else {
		if (userCanPlay == play) {
			userPlayTheGame3();
		}
		else {
			if (howManyCard3 <= 0) {
				CountPoint3();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				userPlayTheGame3();
			}
		}
	}
}


void player1PlayTheGame3()
{
	cout << "\n***Computer player1's round***" << endl;
	// 只要可收牌就收牌的機制
	if (isPile1Usable != noCard && isPile1Usable != unusable) {
		cout << "Computer player1 take back row 1" << endl;
		for (int i = 0; i < 3; i++) {
			player1array[pile1[i]]++;
			pile1[i] = 0;
		}
		isPile1Usable = unusable;
		player1CanPlay = endplay;
		showAllPlayerArray3();
		showPile3();
	}
	else if (isPile2Usable != noCard && isPile2Usable != unusable) {
		cout << "Computer player1 take back row 2" << endl;
		for (int i = 0; i < 3; i++) {
			player1array[pile2[i]]++;
			pile2[i] = 0;
		}
		isPile2Usable = unusable;
		player1CanPlay = endplay;
		showAllPlayerArray3();
		showPile3();
	}
	else if (isPile3Usable != noCard && isPile3Usable != unusable) {
		cout << "Computer player1 take back row 3" << endl;
		for (int i = 0; i < 3; i++) {
			player1array[pile3[i]]++;
			pile3[i] = 0;
		}
		isPile3Usable = unusable;
		player1CanPlay = endplay;
		showAllPlayerArray3();
		showPile3();
	}
	else { // 無法收牌，只能抽牌
		cout << "Computer player1 draw a card";
		int drawColorNumber = drawCard3();
		//判斷哪個行列能放牌
		if (isPile1Usable != unusable) {
			cout << "Put the card in row 1" << endl;
			pile1[0] = drawColorNumber;
			isPile1Usable = canPutCard;
			showAllPlayerArray3();
			showPile3();
		}
		else if (isPile2Usable != unusable) {
			cout << "Put the card in row 2" << endl;
			pile2[0] = drawColorNumber;
			isPile2Usable = canPutCard;
			showAllPlayerArray3();
			showPile3();
		}
		else if (isPile3Usable != unusable) {
			cout << "Put the card in row 3" << endl;
			pile3[0] = drawColorNumber;
			isPile3Usable = canPutCard;
			showAllPlayerArray3();
			showPile3();
		}
	}

	// 如果該輪還沒結束，則繼續進行，判斷下一位是誰能玩
	if (player2CanPlay == play) {
		player2PlayTheGame3();
	}
	else if (userCanPlay == play) {
		userPlayTheGame3();
	}
	else {
		// 電腦如果是該輪最後一個人並且遊戲沒結束則強制收牌
		if (player1CanPlay == play) {
			if (isPile1Usable != noCard && isPile1Usable != unusable) {
				cout << "Computer player1 take back row 1" << endl;
				for (int i = 0; i < 3; i++) {
					player1array[pile1[i]]++;
					pile1[i] = 0;
				}
				player1CanPlay = endplay;
				isPile1Usable = unusable;
				showAllPlayerArray3();
				showPile3();
			}
			else if (isPile2Usable != noCard && isPile2Usable != unusable) {
				cout << "Computer player1 take back row 2" << endl;
				for (int i = 0; i < 3; i++) {
					player1array[pile2[i]]++;
					pile2[i] = 0;
				}
				player1CanPlay = endplay;
				isPile2Usable = unusable;
				showAllPlayerArray3();
				showPile3();
			}
			else if (isPile3Usable != noCard && isPile3Usable != unusable) {
				cout << "Computer player1 take back row 3" << endl;
				for (int i = 0; i < 3; i++) {
					player1array[pile3[i]]++;
					pile3[i] = 0;
				}
				player1CanPlay = endplay;
				isPile3Usable = unusable;
				showAllPlayerArray3();
				showPile3();
			}

			if (howManyCard3 <= 0) {
				CountPoint3();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				player1PlayTheGame3();
			}
		}
		// 所有人皆已完成操作，該輪結束
		else {
			if (howManyCard3 <= 0) {
				CountPoint3();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				player1PlayTheGame3();
			}
		}
	}
}


void player2PlayTheGame3()
{
	cout << "\n***Computer player2's round***" << endl;
	// 只要可收牌就收牌的機制
	if (isPile1Usable != noCard && isPile1Usable != unusable) {
		cout << "Computer player2 take back row 1" << endl;
		for (int i = 0; i < 3; i++) {
			player2array[pile1[i]]++;
			pile1[i] = 0;
		}
		isPile1Usable = unusable;
		player2CanPlay = endplay;
		showAllPlayerArray3();
		showPile3();
	}
	else if (isPile2Usable != noCard && isPile2Usable != unusable) {
		cout << "Computer player2 take back row 2" << endl;
		for (int i = 0; i < 3; i++) {
			player2array[pile2[i]]++;
			pile2[i] = 0;
		}
		isPile2Usable = unusable;
		player2CanPlay = endplay;
		showAllPlayerArray3();
		showPile3();
	}
	else if (isPile3Usable != noCard && isPile3Usable != unusable) {
		cout << "Computer player2 take back row 3" << endl;
		for (int i = 0; i < 3; i++) {
			player2array[pile3[i]]++;
			pile3[i] = 0;
		}
		isPile3Usable = unusable;
		player2CanPlay = endplay;
		showAllPlayerArray3();
		showPile3();
	}
	else { // 無法收牌，只能抽牌
		cout << "Computer player2 draw a card";
		int drawColorNumber = drawCard3();
		//判斷哪個行列能放牌
		if (isPile1Usable != unusable) {
			cout << "Put the card in row 1" << endl;
			pile1[0] = drawColorNumber;
			isPile1Usable = canPutCard;
			showAllPlayerArray3();
			showPile3();
		}
		else if (isPile2Usable != unusable) {
			cout << "Put the card in row 2" << endl;
			pile2[0] = drawColorNumber;
			isPile2Usable = canPutCard;
			showAllPlayerArray3();
			showPile3();
		}
		else if (isPile3Usable != unusable) {
			cout << "Put the card in row 3" << endl;
			pile3[0] = drawColorNumber;
			isPile3Usable = canPutCard;
			showAllPlayerArray3();
			showPile3();
		}
	}

	// 如果該輪還沒結束，則繼續進行，判斷下一位是誰能玩
	if (userCanPlay == play) {
		userPlayTheGame3();
	}
	else if (player1CanPlay == play) {
		player1PlayTheGame3();
	}
	else {
		// 電腦如果是該輪最後一個人並且遊戲沒結束則強制收牌
		if (player2CanPlay == play) {
			if (isPile1Usable != unusable) {
				cout << "Computer player2 take back row 1" << endl;
				for (int i = 0; i < 3; i++) {
					player2array[pile1[i]]++;
					pile1[i] = 0;
				}
				player2CanPlay = endplay;
				isPile1Usable = unusable;
				showAllPlayerArray3();
				showPile3();
			}
			else if (isPile2Usable != unusable) {
				cout << "Computer player2 take back row 2" << endl;
				for (int i = 0; i < 3; i++) {
					player2array[pile2[i]]++;
					pile2[i] = 0;
				}
				player2CanPlay = endplay;
				isPile2Usable = unusable;
				showAllPlayerArray3();
				showPile3();
			}
			else if (isPile3Usable != unusable) {
				cout << "Computer player2 take back row 3" << endl;
				for (int i = 0; i < 3; i++) {
					player2array[pile3[i]]++;
					pile3[i] = 0;
				}
				player2CanPlay = endplay;
				isPile3Usable = unusable;
				showAllPlayerArray3();
				showPile3();
			}

			if (howManyCard3 <= 0) {
				CountPoint3();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				player2PlayTheGame3();
			}
		}
		// 所有人皆已完成操作，該輪結束
		else {
			if (howManyCard3 <= 0) {
				CountPoint3();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				player2PlayTheGame3();
			}
		}
	}
}


bool cmp(int a, int b)
{
	return a > b;
}

void CountPoint3()
{
	// 強制讓[0]位置為0
	userarray[0] = 0;
	userarray[7] = 0;
	player1array[0] = 0;
	player1array[7] = 0;
	player2array[0] = 0;
	player1array[7] = 0;

	// sort 排卡的數量
	sort(userarray, userarray + 8, cmp);
	sort(player1array, player1array + 8, cmp);
	sort(player2array, player2array + 8, cmp);
	sort(player3array, player3array + 8, cmp);

	// 彩色變色龍的最佳放法
	// user
	if (userarray[0] >= 6) {
		if (userarray[1] > 6) {
			for (int i = 0; i < userarray[8]; i++) {
				userarray[2]++;
			}
		}
		else {
			for (int i = 0; i < userarray[8]; i++) {
				userarray[1]++;
			}
		}
	}
	else {
		for (int i = 0; i < userarray[8]; i++) {
			userarray[0]++;
		}
	}

	// 電腦一
	if (player1array[1] >= 6) {
		if (player1array[2] > 6) {
			for (int i = 0; i < player1array[8]; i++) {
				player1array[3]++;
			}
		}
		else {
			for (int i = 0; i < player1array[8]; i++) {
				player1array[2]++;
			}
		}
	}
	else {
		for (int i = 0; i < player1array[8]; i++) {
			player1array[1]++;
		}
	}

	// 電腦二
	if (player2array[1] >= 6) {
		if (player2array[2] > 6) {
			for (int i = 0; i < player2array[8]; i++) {
				player2array[3]++;
			}
		}
		else {
			for (int i = 0; i < player2array[8]; i++) {
				player2array[2]++;
			}
		}
	}
	else {
		for (int i = 0; i < player2array[8]; i++) {
			player2array[1]++;
		}
	}

	// 電腦三
	if (player3array[1] >= 6) {
		if (player3array[2] > 6) {
			for (int i = 0; i < player3array[8]; i++) {
				player3array[3]++;
			}
		}
		else {
			for (int i = 0; i < player3array[8]; i++) {
				player3array[2]++;
			}
		}
	}
	else {
		for (int i = 0; i < player3array[8]; i++) {
			player3array[1]++;
		}
	}

	// 開始計算分數，用swich判斷每一個使用者陣列裡的數值
	// user牌由大到小
	int u1 = 0;
	int u2 = 0;
	int u3 = 0;
	int u4 = 0;
	int u5 = 0;
	int u6 = 0;

	switch (userarray[0]) // 最多的牌可拿幾分
	{
	case 6:
		u1 = 21;
		break;
	case 5:
		u1 = 15;
		break;
	case 4:
		u1 = 10;
		break;
	case 3:
		u1 = 6;
		break;
	case 2:
		u1 = 3;
		break;
	case 1:
		u1 = 1;
		break;
	case 0:
		u1 = 0;
		break;
	}

	switch (userarray[1]) // 第二多的牌可拿幾分
	{
	case 6:
		u2 = 21;
		break;
	case 5:
		u2 = 15;
		break;
	case 4:
		u2 = 10;
		break;
	case 3:
		u2 = 6;
		break;
	case 2:
		u2 = 3;
		break;
	case 1:
		u2 = 1;
		break;
	case 0:
		u2 = 0;
		break;
	}

	switch (userarray[2]) // 第三多的牌可拿幾分
	{
	case 6:
		u3 = 21;
		break;
	case 5:
		u3 = 15;
		break;
	case 4:
		u3 = 10;
		break;
	case 3:
		u3 = 6;
		break;
	case 2:
		u3 = 3;
		break;
	case 1:
		u3 = 1;
		break;
	case 0:
		u3 = 0;
		break;
	}

	switch (userarray[3]) // 第四多的牌可要扣幾分
	{
	case 6:
		u4 = -21;
		break;
	case 5:
		u4 = -15;
		break;
	case 4:
		u4 = -10;
		break;
	case 3:
		u4 = -6;
		break;
	case 2:
		u4 = -3;
		break;
	case 1:
		u4 = -1;
		break;
	case 0:
		u4 = 0;
		break;
	}

	switch (userarray[4]) // 第五多的牌可要扣幾分
	{
	case 6:
		u5 = -21;
		break;
	case 5:
		u5 = -15;
		break;
	case 4:
		u5 = -10;
		break;
	case 3:
		u5 = -6;
		break;
	case 2:
		u5 = -3;
		break;
	case 1:
		u5 = -1;
		break;
	case 0:
		u5 = 0;
		break;
	}

	switch (userarray[5]) // 第六多的牌可要扣幾分
	{
	case 6:
		u6 = -21;
		break;
	case 5:
		u6 = -15;
		break;
	case 4:
		u6 = -10;
		break;
	case 3:
		u6 = -6;
		break;
	case 2:
		u6 = -3;
		break;
	case 1:
		u6 = -1;
		break;
	case 0:
		u6 = 0;
		break;
	}

	int userTotalPoints = u1 + u2 + u3 + u4 + u5 + u6 + userarray[9] * 2;

	// 電腦一牌由大到小
	int p11 = 0;
	int p12 = 0;
	int p13 = 0;
	int p14 = 0;
	int p15 = 0;
	int p16 = 0;

	switch (player1array[0]) // 最多的牌可拿幾分
	{
	case 6:
		p11 = 21;
		break;
	case 5:
		p11 = 15;
		break;
	case 4:
		p11 = 10;
		break;
	case 3:
		p11 = 6;
		break;
	case 2:
		p11 = 3;
		break;
	case 1:
		p11 = 1;
		break;
	case 0:
		p11 = 0;
		break;
	}

	switch (player1array[1]) // 第二多的牌可拿幾分
	{
	case 6:
		p12 = 21;
		break;
	case 5:
		p12 = 15;
		break;
	case 4:
		p12 = 10;
		break;
	case 3:
		p12 = 6;
		break;
	case 2:
		p12 = 3;
		break;
	case 1:
		p12 = 1;
		break;
	case 0:
		p12 = 0;
		break;
	}

	switch (player1array[2]) // 第三多的牌可拿幾分
	{
	case 6:
		p13 = 21;
		break;
	case 5:
		p13 = 15;
		break;
	case 4:
		p13 = 10;
		break;
	case 3:
		p13 = 6;
		break;
	case 2:
		p13 = 3;
		break;
	case 1:
		p13 = 1;
		break;
	case 0:
		p13 = 0;
		break;
	}

	switch (player1array[3]) // 第四多的牌可要扣幾分
	{
	case 6:
		p14 = -21;
		break;
	case 5:
		p14 = -15;
		break;
	case 4:
		p14 = -10;
		break;
	case 3:
		p14 = -6;
		break;
	case 2:
		p14 = -3;
		break;
	case 1:
		p14 = -1;
		break;
	case 0:
		p14 = 0;
		break;
	}

	switch (player1array[4]) // 第五多的牌可要扣幾分
	{
	case 6:
		p15 = -21;
		break;
	case 5:
		p15 = -15;
		break;
	case 4:
		p15 = -10;
		break;
	case 3:
		p15 = -6;
		break;
	case 2:
		p15 = -3;
		break;
	case 1:
		p15 = -1;
		break;
	case 0:
		p15 = 0;
		break;
	}

	switch (player1array[5]) // 第六多的牌可要扣幾分
	{
	case 6:
		p16 = -21;
		break;
	case 5:
		p16 = -15;
		break;
	case 4:
		p16 = -10;
		break;
	case 3:
		p16 = -6;
		break;
	case 2:
		p16 = -3;
		break;
	case 1:
		p16 = -1;
		break;
	case 0:
		p16 = 0;
		break;
	}


	int player1TotalPoints = p11 + p12 + p13 + p14 + p15 + p16 + player1array[9] * 2;

	// 電腦二牌由大到小
	int p21 = 0;
	int p22 = 0;
	int p23 = 0;
	int p24 = 0;
	int p25 = 0;
	int p26 = 0;

	switch (player2array[0]) // 最多的牌可拿幾分
	{
	case 6:
		p21 = 21;
		break;
	case 5:
		p21 = 15;
		break;
	case 4:
		p21 = 10;
		break;
	case 3:
		p21 = 6;
		break;
	case 2:
		p21 = 3;
		break;
	case 1:
		p21 = 1;
		break;
	case 0:
		p21 = 0;
		break;
	}

	switch (player2array[1]) // 第二多的牌可拿幾分
	{
	case 6:
		p22 = 21;
		break;
	case 5:
		p22 = 15;
		break;
	case 4:
		p22 = 10;
		break;
	case 3:
		p22 = 6;
		break;
	case 2:
		p22 = 3;
		break;
	case 1:
		p22 = 1;
		break;
	case 0:
		p22 = 0;
		break;
	}

	switch (player2array[2]) // 第三多的牌可拿幾分
	{
	case 6:
		p23 = 21;
		break;
	case 5:
		p23 = 15;
		break;
	case 4:
		p23 = 10;
		break;
	case 3:
		p23 = 6;
		break;
	case 2:
		p23 = 3;
		break;
	case 1:
		p23 = 1;
		break;
	case 0:
		p23 = 0;
		break;
	}

	switch (player2array[3]) // 第四多的牌可要扣幾分
	{
	case 6:
		p24 = -21;
		break;
	case 5:
		p24 = -15;
		break;
	case 4:
		p24 = -10;
		break;
	case 3:
		p24 = -6;
		break;
	case 2:
		p24 = -3;
		break;
	case 1:
		p24 = -1;
		break;
	case 0:
		p24 = 0;
		break;
	}

	switch (player2array[4]) // 第五多的牌可要扣幾分
	{
	case 6:
		p25 = -21;
		break;
	case 5:
		p25 = -15;
		break;
	case 4:
		p25 = -10;
		break;
	case 3:
		p25 = -6;
		break;
	case 2:
		p25 = -3;
		break;
	case 1:
		p25 = -1;
		break;
	case 0:
		p25 = 0;
		break;
	}

	switch (player2array[5]) // 第六多的牌可要扣幾分
	{
	case 6:
		p26 = -21;
		break;
	case 5:
		p26 = -15;
		break;
	case 4:
		p26 = -10;
		break;
	case 3:
		p26 = -6;
		break;
	case 2:
		p26 = -3;
		break;
	case 1:
		p26 = -1;
		break;
	case 0:
		p26 = 0;
		break;
	}


	int player2TotalPoints = p21 + p22 + p23 + p24 + p25 + p26 + player2array[9] * 2;


	cout << "\nThe points you get:" << userTotalPoints << endl;
	cout << "The points computer player1 gets:" << player1TotalPoints << endl;
	cout << "The points computer player2 gets:" << player2TotalPoints << endl;
}

void playerSetUp4()
{
	// 初始化所有玩家狀態=可玩，行列狀態=沒有牌，可放牌
	isPile1Usable = noCard;
	isPile2Usable = noCard;
	isPile3Usable = noCard;
	isPile4Usable = noCard;
	userCanPlay = play;
	player1CanPlay = play;
	player2CanPlay = play;
	player3CanPlay = play;

	playerColor4(); // 每個玩家的初始變色龍顏色
	showPile4(); // 卡堆初始情況 
	userPlayTheGame4();
}

void playerColor4()
{
	int userInitialColor = 0;
	int player1InitialColor = 0;
	int player2IntialColor = 0;
	int player3IntialColor = 0;

	do {
		srand(time(NULL));
		userInitialColor = rand() % 7 + 1;
		player1InitialColor = rand() % 7 + 1;
		player2IntialColor = rand() % 7 + 1;
		player3IntialColor = rand() % 7 + 1;
	} while (userInitialColor == player1InitialColor || userInitialColor == player2IntialColor || userInitialColor == player3IntialColor || player1InitialColor == player2IntialColor ||
		player1InitialColor == player3IntialColor || player2IntialColor == player3IntialColor);

	switch (userInitialColor) // 玩家user的第一隻變色龍顏色，存進玩家的array
	{
	case 1:
		userarray[1]++;
		redCard--;
		howManyCard4--;
		break;
	case 2:
		userarray[2]++;
		pinkCard--;
		howManyCard4--;
		break;
	case 3:
		userarray[3]++;
		yellowCard--;
		howManyCard4--;
		break;
	case 4:
		userarray[4]++;
		orangeCard--;
		howManyCard4--;
		break;
	case 5:
		userarray[5]++;
		blueCard--;
		howManyCard4--;
		break;
	case 6:
		userarray[6]++;
		greenCard--;
		howManyCard4--;
		break;
	case 7:
		userarray[7]++;
		grayCard--;
		howManyCard4--;
		break;
	}

	switch (player1InitialColor) //電腦1顏色，存進電腦1的array
	{
	case 1:
		player1array[1]++;
		redCard--;
		howManyCard4--;
		break;
	case 2:
		player1array[2]++;
		pinkCard--;
		howManyCard4--;
		break;
	case 3:
		player1array[3]++;
		yellowCard--;
		howManyCard4--;
		break;
	case 4:
		player1array[4]++;
		orangeCard--;
		howManyCard4--;
		break;
	case 5:
		player1array[5]++;
		blueCard--;
		howManyCard4--;
		break;
	case 6:
		player1array[6]++;
		greenCard--;
		howManyCard4--;
		break;
	case 7:
		player1array[7]++;
		grayCard--;
		howManyCard4--;
		break;
	}

	switch (player2IntialColor) //電腦2顏色
	{
	case 1:
		player2array[1]++;
		redCard--;
		howManyCard4--;
		break;
	case 2:
		player2array[2]++;
		pinkCard--;
		howManyCard4--;
		break;
	case 3:
		player2array[3]++;
		yellowCard--;
		howManyCard4--;
		break;
	case 4:
		player2array[4]++;
		orangeCard--;
		howManyCard4--;
		break;
	case 5:
		player2array[5]++;
		blueCard--;
		howManyCard4--;
		break;
	case 6:
		player2array[6]++;
		greenCard--;
		howManyCard4--;
		break;
	case 7:
		player2array[7]++;
		grayCard--;
		howManyCard4--;
		break;
	}

	switch (player3IntialColor)// 電腦3顏色
	{
	case 1:
		player3array[1]++;
		redCard--;
		howManyCard4--;
		break;
	case 2:
		player3array[2]++;
		pinkCard--;
		howManyCard4--;
		break;
	case 3:
		player3array[3]++;
		yellowCard--;
		howManyCard4--;
		break;
	case 4:
		player3array[4]++;
		orangeCard--;
		howManyCard4--;
		break;
	case 5:
		player3array[5]++;
		blueCard--;
		howManyCard4--;
		break;
	case 6:
		player3array[6]++;
		greenCard--;
		howManyCard4--;
		break;
	case 7:
		player3array[7]++;
		grayCard--;
		howManyCard4--;
		break;
	}
	showAllPlayerArray4();
}


void showAllPlayerArray4() //顯示玩家user手牌
{
	cout << endl;
	cout << "All players' card:" << endl;
	cout << "Your card {Red:" << userarray[1] << " Pink:" << userarray[2] << " Yellow:" << userarray[3] << " Orange:" << userarray[4] << " Blue：" << userarray[5] <<
		" Green:" << userarray[6] << " Gray:" << userarray[7] << " Rainbow:" << userarray[8] << " +2:" << userarray[9] << "}" << endl << endl;

	cout << "Computer player1's card {Red:" << player1array[1] << " Pink:" << player1array[2] << " Yellow:" << player1array[3] << " Orange:" << player1array[4] << " Blue：" << player1array[5] <<
		" Green:" << player1array[6] << " Gray:" << player1array[7] << " Rainbow:" << player1array[8] << " +2:" << player1array[9] << "}" << endl << endl;

	cout << "Computer player 2's card {Red:" << player2array[1] << " Pink:" << player2array[2] << " Yellow:" << player2array[3] << " Orange:" << player2array[4] << " Blue：" << player2array[5] <<
		" Green:" << player2array[6] << " Gray:" << player2array[7] << " Rainbow:" << player2array[8] << " +2:" << player2array[9] << "}" << endl << endl;

	cout << "Computer player3's card {Red:" << player3array[1] << " Pink:" << player3array[2] << " Yellow:" << player3array[3] << " Orange:" << player3array[4] << " Blue：" << player3array[5] <<
		" Green:" << player3array[6] << " Gray:" << player3array[7] << " Rainbow:" << player3array[8] << " +2:" << player3array[9] << "}" << endl << endl;
}

void showPile4()
{
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Card set up   0:no card 1:Red 2:Pink 3:Yellow 4:Orange 5:Blue 6:Green 7:Gray 8:Rainbow 9:+2" << endl;
	cout << "Row 1 { "; // 輸出行列一內的牌
	for (int i = 0; i < 3; i++) {
		cout << pile1[i] << " ";
	}
	cout << "}" << endl;

	cout << "Row 2 { "; // 輸出行列二內的牌
	for (int i = 0; i < 3; i++) {
		cout << pile2[i] << " ";
	}
	cout << "}" << endl;

	cout << "Row 3 { "; // 輸出行列三內的牌
	for (int i = 0; i < 3; i++) {
		cout << pile3[i] << " ";
	}
	cout << "}" << endl;

	cout << "Row 4 { "; // 輸出行列四內的牌
	for (int i = 0; i < 3; i++) {
		cout << pile4[i] << " ";
	}
	cout << "}" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------" << endl;
}


int drawCard4()
{
	srand(time(NULL));
	int drawColorNumber = rand() % 9 + 1;

	switch (drawColorNumber)
	{
	case 1:
		// 卡顏色為紅色
		if (redCard != 0) {
			cout << "\nGet a red card\n";
			howManyCard4--;
			redCard--;
			return drawColorNumber;
		}
		else {
			drawCard4();
		}
		break;
	case 2:
		// 卡顏色為粉色
		if (pinkCard != 0) {
			cout << "\nGet a pink card\n";
			howManyCard4--;
			pinkCard--;
			return drawColorNumber;
		}
		else {
			drawCard4();
		}
		break;
	case 3:
		// 卡顏色為黃色
		if (yellowCard != 0) {
			cout << "\nGet a yellow card\n";
			howManyCard4--;
			yellowCard--;
			return drawColorNumber;
		}
		else {
			drawCard4();
		}
		break;
	case 4:
		// 卡顏色為橘色
		if (orangeCard != 0) {
			cout << "\nGet a orange card\n";
			howManyCard4--;
			orangeCard--;
			return drawColorNumber;
		}
		else {
			drawCard4();
		}
		break;
	case 5:
		// 卡顏色為藍色
		if (blueCard != 0) {
			cout << "\nGet a blue card\n";
			howManyCard4--;
			blueCard--;
			return drawColorNumber;
		}
		else {
			drawCard4();
		}
		break;
	case 6:
		// 卡顏色為綠色
		if (greenCard != 0) {
			cout << "\nGet a green card\n";
			howManyCard4--;
			greenCard--;
			return drawColorNumber;
		}
		else {
			drawCard4();
		}
		break;
	case 7:
		// 卡顏色為灰色
		if (grayCard != 0) {
			cout << "\nGet a gray card\n";
			howManyCard4--;
			grayCard--;
			return drawColorNumber;
		}
		else {
			drawCard4();
		}
		break;
	case 8:
		// 卡顏色為彩色
		if (colorfulCard != 0) {
			cout << "\nGet a rainbow card\n";
			howManyCard4--;
			colorfulCard--;
			return drawColorNumber;
		}
		else {
			drawCard4();
		}
		break;
	case 9:
		// +2卡
		if (plus2Card != 0) {
			cout << "\nGet a +2 card\n";
			howManyCard4--;
			plus2Card--;
			return drawColorNumber;
		}
		else {
			drawCard4();
		}
		break;
	}
}


void placeCard4(int whichPile, int drawColorNumber)
{
	if (whichPile == 1) {
		if (counterPile1 != 0) {
			if (isPile1Usable != unusable) {
				for (int i = 0; i < 3; i++) {
					if (pile1[i] == 0) {
						pile1[i] = drawColorNumber;
						counterPile1--;
						isPile1Usable = canPutCard;
						break;
					}
				}
			}
			else {
				cout << "Row 1 has bee taken. Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place4();
				placeCard4(whichPile, drawColorNumber);
			}
		}
		else {
			isPile1Usable = full;
			cout << "Row 1 is already full. Please Choose another row to place your card:" << endl;
			int whichPile = choosePile_place4();
			placeCard4(whichPile, drawColorNumber);
		}
	}

	else if (whichPile == 2) {
		if (counterPile2 != 0) {
			if (isPile2Usable != unusable) {
				for (int i = 0; i < 3; i++) {
					if (pile2[i] == 0) {
						pile2[i] = drawColorNumber;
						counterPile2--;
						isPile2Usable = canPutCard;
						break;
					}
				}
			}
			else {
				cout << "Row 2 has bee taken, Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place4();
				placeCard4(whichPile, drawColorNumber);
			}
		}
		else {
			if (isPile2Usable = full) {
				cout << "Row 2 is already full. Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place4();
				placeCard4(whichPile, drawColorNumber);
			}
		}
	}

	else if (whichPile == 3) {
		if (counterPile3 != 0) {
			if (isPile3Usable != unusable) {
				for (int i = 0; i < 3; i++) {
					if (pile3[i] == 0) {
						pile3[i] = drawColorNumber;
						counterPile3--;
						isPile3Usable = canPutCard;
						break;
					}
				}
			}
			else {
				cout << "Row 3 has bee taken, Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place4();
				placeCard4(whichPile, drawColorNumber);
			}
		}
		else {
			cout << "Row 3 is already full. Please Choose another row to place your card:" << endl;
			int whichPile = choosePile_place4();
			placeCard4(whichPile, drawColorNumber);
		}
	}

	else if (whichPile == 4) {
		if (counterPile4 != 0) {
			if (isPile4Usable != unusable) {
				for (int i = 0; i < 3; i++) {
					if (pile4[i] == 0) {
						pile4[i] = drawColorNumber;
						counterPile4--;
						isPile4Usable = canPutCard;
						break;
					}
				}
			}
			else {
				cout << "Row 4 has bee taken, Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place4();
				placeCard4(whichPile, drawColorNumber);
			}
		}
		else {
			if (isPile4Usable = full) {
				cout << "Row 4 is already full. Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place4();
				placeCard4(whichPile, drawColorNumber);
			}
		}
	}
}

int choosePile_place4()
{
	cout << "Which row do you want to put your card:";
	int choose_a_pile_to_place;
	cin >> choose_a_pile_to_place;
	return choose_a_pile_to_place;
}

int choosePile_take4()
{
	cout << "Which row do you want to take back:";
	int choose_a_pile_to_take = 0;
	cin >> choose_a_pile_to_take;
	return choose_a_pile_to_take;
}

void userTakePile4(int whichPile)
{
	if (whichPile == 1 || whichPile == 2 || whichPile == 3 || whichPile == 4) {
		bool inputError = true;
		if (whichPile == 1) {
			if (isPile1Usable == canPutCard || isPile1Usable == full) {
				for (int i = 0; i < 3; i++) {
					userarray[pile1[i]]++;
					pile1[i] = 0;
				}
				isPile1Usable = unusable;
				userCanPlay = endplay;
			}
			else {
				cout << "Row 1 can not be taken for now. Please choose your move again:" << endl;
				while (inputError) {
					cout << "1:draw a card  2:take a row back   Please enter your choice of move:";
					int choice;
					cin >> choice;
					if (choice == 1) {
						int drawColorNumber = drawCard4();
						int whichPile = choosePile_place4();
						placeCard4(whichPile, drawColorNumber);
						inputError = false;
					}
					else if (choice == 2) {
						cout << "Which row do you want to take back:";
						int whichPile = choosePile_take4();
						userTakePile4(whichPile);
						inputError = false;
					}
					else {
						cout << "Input error please try again!" << endl;
					}
				}
			}
		}

		else if (whichPile == 2) {
			if (isPile2Usable == canPutCard || isPile2Usable == full) {
				for (int i = 0; i < 3; i++) {
					userarray[pile2[i]]++;
					pile2[i] = 0;
				}
				isPile2Usable = unusable;
				userCanPlay = endplay;
			}
			else {
				cout << "Row 2 can not be taken for now. Please choose your move again:" << endl;
				while (inputError) {
					cout << "1:draw a card  2:take a row back   Please enter your choice of move:";
					int choice;
					cin >> choice;
					if (choice == 1) {
						int drawColorNumber = drawCard4();
						int whichPile = choosePile_place4();
						placeCard4(whichPile, drawColorNumber);
						inputError = false;
					}
					else if (choice == 2) {
						cout << "Which row do you want to take back:";
						int whichPile = choosePile_take4();
						userTakePile4(whichPile);
						inputError = false;
					}
					else {
						cout << "Input error please try again!" << endl;
					}
				}
			}
		}

		else if (whichPile == 3) {
			if (isPile3Usable == canPutCard || isPile3Usable == full) {
				for (int i = 0; i < 3; i++) {
					userarray[pile3[i]]++;
					pile3[i] = 0;
				}
				isPile3Usable = unusable;
				userCanPlay = endplay;
			}
			else {
				cout << "Row 3 can not be taken for now. Please choose your move again:" << endl;
				while (inputError) {
					cout << "1:draw a card  2:take a row back   Please enter your choice of move:";
					int choice;
					cin >> choice;
					if (choice == 1) {
						int drawColorNumber = drawCard4();
						int whichPile = choosePile_place4();
						placeCard4(whichPile, drawColorNumber);
						inputError = false;
					}
					else if (choice == 2) {
						cout << "Which row do you want to take back:";
						int whichPile = choosePile_take4();
						userTakePile4(whichPile);
						inputError = false;
					}
					else {
						cout << "Input error please try again!" << endl;
					}
				}
			}
		}

		else if (whichPile == 4) {
			if (isPile4Usable == canPutCard || isPile4Usable == full) {
				for (int i = 0; i < 3; i++) {
					userarray[pile4[i]]++;
					pile4[i] = 0;
				}
				isPile4Usable = unusable;
				userCanPlay = endplay;
			}
			else {
				cout << "Row 4 can not be taken for now. Please choose your move again:" << endl;
				while (inputError) {
					cout << "1:draw a card  2:take a row back   Please enter your choice of move:";
					int choice;
					cin >> choice;
					if (choice == 1) {
						int drawColorNumber = drawCard4();
						int whichPile = choosePile_place4();
						placeCard4(whichPile, drawColorNumber);
						inputError = false;
					}
					else if (choice == 2) {
						cout << "Which row do you want to take back:";
						int whichPile = choosePile_take4();
						userTakePile4(whichPile);
						inputError = false;
					}
					else {
						cout << "Input error please try again!" << endl;
					}
				}
			}
		}
	}
	else {
		cout << "Input error please try again!" << endl;
		cout << "Which row do you want to take back:";
		int whichPile;
		cin >> whichPile;
		userTakePile4(whichPile);
	}
}


void userPlayTheGame4() // 玩家user的主要程式，包含user的所有選擇
{
	int userChoiceOfMove; //紀錄玩家選擇
	cout << "\n***Your round***" << endl;
	cout << "1:draw a card  2:take a row back   Please enter your choice of move:";

	do {
		cin >> userChoiceOfMove;

		if (userChoiceOfMove == 1) {
			int drawColorNumber = drawCard4();
			int whichPile = choosePile_place4();
			placeCard4(whichPile, drawColorNumber);
			showAllPlayerArray4();
			showPile4();
			break;
		}
		else if (userChoiceOfMove == 2) {
			int whichPile = choosePile_take4();
			userTakePile4(whichPile);
			showAllPlayerArray4();
			showPile4();
			break;
		}
		else {
			cout << "Input error please try again! 1:draw a card  2:take a row back   Please enter your choice of move:";
		}
	} while (userChoiceOfMove != 1 || userChoiceOfMove != 2);

	// 如果該輪還沒結束，則繼續進行，判斷下一位是誰能玩
	if (player1CanPlay == play) {
		player1PlayTheGame4();
	}
	else if (player2CanPlay == play) {
		player2PlayTheGame4();
	}
	else if (player3CanPlay == play) {
		player3PlayTheGame4();
	}
	else {
		if (userCanPlay == play) {
			userPlayTheGame4();
		}
		else {
			if (howManyCard4 <= 0) {
				CountPoint4();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				userPlayTheGame4();
			}
		}
	}
}


void player1PlayTheGame4()
{
	cout << "\n***Computer player1's round***" << endl;
	// 只要可收牌就收牌的機制
	if (isPile1Usable != noCard && isPile1Usable != unusable) {
		cout << "Computer player1 take back row 1" << endl;
		for (int i = 0; i < 3; i++) {
			player1array[pile1[i]]++;
			pile1[i] = 0;
		}
		isPile1Usable = unusable;
		player1CanPlay = endplay;
		showAllPlayerArray4();
		showPile4();
	}
	else if (isPile2Usable != noCard && isPile2Usable != unusable) {
		cout << "Computer player1 take back row 2" << endl;
		for (int i = 0; i < 3; i++) {
			player1array[pile2[i]]++;
			pile2[i] = 0;
		}
		isPile2Usable = unusable;
		player1CanPlay = endplay;
		showAllPlayerArray4();
		showPile4();
	}
	else if (isPile3Usable != noCard && isPile3Usable != unusable) {
		cout << "Computer player1 take back row 3" << endl;
		for (int i = 0; i < 3; i++) {
			player1array[pile3[i]]++;
			pile3[i] = 0;
		}
		isPile3Usable = unusable;
		player1CanPlay = endplay;
		showAllPlayerArray4();
		showPile4();
	}
	else if (isPile4Usable != noCard && isPile4Usable != unusable) {
		cout << "Computer player1 take back row 4" << endl;
		for (int i = 0; i < 3; i++) {
			player1array[pile4[i]]++;
			pile4[i] = 0;
		}
		isPile4Usable = unusable;
		player1CanPlay = endplay;
		showAllPlayerArray4();
		showPile4();
	}
	else { // 無法收牌，只能抽牌
		cout << "Computer player1 draw a card";
		int drawColorNumber = drawCard4();
		//判斷哪個行列能放牌
		if (isPile1Usable != unusable) {
			cout << "Put the card in row 1" << endl;
			pile1[0] = drawColorNumber;
			isPile1Usable = canPutCard;
			showAllPlayerArray4();
			showPile4();
		}
		else if (isPile2Usable != unusable) {
			cout << "Put the card in row 2" << endl;
			pile2[0] = drawColorNumber;
			isPile2Usable = canPutCard;
			showAllPlayerArray4();
			showPile4();
		}
		else if (isPile3Usable != unusable) {
			cout << "Put the card in row 3" << endl;
			pile3[0] = drawColorNumber;
			isPile3Usable = canPutCard;
			showAllPlayerArray4();
			showPile4();
		}
		else if (isPile4Usable != unusable) {
			cout << "Put the card in row 4" << endl;
			pile4[0] = drawColorNumber;
			isPile4Usable = canPutCard;
			showAllPlayerArray4();
			showPile4();
		}
	}

	// 如果該輪還沒結束，則繼續進行，判斷下一位是誰能玩
	if (player2CanPlay == play) {
		player2PlayTheGame4();
	}
	else if (player3CanPlay == play) {
		player3PlayTheGame4();
	}
	else if (userCanPlay == play) {
		userPlayTheGame4();
	}
	else {
		// 電腦如果是該輪最後一個人並且遊戲沒結束則強制收牌
		if (player1CanPlay == play) {
			if (isPile1Usable != noCard && isPile1Usable != unusable) {
				cout << "Computer player1 take back row 1" << endl;
				for (int i = 0; i < 3; i++) {
					player1array[pile1[i]]++;
					pile1[i] = 0;
				}
				player1CanPlay = endplay;
				isPile1Usable = unusable;
				showAllPlayerArray4();
				showPile4();
			}
			else if (isPile2Usable != noCard && isPile2Usable != unusable) {
				cout << "Computer player1 take back row 2" << endl;
				for (int i = 0; i < 3; i++) {
					player1array[pile2[i]]++;
					pile2[i] = 0;
				}
				player1CanPlay = endplay;
				isPile2Usable = unusable;
				showAllPlayerArray4();
				showPile4();
			}
			else if (isPile3Usable != noCard && isPile3Usable != unusable) {
				cout << "Computer player1 take back row 3" << endl;
				for (int i = 0; i < 3; i++) {
					player1array[pile3[i]]++;
					pile3[i] = 0;
				}
				player1CanPlay = endplay;
				isPile3Usable = unusable;
				showAllPlayerArray4();
				showPile4();
			}
			else if (isPile4Usable != noCard && isPile4Usable != unusable) {
				cout << "Computer player1 take back row 4" << endl;
				for (int i = 0; i < 3; i++) {
					player1array[pile4[i]]++;
					pile4[i] = 0;
				}
				player1CanPlay = endplay;
				isPile4Usable = unusable;
				showAllPlayerArray4();
				showPile4();
			}

			if (howManyCard4 <= 0) {
				CountPoint4();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				player1PlayTheGame4();
			}

		}
		// 所有人皆已完成操作，該輪結束
		else {
			if (howManyCard4 <= 0) {
				CountPoint4();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				player1PlayTheGame4();
			}
		}
	}
}


void player2PlayTheGame4()
{
	cout << "\n***Computer player2's round***" << endl;
	// 只要可收牌就收牌的機制
	if (isPile1Usable != noCard && isPile1Usable != unusable) {
		cout << "Computer player2 take back row 1" << endl;
		for (int i = 0; i < 3; i++) {
			player2array[pile1[i]]++;
			pile1[i] = 0;
		}
		isPile1Usable = unusable;
		player2CanPlay = endplay;
		showAllPlayerArray4();
		showPile4();
	}
	else if (isPile2Usable != noCard && isPile2Usable != unusable) {
		cout << "Computer player2 take back row 2" << endl;
		for (int i = 0; i < 3; i++) {
			player2array[pile2[i]]++;
			pile2[i] = 0;
		}
		isPile2Usable = unusable;
		player2CanPlay = endplay;
		showAllPlayerArray4();
		showPile4();
	}
	else if (isPile3Usable != noCard && isPile3Usable != unusable) {
		cout << "Computer player2 take back row 3" << endl;
		for (int i = 0; i < 3; i++) {
			player2array[pile3[i]]++;
			pile3[i] = 0;
		}
		isPile3Usable = unusable;
		player2CanPlay = endplay;
		showAllPlayerArray4();
		showPile4();
	}
	else if (isPile4Usable != noCard && isPile4Usable != unusable) {
		cout << "Computer player2 take back row 4" << endl;
		for (int i = 0; i < 3; i++) {
			player2array[pile4[i]]++;
			pile4[i] = 0;
		}
		isPile4Usable = unusable;
		player2CanPlay = endplay;
		showAllPlayerArray4();
		showPile4();
	}
	else { // 無法收牌，只能抽牌
		cout << "Computer player2 draw a card";
		int drawColorNumber = drawCard4();
		//判斷哪個行列能放牌
		if (isPile1Usable != unusable) {
			cout << "Put the card in row 1" << endl;
			pile1[0] = drawColorNumber;
			isPile1Usable = canPutCard;
			showAllPlayerArray4();
			showPile4();
		}
		else if (isPile2Usable != unusable) {
			cout << "Put the card in row 2" << endl;
			pile2[0] = drawColorNumber;
			isPile2Usable = canPutCard;
			showAllPlayerArray4();
			showPile4();
		}
		else if (isPile3Usable != unusable) {
			cout << "Put the card in row 3" << endl;
			pile3[0] = drawColorNumber;
			isPile3Usable = canPutCard;
			showAllPlayerArray4();
			showPile4();
		}
		else if (isPile4Usable != unusable) {
			cout << "Put the card in row 4" << endl;
			pile4[0] = drawColorNumber;
			isPile4Usable = canPutCard;
			showAllPlayerArray4();
			showPile4();
		}
	}

	// 如果該輪還沒結束，則繼續進行，判斷下一位是誰能玩
	if (player3CanPlay == play) {
		player3PlayTheGame4();
	}
	else if (userCanPlay == play) {
		userPlayTheGame4();
	}
	else if (player1CanPlay == play) {
		player1PlayTheGame4();
	}
	else {
		// 電腦如果是該輪最後一個人並且遊戲沒結束則強制收牌
		if (player2CanPlay == play) {
			if (isPile1Usable != unusable) {
				cout << "Computer player2 take back row 1" << endl;
				for (int i = 0; i < 3; i++) {
					player2array[pile1[i]]++;
					pile1[i] = 0;
				}
				player2CanPlay = endplay;
				isPile1Usable = unusable;
				showAllPlayerArray4();
				showPile4();
			}
			else if (isPile2Usable != unusable) {
				cout << "Computer player2 take back row 2" << endl;
				for (int i = 0; i < 3; i++) {
					player2array[pile2[i]]++;
					pile2[i] = 0;
				}
				player2CanPlay = endplay;
				isPile2Usable = unusable;
				showAllPlayerArray4();
				showPile4();
			}
			else if (isPile3Usable != unusable) {
				cout << "Computer player2 take back row 3" << endl;
				for (int i = 0; i < 3; i++) {
					player2array[pile3[i]]++;
					pile3[i] = 0;
				}
				player2CanPlay = endplay;
				isPile3Usable = unusable;
				showAllPlayerArray4();
				showPile4();
			}
			else if (isPile4Usable != unusable) {
				cout << "Computer player2 take back row 4" << endl;
				for (int i = 0; i < 3; i++) {
					player2array[pile4[i]]++;
					pile4[i] = 0;
				}
				player2CanPlay = endplay;
				isPile4Usable = unusable;
				showAllPlayerArray4();
				showPile4();
			}

			if (howManyCard4 <= 0) {
				CountPoint4();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				player2PlayTheGame4();
			}

		}
		// 所有人皆已完成操作，該輪結束
		else {
			if (howManyCard4 <= 0) {
				CountPoint4();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				player2PlayTheGame4();
			}
		}
	}
}


void player3PlayTheGame4()
{
	cout << "\n***Computer player3's round***" << endl;
	// 只要可收牌就收牌的機制
	if (isPile1Usable != unusable && isPile1Usable != noCard) {
		cout << "Computer player3 take back row 1" << endl;
		for (int i = 0; i < 3; i++) {
			player3array[pile1[i]]++;
			pile1[i] = 0;
		}
		isPile1Usable = unusable;
		player3CanPlay = endplay;
		showAllPlayerArray4();
		showPile4();
	}
	else if (isPile2Usable != unusable && isPile2Usable != noCard) {
		cout << "Computer player3 take back row 2" << endl;
		for (int i = 0; i < 3; i++) {
			player3array[pile2[i]]++;
			pile2[i] = 0;
		}
		isPile2Usable = unusable;
		player3CanPlay = endplay;
		showAllPlayerArray4();
		showPile4();
	}
	else if (isPile3Usable != unusable && isPile3Usable != noCard) {
		cout << "Computer player3 take back row 3" << endl;
		for (int i = 0; i < 3; i++) {
			player3array[pile3[i]]++;
			pile3[i] = 0;
		}
		isPile3Usable = unusable;
		player3CanPlay = endplay;
		showAllPlayerArray4();
		showPile4();
	}
	else if (isPile4Usable != unusable && isPile4Usable != noCard) {
		cout << "Computer player3 take back row 4" << endl;
		for (int i = 0; i < 3; i++) {
			player3array[pile4[i]]++;
			pile4[i] = 0;
		}
		isPile4Usable = unusable;
		player3CanPlay = endplay;
		showAllPlayerArray4();
		showPile4();
	}
	else {
		// 無法收牌，只能抽牌
		cout << "Computer player3 draw a card" << endl;
		int drawColorNumber = drawCard4();
		//判斷哪個行列能放牌
		if (isPile1Usable != unusable) {
			cout << "Put the card in row 1" << endl;
			pile1[0] = drawColorNumber;
			isPile1Usable = canPutCard;
			showAllPlayerArray4();
			showPile4();
		}
		else if (isPile2Usable != unusable) {
			cout << "Put the card in row 2" << endl;
			pile2[0] = drawColorNumber;
			isPile2Usable = canPutCard;
			showAllPlayerArray4();
			showPile4();
		}
		else if (isPile3Usable != unusable) {
			cout << "Put the card in row 3" << endl;
			pile3[0] = drawColorNumber;
			isPile3Usable = canPutCard;
			showAllPlayerArray4();
			showPile4();
		}
		else if (isPile4Usable != unusable) {
			cout << "Put the card in row 4" << endl;
			pile4[0] = drawColorNumber;
			isPile4Usable = canPutCard;
			showAllPlayerArray4();
			showPile4();
		}
	}

	// 如果該輪還沒結束，則繼續進行，判斷下一位是誰能玩
	if (userCanPlay == play) {
		userPlayTheGame4();
	}
	else if (player1CanPlay == play) {
		player1PlayTheGame4();
	}
	else if (player2CanPlay == play) {
		player2PlayTheGame4();
	}
	else {
		// 電腦如果是該輪最後一個人並且遊戲沒結束則強制收牌
		if (player3CanPlay == play) {
			if (isPile1Usable != unusable) {
				cout << "Computer player3 take back row 1" << endl;
				for (int i = 0; i < 3; i++) {
					player3array[pile1[i]]++;
					pile1[i] = 0;
				}
				player3CanPlay = endplay;
				isPile1Usable = unusable;
				showAllPlayerArray4();
				showPile4();
			}
			else if (isPile2Usable != unusable) {
				cout << "Computer player3 take back row 2" << endl;
				for (int i = 0; i < 3; i++) {
					player3array[pile2[i]]++;
					pile2[i] = 0;
				}
				player3CanPlay = endplay;
				isPile2Usable = unusable;
				showAllPlayerArray4();
				showPile4();
			}
			else if (isPile3Usable != unusable) {
				cout << "Computer player3 take back row 3" << endl;
				for (int i = 0; i < 3; i++) {
					player3array[pile3[i]]++;
					pile3[i] = 0;
				}
				player3CanPlay = endplay;
				isPile3Usable = unusable;
				showAllPlayerArray4();
				showPile4();
			}
			else if (isPile4Usable != unusable) {
				cout << "Computer player3 take back row 4" << endl;
				for (int i = 0; i < 3; i++) {
					player3array[pile4[i]]++;
					pile4[i] = 0;
				}
				player3CanPlay = endplay;
				isPile4Usable = unusable;
				showAllPlayerArray4();
				showPile4();
			}

			if (howManyCard4 <= 0) {
				CountPoint4();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				player3PlayTheGame4();
			}

		}
		// 所有人皆已完成操作，該輪結束
		else {
			if (howManyCard4 <= 0) {
				CountPoint4();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				player3PlayTheGame4();
			}
		}
	}
}


void CountPoint4()
{
	// 強制讓[0]位置為0
	userarray[0] = 0;
	player1array[0] = 0;
	player2array[0] = 0;
	player3array[0] = 0;

	// sort 排卡的數量
	sort(userarray, userarray + 8, cmp);
	sort(player1array, player1array + 8, cmp);
	sort(player2array, player2array + 8, cmp);
	sort(player3array, player3array + 8, cmp);

	// 彩色變色龍的最佳放法
	// user
	if (userarray[0] >= 6) {
		if (userarray[1] > 6) {
			for (int i = 0; i < userarray[8]; i++) {
				userarray[2]++;
			}
		}
		else {
			for (int i = 0; i < userarray[8]; i++) {
				userarray[1]++;
			}
		}
	}
	else {
		for (int i = 0; i < userarray[8]; i++) {
			userarray[0]++;
		}
	}

	// 電腦一
	if (player1array[1] >= 6) {
		if (player1array[2] > 6) {
			for (int i = 0; i < player1array[8]; i++) {
				player1array[3]++;
			}
		}
		else {
			for (int i = 0; i < player1array[8]; i++) {
				player1array[2]++;
			}
		}
	}
	else {
		for (int i = 0; i < player1array[8]; i++) {
			player1array[1]++;
		}
	}

	// 電腦二
	if (player2array[1] >= 6) {
		if (player2array[2] > 6) {
			for (int i = 0; i < player2array[8]; i++) {
				player2array[3]++;
			}
		}
		else {
			for (int i = 0; i < player2array[8]; i++) {
				player2array[2]++;
			}
		}
	}
	else {
		for (int i = 0; i < player2array[8]; i++) {
			player2array[1]++;
		}
	}

	// 電腦三
	if (player3array[1] >= 6) {
		if (player3array[2] > 6) {
			for (int i = 0; i < player3array[8]; i++) {
				player3array[3]++;
			}
		}
		else {
			for (int i = 0; i < player3array[8]; i++) {
				player3array[2]++;
			}
		}
	}
	else {
		for (int i = 0; i < player3array[8]; i++) {
			player3array[1]++;
		}
	}


	// 開始計算分數，用swich判斷每一個使用者陣列裡的數值
	// user牌由大到小
	int u1 = 0;
	int u2 = 0;
	int u3 = 0;
	int u4 = 0;
	int u5 = 0;
	int u6 = 0;
	int u7 = 0;

	switch (userarray[0]) // 最多的牌可拿幾分
	{
	case 6:
		u1 = 21;
		break;
	case 5:
		u1 = 15;
		break;
	case 4:
		u1 = 10;
		break;
	case 3:
		u1 = 6;
		break;
	case 2:
		u1 = 3;
		break;
	case 1:
		u1 = 1;
		break;
	case 0:
		u1 = 0;
		break;
	}

	switch (userarray[1]) // 第二多的牌可拿幾分
	{
	case 6:
		u2 = 21;
		break;
	case 5:
		u2 = 15;
		break;
	case 4:
		u2 = 10;
		break;
	case 3:
		u2 = 6;
		break;
	case 2:
		u2 = 3;
		break;
	case 1:
		u2 = 1;
		break;
	case 0:
		u2 = 0;
		break;
	}

	switch (userarray[2]) // 第三多的牌可拿幾分
	{
	case 6:
		u3 = 21;
		break;
	case 5:
		u3 = 15;
		break;
	case 4:
		u3 = 10;
		break;
	case 3:
		u3 = 6;
		break;
	case 2:
		u3 = 3;
		break;
	case 1:
		u3 = 1;
		break;
	case 0:
		u3 = 0;
		break;
	}

	switch (userarray[3]) // 第四多的牌可要扣幾分
	{
	case 6:
		u4 = -21;
		break;
	case 5:
		u4 = -15;
		break;
	case 4:
		u4 = -10;
		break;
	case 3:
		u4 = -6;
		break;
	case 2:
		u4 = -3;
		break;
	case 1:
		u4 = -1;
		break;
	case 0:
		u4 = 0;
		break;
	}

	switch (userarray[4]) // 第五多的牌可要扣幾分
	{
	case 6:
		u5 = -21;
		break;
	case 5:
		u5 = -15;
		break;
	case 4:
		u5 = -10;
		break;
	case 3:
		u5 = -6;
		break;
	case 2:
		u5 = -3;
		break;
	case 1:
		u5 = -1;
		break;
	case 0:
		u5 = 0;
		break;
	}

	switch (userarray[5]) // 第六多的牌可要扣幾分
	{
	case 6:
		u6 = -21;
		break;
	case 5:
		u6 = -15;
		break;
	case 4:
		u6 = -10;
		break;
	case 3:
		u6 = -6;
		break;
	case 2:
		u6 = -3;
		break;
	case 1:
		u6 = -1;
		break;
	case 0:
		u6 = 0;
		break;
	}

	switch (userarray[6]) // 第七多的牌可要扣幾分
	{
	case 6:
		u7 = -21;
		break;
	case 5:
		u7 = -15;
		break;
	case 4:
		u7 = -10;
		break;
	case 3:
		u7 = -6;
		break;
	case 2:
		u7 = -3;
		break;
	case 1:
		u7 = -1;
		break;
	case 0:
		u7 = 0;
		break;
	}

	int userTotalPoints = u1 + u2 + u3 + u4 + u5 + u6 + u7 + userarray[9] * 2;

	// 電腦一牌由大到小
	int p11 = 0;
	int p12 = 0;
	int p13 = 0;
	int p14 = 0;
	int p15 = 0;
	int p16 = 0;
	int p17 = 0;

	switch (player1array[0]) // 最多的牌可拿幾分
	{
	case 6:
		p11 = 21;
		break;
	case 5:
		p11 = 15;
		break;
	case 4:
		p11 = 10;
		break;
	case 3:
		p11 = 6;
		break;
	case 2:
		p11 = 3;
		break;
	case 1:
		p11 = 1;
		break;
	case 0:
		p11 = 0;
		break;
	}

	switch (player1array[1]) // 第二多的牌可拿幾分
	{
	case 6:
		p12 = 21;
		break;
	case 5:
		p12 = 15;
		break;
	case 4:
		p12 = 10;
		break;
	case 3:
		p12 = 6;
		break;
	case 2:
		p12 = 3;
		break;
	case 1:
		p12 = 1;
		break;
	case 0:
		p12 = 0;
		break;
	}

	switch (player1array[2]) // 第三多的牌可拿幾分
	{
	case 6:
		p13 = 21;
		break;
	case 5:
		p13 = 15;
		break;
	case 4:
		p13 = 10;
		break;
	case 3:
		p13 = 6;
		break;
	case 2:
		p13 = 3;
		break;
	case 1:
		p13 = 1;
		break;
	case 0:
		p13 = 0;
		break;
	}

	switch (player1array[3]) // 第四多的牌可要扣幾分
	{
	case 6:
		p14 = -21;
		break;
	case 5:
		p14 = -15;
		break;
	case 4:
		p14 = -10;
		break;
	case 3:
		p14 = -6;
		break;
	case 2:
		p14 = -3;
		break;
	case 1:
		p14 = -1;
		break;
	case 0:
		p14 = 0;
		break;
	}

	switch (player1array[4]) // 第五多的牌可要扣幾分
	{
	case 6:
		p15 = -21;
		break;
	case 5:
		p15 = -15;
		break;
	case 4:
		p15 = -10;
		break;
	case 3:
		p15 = -6;
		break;
	case 2:
		p15 = -3;
		break;
	case 1:
		p15 = -1;
		break;
	case 0:
		p15 = 0;
		break;
	}

	switch (player1array[5]) // 第六多的牌可要扣幾分
	{
	case 6:
		p16 = -21;
		break;
	case 5:
		p16 = -15;
		break;
	case 4:
		p16 = -10;
		break;
	case 3:
		p16 = -6;
		break;
	case 2:
		p16 = -3;
		break;
	case 1:
		p16 = -1;
		break;
	case 0:
		p16 = 0;
		break;
	}

	switch (player1array[6]) // 第七多的牌可要扣幾分
	{
	case 6:
		p17 = -21;
		break;
	case 5:
		p17 = -15;
		break;
	case 4:
		p17 = -10;
		break;
	case 3:
		p17 = -6;
		break;
	case 2:
		p17 = -3;
		break;
	case 1:
		p17 = -1;
		break;
	case 0:
		p17 = 0;
		break;
	}

	int player1TotalPoints = p11 + p12 + p13 + p14 + p15 + p16 + p17 + player1array[9] * 2;

	// 電腦二牌由大到小
	int p21 = 0;
	int p22 = 0;
	int p23 = 0;
	int p24 = 0;
	int p25 = 0;
	int p26 = 0;
	int p27 = 0;

	switch (player2array[0]) // 最多的牌可拿幾分
	{
	case 6:
		p21 = 21;
		break;
	case 5:
		p21 = 15;
		break;
	case 4:
		p21 = 10;
		break;
	case 3:
		p21 = 6;
		break;
	case 2:
		p21 = 3;
		break;
	case 1:
		p21 = 1;
		break;
	case 0:
		p21 = 0;
		break;
	}

	switch (player2array[1]) // 第二多的牌可拿幾分
	{
	case 6:
		p22 = 21;
		break;
	case 5:
		p22 = 15;
		break;
	case 4:
		p22 = 10;
		break;
	case 3:
		p22 = 6;
		break;
	case 2:
		p22 = 3;
		break;
	case 1:
		p22 = 1;
		break;
	case 0:
		p22 = 0;
		break;
	}

	switch (player2array[2]) // 第三多的牌可拿幾分
	{
	case 6:
		p23 = 21;
		break;
	case 5:
		p23 = 15;
		break;
	case 4:
		p23 = 10;
		break;
	case 3:
		p23 = 6;
		break;
	case 2:
		p23 = 3;
		break;
	case 1:
		p23 = 1;
		break;
	case 0:
		p23 = 0;
		break;
	}

	switch (player2array[3]) // 第四多的牌可要扣幾分
	{
	case 6:
		p24 = -21;
		break;
	case 5:
		p24 = -15;
		break;
	case 4:
		p24 = -10;
		break;
	case 3:
		p24 = -6;
		break;
	case 2:
		p24 = -3;
		break;
	case 1:
		p24 = -1;
		break;
	case 0:
		p24 = 0;
		break;
	}

	switch (player2array[4]) // 第五多的牌可要扣幾分
	{
	case 6:
		p25 = -21;
		break;
	case 5:
		p25 = -15;
		break;
	case 4:
		p25 = -10;
		break;
	case 3:
		p25 = -6;
		break;
	case 2:
		p25 = -3;
		break;
	case 1:
		p25 = -1;
		break;
	case 0:
		p25 = 0;
		break;
	}

	switch (player2array[5]) // 第六多的牌可要扣幾分
	{
	case 6:
		p26 = -21;
		break;
	case 5:
		p26 = -15;
		break;
	case 4:
		p26 = -10;
		break;
	case 3:
		p26 = -6;
		break;
	case 2:
		p26 = -3;
		break;
	case 1:
		p26 = -1;
		break;
	case 0:
		p26 = 0;
		break;
	}

	switch (player2array[6]) // 第七多的牌可要扣幾分
	{
	case 6:
		p27 = -21;
		break;
	case 5:
		p27 = -15;
		break;
	case 4:
		p27 = -10;
		break;
	case 3:
		p27 = -6;
		break;
	case 2:
		p27 = -3;
		break;
	case 1:
		p27 = -1;
		break;
	case 0:
		p27 = 0;
		break;
	}

	int player2TotalPoints = p21 + p22 + p23 + p24 + p25 + p26 + p27 + player2array[9] * 2;


	int p31 = 0;
	int p32 = 0;
	int p33 = 0;
	int p34 = 0;
	int p35 = 0;
	int p36 = 0;
	int p37 = 0; // 電腦三牌由大到小

	switch (player3array[0]) // 最多的牌可拿幾分
	{
	case 6:
		p31 = 21;
		break;
	case 5:
		p31 = 15;
		break;
	case 4:
		p31 = 10;
		break;
	case 3:
		p31 = 6;
		break;
	case 2:
		p31 = 3;
		break;
	case 1:
		p31 = 1;
		break;
	case 0:
		p31 = 0;
		break;
	}

	switch (player3array[1]) // 第二多的牌可拿幾分
	{
	case 6:
		p32 = 21;
		break;
	case 5:
		p32 = 15;
		break;
	case 4:
		p32 = 10;
		break;
	case 3:
		p32 = 6;
		break;
	case 2:
		p32 = 3;
		break;
	case 1:
		p32 = 1;
		break;
	case 0:
		p32 = 0;
		break;
	}

	switch (player3array[2]) // 第三多的牌可拿幾分
	{
	case 6:
		p33 = 21;
		break;
	case 5:
		p33 = 15;
		break;
	case 4:
		p33 = 10;
		break;
	case 3:
		p33 = 6;
		break;
	case 2:
		p33 = 3;
		break;
	case 1:
		p33 = 1;
		break;
	case 0:
		p33 = 0;
		break;
	}

	switch (player3array[3]) // 第四多的牌可要扣幾分
	{
	case 6:
		p34 = -21;
		break;
	case 5:
		p34 = -15;
		break;
	case 4:
		p34 = -10;
		break;
	case 3:
		p34 = -6;
		break;
	case 2:
		p34 = -3;
		break;
	case 1:
		p34 = -1;
		break;
	case 0:
		p34 = 0;
		break;
	}

	switch (player3array[4]) // 第五多的牌可要扣幾分
	{
	case 6:
		p35 = -21;
		break;
	case 5:
		p35 = -15;
		break;
	case 4:
		p35 = -10;
		break;
	case 3:
		p35 = -6;
		break;
	case 2:
		p35 = -3;
		break;
	case 1:
		p35 = -1;
		break;
	case 0:
		p35 = 0;
		break;
	}

	switch (player3array[5]) // 第六多的牌可要扣幾分
	{
	case 6:
		p36 = -21;
		break;
	case 5:
		p36 = -15;
		break;
	case 4:
		p36 = -10;
		break;
	case 3:
		p36 = -6;
		break;
	case 2:
		p36 = -3;
		break;
	case 1:
		p36 = -1;
		break;
	case 0:
		p36 = 0;
		break;
	}

	switch (player3array[6]) // 第七多的牌可要扣幾分
	{
	case 6:
		p37 = -21;
		break;
	case 5:
		p37 = -15;
		break;
	case 4:
		p37 = -10;
		break;
	case 3:
		p37 = -6;
		break;
	case 2:
		p37 = -3;
		break;
	case 1:
		p37 = -1;
		break;
	case 0:
		p37 = 0;
		break;
	}

	int player3TotalPoints = p31 + p32 + p33 + p34 + p35 + p36 + p37 + player2array[9] * 2;

	cout << "\nThe points you get:" << userTotalPoints << endl;
	cout << "The points computer player1 gets:" << player1TotalPoints << endl;
	cout << "The points computer player2 gets:" << player2TotalPoints << endl;
	cout << "The points computer player3 gets:" << player3TotalPoints << endl;
}


void playerSetUp5()
{
	// 初始化所有玩家狀態=可玩，行列狀態=沒有牌，可放牌
	isPile1Usable = noCard;
	isPile2Usable = noCard;
	isPile3Usable = noCard;
	isPile4Usable = noCard;
	userCanPlay = play;
	player1CanPlay = play;
	player2CanPlay = play;
	player3CanPlay = play;

	playerColor5(); // 每個玩家的初始變色龍顏色
	showPile5(); // 卡堆初始情況 
	userPlayTheGame5();
}


void playerColor5()
{
	int userInitialColor = 0;
	int player1InitialColor = 0;
	int player2IntialColor = 0;
	int player3IntialColor = 0;
	int player4IntialColor = 0;

	do {
		srand(time(NULL));
		userInitialColor = rand() % 7 + 1;
		player1InitialColor = rand() % 7 + 1;
		player2IntialColor = rand() % 7 + 1;
		player3IntialColor = rand() % 7 + 1;
		player4IntialColor = rand() % 7 + 1;
	} while (userInitialColor == player1InitialColor || userInitialColor == player2IntialColor || userInitialColor == player3IntialColor || userInitialColor == player4IntialColor || player1InitialColor == player2IntialColor ||
		player1InitialColor == player3IntialColor || player1InitialColor == player4IntialColor || player2IntialColor == player3IntialColor || player2IntialColor == player4IntialColor || player3IntialColor == player4IntialColor);

	switch (userInitialColor) // 玩家user的第一隻變色龍顏色，存進玩家的array
	{
	case 1:
		userarray[1]++;
		redCard--;
		howManyCard5--;
		break;
	case 2:
		userarray[2]++;
		pinkCard--;
		howManyCard5--;
		break;
	case 3:
		userarray[3]++;
		yellowCard--;
		howManyCard5--;
		break;
	case 4:
		userarray[4]++;
		orangeCard--;
		howManyCard5--;
		break;
	case 5:
		userarray[5]++;
		blueCard--;
		howManyCard5--;
		break;
	case 6:
		userarray[6]++;
		greenCard--;
		howManyCard5--;
		break;
	case 7:
		userarray[7]++;
		grayCard--;
		howManyCard5--;
		break;
	}

	switch (player1InitialColor) //電腦1顏色，存進電腦1的array
	{
	case 1:
		player1array[1]++;
		redCard--;
		howManyCard5--;
		break;
	case 2:
		player1array[2]++;
		pinkCard--;
		howManyCard5--;
		break;
	case 3:
		player1array[3]++;
		yellowCard--;
		howManyCard5--;
		break;
	case 4:
		player1array[4]++;
		orangeCard--;
		howManyCard5--;
		break;
	case 5:
		player1array[5]++;
		blueCard--;
		howManyCard5--;
		break;
	case 6:
		player1array[6]++;
		greenCard--;
		howManyCard5--;
		break;
	case 7:
		player1array[7]++;
		grayCard--;
		howManyCard5--;
		break;
	}

	switch (player2IntialColor) //電腦2顏色
	{
	case 1:
		player2array[1]++;
		redCard--;
		howManyCard5--;
		break;
	case 2:
		player2array[2]++;
		pinkCard--;
		howManyCard5--;
		break;
	case 3:
		player2array[3]++;
		yellowCard--;
		howManyCard5--;
		break;
	case 4:
		player2array[4]++;
		orangeCard--;
		howManyCard5--;
		break;
	case 5:
		player2array[5]++;
		blueCard--;
		howManyCard5--;
		break;
	case 6:
		player2array[6]++;
		greenCard--;
		howManyCard5--;
		break;
	case 7:
		player2array[7]++;
		grayCard--;
		howManyCard5--;
		break;
	}

	switch (player3IntialColor)// 電腦3顏色
	{
	case 1:
		player3array[1]++;
		redCard--;
		howManyCard5--;
		break;
	case 2:
		player3array[2]++;
		pinkCard--;
		howManyCard5--;
		break;
	case 3:
		player3array[3]++;
		yellowCard--;
		howManyCard5--;
		break;
	case 4:
		player3array[4]++;
		orangeCard--;
		howManyCard5--;
		break;
	case 5:
		player3array[5]++;
		blueCard--;
		howManyCard5--;
		break;
	case 6:
		player3array[6]++;
		greenCard--;
		howManyCard5--;
		break;
	case 7:
		player3array[7]++;
		grayCard--;
		howManyCard5--;
		break;
	}

	switch (player4IntialColor)// 電腦4顏色
	{
	case 1:
		player4array[1]++;
		redCard--;
		howManyCard5--;
		break;
	case 2:
		player4array[2]++;
		pinkCard--;
		howManyCard5--;
		break;
	case 3:
		player4array[3]++;
		yellowCard--;
		howManyCard5--;
		break;
	case 4:
		player4array[4]++;
		orangeCard--;
		howManyCard5--;
		break;
	case 5:
		player4array[5]++;
		blueCard--;
		howManyCard5--;
		break;
	case 6:
		player4array[6]++;
		greenCard--;
		howManyCard5--;
		break;
	case 7:
		player4array[7]++;
		grayCard--;
		howManyCard5--;
		break;
	}

	showAllPlayerArray5();
}


void showAllPlayerArray5() //顯示玩家user手牌
{
	cout << endl;
	cout << "All players' card:" << endl;
	cout << "Your card {Red:" << userarray[1] << " Pink:" << userarray[2] << " Yellow:" << userarray[3] << " Orange:" << userarray[4] << " Blue：" << userarray[5] <<
		" Green:" << userarray[6] << " Gray:" << userarray[7] << " Rainbow:" << userarray[8] << " +2:" << userarray[9] << "}" << endl << endl;

	cout << "Computer player1's card {Red:" << player1array[1] << " Pink:" << player1array[2] << " Yellow:" << player1array[3] << " Orange:" << player1array[4] << " Blue：" << player1array[5] <<
		" Green:" << player1array[6] << " Gray:" << player1array[7] << " Rainbow:" << player1array[8] << " +2:" << player1array[9] << "}" << endl << endl;

	cout << "Computer player2's card {Red:" << player2array[1] << " Pink:" << player2array[2] << " Yellow:" << player2array[3] << " Orange:" << player2array[4] << " Blue：" << player2array[5] <<
		" Green:" << player2array[6] << " Gray:" << player2array[7] << " Rainbow:" << player2array[8] << " +2:" << player2array[9] << "}" << endl << endl;

	cout << "Computer player3's card {Red:" << player3array[1] << " Pink:" << player3array[2] << " Yellow:" << player3array[3] << " Orange:" << player3array[4] << " Blue：" << player3array[5] <<
		" Green:" << player3array[6] << " Gray:" << player3array[7] << " Rainbow:" << player3array[8] << " +2:" << player3array[9] << "}" << endl << endl;

	cout << "Computer player4's card {Red:" << player4array[1] << " Pink:" << player4array[2] << " Yellow:" << player4array[3] << " Orange:" << player4array[4] << " Blue：" << player4array[5] <<
		" Green:" << player4array[6] << " Gray:" << player4array[7] << " Rainbow:" << player4array[8] << " +2:" << player4array[9] << "}" << endl << endl;
}

void showPile5()
{
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Card set up   0:no card 1:Red 2:Pink 3:Yellow 4:Orange 5:Blue 6:Green 7:Gray 8:Rainbow 9:+2" << endl;
	cout << "Row 1 { "; // 輸出行列一內的牌
	for (int i = 0; i < 3; i++) {
		cout << pile1[i] << " ";
	}
	cout << "}" << endl;

	cout << "Row 2 { "; // 輸出行列二內的牌
	for (int i = 0; i < 3; i++) {
		cout << pile2[i] << " ";
	}
	cout << "}" << endl;

	cout << "Row 3 { "; // 輸出行列三內的牌
	for (int i = 0; i < 3; i++) {
		cout << pile3[i] << " ";
	}
	cout << "}" << endl;

	cout << "Row 4 { "; // 輸出行列四內的牌
	for (int i = 0; i < 3; i++) {
		cout << pile4[i] << " ";
	}
	cout << "}" << endl;

	cout << "Row 5 { "; // 輸出行列四內的牌
	for (int i = 0; i < 3; i++) {
		cout << pile5[i] << " ";
	}
	cout << "}" << endl;

	cout << "-------------------------------------------------------------------------------------------------------------" << endl;
}


int drawCard5()
{
	srand(time(NULL));
	int drawColorNumber = rand() % 9 + 1;

	switch (drawColorNumber)
	{
	case 1:
		// 卡顏色為紅色
		if (redCard != 0) {
			cout << "\nGet a red card\n";
			howManyCard5--;
			redCard--;
			return drawColorNumber;
		}
		else {
			drawCard5();
		}
		break;
	case 2:
		// 卡顏色為粉色
		if (pinkCard != 0) {
			cout << "\nGet a pink card\n";
			howManyCard5--;
			pinkCard--;
			return drawColorNumber;
		}
		else {
			drawCard5();
		}
		break;
	case 3:
		// 卡顏色為黃色
		if (yellowCard != 0) {
			cout << "\nGet a yellow card\n";
			howManyCard5--;
			yellowCard--;
			return drawColorNumber;
		}
		else {
			drawCard5();
		}
		break;
	case 4:
		// 卡顏色為橘色
		if (orangeCard != 0) {
			cout << "\nGet a orange card\n";
			howManyCard5--;
			orangeCard--;
			return drawColorNumber;
		}
		else {
			drawCard5();
		}
		break;
	case 5:
		// 卡顏色為藍色
		if (blueCard != 0) {
			cout << "\nGet a blue card\n";
			howManyCard5--;
			blueCard--;
			return drawColorNumber;
		}
		else {
			drawCard5();
		}
		break;
	case 6:
		// 卡顏色為綠色
		if (greenCard != 0) {
			cout << "\nGet a green card\n";
			howManyCard5--;
			greenCard--;
			return drawColorNumber;
		}
		else {
			drawCard5();
		}
		break;
	case 7:
		// 卡顏色為灰色
		if (grayCard != 0) {
			cout << "\nGet a gray card\n";
			howManyCard5--;
			grayCard--;
			return drawColorNumber;
		}
		else {
			drawCard5();
		}
		break;
	case 8:
		// 卡顏色為彩色
		if (colorfulCard != 0) {
			cout << "\nGet a rainbow card\n";
			howManyCard5--;
			colorfulCard--;
			return drawColorNumber;
		}
		else {
			drawCard5();
		}
		break;
	case 9:
		// +2卡
		if (plus2Card != 0) {
			cout << "\nGet a +2 card\n";
			howManyCard5--;
			plus2Card--;
			return drawColorNumber;
		}
		else {
			drawCard5();
		}
		break;
	}
}


void placeCard5(int whichPile, int drawColorNumber)
{
	if (whichPile == 1) {
		if (counterPile1 != 0) {
			if (isPile1Usable != unusable) {
				for (int i = 0; i < 3; i++) {
					if (pile1[i] == 0) {
						pile1[i] = drawColorNumber;
						counterPile1--;
						isPile1Usable = canPutCard;
						break;
					}
				}
			}
			else {
				cout << "Row 1 has bee taken. Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place5();
				placeCard5(whichPile, drawColorNumber);
			}
		}
		else {
			isPile1Usable = full;
			cout << "Row 1 is already full. Please Choose another row to place your card:" << endl;
			int whichPile = choosePile_place5();
			placeCard5(whichPile, drawColorNumber);
		}
	}

	else if (whichPile == 2) {
		if (counterPile2 != 0) {
			if (isPile2Usable != unusable) {
				for (int i = 0; i < 3; i++) {
					if (pile2[i] == 0) {
						pile2[i] = drawColorNumber;
						counterPile2--;
						isPile2Usable = canPutCard;
						break;
					}
				}
			}
			else {
				cout << "Row 2 has bee taken, Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place5();
				placeCard5(whichPile, drawColorNumber);
			}
		}
		else {
			if (isPile2Usable = full) {
				cout << "Row 2 is already full. Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place5();
				placeCard5(whichPile, drawColorNumber);
			}
		}
	}

	else if (whichPile == 3) {
		if (counterPile3 != 0) {
			if (isPile3Usable != unusable) {
				for (int i = 0; i < 3; i++) {
					if (pile3[i] == 0) {
						pile3[i] = drawColorNumber;
						counterPile3--;
						isPile3Usable = canPutCard;
						break;
					}
				}
			}
			else {
				cout << "Row 3 has bee taken, Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place5();
				placeCard5(whichPile, drawColorNumber);
			}
		}
		else {
			cout << "Row 3 is already full. Please Choose another row to place your card:" << endl;
			int whichPile = choosePile_place5();
			placeCard5(whichPile, drawColorNumber);
		}
	}

	else if (whichPile == 4) {
		if (counterPile4 != 0) {
			if (isPile4Usable != unusable) {
				for (int i = 0; i < 3; i++) {
					if (pile4[i] == 0) {
						pile4[i] = drawColorNumber;
						counterPile4--;
						isPile4Usable = canPutCard;
						break;
					}
				}
			}
			else {
				cout << "Row 4 has bee taken, Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place5();
				placeCard5(whichPile, drawColorNumber);
			}
		}
		else {
			if (isPile4Usable = full) {
				cout << "Row 4 is already full. Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place5();
				placeCard5(whichPile, drawColorNumber);
			}
		}
	}

	else if (whichPile == 5) {
		if (counterPile5 != 0) {
			if (isPile5Usable != unusable) {
				for (int i = 0; i < 3; i++) {
					if (pile5[i] == 0) {
						pile5[i] = drawColorNumber;
						counterPile5--;
						isPile5Usable = canPutCard;
						break;
					}
				}
			}
			else {
				cout << "Row 5 has bee taken, Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place5();
				placeCard5(whichPile, drawColorNumber);
			}
		}
		else {
			if (isPile5Usable = full) {
				cout << "Row 5 is already full. Please Choose another row to place your card:" << endl;
				int whichPile = choosePile_place5();
				placeCard5(whichPile, drawColorNumber);
			}
		}
	}
}

int choosePile_place5()
{
	cout << "Which row do you want to put your card:";
	int choose_a_pile_to_place;
	cin >> choose_a_pile_to_place;
	return choose_a_pile_to_place;
}

int choosePile_take5()
{
	cout << "Which row do you want to take back:";
	int choose_a_pile_to_take = 0;
	cin >> choose_a_pile_to_take;
	return choose_a_pile_to_take;
}


void userTakePile5(int whichPile)
{
	if (whichPile == 1 || whichPile == 2 || whichPile == 3 || whichPile == 4 || whichPile == 5) {
		bool inputError = true;
		if (whichPile == 1) {
			if (isPile1Usable == canPutCard || isPile1Usable == full) {
				for (int i = 0; i < 3; i++) {
					userarray[pile1[i]]++;
					pile1[i] = 0;
				}
				isPile1Usable = unusable;
				userCanPlay = endplay;
			}
			else {
				cout << "Row 1 can not be taken for now. Please choose your move again:" << endl;
				while (inputError) {
					cout << "1:draw a card  2:take a row back   Please enter your choice of move:";
					int choice;
					cin >> choice;
					if (choice == 1) {
						int drawColorNumber = drawCard5();
						int whichPile = choosePile_place5();
						placeCard5(whichPile, drawColorNumber);
						inputError = false;
					}
					else if (choice == 2) {
						cout << "Which row do you want to take back:";
						int whichPile = choosePile_take5();
						userTakePile5(whichPile);
						inputError = false;
					}
					else {
						cout << "Input error please try again!" << endl;
					}
				}
			}
		}

		else if (whichPile == 2) {
			if (isPile2Usable == canPutCard || isPile2Usable == full) {
				for (int i = 0; i < 3; i++) {
					userarray[pile2[i]]++;
					pile2[i] = 0;
				}
				isPile2Usable = unusable;
				userCanPlay = endplay;
			}
			else {
				cout << "Row 2 can not be taken for now. Please choose your move again:" << endl;
				while (inputError) {
					cout << "1:draw a card  2:take a row back   Please enter your choice of move:";
					int choice;
					cin >> choice;
					if (choice == 1) {
						int drawColorNumber = drawCard5();
						int whichPile = choosePile_place5();
						placeCard5(whichPile, drawColorNumber);
						inputError = false;
					}
					else if (choice == 2) {
						cout << "Which row do you want to take back:";
						int whichPile = choosePile_take5();
						userTakePile5(whichPile);
						inputError = false;
					}
					else {
						cout << "Input error please try again!" << endl;
					}
				}
			}
		}

		else if (whichPile == 3) {
			if (isPile3Usable == canPutCard || isPile3Usable == full) {
				for (int i = 0; i < 3; i++) {
					userarray[pile3[i]]++;
					pile3[i] = 0;
				}
				isPile3Usable = unusable;
				userCanPlay = endplay;
			}
			else {
				cout << "Row 3 can not be taken for now. Please choose your move again:" << endl;
				while (inputError) {
					cout << "1:draw a card  2:take a row back   Please enter your choice of move:";
					int choice;
					cin >> choice;
					if (choice == 1) {
						int drawColorNumber = drawCard5();
						int whichPile = choosePile_place5();
						placeCard5(whichPile, drawColorNumber);
						inputError = false;
					}
					else if (choice == 2) {
						cout << "Which row do you want to take back:";
						int whichPile = choosePile_take5();
						userTakePile5(whichPile);
						inputError = false;
					}
					else {
						cout << "Input error please try again!" << endl;
					}
				}
			}
		}

		else if (whichPile == 4) {
			if (isPile4Usable == canPutCard || isPile4Usable == full) {
				for (int i = 0; i < 3; i++) {
					userarray[pile4[i]]++;
					pile4[i] = 0;
				}
				isPile4Usable = unusable;
				userCanPlay = endplay;
			}
			else {
				cout << "Row 4 can not be taken for now. Please choose your move again:" << endl;
				while (inputError) {
					cout << "1:draw a card  2:take a row back   Please enter your choice of move:";
					int choice;
					cin >> choice;
					if (choice == 1) {
						int drawColorNumber = drawCard5();
						int whichPile = choosePile_place5();
						placeCard5(whichPile, drawColorNumber);
						inputError = false;
					}
					else if (choice == 2) {
						cout << "Which row do you want to take back:";
						int whichPile = choosePile_take5();
						userTakePile5(whichPile);
						inputError = false;
					}
					else {
						cout << "Input error please try again!" << endl;
					}
				}
			}
		}

		else if (whichPile == 5) {
			if (isPile5Usable == canPutCard || isPile5Usable == full) {
				for (int i = 0; i < 3; i++) {
					userarray[pile5[i]]++;
					pile5[i] = 0;
				}
				isPile5Usable = unusable;
				userCanPlay = endplay;
			}
			else {
				cout << "Row 5 can not be taken for now. Please choose your move again:" << endl;
				while (inputError) {
					cout << "1:draw a card  2:take a row back   Please enter your choice of move:";
					int choice;
					cin >> choice;
					if (choice == 1) {
						int drawColorNumber = drawCard5();
						int whichPile = choosePile_place5();
						placeCard5(whichPile, drawColorNumber);
						inputError = false;
					}
					else if (choice == 2) {
						cout << "Which row do you want to take back:";
						int whichPile = choosePile_take5();
						userTakePile5(whichPile);
						inputError = false;
					}
					else {
						cout << "Input error please try again!" << endl;
					}
				}
			}
		}
	}

	else {
		cout << "Input error please try again!" << endl;
		cout << "Which row do you want to take back:";
		int whichPile;
		cin >> whichPile;
		userTakePile5(whichPile);
	}
}


void userPlayTheGame5() // 玩家user的主要程式，包含user的所有選擇
{
	int userChoiceOfMove; //紀錄玩家選擇
	cout << "\n***Your round***" << endl;
	cout << "1:draw a card  2:take a row back   Please enter your choice of move:";

	do {
		cin >> userChoiceOfMove;

		if (userChoiceOfMove == 1) {
			int drawColorNumber = drawCard5();
			int whichPile = choosePile_place5();
			placeCard5(whichPile, drawColorNumber);
			showAllPlayerArray5();
			showPile5();
			break;
		}
		else if (userChoiceOfMove == 2) {
			int whichPile = choosePile_take5();
			userTakePile5(whichPile);
			showAllPlayerArray5();
			showPile5();
			break;
		}
		else {
			cout << "Input error please try again! 1:draw a card  2:take a row back   Please enter your choice of move:";
		}
	} while (userChoiceOfMove != 1 || userChoiceOfMove != 2);

	// 如果該輪還沒結束，則繼續進行，判斷下一位是誰能玩
	if (player1CanPlay == play) {
		player1PlayTheGame5();
	}
	else if (player2CanPlay == play) {
		player2PlayTheGame5();
	}
	else if (player3CanPlay == play) {
		player3PlayTheGame5();
	}
	else if (player4CanPlay == play) {
		player4PlayTheGame5();
	}
	else {
		if (userCanPlay == play) {
			userPlayTheGame5();
		}
		else {
			if (howManyCard5 <= 0) {
				CountPoint5();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				player4CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				isPile5Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				counterPile5 = 3;
				userPlayTheGame5();
			}
		}
	}
}


void player1PlayTheGame5()
{
	cout << "\n***Computer player1's round***" << endl;
	// 只要可收牌就收牌的機制
	if (isPile1Usable != noCard && isPile1Usable != unusable) {
		cout << "Computer player1 take back row 1" << endl;
		for (int i = 0; i < 3; i++) {
			player1array[pile1[i]]++;
			pile1[i] = 0;
		}
		isPile1Usable = unusable;
		player1CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile2Usable != noCard && isPile2Usable != unusable) {
		cout << "Computer player1 take back row 2" << endl;
		for (int i = 0; i < 3; i++) {
			player1array[pile2[i]]++;
			pile2[i] = 0;
		}
		isPile2Usable = unusable;
		player1CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile3Usable != noCard && isPile3Usable != unusable) {
		cout << "Computer player1 take back row 3" << endl;
		for (int i = 0; i < 3; i++) {
			player1array[pile3[i]]++;
			pile3[i] = 0;
		}
		isPile3Usable = unusable;
		player1CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile4Usable != noCard && isPile4Usable != unusable) {
		cout << "Computer player1 take back row 4" << endl;
		for (int i = 0; i < 3; i++) {
			player1array[pile4[i]]++;
			pile4[i] = 0;
		}
		isPile4Usable = unusable;
		player1CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile5Usable != noCard && isPile5Usable != unusable) {
		cout << "Computer player1 take back row 5" << endl;
		for (int i = 0; i < 3; i++) {
			player1array[pile5[i]]++;
			pile5[i] = 0;
		}
		isPile5Usable = unusable;
		player1CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else { // 無法收牌，只能抽牌
		cout << "Computer player1 draw a card";
		int drawColorNumber = drawCard5();
		//判斷哪個行列能放牌
		if (isPile1Usable != unusable) {
			cout << "Put the card in row 1" << endl;
			pile1[0] = drawColorNumber;
			isPile1Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile2Usable != unusable) {
			cout << "Put the card in row 2" << endl;
			pile2[0] = drawColorNumber;
			isPile2Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile3Usable != unusable) {
			cout << "Put the card in row 3" << endl;
			pile3[0] = drawColorNumber;
			isPile3Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile4Usable != unusable) {
			cout << "Put the card in row 4" << endl;
			pile4[0] = drawColorNumber;
			isPile4Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile5Usable != unusable) {
			cout << "Put the card in row 5" << endl;
			pile5[0] = drawColorNumber;
			isPile5Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
	}

	// 如果該輪還沒結束，則繼續進行，判斷下一位是誰能玩
	if (player2CanPlay == play) {
		player2PlayTheGame5();
	}
	else if (player3CanPlay == play) {
		player3PlayTheGame5();
	}
	else if (player4CanPlay == play) {
		player4PlayTheGame5();
	}
	else if (userCanPlay == play) {
		userPlayTheGame5();
	}
	else {
		// 電腦如果是該輪最後一個人並且遊戲沒結束則強制收牌
		if (player1CanPlay == play) {
			if (isPile1Usable != noCard && isPile1Usable != unusable) {
				cout << "Computer player1 take back row 1" << endl;
				for (int i = 0; i < 3; i++) {
					player1array[pile1[i]]++;
					pile1[i] = 0;
				}
				player1CanPlay = endplay;
				isPile1Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile2Usable != noCard && isPile2Usable != unusable) {
				cout << "Computer player1 take back row 2" << endl;
				for (int i = 0; i < 3; i++) {
					player1array[pile2[i]]++;
					pile2[i] = 0;
				}
				player1CanPlay = endplay;
				isPile2Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile3Usable != noCard && isPile3Usable != unusable) {
				cout << "Computer player1 take back row 3" << endl;
				for (int i = 0; i < 3; i++) {
					player1array[pile3[i]]++;
					pile3[i] = 0;
				}
				player1CanPlay = endplay;
				isPile3Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile4Usable != noCard && isPile4Usable != unusable) {
				cout << "Computer player1 take back row 4" << endl;
				for (int i = 0; i < 3; i++) {
					player1array[pile4[i]]++;
					pile4[i] = 0;
				}
				player1CanPlay = endplay;
				isPile4Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile5Usable != noCard && isPile5Usable != unusable) {
				cout << "Computer player1 take back row 5" << endl;
				for (int i = 0; i < 3; i++) {
					player1array[pile5[i]]++;
					pile5[i] = 0;
				}
				player1CanPlay = endplay;
				isPile5Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}

			if (howManyCard5 <= 0) {
				CountPoint5();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				isPile5Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				counterPile5 = 3;
				player1PlayTheGame5();
			}

		}
		// 所有人皆已完成操作，該輪結束
		else {
			if (howManyCard5 <= 0) {
				CountPoint5();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				isPile5Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				counterPile5 = 3;
				player1PlayTheGame5();
			}
		}
	}
}


void player2PlayTheGame5()
{
	cout << "\n***Computer player2's round***" << endl;
	// 只要可收牌就收牌的機制
	if (isPile1Usable != noCard && isPile1Usable != unusable) {
		cout << "Computer player2 take back row 1" << endl;
		for (int i = 0; i < 3; i++) {
			player2array[pile1[i]]++;
			pile1[i] = 0;
		}
		isPile1Usable = unusable;
		player2CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile2Usable != noCard && isPile2Usable != unusable) {
		cout << "Computer player2 take back row 2" << endl;
		for (int i = 0; i < 3; i++) {
			player2array[pile2[i]]++;
			pile2[i] = 0;
		}
		isPile2Usable = unusable;
		player2CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile3Usable != noCard && isPile3Usable != unusable) {
		cout << "Computer player2 take back row 3" << endl;
		for (int i = 0; i < 3; i++) {
			player2array[pile3[i]]++;
			pile3[i] = 0;
		}
		isPile3Usable = unusable;
		player2CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile4Usable != noCard && isPile4Usable != unusable) {
		cout << "Computer player2 take back row 4" << endl;
		for (int i = 0; i < 3; i++) {
			player2array[pile4[i]]++;
			pile4[i] = 0;
		}
		isPile4Usable = unusable;
		player2CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile5Usable != noCard && isPile5Usable != unusable) {
		cout << "Computer player2 take back row 5" << endl;
		for (int i = 0; i < 3; i++) {
			player2array[pile5[i]]++;
			pile5[i] = 0;
		}
		isPile5Usable = unusable;
		player2CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else { // 無法收牌，只能抽牌
		cout << "Computer player2 draw a card";
		int drawColorNumber = drawCard5();
		//判斷哪個行列能放牌
		if (isPile1Usable != unusable) {
			cout << "Put the card in row 1" << endl;
			pile1[0] = drawColorNumber;
			isPile1Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile2Usable != unusable) {
			cout << "Put the card in row 2" << endl;
			pile2[0] = drawColorNumber;
			isPile2Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile3Usable != unusable) {
			cout << "Put the card in row 3" << endl;
			pile3[0] = drawColorNumber;
			isPile3Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile4Usable != unusable) {
			cout << "Put the card in row 4" << endl;
			pile4[0] = drawColorNumber;
			isPile4Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile5Usable != unusable) {
			cout << "Put the card in row 5" << endl;
			pile5[0] = drawColorNumber;
			isPile5Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
	}

	// 如果該輪還沒結束，則繼續進行，判斷下一位是誰能玩
	if (player3CanPlay == play) {
		player3PlayTheGame5();
	}
	else if (player4CanPlay == play) {
		player4PlayTheGame5();
	}
	else if (userCanPlay == play) {
		userPlayTheGame5();
	}
	else if (player1CanPlay == play) {
		player1PlayTheGame5();
	}
	else {
		// 電腦如果是該輪最後一個人並且遊戲沒結束則強制收牌
		if (player2CanPlay == play) {
			if (isPile1Usable != unusable) {
				cout << "Computer player2 take back row 1" << endl;
				for (int i = 0; i < 3; i++) {
					player2array[pile1[i]]++;
					pile1[i] = 0;
				}
				player2CanPlay = endplay;
				isPile1Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile2Usable != unusable) {
				cout << "Computer player2 take back row 2" << endl;
				for (int i = 0; i < 3; i++) {
					player2array[pile2[i]]++;
					pile2[i] = 0;
				}
				player2CanPlay = endplay;
				isPile2Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile3Usable != unusable) {
				cout << "Computer player2 take back row 3" << endl;
				for (int i = 0; i < 3; i++) {
					player2array[pile3[i]]++;
					pile3[i] = 0;
				}
				player2CanPlay = endplay;
				isPile3Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile4Usable != unusable) {
				cout << "Computer player2 take back row 4" << endl;
				for (int i = 0; i < 3; i++) {
					player2array[pile4[i]]++;
					pile4[i] = 0;
				}
				player2CanPlay = endplay;
				isPile4Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile5Usable != unusable) {
				cout << "Computer player2 take back row 5" << endl;
				for (int i = 0; i < 3; i++) {
					player2array[pile5[i]]++;
					pile5[i] = 0;
				}
				player2CanPlay = endplay;
				isPile5Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}

			if (howManyCard5 <= 0) {
				CountPoint5();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				player4CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				isPile5Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				counterPile5 = 3;
				player2PlayTheGame5();
			}

		}
		// 所有人皆已完成操作，該輪結束
		else {
			if (howManyCard5 <= 0) {
				CountPoint5();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				player4CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				isPile5Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				counterPile5 = 3;
				player2PlayTheGame5();
			}
		}
	}
}


void player3PlayTheGame5()
{
	cout << "\n***Computer player3's round***" << endl;
	// 只要可收牌就收牌的機制
	if (isPile1Usable != unusable && isPile1Usable != noCard) {
		cout << "Computer player3 take back row 1" << endl;
		for (int i = 0; i < 3; i++) {
			player3array[pile1[i]]++;
			pile1[i] = 0;
		}
		isPile1Usable = unusable;
		player3CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile2Usable != unusable && isPile2Usable != noCard) {
		cout << "Computer player3 take back row 2" << endl;
		for (int i = 0; i < 3; i++) {
			player3array[pile2[i]]++;
			pile2[i] = 0;
		}
		isPile2Usable = unusable;
		player3CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile3Usable != unusable && isPile3Usable != noCard) {
		cout << "Computer player3 take back row 3" << endl;
		for (int i = 0; i < 3; i++) {
			player3array[pile3[i]]++;
			pile3[i] = 0;
		}
		isPile3Usable = unusable;
		player3CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile4Usable != unusable && isPile4Usable != noCard) {
		cout << "Computer player3 take back row 4" << endl;
		for (int i = 0; i < 3; i++) {
			player3array[pile4[i]]++;
			pile4[i] = 0;
		}
		isPile4Usable = unusable;
		player3CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile5Usable != unusable && isPile5Usable != noCard) {
		cout << "Computer player3 take back row 5" << endl;
		for (int i = 0; i < 3; i++) {
			player3array[pile5[i]]++;
			pile5[i] = 0;
		}
		isPile5Usable = unusable;
		player3CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else {
		// 無法收牌，只能抽牌
		cout << "Computer player3 draw a card" << endl;
		int drawColorNumber = drawCard5();
		//判斷哪個行列能放牌
		if (isPile1Usable != unusable) {
			cout << "Put the card in row 1" << endl;
			pile1[0] = drawColorNumber;
			isPile1Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile2Usable != unusable) {
			cout << "Put the card in row 2" << endl;
			pile2[0] = drawColorNumber;
			isPile2Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile3Usable != unusable) {
			cout << "Put the card in row 3" << endl;
			pile3[0] = drawColorNumber;
			isPile3Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile4Usable != unusable) {
			cout << "Put the card in row 4" << endl;
			pile4[0] = drawColorNumber;
			isPile4Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile5Usable != unusable) {
			cout << "Put the card in row 5" << endl;
			pile5[0] = drawColorNumber;
			isPile5Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
	}

	// 如果該輪還沒結束，則繼續進行，判斷下一位是誰能玩
	if (player4CanPlay == play) {
		player4PlayTheGame5();
	}
	else if (userCanPlay == play) {
		userPlayTheGame5();
	}
	else if (player1CanPlay == play) {
		player1PlayTheGame5();
	}
	else if (player2CanPlay == play) {
		player2PlayTheGame5();
	}
	else {
		// 電腦如果是該輪最後一個人並且遊戲沒結束則強制收牌
		if (player3CanPlay == play) {
			if (isPile1Usable != unusable) {
				cout << "Computer player3 take back row 1" << endl;
				for (int i = 0; i < 3; i++) {
					player3array[pile1[i]]++;
					pile1[i] = 0;
				}
				player3CanPlay = endplay;
				isPile1Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile2Usable != unusable) {
				cout << "Computer player3 take back row 2" << endl;
				for (int i = 0; i < 3; i++) {
					player3array[pile2[i]]++;
					pile2[i] = 0;
				}
				player3CanPlay = endplay;
				isPile2Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile3Usable != unusable) {
				cout << "Computer player3 take back row 3" << endl;
				for (int i = 0; i < 3; i++) {
					player3array[pile3[i]]++;
					pile3[i] = 0;
				}
				player3CanPlay = endplay;
				isPile3Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile4Usable != unusable) {
				cout << "Computer player3 take back row 4" << endl;
				for (int i = 0; i < 3; i++) {
					player3array[pile4[i]]++;
					pile4[i] = 0;
				}
				player3CanPlay = endplay;
				isPile4Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile5Usable != unusable) {
				cout << "Computer player3 take back row 5" << endl;
				for (int i = 0; i < 3; i++) {
					player3array[pile5[i]]++;
					pile5[i] = 0;
				}
				player3CanPlay = endplay;
				isPile5Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}

			if (howManyCard5 <= 0) {
				CountPoint5();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				player4CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				isPile5Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				counterPile5 = 3;
				player3PlayTheGame5();
			}

		}
		// 所有人皆已完成操作，該輪結束
		else {
			if (howManyCard5 <= 0) {
				CountPoint5();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				player4CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				isPile5Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				counterPile5 = 3;
				player3PlayTheGame5();
			}
		}
	}
}

void player4PlayTheGame5()
{
	cout << "\n***Computer player4's round***" << endl;
	// 只要可收牌就收牌的機制
	if (isPile1Usable != unusable && isPile1Usable != noCard) {
		cout << "Computer player4 take back row 1" << endl;
		for (int i = 0; i < 3; i++) {
			player4array[pile1[i]]++;
			pile1[i] = 0;
		}
		isPile1Usable = unusable;
		player4CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile2Usable != unusable && isPile2Usable != noCard) {
		cout << "Computer player4 take back row 2" << endl;
		for (int i = 0; i < 3; i++) {
			player4array[pile2[i]]++;
			pile2[i] = 0;
		}
		isPile2Usable = unusable;
		player4CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile3Usable != unusable && isPile3Usable != noCard) {
		cout << "Computer player4 take back row 3" << endl;
		for (int i = 0; i < 3; i++) {
			player4array[pile3[i]]++;
			pile3[i] = 0;
		}
		isPile3Usable = unusable;
		player4CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile4Usable != unusable && isPile4Usable != noCard) {
		cout << "Computer player4 take back row 4" << endl;
		for (int i = 0; i < 3; i++) {
			player3array[pile4[i]]++;
			pile4[i] = 0;
		}
		isPile4Usable = unusable;
		player4CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else if (isPile5Usable != unusable && isPile5Usable != noCard) {
		cout << "Computer player3 take back row 5" << endl;
		for (int i = 0; i < 3; i++) {
			player4array[pile5[i]]++;
			pile5[i] = 0;
		}
		isPile5Usable = unusable;
		player4CanPlay = endplay;
		showAllPlayerArray5();
		showPile5();
	}
	else {
		// 無法收牌，只能抽牌
		cout << "Computer player4 draw a card" << endl;
		int drawColorNumber = drawCard5();
		//判斷哪個行列能放牌
		if (isPile1Usable != unusable) {
			cout << "Put the card in row 1" << endl;
			pile1[0] = drawColorNumber;
			isPile1Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile2Usable != unusable) {
			cout << "Put the card in row 2" << endl;
			pile2[0] = drawColorNumber;
			isPile2Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile3Usable != unusable) {
			cout << "Put the card in row 3" << endl;
			pile3[0] = drawColorNumber;
			isPile3Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile4Usable != unusable) {
			cout << "Put the card in row 4" << endl;
			pile4[0] = drawColorNumber;
			isPile4Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
		else if (isPile5Usable != unusable) {
			cout << "Put the card in row 5" << endl;
			pile5[0] = drawColorNumber;
			isPile5Usable = canPutCard;
			showAllPlayerArray5();
			showPile5();
		}
	}

	// 如果該輪還沒結束，則繼續進行，判斷下一位是誰能玩
	if (userCanPlay == play) {
		userPlayTheGame5();
	}
	else if (player1CanPlay == play) {
		player1PlayTheGame5();
	}
	else if (player2CanPlay == play) {
		player2PlayTheGame5();
	}	
	else if (player3CanPlay == play) {
		player3PlayTheGame5();
	}
	else {
		// 電腦如果是該輪最後一個人並且遊戲沒結束則強制收牌
		if (player4CanPlay == play) {
			if (isPile1Usable != unusable) {
				cout << "Computer player4 take back row 1" << endl;
				for (int i = 0; i < 3; i++) {
					player4array[pile1[i]]++;
					pile1[i] = 0;
				}
				player4CanPlay = endplay;
				isPile1Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile2Usable != unusable) {
				cout << "Computer player4 take back row 2" << endl;
				for (int i = 0; i < 3; i++) {
					player4array[pile2[i]]++;
					pile2[i] = 0;
				}
				player4CanPlay = endplay;
				isPile2Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile3Usable != unusable) {
				cout << "Computer player4 take back row 3" << endl;
				for (int i = 0; i < 3; i++) {
					player4array[pile3[i]]++;
					pile3[i] = 0;
				}
				player4CanPlay = endplay;
				isPile3Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile4Usable != unusable) {
				cout << "Computer player4 take back row 4" << endl;
				for (int i = 0; i < 3; i++) {
					player4array[pile4[i]]++;
					pile4[i] = 0;
				}
				player4CanPlay = endplay;
				isPile4Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}
			else if (isPile5Usable != unusable) {
				cout << "Computer player4 take back row 5" << endl;
				for (int i = 0; i < 3; i++) {
					player4array[pile5[i]]++;
					pile5[i] = 0;
				}
				player4CanPlay = endplay;
				isPile5Usable = unusable;
				showAllPlayerArray5();
				showPile5();
			}

			if (howManyCard5 <= 0) {
				CountPoint5();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				player4CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				isPile5Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				counterPile5 = 3;
				player4PlayTheGame5();
			}

		}
		// 所有人皆已完成操作，該輪結束
		else {
			if (howManyCard5 <= 0) {
				CountPoint5();
			}
			else {
				userCanPlay = play;
				player1CanPlay = play;
				player2CanPlay = play;
				player3CanPlay = play;
				player4CanPlay = play;
				isPile1Usable = noCard;
				isPile2Usable = noCard;
				isPile3Usable = noCard;
				isPile4Usable = noCard;
				isPile5Usable = noCard;
				counterPile1 = 3;
				counterPile2 = 3;
				counterPile3 = 3;
				counterPile4 = 3;
				counterPile5 = 3;
				player4PlayTheGame5();
			}
		}
	}
}


void CountPoint5()
{
	// 強制讓[0]位置為0
	userarray[0] = 0;
	player1array[0] = 0;
	player2array[0] = 0;
	player3array[0] = 0;
	player4array[0] = 0;

	// sort 排卡的數量
	sort(userarray, userarray + 8, cmp);
	sort(player1array, player1array + 8, cmp);
	sort(player2array, player2array + 8, cmp);
	sort(player3array, player3array + 8, cmp);
	sort(player4array, player4array + 8, cmp);

	// 彩色變色龍的最佳放法
	// user
	if (userarray[0] >= 6) {
		if (userarray[1] > 6) {
			for (int i = 0; i < userarray[8]; i++) {
				userarray[2]++;
			}
		}
		else {
			for (int i = 0; i < userarray[8]; i++) {
				userarray[1]++;
			}
		}
	}
	else {
		for (int i = 0; i < userarray[8]; i++) {
			userarray[0]++;
		}
	}

	// 電腦一
	if (player1array[1] >= 6) {
		if (player1array[2] > 6) {
			for (int i = 0; i < player1array[8]; i++) {
				player1array[3]++;
			}
		}
		else {
			for (int i = 0; i < player1array[8]; i++) {
				player1array[2]++;
			}
		}
	}
	else {
		for (int i = 0; i < player1array[8]; i++) {
			player1array[1]++;
		}
	}

	// 電腦二
	if (player2array[1] >= 6) {
		if (player2array[2] > 6) {
			for (int i = 0; i < player2array[8]; i++) {
				player2array[3]++;
			}
		}
		else {
			for (int i = 0; i < player2array[8]; i++) {
				player2array[2]++;
			}
		}
	}
	else {
		for (int i = 0; i < player2array[8]; i++) {
			player2array[1]++;
		}
	}

	// 電腦三
	if (player3array[1] >= 6) {
		if (player3array[2] > 6) {
			for (int i = 0; i < player3array[8]; i++) {
				player3array[3]++;
			}
		}
		else {
			for (int i = 0; i < player3array[8]; i++) {
				player3array[2]++;
			}
		}
	}
	else {
		for (int i = 0; i < player3array[8]; i++) {
			player3array[1]++;
		}
	}

	// 電腦四
	if (player4array[1] >= 6) {
		if (player4array[2] > 6) {
			for (int i = 0; i < player4array[8]; i++) {
				player4array[3]++;
			}
		}
		else {
			for (int i = 0; i < player4array[8]; i++) {
				player4array[2]++;
			}
		}
	}
	else {
		for (int i = 0; i < player4array[8]; i++) {
			player4array[1]++;
		}
	}


	// 開始計算分數，用swich判斷每一個使用者陣列裡的數值
	// user牌由大到小
	int u1 = 0;
	int u2 = 0;
	int u3 = 0;
	int u4 = 0;
	int u5 = 0;
	int u6 = 0;
	int u7 = 0;

	switch (userarray[0]) // 最多的牌可拿幾分
	{
	case 6:
		u1 = 21;
		break;
	case 5:
		u1 = 15;
		break;
	case 4:
		u1 = 10;
		break;
	case 3:
		u1 = 6;
		break;
	case 2:
		u1 = 3;
		break;
	case 1:
		u1 = 1;
		break;
	case 0:
		u1 = 0;
		break;
	}

	switch (userarray[1]) // 第二多的牌可拿幾分
	{
	case 6:
		u2 = 21;
		break;
	case 5:
		u2 = 15;
		break;
	case 4:
		u2 = 10;
		break;
	case 3:
		u2 = 6;
		break;
	case 2:
		u2 = 3;
		break;
	case 1:
		u2 = 1;
		break;
	case 0:
		u2 = 0;
		break;
	}

	switch (userarray[2]) // 第三多的牌可拿幾分
	{
	case 6:
		u3 = 21;
		break;
	case 5:
		u3 = 15;
		break;
	case 4:
		u3 = 10;
		break;
	case 3:
		u3 = 6;
		break;
	case 2:
		u3 = 3;
		break;
	case 1:
		u3 = 1;
		break;
	case 0:
		u3 = 0;
		break;
	}

	switch (userarray[3]) // 第四多的牌可要扣幾分
	{
	case 6:
		u4 = -21;
		break;
	case 5:
		u4 = -15;
		break;
	case 4:
		u4 = -10;
		break;
	case 3:
		u4 = -6;
		break;
	case 2:
		u4 = -3;
		break;
	case 1:
		u4 = -1;
		break;
	case 0:
		u4 = 0;
		break;
	}

	switch (userarray[4]) // 第五多的牌可要扣幾分
	{
	case 6:
		u5 = -21;
		break;
	case 5:
		u5 = -15;
		break;
	case 4:
		u5 = -10;
		break;
	case 3:
		u5 = -6;
		break;
	case 2:
		u5 = -3;
		break;
	case 1:
		u5 = -1;
		break;
	case 0:
		u5 = 0;
		break;
	}

	switch (userarray[5]) // 第六多的牌可要扣幾分
	{
	case 6:
		u6 = -21;
		break;
	case 5:
		u6 = -15;
		break;
	case 4:
		u6 = -10;
		break;
	case 3:
		u6 = -6;
		break;
	case 2:
		u6 = -3;
		break;
	case 1:
		u6 = -1;
		break;
	case 0:
		u6 = 0;
		break;
	}

	switch (userarray[6]) // 第七多的牌可要扣幾分
	{
	case 6:
		u7 = -21;
		break;
	case 5:
		u7 = -15;
		break;
	case 4:
		u7 = -10;
		break;
	case 3:
		u7 = -6;
		break;
	case 2:
		u7 = -3;
		break;
	case 1:
		u7 = -1;
		break;
	case 0:
		u7 = 0;
		break;
	}

	int userTotalPoints = u1 + u2 + u3 + u4 + u5 + u6 + u7 + userarray[9] * 2;

	// 電腦一牌由大到小
	int p11 = 0;
	int p12 = 0;
	int p13 = 0;
	int p14 = 0;
	int p15 = 0;
	int p16 = 0;
	int p17 = 0;

	switch (player1array[0]) // 最多的牌可拿幾分
	{
	case 6:
		p11 = 21;
		break;
	case 5:
		p11 = 15;
		break;
	case 4:
		p11 = 10;
		break;
	case 3:
		p11 = 6;
		break;
	case 2:
		p11 = 3;
		break;
	case 1:
		p11 = 1;
		break;
	case 0:
		p11 = 0;
		break;
	}

	switch (player1array[1]) // 第二多的牌可拿幾分
	{
	case 6:
		p12 = 21;
		break;
	case 5:
		p12 = 15;
		break;
	case 4:
		p12 = 10;
		break;
	case 3:
		p12 = 6;
		break;
	case 2:
		p12 = 3;
		break;
	case 1:
		p12 = 1;
		break;
	case 0:
		p12 = 0;
		break;
	}

	switch (player1array[2]) // 第三多的牌可拿幾分
	{
	case 6:
		p13 = 21;
		break;
	case 5:
		p13 = 15;
		break;
	case 4:
		p13 = 10;
		break;
	case 3:
		p13 = 6;
		break;
	case 2:
		p13 = 3;
		break;
	case 1:
		p13 = 1;
		break;
	case 0:
		p13 = 0;
		break;
	}

	switch (player1array[3]) // 第四多的牌可要扣幾分
	{
	case 6:
		p14 = -21;
		break;
	case 5:
		p14 = -15;
		break;
	case 4:
		p14 = -10;
		break;
	case 3:
		p14 = -6;
		break;
	case 2:
		p14 = -3;
		break;
	case 1:
		p14 = -1;
		break;
	case 0:
		p14 = 0;
		break;
	}

	switch (player1array[4]) // 第五多的牌可要扣幾分
	{
	case 6:
		p15 = -21;
		break;
	case 5:
		p15 = -15;
		break;
	case 4:
		p15 = -10;
		break;
	case 3:
		p15 = -6;
		break;
	case 2:
		p15 = -3;
		break;
	case 1:
		p15 = -1;
		break;
	case 0:
		p15 = 0;
		break;
	}

	switch (player1array[5]) // 第六多的牌可要扣幾分
	{
	case 6:
		p16 = -21;
		break;
	case 5:
		p16 = -15;
		break;
	case 4:
		p16 = -10;
		break;
	case 3:
		p16 = -6;
		break;
	case 2:
		p16 = -3;
		break;
	case 1:
		p16 = -1;
		break;
	case 0:
		p16 = 0;
		break;
	}

	switch (player1array[6]) // 第七多的牌可要扣幾分
	{
	case 6:
		p17 = -21;
		break;
	case 5:
		p17 = -15;
		break;
	case 4:
		p17 = -10;
		break;
	case 3:
		p17 = -6;
		break;
	case 2:
		p17 = -3;
		break;
	case 1:
		p17 = -1;
		break;
	case 0:
		p17 = 0;
		break;
	}

	int player1TotalPoints = p11 + p12 + p13 + p14 + p15 + p16 + p17 + player1array[9] * 2;

	// 電腦二牌由大到小
	int p21 = 0;
	int p22 = 0;
	int p23 = 0;
	int p24 = 0;
	int p25 = 0;
	int p26 = 0;
	int p27 = 0;

	switch (player2array[0]) // 最多的牌可拿幾分
	{
	case 6:
		p21 = 21;
		break;
	case 5:
		p21 = 15;
		break;
	case 4:
		p21 = 10;
		break;
	case 3:
		p21 = 6;
		break;
	case 2:
		p21 = 3;
		break;
	case 1:
		p21 = 1;
		break;
	case 0:
		p21 = 0;
		break;
	}

	switch (player2array[1]) // 第二多的牌可拿幾分
	{
	case 6:
		p22 = 21;
		break;
	case 5:
		p22 = 15;
		break;
	case 4:
		p22 = 10;
		break;
	case 3:
		p22 = 6;
		break;
	case 2:
		p22 = 3;
		break;
	case 1:
		p22 = 1;
		break;
	case 0:
		p22 = 0;
		break;
	}

	switch (player2array[2]) // 第三多的牌可拿幾分
	{
	case 6:
		p23 = 21;
		break;
	case 5:
		p23 = 15;
		break;
	case 4:
		p23 = 10;
		break;
	case 3:
		p23 = 6;
		break;
	case 2:
		p23 = 3;
		break;
	case 1:
		p23 = 1;
		break;
	case 0:
		p23 = 0;
		break;
	}

	switch (player2array[3]) // 第四多的牌可要扣幾分
	{
	case 6:
		p24 = -21;
		break;
	case 5:
		p24 = -15;
		break;
	case 4:
		p24 = -10;
		break;
	case 3:
		p24 = -6;
		break;
	case 2:
		p24 = -3;
		break;
	case 1:
		p24 = -1;
		break;
	case 0:
		p24 = 0;
		break;
	}

	switch (player2array[4]) // 第五多的牌可要扣幾分
	{
	case 6:
		p25 = -21;
		break;
	case 5:
		p25 = -15;
		break;
	case 4:
		p25 = -10;
		break;
	case 3:
		p25 = -6;
		break;
	case 2:
		p25 = -3;
		break;
	case 1:
		p25 = -1;
		break;
	case 0:
		p25 = 0;
		break;
	}

	switch (player2array[5]) // 第六多的牌可要扣幾分
	{
	case 6:
		p26 = -21;
		break;
	case 5:
		p26 = -15;
		break;
	case 4:
		p26 = -10;
		break;
	case 3:
		p26 = -6;
		break;
	case 2:
		p26 = -3;
		break;
	case 1:
		p26 = -1;
		break;
	case 0:
		p26 = 0;
		break;
	}

	switch (player2array[6]) // 第七多的牌可要扣幾分
	{
	case 6:
		p27 = -21;
		break;
	case 5:
		p27 = -15;
		break;
	case 4:
		p27 = -10;
		break;
	case 3:
		p27 = -6;
		break;
	case 2:
		p27 = -3;
		break;
	case 1:
		p27 = -1;
		break;
	case 0:
		p27 = 0;
		break;
	}

	int player2TotalPoints = p21 + p22 + p23 + p24 + p25 + p26 + p27 + player2array[9] * 2;


	int p31 = 0;
	int p32 = 0;
	int p33 = 0;
	int p34 = 0;
	int p35 = 0;
	int p36 = 0;
	int p37 = 0; // 電腦三牌由大到小

	switch (player3array[0]) // 最多的牌可拿幾分
	{
	case 6:
		p31 = 21;
		break;
	case 5:
		p31 = 15;
		break;
	case 4:
		p31 = 10;
		break;
	case 3:
		p31 = 6;
		break;
	case 2:
		p31 = 3;
		break;
	case 1:
		p31 = 1;
		break;
	case 0:
		p31 = 0;
		break;
	}

	switch (player3array[1]) // 第二多的牌可拿幾分
	{
	case 6:
		p32 = 21;
		break;
	case 5:
		p32 = 15;
		break;
	case 4:
		p32 = 10;
		break;
	case 3:
		p32 = 6;
		break;
	case 2:
		p32 = 3;
		break;
	case 1:
		p32 = 1;
		break;
	case 0:
		p32 = 0;
		break;
	}

	switch (player3array[2]) // 第三多的牌可拿幾分
	{
	case 6:
		p33 = 21;
		break;
	case 5:
		p33 = 15;
		break;
	case 4:
		p33 = 10;
		break;
	case 3:
		p33 = 6;
		break;
	case 2:
		p33 = 3;
		break;
	case 1:
		p33 = 1;
		break;
	case 0:
		p33 = 0;
		break;
	}

	switch (player3array[3]) // 第四多的牌可要扣幾分
	{
	case 6:
		p34 = -21;
		break;
	case 5:
		p34 = -15;
		break;
	case 4:
		p34 = -10;
		break;
	case 3:
		p34 = -6;
		break;
	case 2:
		p34 = -3;
		break;
	case 1:
		p34 = -1;
		break;
	case 0:
		p34 = 0;
		break;
	}

	switch (player3array[4]) // 第五多的牌可要扣幾分
	{
	case 6:
		p35 = -21;
		break;
	case 5:
		p35 = -15;
		break;
	case 4:
		p35 = -10;
		break;
	case 3:
		p35 = -6;
		break;
	case 2:
		p35 = -3;
		break;
	case 1:
		p35 = -1;
		break;
	case 0:
		p35 = 0;
		break;
	}

	switch (player3array[5]) // 第六多的牌可要扣幾分
	{
	case 6:
		p36 = -21;
		break;
	case 5:
		p36 = -15;
		break;
	case 4:
		p36 = -10;
		break;
	case 3:
		p36 = -6;
		break;
	case 2:
		p36 = -3;
		break;
	case 1:
		p36 = -1;
		break;
	case 0:
		p36 = 0;
		break;
	}

	switch (player3array[6]) // 第七多的牌可要扣幾分
	{
	case 6:
		p37 = -21;
		break;
	case 5:
		p37 = -15;
		break;
	case 4:
		p37 = -10;
		break;
	case 3:
		p37 = -6;
		break;
	case 2:
		p37 = -3;
		break;
	case 1:
		p37 = -1;
		break;
	case 0:
		p37 = 0;
		break;
	}

	int player3TotalPoints = p31 + p32 + p33 + p34 + p35 + p36 + p37 + player2array[9] * 2;

	// 電腦四牌由大到小
	int p41 = 0;
	int p42 = 0;
	int p43 = 0;
	int p44 = 0;
	int p45 = 0;
	int p46 = 0;
	int p47 = 0;

	switch (player4array[0]) // 最多的牌可拿幾分
	{
	case 6:
		p41 = 21;
		break;
	case 5:
		p41 = 15;
		break;
	case 4:
		p41 = 10;
		break;
	case 3:
		p41 = 6;
		break;
	case 2:
		p41 = 3;
		break;
	case 1:
		p41 = 1;
		break;
	case 0:
		p41 = 0;
		break;
	}

	switch (player4array[1]) // 第二多的牌可拿幾分
	{
	case 6:
		p42 = 21;
		break;
	case 5:
		p42 = 15;
		break;
	case 4:
		p42 = 10;
		break;
	case 3:
		p42 = 6;
		break;
	case 2:
		p42 = 3;
		break;
	case 1:
		p42 = 1;
		break;
	case 0:
		p42 = 0;
		break;
	}

	switch (player4array[2]) // 第三多的牌可拿幾分
	{
	case 6:
		p43 = 21;
		break;
	case 5:
		p43 = 15;
		break;
	case 4:
		p43 = 10;
		break;
	case 3:
		p43 = 6;
		break;
	case 2:
		p43 = 3;
		break;
	case 1:
		p43 = 1;
		break;
	case 0:
		p43 = 0;
		break;
	}

	switch (player4array[3]) // 第四多的牌可要扣幾分
	{
	case 6:
		p44 = -21;
		break;
	case 5:
		p44 = -15;
		break;
	case 4:
		p44 = -10;
		break;
	case 3:
		p44 = -6;
		break;
	case 2:
		p44 = -3;
		break;
	case 1:
		p44 = -1;
		break;
	case 0:
		p44 = 0;
		break;
	}

	switch (player4array[4]) // 第五多的牌可要扣幾分
	{
	case 6:
		p45 = -21;
		break;
	case 5:
		p45 = -15;
		break;
	case 4:
		p45 = -10;
		break;
	case 3:
		p45 = -6;
		break;
	case 2:
		p45 = -3;
		break;
	case 1:
		p45 = -1;
		break;
	case 0:
		p45 = 0;
		break;
	}

	switch (player4array[5]) // 第六多的牌可要扣幾分
	{
	case 6:
		p46 = -21;
		break;
	case 5:
		p46 = -15;
		break;
	case 4:
		p46 = -10;
		break;
	case 3:
		p46 = -6;
		break;
	case 2:
		p46 = -3;
		break;
	case 1:
		p46 = -1;
		break;
	case 0:
		p46 = 0;
		break;
	}

	switch (player4array[6]) // 第七多的牌可要扣幾分
	{
	case 6:
		p47 = -21;
		break;
	case 5:
		p47 = -15;
		break;
	case 4:
		p47 = -10;
		break;
	case 3:
		p47 = -6;
		break;
	case 2:
		p47 = -3;
		break;
	case 1:
		p47 = -1;
		break;
	case 0:
		p47 = 0;
		break;
	}

	int player4TotalPoints = p41 + p42 + p43 + p44 + p45 + p46 + p47 + player4array[9] * 2;


	cout << "\nThe points you get:" << userTotalPoints << endl;
	cout << "The points computer player1 gets:" << player1TotalPoints << endl;
	cout << "The points computer player2 gets:" << player2TotalPoints << endl;
	cout << "The points computer player3 gets:" << player3TotalPoints << endl;
	cout << "The points computer player4 gets:" << player4TotalPoints << endl;

}
