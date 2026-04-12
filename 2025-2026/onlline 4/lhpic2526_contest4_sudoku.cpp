#include <bits/stdc++.h>

using namespace std;

bool isPlausible(const array<array<char, 9>, 9> &sudoku, int y, int x) {
    array<bool, 9> flags;

    // check dòng
    flags.fill(false);

    for (int j = 0; j < 9; ++j) {
        if (sudoku[y][j] == '.') {
            continue;
        }

        if (flags[sudoku[y][j] - '1']) {
            return false;
        }

        flags[sudoku[y][j] - '1'] = true;
    }

    // check cột
    flags.fill(false);

    for (int i = 0; i < 9; ++i) {
        if (sudoku[i][x] == '.') {
            continue;
        }

        if (flags[sudoku[i][x] - '1']) {
            return false;
        }

        flags[sudoku[i][x] - '1'] = true;
    }

    // check các bảng con
    flags.fill(false);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (sudoku[y / 3 * 3 + i][x / 3 * 3 + j] == '.') {
                continue;
            }

            if (flags[sudoku[y / 3 * 3 + i][x / 3 * 3 + j] - '1']) {
                return false;
            }

            flags[sudoku[y / 3 * 3 + i][x / 3 * 3 + j] - '1'] = true;
        }
    }

    return true;
}

/*
    Hàm đệ quy quay lui.
    Trả về giái trị true nếu đã hoàn thiện để kết thúc chuỗi đệ quy.
    Mỗi lần gọi sẽ tìm ô '.' đầu tiên và lần lượt thế vào các số 1 - 9 để thử.
*/
bool backTrack(array<array<char, 9>, 9> &sudoku) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (sudoku[i][j] != '.') {
                continue;
            }

            for (char c = '1'; c <= '9'; ++c) {
                // thế trực tiếp vào bảng nếu bảng được hoàn thiện
                // và hợp lệ thì giá trị này sẽ không được đổi lại
                // thành '.' và bảng sudoku ban đầu sẽ đầy số
                sudoku[i][j] = c;

                // dùng hàm để kiểm tra sự khả thi của bảng
                // trước khi đệ quy
                if (!isPlausible(sudoku, i, j)) {
                    continue;
                }

                bool isFinished = backTrack(sudoku);

                if (isFinished) {
                    return true;
                }
            }

            // nếu không có hoán vị nào hợp lệ được thì giá trị
            // ở ô này được reset lại thành trống và ta không
            // tìm thêm ô khác tại vì như vậy ta sẽ kiểm tra trùng
            // gây phí thời gian
            sudoku[i][j] = '.';

            return false;
        }
    }

    // không còn ô '.' nào trong bảng
    return true;
}

int main() {
    array<array<char, 9>, 9> sudoku;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> sudoku[i][j];
        }
    }

    backTrack(sudoku);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << sudoku[i][j];
        }

        cout << "\n";
    }

    return 0;
}
