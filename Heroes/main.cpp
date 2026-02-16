#include <iostream>
using namespace std;

class subvector
{
public:

    subvector()
    {
        mas = NULL;
        top = 0;
        capacity = 0;
    }

    ~subvector()
    {
        top = 0;
        capacity = 0;
        delete[] mas;
    }

    bool init()
    {
        top = 0;
        capacity = 0;
        mas = NULL;
        return true;
    }

    bool push_back(int d)
    {
        if (capacity == 0) {
            capacity = 1;
            mas = new int[1];
        }
        if (capacity == top) {
            capacity *= 2;
            int *a = new int[capacity];
            for (unsigned int i = 0; i < top; i++) {
                a[i] = mas[i];
            }
            delete[] mas;
            mas = a;
        }

        mas[top] = d;
        top++;

        return true;
    }

    int pop_back()
    {
        if ((top == 0) or (mas == NULL)) {
            return 0;
        }
        else {
            top--;
            return mas[top];
        }
    }

    bool resize(unsigned int new_capacity)
    {
        if (new_capacity >= capacity) {
            int *a = new int[new_capacity];
            for (unsigned int i = 0; i < top; i++) {
                a[i] = mas[i];
            }
            delete[] mas;
            mas = a;
        }
        else {
            top = capacity = new_capacity;
        }

        return true;
    }

    void shrink_to_fit() // очистить неиспользуемую память, переехав на новое место с уменьшением capacity до top
    {
        if (top == 0) {
            delete[] mas;
            init();
            return;
        }
        capacity = top;
        int *a = new int[capacity];
        for (unsigned int i = 0; i < capacity; i++) {
            a[i] = mas[i];
        }
        delete[] mas;
        mas = a;
    }

    void clear() // очистить содержимое недовектора, занимаемое место при этом не меняется
    {
        top = 0;
    }

    void print()
    {
        for (int i = 0; i < top; i++) {
            cout << mas[i] << endl;
        }
    }

private:
    int *mas;
    unsigned int top;
    unsigned int capacity;
};

class matrix
{
public:

    matrix(int m_, int n_)
    {
        m = m_;
        n = n_;
        arr = new int*[m];
        for (int i = 0; i < m; i++) {
            arr[i] = new int[n];
        }
    }

    ~matrix() {
        for (int i = 0; i < m; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    void full()
    {
        int k;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> k;
                arr[i][j] = k;
            }
        }
    }

    int** sum(matrix& arr2) //& чтобы память не страдала
    {
        int** res = new int*[m];
        for (int i = 0; i < m; i++) {
            res[i] = new int[n];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = 0;
            }
        }
        if (arr2.m == m && arr2.n == n) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] = arr[i][j] + arr2.arr[i][j];
                }
            }
        }
        return res;
    }

    int** mltp(matrix& arr2)
    {
        int** res = new int*[m];
        for (int i = 0; i < m; i++) {
            res[i] = new int[n];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = 0;
            }
        }
        if (n == arr2.m) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for(int k = 0; k < n; k++) {
                        res[i][j] += (arr[i][k] * arr2.arr[k][j]);
                    }
                }
            }
        }
        return res;
    }

    /*int get_rank()
    {
        //int rank = min(m, n);

        int** mat = new int*[m];
        for (int i = 0; i < m; ++i) {
            mat[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                mat[i][j] = arr[i][j];
            }
        }

        int r = 0;
        for (int col = 0; col < n && r < m; col++) {
            int k = -1;
            for (int i = r; i < m; i++) {
                if (mat[i][col] != 0) {
                    k = i;
                    break;
                }
            }

            if (k == -1) {
                if (k != r) {
                    int* tmp = mat[r];
                    mat[r] = mat[k];
                    mat[k] = tmp;
                }

                for (int i = r+1; i < m; i++) {
                    if (mat[i][col] != 0) {
                        int f1 = mat[r][col];
                        int f2 = mat[i][col];
                        for (int j = col; j < n; ++j) {
                            mat[i][j] = f1 * mat[i][j] - f2 * mat[r][j];
                        }
                    }
                }
                r++;
            }
        }
        for (int i = 0; i < m; ++i) {
            delete[] mat[i];
        }
        delete[] mat;

        return r;

    }*/

    /*int get_rank()
    {
        // Создаем копию матрицы, чтобы не испортить оригинал
        // Используем double, так как при вычитании строк неизбежно деление,
        // иначе точность на int упадет до нуля.
        int temp_m = m;
        int temp_n = n;

        double** mat = new double*[temp_m];
        for (int i = 0; i < temp_m; ++i) {
            mat[i] = new double[temp_n];
            for (int j = 0; j < temp_n; ++j) {
                mat[i][j] = static_cast<double>(arr[i][j]);
            }
        }

        int rank = 0;
        bool* row_selected = new bool[temp_m];
        for (int i = 0; i < temp_m; ++i) row_selected[i] = false;

        for (int j = 0; j < temp_n; ++j) {
            int pivot = -1;
            for (int i = 0; i < temp_m; ++i) {
                // Ищем строку с ненулевым элементом в текущем столбце
                if (!row_selected[i] && abs(mat[i][j]) > 1e-9) {
                    pivot = i;
                    break;
                }
            }

            if (pivot != -1) {
                rank++;
                row_selected[pivot] = true;
                // Обнуляем этот столбец в других строках
                for (int i = 0; i < temp_m; ++i) {
                    if (i != pivot && abs(mat[i][j]) > 1e-9) {
                        double factor = mat[i][j] / mat[pivot][j];
                        for (int k = j; k < temp_n; ++k) {
                            mat[i][k] -= factor * mat[pivot][k];
                        }
                    }
                }
            }
        }

        // Чистим память
        for (int i = 0; i < temp_m; ++i) delete[] mat[i];
        delete[] mat;
        delete[] row_selected;

        return rank;
    }*/

    /*double get_determinant() {
        // 1. Проверка: матрица должна быть квадратной
        if (m != n) {
            // В математике определитель неквадратной матрицы не определен.
            // Можно выбросить исключение или вернуть 0.
            return 0;
        }

        // 2. Создаем копию данных в формате double
        double** mat = new double*[m];
        for (int i = 0; i < m; i++) {
            mat[i] = new double[n];
            for (int j = 0; j < n; j++) {
                mat[i][j] = static_cast<double>(arr[i][j]);
            }
        }

        double det = 1.0;

        for (int i = 0; i < m; i++) {
            // Поиск ведущего элемента (с наибольшим значением для стабильности)
            int pivot = i;
            for (int j = i + 1; j < m; j++) {
                if (abs(mat[j][i]) > abs(mat[pivot][i])) {
                    pivot = j;
                }
            }

            // Если в столбце одни нули, определитель равен 0
            if (abs(mat[pivot][i]) < 1e-9) {
                // Не забываем чистить память перед выходом
                for (int k = 0; k < m; k++) delete[] mat[k];
                delete[] mat;
                return 0;
            }

            // Перестановка строк
            if (pivot != i) {
                double* temp = mat[i];
                mat[i] = mat[pivot];
                mat[pivot] = temp;
                det *= -1; // Меняем знак при перестановке строк
            }

            // Обнуление элементов под главной диагональю
            for (int j = i + 1; j < m; j++) {
                double factor = mat[j][i] / mat[i][i];
                for (int k = i + 1; k < n; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }

            // Умножаем результат на элемент главной диагонали
            det *= mat[i][i];
        }

        // 3. Чистим память
        for (int i = 0; i < m; i++) {
            delete[] mat[i];
        }
        delete[] mat;

        return det;
    }*/


    void print_matrix()
    {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    int m, n;
    int** arr;
};

