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
void input_chocolate_bar_size(
	int &row,
	int &column
);


// �`���R��\������
void print_chocolate_bar(
	int row,
	int column
);

// �`���R�̓���\������
void print_chocolate_bar_head(
	int row
);

// �`���R�̒��g��\������
void print_chocolate_bar_body(
	int row
);

// �`���R�̕����\������
void print_chocolate_bar_wrapping(
	int row
);


// ���[+�^��+�E�[�ŕ������\������
void print_3_string_row_times(
	int    row,
	string left,
	string center,
	string right
);


// ���[+�^��+�E�[�ŏ���t���̕����̕������\������
void print_3_string_row_times_with_decoration(
	int    row,
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
	// **** �ϐ��錾 ****

	// ���̐�
	int row    = 0;
	// �c�̐�
	int column = 0;


	// **** ���� ****
	input_chocolate_bar_size(
		row,
		column
	);




	// **** �`���R�̏o�� ****
	
	print_chocolate_bar(
		row,
		column
	);


}








// �`���R�̑傫������͂���
void input_chocolate_bar_size(
	int &row,
	int &column
)
{
	// ���̐�
	cout << "row?: ";
	cin >> row;

	// �c�̐�
	cout << "column?: ";
	cin >> column;
}




// �`���R��\������
void print_chocolate_bar(
	int row,
	int column
)
{
	// �`���R�̓���\������
	print_chocolate_bar_head( row );


	// �`���R�̒��g���A
	// �c�̐������\������
	if (column < 0)
	{
		cout << "�c�̐����}�C�i�X�ł��I" << endl;
	}
	for (int i = 0; i < column; ++i)
	{
		print_chocolate_bar_body( row );
	}

	// �`���R�̕����\������
	print_chocolate_bar_wrapping( row );
}




// �`���R�̓���\������
void print_chocolate_bar_head(
	int row
)
{
	print_3_string_row_times(
		row,
		"�� ",  "�� �� �� ",  "�� "
	);
}




// �`���R�̒��g��\������
void print_chocolate_bar_body(
	int row
)
{
	print_3_string_row_times(
		row,
		"�� ",  "�� �� �� ",  "�� "
	);
	
	print_3_string_row_times(
		row,
		"�� ",  "�� �@�� " ,  "�� "
	);
	
	print_3_string_row_times(
		row,
		"�� ",  "�� �� �� ",  "�� "
	);
}




// �`���R�̕����\������
void print_chocolate_bar_wrapping(
	int row
)
{
	print_3_string_row_times_with_decoration(
		row,
		"�� "      ,  "�� �� ",
		"�� �� �� ",  "�� "   ,
		"�� "      ,  "�� �� "
	);
	
	for (int i = 0; i < WRAPPING_HEIGHT; ++i)
	{
		print_3_string_row_times_with_decoration(
			row,
			"�� "      ,  "�� �� ",
			"�@�@�@"   ,  "�@"    ,
			"�� "      ,  "�� �� "
		);
	}
	
	print_3_string_row_times_with_decoration(
		row,
		"�� "      ,  "�� �� ",
		"�� �� �� ",  "�� "   ,
		"�� "      ,  "�� �� "
	);
	
	print_3_string_row_times_with_decoration(
		row,
		"�� "      ,  "�� �� ",
		"�� �� �� ",  "�� "   ,
		"�� "      ,  "�� �� "
	);


}




// ���[+�^��+�E�[�ŕ������\������
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




// ���[+�^��+�E�[�ŏ���t���̕����̕������\������
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
	// ������1����(�͗l��\�����镝������)�̏ꍇ
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



