#include"util.h"


int main() {
    setlocale(LC_ALL, "Rus");
    int n = 9;
    int edges[][3] = {
        {0, 1, 3}, {0, 3, 2},
        {1, 2, 5}, {1, 4, 7},
        {2, 5, 2},
        {3, 4, 2}, {3, 6, 4},
        {4, 5, 1}, {4, 7, 2},
        {5, 8, 7},
        {6, 7, 6},
        {7, 8, 4}
    };
    int edgesSize = 12;

    // �������� �����
    graph* myGraph = createGraph(n, edges, edgesSize);

    // ����� �����
    printGraphAdjMatrix(myGraph);

    printGraph(myGraph);

    // ����� ����������� ���� ����� 
    int shortestPathCost;
    int a = -1, b = -1;
    printf("������� �� ����� ����� �� ����� ����� ����������� ����������:\n");
    while (scanf("%d %d", &a, &b) == 2){
        shortestPathCost = graphShortestPath(myGraph, a, b);
        if (shortestPathCost != -1) {
            printf("��������� ���� ����� ������ %d � ������ %d: %d\n",a,b, shortestPathCost);
        }
        else {
            printf("�� ������� ���� ����� ������ %d � ������ %d\n",a, b);
        }
        printf("������� ��� �����:\n");
    }
    // ������������ ������
    freeGraph(myGraph);

    return 0;
}

