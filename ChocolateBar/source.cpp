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


// ********  using �錾  ********
using std::cout;
using std::cin;
using std::endl;
using std::string;




// ********  �萔�錾  ********
static constexpr int WRAPPING_HEIGHT = 6;




// ********  �v���g�^�C�v�錾  ********

// �`���R�̑傫������͂���
void get_chocolate_bar_size(
		int &column,
		int &row
);


// �`���R��\������
void print_chocolate_bar(
		int column,
		int row
);

// �`���R�̓���\������
void print_chocolate_bar_head(
		int column
);

// �`���R�̒��g��\������
void print_chocolate_bar_body(
		int column
);

// �`���R�̕����\������
void print_chocolate_bar_wrapping(
		int column
);


// ���[+�^��+�E�[�ŕ������\������
void print_chocolate_bar_line(
		int    column,
		string left,
		string center,
		string right
);


// ���[+�^��+�E�[�ŏ���t���̕����̕������\������
void print_chocolate_bar_line_decorated(
		int    column,
		string left,
		string left_decolated,
		string center,
		string center_adjust,
		string right,
		string right_decolated
);








// ********  �֐���`  ********

int main()
{
	// **** �ϐ� ****

	// ���̐�
	int column = 0;
	// �c�̐�
	int row    = 0;


	// **** �傫���̓��� ****
	get_chocolate_bar_size( column, row );
	
	// 1�s�󂯂�
	cout << endl;


	// **** �`���R�̏o�� ****
	print_chocolate_bar( column, row );


}








// �`���R�̑傫������͂���
void get_chocolate_bar_size(
		int &column,
		int &row
)
{
	// ���̐�
	cout << "column?: ";
	cin  >> column;

	// �c�̐�
	cout << "row?: ";
	cin  >> row;
}




// �`���R��\������
void print_chocolate_bar(
		int column,
		int row
)
{
	// �`���R�̓���\������
	print_chocolate_bar_head( column );


	// �`���R�̒��g���A
	// �c�̐������\������
	if (row < 0)
	{
		cout << "�c�̐����}�C�i�X�ł��I" << endl;
	}
	for (int i = 0; i < row; ++i)
	{
		print_chocolate_bar_body( column );
	}

	// �`���R�̕����\������
	print_chocolate_bar_wrapping( column );
}




// �`���R�̓���\������
void print_chocolate_bar_head(
		int column
)
{
	print_chocolate_bar_line(
		column,
		"�� ",  "�� �� �� ",  "�� "
	);
}




// �`���R�̒��g��\������
void print_chocolate_bar_body(
		int column
)
{
	print_chocolate_bar_line(
		column,
		"�� ",  "�� �� �� ",  "�� "
	);
	
	print_chocolate_bar_line(
		column,
		"�� ",  "�� �@�� " ,  "�� "
	);
	
	print_chocolate_bar_line(
		column,
		"�� ",  "�� �� �� ",  "�� "
	);
}




// �`���R�̕����\������
void print_chocolate_bar_wrapping(
		int column
)
{
	print_chocolate_bar_line_decorated(
		column,
		"�� "      ,  "�� �� ",
		"�� �� �� ",  "�� "   ,
		"�� "      ,  "�� �� "
	);
	
	for (int i = 0; i < WRAPPING_HEIGHT; ++i)
	{
		print_chocolate_bar_line_decorated(
			column,
			"�� "      ,  "�� �� ",
			"�@�@�@"   ,  "�@"    ,
			"�� "      ,  "�� �� "
		);
	}
	
	print_chocolate_bar_line_decorated(
		column,
		"�� "      ,  "�� �� ",
		"�� �� �� ",  "�� "   ,
		"�� "      ,  "�� �� "
	);
	
	print_chocolate_bar_line_decorated(
		column,
		"�� "      ,  "�� �� ",
		"�� �� �� ",  "�� "   ,
		"�� "      ,  "�� �� "
	);


}




// ���[+�^��+�E�[�ŕ������\������
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




// ���[+�^��+�E�[�ŏ���t���̕����̕������\������
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
	// ������1����(�͗l��\�����镝������)�̏ꍇ
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



