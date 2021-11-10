#include <iostream>
using namespace std;

class Matrix {
    private:
        int numRow;
        int numCol;
        double **val;
    public:
        Matrix(){}
        ~Matrix(){}
        void Nhap();
        void Xuat();
        Matrix Cong(Matrix&);
        Matrix Tru(Matrix&);
        Matrix Nhan(Matrix&);
};

void Matrix::Nhap(){
    cout << "Nhap so hang: "; cin >> numRow;
    cout << "Nhap so cot: "; cin >> numCol;
    val = new double *[numRow];
    cout << "Nhap gia tri cho MT!" << endl;
    for(int i = 0; i < numRow; i++){
        val[i] = new double [numCol];
        for(int j = 0; j < numCol; j++){
            cout << "Nhap [" << i << "][" << j << "]: "; cin >> val[i][j];
        }
    }
}

void Matrix::Xuat(){
    for(int i = 0; i < numRow; i++){
        for(int j = 0; j < numCol; j++){
            cout << "\t" << this->val[i][j];
        }
        cout << endl;
    }
}

Matrix Matrix::Cong(Matrix &a){
    Matrix temp;
    if((this->numRow != a.numRow) || (this->numCol != a.numCol)){
        cout << "Hai Matrix khong cung kich thuoc!" << endl;
    } else {
        temp.numRow = this->numRow;
        temp.numCol = this->numCol;
        temp.val = new double *[this->numRow];
        for(int i = 0; i < this->numRow; i++){
            temp.val[i] = new double [this->numCol];
            for(int j = 0; j < this->numCol; j++){
                temp.val[i][j] = this->val[i][j] + a.val[i][j];
            }
        }
    }
    return temp;
}

Matrix Matrix::Tru(Matrix &a) {
    Matrix temp;
    if((this->numRow != a.numRow) || (this->numCol != a.numCol)){
        cout << "Hai Matrix khong cung kich thuoc!" << endl;
    } else {
        temp.numRow = this->numRow;
        temp.numCol = this->numCol;
        temp.val = new double *[this->numRow];
        for(int i = 0; i < this->numRow; i++){
            temp.val[i] = new double [this->numCol];
            for(int j = 0; j < this->numCol; j++){
                temp.val[i][j] = this->val[i][j] - a.val[i][j];
            }
        }
    }
    return temp;
}

Matrix Matrix::Nhan(Matrix &a){
    Matrix temp;
    temp.numRow = this->numRow;
    temp.numCol = a.numCol;
    temp.val = new double *[this->numRow];
    for(int i = 0; i < this->numRow; i++){
        temp.val[i] = new double [a.numCol];
        for(int j = 0; j < a.numCol; j++){
            for(int k = 0; k < this->numCol; k++){
                temp.val[i][j] += this->val[i][k] * a.val[k][j];
            }
        }
    }
    return temp;
}

int main(){
    Matrix A, B, C, D, F, G;
    cout << "Nhap Matrix 1" << endl;
    A.Nhap();
    cout << "Nhap Matrix 2" << endl;
    B.Nhap();
    cout << "Matrix 1!" << endl;
    A.Xuat();
    cout << "Matrix 2!" << endl;
    B.Xuat();
    cout << "Tong 2 Matrix!" << endl;
    C = A.Cong(B);
    C.Xuat();
    cout << "Hieu 2 Matrix!" << endl;
    D = A.Tru(B);
    D.Xuat();
    cout << "Nhap Matrix 3" << endl;
    F.Nhap();
    cout << "Matrix 3!" << endl;
    cout << "Tich cua MT 1 va 3!" << endl;
G = A.Nhan(F);
    G.Xuat();
    return 0;
}