/*int main()
{
    subvector sv;
    for (int i = 0; i < 10; i++) {
        sv.push_back(i+1);
    }
    sv.pop_back();
    sv.resize(5);
    sv.print();

    cout << "A:" << endl;
    matrix A(2, 3);
    A.full();
    cout << "B:" << endl;
    matrix B(3, 3);
    B.full();

    cout << "A + B:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A.sum(B)[i][j] << " ";
        }
        cout << endl;
    }
    cout << "A * B:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A.mltp(B)[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix:" << endl;
    matrix C(2, 2);
    C.full();
    cout << "rank: ";
    cout << C.get_rank() << endl;
    cout << "det: " << C.get_determinant() << endl;



    return 0;
}*/

//============================================================================

/*class buildings
{
protected:
    int gold;
    int stone;
    int wood;
public:
    buildings ()
    {
        cout << "building created" << endl;
    }

    int get_gold()
    {
        return gold;
    }
    int get_stone()
    {
        return stone;
    }
    int get_wood()
    {
        return wood;
    }
    void set(int gold_, int stone_, int wood_)
    {
        gold = gold_;
        stone = stone_;
        wood = wood_;
    }
};

class Tavern: public buildings
{
public:
    Tavern() {
        cout << "Tavern is created" << endl;
        gold = 500;
    }
};

class Well: public buildings
{
public:
    Well() {
        cout << "Well is created" << endl;
        gold = 500;
    }
};

class Estate: public buildings
{
public:
    Estate() {
        cout << "Estate is created" << endl;
        gold = 1000;
    }
};

class EstateUp: public Estate
{
public:
    EstateUp() {
        cout << "Estate is upgraded" << endl;
        gold = 1000;
    }
};

class Blacksmith: public buildings
{
public:
    Blacksmith() {
        cout << "Blacksmith is created" << endl;
        gold = 1500;
    }
};

class Marketplace: public buildings
{
public:
    Marketplace() {
        cout << "Marketplace is created" << endl;
        gold = 500;
    }
};

class MarketplaceUp: public Marketplace
{
public:
    MarketplaceUp() {
        cout << "Marketplace is upgraded" << endl;
        gold = 500;
    }
};

class Fortifications: public buildings
{
public:
    Fortifications() {
        cout << "Fortifications is created" << endl;
        gold = 2000;
        stone = 20;
    }
};

class FortificationsUp: public Fortifications
{
public:
    FortificationsUp() {
        cout << "Fortifications is upgraded" << endl;
        gold = 4000;
    }
};

class Citadel: public buildings
{
public:
    Citadel() {
        cout << "Citadel is created" << endl;
        gold = 2500;
        stone = 10;
    }
};

class CitadelUp: public Citadel
{
public:
    CitadelUp() {
        cout << "Citadel is upgraded" << endl;
        gold = 5000;
    }
};

class Castle: public buildings
{
public:
    Castle() {
        cout << "Castle is created" << endl;
        gold = 5000;
        stone = 20;
    }
};*/

#include <iostream>
#include "build.h"

int main()
{
    Tavern t;
    int coins = 600, stones = 30;
    if (coins >= t.get_gold() && stones >= t.get_stone()) {
        FortificationsUp fUp;
    }
    Well w;
    Castle c;
    cout << c.get_gold() << endl;

    return 0;
}

