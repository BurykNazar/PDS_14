#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

int N, M;
vector<vector<int>> adjList;

void addEdge(int from, int to) {
    adjList[from].push_back(to);
}

bool readGraphFromFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "�� ������� ������� ����." << endl;
        return false;
    }

    file >> N >> M;

    if (N <= 0 || M <= 0) {
        cerr << "ʳ������ ������ � ����� ������� ���� ����� ����." << endl;
        return false;
    }

    adjList.resize(N);

    for (int i = 0; i < M; i++) {
        int start, end;
        if (!(file >> start >> end)) {
            cerr << "������� ��� ��������� �����." << endl;
            return false;
        }
        if (start < 1 || start > N || end < 1 || end > N) {
            cerr << "�������: ����� ������� �����: "
                << start << " -> " << end << endl;
        }
        addEdge(start - 1, end - 1);
    }
    file.close();
    return true;
}

void printAdjacencyMatrix() {
    vector<vector<int>> adjMatrix(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        for (int neighbor : adjList[i])
            adjMatrix[i][neighbor] = 1;

    cout << "������� �������� �����: " << endl;
    for (const auto& row : adjMatrix) {
        for (int val : row)
            cout << setw(5) << val << " ";
        cout << endl;
    }
}

bool isReflexive() {
    for (int i = 0; i < N; i++) {
        bool foundSelfLoop = false;
        for (int j : adjList[i]) {
            if (i == j) {
                foundSelfLoop = true;
                break;
            }
        }
        if (!foundSelfLoop) {
            return false;
        }
    }
    return true;
}

bool isSymmetric() {
    for (int from = 0; from < N; from++) {
        for (int to : adjList[from]) {
            bool foundSymmetry = false;
            for (int neighbor : adjList[to]) {
                if (neighbor == from) {
                    foundSymmetry = true;
                    break;
                }
            }
            if (!foundSymmetry) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filePath;
    cout << "������ ���� � ������ ����� �����: ";
    getline(cin, filePath);

    if (!readGraphFromFile(filePath)) {
        cerr << "������� ��� ��������� ����� � �����." << endl;
        return 1;
    }

    printAdjacencyMatrix();

    isReflexive() ? (
        cout << "���� � ������������." << endl
        ) : (
            cout << "���� �� � ������������." << endl
            );

    isSymmetric() ? (
        cout << "���� � �����������." << endl
        ) : (
            cout << "���� �� � �����������." << endl
            );

    return 0;
}
