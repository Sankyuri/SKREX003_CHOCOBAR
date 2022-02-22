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
void input_chocolate_bar_size(
	int &row,
	int &column
);


// 板チョコを表示する
void print_chocolate_bar(
	int row,
	int column
);

// 板チョコの頭を表示する
void print_chocolate_bar_head(
	int row
);

// 板チョコの中身を表示する
void print_chocolate_bar_body(
	int row
);

// 板チョコの包装紙を表示する
void print_chocolate_bar_wrapping(
	int row
);


// 左端+真ん中+右端で文字列を表示する
void print_3_string_row_times(
	int    row,
	string left,
	string center,
	string right
);


// 左端+真ん中+右端で飾り付きの部分の文字列を表示する
void print_3_string_row_times_with_decoration(
	int    row,
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
	// **** 変数宣言 ****

	// 横の数
	int row    = 0;
	// 縦の数
	int column = 0;


	// **** 入力 ****
	input_chocolate_bar_size(
		row,
		column
	);




	// **** 板チョコの出力 ****
	
	print_chocolate_bar(
		row,
		column
	);


}








// 板チョコの大きさを入力する
void input_chocolate_bar_size(
	int &row,
	int &column
)
{
	// 横の数
	cout << "row?: ";
	cin >> row;

	// 縦の数
	cout << "column?: ";
	cin >> column;
}




// 板チョコを表示する
void print_chocolate_bar(
	int row,
	int column
)
{
	// 板チョコの頭を表示する
	print_chocolate_bar_head( row );


	// 板チョコの中身を、
	// 縦の数だけ表示する
	if (column < 0)
	{
		cout << "縦の数がマイナスです！" << endl;
	}
	for (int i = 0; i < column; ++i)
	{
		print_chocolate_bar_body( row );
	}

	// 板チョコの包装紙を表示する
	print_chocolate_bar_wrapping( row );
}




// 板チョコの頭を表示する
void print_chocolate_bar_head(
	int row
)
{
	print_3_string_row_times(
		row,
		"┏ ",  "━ ━ ━ ",  "┓ "
	);
}




// 板チョコの中身を表示する
void print_chocolate_bar_body(
	int row
)
{
	print_3_string_row_times(
		row,
		"┃ ",  "┏ ━ ┓ ",  "┃ "
	);
	
	print_3_string_row_times(
		row,
		"┃ ",  "┃ 　┃ " ,  "┃ "
	);
	
	print_3_string_row_times(
		row,
		"┃ ",  "┗ ━ ┛ ",  "┃ "
	);
}




// 板チョコの包装紙を表示する
void print_chocolate_bar_wrapping(
	int row
)
{
	print_3_string_row_times_with_decoration(
		row,
		"┣ "      ,  "┣ ┯ ",
		"━ ━ ━ ",  "━ "   ,
		"┫ "      ,  "┯ ┫ "
	);
	
	for (int i = 0; i < WRAPPING_HEIGHT; ++i)
	{
		print_3_string_row_times_with_decoration(
			row,
			"┃ "      ,  "┃ │ ",
			"　　　"   ,  "　"    ,
			"┃ "      ,  "│ ┃ "
		);
	}
	
	print_3_string_row_times_with_decoration(
		row,
		"┃ "      ,  "┃ └ ",
		"─ ─ ─ ",  "─ "   ,
		"┃ "      ,  "┘ ┃ "
	);
	
	print_3_string_row_times_with_decoration(
		row,
		"┗ "      ,  "┗ ━ ",
		"━ ━ ━ ",  "━ "   ,
		"┛ "      ,  "━ ┛ "
	);


}




// 左端+真ん中+右端で文字列を表示する
void print_3_string_row_times(
	int    row,
	string left,
	string center,
	string right
)
{
	cout << left;
	for (int i = 0; i < row; ++i)
	{
		cout << center;
	}
	cout << right;
	cout << endl;
}




// 左端+真ん中+右端で飾り付きの部分の文字列を表示する
void print_3_string_row_times_with_decoration(
	int    row,
	string left,
	string left_decolated,
	string center,
	string center_adjust,
	string right,
	string right_decolated
)
{
	// 横幅が1未満(模様を表示する幅が無い)の場合
	if (row < 1)
	{
		print_3_string_row_times(
			row,
			left,  center,  right
		);
	}
	else
	{
		cout << left_decolated;
		for (int i = 0; i < row - 1; ++i)
		{
			cout << center;
		}
		cout << center_adjust;
		cout << right_decolated;
		cout << endl;
	}
}



