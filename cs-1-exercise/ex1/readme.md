# OOP = парадигма за програмиране, която моделира реални обекти
====
Запис: https://drive.google.com/drive/folders/1NkpK90_Lk2WgfMY3_3xmSn9c4Z3ek5us?usp=sharing
12.02 - може би няма да имаме час. ще пусна инфо в moodle. 


Sum of two matrices
// the data is controlled by the main function (or it's subfunctions) and are connect to their stacks
int main() {
	double * A = readMatrix(2, 3);
	double * B = readMatrix(2, 3);
	double * C = sum(A, B, 2, 3);
	
	print(C, 2, 3);
	
	delete A;
	delete B;
	delete C;
}

// OOP
// We enclose the state in an Object. State = all variables needed to present an abstraction

# State
## Tic-Tac-Toe
### Option 1:
char board[3][3] - 'O', 'X', '\0';

### Option 2:
char board[9] - 'O', 'X', '\0';

### Option 3:
char board_0;
char board_1;
char board_2;
char board_3;
char board_4;
char board_5;
char board_6;
char board_7;
char board_8;

### Option 4:
int board; - group of 2 bits per field. 00 - empty, 01 - X, 10 - O

int main() {
	matrix A = new matrix(2,3);
	A.read();

	matrix B = new matrix(2,3);
	B.read();

	matrix C = A + B;
	C.print();
}

абстракция
енкапсулация
наследяване
полиморфизъм
