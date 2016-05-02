#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

const vector<unsigned long long> model = {
	577094088726155265 , 1153493525606703105 , 292736725095563265 , 297246382237958145 , 1170937021957408770 , 585608706247364610 , 297378317328191490 , 1154188177435598850 , 1170944703579824130 , 576760369759141890 , 297246377942990850 , 594492760197726210 , 2308097558079078660 , 2308165184214142980 , 90080928227004420 , 2341874039636627460 , 2306476332348870660 , 594476800348921860 , 1188959103087681540 , 612490718627373060 , 162147728544505860 , 90090134523355140 , 148689190832316420 , 577094139745673220 , 1170937037029646340 , 2308095979406114820 , 1153211915263164420 , 1153519644301623300 , 2307039288603181320 , 162134124219334920 , 4612813157433344520 , 1153343854582170120 , 76702068663910920 , 297378317462405640 , 2306970283786895880 , 4616194020941496840 , 4612952664681029640 , 1154048778945175560 , 148689160817877000 , 297239845296750600 , 2306142087114145800 , 9224499173746819080 , 180179173830049800 , 1170938239645745160 , 297240049576149000 , 2306476332274450440 , 306247523977658640 , 2307039286597255440 , 577094088726151440 , 4611972441743819280 , 81205549035160080 , 324268244160479760 , 2307039312249618960 , 4613940567557080080 , 585608698710262800 , 153123761862738960 , 146402722084634640 , 297378321619042320 , 2306970558522343440 , 9225624953896976400 , 612490666550902800 , 153263142016139280 , 4612284169950101520 , 297240049324949520 , 594480098649833760 , 612507158709273120 , 292874747648148000 , 577164509538485280 , 1170938138646873120 , 4613940088131355680 , 9223943788270978080 , 4612257770917332000 , 1153343751469401120 , 576760369259742240 , 1153625196482004000 , 306247523708766240 , 288582290739693600 , 9223952596195084320 , 292736724579125280 , 292804348952608800 , 1153493390239990080 , 2306987051079696960 , 1188959102083007040 , 577041844735640640 , 585469119831213120 , 2306970558656546880 , 1154048643611887680 , 577164577201197120 , 2306986776201790080 , 2308165182134682240 , 594492752125822080 , 1170938239645714560
};
const size_t sizeModel = model.size();
vector<unsigned long long> board(8);

int minMove(unsigned long long modelBoard);

int main()
{
	std::ios::sync_with_stdio(false);
	int counter = 1;
	while (cin >> board[0])
	{
		--board[0];
		for (int i = 1; i < 8; ++i)
		{
			cin >> board[i];
			--board[i];
		}
		int min = 8;
		for (int i = 0; i < sizeModel; ++i)
		{
			int subMin = minMove(model[i]);
			if (subMin < min)
				min = subMin;
		}
		cout << "Case " << counter << ": " << min << '\n';
		++counter;
	}
	return 0;
}

int minMove(unsigned long long modelBoard)
{
	int result = 0;
	for (int i = 0; i < 8; ++i)
	{
		int index = 8 * i;
		unsigned long long rowModel = 255;
		rowModel &= modelBoard >> index;
		unsigned long long rowBoard = 1;
		rowBoard <<= board[i];
		if (rowModel != rowBoard)
			++result;
	}
	return result;
}

//vector<bool> column(8 , true) , diagonal(15 , true) , antigonal(15 , true);
//vector<int> result(8);
//int counter = 0;
//
//void backtrack(int row);
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	backtrack(0);
//	
//	return 0;
//}
//
//void backtrack(int row)
//{
//	if (row == 8)
//	{
//		++counter;
//		unsigned long long number = 0;
//		for (int i = 0; i < 8; ++i)
//		{
//			number |= unsigned long long(1) << (result[i] + 8 * i);
//		}
//		cout << number << " , ";
//		return;
//	}
//	for (int col = 0; col < 8; ++col)
//		if (column[col] &&
//			diagonal[7 - row + col] &&
//			antigonal[row + col])
//		{
//			column[col] = false;
//			diagonal[7 - row + col] = false;
//			antigonal[row + col] = false;
//			result[row] = col;
//			backtrack(row + 1);
//			antigonal[row + col] = true;
//			diagonal[7 - row + col] = true;
//			column[col] = true;
//		}
//}