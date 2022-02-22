/*
 * 
 *  Created by Sankyuri
 * 
 *  Attention:
 *  - Written by Japanese.
 *  - Required C++20.
 * 
 *  License:
 *  This program has not license.
 *  You can free use, copy and etc at all.
 * 
 * 
 */

#include <iostream>
#include <string>


// ********  using 宣言  ********
using std::cout;
using std::cin;
using std::endl;
using std::string;




// ********  定数宣言  ********
static constexpr int WRAPPING_HEIGHT = 6;




// ********  プロトタイプ宣言  ********

// 板チョコの大きさを入力する
void get_chocolate_bar_size(
		int &column,
		int &row
);


// 板チョコを表示する
void print_chocolate_bar(
		int column,
		int row
);

// 板チョコの頭を表示する
void print_chocolate_bar_head(
		int column
);

// 板チョコの中身を表示する
void print_chocolate_bar_body(
		int column
);

// 板チョコの包装紙を表示する
void print_chocolate_bar_wrapping(
		int column
);


// 左端+真ん中+右端で文字列を表示する
void print_chocolate_bar_line(
		int    column,
		string left,
		string center,
		string right
);


// 左端+真ん中+右端で飾り付きの部分の文字列を表示する
void print_chocolate_bar_line_decorated(
		int    column,
		string left,
		string left_decolated,
		string center,
		string center_adjust,
		string right,
		string right_decolated
);








// ********  関数定義  ********

int main()
{
	// **** 変数 ****

	// 横の数
	int column = 0;
	// 縦の数
	int row    = 0;


	// **** 大きさの入力 ****
	get_chocolate_bar_size( column, row );
	
	// 1行空ける
	cout << endl;


	// **** 板チョコの出力 ****
	print_chocolate_bar( column, row );


}








// 板チョコの大きさを入力する
void get_chocolate_bar_size(
		int &column,
		int &row
)
{
	// 横の数
	cout << "column?: ";
	cin  >> column;

	// 縦の数
	cout << "row?: ";
	cin  >> row;
}




// 板チョコを表示する
void print_chocolate_bar(
		int column,
		int row
)
{
	// 板チョコの頭を表示する
	print_chocolate_bar_head( column );


	// 板チョコの中身を、
	// 縦の数だけ表示する
	if (row < 0)
	{
		cout << "縦の数がマイナスです！" << endl;
	}
	for (int i = 0; i < row; ++i)
	{
		print_chocolate_bar_body( column );
	}

	// 板チョコの包装紙を表示する
	print_chocolate_bar_wrapping( column );
}




// 板チョコの頭を表示する
void print_chocolate_bar_head(
		int column
)
{
	print_chocolate_bar_line(
		column,
		"┏ ",  "━ ━ ━ ",  "┓ "
	);
}




// 板チョコの中身を表示する
void print_chocolate_bar_body(
		int column
)
{
	print_chocolate_bar_line(
		column,
		"┃ ",  "┏ ━ ┓ ",  "┃ "
	);
	
	print_chocolate_bar_line(
		column,
		"┃ ",  "┃ 　┃ " ,  "┃ "
	);
	
	print_chocolate_bar_line(
		column,
		"┃ ",  "┗ ━ ┛ ",  "┃ "
	);
}




// 板チョコの包装紙を表示する
void print_chocolate_bar_wrapping(
		int column
)
{
	print_chocolate_bar_line_decorated(
		column,
		"┣ "      ,  "┣ ┯ ",
		"━ ━ ━ ",  "━ "   ,
		"┫ "      ,  "┯ ┫ "
	);
	
	for (int i = 0; i < WRAPPING_HEIGHT; ++i)
	{
		print_chocolate_bar_line_decorated(
			column,
			"┃ "      ,  "┃ │ ",
			"　　　"   ,  "　"    ,
			"┃ "      ,  "│ ┃ "
		);
	}
	
	print_chocolate_bar_line_decorated(
		column,
		"┃ "      ,  "┃ └ ",
		"─ ─ ─ ",  "─ "   ,
		"┃ "      ,  "┘ ┃ "
	);
	
	print_chocolate_bar_line_decorated(
		column,
		"┗ "      ,  "┗ ━ ",
		"━ ━ ━ ",  "━ "   ,
		"┛ "      ,  "━ ┛ "
	);


}




// 左端+真ん中+右端で文字列を表示する
void print_chocolate_bar_line(
		int    column,
		string left,
		string center,
		string right
)
{
	cout << left;
	for (int i = 0; i < column; ++i)
	{
		cout << center;
	}
	cout << right;
	cout << endl;
}




// 左端+真ん中+右端で飾り付きの部分の文字列を表示する
void print_chocolate_bar_line_decorated(
		int    column,
		string left,
		string left_decolated,
		string center,
		string center_adjust,
		string right,
		string right_decolated
)
{
	// 横幅が1未満(模様を表示する幅が無い)の場合
	if (column < 1)
	{
		print_chocolate_bar_line(
			column,
			left,  center,  right
		);
	}
	else
	{
		cout << left_decolated;
		for (int i = 0; i < column - 1; ++i)
		{
			cout << center;
		}
		cout << center_adjust;
		cout << right_decolated;
		cout << endl;
	}
}



